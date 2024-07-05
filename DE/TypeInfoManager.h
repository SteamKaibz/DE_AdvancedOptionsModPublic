#pragma once
#include <cstdint>
#include "MemHelper.h"
#include "GeneratedClasses.h"
#include "../K_Utils/K_Utils.h"





class TypeInfoManager {

private:

	static inline __int64 m_typeInfoToolsPtrAddr = 0;
	static inline idTypeInfoTools* m_idTypeInfoTools = nullptr;
	static inline typeInfoGenerated_t* m_typeInfoGeneratedPtr = nullptr;

	static inline __int64 m_findClassInfoFuncPtr = 0;
	static inline __int64 m_findEnumInfoFuncPtr = 0;
	static inline __int64 m_engine_tAddr = 0;

	static inline int m_cached_IdGameSystemLocalStateOffset = 0;
	static inline int m_cached_IdGameSystemLocalMapInstanceOffset = 0;


	//! Global Cached:

	//! idList defined in idLib not sure if  good idea or not but very low chance it changes.
	//static classVariableInfo_t* m_idList_VarInfo;
	
	// __int64 __fastcall idTypeInfoTools::FindClassInfo_4104A0(__int64 a1, unsigned __int8 *a2)
	typedef __int64(__fastcall* pIdTypeInfoTools_FindClassInfo)(__int64 typeInfoTools, const char* className);
	static pIdTypeInfoTools_FindClassInfo m_pIdTypeInfoTools_FindClassInfo;
		
	typedef __int64(__fastcall* pIdTypeInfoTools_FindEnumInfo)(__int64 typeInfoTools, const char* className);
	static pIdTypeInfoTools_FindEnumInfo m_pIdTypeInfoTools_FindEnumInfo;
	

public:

	


	static bool acquireTypeInfoTools(__int64 typeInfoToolsPtr);

	static bool acquirreFindClassInfoFuncPtr(__int64 funcAddr);

	static bool acquirreFindEnumInfoFuncPtr(__int64 funcAddr);


	static  typeInfoGenerated_t* getTypeInfoGenerated_t();

	static classTypeInfo_t* findClassInfo(const char* className);

	static classVariableInfo_t* findClassField(const char* cname, const char* fieldname);

	//static classVariableInfo_t* findClassFirstField(const char* cname);

	static enumTypeInfo_t* FindEnumInfo(const char* enumName);

	static std::string getEnumMemberName(const char* enumName, long long enumMemberVal);

	static __int64 get_engine_t();

	static void acquirreGameSystemLocalStateOffset();

	static int getGameSystemLocalStateOffset();

	static void acquirreGameSystemLocalMapInstanceOffset();

	static int getGameSystemLocalMapInstanceOffset();

	static __int64 getCvarSystemPtrAddr();

	static __int64 getCmdSystemPtrAddr();

	static __int64 getIdEventDefInterface();

	static __int64 getIdBroadcastManager();
	
	static __int64 getidEngineVersionInfoPtrAddr();

	static __int64 getWin32VarsAddr();

	static __int64 getIdBuildVersionInfoPtrAddr();

	static __int64 getIdConsoleAddr();

	static __int64 getIdDebugHudAddr();

	static __int64 getGlobalFontTable();



	static void debugLog_typeInfoGenerated_t();

	static void debugListClassFields(const char* cname);

	static void debugPrintOffsets();

	static __int64 get_engine_t_EducationalEdition();

};

//__int64 TypeInfoManager::m_typeInfoToolsPtrAddr = 0;
//__int64 TypeInfoManager::m_findClassInfoFuncPtr = 0;
//__int64 TypeInfoManager::m_findEnumInfoFuncPtr = 0;
//__int64 TypeInfoManager::m_engine_tAddr = 0;
// int TypeInfoManager::m_cached_IdGameSystemLocalStateOffset = 0;
// int TypeInfoManager::m_cached_IdGameSystemLocalMapInstanceOffset = 0;

