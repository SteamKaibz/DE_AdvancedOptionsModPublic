//#include "idConsoleLocalManager.h"
//
// __int64 idConsoleLocalManager::getStaticWhiteMatrAddr() {
//	 logErr("isConsoleOpened: getStaticWhiteMatrAddr this func should not be used !!!");
//	return MemHelper::getAddr(0x3982CF0);
//}
//
//  std::string idConsoleLocalManager::getEmptyString() {
//	 return "";
// }
//
//bool idConsoleLocalManager::isConsoleOpened() {
//	if (!m_idConsoleAddr) {
//		m_idConsoleAddr = TypeInfoManager::getIdConsoleAddr();
//	}
//	if (!m_idConsoleAddr) {
//		logErr("isConsoleOpened: m_idConsoleAddr is null can not get info, returning false");
//		return false;
//	}
//	//! have to hardcode this the offset is not documented in typeInfo
//	return *(unsigned int*)(m_idConsoleAddr + 0xD0);
//
//	
//}
