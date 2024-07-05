#pragma once

#include <Windows.h>
#include <algorithm>
#include <string>
//#include "BindString.h"
//#include "Patcher.h"
#include "CommonDE.h"
#include <iostream>
#include <psapi.h>
#include "../Config/Config.h"

//#include "Weapon.h"


struct MatchPathSeparator
{
	bool operator()(char ch) const
	{
		return ch == '\\' || ch == '/';
	}
};



//! we only handle weapons from shotgun to minigun. the balista has the unmaker toggle which makes it annoying to handle and the crucible and hammer have the same key which makes them hard to handle as well however those weapons don't get use too often so it's ok.
const int monitoredWeaponMinIndex = 1; //!  shotgun
const int monitoredWeaponMaxIndex = 7; //!  minigun

class MemHelper
{
private:
	//uintptr_t m_moduleBaseAddr = 0;
	uintptr_t m_idPlayerAddr = 0;
	//GameState m_gameState = GameState::unknown;

	__int64 m_idHud_WeaponInfoPtr = 0;

	const int m_iceNadeSelected = 1;
	const int m_normalNadeSelected = 2;
	NadeStatus m_nadeStatus = NadeStatus::undefinedNade;
	
	//void updateNadeStatus();
	//NadeStatus getNadeStatus();


	

	std::string basename(std::string const& pathname);
	std::string GetGameExeNameToLower();



		
	//? this is not usable those "ids" can change is some mod are installed
	/*const std::vector<unsigned int>m_knownWeaponIdsVec{ 7113, 8562, 7404, 22668, 7732, 20817, 11052, 7982, 8300, 23691, 10464 };*/
	//const std::vector<unsigned int>m_knownGrenadeTypesIdVec{ 9843, 0x276A }; // frag(9843), ice(0x276A)
	std::vector<uintptr_t>m_ownedItemPtrsVec{}; //! weapons found in idInventoryCollection::GetInventoryItem_1D1D6A0 when deref first ptr there
	//std::vector<Weapon>m_ownedWeaponsVec{}; 
	std::vector<unsigned int>m_ownedGrenadeTypeIdsVec{};
	uintptr_t  m_idInventoryCollectionPtr = 0;
	const unsigned int m_inventoryMaxItemsCount = 256; //! this is to prevent issue when we get data from a "wrong" pointer check reminder file for why not having this can cause a memory leak. However the value of 256 is not final as may be player could have more(?)
	 
	//void initializeInventoryItemObjsVec();
	//void clearInventoryItemObjsVec();
	//void updateInventoryItems();
	uintptr_t  m_idPlayerPtr = 0;
	const std::string m_unknowWeapon = "Unknown Weapon";
	

	
	

public:
	MemHelper()
	{
		//m_voiceChatBindStr = BindString(voiceChatStr, 25, throwIceStr, (uintptr_t)0x04305108, voiceChatStrOffsets);
		//m_moduleBaseAddr = (uintptr_t)GetModuleHandle(NULL);
		//initializeInventoryItemObjsVec();
	}
	

	
	
	
	static bool isBadReadPtr(void* ptr);
	static uintptr_t FindPtrAddress(uintptr_t addr, std::vector<unsigned int>& offsets);
	static __int64 FindPtrFromRelativeOffset(uintptr_t funcStartAddress, int instructionOffset1, int instructionOffset2);
	static int FindHardcodedOffset(uintptr_t funcStartAddress, const int instructionOffset);
	//static __int64 getIdHud_WeaponInfoPtr();
	bool isGameFileNameValid();	
	static uintptr_t getModuleBaseAddr();
	static uintptr_t getFuncAddr(uintptr_t offset);
	static uintptr_t getAddr(uintptr_t offset);
	static bool overwriteInstruction(std::string refStr, const uintptr_t instructionAddr, std::vector<unsigned char> newInstructionVec);
	static bool overwriteInstructionIfNotEqual(std::string refStr, const uintptr_t instructionAddr, std::vector<unsigned char> newInstructionVec);
	//void overwriteInstructionV2(const uintptr_t instructionAddr, std::vector<unsigned char> newInstructionVec);
	//static void overwriteInstruction(uintptr_t instructionAddr, const Patcher& patch);
	//static void overwriteInstruction(const Patcher& patch);

	static bool isSameByteArrays(const BYTE* array1, const BYTE* array2, size_t length);
	static DWORD64 PatternScan(const char* szModule, const char* signature);
	static DWORD64 ModulePatternScan(std::string scanFriendlyName, const char* signature);

	//uintptr_t FindSignaturePattern(HANDLE hProcess, uintptr_t startAddress, const char* signature, const char* mask);
	//SIZE_T ReadPtr(SIZE_T Address, UINT Offset);
	//DWORD64 PatternScan(const char* szModule, const char* signature)
	//static DWORD64 PatternScan(const char* szModule, const char* signature);
	//void ScanMemoryPattern(const BYTE* pattern, size_t patternSize);
	//uintptr_t getInstructionAddr(uintptr_t offset);
	//uintptr_t getIdPlayerAddr();
	//void setIdPlayerAddr(uintptr_t addr);
	//GameState updateGameState();
	//void aquire_idHudWeaponInfoPtr(__int64 nadePtr);
	//bool isIceNadeSelected();
	//bool isNormalNadeSelected();
	//void setNadeStatus(__int64 nadePtr);
	//void printNadeStatusChange();
	//void overwriteBindStrings();
	//void patchInstruction(Patcher& patch);
	//! atm used to prevent objective key to actually display obj so we can bind its key to a dedicated nade bind.
	//void patchObjectiveOverlay();
	//std::string getBindInputStr(__int64 bindPtr);
	//std::string getBindActionStr(__int64 bindPtr);
	//void getCurrentlyEquippedWeaponIndex();
	//void logChangedWeaponData(int weaponDataInt, int weaponIndex);
	//std::string getWeaponStrFromWeaponData(int weaponDataInt);
	//std::string getWeaponStrFromWeaponId(unsigned int weaponId);
	//std::string getGrenadeTypeStrFromId(unsigned int itemId);

	//int getCurrentlyEquippedWeaponIndex();
	//Weapon GetcurrentlyEquippedWeapon(); 
	//int getCurrentlyEquippedWeaponIndex();
	//void printWeaponPotentialErrorVal(__int64 idPlayerPtr, int weaponIndex);
	//int convertWeaponDataToIndex(int weaponDataInt);
	//bool isKnowWeaponData(int weaponDataInt);

	//static bool isWeaponIndexError(int weaponIndex);

	//bool isPlayerInGame();

	//void aquire_idInventoryCollectionPtr(uintptr_t ptr);
	//void aquireWatchedOwnedItems(); //! weapons and grenades
	//void debugPrintWatchedOwnedItems();
	//std::vector<unsigned int>getOwnedGrenadeTypeIdsVec();
	//std::vector<Weapon>getOwnedWeaponsVec();
	//bool isWeapon(unsigned int itemId);
	//void debugPrintOwnedWeapons();
	//bool isGrenadeType(unsigned int itemId);

	//void aquire_idPlayerPtr(uintptr_t ptr);
	//unsigned int getInventoryItemsCount();

	//bool isKeyPressedCustom(__int64& ptr, __int64 btnEnum); //! check definition for info

	

	

};

