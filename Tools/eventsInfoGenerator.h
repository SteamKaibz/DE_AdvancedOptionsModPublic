#pragma once
#include <string>
#include "../DE/GeneratedClasses.h"
#include "../DE/MemHelper.h"
#include "../K_Utils/K_Utils.h"
#include "../DE/idEventManager.h"


class eventsInfoGenerator
{
private:

	std::string m_eventsListFileName = "eventsList_K.txt";

	std::string getidEventAsEnumToStr(idEventDef* idEventDefPtr);

	std::string getidEventDefToStr(idEventDef* idEventDefPtr);

	std::string eventTypeToString(eventType_t eventType);

	std::string getStaticOffsetsAsStr(idEventDef* eventPtr);

public:	

	//bool compareEventNames(const idEventDef* a, const idEventDef* b);

	void dumpEventsListEnumToFile();

	void dumpEventsListToFile(bool sortByName = false); //! if false will 'sort' by event num

	

	
};

