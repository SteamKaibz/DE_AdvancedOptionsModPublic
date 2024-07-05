#pragma once

#include "GeneratedClasses.h"
#include "TypeInfoManager.h"
#include "../K_Utils/K_Utils.h"



//? this is not static, doesn't need to be
class idLibManager
{
private:

	std::string m_idaIdbStringsFileName = "DE_IdaAllStringsCleaned.txt";

	std::string m_idLibClassesFileName = "DE_idLib_Cls.h";
	std::string m_idLibEnumsFileName = "DE_idLib_Enums.h";

	std::set<std::string> m_uniqueClassNamesSet;
	unsigned int m_dupeCounter = 0;

	std::vector<std::string> m_uniqueEnumVarNamesVec;
	unsigned int m_dupeEnumVarsCounter = 0;

	


public:



	void generateIdLibFiles();

	std::string getClsInfoAsText(classTypeInfo_t* typeInfoPtr);

	//std::string getSuperTypeStr(classTypeInfo_t* typeInfoPtr);

	std::string getInheritanceChainStr(classTypeInfo_t* typeInfoPtr);

	std::string getUniqueEnumVarName(std::string enumVarName);

	std::string getEnumInfoAsText(enumTypeInfo_t* enumTypeInfoPtr);

};

