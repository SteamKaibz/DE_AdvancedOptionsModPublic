#pragma once





//? some of the code is also from main

	//! not needed anymore except if alt method fails...
			//if (EpochMillis() - lastCrosshairScaleCheckMs > 1000) {
			//	lastCrosshairScaleCheckMs = EpochMillis();
			//	//idPlayer_K::setReticleScaleTest(.5f);
			//}

			//if (EpochMillis() - lastCrosshairInScropCheckMs > 100) {
			//	lastCrosshairInScropCheckMs = EpochMillis();
			//	//! the idea is that the overideCrosshairInScope setting of the ini file will overide whatever game user setting is currently meaning that even if user has game reticleMode to dot or ful, game reticleMode will be overiden to none when not in scope
			//	
			//	//ReticleColorManager::HandleReticleDisplay();

			//	
			//}
			// 
			// 


			//! not using pulse anymore for game hud
			/*if (EpochMillis() - lastFragIconBlinkTestMs > 300) {
				lastFragIconBlinkTestMs = EpochMillis();

				if (IniFileData::getIsIceNadeIconPulse()) {
					idCmd::reapplySwfColorsCmd();
				}
				if (IniFileData::getOverrideFragGrenadeColor() == (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_GREEN) {
					IniFileData::debugForceFragNadeColor((int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_BLACK);
				}
				else if (IniFileData::getOverrideFragGrenadeColor() == (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_BLACK) {
					IniFileData::debugForceFragNadeColor((int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_GREEN);
				}
			}*/




			//! logging:

			/*if (EpochMillis() - lastIsInCinematicCheckkMs > 500) {
				lastIsInCinematicCheckkMs = EpochMillis();

				if (idPlayer_K::isInCinematicOrPOIVisible() != g_debugIsInCinematic) {
					g_debugIsInCinematic = idPlayer_K::isInCinematicOrPOIVisible();
					if (g_debugIsInCinematic) {
						logInfo("IsInCinematic is now true");
					}
					else {
						logInfo("IsInCinematic is now false");
					}
				}
			}*/


			/*if (EpochMillis() - lastIsReticleHideCheckkMs > 500) {
				lastIsReticleHideCheckkMs = EpochMillis();

				if (idPlayer_K::isHideReticle() != g_debugIsReticleHide) {
					g_debugIsReticleHide = idPlayer_K::isHideReticle();
					if (g_debugIsReticleHide) {
						logInfo("IsReticleHide is now true");
					}
					else {
						logInfo("IsReticleHide is now false");
					}
				}
			}*/


			//if (EpochMillis() - lastIsDemonPlayerCheckMs > 500) {
			//	lastIsDemonPlayerCheckMs = EpochMillis();
			//	if (idPlayer_K::isPlayerDemon() != g_debugIsDemonPlayer) {
			//		g_debugIsDemonPlayer = idPlayer_K::isPlayerDemon();
			//		if (g_debugIsDemonPlayer) {
			//			logWarn("WARNING: PLAYER IS NOW A DEMON, MOST MODS FEATURES ARE NOW DISABLED!");
			//		}
			//		else {
			//			logInfo("Player is now a Slayer.");
			//		}
			//		//logWarn("Main loop: debug g_debugIsDemonPlayer has changed to: %d", g_debugIsDemonPlayer);
			//	}
			//}


			/*if (EpochMillis() - lastGameModeCheckMs > 500) {
				lastGameModeCheckMs = EpochMillis();
				if (PlayerStateChecker::getCurrentGameModeStr() != g_debugLastCurrentGameMode) {
					g_debugLastCurrentGameMode = PlayerStateChecker::getCurrentGameModeStr();
					logInfo("Current Game mode has changed to: %s", g_debugLastCurrentGameMode.c_str());
				}
			}	*/


//if (EpochMillis() - lastDebugWarningMs > 1000) {
//	lastDebugWarningMs = EpochMillis();

	//logWarn("lastDebugWarningMs Reminder:");

	/*if (g_sleepTimeMainLoopMs == 0) {
		logWarn("g_sleepTimeMainLoopMs is 0...");
	}*/
	//logWarn("isImprovedSwitchingEnabled has been commented in  updateLastWeapKeyPress !!!!!");

}








//bool __fastcall isKeyPressedHook(__int64 ptr, __int64 btnEnum) {
//
//	usercmdButton userCmdBtn = (usercmdButton)btnEnum;
//	switch (userCmdBtn)
//	{
//		/*case usercmdButton::BUTTON_NONE: // not checking this cause NONE is the value of the default weapon btn to resend.
//			break;	*/
//	case usercmdButton::BUTTON_CHANGEWEAPON:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_CHANGEWEAPON)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_CHANGEWEAPON);
//		}
//		break;
//	case usercmdButton::BUTTON_WEAP_NEXT:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_WEAP_NEXT)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_WEAP_NEXT);
//		}
//		break;
//	case usercmdButton::BUTTON_WEAP_PREV:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_WEAP_PREV)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_WEAP_PREV);
//		}
//		break;
//	case usercmdButton::BUTTON_SHOTGUN:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_ASSAULT_RIFFLE:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_PLASMA:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_RL:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_SUPER_SHOTGUN:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_BALISTA:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_MINIGUN:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_BFG_UNMAKER:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_BFG_UNMAKER)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_BFG_UNMAKER);
//		}
//		break;
//	case usercmdButton::BUTTON_WEAP_9: //! no idea what this weapon is, don't think it exists.
//		break;
//	case usercmdButton::BUTTON_BFG:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_BFG)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_BFG);
//		}
//		break;
//	case usercmdButton::BUTTON_WALK:
//		break;
//	case usercmdButton::BUTTON_DASH:
//		break;
//	case usercmdButton::BUTTON_USE_EQUIPMENT:
//
//		eql.updateNadeStatus();
//
//		//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT pressed and  eql.isFragOwned() is {} eql.isIceOwned() {} eql.isFragRequestFlag(): {} eql.isIceRequestFlag() {}  eql.isFragSelected() {} eql.isIceSelected() {}", eql.isFragOwned(), eql.isIceOwned(), eql.isFragRequestFlag(), eql.isIceRequestFlag(), eql.isFragSelected(), eql.isIceSelected());
//
//		if (inv.isIceOwned() && eql.isIceRequestFlag() && eql.isFragSelected()) {
//			//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 1");
//			return false;
//		}
//		else if (inv.isIceOwned() && eql.isIceRequestFlag() && eql.isIceSelected()) {
//			eql.disableIceRequestFlag();
//			//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 2");
//			return true;
//		}
//		else if (inv.isFragOwned() && eql.isFragRequestFlag() && eql.isIceSelected()) {
//			//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 3");
//			return false;
//		}
//		else if (inv.isFragOwned() && eql.isFragRequestFlag() && eql.isFragSelected()) {
//			eql.disableFragRequestFlag();
//			//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 4");
//			return true;
//		}
//		else if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_USE_EQUIPMENT)) { //! if user actually pressed the key
//			if (inv.isFragOwned() && eql.isIceSelected()) {
//				eql.enableFragRequestFlag();
//				//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 5");
//				return false;
//			}
//			else if (inv.isFragOwned() && eql.isFragSelected()) {
//				eql.disableFragRequestFlag();
//				//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 6");
//				return true;
//			}
//		}
//		//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 7");
//		break;
//	case usercmdButton::BUTTON_SWITCH_EQUIPMENT:
//		//spdlog::info("isKeyPressedHook: BUTTON_SWITCH_EQUIPMENT pressed and  eql.isFragOwned() is {} eql.isIceOwned() {} eql.isFragRequestFlag(): {} eql.isIceRequestFlag() {}", eql.isFragOwned(), eql.isIceOwned(), eql.isFragRequestFlag(), eql.isIceRequestFlag());
//
//		eql.updateNadeStatus();
//
//		if (inv.isIceOwned() && eql.isIceRequestFlag() && eql.isFragSelected()) {
//			//spdlog::info("isKeyPressedHook: BUTTON_SWITCH_EQUIPMENT cond 1");
//			return true;
//		}
//		else if (inv.isFragOwned() && eql.isFragRequestFlag() && eql.isIceSelected()) {
//			//spdlog::info("isKeyPressedHook: BUTTON_SWITCH_EQUIPMENT cond 2");
//
//			return true;
//		}
//		//spdlog::info("isKeyPressedHook: BUTTON_SWITCH_EQUIPMENT cond 3");
//
//		break;
//	case usercmdButton::BUTTON_QUICK_3:
//		break;
//	case usercmdButton::BUTTON_INVENTORY:
//		break;
//	case usercmdButton::BUTTON_ACTIVATE_ABILITY:
//		break;
//	case usercmdButton::BUTTON_CRUCIBLE_HAMMER:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_CRUCIBLE_HAMMER)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_CRUCIBLE_HAMMER);
//		}
//		break;
//	case usercmdButton::BUTTON_OBJECTIVES:
//
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_OBJECTIVES)) {
//
//			eql.updateNadeStatus();
//			//eql.updateNadeStatus();
//
//			if (inv.isIceOwned()) {
//				eql.enableIceRequestFlag();
//				//spdlog::info("isKeyPressedHook: BUTTON_OBJECTIVES pressed and enabled ice request so isIceRequestFlag is: {}", eql.isIceRequestFlag());
//			}
//			//spdlog::info("isKeyPressedHook: BUTTON_OBJECTIVES about to return false...");
//			return false;
//		}
//		break;
//	default:
//		break;
//	}
//
//	return pisKeyPressed(ptr, btnEnum);
//}
