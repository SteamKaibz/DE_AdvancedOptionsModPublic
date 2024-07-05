#pragma once
#include "../DE/TypeInfoManager.h"
#include <regex>
#include <string>
#include <unordered_map>


class varInfoCustom {

private:

    classVariableInfo_t* varInfoPtr;
    //std::string inheritanceCommentStr;
    std::string declarationStr;
    std::string varNameStr;
    std::string usableTypeStr;
    std::string opsStr;
    std::string typeCommentStr; //! info about for ex what an idList is made of


    void convertToUsableType() {
        if (!varInfoPtr) {
            logErr("convertToUsableType varInfoPtr is null can not process");
            return;
        }

        std::string varInfoTypeStr = varInfoPtr->type;
        logInfo("convertToUsableType: debug: varInfoTypeStr is %s", varInfoTypeStr.c_str());

        //! more effective to do that here than in every statement
        typeCommentStr = "// " + std::string(varInfoTypeStr);

        if (varInfoTypeStr.starts_with("idList")) {
            usableTypeStr = "idList";
        }
        else if (varInfoTypeStr.starts_with("idGrowableList")) {
            usableTypeStr = "void*";
            varNameStr = "idGrowableList_" + std::string(varInfoPtr->name);
        }
        else if (varInfoTypeStr.starts_with("idTypesafeTime")) {
            
            usableTypeStr = extractIdTimeSafeType(varInfoTypeStr);
        }
        else if (varInfoTypeStr == "idMapInstance_Interface") {
            usableTypeStr = "void*";
        }
        else if (varInfoTypeStr == "resourceList_t") {
            usableTypeStr = "void*";
        }
        else if (varInfoTypeStr.starts_with("idArray")) {
            std::regex pattern(R"(idArray\s*<\s*(.*?)\s*,\s*(\d+)\s*>)");
            std::smatch match;
            // Try to match the pattern in the first input
            if (std::regex_search(varInfoTypeStr, match, pattern)) {
                if (match.size() == 3) {
                    std::string variableName = match[1].str();
                    std::string numberStr = match[2].str();
                    usableTypeStr = variableName;
                    varNameStr = std::string(varInfoPtr->name) + "_ptr" + "[" + numberStr + "]";
                }
            }
        }
        else {

            usableTypeStr = varInfoTypeStr;
            if (varInfoPtr->ops) {
                usableTypeStr += std::string(varInfoPtr->ops);
            }
            typeCommentStr.clear();
        }
        usableTypeStr = replaceDoubleScopeWithUnderscore(usableTypeStr);
    }

    void ConvertToVS64Type() {

        // Map of types to their VS 64-bit equivalents
        std::unordered_map<std::string, std::string> typeMap = {
            {"uint32", "unsigned int"},
            {"int32", "int"},
            {"uint16", "unsigned short"},
            {"int16", "short"},
            {"uint8", "unsigned char"},
            {"int8", "char"},
            {"uint64", "unsigned long long"},
            {"int64", "long long"}
        };

        std::string output = usableTypeStr;
        for (const auto& pair : typeMap) {
            size_t pos = output.find(pair.first);
            while (pos != std::string::npos) {
                output.replace(pos, pair.first.length(), pair.second);
                pos = output.find(pair.first, pos + pair.second.length());
            }
        }

        usableTypeStr = output;
    }


    std::string extractIdTimeSafeType(const std::string& input) {
        // Find the position of "<" and ","
        size_t openBracketPos = input.find('<');
        size_t commaPos = input.find(',');

        if (openBracketPos != std::string::npos && commaPos != std::string::npos) {
            // Extract the type between "<" and the first ","
            std::string type = input.substr(openBracketPos + 1, commaPos - openBracketPos - 1);
            // Trim leading and trailing spaces
            size_t firstNonSpace = type.find_first_not_of(" ");
            size_t lastNonSpace = type.find_last_not_of(" ");
            if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
                type = type.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
            }
            return type;
        }

        return "TYPE NOT FOUND ";  // Type not found
    }

    std::string replaceDoubleScopeWithUnderscore(std::string typeName) {
        std::regex doubleScope("::");
        return std::regex_replace(typeName, doubleScope, "_");
    }


    std::string getOffsetAndSizeComment() {
        if (!varInfoPtr) {
            logErr("getOffsetAndSizeComment varInfoPtr is null can not process");
            return std::string();
        }
        std::ostringstream result;
        result << "// offset: " << std::hex << std::uppercase << varInfoPtr->offset  << "h (" <<  std::dec << varInfoPtr->offset << "d)  size: " << varInfoPtr->size;
        return result.str();
    }


public:

    varInfoCustom(classVariableInfo_t* varInfoPtrArg)
    {
        varInfoPtr = varInfoPtrArg;
        if (!varInfoPtr) {
            logErr("varInfoCustom: varInfoPtr is null ptr can not process");
            return;
        }
        convertToUsableType();
        ConvertToVS64Type(); // making sure there is no uint64 or types like thoses
    }

    //! useful for arrays cause by default we get for ex char[20] baseBuffer instead of char baseBuffer[20]
    std::string rearrangeBracketsInDeclaration(const std::string& input) {
        std::regex pattern(R"((\w+)\[(\d+)\]\s+(\w+))"); // Matches types like char[20], int[10], etc.
        std::smatch matches;

        if (std::regex_match(input, matches, pattern)) {
            if (matches.size() == 4) { // 3 captured groups + the entire match
                return matches[1].str() + " " + matches[3].str() + "[" + matches[2].str() + "]";
            }
        }
        return input; // return original input if no match
    }

    std::string getStr() {
        if (!varInfoPtr) {
            logErr("varInfoCustom: can not get Str cause varInfoPtr is null");
            return std::string();
        }
        std::string result;
        std::string spacing = "    ";

        /*if (!inheritanceCommentStr.empty()) {
            result += spacing + inheritanceCommentStr + "\n";
        }*/
        if (!typeCommentStr.empty()) {
            result += spacing + typeCommentStr + "\n";
        }
        if (varNameStr.empty()) {
            varNameStr = varInfoPtr->name;
        }

        std::string declarationStr = usableTypeStr.c_str();
        declarationStr += " ";
        declarationStr += varNameStr.c_str();
        declarationStr = rearrangeBracketsInDeclaration(declarationStr);


        logInfo("getStr: usableTypeStr: %s varNameStr: %s declarationStr: %s getOffsetAndSizeComment(): %s", usableTypeStr.c_str(), varNameStr.c_str(), declarationStr.c_str(), getOffsetAndSizeComment().c_str());
        result += spacing + declarationStr + " ; " + getOffsetAndSizeComment() + "\n";
        return result;
    }


};
