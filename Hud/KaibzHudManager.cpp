#include "KaibzHudManager.h"


//? i don't get it this func used to crash as soon as we went from menu to the game and now it doesn't crash wtf??!!!
std::string KaibzHudManager::getHudValueAsStr(float valueF, float maxValue) {
	int resultInt = 0;	

	if (std::round(valueF) == valueF) {		
		resultInt = (int)valueF;
	}
	else {
		resultInt = (int)valueF + 1;		
	}

	return std::to_string(resultInt);
}

int KaibzHudManager::getIntVal(float valueF, float maxValue){
	int resultInt = 0;

	if (std::round(valueF) == valueF) {
		resultInt = (int)valueF;
	}
	else {
		resultInt = (int)valueF + 1;
	}

	return resultInt;
}


//std::string KaibzHudManager::getHudValueAsStr(float valueF, float maxValue) {
//	int resultInt = 0;
//
//	if (std::round(valueF) == valueF) {
//		resultInt = (int)valueF;
//	}
//	else {
//		resultInt = (int)valueF + 1;
//	}
//
//	std::string resultStr = std::to_string(resultInt);
//	//logInfo("getHudValueAsStr: valueF: %.3f, maxValue: %.3f resultInt: %d resultStr: %s", valueF, maxValue, resultInt, resultStr.c_str());
//
//	return std::to_string(resultInt);
//	//return resultStr;
//}


ImU32 KaibzHudManager::getCustomCrosshairHealthAsImU32Color(float currentHealthValue, float MaxHealthValue, float currentArmorValue, float MaxArmorValue) {

	if (MaxArmorValue <= 0 || MaxHealthValue <= 0) {
		// Handle error or return a default color
		return modSettings::getKaibzHudDisabledColorImU32();
	}

	float armorPercentage = (currentArmorValue) / MaxArmorValue * 100.0f;
	float healthPercentage = (currentHealthValue) / MaxHealthValue * 100.0f;

	if (armorPercentage == 100.0f) {
		return modSettings::getKaibzHudArmorMaxColorImU32();
	}
	else if (armorPercentage > 0.0f) {
		return modSettings::getKaibzHudArmorColorImU32();
	}

	else if (healthPercentage <= 0.0f) {
		return modSettings::getKaibzHudCriticalColorImU32();
	}

	else if (healthPercentage <= 25.0f) {
		return modSettings::getKaibzHudWarningColorImU32();
	}
	else if (healthPercentage <= 50.0f) {
		return modSettings::getKaibzHudCautionColorImU32();
	}

	else if (healthPercentage <= 100.0f) {
		return modSettings::getKaibzHudHealthColorImU32();
	}

	else  {
		return modSettings::getKaibzHudHealthMaxColorImU32();
	}

}



KaibzHudColor_t KaibzHudManager::get3StagesCorlor(float currentValue, float MaxValue, KaibzHudColor_t normalColor) {
	if (MaxValue <= 0) {
		// Handle error or return a default color
		return KaibzHudColor_t::disabledColor;
	}

	float percentage = (currentValue) / MaxValue * 100.0f;

	if (percentage < 25.0f) {
		return KaibzHudColor_t::criticalColor;
	}
	else if (percentage < 50.0f) {
		return KaibzHudColor_t::warningColor;
	}
	else {
		return normalColor;
	}
}



//! goes from 0 to 0.999999 when on cooldown and 1.0 when not on cooldown
float KaibzHudManager::getIceNadeCooldownProgress() {
	bool isIceOnCooldown = (idPlayer_K::getIceNadeCount() == 0);
	if (!isIceOnCooldown) return 1.0f;

	long long gameTime = idMapInstanceLocalManager::getGameTime_t();
	auto timers = idPlayer_K::getEquipmentTimers(equipmentIndex_t::ICE);
	//long long rechargeDurationSec = timers.equipmentRechargeDuration / 1000000;
	long long rechargeDuration = timers.equipmentRechargeDuration ;
	long long countdown = (timers.equipmentRechargeTime - gameTime) ;
	//long long countdownSec = ((timers.equipmentRechargeTime - gameTime) / 1000000) + 1;

	// Calculate the percentage of cooldown progress
	float cooldownProgress = static_cast<float>(countdown) / static_cast<float>(rechargeDuration);

	// Clamp the cooldown progress to the range [0, 1]
	cooldownProgress = std::max(0.0f, std::min(1.0f, cooldownProgress));

	cooldownProgress = 1.0f - cooldownProgress;

	return cooldownProgress;
}


//float KaibzHudManager::getIceNadeCooldownProgress() {
//	bool isIceOnCooldown = (idPlayer_K::getIceNadeCount() == 0);
//	if (isIceOnCooldown) return 1.0f; // Return 1 when on cooldown
//
//	long long gameTime = idMapInstanceLocalManager::getGameTime_t();
//	auto timers = idPlayer_K::getEquipmentTimers(equipmentIndex_t::ICE);
//	long long rechargeDurationSec = timers.equipmentRechargeDuration / 1000000;
//	long long countdownSec = ((timers.equipmentRechargeTime - gameTime) / 1000000) + 1;
//
//	// Calculate the percentage of cooldown progress
//	float cooldownProgress = static_cast<float>(countdownSec) / static_cast<float>(rechargeDurationSec);
//
//	// Clamp the cooldown progress to the range [0, 1]
//	cooldownProgress = std::max(0.0f, std::min(1.0f, cooldownProgress));
//
//	// Invert the cooldown progress
//	cooldownProgress = 1.0f - cooldownProgress;
//
//	return cooldownProgress;
//}


KaibzHudData KaibzHudManager::getData() {


	static idPlayer* lastIdPlayerPtr = nullptr;
	static int lastBloodPunchCount = 0;
	static int lastHammerChargeCount = 0;
	static int lastFragCount = 0;
	static int lastIceCount = 0;	

	static bool isFirtTimeIceFlash = true; //! used to prevent flash when player spawns

	KaibzHudData data;

	idHUD_LowWarning* idHUD_LowWarningPtr = (idHUD_LowWarning*)idHudManager::getIdHud_Element(HudElementName::LowWarning);
	idHUD_AbilityIndicators* idHUD_AbilityIndicatorsPtr = (idHUD_AbilityIndicators*)idHudManager::getIdHud_Element(HudElementName::AbilityIndicators);
	idHUD_ExtraLives* idHUD_ExtraLivesPtr = (idHUD_ExtraLives*)idHudManager::getIdHud_Element(HudElementName::ExtraLives);
	idHUD_WeaponInfo* idHud_WeaponInfoPtr = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
	idHUD_HealthInfo* idHUD_HealthInfoPtr = (idHUD_HealthInfo*)idHudManager::getIdHud_Element(HudElementName::HealthInfo);
	idHUD_BloodPunch* idHUD_BloodPunchPtr = (idHUD_BloodPunch*)idHudManager::getIdHud_Element(HudElementName::BloodPunch);


	if (idHUD_ExtraLivesPtr) {

		if (idHUD_ExtraLivesPtr->currentExtraLives || idHUD_ExtraLivesPtr->infiniteExtraLives) {
			data.extraLivesColor = KaibzHudColor_t::extraLivesColor;
		}	
		//! it's initialized as disabled.
	}


	if (idHUD_HealthInfoPtr) {

		data.isRadsuitEquipped = idHUD_HealthInfoPtr->radShieldEquipped;
		data.radsuitColor = get3StagesCorlor(idHUD_HealthInfoPtr->radShieldDesc.currentValue, idHUD_HealthInfoPtr->radShieldDesc.maxValue, KaibzHudColor_t::radsuitColor);

		data.isOxygenEquipped = idHUD_HealthInfoPtr->oxygenEquipped;
		data.oxygenColor = get3StagesCorlor(idHUD_HealthInfoPtr->oxygenDesc.currentValue, idHUD_HealthInfoPtr->oxygenDesc.maxValue, KaibzHudColor_t::oxygenColor);		

		/*std::string bpInfoStr = "bpInfoStr: is Visble: ";
		bpInfoStr += K_Utils::getBoolAsStr(idHUD_HealthInfoPtr->bloodPunchUnlockedAndVisible);*/	
	}


	if (idHUD_LowWarningPtr) {

		if (idHUD_LowWarningPtr->healthCurrent >= idHUD_LowWarningPtr->healthMax) {
			data.healthColor = KaibzHudColor_t::healthMaxColor;
		}
		else if (idHUD_LowWarningPtr->healthCurrent <= idHUD_LowWarningPtr->lowHealthThreshold) {
			data.healthColor = KaibzHudColor_t::warningColor;
		}
		else if (idHUD_LowWarningPtr->healthCurrent <= idHUD_LowWarningPtr->criticalHealthThreshold) {
			data.healthColor = KaibzHudColor_t::criticalColor;
		}
		else {
			data.healthColor = KaibzHudColor_t::healthColor;
		}	

		data.health = KaibzHudManager::getIntVal(idHUD_LowWarningPtr->healthCurrent, idHUD_LowWarningPtr->healthMax);
		data.healthStr = std::to_string(data.health);



		if (idHUD_LowWarningPtr->armorCurrent >= idHUD_LowWarningPtr->armorMax) {
			data.armorColor = KaibzHudColor_t::armorMaxColor;
		}
		else if (idHUD_LowWarningPtr->armorCurrent >= 0.0f) {
			data.armorColor = KaibzHudColor_t::armorColor;
		}	

		data.armor = KaibzHudManager::getIntVal(idHUD_LowWarningPtr->armorCurrent, idHUD_LowWarningPtr->armorMax);
		data.armorStr = std::to_string(data.armor);



		
		if (idHUD_LowWarningPtr->currentAmmoCount > idHUD_LowWarningPtr->lowAmmoThreshold || idHUD_LowWarningPtr->infinite) {
			data.ammoColor = KaibzHudColor_t::ammoColor;
		}		
		else {
			data.ammoColor = KaibzHudColor_t::criticalColor;
		}

		if (idHUD_LowWarningPtr->infinite) {
			data.ammoStr = data.hudNumberMaxValueStr;			
		}
		else {
			data.ammo = idHUD_LowWarningPtr->currentAmmoCount;
			data.ammoStr = std::to_string(idHUD_LowWarningPtr->currentAmmoCount);
		}

		//! crosshair data:
		data.crosshairHealthColorImU32 = getCustomCrosshairHealthAsImU32Color(idHUD_LowWarningPtr->healthCurrent, idHUD_LowWarningPtr->healthMax, idHUD_LowWarningPtr->armorCurrent, idHUD_LowWarningPtr->armorMax);
	}


	if (idHud_WeaponInfoPtr) {

		data.isCrucibleShownOnHud = idHud_WeaponInfoPtr->crucibleShown;
		if ((int)idHud_WeaponInfoPtr->crucibleCharge > 0) {
			data.crucibleColor = KaibzHudColor_t::hammerCrucibleColor;
		}

		data.isHammerShownOnHud = idHud_WeaponInfoPtr->hammerShown;
		data.hammerCharges = (int)idHud_WeaponInfoPtr->hammerRecharge;

		if (data.hammerCharges > 0) {
			data.hammerColor = KaibzHudColor_t::hammerCrucibleColor;
		}		
	}


	if (idHUD_AbilityIndicatorsPtr) {

		data.bloodPunchCount = (int)idHUD_AbilityIndicatorsPtr->bloodPunchCharge;

		if (idPlayer_K::isDesperatePunchAvailable()) {
			data.bloodPunchColor = KaibzHudColor_t::bloodPunchDesperateColor;
		}	

		else if (data.bloodPunchCount >= 2){
			data.bloodPunchColor = KaibzHudColor_t::bloodPunch2Color;
		}
		else if (data.bloodPunchCount == 1) {
			data.bloodPunchColor = KaibzHudColor_t::bloodPunch1Color;
		}


		if ((int)idHUD_AbilityIndicatorsPtr->flameBelchCharge >= 1) {
			data.flamebelchColor = KaibzHudColor_t::flameBelchColor;
		}

		
		if ((int)idHUD_AbilityIndicatorsPtr->chainsawCharge >= 3) {
			data.fuelColor = KaibzHudColor_t::fuel3Color;
		}
		else if ((int)idHUD_AbilityIndicatorsPtr->chainsawCharge == 2) {
			data.fuelColor = KaibzHudColor_t::fuel2Color;
		}
		else if ((int)idHUD_AbilityIndicatorsPtr->chainsawCharge == 1) {
			data.fuelColor = KaibzHudColor_t::fuel1Color;
		}


		data.fragCharges = (int)idHUD_AbilityIndicatorsPtr->grenadeCharge;

		if (data.fragCharges >= 2) {
			data.fragColor = KaibzHudColor_t::frag2Color;
		}
		else if (data.fragCharges == 1) {
			data.fragColor = KaibzHudColor_t::frag1Color;
		}

		
		data.iceNadeCooldownProgress = KaibzHudManager::getIceNadeCooldownProgress();

		data.iceCharges = (int)idHUD_AbilityIndicatorsPtr->iceGrenadeCharge;

		if (data.iceNadeCooldownProgress < 1.0f) {
			data.iceColor = KaibzHudColor_t::iceColorCoolDown;
		}
		else if (data.iceCharges >= 1) {
			data.iceColor = KaibzHudColor_t::iceColor;
		}


		//! if player ptr has changed we should reset items/abilities count
		idPlayer* idPlayerPtr = idMapInstanceLocalManager::getIdPlayer();
		if (idPlayerPtr != lastIdPlayerPtr) {
			lastIdPlayerPtr = idPlayerPtr;

			lastBloodPunchCount = data.bloodPunchCount;
			lastHammerChargeCount = data.hammerCharges;
			lastFragCount = data.fragCharges;
			lastIceCount = data.iceCharges;

			isFirtTimeIceFlash = true;
		}

		//! prioritization based on what could be the most important for user:

		
		if (data.hammerCharges != lastHammerChargeCount) {			

			if (data.hammerCharges > lastHammerChargeCount && modSettings::getFlag(KaibzHudFlag::FlashHudForHammerCount)) {
				data.isHudFlash = true;
				data.hudFlashColor = modSettings::getKaibzHudHammerCrucibleColorImU32();
			}	

			lastHammerChargeCount = data.hammerCharges;
		}

		else if (data.iceCharges != lastIceCount) {			
			

			if (data.iceCharges > lastIceCount && modSettings::getFlag(KaibzHudFlag::FlashHudForIceCount)) {
				if(isFirtTimeIceFlash) { //! will prevent the flash when player spawns
					isFirtTimeIceFlash = false;
				}
				else {
					data.isHudFlash = true;
					data.hudFlashColor = modSettings::getKaibzHudIceColorImU32();
				}				
			}

			lastIceCount = data.iceCharges;
		}

		else if (data.fragCharges != lastFragCount) {

			if (data.fragCharges > lastFragCount && modSettings::getFlag(KaibzHudFlag::FlashHudForFragCount)) {
				data.isHudFlash = true;
				data.hudFlashColor = modSettings::getKaibzHudFrag1ColorImU32();
			}		

			lastFragCount = data.fragCharges;
		}

		else if (data.bloodPunchCount != lastBloodPunchCount) {

			if (data.bloodPunchCount > lastBloodPunchCount && modSettings::getFlag(KaibzHudFlag::FlashHudForBloodPunchCount)) {
				data.isHudFlash = true;
				data.hudFlashColor = modSettings::getKaibzHudBloodPunch1ColorImU32();
			}		

			lastBloodPunchCount = data.bloodPunchCount;
		}			

	}


	return data;

}


std::string KaibzHudManager::getDdgStrForImgui()
{
	std::string resultStr = "\nKaibzHudManager Debug Data:\n";

	idHUD_LowWarning* idHUD_LowWarningPtr = (idHUD_LowWarning*)idHudManager::getIdHud_Element(HudElementName::LowWarning);	
	idHUD_AbilityIndicators* idHUD_AbilityIndicatorsPtr = (idHUD_AbilityIndicators*)idHudManager::getIdHud_Element(HudElementName::AbilityIndicators);
	idHUD_ExtraLives* idHUD_ExtraLivesPtr = (idHUD_ExtraLives*)idHudManager::getIdHud_Element(HudElementName::ExtraLives);	
	idHUD_WeaponInfo* idHud_WeaponInfoPtr = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
	idHUD_HealthInfo* idHUD_HealthInfoPtr = (idHUD_HealthInfo*)idHudManager::getIdHud_Element(HudElementName::HealthInfo);
	idHUD_BloodPunch* idHUD_BloodPunchPtr = (idHUD_BloodPunch*)idHudManager::getIdHud_Element(HudElementName::BloodPunch);


	std::string ptrsInfoStr;
	char buffer[512]; // Adjust the size as needed
	// Format the string using std::sprintf
	std::sprintf(buffer, "Ptrs: idHUD_LowWarningPtr: %p  idHUD_AbilityIndicatorsPtr: %p idHUD_ExtraLivesPtr: %p idHud_WeaponInfoPtr: %p idHUD_HealthInfoPtr: %p idHUD_BloodPunchPtr : %p",
		idHUD_LowWarningPtr, idHUD_AbilityIndicatorsPtr, idHUD_ExtraLivesPtr, idHud_WeaponInfoPtr, idHUD_HealthInfoPtr, idHUD_BloodPunchPtr);
	// Assign the formatted string to ptrsInfoStr
	ptrsInfoStr = buffer;
	
	resultStr += "\t" + ptrsInfoStr + "\n";


	if (idHUD_BloodPunchPtr) {
		std::string idHudbloodPunchInfoStr = "idHudbloodPunchInfoStr: Max: ";
		idHudbloodPunchInfoStr += std::to_string(idHUD_BloodPunchPtr->maxCharge);
		idHudbloodPunchInfoStr += " curr charge: ";
		idHudbloodPunchInfoStr += std::to_string(idHUD_BloodPunchPtr->currentCharge);

		resultStr += "\t" + idHudbloodPunchInfoStr + "\n";
	}


	if (idHUD_LowWarningPtr) {
		
		std::string healthInfoStr = "healthInfoStr: Max: ";
		healthInfoStr += std::to_string(idHUD_LowWarningPtr->healthMax);
		healthInfoStr += " cur: ";
		healthInfoStr += std::to_string(idHUD_LowWarningPtr->healthCurrent);
		healthInfoStr += " low thresh.: ";
		healthInfoStr += std::to_string(idHUD_LowWarningPtr->lowHealthThreshold);
		healthInfoStr += " critical: ";
		healthInfoStr += std::to_string(idHUD_LowWarningPtr->criticalHealthThreshold);

		std::string armorInfoStr = "armorInfo: Max: ";
		armorInfoStr += std::to_string(idHUD_LowWarningPtr->armorMax);
		armorInfoStr += " cur: ";
		armorInfoStr += std::to_string(idHUD_LowWarningPtr->armorCurrent);

		std::string ammoInfoStr = "ammoInfoStr Info: Max: ";
		ammoInfoStr += std::to_string(idHUD_LowWarningPtr->maxAmmoCount);
		ammoInfoStr += " cur: ";
		ammoInfoStr += std::to_string(idHUD_LowWarningPtr->currentAmmoCount);
		ammoInfoStr += " per shot: ";
		ammoInfoStr += std::to_string(idHUD_LowWarningPtr->ammoPerShot);
		ammoInfoStr += " low: ";
		ammoInfoStr += std::to_string(idHUD_LowWarningPtr->lowAmmoThreshold);
		ammoInfoStr += " is Inf: ";
		ammoInfoStr += std::to_string(idHUD_LowWarningPtr->infinite);

		std::string otherStr = "other data: is Demon: ";
		otherStr += std::to_string(idHUD_LowWarningPtr->isDemonPlayer);


		resultStr += "\t" + healthInfoStr + "\n";
		resultStr += "\t" + armorInfoStr + "\n";
		resultStr += "\t" + ammoInfoStr + "\n";
		resultStr += "\t" + otherStr + "\n";
	}

	if (idHUD_HealthInfoPtr) {

		std::string radsuitInfoStr = "radsuitInfoStr: radShieldEquipped: ";
		radsuitInfoStr += K_Utils::getBoolAsStr(idHUD_HealthInfoPtr->radShieldEquipped);
		radsuitInfoStr += " max: ";
		radsuitInfoStr += std::to_string(idHUD_HealthInfoPtr->radShieldDesc.maxValue);
		radsuitInfoStr += " cur: ";
		radsuitInfoStr += std::to_string(idHUD_HealthInfoPtr->radShieldDesc.currentValue);

		std::string oxygenInfoStr = "oxygenInfoStr: oxygenEquipped: ";
		oxygenInfoStr += K_Utils::getBoolAsStr(idHUD_HealthInfoPtr->oxygenEquipped);
		oxygenInfoStr += " max: ";
		oxygenInfoStr += std::to_string(idHUD_HealthInfoPtr->oxygenDesc.maxValue);
		oxygenInfoStr += " cur: ";
		oxygenInfoStr += std::to_string(idHUD_HealthInfoPtr->oxygenDesc.currentValue);

		std::string bpInfoStr = "bpInfoStr: is Visble: ";
		bpInfoStr += K_Utils::getBoolAsStr(idHUD_HealthInfoPtr->bloodPunchUnlockedAndVisible);

		resultStr += "\t" + radsuitInfoStr + "\n";
		resultStr += "\t" + oxygenInfoStr + "\n";
		resultStr += "\t" + bpInfoStr + "\n";
	}

	if (idHud_WeaponInfoPtr) {
		std::string crucibleInfoStr = "crucible : Equipped: ";
		crucibleInfoStr += K_Utils::getBoolAsStr(idHud_WeaponInfoPtr->crucibleEquipped);
		crucibleInfoStr += " shown: ";
		crucibleInfoStr += K_Utils::getBoolAsStr(idHud_WeaponInfoPtr->crucibleShown);
		crucibleInfoStr += " charge: ";
		crucibleInfoStr += std::to_string(idHud_WeaponInfoPtr->crucibleCharge);
		crucibleInfoStr += " max Charge: ";
		crucibleInfoStr += std::to_string(idHud_WeaponInfoPtr->crucibleMaxCharges);

		resultStr += "\t" + crucibleInfoStr + "\n";
	}

	//? have to be carefull with this one as aside from the charge the showing value will be false if the racecar hud is disabled.
	if (idHUD_AbilityIndicatorsPtr) {

		std::string bloodPunchInfoStr = "bloodPunch charges: ";
		bloodPunchInfoStr += std::to_string(idHUD_AbilityIndicatorsPtr->bloodPunchCharge);
		bloodPunchInfoStr += " Showing: ";
		bloodPunchInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->bloodPunchShowing);
		bloodPunchInfoStr += " PipShowing: ";
		bloodPunchInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->bloodPunchPipShowing);

		std::string hammerInfoStr = "hammer: Shown: ";
		hammerInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->hammerShown);
		hammerInfoStr += " Showing: ";
		hammerInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->hammerShowing);
		hammerInfoStr += " Recharge: ";
		hammerInfoStr += std::to_string(idHUD_AbilityIndicatorsPtr->hammerRecharge);
		hammerInfoStr += " Supercharge: ";
		hammerInfoStr += std::to_string(idHUD_AbilityIndicatorsPtr->hammerSupercharge);

		std::string flammebelchInfoStr = "flame: Showing: ";
		flammebelchInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->flameBelchShowing);
		flammebelchInfoStr += " charge: ";
		flammebelchInfoStr += std::to_string(idHUD_AbilityIndicatorsPtr->flameBelchCharge);

		std::string chainsawInfoStr = "chainsaw: : pipH: ";
		chainsawInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->chainsawHighPipShowing);
		chainsawInfoStr += " pipM: ";
		chainsawInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->chainsawMidPipShowing);
		chainsawInfoStr += " showing: ";
		chainsawInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->chainsawShowing);
		chainsawInfoStr += " charge: ";
		chainsawInfoStr += std::to_string(idHUD_AbilityIndicatorsPtr->chainsawCharge);


		std::string fragNadeInfoStr = "frag: showing: ";
		fragNadeInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->grenadeShowing);
		fragNadeInfoStr += " H_PipShow: ";
		fragNadeInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->grenadeHighPipShowing);
		fragNadeInfoStr += " H_HollowPipShow: ";
		fragNadeInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->grenadeHighHollowPipShowing);
		fragNadeInfoStr += " L_PipShow: ";
		fragNadeInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->grenadeLowPipShowing);
		fragNadeInfoStr += " L_HollowPipShow: ";
		fragNadeInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->grenadeLowHollowPipShowing);
		fragNadeInfoStr += " charge: ";
		fragNadeInfoStr += std::to_string(idHUD_AbilityIndicatorsPtr->grenadeCharge);


		std::string iceNadeInfoStr = "Ice: Showing:";
		iceNadeInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->iceGrenadeShowing);
		iceNadeInfoStr += " PipShow: ";
		iceNadeInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->icegrenadePipShowing);
		iceNadeInfoStr += " HollowPipShow: ";
		iceNadeInfoStr += K_Utils::getBoolAsStr(idHUD_AbilityIndicatorsPtr->icegrenadeHollowPipShowing);
		iceNadeInfoStr += " charge: ";
		iceNadeInfoStr += std::to_string(idHUD_AbilityIndicatorsPtr->iceGrenadeCharge);


		resultStr += "\t" + bloodPunchInfoStr + "\n";
		resultStr += "\t" + hammerInfoStr + "\n";
		resultStr += "\t" + flammebelchInfoStr + "\n";
		resultStr += "\t" + chainsawInfoStr + "\n";
		resultStr += "\t" + fragNadeInfoStr + "\n";
		resultStr += "\t" + iceNadeInfoStr + "\n";
	}

	if (idHUD_ExtraLivesPtr) {

		std::string extraLivexInfoStr = "ExtraLives : curr: ";
		extraLivexInfoStr += std::to_string(idHUD_ExtraLivesPtr->currentExtraLives);
		extraLivexInfoStr += " is Inf: ";
		extraLivexInfoStr += K_Utils::getBoolAsStr(idHUD_ExtraLivesPtr->infiniteExtraLives);

		resultStr += "\t" + extraLivexInfoStr + "\n";
	}

	return resultStr;

}


KaibzHudData KaibzHudManager::getTestData()
{
	static uint64_t lastDataChangeMs = 0;
	static int dummyValue = 0;
	static KaibzHudData data;	


	if (K_Utils::EpochMillis() - lastDataChangeMs > 100) {
		dummyValue++;		
		if (dummyValue > 200) {
			dummyValue = 0;
		}

		data.health = dummyValue;
		data.armor = dummyValue;
		data.ammo = dummyValue;

		lastDataChangeMs = K_Utils::EpochMillis();
	}


	return data;
}

//void KaibzHudManager::updateData()
//{
//
//}
