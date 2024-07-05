#include "idDeclGlobalShellManager.h"

// bool idDeclGlobalShellManager::acquireGlobalDeclAddr() {		
//
//	if (MemHelper::isBadReadPtr((void*)Ptr)) {
//		logErr("acquireGlobalDeclAddr: Ptr is bad ptr: %p", (void*)Ptr);
//		m_idDeclGlobalShellPtr = nullptr;
//		return false;
//	}
//	
//	logInfo("acquireGlobalDeclAddr: waiting for idDeclGlobalShellPtr to exist...");
//	uint64_t searchStartMs = K_Utils::EpochMillis();
//	while (!m_idDeclGlobalShellPtr)
//	{
//		m_idDeclGlobalShellPtr = (idDeclGlobalShell*)*(__int64*)Ptr;
//
//		if (K_Utils::EpochMillis() - searchStartMs > idDeclGlobalShellPtrMaxWaitMs) {
//			int timeOutSec = idDeclGlobalShellPtrMaxWaitMs / 1000;
//			logErr("acquireGlobalDeclAddr: TIMEOUT (%d seconds) trying to find idDeclGlobalShellPtr, mod can not work.", timeOutSec);
//			return 0;			
//		}
//	}
//
//	logInfo("acquireGlobalDeclAddr: succes getting m_idDeclGlobalShellPtr at : %p ", m_idDeclGlobalShellPtr);
//	return true;
//}

 // __int64 idDeclGlobalShellManager::getGlobalDeclAddr() {
	// return m_decGlobalShellPtP;
 //}

 //! this address will be a ptr to the first profile in the list of profiles.
 //? old version
  /*__int64 idDeclGlobalShellManager::getColorProfileColorsListAddr() {

	  if (!m_idDeclGlobalShellPtr) {
		  logErr("getColorProfileColorsListAddr: m_idDeclGlobalShellPtr is nullptr returning 0");
		  return 0;
	  }
	  logInfo("getColorProfileColorsListAddr: m_idDeclGlobalShellPtr: %p &m_idDeclGlobalShellPtr->colorProfile: %p", m_idDeclGlobalShellPtr, (void*)&m_idDeclGlobalShellPtr->colorProfile);
	  return (__int64)m_idDeclGlobalShellPtr->colorProfile.list;

  }*/


idDeclUIColor* idDeclGlobalShellManager::getCurrentColorProfile() {

	int currentProfileIndex = fastCvarManager::getColorProfileIndex();
	if (currentProfileIndex < 0) {
		logErr("getCurrentColorProfile: currentProfileIndex < 0 can not get profile");
		return nullptr;
	}	

	idList* colorProfilesIdList = getColorProfileColorsIdList();

	//logInfo("getCurrentColorProfile: colorProfilesIdList: %p searching for profile index: %d", colorProfilesIdList, currentProfileIndex);


	if (colorProfilesIdList) {

		//__int64* IdHud_ElementPtr = (__int64*)IdHud_Elements_ListPtr->list;
		__int64* declProfilePtr = (__int64*) colorProfilesIdList->list;

		for (size_t i = 0; i < colorProfilesIdList->num; i++)
		{
			if (i == currentProfileIndex) {
				if (!MemHelper::isBadReadPtr(declProfilePtr)) {
					return (idDeclUIColor*) *declProfilePtr;
				}
			}
			declProfilePtr++;
		}
	}

	logWarn("getCurrentColorProfile: failed to find profile with index : %d", currentProfileIndex);
	return nullptr;

}


  idList* idDeclGlobalShellManager::getColorProfileColorsIdList() {

	  if (!m_idDeclGlobalShellPtr) {
		  m_idDeclGlobalShellPtr = idResourceListManager::getIdDeclGlobalShellPtr();	
		  if (!m_idDeclGlobalShellPtr) {
			  logErr("getColorProfileColorsIdList: failed to get m_idDeclGlobalShellPtr returning nullptr");
			  return nullptr;
		  }	
		  else {
			  logInfo("getColorProfileColorsIdList: m_idDeclGlobalShellPtr: set to %p", m_idDeclGlobalShellPtr);
		  }
	  }
	  idList* result = (idList*)&m_idDeclGlobalShellPtr->colorProfile;
	  logInfo("getColorProfileColorsIdList: m_idDeclGlobalShellPtr: %p idList* %p", m_idDeclGlobalShellPtr, result);
	  return result;
  }
  


  void idDeclGlobalShellManager::disableNewCampaignPopUp(bool isDisabled) {

	  static int defautLastNewCampaignPopupsNum = -1;

	  if (!m_idDeclGlobalShellPtr) {
		  m_idDeclGlobalShellPtr = idResourceListManager::getIdDeclGlobalShellPtr();
		  if (!m_idDeclGlobalShellPtr) {
			  logErr("disableNewCampaignPopUp: failed to get m_idDeclGlobalShellPtr returning nullptr");
			  return;
		  }		
		  else {
			  logInfo("disableNewCampaignPopUp: m_idDeclGlobalShellPtr: set to %p", m_idDeclGlobalShellPtr);
		  }
	  }

	  if (defautLastNewCampaignPopupsNum == -1) {
		  defautLastNewCampaignPopupsNum = m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num;
		  logInfo("disableNewCampaignPopUp: defautLastNewCampaignPopupsNum set to :%d", defautLastNewCampaignPopupsNum);
	  }

	  if (isDisabled) {
		  if (m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num != 0) {
			  logInfo("disableNewCampaignPopUp : current popUp list Num is: %d setting it to 0...", m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num);
			  m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num = 0;
		  }
	  }
	  else {
		  if (m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num != defautLastNewCampaignPopupsNum) {
			  logInfo("disableNewCampaignPopUp : current popUp list Num is: %d setting it to defautLastNewCampaignPopupsNum: %d ", m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num, defautLastNewCampaignPopupsNum);
			  m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num = defautLastNewCampaignPopupsNum;
		  }
	  }

	  
	 // int popUplistNum = m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num;
	 /* logInfo("setIsNewCampaignPopUp : debug: m_idDeclGlobalShellPtr: %p  &m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups: %p popUplistNum: %d", m_idDeclGlobalShellPtr, &m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups, popUplistNum);*/
	 // logInfo("disableNewCampaignPopUp : debug: current popUplistNum is: %d setting it to 0...", popUplistNum);
	 // m_idDeclGlobalShellPtr->mainCampaignDecl->newCampaignPopups.num = 0;

  }



