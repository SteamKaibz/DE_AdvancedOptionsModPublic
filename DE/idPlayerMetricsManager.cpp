#include "idPlayerMetricsManager.h"

 void idPlayerMetricsManager::debugPrintAddr() {
	__int64 gameSysLocalAddr = idGameSystemLocalManager::getIdGameSystemLocalAddr();
	if (!gameSysLocalAddr) {
		logErr("debugPrintAddr: gameSysLocalAddr is null, returning.");
		return;
	}
	logInfo("debugPrintAddr: gameSysLocalAddr: %p", (void*)gameSysLocalAddr);
	long long* idSaveGameSerializer = ((long long*)((char*)gameSysLocalAddr + 0xB0));
	long long* idSerializerFunctor = (long long*)(*(idSaveGameSerializer));
	long long* idMetrics = (long long*)(*(idSerializerFunctor + 0x59)); // 0x2C8 K: if you're here in CE look for 0x2C8 offset not 0x59
	//? wait idSerializerFunctor + 0x59 it's a long long ptr + 0x59 not a char pointer !!!!!!! that's why....
	logInfo("debugPrintAddr: idMetrics ptr at: %p", idMetrics);
	long long* idPlayerMetrics = (long long*)(*(idMetrics + 1)); // 0x8
	logInfo("debugPrintAddr: idPlayerMetrics ptr at: %p", idPlayerMetrics);
}
