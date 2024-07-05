#include "eventsInfoGenerator.h"



std::string eventsInfoGenerator::getidEventAsEnumToStr(idEventDef* idEventDefPtr) {
    if (idEventDefPtr->name && idEventDefPtr->name[0] != 0) {
        return "EVID_" + std::string{ idEventDefPtr->name } + " = " + K_Utils::intToHexString(idEventDefPtr->eventnum) + ",";
    }
    logErr("getidEventAsEnumToStr: failed to find name for event : 0x%X", idEventDefPtr->eventnum);
    return std::string();
}


std::string eventsInfoGenerator::getidEventDefToStr(idEventDef* idEventDefPtr) {
    std::string result = "";

    if (MemHelper::isBadReadPtr((void*)idEventDefPtr)) {
        logErr("getidEventDefToStr: idEventDefPtr is a bad ptr: %p", (void*)idEventDefPtr);
        return result;
    }
   

    if (idEventDefPtr->name && idEventDefPtr->name[0] != 0) {
       result += "name: " + std::string(idEventDefPtr->name) + "\n";       
    }
    if (idEventDefPtr->formatspec && idEventDefPtr->formatspec[0] != 0) {
        result += "formatspec: " + std::string(idEventDefPtr->formatspec) + "\n";
    }
    if (idEventDefPtr->argTypes && idEventDefPtr->argTypes[0] != 0) {
        result += "argTypes: " + std::string(idEventDefPtr->argTypes) + "\n";
    }
    if (idEventDefPtr->argNames && idEventDefPtr->argNames[0] != 0) {
        result += "argNames: " + std::string(idEventDefPtr->argNames) + "\n";
    }
    if (idEventDefPtr->argDefaultValues && idEventDefPtr->argDefaultValues[0] != 0) {
        result += "argDefaultValues: " + std::string(idEventDefPtr->argDefaultValues) + "\n";
    }   
    
    result += "returnType: " + std::to_string(idEventDefPtr->returnType) + "\n";
    result += "numargs: " + std::to_string(idEventDefPtr->numargs) + "\n";
    result += "numstrings: " + std::to_string(idEventDefPtr->numstrings) + "\n";
  
    result += "eventnum: " + K_Utils::intToHexString(idEventDefPtr->eventnum)  + " (dec: " + std::to_string(idEventDefPtr->eventnum) +  ")\n";
    result += "flags: " + std::to_string(idEventDefPtr->flags) + "\n";
    std::string typeStr = eventTypeToString(idEventDefPtr->type) + "\n";
    result += "type: " + typeStr;
    if (idEventDefPtr->timelineEventGroup && idEventDefPtr->timelineEventGroup[0] != 0) {
        result += "timelineEventGroup: " + std::string(idEventDefPtr->timelineEventGroup) + "\n";
    }
    if (idEventDefPtr->comment && idEventDefPtr->comment[0] != 0) {
        result += "comment: " + std::string(idEventDefPtr->comment) + "\n";
    }
    result += getStaticOffsetsAsStr(idEventDefPtr) + "\n";

    result += "\n";

    return result;
}



std::string eventsInfoGenerator::eventTypeToString(eventType_t eventType) {
    switch (eventType) {

    case EVENT_GAME:
        return "EVENT_GAME";
    case EVENT_ACTION:
        return "EVENT_ACTION";
    case EVENT_ANIMEVENT:
        return "EVENT_ANIMEVENT";
    case EVENT_FSMEVENT:
        return "EVENT_FSMEVENT";
    case EVENT_NOTICE:
        return "EVENT_NOTICE";
    case EVENT_SSACTION:
        return "EVENT_SSACTION";
    default:
        return "Unknown";
    }
}


//bool eventsInfoGenerator::compareEventNames(const idEventDef* a, const idEventDef* b) {
//    if (a->name && b->name) {
//        return std::string(a->name) < std::string(b->name);
//    }
//    // Handle null names by placing them at the end of the sorted list
//    return a->name != nullptr;
//}


//return "EVID_" + std::string{ name } + " = " + std::to_string(evnum) + ",";


void eventsInfoGenerator::dumpEventsListEnumToFile() {
    unsigned int eventsPtrCounter = 0;
    unsigned int eventsStrCounter = 0;
    std::vector<std::string> idEventEnumsStrVec;
    std::vector<idEventDef*> eventDefsPtrs;

    int EventsNum = idEventManager::GetNumEvents();
    idEventEnumsStrVec.reserve(EventsNum);
    eventDefsPtrs.reserve(EventsNum);


    for (size_t i = 0; i < EventsNum; i++)
    {
        auto event = idEventManager::GetEventForNum((unsigned int)i);
        eventDefsPtrs.push_back(event);
        eventsPtrCounter++;
    }

    logInfo("dumpEventsListEnumToFile: found : %u events ptrs", eventsPtrCounter);   


    for (size_t i = 0; i < eventDefsPtrs.size(); i++)
    {
        idEventEnumsStrVec.push_back(getidEventAsEnumToStr(eventDefsPtrs[i]));
        eventsStrCounter++;
    }

    logInfo("dumpEventsListEnumToFile: found : %u events Str, saving to file...", eventsPtrCounter);
    K_Utils::saveVecToFile(m_eventsListFileName, idEventEnumsStrVec);
}



void eventsInfoGenerator::dumpEventsListToFile(bool sortByName)
{
    unsigned int eventsPtrCounter = 0;   
    unsigned int eventsStrCounter = 0;   
    std::vector<std::string> idEventDefStrVec;
    std::vector<idEventDef*> eventDefsPtrs;

    int EventsNum = idEventManager::GetNumEvents();
    idEventDefStrVec.reserve(EventsNum);
    eventDefsPtrs.reserve(EventsNum);


    for (size_t i = 0; i < EventsNum; i++)
    {
        auto event = idEventManager::GetEventForNum((unsigned int)i);
        eventDefsPtrs.push_back(event);
        eventsPtrCounter++;
    }
  
    logInfo("dumpEventsListToFile: found : %u events ptrs", eventsPtrCounter);


    if (sortByName) {
        std::sort(eventDefsPtrs.begin(), eventDefsPtrs.end(), K_Utils::compareEventNames);
    }


    for (size_t i = 0; i < eventDefsPtrs.size(); i++)
    {
        idEventDefStrVec.push_back(getidEventDefToStr(eventDefsPtrs[i]));
        eventsStrCounter++;
    }

    logInfo("dumpEventsListToFile: found : %u events Str, saving to file: %s", eventsPtrCounter, m_eventsListFileName.c_str());
    K_Utils::saveVecToFile(m_eventsListFileName, idEventDefStrVec);

}



std::string eventsInfoGenerator::getStaticOffsetsAsStr(idEventDef* eventPtr) {

    __int64 eventOffset = (uintptr_t)eventPtr - MemHelper::getModuleBaseAddr();
    __int64 eventNumOffset = eventOffset + 0x34;
   
    /*__int64 cvarDataOffset = (*(uintptr_t*)cvarPtr) - MemHelper::getModuleBaseAddr();
    __int64 valIntOffset = cvarDataOffset + 0x8;
    __int64 valFloatOffset = cvarDataOffset + 0xC;*/

    return "EventDef Offset: " + K_Utils::intToHexString(eventOffset) + " Num Offset: " + K_Utils::intToHexString(eventNumOffset);
    //return "Cvar Offset: " + K_Utils::intToHexString(cvarOffset);


}

//void eventsInfoGenerator::listAllEventsToFile() {
//
//    std::vector<std::string> idEventDefStrVec;
//
//
//    int v2 = 0;
//    
//    __int64 maxEventNumAdd = MemHelper::getAddr(0x4297098);
//    if (MemHelper::isBadReadPtr((void*)maxEventNumAdd)) {
//        logErr("listAllEventsToFile: maxEventNumAdd is bad ptr: %p", (void*)maxEventNumAdd);
//        return;
//    }
//    int maxEventNum = *(int*)maxEventNumAdd;
//    logInfo("listAllEventsToFile : maxEventNum: %d", maxEventNum);
//
//    if (maxEventNum > 0) {
//        //! result: matches @ 0x42974A0, sig direct: D0 F3 44 3C F7 7F 00
//        __int64* idEventDefListPtr = (__int64*)MemHelper::getAddr(0x42974A0);
//        if (MemHelper::isBadReadPtr((void*)idEventDefListPtr)) {
//            logErr("listAllEventsToFile: idEventDefListPtr is bad ptr: %p", (void*)idEventDefListPtr);
//            return;
//        }
//        logInfo("listAllEventsToFile : idEventDefListPtr: %p", (void*)idEventDefListPtr);
//
//        std::string fileTitleStr = "idEvent Definitions: events max count: " + std::to_string(maxEventNum);
//        idEventDefStrVec.push_back(fileTitleStr);
//        idEventDefStrVec.push_back("\n");
//
//        do {
//            //logInfo("listAllEventsToFile : counter: %d", v2);
//            idEventDef* eventDefPtr = (idEventDef*)*idEventDefListPtr;
//            if (MemHelper::isBadReadPtr(eventDefPtr)) {
//                logErr("listAllEventsToFile: eventDefPtr is bad ptr: %p", eventDefPtr);
//                return;
//            }
//            idEventDefStrVec.push_back(getidEventDefToStr(eventDefPtr));
//            //m_idEventDefVec.push_back(eventDefPtr);
//            //printidEventDef(eventDefPtr);           
//            ++v2;
//            ++idEventDefListPtr;
//        } while (v2 < maxEventNum);
//    }
//
//    K_Utils::saveVecToFile(m_eventsListFileName, idEventDefStrVec);
//
//}
