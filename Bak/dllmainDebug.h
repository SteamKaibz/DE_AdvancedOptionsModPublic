//#pragma once
//? some func might be duplicate but at least we have everything just in case.
// 
// 
//
//
//
//
//
//
//
//#include "stdafx.h"
//#include "Common.h"
//#include "SWIP.h"
////#include "Logger.h"
//#include "Utils.h"
//#include "dllmain.h"
//
////#include "spdlog/spdlog.h"
////#include "spdlog/sinks/basic_file_sink.h"
//
//#include "SWIP.h"
//#include <iostream>
//#include "DE/idCmd.h"
////#include "DE/HudAmmoData.h"
//#include "DE/GameSettings.h"
//#include"DE/Sigs.h"
//#include "DE/Addresses.h"
//#include "Debug/idPlayerDebug.h"
//#include "Debug/idInventoryManagerDebug.h"
//#include "DE/idFxManager.h"
//#include "Rtti/Rtti_Helper.h"
//#include "DE/ReticleSettings.h"
//#include "Debug/ReticleSettingsDebug.h"
//
//
// 
// 
// 
// 



//! 4CAD00 is triggered 4 times per image rendered and will call hud_string_Print_Smth_4CB340 twice each call in theory we can print 2 strings each call or 1 string and many icons.
//! However i managed to make it render 8 strings in one call with no apparent perf loss but let's be conservative. 
//! So far it's working great to show text and strings with not apparent perf loss. Also it fades in and out automatically with menus which is nice. it needs debug_hud_string cmd to be active for it to work though.
typedef __int64(__fastcall* printOutlinedStringMB_func)(
	__int64 idRenderModelGui_a1PtrToPtr,
	int a2,
	__int64 a3,
	int a4,
	__int64 a5,
	char* a6,
	int a7,
	int a8
	);

printOutlinedStringMB_func pPrintOutlinedStringMB = nullptr;
printOutlinedStringMB_func pPrintOutlinedStringMB_target;

_int64 __fastcall printOutlinedStringMB_hook(
	__int64 idRenderModelGui_a1PtrToPtr,
	int a2,
	__int64 a3,
	int a4,
	__int64 a5,
	char* a6,
	int a7,
	int a8
) {

	__int64 gui = *(__int64*)idRenderModelGui_a1PtrToPtr;

	//! keep this:
	if (MaterialDebug::isMaterialDebugMode()) {

		idRenderModelGuiManager::debugDrawMaterialLibMatr(gui, MaterialDebug::getTestMtr(), MaterialDebug::getTestMaterialName());

	}

	if (idInventoryCollectionManager::isItemOwned(ItemID::IceBomb) {
		return 1.0f; //! not rendering ice icon if not owned. the value returned here is arbitrary.
	}

	//? ofc this will not be here and that often:
	CustomIceNadeIconManager::updateCoords();
		CustomIceNadeIconManager::updateIsIceNadeCooldownStatus();
		CustomIceNadeIconManager::updateColors();
		CustomIceNadeIconManager::updateMaterials();
		CustomIceNadeIconManager::updateCooldownTimeLeftStr();

		idRenderModelGuiManager::drawIceIcon(gui, CustomIceNadeIconManager::getData());


	//auto debugTimers = CustomIceNadeIconManager::getDebugTimersStrs();

	//idRenderModelGuiManager::debugDrawString(gui, colorWhite, debugTimers.RechargeDurationStr.c_str(), 200, 100, 1.5);
	//idRenderModelGuiManager::debugDrawString(gui, colorYellow, debugTimers.RechargeTimeStr.c_str(), 200, 200, 1.5);
	//idRenderModelGuiManager::debugDrawString(gui, colorOrange, debugTimers.ReuseTimeStr.c_str(), 200, 300, 1.5);
	//idRenderModelGuiManager::debugDrawString(gui, colorGreen, debugTimers.StartTimeStr.c_str(), 200, 400, 1.5);
	//idRenderModelGuiManager::debugDrawString(gui, colorPurple, debugTimers.gameTimeStr.c_str(), 200, 500, 1.5);
	//idRenderModelGuiManager::debugDrawString(gui, colorLtGrey, debugTimers.countdownStr.c_str(), 200, 600, 1.5);


	/*idRenderModelGuiManager::drawDrawStretchPicSwfRect(*(__int64*)idRenderModelGui_a1PtrToPtr, iceSwfRect, MaterialLib::getIceNadeExtraBorderMtr(), iceNadeIcon_ExtraBorderColor);

	idRenderModelGuiManager::drawDrawStretchPicSwfRect(*(__int64*)idRenderModelGui_a1PtrToPtr, iceSwfRect, MaterialLib::getIceNadeBackgroundMtr(), iceNadeIcon_BackgroundColor);

	idRenderModelGuiManager::drawDrawStretchPicSwfRect(*(__int64*)idRenderModelGui_a1PtrToPtr, iceSwfRect, MaterialLib::getIceNadeBorderMtr(), baseIceBackGroundColor);


	idRenderModelGuiManager::drawDrawStretchPicSwfRect(*(__int64*)idRenderModelGui_a1PtrToPtr, iceIconSwfRect, MaterialLib::getIceGrenadeMtr(), iceNadeIcon_IconColor);*/














	//? if our current CustomIceNadeIconManager test is failling this is what you want to uncomment:


	//auto rectVec4_1 = idVec4(100, 700, 50, 30);
	//auto rectVec4_2 = idVec4(150, 700, 50, 30);
	//auto rectVec4_3 = idVec4(200, 700, 50, 30);

	//auto rectVec4_Fill_1 = idVec4(110, 700, 70, 30);
	//auto rectVec4_Fill_2 = idVec4(150, 700, 50, 30);
	//auto rectVec4_Fill_3 = idVec4(200, 700, 50, 30);

	//auto rectVec4_4 = idVec4(200, 500, 50, 30);
	//auto rectVec4_5 = idVec4(200, 600, 200, 30);

	//

	//auto fragIconSwfRect = GameHudColorsManager::debugGetFragBorderCoords();
	//
	//swfRect_t iceSwfRect;
	//float rectWidth = fragIconSwfRect.br.x - fragIconSwfRect.tl.x;
	//float rightOffsetMul = .675f; // was .68
	//iceSwfRect.tl.x = rightOffsetMul * rectWidth + fragIconSwfRect.tl.x;
	//iceSwfRect.br.x = rightOffsetMul * rectWidth + fragIconSwfRect.br.x;
	//iceSwfRect.tl.y = fragIconSwfRect.tl.y;
	//iceSwfRect.br.y = fragIconSwfRect.br.y;

	//swfRect_t iceIconSwfRect;
	//float iceContainerRectWidth = iceSwfRect.br.x - iceSwfRect.tl.x;
	//float iceContainerRectHeight = iceSwfRect.br.y - iceSwfRect.tl.y;
	//float iconScale = .29f;
	//iceIconSwfRect.tl.x = iceSwfRect.tl.x + iconScale * iceContainerRectWidth;
	//iceIconSwfRect.tl.y = iceSwfRect.tl.y + iconScale * iceContainerRectHeight;
	//iceIconSwfRect.br.x = iceSwfRect.br.x - iconScale * iceContainerRectWidth;
	//iceIconSwfRect.br.y = iceSwfRect.br.y - iconScale * iceContainerRectHeight;

	////todo when ice nade deactivated the icon color should be the same color as the background, especially as we'll have text on the icon

	////! using custom colors:
	//idColor baseIceIconColor = colorDkGrey;
	//idColor baseIceBackGroundColor = colorDkGrey;

	////! using default profile game color
	///*idColor baseIceIconColor = GameHudColorsManager::getCurrentProfileIceNadeIconColor();
	//idColor baseIceBackGroundColor = GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor();*/

	//GameHudColorsManager::setIconWhiteBlendColor(baseIceIconColor, iceNadeIcon_IconColor, .45f);
	//GameHudColorsManager::setIconExtraBorderColor(baseIceBackGroundColor, iceNadeIcon_ExtraBorderColor);
	//GameHudColorsManager::setIconBackgroundColor(baseIceBackGroundColor, iceNadeIcon_BackgroundColor);

	//idRenderModelGuiManager::drawDrawStretchPicSwfRect(*(__int64*)idRenderModelGui_a1PtrToPtr, iceSwfRect, MaterialLib::getIceNadeExtraBorderMtr(), iceNadeIcon_ExtraBorderColor);

	//idRenderModelGuiManager::drawDrawStretchPicSwfRect(*(__int64*)idRenderModelGui_a1PtrToPtr, iceSwfRect, MaterialLib::getIceNadeBackgroundMtr(), iceNadeIcon_BackgroundColor);

	//idRenderModelGuiManager::drawDrawStretchPicSwfRect(*(__int64*)idRenderModelGui_a1PtrToPtr, iceSwfRect, MaterialLib::getIceNadeBorderMtr(), baseIceBackGroundColor);
	//

	//idRenderModelGuiManager::drawDrawStretchPicSwfRect(*(__int64*)idRenderModelGui_a1PtrToPtr, iceIconSwfRect, MaterialLib::getIceGrenadeMtr(), iceNadeIcon_IconColor);


	////! countdown 2 chars
	//static int count = 30;
	//static std::string iceCooldownText = "??";
	//static uint64_t lastTextChangeMs = 0;

	//if (EpochMillis() - lastTextChangeMs > 500) {
	//	lastTextChangeMs = EpochMillis();
	//	if (count <= 0) {
	//		count = 30;
	//	}
	//	else {
	//		count--;
	//	}
	//	if (count < 10) {
	//		iceCooldownText =  "0" + std::to_string(count);
	//	}
	//	else {
	//		iceCooldownText = std::to_string(count);
	//	}
	//}
	//const char* testText = iceCooldownText.c_str();
	//
	//idRenderModelGuiManager::drawIceNadeCooldownText(*(__int64*)idRenderModelGui_a1PtrToPtr, colorLtGrey, iceCooldownText, idVec4(iceIconSwfRect), .8f, false);




















	/*idRenderModelGuiManager::drawDrawStretchPicTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4_Fill_1.x, rectVec4_Fill_1.y, rectVec4_Fill_1.w, rectVec4_Fill_1.h, MaterialLib::getIceBarBgMtr(), colorWhite, true);

	idRenderModelGuiManager::drawDrawStretchPicTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4_Fill_2.x, rectVec4_Fill_2.y, rectVec4_Fill_2.w, rectVec4_Fill_2.h, MaterialLib::getIceBarBgMtr(), colorWhite, true);

	idRenderModelGuiManager::drawDrawStretchPicTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4_Fill_3.x, rectVec4_Fill_3.y, rectVec4_Fill_3.w, rectVec4_Fill_3.h, MaterialLib::getIceBarBgMtr(), colorWhite, true);


	idRenderModelGuiManager::drawDrawStretchPicTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4_1.x, rectVec4_1.y, rectVec4_1.w, rectVec4_1.h, MaterialLib::getIceBarRightMtr(), colorWhite, true);

	idRenderModelGuiManager::drawDrawStretchPicTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4_2.x, rectVec4_2.y, rectVec4_2.w, rectVec4_2.h, MaterialLib::getIceBarMidMtr(), colorWhite);

	idRenderModelGuiManager::drawDrawStretchPicTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4_3.x, rectVec4_3.y, rectVec4_3.w, rectVec4_3.h, MaterialLib::getIceBarLeftMtr(), colorWhite, true);*/





	/*idRenderModelGuiManager::drawDrawStretchPicTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4_4.x, rectVec4_4.y, rectVec4_4.w, rectVec4_4.h, MaterialLib::getLiveTestMtr(), colorWhite, true);

	idRenderModelGuiManager::drawDrawStretchPicTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4_5.x, rectVec4_5.y, rectVec4_5.w, rectVec4_5.h, MaterialLib::getLiveTestMtr(), colorWhite, true);


	idRenderModelGuiManager::debugDrawString(*(__int64*)idRenderModelGui_a1PtrToPtr, colorPurple, MaterialLib::getLiveTestMtrStr().c_str(), 50, 400, 1.5);*/

	//logInfo("printOutlinedStringMB_hook HudTracker::curIndex: %d", HudTracker::curIndex);
	//HudTracker::curIndex++;
	//static int debugCounter = 0;

	//return pPrintOutlinedStringMB(idRenderModelGui_a1PtrToPtr, a2, a3, a4, a5, a6, a7, a8);

	//return pPrintOutlinedStringMB(idRenderModelGui_a1PtrToPtr, a2, a3, a4, a5, a6, a7, a8);

	// Your custom code here...

	//logInfo("printOutlinedStringMB_hook: idRenderModelGui_a1PtrToPtr: %p", (void*)idRenderModelGui_a1PtrToPtr);

	//idRenderModelGuiManager::drawAllNeededIconsTest(*(__int64*)idRenderModelGui_a1PtrToPtr);

	//idRenderModelGuiManager::drawStringsTest(*(__int64*)idRenderModelGui_a1PtrToPtr);
	//idRenderModelGuiManager::drawStringsTest2(*(__int64*)idRenderModelGui_a1PtrToPtr, 18);
	/*static float debugLastSmallCharHeight = 0;

	if (idRenderModelGuiManager::getSmallCharHeight() != debugLastSmallCharHeight) {
		logInfo("debug: getSmallCharHeight has changed to: %.2f", idRenderModelGuiManager::getSmallCharHeight());
		debugLastSmallCharHeight = idRenderModelGuiManager::getSmallCharHeight();
	}*/


	/*float _x = 100.0f;
	float _y = 100.0f;*/

	//static std::string textStr = "  0";
	//std::string textStr = "_______";
	//std::string textStr = "helloooOXXXXX";
	//std::string textStr = "helloooO";
	//std::string textStr = "hellh";
	//std::string textStr = "ABCD";
	//std::string textStr = "120";	
	//std::string textStr = "12";	
	//std::string textStr = "1";
	//std::string textStr = "A";
	//std::string textStr = "a";

	//! Fixed lenght text like Health that has to occupy the same space whether it's 200 or 0
	/*static uint64_t lastTextChangeMs = 0;
	if (EpochMillis() - lastTextChangeMs > 1000) {
		lastTextChangeMs = EpochMillis();
		if (textStr == "  0") {
			textStr = "200";
		}
		else if (textStr == "200") {
			textStr = "100";
		}
		else if (textStr == "100") {
			textStr = " 10";
		}
		else if (textStr == " 10") {
			textStr = "  0";
		}
		else {
			textStr = "  0";
		}
	}
	const char* testText = textStr.c_str();*/

	//! Variable lenght Text, like timer that goes from 30 to 0
	/*static uint64_t lastTextChangeMs = 0;
	if (EpochMillis() - lastTextChangeMs > 1000) {
		lastTextChangeMs = EpochMillis();
		if (textStr == "0") {
			textStr = "200";
		}
		else if (textStr == "200") {
			textStr = "100";
		}
		else if (textStr == "100") {
			textStr = "10";
		}
		else if (textStr == "10") {
			textStr = "0";
		}
		else {
			textStr = "0";
		}
	}
	const char* testText = textStr.c_str();*/

	//! countdown 2 chars
	//static int count = 30;
	////static std::string countDownText = "?";
	//static uint64_t lastTextChangeMs = 0;

	//if (EpochMillis() - lastTextChangeMs > 500) {
	//	lastTextChangeMs = EpochMillis();
	//	if (count <= 0) {
	//		count = 30;
	//	}
	//	else {
	//		count--;
	//	}
	//	if (count < 10) {
	//		textStr =  "0" + std::to_string(count);
	//	}
	//	else {
	//		textStr = std::to_string(count);
	//	}
	//}
	//const char* testText = textStr.c_str();

	/*float rectWidth = 200.0f;
	float rectHeight = 70.0f;*/

	//float scaleTest1 = 3.0f;
	//float scaleTest2 = 6.0f;
	// float scaleTest = 6.0f;
	//float scaleTest = 1.0f;

	//! this is the rect in which we want a string centered
	//auto rectVec4 = idVec4(100, 400, 200, 40);

	//auto rectVec4 = idVec4(100, 400, 100, 50);

	//__int64 glyphDataAddr = idFontManager::getGlyphDataAddr(textStr.c_str());
	//logInfo("main: glyphDataAddr: %p", (void*)glyphDataAddr);


	//idRenderModelGuiManager::debugDrawColoredRect(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4.x, rectVec4.y, rectVec4.w, rectVec4.h, colorRed);

	//rectVec4.x += 300; //! doing that so we can compare sizes	


	//! the problem we have with this is that the string will be centered for certaine fonts but not for others, if you ever want to go back to this someday know that the default font, is the one that is centered for all the scales.Also read the comment above drawStringCenteredInBounds for more info
	/*idRenderModelGuiManager::drawStringCenteredInBounds(*(__int64*)idRenderModelGui_a1PtrToPtr, colorGreen, textStr, rectVec4, true);

	idRenderModelGuiManager::drawStringCenteredInBounds(*(__int64*)idRenderModelGui_a1PtrToPtr, colorGreen, textStr, rectVec4_2, true);

	idRenderModelGuiManager::drawStringCenteredInBounds(*(__int64*)idRenderModelGui_a1PtrToPtr, colorGreen, textStr, rectVec4_3, true);

	idRenderModelGuiManager::drawStringCenteredInBounds(*(__int64*)idRenderModelGui_a1PtrToPtr, colorGreen, textStr, rectVec4_4, true);*/




	//? this is shit afaik
	/*idRenderModelGuiManager::debugDrawString(*(__int64*)idRenderModelGui_a1PtrToPtr, colorPurple, idFontManager::getCurrentFontAsStr().c_str(), 800, 700, 2);

	auto ascenderTestVecRect = idVec4(700, 600, 100, 100);
	idRenderModelGuiManager::debugDrawColoredRect(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4.x, rectVec4.y, rectVec4.w, rectVec4.h, colorRed);

	float scaleTest = 4.0f;

	auto fontInfoPtr = idFontManager::getFontInfoPtr();
	if (fontInfoPtr) {
		float scaledAscender = fontInfoPtr->ascender * scaleTest;
		float scaledDescender = fontInfoPtr->descender * scaleTest;
		float scaledFontHeight = scaledAscender - scaledDescender;
		logInfo("scaledFontHeight: %.2f", scaledFontHeight);
		float middle_y =  650 - scaledFontHeight / 2;
		logInfo("middle_y: %.2f", middle_y);


		idRenderModelGuiManager::debugDrawString(*(__int64*)idRenderModelGui_a1PtrToPtr, colorWhite, "2", 750, middle_y, scaleTest);

	}*/







	//! this is an alternative attempt with fixed sized char count:
	//idRenderModelGuiManager::debugFixedCharWidthStringInRect(*(__int64*)idRenderModelGui_a1PtrToPtr, colorGreen, textStr, rectVec4, 2);


	/*idRenderModelGuiManager::debugDrawString(*(__int64*)idRenderModelGui_a1PtrToPtr, colorBlack, "100  150       75", 51, 501, 1);
	idRenderModelGuiManager::debugDrawString(*(__int64*)idRenderModelGui_a1PtrToPtr, colorWhite, "100  150       75", 50, 500, 1);*/



	/*idRenderModelGuiManager::setColor(*(__int64*)idRenderModelGui_a1PtrToPtr, colorDarkBlue);
	float pip_x = 50;
	for (size_t i = 0; i < 10; i++)
	{
		idRenderModelGuiManager::drawDrawStretchPicTest5(*(__int64*)idRenderModelGui_a1PtrToPtr, pip_x, 400, 30, 50, MaterialLib::getMtr("swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_pip_empty_"));
		pip_x +=35;

	}*/

	/*auto normalizedRect = idRenderModelGuiManager::debugGetNormalizedStringContainerRect(rectVec4, textStr.size());




	idRenderModelGuiManager::debugDrawColoredRect(*(__int64*)idRenderModelGui_a1PtrToPtr, normalizedRect.x+300, normalizedRect.y, normalizedRect.w, normalizedRect.h, colorGreen);



	float computedTextScale = idRenderModelGuiManager::getFontScaleFromWidthV3(rectVec4, textStr.size());

	idRenderModelGuiManager::debugDrawString(*(__int64*)idRenderModelGui_a1PtrToPtr, colorOrange, testText,  idRenderModelGuiManager::debugGetString_X(rectVec4, textStr.size()), rectVec4.y, computedTextScale);*/


	return 1; //? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!






	/*float str_x = idRenderModelGuiManager::debugGetString_X(rectVec4, textStr.size());

	float computedTextScale = idRenderModelGuiManager::getFontScaleFromWidthV2(rectVec4, textStr.size());*/

	//auto str_X_Offset = idRenderModelGuiManager::debugGetTextCentered_X(rectVec4, textStr.size());

	//logInfo("str_x: %.2f computedTextScale: %.2f str_X_Offset: %.2f", str_x, computedTextScale, str_X_Offset);
	//logInfo("str_x: %.2f computedTextScale: %.2f ", str_x, computedTextScale );

	//float x_offsetInDrawString = idRenderModelGuiManager::getSmallCharWidth() * idRenderModelGuiManager::getUseScaleVal() ;

	/*float x_offsetKaibzEdition = (idRenderModelGuiManager::getSmallCharWidth() / 2) * scaleTest * .34f;
	float y_offsetKaibzEdition = (idRenderModelGuiManager::getSmallCharHeight() / 2) * scaleTest * .34f;*/

	//unsigned int strLenght = idRenderModelGuiManager::GetStringWidthInPixels(testText, scaleTest);

	// Scale the height by the scaleTest factor
	//float scaledHeight = idRenderModelGuiManager::getSmallCharHeight() * scaleTest;

	//idRenderModelGuiManager::drawDrawStretchPicTest5(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4.x, rectVec4.y, rectVec4.w, rectVec4.h,  MaterialLib::getWhite());
	////idRenderModelGuiManager::drawDrawStretchPicTest5(*(__int64*)idRenderModelGui_a1PtrToPtr, _x - x_offsetInDrawString, _y - scaledHeight/2, (float)strLenght, scaledHeight, MaterialLib::getWhite());
	////idRenderModelGuiManager::drawDrawStretchPicTest5(*(__int64*)idRenderModelGui_a1PtrToPtr, _x, _y - scaledHeight/2, (float)strLenght, scaledHeight, MaterialLib::getWhite());

	//idRenderModelGuiManager::drawStringsTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, testText, idRenderModelGuiManager::debugGetString_X(rectVec4, textStr.size()), rectVec4.y, computedTextScale);
	////idRenderModelGuiManager::drawStringsTest3(*(__int64*)idRenderModelGui_a1PtrToPtr, testText, _x + (idRenderModelGuiManager::getSmallCharWidth() * scaleTest)/2, _y, scaleTest);


	//idRenderModelGuiManager::drawDrawStretchPicTest5(*(__int64*)idRenderModelGui_a1PtrToPtr, rectVec4.x , rectVec4.y + 200, idRenderModelGuiManager::debugGetStringLengthInPixel(rectVec4, textStr.size()), rectVec4.h, MaterialLib::getWhite());





	//idRenderModelGuiManager::drawDrawStretchPicTest5(*(__int64*)idRenderModelGui_a1PtrToPtr, _x + strLenght, _y, 100.0f, 100.0f, MaterialLib::getWhite());

	//idRenderModelGuiManager::drawDrawStretchPicTest5(*(__int64*)idRenderModelGui_a1PtrToPtr, _x + strLenght, _y - (idRenderModelGuiManager::getSmallCharHeight() / 2), (float)strLenght, idRenderModelGuiManager::getSmallCharHeight(), MaterialLib::getWhite());



	//if (HudElement::index == 0) {
	//	
	//	x_a2 = HudDataBuffer::health.outlineText_X;
	//	y_a3 = HudDataBuffer::health.outlineText_Y;
	//	text_a4 = HudDataBuffer::health.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::health.outlineColor;
	//	scale_a7 = HudDataBuffer::health.outlineScale;		

	//	//logInfo("idRenderModelGui_DrawStringHook: x_a2: %.2f  y_a3: %.2f text_a4: %s, idColor_a5: %p scale_a7: %.3f", x_a2, y_a3, text_a4, (void*)idColor_a5, scale_a7);

	//	HudElement::index++;
	//}

	//else if (HudElement::index == 1) {

	//	x_a2 = HudDataBuffer::health.fillText_X;
	//	y_a3 = HudDataBuffer::health.fillText_Y;
	//	text_a4 = HudDataBuffer::health.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::health.fillColor;
	//	scale_a7 = HudDataBuffer::health.fillScale;

	//	HudElement::index++;
	//}

	//else if (HudElement::index == 2) {


	//	x_a2 = HudDataBuffer::armor.outlineText_X;
	//	y_a3 = HudDataBuffer::armor.outlineText_Y;
	//	text_a4 = HudDataBuffer::armor.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::armor.outlineColor;
	//	scale_a7 = HudDataBuffer::armor.outlineScale;	

	//	HudElement::index++;
	//}

	//else if (HudElement::index == 3) {
	//	x_a2 = HudDataBuffer::armor.fillText_X;
	//	y_a3 = HudDataBuffer::armor.fillText_Y;
	//	text_a4 = HudDataBuffer::armor.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::armor.fillColor;
	//	scale_a7 = HudDataBuffer::armor.fillScale;

	//	HudElement::index++;
	//}

	//else if (HudElement::index == 4) {

	//	x_a2 = HudDataBuffer::ammo.outlineText_X;
	//	y_a3 = HudDataBuffer::ammo.outlineText_Y;
	//	text_a4 = HudDataBuffer::ammo.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::ammo.outlineColor;
	//	scale_a7 = HudDataBuffer::ammo.outlineScale;

	//	HudElement::index++;
	//}

	//else if (HudElement::index == 5) {

	//	x_a2 = HudDataBuffer::ammo.fillText_X;
	//	y_a3 = HudDataBuffer::ammo.fillText_Y;
	//	text_a4 = HudDataBuffer::ammo.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::ammo.fillColor;
	//	scale_a7 = HudDataBuffer::ammo.fillScale;

	//	HudElement::index++;
	//}

	//else if (HudElement::index == 6) {

	//	x_a2 = HudDataBuffer::ammo.fillText_X + 10;
	//	y_a3 = HudDataBuffer::ammo.fillText_Y + 10;
	//	text_a4 = HudDataBuffer::ammo.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::ammo.fillColor;
	//	scale_a7 = HudDataBuffer::ammo.fillScale;

	//	HudElement::index++;
	//}

	//else if (HudElement::index == 7) {

	//	x_a2 = HudDataBuffer::ammo.fillText_X + 20;
	//	y_a3 = HudDataBuffer::ammo.fillText_Y + 20;
	//	text_a4 = HudDataBuffer::ammo.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::ammo.fillColor;
	//	scale_a7 = HudDataBuffer::ammo.fillScale;

	//	HudElement::index++;
	//}

	//else if (HudElement::index == 8) {

	//	x_a2 = HudDataBuffer::ammo.fillText_X + 40;
	//	y_a3 = HudDataBuffer::ammo.fillText_Y + 40;
	//	text_a4 = HudDataBuffer::ammo.text;
	//	idColor_a5 = (__int64)&HudDataBuffer::ammo.fillColor;
	//	scale_a7 = HudDataBuffer::ammo.fillScale;

	//	HudElement::index++;
	//}

	//else {
	//	text_a4 ="";
	//}







	return 1;

	// Call the original function
	//return pPrintOutlinedStringMB(idRenderModelGui_a1PtrToPtr, a2, a3, a4, a5, a6, a7, a8);
}








// //! void __fastcall idHUD_Reticle::SetActiveReticle_15773A0(__int64 idMenu, signed int x_a2, __int64 y_a3, unsigned __int8 text_a4)
typedef void(__fastcall* idHUD_Reticle_SetActiveReticle)(__int64 a1, unsigned int a2, idDeclWeaponReticle* a3, unsigned __int8 a4);
idHUD_Reticle_SetActiveReticle pidHUD_Reticle_SetActiveReticle = nullptr;
idHUD_Reticle_SetActiveReticle pidHUD_Reticle_SetActiveReticleTarget;

void __fastcall idHUD_Reticle_SetActiveReticleHook(__int64 idHUD_Reticle_a1, unsigned int reticleIndex_a2, idDeclWeaponReticle* idDeclWeaponReticle_a3, unsigned __int8 a4) {

	//logInfo("idHUD_Reticle_SetActiveReticleHook");
	PlayerStateChecker::updateLastReticleRefresh(); //todo we should not use that

	//todo i guess this could mean we should use our idClasses to include all offset related to that idClass and use them this way.
	//Ida
	__int64 idSWFWidget_Hud_Reticle_v8 = 0;
	unsigned int activeReticleStyle = *(unsigned int*)(idHUD_Reticle_a1 + 0x330);
	if (reticleIndex_a2 != activeReticleStyle || idDeclWeaponReticle_a3 != (idDeclWeaponReticle*)(idHUD_Reticle_a1 + 0x338)) {
		if (reticleIndex_a2 > 0x24) {
			idSWFWidget_Hud_Reticle_v8 = 0i64;
		}
		else {
			idSWFWidget_Hud_Reticle_v8 = *(__int64*)(idHUD_Reticle_a1 + 8i64 * (int)reticleIndex_a2 + 0x208);
		}
	}
	//? idSWFWidget_Hud_Reticle_v8 will be null when the ingame reticle mode is set to None so the rest of this code will not trigger, obviously
	if (idSWFWidget_Hud_Reticle_v8) {
		__int64 idSWFSpriteInstance_v17 = *(__int64*)(idSWFWidget_Hud_Reticle_v8 + 0x18);

		idSWFSpriteInstanceManager::setHitMarkerState((idHUD_Reticle*)idHUD_Reticle_a1, IniFileData::getIsDisableHitMarker());

		//! this is how we manage to change the scale of the crosshair even when it's already displayed
		if (idDeclWeaponReticle_a3 && idSWFSpriteInstance_v17) {
			ReticleScaleManager::setIsSpriteReloadedNeeded(ReticleScaleManager::updateScale(idDeclWeaponReticle_a3));
			if (ReticleScaleManager::isSpriteReloadedNeeded()) {
				if (SpriteInstanceManager::updateScale(idSWFSpriteInstance_v17, idDeclWeaponReticle_a3->reticleModelScale)) {
					ReticleScaleManager::setIsSpriteReloadedNeeded(false);
				}
				else {
					ReticleScaleManager::setIsSpriteReloadedNeeded(true);
				}
			}	//if (ReticleScaleManager::updateScale(idDeclWeaponReticle_a3))

		}
	}

	// still need to fix the __int64 mistake for reticle index and make sure you force the reticle mode to be either dot or full when switching immersive crosshair and a bad ptr check for the sprite instance itself but yeah it works great, keep this for doc may be.
	/*if (idDeclWeaponReticle_a3) {
		idDeclWeaponReticle* declWeaponReticle = (idDeclWeaponReticle*) idDeclWeaponReticle_a3;

		if (declWeaponReticle->getNameStr() == Reticle::g_weaponreticleHeavyCannonBoltActionZoomed) {
			if (declWeaponReticle->reticleModelScale != 1.0f) {
				declWeaponReticle->reticleModelScale = 1.0f;
				logInfo("1: idHudManager::updateReticleSprite triggered");
				idHudManager::updateReticleSprite(idHUD_Reticle_a1, declWeaponReticle->reticleModelScale);
			}

		}
		else if (declWeaponReticle->getNameStr() == Reticle::g_weaponreticleGaussBallista && idPlayer_K::wantZoom()) {
			if (declWeaponReticle->reticleModelScale != 1.0f) {
				declWeaponReticle->reticleModelScale = 1.0f;
				logInfo("2: idHudManager::updateReticleSprite triggered");
				idHudManager::updateReticleSprite(idHUD_Reticle_a1, declWeaponReticle->reticleModelScale);
			}
		}
		else {
			if (declWeaponReticle->reticleModelScale != 0.001f) {
				declWeaponReticle->reticleModelScale = 0.001f;
				float reticleScale = declWeaponReticle->reticleModelScale;
				logInfo("3: idHudManager::updateReticleSprite triggered and reticleScale is: %.3f", reticleScale);
				idHudManager::updateReticleSprite(idHUD_Reticle_a1, declWeaponReticle->reticleModelScale);
			}
		}*/


		//}	
		//logInfo("idHUD_Reticle_SetActiveReticleHook, idDeclWeaponReticle_a3: %p, reticleIndex_a2: %d", (void*)idDeclWeaponReticle_a3, reticleIndex_a2),


		//! this scales down the dot crosshair from the game so that our custom one will cover it whatever happens
		/* if (GameSettings::getReticleMode() == (int)gameSettingsCrosshairMode::DOT) {
			HudManager::scaleDownGameDotCrosshair(idDeclWeaponReticle_a3);
		}
		else if (GameSettings::getReticleMode() == (int)gameSettingsCrosshairMode::FULL) {
			HudManager::setGameCrosshairScaleToDefaultValue(idDeclWeaponReticle_a3);
		}*/

	pidHUD_Reticle_SetActiveReticle(idHUD_Reticle_a1, reticleIndex_a2, idDeclWeaponReticle_a3, a4);
}
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//
////void testFindCvarSystemPtr2() {
////	if (Addresses::cvarSystemHelperSigAddr == 0) {
////	logErr:"testFindCvarSystemPtr2 cvarSystemHelperAddr is 0, failed. ";
////		return;
////	}
////	logInfo("testFindCvarSystemPtr2 cvarSystemHelperAddr is %p", (void*)Addresses::cvarSystemHelperSigAddr);
////	uintptr_t relativeOffsetAddr = (Addresses::cvarSystemHelperSigAddr + 3);
////	logInfo("testFindCvarSystemPtr2 relativeOffsetAddr is %p", (void*)relativeOffsetAddr);
////
////	// Open a handle to the current process (assumes your proxy DLL is attached to the game's process).
////	HANDLE hProcess = GetCurrentProcess();
////
////	// Buffer to store the read data.
////	uint8_t buffer[4]; // Assuming you want to read 4 bytes.
////
////	// Read the 4 bytes from the specified address in the game's memory.
////	SIZE_T bytesRead;
////	//! int and not uint as the offset has to be signed
////	int relativeOffsetValue = 0;
////	if (ReadProcessMemory(hProcess, (LPCVOID)relativeOffsetAddr, buffer, sizeof(buffer), &bytesRead)) {
////		if (bytesRead == sizeof(buffer)) {
////			// Successfully read 4 bytes.
////			// Convert the bytes to an integer value.
////			int relativeOffsetValue = *reinterpret_cast<int*>(buffer);
////
////			// Now 'value' contains the integer value read from memory.
////			logInfo("testFindCvarSystemPtr2 int value is %X", relativeOffsetValue);
////		}
////		else {
////			logErr("testFindCvarSystemPtr2 ReadProcessMemory did not read the expected number of bytes");
////			return;
////		}
////	}
////	else {
////		logErr("testFindCvarSystemPtr2 Failed to read process memory. Error code: %d", GetLastError());
////		return;
////	}
////	
////	//! this is the value of rip as rip always has the addresse of the next instruction:
////	uintptr_t nextInstructionAddress = Addresses::cvarSystemHelperSigAddr + 7;
////	logInfo("testFindCvarSystemPtr2 nextInstructionAddress is %p", (void*)nextInstructionAddress);
////	uintptr_t cvarSystemPtr = nextInstructionAddress + relativeOffsetValue;
////	logInfo("testFindCvarSystemPtr2 computed cvarSystemPtr to be %p", (void*)cvarSystemPtr);
////
////}
//
//
//
////void FindPointerTest() {
////	uintptr_t instructionStartAddress = patternScanForInstructionStartAddress();
////	if (instructionStartAddress <= 0) {
////	logErr:"FindPointerTest instructionStartAddress is 0, failed. ";
////		return;
////	}
////	logInfo("FindPointerTest instructionStartAddress is %p", (void*)instructionStartAddress);
////	// adding 3 cause we want to the address of the "value" 72 F8 78 03 which is a relative offset, the value is little indian so the actual value is 0x378F872
////	uintptr_t relativeOffsetAddr = (instructionStartAddress + 3);
////	logInfo("FindPointerTest relativeOffsetAddr is %p", (void*)relativeOffsetAddr);
////	// Open a handle to the current process ( proxy DLL is attached to the game's process).
////	HANDLE hProcess = GetCurrentProcess();
////	// Buffer to store the read data.
////	uint8_t buffer[4]; // need to read 4 bytes.	
////	SIZE_T bytesRead;
////	// int and NOT uint as the offset is signed
////	int relativeOffsetValue = 0;
////	if (ReadProcessMemory(hProcess, (LPCVOID)relativeOffsetAddr, buffer, sizeof(buffer), &bytesRead)) {
////		if (bytesRead == sizeof(buffer)) {
////			// Successfully read 4 bytes and convert the bytes to an integer value.
////			int relativeOffsetValue = *reinterpret_cast<int*>(buffer);
////			// Now 'relativeOffsetValue' contains the integer value read from memory.
////			logInfo("FindPointerTest relativeOffsetValue: %X", relativeOffsetValue);
////		}
////		else {
////			logErr("FindPointerTest ReadProcessMemory did not read the expected number of bytes");
////			return;
////		}
////	}
////	else {
////		logErr("FindPointerTest Failed to read process memory. Error code: %d", GetLastError());
////		return;
////	}
////	// nextInstructionAddress is the value of rip as rip always has the address of the next instruction, adding 7 because the next instruction is at address 0xAD4D27 + 7 (0xAD4D2E)
////	uintptr_t nextInstructionAddress = instructionStartAddress + 7;
////	logInfo("FindPointerTest nextInstructionAddress is %p", (void*)nextInstructionAddress);
////	uintptr_t myPtr = nextInstructionAddress + relativeOffsetValue;
////	logInfo("FindPointerTest myPtr is %p", (void*)myPtr);
////
////}
//
////! this works but it seems to crash afterward, (acces violation?) or was it just a bug cause CE was running?
////void testFindCvarSystemPtr() {
////	if (Addresses::cvarSystemHelperAddr == 0) {
////	logErr:"testFindCvarSystemPtr cvarSystemHelperAddr is 0, failed. ";
////		return;
////	}
////	logInfo("testFindCvarSystemPtr cvarSystemHelperAddr is %p", (void*)Addresses::cvarSystemHelperAddr);
////	uintptr_t relativeOffsetAddr = (Addresses::cvarSystemHelperAddr + 3);
////	logInfo("testFindCvarSystemPtr relativeOffsetAddr is %p", (void*)relativeOffsetAddr);
////	//! int and not uint as the offset has to be signed
////	/*if (MemHelper::isBadReadPtr((void*)relativeOffsetAddr)){
////		logInfo("testFindCvarSystemPtr relativeOffsetAddr is bad ptr returning");
////		return;
////	}*/
////	int relativeOffsetValue = *(int*)relativeOffsetAddr;
////	logInfo("testFindCvarSystemPtr relativeOffsetValue is %x", relativeOffsetValue);
////	//! this is the value of rip as rip always has the addresse of the next instruction:
////	uintptr_t nextInstructionAddress = Addresses::cvarSystemHelperAddr + 7;
////	logInfo("testFindCvarSystemPtr nextInstructionAddress is %p", (void*)nextInstructionAddress);
////	uintptr_t cvarSystemPtr = nextInstructionAddress + relativeOffsetValue;
////	logInfo("testFindCvarSystemPtr computed cvarSystemPtr to be %p", (void*)cvarSystemPtr);
////
////}
//
//
//
//
//
//void applyIniFileSettings() {
//	logInfo("applyIniFileSettings called");
//
//	idCmd::skipHudBtnsCallOut(IniFileData::getIsRemoveBindsReminderOnHud());
//
//	idCmd::setHandsFov(IniFileData::getHandsFOV());
//
//
//	ws.overwriteDeclWeaponsWithUserSettings();
//	//ws.overwriteDeclWeapons();
//
//	//ReticleSettingsDebug::overwriteAllReticlesScaleDebug(IniFileData::getReticleScale());
//	ReticleSettings::overwriteAllReticlesScale(IniFileData::getReticleScale());
//
//	UserColorSet::Update();
//
//	//HudManager::updateCrosshair(CrosshairDot(iniFileData.getCrosshairSize(), iniFileData.getCrosshairOutlineThickness()));
//
//	idCmd::reapplySwfColorsCmd();
//}
//
//
//void LoadIniFileAndCheckFeedback() {
//	/*IniFileStatus iniFileStatus =
//	logInfo("loadModSettingsFromIniFile iniFileStatus: %d", (int)iniFileStatus);*/
//	iniFile.load();
//	iniFile.printStatus();
//	IniFileData::debugPrint();
//
//	IniFileStatus iniFileStatus = iniFile.getlastLoadStatus();
//
//	logInfo("LoadIniFileAndCheckFeedback: iniFileStatus: %d", (int)iniFileStatus);
//
//	if (iniFileStatus == iniFileLoaded) {
//		TTS::addToQueue(saySIniFileReLoaded);
//	}
//	else if (iniFileStatus == iniFileParsingError) {
//		TTS::addToQueue(sayIniFileParsingError);
//	}
//	else if (iniFileStatus == iniFileSavingDefault) {
//		TTS::addToQueue(sayIniFileSavingDefault);
//	}
//}
//
//void loadModSettingsFromIniFile() {
//	//? Have to be carefull here as we don't want to execute anything that could make the game crash if the game is in main menu or loading:
//	logInfo("loadModSettingsFromIniFile called");
//	LoadIniFileAndCheckFeedback();
//	applyIniFileSettings();
//}
//
//
//void modInit() {
//
//	logInfo("modInit called");
//
//	//idCmd::UnrestrictIdConsole();
//
//	//? debuging..............................................
//	/*idCmd::cmdSysTemDebug("swf_skipHudButtonCallouts 1");
//	modStatus.setInitialized();
//	return;*/
//
//	applyIniFileSettings();
//
//	//idCmd::enableUISideNotification(false);	
//
//
//	//if (Config::isDebugMode()) {
//	//	MaterialLib::addStaticMatPtrToDebugVec(); //? don't forget this is here  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	//}
//
//
//	/*if (isdisableShowInformationSetting) {
//		logInfo("modInit: succes disabling ShowInformation setting");
//	}
//	else {
//		logWarn("modInit: FAILED to disable ShowInformation setting");
//	}*/
//
//	//! attempting to overwrite controller static bind strings only once and only when not in game and once menu is levelLoaded.
//	if (!bindLabelChanger.isControllerStaticStringsOverwriteAttempt()) {
//		//if (EpochMillis() - lastStringOverwriteAttempMs > 1000 && GameStateChecker::isMainMenuLoaded()) {
//			//mem.overwriteBindStrings(); //! will only try to overwrite if not already overwritten
//			//stringChanger.overwriteBindStrings();
//		bindLabelChanger.overwriteControllerLabels(lang.getLocalizedBindStringData());
//		//lastStringOverwriteAttempMs = EpochMillis();
//	}
//
//	//! we set it initialized cause we don't want to triggers thoses functions again if they failt the first times there is not use. It anything fails it should be reflected in the log and i should see it when people post their log file if they have issues.
//	modStatus.setInitialized();
//
//
//}
//
//
//
//void EnableHooks() {
//
//	//? commenting this for now for other tests
//	/*if (modStatus.isAllGood()) {
//
//		if (MH_EnableHook(pIdLib_PrintfTarget) != MH_OK) {
//			logErr("MH_EnableHook: pIdLib_PrintfTarget failed, mod can not start.");
//
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pIdLib_PrintfTarget: OK");
//		}
//
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pSub_544BB0_Target) != MH_OK) {
//			logErr("MH_EnableHook: pSub_544BB0_Target failed, mod can not start.");
//
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pSub_544BB0_Target: OK");
//		}
//	}
//	*/
//
//	if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pgetFovTargetValMBTarget) != MH_OK) {
//			logErr("MH_EnableHook: pgetFovTargetValMBTarget failed, mod can not start.");
//
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pgetFovTargetValMBTarget: OK");
//		}
//	}
//
//	/*if (modStatus.isAllGood()) {
//
//		if (MH_EnableHook(pidCmdSystemSmth_461060Target) != MH_OK) {
//			logErr("MH_EnableHook: pidCmdSystemSmth_461060Target failed, mod can not start.");
//
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidCmdSystemSmth_461060Target: OK");
//		}
//
//	}*/
//
//
//
//	if (modStatus.isAllGood()) {
//
//		if (MH_EnableHook(pIdPlayerProcessInputTarget) != MH_OK) {
//			logErr("MH_EnableHook: pIdPlayerProcessInputTarget failed, mod can not start.");
//
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pIdPlayerProcessInputTarget: OK");
//		}
//
//	}
//
//	/*if (modStatus.isAllGood()) {
//
//		if (MH_EnableHook(pidInternalCVar_SetTarget) != MH_OK) {
//			logErr("MH_EnableHook: pidInternalCVar_SetTarget failed, mod can not start.");
//
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidInternalCVar_SetTarget: OK");
//		}
//
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pSoundLangSmth_A8AE00Target) != MH_OK) {
//			logErr("MH_EnableHook: pSoundLangSmth_A8AE00Target failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pSoundLangSmth_A8AE00Target: OK");
//		}
//	}*/
//
//
//	//? info: this will make the program crash:
//	//if (MH_EnableHook(pWndProcOriginalTarget) != MH_OK) {
//	//	std::cout << "pWndProcOriginalTarget failed" << std::endl;
//	//	//return 1;
//	//}
//	//else {
//	//	std::cout << "pWndProcOriginalTarget enabled" << std::endl;
//	//}
//
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pEquipmentInfoTarget) != MH_OK) {
//			logErr("MH_EnableHook: pEquipmentInfoTarget failed, mod can not start.");
//
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pEquipmentInfoTarget: OK");
//		}
//	}*/
//
//	/*if (!binderHelper.isHookError()) {
//		if (MH_EnableHook(pGetCurrentBindsetIndexTarget) != MH_OK) {
//			spdlog::error("MH_EnableHook: pGetCurrentBindsetIndexTarget failed, mod can not start.");
//			binderHelper.setIsHookError(true);
//		}
//		else {
//			spdlog::info("MH_EnableHook:: pGetCurrentBindsetIndexTarget: OK");
//		}
//	}*/
//
//	/*if (!binderHelper.isHookError()) {
//		if (MH_EnableHook(pGetBindsListTarget) != MH_OK) {
//			spdlog::error("MH_EnableHook: pGetBindsListTarget failed, mod can not start.");
//			binderHelper.setIsHookError(true);
//		}
//		else {
//			spdlog::info("MH_EnableHook:: pGetBindsListTarget: OK");
//		}
//	}	*/
//
//
//
//	/*if (!binderHelper.isHookError()) {
//		if (MH_EnableHook(pIdPlayerProfileSerializeTarget) != MH_OK) {
//			spdlog::error("MH_EnableHook: pIdPlayerProfileSerializeTarget failed, mod can not start.");
//			binderHelper.setIsHookError(true);
//		}
//		else {
//			spdlog::info("MH_EnableHook:: pIdPlayerProfileSerializeTarget: OK");
//		}
//	}*/
//
//	if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pSelectWeaponForSelectionGroupTarget) != MH_OK) {
//			logErr("MH_EnableHook: pSelectWeaponForSelectionGroupTarget failed, mod can not start.");
//			modStatus.setHookError();
//
//		}
//		else {
//			logInfo("MH_EnableHook:: pSelectWeaponForSelectionGroupTarget: OK");
//		}
//	}
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidInventoryCollectionGetInventoryItemTarget) != MH_OK) {
//			logErr("MH_EnableHook: pidInventoryCollectionGetInventoryItemTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidInventoryCollectionGetInventoryItemTarget: OK");
//		}
//	}*/
//
//	if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pisKeyPressedTarget) != MH_OK) {
//			logErr("MH_EnableHook: pisKeyPressedTarget failed, mod can not start.");
//			modStatus.setHookError();
//
//		}
//		else {
//			logInfo("MH_EnableHook:: pisKeyPressedTarget: OK");
//		}
//	}
//
//
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pBindCopyControllerStrSomethingTarget) != MH_OK) {
//			logErr("MH_EnableHook: pBindCopyControllerStrSomethingHook failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pBindCopyControllerStrSomethingHook: OK");
//		}
//	}*/
//
//	if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidMenu_UpdateTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidMenu_UpdateTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidMenu_UpdateTarget: OK");
//		}
//	}
//
//	if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pBindsStrSetTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pBindsStrSetTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pBindsStrSetTarget: OK");
//		}
//	}
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidResourceSmthTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidResourceSmthTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidResourceSmthTarget: OK");
//		}
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidGameSystemLocalMinimalGameCleanupTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidGameSystemLocalMinimalGameCleanupTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidGameSystemLocalMinimalGameCleanupTarget: OK");
//		}
//	}*/
//
//	if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidHUD_Reticle_SetActiveReticleTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidHUD_Reticle_SetActiveReticleTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidHUD_Reticle_SetActiveReticleTarget: OK");
//		}
//	}
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidHUDMenuScreenPause_HandleActionTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidHUDMenuScreenPause_HandleActionTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidHUDMenuScreenPause_HandleActionTarget: OK");
//		}
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidDebugHUDLocal_RenderTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidDebugHUDLocal_RenderTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidDebugHUDLocal_RenderTarget: OK");
//		}
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pGetPerfMetricsStrTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pGetPerfMetricsStrTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pGetPerfMetricsStrTarget: OK");
//		}
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidRenderModelGui_DrawStringTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidRenderModelGui_DrawStringTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidRenderModelGui_DrawStringTarget: OK");
//		}
//	}*/
//
//	//if (modStatus.isAllGood()) {
//	//	//MH_STATUS enableHookforpRenderShapeTargetVal = MH_EnableHook(pRenderShapeTarget);
//	//	//logWarn("enableHookforpRenderShapeTargetVal is %d", (int)enableHookforpRenderShapeTargetVal);
//	//	//if (enableHookforpRenderShapeTargetVal != MH_OK) {
//	//	if (MH_EnableHook(pRenderShapeTarget) != MH_OK) {
//	//		logErr("MMH_EnableHook: pRenderShapeTarget failed, mod can not start.");
//	//		modStatus.setHookError();
//	//	}
//	//	else {
//	//		logInfo("MH_EnableHook:: pRenderShapeTarget: OK");
//	//	}
//	//}
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidSWF_Render_CallerTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidSWF_Render_CallerTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidSWF_Render_CallerTarget: OK");
//		}
//	}*/
//
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidRenderModelGui_DrawStretchPic_623070Target) != MH_OK) {
//			logErr("MMH_EnableHook: pidRenderModelGui_DrawStretchPic_623070Target failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidRenderModelGui_DrawStretchPic_623070Target: OK");
//		}
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidRenderModelGui_DrawStretchPic_498ED0Target) != MH_OK) {
//			logErr("MMH_EnableHook: pidRenderModelGui_DrawStretchPic_498ED0Target failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidRenderModelGui_DrawStretchPic_498ED0Target: OK");
//		}
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pidBroadcastManager_ReleaseBroadcastEventTarget) != MH_OK) {
//			logErr("MMH_EnableHook: pidBroadcastManager_ReleaseBroadcastEventTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pidBroadcastManager_ReleaseBroadcastEventTarget: OK");
//		}
//	}*/
//
//	if (modStatus.isAllGood()) {
//		MH_STATUS enableHookforpconvertIdDeclUIColorToidColorTargetVal = MH_EnableHook(pconvertIdDeclUIColorToidColorTarget);
//		if (enableHookforpconvertIdDeclUIColorToidColorTargetVal != MH_OK && enableHookforpconvertIdDeclUIColorToidColorTargetVal != MH_ERROR_ENABLED) {
//			logErr("MMH_EnableHook: pconvertIdDeclUIColorToidColorTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pconvertIdDeclUIColorToidColorTarget: OK, MH enabled status: %d", (int)enableHookforpconvertIdDeclUIColorToidColorTargetVal);
//		}
//	}
//
//
//
//	if (modStatus.isAllGood()) {
//		//logWarn("MH_EnableHook(psetSpriteInstanceColorTarget): Addresses::setSpriteInstanceAddr: %p", (void*)Addresses::setSpriteInstanceAddr);
//		MH_STATUS enableHookforSpriteInstanceVal = MH_EnableHook(psetSpriteInstanceColorTarget);
//		//if (MH_EnableHook(psetSpriteInstanceColorTarget) != MH_OK) {
//		if (enableHookforSpriteInstanceVal != MH_OK && enableHookforSpriteInstanceVal != MH_ERROR_ENABLED) {
//			logErr("MMH_EnableHook: psetSpriteInstanceColorTarget failed, mod can not start. MH_EnableHook val is %d", (int)enableHookforSpriteInstanceVal);
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: psetSpriteInstanceColorTarget: OK, MH enabled status: %d", (int)enableHookforSpriteInstanceVal);
//		}
//	}
//
//	/*if (modStatus.isAllGood()) {
//		MH_STATUS enableHookforprenderSWFTargetVal = MH_EnableHook(prenderSWFTarget);
//		if (enableHookforprenderSWFTargetVal  != MH_OK && enableHookforprenderSWFTargetVal != MH_ERROR_ENABLED) {
//			logErr("MMH_EnableHook: prenderSWFTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: prenderSWFTarget: OK");
//		}
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(prender_gTestMaterialTarget) != MH_OK) {
//			logErr("MMH_EnableHook: prender_gTestMaterialTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: prender_gTestMaterialTarget: OK");
//		}
//	}*/
//
//	/*if (modStatus.isAllGood()) {
//		MH_STATUS enableHookforpshowPerfMetricsSmthTargetVal = MH_EnableHook(pshowPerfMetricsSmthTarget);
//		if (enableHookforpshowPerfMetricsSmthTargetVal != MH_OK && enableHookforpshowPerfMetricsSmthTargetVal != MH_ERROR_ENABLED) {
//			logErr("MMH_EnableHook: pshowPerfMetricsSmthTarget failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pshowPerfMetricsSmthTarget: OK");
//		}
//	}*/
//
//
//
//
//	//pidRenderModelGui_DrawStretchPic_623070Target
//
//
//	/*if (modStatus.isAllGood()) {
//		if (MH_EnableHook(pshowPerfMetricsStrLineTarger) != MH_OK) {
//			logErr("MMH_EnableHook: pshowPerfMetricsStrLineTarger failed, mod can not start.");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("MH_EnableHook:: pshowPerfMetricsStrLineTarger: OK");
//		}
//	}*/
//
//
//}
//
//
//
//DWORD __stdcall EjectThread(LPVOID lpParameter) {
//	Sleep(100);
//	FreeLibraryAndExitThread(DllHandle, 0);
//}
//
//
//ModVersion getCfgVersionFromIniFile() {
//	if (IniFileData::getIsUserDebugModeEnabled()) {
//		return ModVersion::modeReleaseUserDebugEnabled;
//	}
//	return ModVersion::modeReleaseNoUserDebug;
//}
//
//
////? Reminder: the way to load this dll with xenos is simply to change the output name to smth like somedll.dll.
//DWORD WINAPI ModMain() {
//
//
//
//	//const float modVersionF = 0.7f;
//
//	//Config::set(getCfgVersionFromIniFile(), modVersionF);	
//	//!? only uncomment this and comment above when debugging code:!!!!!
//	Config::set(ModVersion::modeDebug);
//
//	//? moving ini load below Config set so we can see ini file path but we have to find a better was to set the config as we need to know if user ini file has been loded correclty from the log
//	//! loading early now so we know if user wants debug or not
//
//	iniFile.load();
//	iniFile.printStatus();
//
//
//	FileWatcher::Initialize(iniFile.getIniFilePath());
//
//
//	logInfo("ModMain: this msg should not be seen if modeReleaseNoUserDebug");
//	logWarn("ModMain: this msg should be seen either in modeReleaseNoUserDebug or in modeReleaseUserDebugEnabled");
//
//	//? remember if you have nothing displayed in the console or even in the log file it's may be because an object logs before Config::Set is called....
//
//
//	//! checks for a previous version of the mod in the game folder that would create issues so we alert the user and prevent the mod from working.
//	ExistingModError existingModError = md5Check.CheckForExistingDE_Mods();
//	logInfo("ModMain: existingModError is %d", (int)existingModError);
//	switch (existingModError)
//	{
//	case ExistingModError::NoPreviousModVersionFound:
//		logInfo("ModMain NoPreviousModVersionFound");
//		break;
//	case ExistingModError::GrenadeKeysModAndQolFound:
//		logWarn("ModMain GrenadeKeysModAndQolFound");
//		modStatus.setPreviousModVersionDinput8FoundError();
//		break;
//	case ExistingModError::GrenadeKeysModAndQolDebugFound:
//		logWarn("ModMain GrenadeKeysModAndQolDebugFound");
//		modStatus.setPreviousModVersionDinput8FoundError();
//		break;
//	case ExistingModError::GrenadeKeysModAndQol_04Found:
//		logWarn("ModMain GrenadeKeysModAndQol_04Found");
//		modStatus.setPreviousModVersionXinput9_1_0FoundError();
//		break;
//	default:
//		logWarn("ModMain ExistingModError: default case (?!)");
//		break;
//	}
//
//	logInfo("ModMain: modStatus.isAllGood() is %d", modStatus.isAllGood());
//
//	if (modStatus.isAllGood() && !mem.isGameFileNameValid()) {
//		logErr("ModMain: exe file name incorect, mod can not start.");
//		//TTS::addToQueue(sayWrongGameNameError);
//		modStatus.setWrongFileNameError();
//		//modStatus.setHookError();
//	}
//
//	HWND hWindow = NULL;
//
//	if (modStatus.isAllGood()) {
//		logWarn("ModMain: searching for DoomEternal Window, Please wait...");
//		while (hWindow == NULL)
//		{
//			hWindow = FindWindowA("Ghost_CLASS", NULL); //! name of doom eternal window
//			Sleep(100);
//		}
//		logWarn("ModMain: Succes Finding DoomEternal Window!");
//		Sleep(500); //! just a safety not sure if necessary
//
//		/*if (mem.isModuleBaseAddrOk()) {
//
//		}*/
//		uintptr_t mainModuleAddr = mem.getModuleBaseAddr();
//		if (mainModuleAddr == NULL) {
//			logErr("Module base address is: NULL, mod can not start!");
//			modStatus.setHookError();
//		}
//		else {
//			logInfo("Module base address is: %p", (void*)mainModuleAddr);
//		}
//	}
//
//	//? attempting to move this earlier here: also need to check if modStatus is good at this point
//	Addresses::scanForAddrs();
//
//
//	//? will also need to set hook error if not succesfull
//	//uintptr_t idProcessInputFuncAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), idPlayerProcessInputSig);
//	/*if (MemHelper::isBadReadPtr((void*)idProcessInputFuncAddr)) {
//		logErr("FAILED to scan for idProcessInputFuncAddr");
//
//	}
//	else {
//		logInfo("Succes Finding idProcessInputFuncAddr at addr: %p", (void*)idProcessInputFuncAddr);
//	}*/
//
//	/*uintptr_t idPLayerSelectWeaponForSelectionGroupAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), idPLayerSelectWeaponForSelectionGroupSig);
//	uintptr_t isKeyPressedAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), isKeyPressedSig);
//	uintptr_t idGameSystemLocalMinimalGameCleanupAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), idGameSystemLocalMinimalGameCleanupSig);
//	uintptr_t idMenu_UpdateAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), idMenu_UpdateSig);
//	uintptr_t pBindsStrSetAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), pBindsStrSetSig);
//	uintptr_t setActiveReticleAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), setActiveReticleSig);
//	uintptr_t idBroadcastManager_ReleaseBroadcastEventAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), idBroadcastManager_ReleaseBroadcastEventSig);
//	uintptr_t convertIdDeclUIColorToidColorTargetAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), convertIdDeclUIColorToidColorTargetSig);
//	uintptr_t setSpriteInstanceAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), setSpriteInstanceSig);
//	uintptr_t showPerfMetricsSmthAddr = (uintptr_t)mem.PatternScan(doomEternalExeName.c_str(), showPerfMetricsSmthSig);*/
//
//
//	/*logInfo("to be sure our method is good here is another result: idProcessInputFuncSig PatternScan result: %p", (void*)mem.PatternScan(doomEternalExeName.c_str(), idPlayerProcessInputSig));*/
//
//	//logInfo("idPlayerProcessInput predenuvo removal addr: : %p", (void*)MemHelper::getFuncAddr(idPlayerProcessInputOffset));	
//
//
//
//
//
//
//
//
//	if (modStatus.isAllGood()) {
//		MH_STATUS MH_status = MH_Initialize();
//		if (MH_status != MH_OK)
//		{
//			std::string MH_StatusStr = MH_StatusToString(MH_status);
//			logErr("Minhook init failed: %s Mod can not start.", MH_StatusStr.c_str());
//
//			modStatus.setHookError();
//		}
//		else {
//			logWarn("Minhook init succes");
//		}
//	}
//
//	//? will not work:
//	//uintptr_t* vtablePtrTestResult =  h_rtti::get_vtable_pointer(doomEternalExeName, "idDeclInfoTemplate@VidDeclWeapon");
//
//	/*uintptr_t* vtablePtrTestResult =  h_rtti::get_vtable_pointer(doomEternalExeName, "?$idDeclInfoTemplate@VidDeclWeapon@@");
//
//	uintptr_t* vtablePtrTestResult2 =  h_rtti::get_vtable_pointer(doomEternalExeName, "idDeclWeapon");
//
//	logInfo("vtablePtrTestResult: %p", (void*)vtablePtrTestResult);
//	logInfo("vtablePtrTestResult2: %p", (void*)vtablePtrTestResult2);*/
//
//
//	//? attempting to move this earlier
//	//Addresses::scanForAddrs();
//
//
//
//	//idResource::getResourceListTest(); 
//
//	//idResource::getResourceListFirstElementPtr("idDeclWeapon");
//	//idResource::getResourceListFirstElementPtr("idDeclWeaponReticle");
//
//	//testFindCvarSystemPtr(); //? don't forget it's here..............
//	//testFindCvarSystemPtr2(); //? don't forget it's here..............
//
//	/*logInfo("found language static address at: %p and the string is: %s", (void*)Addresses::languageStaticAddr, (const char*)Addresses::languageStaticAddr);*/
//
//
//
//	/*if (modStatus.isAllGood()) {
//		pSoundLangSmth_A8AE00Target = reinterpret_cast<SoundLangSmth_A8AE00>(Addresses::SoundLangSmthAddr);
//		if (Addresses::SoundLangSmthAddr == 0 || (MH_CreateHook(reinterpret_cast<void**>(pSoundLangSmth_A8AE00Target), &SoundLangSmth_A8AE00Hook, reinterpret_cast<void**>(&pSoundLangSmth_A8AE00)) != MH_OK)) {
//			logErr("SoundLangSmth_A8AE00Hook CreateHook failed, mod can not start. ");
//
//			modStatus.setHookError();
//		}
//	}*/
//
//
//	//? commenting this for now for other tests
//	/*if (modStatus.isAllGood()){
//		pIdLib_PrintfTarget = reinterpret_cast<IdLib_Printf>(Addresses::idLibPrintFAddr);
//		if (Addresses::idLibPrintFAddr == 0 || (MH_CreateHook(reinterpret_cast<void**>(pIdLib_PrintfTarget), &IdLib_PrintfHook, reinterpret_cast<void**>(&pIdLib_Printf)) != MH_OK)) {
//			logErr("IdLib_PrintfHook CreateHook failed, mod can not start. ");
//
//			modStatus.setHookError();
//		}
//	}*/
//
//	//if (modStatus.isAllGood()) {
//	//	pSub_544BB0_Target = reinterpret_cast<sub_544BB0_Type>(Addresses::sub_544BB0Addr);
//	//	if (Addresses::sub_544BB0Addr == 0 || (MH_CreateHook(reinterpret_cast<void**>(pSub_544BB0_Target), &sub_544BB0_Hook, reinterpret_cast<void**>(&pSub_544BB0)) != MH_OK)) {
//	//		logErr("getFovTargetValMB_Hook CreateHook failed, mod can not start. ");
//
//	//		modStatus.setHookError();
//	//	}
//	//	/*if (MH_CreateHook(reinterpret_cast<void**>(&pSub_544BB0_Target), &sub_544BB0_Hook,
//	//		reinterpret_cast<void**>(&pSub_544BB0)) != MH_OK) {
//	//		logErr("sub_544BB0_Hook CreateHook failed, mod can not start. ");
//	//		modStatus.setHookError();
//	//	}*/
//	//}
//
//
//
//	if (modStatus.isAllGood()) {
//		pgetFovTargetValMBTarget = reinterpret_cast<getFovTargetValMB>(Addresses::GetFovTargetValAddr);
//		if (Addresses::GetFovTargetValAddr == 0 || (MH_CreateHook(reinterpret_cast<void**>(pgetFovTargetValMBTarget), &getFovTargetValMB_Hook, reinterpret_cast<void**>(&pgetFovTargetValMB)) != MH_OK)) {
//			logErr("getFovTargetValMB_Hook CreateHook failed, mod can not start. ");
//
//			modStatus.setHookError();
//		}
//	}
//
//	/*if (modStatus.isAllGood()) {
//		pidCmdSystemSmth_461060Target = reinterpret_cast<idCmdSystemSmth_461060>(Addresses::idCmdSystemSmth_461060_Addr);
//		if (Addresses::idCmdSystemSmth_461060_Addr == 0 || (MH_CreateHook(reinterpret_cast<void**>(pidCmdSystemSmth_461060Target), &idCmdSystemSmth_461060_Hook, reinterpret_cast<void**>(&pidCmdSystemSmth_461060)) != MH_OK)) {
//			logErr("idCmdSystemSmth_461060_Hook CreateHook failed, mod can not start. ");
//
//			modStatus.setHookError();
//		}
//	}*/
//
//
//	/*if (modStatus.isAllGood()) {
//		pidInternalCVar_SetTarget = reinterpret_cast<idInternalCVar_Set>(Addresses::idInternalCVar_SetAddr);
//		if (Addresses::idInternalCVar_SetAddr == 0 || (MH_CreateHook(reinterpret_cast<void**>(pidInternalCVar_SetTarget), &idInternalCVar_SetHook, reinterpret_cast<void**>(&pidInternalCVar_Set)) != MH_OK)) {
//			logErr("idInternalCVar_SetHook CreateHook failed, mod can not start. ");
//
//			modStatus.setHookError();
//		}
//	}*/
//
//
//	//! idPlayer ptr grab hook:
//	if (modStatus.isAllGood()) {
//		pIdPlayerProcessInputTarget = reinterpret_cast<idPlayerProcessInputSACL>(Addresses::idProcessInputFuncAddr);
//		//pIdPlayerProcessInputTarget = reinterpret_cast<idPlayerProcessInputSACL>(MemHelper::getFuncAddr(idPlayerProcessInputOffset));
//		if (Addresses::idProcessInputFuncAddr == 0 || (MH_CreateHook(reinterpret_cast<void**>(pIdPlayerProcessInputTarget), &idPlayerProcessInputSACLHook, reinterpret_cast<void**>(&pIdPlayerProcessInput)) != MH_OK)) {
//			logErr("idPlayerProcessInputSACLHook CreateHook failed, mod can not start. ");
//
//			modStatus.setHookError();
//
//		}
//		/*else {
//			logInfo("idPlayerProcessInputSACLHook CreateHook: OK");
//		}*/
//	}
//
//
//
//	if (modStatus.isAllGood()) {
//		pSelectWeaponForSelectionGroupTarget = reinterpret_cast<SelectWeaponForSelectionGroup>(Addresses::idPLayerSelectWeaponForSelectionGroupAddr);
//		//pSelectWeaponForSelectionGroupTarget = reinterpret_cast<SelectWeaponForSelectionGroup>(MemHelper::getFuncAddr(idPLayerSelectWeaponForSelectionGroupOffset));
//		if (Addresses::idPLayerSelectWeaponForSelectionGroupAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(pSelectWeaponForSelectionGroupTarget), &SelectWeaponForSelectionGroupHook, reinterpret_cast<void**>(&pSelectWeaponForSelectionGroup)) != MH_OK) {
//			logErr("SelectWeaponForSelectionGroupHook CreateHook failed, mod can not start.");
//
//			modStatus.setHookError();
//
//		}
//		/*else {
//			logInfo("SelectWeaponForSelectionGroupHook CreateHook : OK");
//		}*/
//	}
//
//
//
//	if (modStatus.isAllGood()) {
//		pisKeyPressedTarget = reinterpret_cast<isKeyPressed>(Addresses::isKeyPressedAddr);
//		//pisKeyPressedTarget = reinterpret_cast<isKeyPressed>(MemHelper::getFuncAddr(isKeyPressedOffset));
//		//logWarn("Addresses::isKeyPressedAddr: %p", (void*)Addresses::isKeyPressedAddr);
//		if (Addresses::isKeyPressedAddr == 0 || (MH_CreateHook(reinterpret_cast<void**>(pisKeyPressedTarget), &isKeyPressedHook, reinterpret_cast<void**>(&pisKeyPressed)) != MH_OK)) {
//			logErr("isKeyPressedHook CreateHook failed, mod can not start");
//
//			modStatus.setHookError();
//
//		}
//		/*else {
//			logInfo("isKeyPressedHook CreateHook : OK");
//		}*/
//	}
//
//
//
//
//	if (modStatus.isAllGood()) {
//		pidMenu_UpdateTarget = reinterpret_cast<idMenu_Update>(Addresses::idMenu_UpdateAddr);
//		//pidMenu_UpdateTarget = reinterpret_cast<idMenu_Update>(MemHelper::getFuncAddr(idMenu_UpdateOffset));
//		if (Addresses::idMenu_UpdateAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(pidMenu_UpdateTarget), &idMenu_UpdateHook, reinterpret_cast<void**>(&pidMenu_Update)) != MH_OK) {
//			logErr("pidMenu_UpdateTarget CreateHook failed, mod can not start. ");
//
//			modStatus.setHookError();
//
//		}
//	}
//
//	if (modStatus.isAllGood()) {
//		pBindsStrSetTarget = reinterpret_cast<BindsStrSet>(Addresses::pBindsStrSetAddr);
//		//pBindsStrSetTarget = reinterpret_cast<BindsStrSet>(MemHelper::getFuncAddr(pBindsStrSetOffset));
//		if (Addresses::pBindsStrSetAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(pBindsStrSetTarget), &BindsStrSetHook, reinterpret_cast<void**>(&pBindsStrSet)) != MH_OK) {
//			logErr("pBindsStrSetTarget CreateHook failed, mod can not start ");
//
//			modStatus.setHookError();
//		}
//	}
//
//
//
//
//	//if (modStatus.isAllGood()) {
//	//	pidGameSystemLocalMinimalGameCleanupTarget = reinterpret_cast<idGameSystemLocalMinimalGameCleanup>(Addresses::idGameSystemLocalMinimalGameCleanupAddr);
//	//	//pidGameSystemLocalMinimalGameCleanupTarget = reinterpret_cast<idGameSystemLocalMinimalGameCleanup>(MemHelper::getFuncAddr(idGameSystemLocalMinimalGameCleanupOffset));
//	//	if (Addresses::idGameSystemLocalMinimalGameCleanupAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(pidGameSystemLocalMinimalGameCleanupTarget), &idGameSystemLocalMinimalGameCleanupHook, reinterpret_cast<void**>(&pidGameSystemLocalMinimalGameCleanup)) != MH_OK) {
//	//		logErr("pidGameSystemLocalMinimalGameCleanupTarget CreateHook failed, mod can not start");
//
//	//		modStatus.setHookError();
//	//	}
//	//}
//
//	if (modStatus.isAllGood()) {
//		pidHUD_Reticle_SetActiveReticleTarget = reinterpret_cast<idHUD_Reticle_SetActiveReticle>(Addresses::setActiveReticleAddr);
//		//pidHUD_Reticle_SetActiveReticleTarget = reinterpret_cast<idHUD_Reticle_SetActiveReticle>(MemHelper::getFuncAddr(setActiveReticleOffset));
//		if (Addresses::setActiveReticleAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(pidHUD_Reticle_SetActiveReticleTarget), &idHUD_Reticle_SetActiveReticleHook, reinterpret_cast<void**>(&pidHUD_Reticle_SetActiveReticle)) != MH_OK) {
//			logErr("pidHUD_Reticle_SetActiveReticleTarget CreateHook failed, mod can not start");
//
//			modStatus.setHookError();
//		}
//	}
//
//
//	//? last thing i know is that last time we failed to create hook, even though in CE i could see the hook was made...anyway we can make the mod work without this and also i guess many of the crashes we had in the was because of this hook...
//	//if (modStatus.isAllGood()) {
//	//	pidBroadcastManager_ReleaseBroadcastEventTarget = reinterpret_cast<idBroadcastManager_ReleaseBroadcastEvent>(Addresses::idBroadcastManager_ReleaseBroadcastEventAddr);
//	//	logWarn("Addresses::idBroadcastManager_ReleaseBroadcastEventAddr: %p", (void*)Addresses::idBroadcastManager_ReleaseBroadcastEventAddr);
//	//	//pidBroadcastManager_ReleaseBroadcastEventTarget = reinterpret_cast<idBroadcastManager_ReleaseBroadcastEvent>(MemHelper::getFuncAddr(idBroadcastManager_ReleaseBroadcastEventOffset));
//	//	if (Addresses::idBroadcastManager_ReleaseBroadcastEventAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(pidBroadcastManager_ReleaseBroadcastEventTarget), &idBroadcastManager_ReleaseBroadcastEventHook, reinterpret_cast<void**>(&pidBroadcastManager_ReleaseBroadcastEvent)) != MH_OK) {
//	//		logErr("pidBroadcastManager_ReleaseBroadcastEventTarget CreateHook failed  mod can not start ");
//
//	//		modStatus.setHookError();
//	//	}
//	//}
//
//	if (modStatus.isAllGood()) {
//		pconvertIdDeclUIColorToidColorTarget = reinterpret_cast<convertIdDeclUIColorToidColor>(Addresses::convertIdDeclUIColorToidColorTargetAddr);
//		//pconvertIdDeclUIColorToidColorTarget = reinterpret_cast<convertIdDeclUIColorToidColor>(MemHelper::getFuncAddr(convertIdDeclUIColorToidColorTargetOffset));
//		if (Addresses::convertIdDeclUIColorToidColorTargetAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(pconvertIdDeclUIColorToidColorTarget), &convertIdDeclUIColorToidColorHook, reinterpret_cast<void**>(&pconvertIdDeclUIColorToidColor)) != MH_OK) {
//			logErr("pconvertIdDeclUIColorToidColorTarget CreateHook failed for pconvertIdDeclUIColorToidColorTarget, mod can not start");
//
//			modStatus.setHookError();
//		}
//	}
//
//	if (modStatus.isAllGood()) {
//		psetSpriteInstanceColorTarget = reinterpret_cast<setSpriteInstanceColor>(Addresses::setSpriteInstanceAddr);
//		//psetSpriteInstanceColorTarget = reinterpret_cast<setSpriteInstanceColor>(MemHelper::getFuncAddr(setSpriteInstancetOffset));
//		if (Addresses::setSpriteInstanceAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(psetSpriteInstanceColorTarget), &setSpriteInstanceColorHook, reinterpret_cast<void**>(&psetSpriteInstanceColor)) != MH_OK) {
//			logErr("psetSpriteInstanceColorTarget CreateHook failed, mod can not start  ");
//
//			modStatus.setHookError();
//		}
//	}
//
//
//
//	//if (modStatus.isAllGood()) {
//	//	pshowPerfMetricsSmthTarget = reinterpret_cast<showPerfMetricsSmth>(Addresses::showPerfMetricsSmthAddr);
//	//	//pshowPerfMetricsSmthTarget = reinterpret_cast<showPerfMetricsSmth>(MemHelper::getFuncAddr(showPerfMetricsSmthOffset));
//	//	if (Addresses::showPerfMetricsSmthAddr == 0 || MH_CreateHook(reinterpret_cast<void**>(pshowPerfMetricsSmthTarget), &showPerfMetricsSmthHook, reinterpret_cast<void**>(&pshowPerfMetricsSmth)) != MH_OK) {
//	//		logErr("pshowPerfMetricsSmthTarget CreateHook failed, mod can not start ");
//
//	//		modStatus.setHookError();
//	//	}
//	//}
//
//
//	//idCmd::UnrestrictIdConsole(); //? just for test purpooses !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!delet it !!!
//
//
//
//	//! The old minhook config we used before are in dllmainDebug.h if you ever need them
//
//
//	//? **********************************************************************************************************************************    
//
//	//? this is where we used to enable the hooks in case the new function does not work
//
//	//Sleep(2000); //? attempting this to check if it fixes erros about hooking
//	EnableHooks();
//
//
//
//	//! not using voice for previous mod detected cause it will be deleted and because some obsure reason the mod loads twice it will just say "error" so might as well not make the user panic
//	//if (modStatus.isPreviousModVersionDinput8FoundError()) {
//	//	TTS::addToQueue(sayPreviousModVersionDinput8FoundError);
//	//}
//	//else if (modStatus.isPreviousModVersionXinput1_9FoundError()) {
//	//	TTS::addToQueue(sayPreviousModVersionXInput9_1_0FoundError);
//	//	//TTS::addToQueue(sayHookingError);
//	//	//showHoorErrorMessageBox();
//	//	//playWindowsErrorSound();
//	//}
//	//? be carefule with this, at some point we remove the first if that the ini file never got made and drove me mad.
//	if (modStatus.isWrongFileNameError()) {
//		TTS::addToQueue(sayWrongGameNameError);
//	}
//	else if (modStatus.isHookError()) {
//		TTS::addToQueue(sayHookingError);
//	}
//	else { //! if modStatus.isAllGood()
//
//		//logInfo("about to call iniFile.load(iniFileData); ");		
//		//MessageBox(NULL, L"textttt", L"caption", 0);
//		//TTS::addToQueue(saySuccesLoadingMod);
//		//playWavModLoadSucces();
//
//		if (IniFileData::isPlayModLoadedBeep()) {
//			PlayModLoadSuccesBeeps(); //? this is weird i hear the sound on speakers but not with headset
//		}
//	}
//
//
//	bool lastIsPlayerInGame = false;
//	uint64_t lastOwnedItemsGetMs = 0;
//	uint64_t lastStringOverwriteAttempMs = 0;
//	uint64_t lastGetAsyncKeyPressMs = 0;
//	uint64_t lastIniFileReloadMs = 0;
//	uint64_t lastDeclWeaponOverwriteMs = 0;
//	uint64_t lastGameTimeDebugMs = 0;
//	uint64_t lastcustomUICoordsCheckMs = 0;
//	uint64_t lastcolorReloadMs = 0;
//	uint64_t lastIdInventoryGetMs = 0;
//	uint64_t lastWeaponSettingCheckMs = 0;
//	uint64_t lastHudColorsUpdateCheckMs = 0;
//	uint64_t lastCrosshairScaleCheckMs = 0;
//	uint64_t lastCrosshairInScropCheckMs = 0;
//	uint64_t lastFXCheckMs = 0;
//	uint64_t lastIniFileWatcherCheckMs = 0;
//	uint64_t lastDebugWarningMs = 0;
//	bool wasPlayerInMenu = false;
//
//
//
//	while (true) {
//
//		//Sleep(50); //! having a long sleep here will not have influence on the hooks which is great!
//		//? Removing this Sleep may have been what caused the crash, i say may, still investigating...
//		Sleep(g_sleepTimeMainLoopMs); //! having a long sleep here will not have influence on the hooks which is great. 
//
//		//logInfo("hello?");
//
//		TTS::sayAllInQueue(); //! make sure this is called before the isHookError check
//
//		if (!modStatus.isAllGood()) { //! if NOT all good
//			//logInfo("main loop:  !modStatus.isAllGood()");
//			continue;	//! keep the mod running so it can output some msg to console/file		
//		}
//
//		if (!PlayerStateChecker::isGameInitialized()) {
//			//logInfo("main loop: ! PlayerStateChecker::isGameInitialized()");
//			continue;	//! if the mod has levelLoaded succesfully, we don't do anything until the game is levelLoaded.
//		}
//
//		PlayerStateChecker::updatePlayerState();
//
//		if (PlayerStateChecker::isGameLoading()) {
//			//logInfo(" main loop: PlayerStateChecker::isGameLoading())");
//
//			//switcher.resetInventoryCount(); // don't need this anymore
//			idPlayer_K::resetLastBloodPunchCount(); // to make sure it updates the colors when player spawns
//			idPlayer_K::resetLastIceGrenadeCount(); // to make sure it updates the colors when player spawns
//			idPlayer_K::resetLastFragGrenadeCount();
//			//logInfo("Game is loading....resetting inventory count");
//			//switcher.resetInventoryCount();
//			continue; //! not doing anything while game loads as this is too prone to crashes.
//		}
//
//
//		if (!modStatus.isInitialized()) {
//			//EnableHooks2(); //? this is so fucked up.................
//			modInit();	//! <= this will set modStatus to initailized.	
//		}
//
//		if (EpochMillis() - lastIniFileWatcherCheckMs > 1000) {
//			lastIniFileWatcherCheckMs = EpochMillis();
//			if (PlayerStateChecker::isGameInitialized() && !PlayerStateChecker::isGameLoading()) {
//				if (IniFileData::isIniFileAutoReload() && FileWatcher::IsFileModified()) {
//					loadModSettingsFromIniFile();
//				}
//			}
//		}
//
//		//! ini file Reload 
//		if (GetAsyncKeyState(IniFileData::getReloadIniFileVkCode()) && ((EpochMillis() - lastGetAsyncKeyPressMs) > 2000)) {
//			lastGetAsyncKeyPressMs = EpochMillis();
//			logInfo("ModMain: user just pressed reload ini file key");
//
//			loadModSettingsFromIniFile();
//
//
//			//HudManager::updateCrosshair(CrosshairDot(iniFileData.getCrosshairSize(), iniFileData.getCrosshairOutlineThickness()));
//		}
//
//
//		//todo check if color profile has changed so we can call HudManager::updateCustomHudIceSpriteProfileColors()
//
//
//		//? Commenting this out for now as we're working on creating scan pattern and i don't need the extra complexity of features we currently don't need for the mod like the hud stuffs
//
//		/*if (HudManager::isColorProfileUnknown() || HudManager::hasColorProfileChanged()) {
//			HudManager::updateCustomHudIceSpriteProfileColors();
//			HudManager::updateCustomHudAmmosColors();
//		}*/
//
//
//		if (PlayerStateChecker::isPlaying()) {
//
//			if (IniFileData::isImprovedWeaponSwitching()) {
//				switcher.checkWeaponSwitchV2(); //! only enabled if user did not disable it in the ini file.
//			}
//
//			//! Not using this anymore as we modify DeclWeapons in the Resource we found:
//			//if (EpochMillis() - lastWeaponSettingCheckMs > 300) { //! every 500 ms
//			//	lastWeaponSettingCheckMs = EpochMillis();
//			//	//ws.checkCurrentlyEquippedIdWeapon();
//			//}
//
//			//! this is used to check if a weapon or a nade is owned. 500ms should be good enough.
//			if (EpochMillis() - lastIdInventoryGetMs > 200) {
//				lastIdInventoryGetMs = EpochMillis();
//				idInventoryManager::updateOwnedItemsIds();
//			}
//
//			//! we allow user to disable it but not re-enable it, they have to restart the game
//			if (EpochMillis() - lastFXCheckMs > 500) {
//				lastFXCheckMs = EpochMillis();
//				if (IniFileData::getIsDisabledDashBlurEffect()) {
//					idFxManager::disableDashFx();
//				}
//			}
//
//
//
//			if (EpochMillis() - lastHudColorsUpdateCheckMs > 50) {
//				//! i know it's not elegant but i'd rather be sure that i triggers for now
//				if (idPlayer_K::isBloodPunchCountChanged()) {
//					idCmd::reapplySwfColorsCmd();
//				}
//				else if (idPlayer_K::isIceNadeCountChanged() || idPlayer_K::isFragNadeCountChanged()) {
//					idCmd::reapplySwfColorsCmd();
//				}
//				//? this could be the reason why we crash:
//				else if (idPlayer_K::isHudSelectedGrenadeChanged()) {
//					idCmd::reapplySwfColorsCmd();
//				}
//				//ReticleSettings::updateDotColor();
//				ReticleSettings::debugUpdateDotColor();
//
//				lastHudColorsUpdateCheckMs = EpochMillis();
//			}
//
//			//! not needed anymore except if alt method fails...
//			//if (EpochMillis() - lastCrosshairScaleCheckMs > 1000) {
//			//	lastCrosshairScaleCheckMs = EpochMillis();
//			//	//idPlayer_K::setReticleScaleTest(.5f);
//			//}
//
//			if (EpochMillis() - lastCrosshairInScropCheckMs > 100) {
//				lastCrosshairInScropCheckMs = EpochMillis();
//				//! the idea is that the overideCrosshairInScope setting of the ini file will overide whatever game user setting is currently meaning that even if user has game reticleMode to dot or ful, game reticleMode will be overiden to none when not in scope
//				if (IniFileData::getIsOnlyShowCrosshairInHARScope()) {
//					//logInfo("getIsOnlyShowCrosshairInHARScope is true");
//					if (idPlayer_K::wantZoom()) {
//
//						if (idCmd::getReticleMode() != UI_ReticleMode::Full) {
//							idCmd::setReticleMode(UI_ReticleMode::Full);
//						}
//					}
//					else {
//						if (idCmd::getReticleMode() != UI_ReticleMode::None) {
//							idCmd::setReticleMode(UI_ReticleMode::None);
//
//						}
//					}
//				}
//			}
//
//
//			if (EpochMillis() - lastDebugWarningMs > 1000) {
//				lastDebugWarningMs = EpochMillis();
//
//				logWarn("lastDebugWarningMs Reminder:");
//
//				if (g_sleepTimeMainLoopMs == 0) {
//					logWarn("g_sleepTimeMainLoopMs is 0...");
//				}
//
//				logWarn("isImprovedSwitchingEnabled has been commented in  updateLastWeapKeyPress !!!!!");
//
//
//				idPlayer_K::debugLogMembersAndAddrs();
//				//FileWatcher::IsFileModified();
//
//
//			}
//
//
//
//
//
//
//
//			//! making sure the crosshair turns red when meathook is not available for ex:
//			//HudManager::computeCrosshairColor();
//
//
//			//
//			////! the trigger every sec makes sure the nade is dispayed after level is loaded, otherwise it's not.
//			//if (Game::isResolutionChanged() ||  GameSettings::hasUIScaleChanged() || wasPlayerInMenu || HudManager::isCustomHudAmmosStringsLengthChanged() || (EpochMillis() - lastcustomUICoordsCheckMs > 1000))  {
//
//			//	if (Config::isDebugMode()) {
//			//		logInfo("updating custom hud coords....");					
//			//	}
//			//
//			//
//			//	//? we still need to check if player is a revenant or other and if player is zooming with weapon
//			//	HudManager::updateCustomHudIceSpriteCoords();
//
//			//	HudManager::updateCustomHudAmmosCoords();
//
//			//	
//
//			//	wasPlayerInMenu = false;
//
//			//	lastcustomUICoordsCheckMs = EpochMillis(); //! checking every seconds for safety cause i've been surprised...
//			//}
//
//			////! this should be fast enough we don't need the data for every frame
//			////? attemting to comment out this and trigger it from event instead let's see what happens. Update bad idea i got a crahs during map load.
//			//HudManager::updateCustomHudIceSpriteData();
//			//HudManager::updateCustomHudAmmosData();
//
//
//
//
//			//! attempting a render here whatever the frequency will just create flickery text/images
//			//consoleLocal.testCrosshairObject();
//
//			//if (EpochMillis() - lastOwnedItemsGetMs > 2000) {
//			//	lastOwnedItemsGetMs = EpochMillis();
//			//	//mem.aquireWatchedOwnedItems();
//			//	//todo we could use an inventory class that would get the items data instead of memhelper
//			//	//eql.updateOwnedGrenades(mem.getOwnedGrenadeTypeIdsVec());
//			//	//binderHelper.updateOwnedWeapons(mem.getOwnedWeaponsVec());
//
//
//			//	//inv.acquireWatchedOwnedItems(); //? 
//
//			//	//! this was in a hooked function before which was a bad idea
//
//			//	//mem.getOwnedWeapons();
//			//	//mem.debugPrintOwnedWeapons();
//
//			//	//logInfo("idPlayer::getIceNadeCoolDownSec() %d", idPlayer::getIceNadeCoolDownSec());
//			//}
//		}
//
//		//! We used to overwrite declWeapons every x seconds when we have a static value of a weapon struct but now we have a better method
//		/*if (EpochMillis() - lastDeclWeaponOverwriteMs > 5000) {
//			lastDeclWeaponOverwriteMs = EpochMillis();
//			if (ws.isDeclWeaponsOverwriteNeeded()) {
//				ws.overwriteDeclWeapons();
//			}
//
//		}*/
//
//		//! we can not use this, i got some crashes and i think this was involved or at least part of it but i have no proof.
//		//if (PlayerStateChecker::getPlayerState() != lastPlayerState) {
//		//	if (lastPlayerState == PlayerState::inPauseMenu && PlayerStateChecker::isInGame()) {
//		//		//todo resend hud data, like the equipment backer will need to be set back to the color we want if the feature is enabled.
//		//		logInfo("debug: pause menu to ingame detected, setting alt nade icons to blue");
//		//		GameHudColorsManager::setEquipmentAltNadeColor(colorBlue);
//		//	}
//		//	lastPlayerState = PlayerStateChecker::getPlayerState();			
//		//}
//
//		/*if (PlayerStateChecker::isInMenus()) {
//			wasPlayerInMenu = true;
//		}*/
//
//
//
//		//lastPlayerState = PlayerStateChecker::getPlayerState();
//
//
//		//! in there goes everything we don't want the user to have acces to:
//		if (Config::isDebugMode()) {
//
//			if (GetAsyncKeyState(VK_NUMPAD0) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 500)) {
//				g_lastGetAsyncKeyPress = EpochMillis();
//				logInfo("DEBUG: user just pressed  VK_NUMPAD0: attempting to Unload Mod...");
//				break;
//			}
//
//			if (GetAsyncKeyState(VK_NUMPAD1) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 500)) {
//				g_lastGetAsyncKeyPress = EpochMillis();
//				logInfo("DEBUG: user just pressed  VK_NUMPAD1: idPlayerFromEntityFinderPtr(); ");
//
//				//idGameLocal::find_entityDebug();
//				void* player1EntityPtr = idGameLocal::find_entity("player1");
//				logInfo("idPlayerFromEntityFinderPtr: %p", player1EntityPtr);
//				//ws.overwriteDeclWeaponsWithUserSettings();
//				//idPlayer_K::setDotReticleScaleV2(.5f);
//				//idCmd::reapplySwfColorsCmd();
//				//idInventoryManagerDebug::printIdInventoryItemsInfo();
//				//debug_printWeaponCoolDownValOfDotReticle();
//
//				/*idPlayer_K::changeDotReticleColorTest();
//				idCmd::reapplySwfColorsCmd();*/
//
//				//idInventoryManager::debugGetOwnedItemsStrings();
//
//				//idCmd::executeCommandText_K("swf_skipHudButtonCallouts 1");
//
//
//				//int idLibHookStatus = (int) MH_EnableHook(pIdLib_PrintfTarget);
//				//logWarn("enabling hook....idLibHookStatus is now : %d", idLibHookStatus);
//
//
//				//! this is what you use when you want to check the next material but you'll need to have set up a renderer first like in render_gTestMaterialHook:
//				//g_debugMaterialAddr = MaterialLib::getPrevious();
//
//				//! use that to make a game's hud element to red: (but addSpriteInstanceAddrToDebugVec will have to be active in setSpriteInstanceColorHook
//				//GameHudColorsManager::debugChangePrevHudElementColorToRed();
//
//
//				//GameHudColorsManager::setEquipmentArrowColorToInvisible();
//
//				//GameHudColorsManager::setEquipmentArrowColor(colorRed);
//
//
//				//GameHudColorsManager::setEquipmentArrowColorToInvisible()
//
//				/*logInfo("VK_NUMPAD1: g_testIdNamedColorIndex before -=1 is : %d", g_testIdNamedColorIndex);
//				//g_testIdNamedColorIndex -= 1;
//				//logInfo("VK_NUMPAD1: g_testIdNamedColorIndex after -=1 : %d", g_testIdNamedColorIndex);
//				//if (g_testIdNamedColorIndex <= 0) {
//					g_testIdNamedColorIndex = 0;
//				}
//				logInfo("VK_NUMPAD1: g_testIdNamedColorIndex is now: %d", g_testIdNamedColorIndex);
//				if (g_namedColorDebug == 94) {
//					g_namedColorDebug = 95;
//				}
//				else {
//					g_namedColorDebug = 94;
//				}
//				idCmd::reapplySwfColors();*/
//
//				//MaterialLib::getLibPrev();
//
//				//hashDebugIndex--;
//				//g_namedColorDebug = 94;  //? blue
//				//if (hashDebugIndex < 0) {
//				//	hashDebugIndex = 0;
//				//}
//
//				//if (hashDebugIndex <= spriteDebugVec.size()) {
//
//				//	logInfo("hashDebugIndex is: %d ", hashDebugIndex);
//				//	spriteDebugVec[hashDebugIndex].print();
//				//	//logInfo("hashDebugIndex is: %d and path hash is: %d", hashDebugIndex, spriteDebugVec[hashDebugIndex]);
//				//}
//				//else {
//				//	logWarn("hashDebugIndex is > pathHashesDebugVec[hashDebugIndex]: hashDebugIndex %d and pathHashesDebugVec size: %zu", hashDebugIndex, spriteDebugVec.size());
//				//}
//				//idCmd::reapplySwfColors();
//
//			}
//
//			if (GetAsyncKeyState(VK_NUMPAD2) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 500)) {
//				g_lastGetAsyncKeyPress = EpochMillis();
//
//				/*logInfo("DEBUG: user just pressed  VK_NUMPAD2: idPlayer_K::setDotReticleScale(1.0f); ");
//
//				idPlayer_K::setDotReticleScaleV2(2.0f);*/
//				//idPlayer_K::resetDotReticleColotToDefault();
//				//idCmd::reapplySwfColorsCmd();
//
//
//
//
//				//idCmd::executeCommandText_K("swf_skipHudButtonCallouts 0");
//				//int idLibHookStatus = (int)MH_DisableHook(pIdLib_PrintfTarget);
//				//logWarn("disalbing hook...idLibHookStatus is now : %d", idLibHookStatus);
//
//
//				//GameHudColorsManager::changeTestColor();
//
//				//HudManager::updateCustomHudIceSpriteCoords();
//
//				//! this is usefull atm to simulate user changing color profile but should not be need when the mod is loaded with the game
//				//idCmd::reapplySwfColorsCmd();
//
//				//GameHudColorsManager::logFragIconsData();
//
//				//g_iceNadeIconDebugVec4 = GameHudColorsManager::getFragSpriteIdBounds(fragCoolDownFillGlowSpriteId);
//				//g_iceNadeIconDebugVec4 = GameHudColorsManager::computeCustomIceSpriteBounds();
//
//				//IdFont.set(idFontEnum::defaultCourrierF8);
//
//				/*__int64 idFontAddr = ObjectLocator::getIdFontAddr(idFontEnum::defaultCourrierF8);
//				logInfo("ifont addr: %llx", idFontAddr);*/
//				//debug.log_reticleColorInfo();
//
//				//debug.Log_idDeclSWFVec();
//
//				//idCmd::setHandsFov(100); //? TEst
//
//				//idInventoryManager::debugGetOwnedItems();
//					//idRes.printIdMaterialsInfo();
//				/*auto playerInv = idInventoryManager::getPlayerInventory();
//				playerInv.debugPrint();
//				logInfo("DEBUG: user just pressed  VK_NUMPAD2");*/
//			}
//
//
//
//			if (GetAsyncKeyState(VK_NUMPAD3) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 500)) {
//				g_lastGetAsyncKeyPress = EpochMillis();
//
//				logInfo("DEBUG: user just pressed  VK_NUMPAD3");
//				//idPlayer_K::printDotReticleColor_namedColorId_Test();
//
//				//! this is what you use when you want to check the next material but you'll need to have set up a renderer first like in render_gTestMaterialHook:
//				//g_debugMaterialAddr = MaterialLib::getNext();
//
//				/*g_debugReticleScale = !g_debugReticleScale;
//				logInfo("DEBUG: user just pressed  VK_NUMPAD3: g_debugIsReticleTest is now %d", g_debugReticleScale);*/
//
//				//! use that to make a game's hud element to blue: (but addSpriteInstanceAddrToDebugVec will have to be active in setSpriteInstanceColorHook
//				//GameHudColorsManager::debugChangeNextHudElementColorToBlue();
//
//				//logInfo("DEBUG: user just pressed  VK_NUMPAD3: idCmd::isReticleModeNone();");
//				//idCmd::PrintCvarFindAddrTest("g_reticleMode");
//				//idCmd::isReticleModeNone();
//
//
//				//hashDebugIndex++;
//				//g_namedColorDebug = 95;  //? red
//				//if (hashDebugIndex >= spriteDebugVec.size()) {
//				//	hashDebugIndex = spriteDebugVec.size() - 1;
//				//}
//
//				//if (hashDebugIndex <= spriteDebugVec.size()) {
//
//				//	logInfo("hashDebugIndex is: %d ", hashDebugIndex);
//				//	spriteDebugVec[hashDebugIndex].print();
//				//	//logInfo("hashDebugIndex is: %d and path hash is: %d", hashDebugIndex, spriteDebugVec[hashDebugIndex]);
//				//}
//				//else {
//				//	logWarn("hashDebugIndex is > pathHashesDebugVec[hashDebugIndex]: hashDebugIndex %d and pathHashesDebugVec size: %zu", hashDebugIndex, spriteDebugVec.size());
//				//}
//				//idCmd::reapplySwfColors();
//				//GameHudColorsManager::setEquipmentArrowColor(colorBlue);
//
//
//				//MaterialLib::getLibNext();
//
//				/*g_testIdNamedColorIndex +=1;
//				if (g_testIdNamedColorIndex >= 269) {
//					g_testIdNamedColorIndex = 269;
//				}
//				logInfo("VK_NUMPAD3: g_testIdNamedColorIndex is now: %d", g_testIdNamedColorIndex);
//				if (g_namedColorDebug == 94) {
//					g_namedColorDebug = 95;
//				}
//				else {
//					g_namedColorDebug = 94;
//				}
//				idCmd::reapplySwfColors();*/
//			}
//
//			if (GetAsyncKeyState(VK_NUMPAD4) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 300)) {
//				g_lastGetAsyncKeyPress = EpochMillis();
//
//
//				/*	logInfo("DEBUG: user just pressed  VK_NUMPAD4: idCmd::ReticleCmdTest()");
//					idCmd::ReticleCmdTest();*/
//					//! this works:
//					/*IniConfig::setRadSuitColorOveride(false);
//					idCmd::reapplySwfColors();*/
//
//					//IniConfig::setEquipmentArrowColorOveride(false);
//
//					//! this work to disabled overide bp colors AND restor bp profile colors
//					//IniConfig::setBloodPunchColorOveride(false);
//					//idCmd::reapplySwfColorsCmd();
//
//
//
//			}
//
//
//			if (GetAsyncKeyState(VK_NUMPAD5) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 300)) {
//				g_lastGetAsyncKeyPress = EpochMillis();
//
//				/*logInfo("DEBUG: user just pressed  VK_NUMPAD5: idCmd::ReticleCmdTest0()");
//				idCmd::ReticleCmdTest0();*/
//
//
//				//idCmd::reapplySwfColorsCmd();
//
//				/*g_isDebugHudEnabled = !g_isDebugHudEnabled;
//				logInfo("g_isDebugHudEnabled value is now: %d", g_isDebugHudEnabled);*/
//
//
//				//logInfo("GameSettings::getReticleMode() val is: %d", GameSettings::getReticleMode());
//
//				//? not using those anymore this was too prone to crashes unfortunately:
//				//GameHudColorsManager::setHealthHudToTextOnly();
//				//GameHudColorsManager::setArmorHudToTextOnly();
//				//GameHudColorsManager::decluterWeaponInfo();
//				//
//				//GameHudColorsManager::setRadSuitHudColor(colorPurple);
//				//GameHudColorsManager::setBloodPunchHudColor(colorOrange, true);
//
//				//GameHudColorsManager::setEquipmentArrowColor(colorRed);
//				//GameHudColorsManager::setEquipmentBackerColor(colorRed);
//
//				//? this doesn't work:
//				//GameHudColorsManager::debugMoveEquipmentArrowRight();
//			}
//
//
//			if (GetAsyncKeyState(VK_NUMPAD6) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 300)) {
//				g_lastGetAsyncKeyPress = EpochMillis();
//
//				/*logInfo("DEBUG: user just pressed  VK_NUMPAD6: idCmd::ReticleCmdTest1();");
//				idCmd::ReticleCmdTest1();*/
//
//				//! this work to overide radsuit colors
//				//IniConfig::setRadSuitColorOveride(false);
//				//GameHudColorsManager::setRadSuitHudColor(colorPurple);
//
//				//! this work to overide bp colors
//				//IniConfig::setBloodPunchColorOveride(false);
//				//idCmd::reapplySwfColorsCmd();
//				//GameHudColorsManager::setBloodPunchHudColor(colorOrange, true);
//				//? this will put the arrow back so basically you never want that to happen as the mod has the custom nade hud by default.
//				//IniConfig::setEquipmentArrowColorOveride(false);
////;				idCmd::reapplySwfColorsCmd();
//			}
//
//			//if (GetAsyncKeyState(VK_NUMPAD7) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 300)) {
//			//	g_lastGetAsyncKeyPress = EpochMillis();
//
//			//	//! make sure g_isDebugHudEnabled is true
//			//	debugHud.getPreviousMaterial();
//
//			//}
//
//			//if (GetAsyncKeyState(VK_NUMPAD9) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 300)) {
//			//	g_lastGetAsyncKeyPress = EpochMillis();
//
//			//	//! make sure g_isDebugHudEnabled is true
//			//	debugHud.getNextMaterial();
//
//			//}
//
//
//
//
//		}	//! end of if debug condition
//
//
//		//else { //! if in menus or not controllable
//		//	
//		//	wasPlayerInMenu = true;
//		//}
//	}
//
//	//? we never get to this point because Xenox can not load this mod anyway.
//
//	//MH_DisableHook(pidInventoryCollectionGetInventoryItemTarget);
//	//MH_DisableHook(pEquipmentInfoTarget);
//	//MH_DisableHook(pSoundLangSmth_A8AE00Target);
//	//MH_DisableHook(pSub_544BB0_Target);
//	MH_DisableHook(pgetFovTargetValMBTarget);
//	//MH_DisableHook(pidCmdSystemSmth_461060Target);
//	//MH_DisableHook(pIdLib_PrintfTarget);
//	MH_DisableHook(pIdPlayerProcessInputTarget);
//	//MH_DisableHook(pidInternalCVar_SetTarget);
//	MH_DisableHook(pSelectWeaponForSelectionGroupTarget);
//	MH_DisableHook(pisKeyPressedTarget);
//	MH_DisableHook(pidMenu_UpdateTarget);
//	MH_DisableHook(pBindsStrSetTarget);
//	//MH_DisableHook(pidResourceSmthTarget);
//	//MH_DisableHook(pidGameSystemLocalMinimalGameCleanupTarget);
//	MH_DisableHook(pidHUD_Reticle_SetActiveReticleTarget);
//	//MH_DisableHook(pidHUDMenuScreenPause_HandleActionTarget);
//	//MH_DisableHook(pidDebugHUDLocal_RenderTarget);
//	//MH_DisableHook(pGetPerfMetricsStrTarget);
//	//MH_DisableHook(pidRenderModelGui_DrawStringTarget);
//	//MH_DisableHook(pRenderShapeTarget);
//	//MH_DisableHook(pidSWF_Render_CallerTarget);
//	//MH_DisableHook(prenderSWFTarget);
//	//MH_DisableHook(pshowPerfMetricsStrLineTarger);
//	//MH_DisableHook(pBindCopyControllerStrSomethingTarget);
//	//MH_DisableHook(pidRenderModelGui_DrawStretchPic_623070Target);
//	//MH_DisableHook(pidRenderModelGui_DrawStretchPic_498ED0Target);
//	//MH_DisableHook(pidBroadcastManager_ReleaseBroadcastEventTarget);
//	MH_DisableHook(pconvertIdDeclUIColorToidColorTarget);
//	MH_DisableHook(psetSpriteInstanceColorTarget);
//	//MH_DisableHook(prender_gTestMaterialTarget);
//	//MH_DisableHook(pshowPerfMetricsSmthTarget);
//
//
//	Config::exit();
//	CreateThread(0, 0, EjectThread, 0, 0, 0);
//	/*int i = 0;*/
//	return 0;
//}
//
//
//
//
//
//
//extern "C" BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
//{
//	UNREFERENCED_PARAMETER(lpReserved);
//
//	switch (ul_reason_for_call)
//	{
//	case DLL_PROCESS_ATTACH:
//		DllHandle = hModule;
//		//std::cout << "DllHandle value is DllMain: " << reinterpret_cast<uintptr_t>(DllHandle) << std::endl;
//		DisableThreadLibraryCalls(hModule);
//		//InitInstance();
//		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)ModMain, DllHandle, 0, nullptr);
//		break;
//
//	case DLL_PROCESS_DETACH:
//		break;
//	}
//
//	return TRUE;
//}
//
//
//
//
//
//
//
//
//
////typedef void(__fastcall* idRenderModelGui_DrawStretchPic2)(__int64 a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, __int64 a11);
////static idRenderModelGui_DrawStretchPic2 pidRenderModelGui_DrawStretchPic = reinterpret_cast<idRenderModelGui_DrawStretchPic2>(MemHelper::getFuncAddr(0x498ED0));
////
//
//////! __int64 __fastcall render_gTestMaterial_Mb_1AFA8E0(__int64 a1)
////typedef __int64(__fastcall* render_gTestMaterial)(__int64 a1);
////render_gTestMaterial prender_gTestMaterial = nullptr;
////render_gTestMaterial prender_gTestMaterialTarget;
////
////
////
//////! for numeral font: getSmallCharWidth: 12.00 and getSmallCharHeight: 20.57 and 
//////! this func will trigger even if no hud but our custom hud will ofc will not not be rendered
////__int64 __fastcall render_gTestMaterialHook(__int64 a1) {
////
////	__int64 guiAddr = *(__int64*)a1;
////
////	//! this should help with the custom hud being displayed when players is dead 
////	//! also will not render hud if player is a demon
////	if (!PlayerStateChecker::isPlaying()) {
////		return prender_gTestMaterial(a1);
////	}
////
////	//! we still drawn the custom crosshair if player is demon cause the game's dot would be drawn
////	if (GameSettings::getReticleMode() == gameSettingsCrosshairMode::DOT) {
////		
////		//? keep in mind that when climbing a wall crosshair is hidden btw
////		if (!idPlayer::isGameDotCrosshairHidden()) { //! if not in cutscene
////
////			//? if crosshair only in HAR ADS mode and reticule mode is dot
////			if (IniConfig::isDotCrosshairOnlyInHARScope()) {
////				if (idPlayer::isInScope()) {
////					idRenderModelGui::drawCrosshairDot(guiAddr, HudManager::getCrosshair());
////				}
////				else {
////					return prender_gTestMaterial(a1);
////				}
////			}
////			else {
////				idRenderModelGui::drawCrosshairDot(guiAddr, HudManager::getCrosshair());
////
////			}
////		}
////	}
////
////
////	
////	//! looks odd but this is a way to make the comparison faster
////	if (!GameSettings::isHudEquipmentInfo() || !GameSettings::isHudModeFull() || idPlayer::isInScope() || idPlayer::isWeaponInfoFadedOut()  || !idPlayer::isSlayer()){
////		//! we don't need to check if settings are on crosshair only cause it automatically prevents the triggering of this hook !
////		return prender_gTestMaterial(a1);
////	}
////	else {
////		/*if (HudManager::isFirstTimeRenderCustomIceSprite()) {
////			HudManager::updateCustomHudIceSpriteProfileColors();
////		}*/
////
////		//! i trid to put this if cond in main mod loop, it didn't help quite the opposite.
////		/*if (PlayerStateChecker::isPlaying()) {
////			if (HudManager::isColorProfileUnknown() || HudManager::hasColorProfileChanged()) {
////				HudManager::updateCustomHudIceSpriteProfileColors();
////				HudManager::updateCustomHudAmmosColors();
////			}
////		}*/
////
////		/*if (HudManager::isColorProfileUnknown() || HudManager::hasColorProfileChanged()) {
////			HudManager::updateCustomHudIceSpriteProfileColors();
////			HudManager::updateCustomHudAmmosColors();
////		}*/
////		
////		idRenderModelGui::drawCustomIceNadeSprite(guiAddr, HudManager::getCustomeHudIceSprite());
////
////		//auto FAKEhudAmmoDataVec = { HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, 76), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, 226), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, 6) };
////		//auto FAKEhudAmmoDataVec = { HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, 6), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, 26), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, 666) };
////
////		//HudManager::updateCustomHudAmmosData(FAKEhudAmmoDataVec);
////
////		//HudManager::updateCustomHudAmmosCoords();
////
////		//? this specific line degrades performances:
////		//HudManager::updateCustomHudAmmosData();
////		
////		if (IniConfig::isAmmoBar()) {
////			idRenderModelGui::drawCustomAmmosHud(guiAddr, HudManager::getCustomHudAmmos());
////
////		}		
////
////		return prender_gTestMaterial(a1);
////	}	
////
////
////	//? don't forget to press/trigger idCmd::reapplySwfColorsCmd() so that the sprite instances vec can be filled before using this	
////	/*idVec4 fakeHudEquipmentCoordsVev4 = idVec4(center_x + 100, center_y, 200, 50);
////	std::vector<hudSpriteId_t> spriteIds = { hudSpriteId_t::HUD_SPRITE_ID_FLAMEBELCH, hudSpriteId_t::HUD_SPRITE_ID_FUEL, hudSpriteId_t::HUD_SPRITE_ID_FRAG,  hudSpriteId_t::HUD_SPRITE_ID_FRAG , hudSpriteId_t::HUD_SPRITE_ID_ICE };
////	HudEquipment hudEquipment = HudEquipment(fakeHudEquipmentCoordsVev4, spriteIds);
////	hudEquipment.updateBase(spriteIds, fakeHudEquipmentCoordsVev4);
////	hudEquipment.updateCoords();
////	hudEquipment.updateData(3, 3, 12);
////	idRenderModelGui::drawHudEquipment(guiAddr, hudEquipment);*/	
////
////
////
////
////	return prender_gTestMaterial(a1);
////}
//
//
//
//
////! void __fastcall idRenderModelGui::DrawStretchPic_623070(__int64 gui_a1,float* x_a2,__int64 y_a3,__int64 text_a4,float* idColor_a5,__int64 matr_a6,float scale_a7)
////typedef void(__fastcall* idRenderModelGui_DrawStretchPic_623070)(__int64 gui_a1, float* x_a2, __int64 y_a3, __int64 text_a4, float* idColor_a5, __int64 matr_a6, float scale_a7);
////idRenderModelGui_DrawStretchPic_623070 pidRenderModelGui_DrawStretchPic_623070 = nullptr;
////idRenderModelGui_DrawStretchPic_623070 pidRenderModelGui_DrawStretchPic_623070Target;
////
////
////void __fastcall idRenderModelGui_DrawStretchPic_623070Hook(__int64 gui_a1, float* x_a2, __int64 y_a3, __int64 text_a4, float* idColor_a5, __int64 matr_a6, float scale_a7) {
////
////	//logInfo("idRenderModelGui_DrawStretchPic_623070Hook: guiptr: %p,  matptr: %p", (void*)gui_a1, (void*)matr_a6);
////	
////	return pidRenderModelGui_DrawStretchPic_623070(gui_a1, x_a2, y_a3, text_a4, idColor_a5, matr_a6, scale_a7);
////}
//
////! char __fastcall GetPerfMetricsStr_Smth_48FE40(__int64 idConsoleLocal_a1, __int64 x_a2, float *y_a3)
////typedef char (__fastcall* GetPerfMetricsStr)(__int64 idConsoleLocal_a1, __int64 x_a2, float* y_a3)
//
//
////? don't need to hook drawchar as it's not called
////! void __fastcall idRenderModelGui::DrawCharMb_622730(__int64 gui_a1, float x_a2, float y_a3, unsigned int text_a4, float idColor_a5)
////typedef void(__fastcall* idRenderModelGui_DrawChar(__int64 gui_a1, float x_a2, float y_a3, unsigned int text_a4, float idColor_a5);
//
//
//
//
////? this doesn't fucking work cause hooking func with variadic arg is almost impossible:
////! trying to hook this cause rendering from GetPerfMetricsStr_Smth_48FE40 still has perf issues
////! __int64 showPerfMetricsStrLine_4930A0(__int64 idConsoleLocal_a1, float *x_a2, int y_a3, float text_a4, __int64 idColor_a5, int a6, ...)
////typedef __int64 (__fastcall* showPerfMetricsStrLine)(__int64 idConsoleLocal_a1, float* x_a2, int y_a3, float text_a4, __int64 idColor_a5, int a6, ...);
////showPerfMetricsStrLine pshowPerfMetricsStrLine = nullptr;
////showPerfMetricsStrLine pshowPerfMetricsStrLineTarger;
////
////__int64 showPerfMetricsStrLineHook(__int64 idConsoleLocal_a1, float* x_a2, int y_a3, float text_a4, __int64 idColor_a5, int a6, ...) {
////
////	//consoleLocal.testDraw();
////
////	va_list args;
////	va_start(args, a6);
////	
////	va_end(args);
////
////	__int64 result = pshowPerfMetricsStrLine(idConsoleLocal_a1, x_a2, y_a3, text_a4, idColor_a5, a6, args);
////
////	return result;
////}
//
////! not useful and not triggered afaik
////void __fastcall keySerializeEndHook(signed int gui_a1, unsigned int x_a2) {
////	
////	//spdlog::info("keySerializeEndHook called BUT WE NEED TO DO SOMETHING WITH IT....: gui_a1: {} x_a2: {}", gui_a1, x_a2 );
////	return pkeySerializeEnd(gui_a1, x_a2);
////}
//
//
////! not useful atm
////void** __fastcall inMenuDetectionHook(_int64 gui_a1) {
////	spdlog::info("inMenuDetectionHook called...");
////	return pinMenuDetection(gui_a1);
////}
//
////! not useful atm
////char __fastcall inGameDetectionHook(__int64* gui_a1, __int64 x_a2) {
////	spdlog::info("inGameDetectionHook called...");
////	return pinGameDetection(gui_a1, x_a2);
////}
//
//
//
//
////typedef __int64(__fastcall* convertIdDeclUIColorToidColor)(__int64 idDeclUIColor_a1, __int64 idColor_a2, int colorId_a3);
////convertIdDeclUIColorToidColor pconvertIdDeclUIColorToidColor = nullptr;
////convertIdDeclUIColorToidColor pconvertIdDeclUIColorToidColorTarget;
////
////__int64 __fastcall convertIdDeclUIColorToidColorHook(__int64 idDeclUIColor_a1, __int64 idColor_a2, int colorId_a3) {
////
////	//! by acequiring this address we always know where the color of a specifi elelment on the hud is. this is useful when user changes profile cause idDeclUIColor_a1 will change in that case and there are many color profiles.
////	GameHudColorsManager::acquireIdDeclUIColorAddr(idDeclUIColor_a1);
////
////	//! we don't need that anymore because we just acquire idDeclUIColor_a1 and find the color ourselves.
////	//if (colorId_a3 == SWF_NAMED_COLOR_HUD_EQUIPMENT_CYRO) {
////	//	//*(_OWORD *)(idDeclUIColor_a1 + 0x1210);
////	//	HudManager::setCurrentIceNadeBackgroundColor(*(idColor*)(idDeclUIColor_a1 + 0x11FC));
////	//}
////	//else if (colorId_a3 == SWF_NAMED_COLOR_HUD_EQUIPMENT_CYRO_ICON) {
////	//	HudManager::setCurrentIceNadeIconColor(*(idColor*)(idDeclUIColor_a1 + 0x1210));
////	//}
////
////	idColor orangeColor;
////	orangeColor.r = 255.0f;  // Red component
////	orangeColor.g = 165.0f;  // Green component
////	orangeColor.b = 0.0f;    // Blue component
////	orangeColor.a = 255.0f;  // Alpha component
////
////
////	/*idColor unpacked_color{};
////	unpacked_color.a = (RGBA >> 24) / 255.0F;
////	unpacked_color.r = static_cast<unsigned char>(RGBA >> 16) / 255.0F;
////	unpacked_color.g = static_cast<unsigned char>(RGBA >> 8) / 255.0F;
////	unpacked_color.b = static_cast<unsigned char>(RGBA) / 255.0F;*/
////
////	//! invisibleFlagColorId is a colorId that is not used by the game (like invasion related color) we set that color id to elements we want to make disappear and then we set the actuall idColor, for ex for invasion color to be transparent:
////	if (colorId_a3 == UserColorSet::getinvisibleFlagColorId()) {
////		__int64 result = idColor_a2;
////		*(__m128i*)idColor_a2 = _mm_set_epi32(0, 0, 0, 0); //! set color "invisible"
////		return result;
////	}
////
////	//? doesn't work, color is invisible
////	//else if (colorId_a3 == UserColorSet::getAbsoluteOrangeFlagColorId()) {
////	//	__int64 result = idColor_a2;
////	//	*(__m128i*)idColor_a2 = _mm_set_epi32(255, 165, 0, 255); 
////	//	return result;
////	//}
////
////
////	//? doesn't work color invisible
////	/*else if (colorId_a3 == UserColorSet::getAbsoluteOrangeFlagColorId()) {
////		__int64 result = idColor_a2;
////		*(__m128i*)idColor_a2 = _mm_set_epi32(orangeColor.PackColor(), 0, 0, 0);
////		return result;
////	}*/
////
////	//? doesn't work color is the same as default hud color whatever the values are
////	//else if (colorId_a3 == UserColorSet::getAbsoluteOrangeFlagColorId()) {
////	//	idColor* colorPtr = reinterpret_cast<idColor*>(idColor_a2);
////	//	colorPtr->r = 0.0f;  // Red component
////	//	colorPtr->g = 0.0f;  // Green component
////	//	colorPtr->b = 255.0f;    // Blue component
////	//	colorPtr->a = 255.0f;  // Alpha component
////	//	//return result;
////	//}
////
////	//else if (colorId_a3 == UserColorSet::getAbsoluteOrangeFlagColorId()) {
////	//	idColor* colorPtr = reinterpret_cast<idColor*>(idColor_a2);
////	//	colorPtr->r = 0.0f;  // Red component
////	//	colorPtr->g = 0.0f;  // Green component
////	//	colorPtr->b = 255.0f;    // Blue component
////	//	colorPtr->a = 255.0f;  // Alpha component
////	//	//return result;
////	//}
////
////
////
////
////
////
////
////	//if (GameHudColorsManager::isEquipmentArrowFlag()) {
////	//	logInfo("convertIdDeclUIColorToidColorHook triggered for isEquipmentArrowFlag, idDeclUIColor_a1: %p idColor_a2 is: %p colorId_a3: %d", (void*)idDeclUIColor_a1, (void*)idColor_a2, colorId_a3);
////	//	colorId_a3 = SWF_NAMED_COLOR_INVASION_RED;
////	//	//colorId_a3 = SWF_NAMED_COLOR_DOOR_LOCK_BLUE; // <= this works
////	//}
////
////	//if (GameHudColorsManager::isEquipmentArrowOverideColor(colorId_a3)) {
////	//	logInfo("convertIdDeclUIColorToidColorHook triggered for EquipmentArrow, idDeclUIColor_a1: %p idColor_a2 is: %p colorId_a3: %d", (void*)idDeclUIColor_a1, (void*)idColor_a2, colorId_a3);
////	//	colorId_a3 = SWF_NAMED_COLOR_DOOR_LOCK_BLUE;
////	//	//return GameHudColorsManager::overideIdColor(idColor_a2, colorBlue);
////	//}
////
////	//x  it looks like we can use this only to change the color of the icons in the weaponinfo hud, which is weird but that's how it is and we can not change the color of the equipment arrow with this. great....
////	//! you can actually change the color of every hud element BUT, you have to do it at startup meaning with the mod loacing with the game, otherwise the only way to updateColor the colors for some of the hud is to change the color profile.
////
////
////
////
////	return pconvertIdDeclUIColorToidColor(idDeclUIColor_a1, idColor_a2, colorId_a3);
////}
//
//
//
//
////if (modStatus.isAllGood()) {
////	pidInventoryCollectionGetInventoryItemTarget = reinterpret_cast<idInventoryCollectionGetInventoryItem>(MemHelper::getFuncAddr(idInventoryCollectionGetInventoryItemOffset));
////	if (MH_CreateHook(reinterpret_cast<void**>(pidInventoryCollectionGetInventoryItemTarget), &idInventoryCollectionGetInventoryItemHook, reinterpret_cast<void**>(&pidInventoryCollectionGetInventoryItem)) != MH_OK) {
////		logErr("pidInventoryCollectionGetInventoryItemTarget CreateHook failed, mod can not start. pidInventoryCollectionGetInventoryItemTarget addr is %p", (void*)MemHelper::getFuncAddr(idInventoryCollectionGetInventoryItemOffset));
//
////		modStatus.setHookError();
//
////	}
////	/*else {
////		logInfo("pidInventoryCollectionGetInventoryItemTarget CreateHook : OK");
////	}*/
////}
//
//	/*if (modStatus.isAllGood()) {
//		pBindCopyControllerStrSomethingTarget = reinterpret_cast<BindCopyControllerStrSomething>(MemHelper::getFuncAddr(BindCopyControllerStrSomethingOffset));
//		if (MH_CreateHook(reinterpret_cast<void**>(pBindCopyControllerStrSomethingTarget), &pBindCopyControllerStrSomethingHook, reinterpret_cast<void**>(&pBindCopyControllerStrSomething)) != MH_OK) {
//			logErr("pBindCopyControllerStrSomethingHook CreateHook failed, mod can not start. pBindCopyControllerStrSomethingHook addr is %p", (void*)MemHelper::getFuncAddr(isKeyPressedOffset));
//
//			modStatus.setHookError();
//
//		}
//	}*/
//
//
//	/*if (modStatus.isAllGood()) {
//	pidResourceSmthTarget = reinterpret_cast<idResourceSmth>(MemHelper::getFuncAddr(idResourceSmthOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pidResourceSmthTarget), &idResourceSmthHook, reinterpret_cast<void**>(&pidResourceSmth)) != MH_OK) {
//		logErr("pidResourceSmthTarget CreateHook failed, mod can not start. pidResourceSmthTarget addr is %p", (void*)MemHelper::getFuncAddr(idResourceSmthOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
////! EquipmentInfo Hook not using to get the actual owned grenades anymore as it's unreliable but using it to get the idHudWeaponInfoPtr
////if (modStatus.isAllGood()) {
////	pEquipmentInfoTarget = reinterpret_cast<equipmentInfo>(MemHelper::getFuncAddr(equipmentFunctionAddrOffset));
////	if (MH_CreateHook(reinterpret_cast<void**>(pEquipmentInfoTarget), &equipmentInfoHook, reinterpret_cast<void**>(&pEquipmentInfo)) != MH_OK) {
////		logErr("equipmentInfoHook CreateHook failed, mod can not start. pEquipmentInfoTarget addr is: %p", (void*)(MemHelper::getFuncAddr(equipmentFunctionAddrOffset)));
//
////		modStatus.setHookError();
//
////	}
////	/*else {
////		logInfo("equipmentInfoHook MH_CreateHook: OK");
////	}*/
////}
//
///*if (modStatus.isAllGood()) {
//	prender_gTestMaterialTarget = reinterpret_cast<render_gTestMaterial>(MemHelper::getFuncAddr(renderTestMaterialOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(prender_gTestMaterialTarget), &render_gTestMaterialHook, reinterpret_cast<void**>(&prender_gTestMaterial)) != MH_OK) {
//		logErr("prender_gTestMaterialTarget CreateHook failed, mod can not start. prender_gTestMaterialTarget addr is %p", (void*)MemHelper::getFuncAddr(renderTestMaterialOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
///*if (modStatus.isAllGood()) {
//pidHUDMenuScreenPause_HandleActionTarget = reinterpret_cast<idHUDMenuScreenPause_HandleAction>(MemHelper::getFuncAddr(idHUDMenuScreenPauseHandleActionOffset));
//if (MH_CreateHook(reinterpret_cast<void**>(pidHUDMenuScreenPause_HandleActionTarget), &idHUDMenuScreenPause_HandleActionHook, reinterpret_cast<void**>(&pidHUDMenuScreenPause_HandleAction)) != MH_OK) {
//	logErr("pidHUDMenuScreenPause_HandleActionTarget CreateHook failed, mod can not start. pidHUDMenuScreenPause_HandleActionTarget addr is %p", (void*)MemHelper::getFuncAddr(idHUDMenuScreenPauseHandleActionOffset));
//
//	modStatus.setHookError();
//}
//}*/
//
///*if (modStatus.isAllGood()) {
//	pidDebugHUDLocal_RenderTarget = reinterpret_cast<idDebugHUDLocal_Render>(MemHelper::getFuncAddr(idDebugHUDLocalOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pidDebugHUDLocal_RenderTarget), &idDebugHUDLocal_RenderHook, reinterpret_cast<void**>(&pidDebugHUDLocal_Render)) != MH_OK) {
//		logErr("pidDebugHUDLocal_RenderTarget CreateHook failed, mod can not start. pidDebugHUDLocal_RenderTarget addr is %p", (void*)MemHelper::getFuncAddr(idDebugHUDLocalOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
///*if (modStatus.isAllGood()) {
//	pGetPerfMetricsStrTarget = reinterpret_cast<GetPerfMetricsStr>(MemHelper::getFuncAddr(GetPerfMetricsStrOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pGetPerfMetricsStrTarget), &GetPerfMetricsStrHook, reinterpret_cast<void**>(&pGetPerfMetricsStr)) != MH_OK) {
//		logErr("pGetPerfMetricsStrTarget CreateHook failed, mod can not start. pGetPerfMetricsStrTarget addr is %p", (void*)MemHelper::getFuncAddr(GetPerfMetricsStrOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
///*if (modStatus.isAllGood()) {
//	pshowPerfMetricsStrLineTarger = reinterpret_cast<showPerfMetricsStrLine>(MemHelper::getFuncAddr(showPerfMetricsStrLineOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pshowPerfMetricsStrLineTarger), &showPerfMetricsStrLineHook, reinterpret_cast<void**>(&pshowPerfMetricsStrLine)) != MH_OK) {
//		logErr("pshowPerfMetricsStrLineTarger CreateHook failed, mod can not start. pshowPerfMetricsStrLineTarger addr is %p", (void*)MemHelper::getFuncAddr(showPerfMetricsStrLineOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
//
///*if (modStatus.isAllGood()) {
//	pidRenderModelGui_DrawStringTarget = reinterpret_cast<idRenderModelGui_DrawString>(MemHelper::getFuncAddr(idRenderModelGui_DrawStringOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pidRenderModelGui_DrawStringTarget), &idRenderModelGui_DrawStringHook, reinterpret_cast<void**>(&pidRenderModelGui_DrawString)) != MH_OK) {
//		logErr("pidRenderModelGui_DrawStringTarget CreateHook failed, mod can not start. pidRenderModelGui_DrawStringTarget addr is %p", (void*)MemHelper::getFuncAddr(idRenderModelGui_DrawStringOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
///*if (modStatus.isAllGood()) {
//	pRenderShapeTarget = reinterpret_cast<RenderShape>(MemHelper::getFuncAddr(RenderShapeOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pRenderShapeTarget), &RenderShapeHook, reinterpret_cast<void**>(&pRenderShape)) != MH_OK) {
//		logErr("pRenderShapeTarget CreateHook failed, mod can not start. pRenderShapeTarget addr is %p", (void*)MemHelper::getFuncAddr(RenderShapeOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
///*if (modStatus.isAllGood()) {
//	pidSWF_Render_CallerTarget = reinterpret_cast<idSWF_Render_Caller>(MemHelper::getFuncAddr(idSWF_Render_CallerOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pidSWF_Render_CallerTarget), &idSWF_Render_CallerHook, reinterpret_cast<void**>(&pidSWF_Render_Caller)) != MH_OK) {
//		logErr("pidSWF_Render_CallerTarget CreateHook failed, mod can not start. pidSWF_Render_CallerTarget addr is %p", (void*)MemHelper::getFuncAddr(idSWF_Render_CallerOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
///*if (modStatus.isAllGood()) {
//	prenderSWFTarget = reinterpret_cast<renderSWF>(MemHelper::getFuncAddr(renderSWFOffset));
//	if (MH_CreateHook(reinterpret_cast<void**>(prenderSWFTarget), &renderSWFHook, reinterpret_cast<void**>(&prenderSWF)) != MH_OK) {
//		logErr("prenderSWFTarget CreateHook failed, mod can not start. prenderSWFTarget addr is %p", (void*)MemHelper::getFuncAddr(renderSWFOffset));
//
//		modStatus.setHookError();
//	}
//}*/
//
///*if (modStatus.isAllGood()) {
//	pidRenderModelGui_DrawStretchPic_623070Target = reinterpret_cast<idRenderModelGui_DrawStretchPic_623070>(MemHelper::getFuncAddr(DrawStretchPic_623070Offset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pidRenderModelGui_DrawStretchPic_623070Target), &idRenderModelGui_DrawStretchPic_623070Hook, reinterpret_cast<void**>(&pidRenderModelGui_DrawStretchPic_623070)) != MH_OK) {
//		logErr("pidRenderModelGui_DrawStretchPic_623070Target CreateHook failed, mod can not start. pidRenderModelGui_DrawStretchPic_623070Target addr is %p", (void*)MemHelper::getFuncAddr(DrawStretchPic_623070Offset));
//
//		modStatus.setHookError();
//	}
//}*/
//
///*if (modStatus.isAllGood()) {
//	pidRenderModelGui_DrawStretchPic_498ED0Target = reinterpret_cast<idRenderModelGui_DrawStretchPic_498ED0>(MemHelper::getFuncAddr(DrawStretchPic_498ED0Offset));
//	if (MH_CreateHook(reinterpret_cast<void**>(pidRenderModelGui_DrawStretchPic_498ED0Target), &idRenderModelGui_DrawStretchPic_498ED0Hook, reinterpret_cast<void**>(&pidRenderModelGui_DrawStretchPic_498ED0)) != MH_OK) {
//		logErr("pidRenderModelGui_DrawStretchPic_498ED0Target CreateHook failed, mod can not start. pidRenderModelGui_DrawStretchPic_498ED0Target addr is %p", (void*)MemHelper::getFuncAddr(DrawStretchPic_498ED0Offset));
//
//		modStatus.setHookError();
//	}
//}*/
//
//
//
//
//
//
////
//////! these are some of the functions or comments i deleted but that could come in handy someday:
////
////
////
////#include <windows.h>
////#include <string>
////#include <iostream>
////#include "MinHook.h"
////#include "intrin.h"
////#include <sstream> //for std::stringstream 
////#include <vector>
////#include <cstring>
////#include "DE/MemHelper.h"
//////#include "DE/Equipment.h"
////#include "DE/WeaponSettings.h"
//////#include "DE/idInventory.h"
////#include "DE/WeaponSwitcher.h"
////#include "DE/PlayerStateChecker.h"
////#include "DE/ButtonCheck.h"
////#include "DE/StringChanger.h"
////#include "DE/IniFile.h"
////#include "DE/GameStateChecker.h"
////#include "DE/LangManager.h"
////#include "DE/BindLabelChanger.h"
////#include "MD5/md5Check.h"
////#include "DE/ModStatus.h"
////#include "DE/idResource.h"
////#include "DE/ObjectLocator.h"
////#include "DE/idPlayer.h"
////#include "DE/idCmd.h"
////#include "DE/idDebugHUDLocal.h"
////#include "DE/idConsoleLocal.h"
////#include <stdarg.h>
////#include "Debug/SwfDebug.h"
////#include "DE/idFont.h"
////#include "DE/SwfHud.h"
////#include "DE/idHudEventManager.h"
////#include "DE/GameHudColorsManager.h"
//////#include "DE/Debug.h"
////
////
////#if _WIN64 
////#pragma comment(lib, "libMinHook.x64.lib")
////#else
////#pragma comment(lib, "libMinHook.x86.lib")
////#endif
////
////
////
////
////
////
////
////bool g_isGameInitialized = false;
////bool g_isDllCalledByGame = false;
////
////
////
//////! key pressed
////uint64_t g_lastGetAsyncKeyPress = 0;
////
////
//////unsigned int g_testIdNamedColorIndex = 94;
////
//////unsigned int g_namedColorBlue = 94; // blue
//////unsigned int g_namedColorDebug = 2;
////
//////std::vector<int> pathHashesDebugVec;
//////std::vector<spriteDebug> spriteDebugVec;
//////int hashDebugIndex = 0;
////
//////const int iceNadeSelected = 1;
//////const int normalNadeSelected = 2;
//////int nadeStatus = -1;
////
////std::string g_plusSignStr = "+";
////
//////? *****  looks like we have to be careful when instanciating those objects as, if one has a ctor that tries to writes to our console it will prevent the console from working.
////HINSTANCE DllHandle;
////WNDPROC wndproc_original = NULL;
////MemHelper mem;
//////BindHelper binderHelper;
//////EquipmentLauncher eql;
////WeaponSettings ws;
//////idInventory inv;
////WeaponSwitcher switcher;
////PlayerState playerState;
////ButtonCheck buttonCheck;
//////StringChanger stringChanger;
////IniFile iniFile;
////IniFileData iniFileData;
////LangManager lang;
////BindLabelChanger bindLabelChanger;
////Md5Check md5Check;
////ModStatus modStatus;
////idResource idRes;
//////idDebugHUDLocal debugHud;
////idConsoleLocal id_ConsoleLocal;
////SwfDebug swfDebug;
////SwfHud swfHud;
//////idFont IdFont;
//////? looks like we have to be careful when instanciating those objects as, if one has a ctor that tries to writes to our console it will prevent the console from working. *****
////
////
////
//////void initializeGameSettings() {
//////	idCmd::enableUISideNotification(false);
//////
//////}
////
////
////
//////__int64 __fastcall idInventoryCollection::GetInventoryItem_1D1D6A0(__int64 gui_a1, int x_a2)
//////typedef __int64(__fastcall* idInventoryCollectionGetInventoryItem)(__int64 gui_a1, int x_a2);
//////idInventoryCollectionGetInventoryItem pidInventoryCollectionGetInventoryItem = nullptr;
//////idInventoryCollectionGetInventoryItem pidInventoryCollectionGetInventoryItemTarget;
//////
//////__int64 __fastcall idInventoryCollectionGetInventoryItemHook(__int64 idInventoryCollectionPtr, int x_a2) {
//////
//////	//mem.aquire_idInventoryCollectionPtr(idInventoryCollectionPtr);
//////	//inv.acquire_idInventoryCollectionPtr(idInventoryCollectionPtr);
//////
//////	return pidInventoryCollectionGetInventoryItem(idInventoryCollectionPtr, x_a2);
//////}
////
////
////
//////typedef __int64(__fastcall* equipmentInfo)(__int64 gui_a1);
//////equipmentInfo pEquipmentInfo = nullptr;
//////equipmentInfo pEquipmentInfoTarget;
//////
//////__int64 __fastcall equipmentInfoHook(__int64 idHudWeaponInfoPtr) {
//////
//////	//switcher.aquire_idHudWeaponInfoPtr(idHudWeaponInfoPtr);
//////	//mem.aquire_idHudWeaponInfoPtr(idHudWeaponInfoPtr); //! this is needed to force weapon switching
//////	//! the arg here is a ptr to a idHud_WeaponInfo obj however it doesn't seem reliable to me to get the nade value. I'll use idplayer ptr + nade offset instead.
//////
//////	return pEquipmentInfo(idHudWeaponInfoPtr);
//////}
////
////
////
////
////
//////! char __fastcall idPlayer::ProcessInput_ServerAndClient_Local_1ABBDD0(__int64 gui_a1, char x_a2)
////typedef char(__fastcall* idPlayerProcessInputSACL)(__int64 a1, char a2);
////idPlayerProcessInputSACL pIdPlayerProcessInput = nullptr;
////idPlayerProcessInputSACL pIdPlayerProcessInputTarget;
////
////char __fastcall idPlayerProcessInputSACLHook(__int64 idPlayerPtr, char a2) {
////	//! as this is called (many times per seconds) only when player is in game it's a good way to find out if player is in menu or not and if we should disable the mod or not.
////		//binderHelper.updateIdplayerProcessInputTimeStamp();
////	//playerState.updateIdplayerProcessInputTimeStamp();
////	//PlayerStateChecker::updateLastInputProcess();
////
////	//mem.aquire_idPlayerPtr(idPlayerPtr);
////	//eql.aquire_idPlayerPtr(idPlayerPtr);
////
////	//inv.acquire_idPlayerPtr(idPlayerPtr);
////
////	ObjectLocator::aquireIdPlayerAddr(idPlayerPtr);
////
////
////	//mem.getCurrentlyEquippedWeaponIndex(); //todo -< for debugh pupose get rid of it when done !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////
////
////	return pIdPlayerProcessInput(idPlayerPtr, a2);
////}
////
////
////
////
//////! SelectWeaponForSelectionGroup Hook: char __fastcall SelectWeaponForSelectionGroupHook(__int64 gui_a1, int x_a2)
////typedef char(__fastcall* SelectWeaponForSelectionGroup)(__int64 a1, int a2);
////SelectWeaponForSelectionGroup pSelectWeaponForSelectionGroup = nullptr;
////SelectWeaponForSelectionGroup pSelectWeaponForSelectionGroupTarget;
////
//////! this is triggered everytime user presses a dedicated weapon key
////char __fastcall SelectWeaponForSelectionGroupHook(__int64 a1, int a2) {
////
////	/*spdlog::warn("(1) SelectWeaponForSelectionGroupHook current weap value : {}", mem.getCurrentlyEquippedWeaponValue());
////	spdlog::warn("SelectWeaponForSelectionGroupHook triggered...requested weapon index: {}", x_a2);
////	spdlog::warn("(2) SelectWeaponForSelectionGroupHook current weap value  : {}", mem.getCurrentlyEquippedWeaponValue());*/
////	//mem.printWeaponPotentia-è_çà)=yuiop^$hjklmù*n,;:!lErrorVal(gui_a1, x_a2);
////	//spdlog::info("SelectWeaponForSelectionGroupHook triggered...requested weapon index: {}", x_a2);
////	switcher.updateLastWeapKeyPress(a2, iniFileData.isImprovedWeaponSwitching());
////	//binderHelper.updateLastWeapKeyPress(x_a2);
////
////	return pSelectWeaponForSelectionGroup(a1, a2);
////}
////
////
////
//////! bool __fastcall isKeyPressed_1AE54F0(__int64 gui_a1, __int64 x_a2)
////typedef bool(__fastcall* isKeyPressed)(__int64 a1, __int64 a2);
////isKeyPressed pisKeyPressed = nullptr;
////isKeyPressed pisKeyPressedTarget;
////
////
//////? the original isKeyPressedHook is in Depreciated.h so you can modify this with no risk.
////bool __fastcall isKeyPressedHook(__int64 ptr, __int64 btnEnum) {
////
////	usercmdButton userCmdBtn = (usercmdButton)btnEnum;
////	switch (userCmdBtn)
////	{
////		/*case usercmdButton::BUTTON_NONE: // not checking this cause NONE is the value of the default weapon btn to resend.
////			break;	*/
////	case usercmdButton::BUTTON_CHANGEWEAPON:
////		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_CHANGEWEAPON)) {
////			switcher.disableEnumResend(usercmdButton::BUTTON_CHANGEWEAPON);
////		}
////		break;
////	case usercmdButton::BUTTON_WEAP_NEXT:
////		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_WEAP_NEXT)) {
////			switcher.disableEnumResend(usercmdButton::BUTTON_WEAP_NEXT);
////		}
////		break;
////	case usercmdButton::BUTTON_WEAP_PREV:
////		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_WEAP_PREV)) {
////			switcher.disableEnumResend(usercmdButton::BUTTON_WEAP_PREV);
////		}
////		break;
////	case usercmdButton::BUTTON_SHOTGUN:
////		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
////			return true;
////		}
////		break;
////	case usercmdButton::BUTTON_ASSAULT_RIFFLE:
////		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
////			return true;
////		}
////		break;
////	case usercmdButton::BUTTON_PLASMA:
////		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
////			return true;
////		}
////		break;
////	case usercmdButton::BUTTON_RL:
////		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
////			return true;
////		}
////		break;
////	case usercmdButton::BUTTON_SUPER_SHOTGUN:
////		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
////			return true;
////		}
////		break;
////	case usercmdButton::BUTTON_BALISTA:
////		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
////			return true;
////		}
////		break;
////	case usercmdButton::BUTTON_MINIGUN:
////		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
////			return true;
////		}
////		break;
////	case usercmdButton::BUTTON_BFG_UNMAKER:
////		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_BFG_UNMAKER)) {
////			switcher.disableEnumResend(usercmdButton::BUTTON_BFG_UNMAKER);
////		}
////		break;
////	case usercmdButton::BUTTON_WEAP_9: //! no idea what this weapon is, don't think it exists.
////		break;
////	case usercmdButton::BUTTON_BFG:
////		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_BFG)) {
////			switcher.disableEnumResend(usercmdButton::BUTTON_BFG);
////		}
////		break;
////	case usercmdButton::BUTTON_WALK:
////		break;
////	case usercmdButton::BUTTON_DASH:
////		break;
////	case usercmdButton::BUTTON_USE_EQUIPMENT:
////
////		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_USE_EQUIPMENT)) {
////			idPlayer::setGrenadeType(GrenadeType::Frag);
////			logInfo("BUTTON_USE_EQUIPMENT (Frag) pressed");
////			return true;
////		}
////		else if ((buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_OBJECTIVES))) {
////			idPlayer::setGrenadeType(GrenadeType::Ice);
////			logInfo("BUTTON_OBJECTIVES (Ice) pressed");
////			return true;
////		}
////
////		//eql.updateNadeStatus();		
////
////		//if (inv.isIceOwned() && eql.isIceRequestFlag() && eql.isFragSelected()) {
////		//	//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 1");
////		//	return false;
////		//}
////		//else if (inv.isIceOwned() && eql.isIceRequestFlag() && eql.isIceSelected()) {
////		//	eql.disableIceRequestFlag();
////		//	//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 2");
////		//	return true;
////		//}
////		//else if (inv.isFragOwned() && eql.isFragRequestFlag() && eql.isIceSelected()) {
////		//	//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 3");
////		//	return false;
////		//}
////		//else if (inv.isFragOwned() && eql.isFragRequestFlag() && eql.isFragSelected()) {
////		//	eql.disableFragRequestFlag();
////		//	//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 4");
////		//	return true;
////		//}
////		//else if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_USE_EQUIPMENT)) { //! if user actually pressed the key
////		//	if (inv.isFragOwned() && eql.isIceSelected()) {
////		//		eql.enableFragRequestFlag();
////		//		//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 5");
////		//		return false;
////		//	}
////		//	else if (inv.isFragOwned() && eql.isFragSelected()) {
////		//		eql.disableFragRequestFlag();
////		//		//spdlog::info("isKeyPressedHook: BUTTON_USE_EQUIPMENT cond 6");
////		//		return true;
////		//	}
////		//}
////
////		break;
////	case usercmdButton::BUTTON_SWITCH_EQUIPMENT:
////
////		/*eql.updateNadeStatus();
////
////		if (inv.isIceOwned() && eql.isIceRequestFlag() && eql.isFragSelected()) {
////			return true;
////		}
////		else if (inv.isFragOwned() && eql.isFragRequestFlag() && eql.isIceSelected()) {
////
////			return true;
////		}*/
////
////		break;
////	case usercmdButton::BUTTON_QUICK_3:
////		break;
////	case usercmdButton::BUTTON_INVENTORY:
////		break;
////	case usercmdButton::BUTTON_ACTIVATE_ABILITY:
////		break;
////	case usercmdButton::BUTTON_CRUCIBLE_HAMMER:
////		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_CRUCIBLE_HAMMER)) {
////			switcher.disableEnumResend(usercmdButton::BUTTON_CRUCIBLE_HAMMER);
////		}
////		break;
////	case usercmdButton::BUTTON_OBJECTIVES:
////
////		//if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_OBJECTIVES)) {
////
////		//	eql.updateNadeStatus();
////		//	//eql.updateNadeStatus();
////
////		//	if (inv.isIceOwned()) {
////		//		eql.enableIceRequestFlag();				
////		//	}
////		//	
////		//	return false;
////		//}
////		break;
////	default:
////		break;
////	}
////
////	return pisKeyPressed(ptr, btnEnum);
////}
////
////
////
////
//////! void __fastcall BindCopyControllerStrSomething_1C335A0(__int64 gui_a1, unsigned __int8 *x_a2)
//////typedef void(__fastcall* BindCopyControllerStrSomething)(__int64 gui_a1, unsigned __int8* x_a2);
//////BindCopyControllerStrSomething pBindCopyControllerStrSomething = nullptr;
//////BindCopyControllerStrSomething pBindCopyControllerStrSomethingTarget;
//////
////////! this will replace any string we need in the menu controller layouts screens
//////void __fastcall pBindCopyControllerStrSomethingHook(__int64 gui_a1, unsigned __int8* x_a2) {
//////
//////	//std::string a2AsStr(reinterpret_cast<char const*>(x_a2));
//////
//////	//unsigned char stringTest[13] = "Frag Grenade";
//////
//////	//if (a2AsStr == "Equipment Launcher") {
//////	//if (a2AsStr == EquipmentLauncherStr) {
//////	//	//return pBindCopyControllerStrSomething(gui_a1, stringTest);
//////	//	return pBindCopyControllerStrSomething(gui_a1, FragGrenadeCharArr);
//////	//}
//////	//else if (a2AsStr == MissionInformationStr) {
//////	//	return pBindCopyControllerStrSomething(gui_a1, IceGrenadeCharArr);
//////	//}
//////	//else {
//////	//	return pBindCopyControllerStrSomething(gui_a1, x_a2);
//////	//}
//////
//////
//////	return pBindCopyControllerStrSomething(gui_a1, x_a2);
//////}
////
////
//////! this triggers continuously when in any menu even main menu
//////! __int64 __fastcall idMenu::UpdateMb_1847CD0(__int64 *idMenu, __int64 x_a2)
////typedef __int64(__fastcall* idMenu_Update)(__int64 idMenu, __int64 a2);
////idMenu_Update pidMenu_Update = nullptr;
////idMenu_Update pidMenu_UpdateTarget;
////
////__int64 __fastcall idMenu_UpdateHook(__int64 idMenu, __int64 a2) {
////
////	//ObjectLocator::acquireCurrentIdMenuAddr(idMenu);
////	PlayerStateChecker::updateLastMenuRefresh(); //! this is a hacky and not so good way to know that the game has been (may be) initialized
////
////	//GameStateChecker::SetMainMenuLoaded();
////
////
////	//std::cout << "idMenu_UpdateHook called " << std::endl;
////	//x_a2 = 0;
////	//ws.acquire_idWeaponPtr(idWeaponPtr);
////
////
////	return pidMenu_Update(idMenu, a2);
////}
////
////
//////! __int64 __fastcall BindsStrSet_35CEC0(__int64 *gui_a1, unsigned __int8 *x_a2)
////typedef __int64(__fastcall* BindsStrSet)(__int64* a1, unsigned char* a2);
////BindsStrSet pBindsStrSet = nullptr;
////BindsStrSet pBindsStrSetTarget;
////
////__int64 __fastcall BindsStrSetHook(__int64* a1, unsigned char* a2) {
////
////	if (PlayerStateChecker::isInMenus()) {
////		bindLabelChanger.overwriteDynamicBindLabels(a2, lang.getLocalizedBindStringData());
////	}
////	return pBindsStrSet(a1, a2);
////}
////
////
////
//////! __int64 __fastcall idMaterial2_SomeInitFunc_464250(__int64 gui_a1)
////typedef __int64(__fastcall* idResourceSmth)(__int64 a1);
////idResourceSmth pidResourceSmth = nullptr;
////idResourceSmth pidResourceSmthTarget;
////
////__int64 __fastcall idResourceSmthHook(__int64 a1) {
////
////	/* debugHud.addResourcePtr(gui_a1);*/
////	idRes.addResourcePtr(a1);
////	return pidResourceSmth(a1);
////}
////
////
//////! used to trigger the updateColor of current game state: loading, main menu or ingame (in game doesn' necesserally mean playing)
//////! __int64 __fastcall idGameSystemLocal__MinimalGameCleanup_sub_CED020(	__int64 idGameSystemLocal_a1,	__int64 x_a2,	__int64* y_a3)
//////typedef __int64(__fastcall* idGameSystemLocalMinimalGameCleanup)(__int64 idGameSystemLocal_a1, __int64 x_a2, __int64* y_a3);
//////idGameSystemLocalMinimalGameCleanup pidGameSystemLocalMinimalGameCleanup = nullptr;
//////idGameSystemLocalMinimalGameCleanup pidGameSystemLocalMinimalGameCleanupTarget;
//////
//////__int64 __fastcall idGameSystemLocalMinimalGameCleanupHook(__int64 idGameSystemLocal_a1, __int64 x_a2, __int64* y_a3) {
//////
//////	//! not using this here as it trigger the check of before this func is executed, but this func will modify the state at offset 44 of idGameSystemLocal_a1 so we'll check check this value manually in the main loop
//////	//PlayerStateChecker::updateGameState(idGameSystemLocal_a1);
//////
//////	return pidGameSystemLocalMinimalGameCleanup(idGameSystemLocal_a1, x_a2, y_a3);
//////}
////
////
//////! void __fastcall idHUD_Reticle::SetActiveReticle_15773A0(__int64 idMenu, signed int x_a2, __int64 y_a3, unsigned __int8 text_a4)
////typedef void(__fastcall* idHUD_Reticle_SetActiveReticle)(__int64 a1, signed int a2, __int64 a3, unsigned __int8 a4);
////idHUD_Reticle_SetActiveReticle pidHUD_Reticle_SetActiveReticle = nullptr;
////idHUD_Reticle_SetActiveReticle pidHUD_Reticle_SetActiveReticleTarget;
////
////void __fastcall idHUD_Reticle_SetActiveReticleHook(__int64 a1, signed int a2, __int64 a3, unsigned __int8 a4) {
////
////	PlayerStateChecker::updateLastReticleRefresh();
////
////	pidHUD_Reticle_SetActiveReticle(a1, a2, a3, a4);
////}
////
////
//////! x_a2 will have a value of 15 when pause menu is active and value of 12 when the settings of the pause menu, and val of 0 when not in pause menu.
//////! char __fastcall idHUDMenu_Screen_Pause::HandleActionMb_16003D0(__int64 idHUDMenu_Screen_Pause_a1, __int64 x_a2)
//////typedef char(__fastcall* idHUDMenuScreenPause_HandleAction)(__int64 idHUDMenu_Screen_Pause_a1, __int64 x_a2);
//////idHUDMenuScreenPause_HandleAction pidHUDMenuScreenPause_HandleAction = nullptr;
//////idHUDMenuScreenPause_HandleAction pidHUDMenuScreenPause_HandleActionTarget;
//////
//////char __fastcall idHUDMenuScreenPause_HandleActionHook(__int64 idHUDMenu_Screen_Pause_a1, __int64 x_a2) {
//////	//static unsigned int lasta2Val = -1;
//////
//////	//unsigned int a2Val = *(unsigned int*)x_a2;
//////
//////	//ObjectLocator::acquire_idHUDMenu_Screen_Pause_Addr(idHUDMenu_Screen_Pause_a1);
//////
//////	//logInfo("idHUDMenuScreenPause_HandleActionHook a2Val %u", a2Val);
//////
//////
//////	/*if (a2Val != lasta2Val) {
//////		logInfo("idHUDMenuScreenPause_HandleActionHook x_a2 has changed from %u to %u", lasta2Val, a2Val);
//////		lasta2Val = a2Val;
//////	}*/
//////
//////	return pidHUDMenuScreenPause_HandleAction(idHUDMenu_Screen_Pause_a1, x_a2);
//////}
////
////
////
//////! void __fastcall idDebugHUDLocal::Render(idDebugHUDLocal *idMenuPtr_a1, idRenderModelGuis *x_a2)
//////! void __fastcall idDebugHUDLocal::Render_499690(__int64 idMenuPtr_a1, __int64 x_a2)
////typedef void(__fastcall* idDebugHUDLocal_Render)(__int64 a1, __int64 a2);
////idDebugHUDLocal_Render pidDebugHUDLocal_Render = nullptr;
////idDebugHUDLocal_Render pidDebugHUDLocal_RenderTarget;
////
////void __fastcall idDebugHUDLocal_RenderHook(__int64 idDebugHudAddr_a1, __int64 idRenderModelGuiAddr_a2) {
////
////
////
////	ObjectLocator::acquire_idDebugHUDAddr(idDebugHudAddr_a1);
////	//ObjectLocator::acquire_DebugHud_idRenderModelGuiAddr(idRenderModelGuiAddr_a2);
////	//debugHud.acquirePtrs(gui_a1, x_a2);
////
////
////	//? 24/3/23: this is the one you want to uncomment for the final version of this mod:
////	//debugHud.testCrosshairObject(); 
////
////
////	//! using this at the exultia bridge will definitely lower performance like 102 fps insteae of 115
////	//debugHud.testDraw();
////
////
////	//debugHud.testDraw();
////	//? this doesn't fixed the crash when going from loading menu <=> loading game
////	/*if (debugHud.isRenderAllowedTest) {
////		debugHud.testDraw(g_isCrossHairTest);
////	}*/
////	//debugHud.drawBox(g_isCrossHairTest);
////	//debugHud.debugGetMaterial();
////
////
////
////	return pidDebugHUDLocal_Render(idDebugHudAddr_a1, idRenderModelGuiAddr_a2);
////}
////
////
//////! this func is triggered when game is about to print performance metrics is it's enabled.
//////! char __fastcall GetPerfMetricsStr_Smth_48FE40(__int64 idConsoleLocal, __int64 x_a2, float *y_a3)
////typedef char(__fastcall* GetPerfMetricsStr)(__int64 idConsoleLocal, __int64 a2, float* a3);
////GetPerfMetricsStr pGetPerfMetricsStr = nullptr;
////GetPerfMetricsStr pGetPerfMetricsStrTarget;
////
////char __fastcall GetPerfMetricsStrHook(__int64 idConsoleLocal, __int64 a2, float* a3) {
////
////	ObjectLocator::acquire_idConsoleLocal_And_idRenderModelGuiAddr(idConsoleLocal); //! modelgui ptr at gui_a1 + 0xD8
////
////	//idRenderModelGui::isGetPerfMetricsStrTriggered = 1;
////
////	//logInfo("debug bookmark 0");
////
////	//! triggering rendering of string first so user can still see framerate
////	id_ConsoleLocal.raiseRenderDrawStringFlag(); //! this will also reset most data in id_ConsoleLocal
////
////	//! if GetPerfMetricsStrHook has been called we should now render the crosshair and other stretched pics
////	//id_ConsoleLocal.setRenderStretchedPicFlag(true);
////
////	//return 1; <= this doesn't reduce perf issue.
////
////	//! i don't think this init smth would help even though i didn't test it cause it's a pain in the but to implement
////	/*consoleLocal.initSmth(idConsoleLocal + 0x61E7A8, );
////	consoleLocal.initSmth(idConsoleLocal + 0x61E7C8);*/
////
////	//consoleLocal.testDraw();
////
////	//consoleLocal.testCrosshairObject();
////	//consoleLocal.testDraw();
////
////	//return 1; // <= this doesn't reduce perf issue.
////
////
////	return pGetPerfMetricsStr(idConsoleLocal, a2, a3);
////}
////
////
////
////
////
//////! void __fastcall RenderShape_4FDD30(__int64 gui_a1, __int64 x_a2, __int64 y_a3, __int64 text_a4, float *idColor_a5, float *a6)
////typedef void(__fastcall* RenderShape)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, float* a5, float* a6);
////RenderShape pRenderShape = nullptr;
////RenderShape pRenderShapeTarget;
////
////void __fastcall RenderShapeHook(__int64 a1, __int64 a2, __int64 a3, __int64 a4, float* a5, float* a6) {
////
////	/*if ((PlayerStateChecker::isPlaying())) {
////		if (swfDebug.isHudSwf(a1, swfDebug.swfWeaponinfoName)) {
////			swfDebug.logSwfHudElementInfos(a2, a2, a3, a4, a5, a6, swfDebug.swfWeaponinfoName);
////		}
////
////	}*/
////
////	//? this actually works to only show the text of health and armor and rad suit and i suppose oxygen level.
////	/*if (swfHud.isHealthHud(a1)) {
////		return;
////	}*/
////
////	//? this works:
////	/*if (swfHud.isBloodPunchHud(a1)) {
////		return;
////	}*/
////
////	//swfDebug.changeEquipmentArrowColor(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
////
////	//? this works and will will act only if gui_a1 is a swfWeaponinfoName
////	//swfHud.OverideEquipmentArrowColor(a1, a3, a4, a6);
////
////
////	//? this works and will act only if gui_a1 is a swfBloodPunchName
////	//swfHud.OverrideBloodPunchIconColor(a1, a3, a4, a6);
////
////	/*if (swfHud.isEquipmentHud(gui_a1)) {
////		swfHud.OverideEquipmentArrowColor(gui_a1, y_a3, text_a4, idColor_a5, a6);
////		return pRenderShape(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
////	}*/
////
////
////	//swfDebug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, swfDebug.swfWeaponinfoName);
////
////	//if (*(float*)(idColor_a5 + 4) > 1780.0f) { //? temp way to decluter debug log
////	//	swfDebug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, swfDebug.swfWeaponinfoName);
////	//}
////
////
//////	//if (*(float*)(idColor_a5 + 4) > 1.0f) { //? temp way to decluter debug log
//////	//	swfDebug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, swfDebug.swfWeaponinfoName);
//////	//}
////
//////	//swfDebug.OverideEquipmentArrowAndBarColors(gui_a1, text_a4, idColor_a5);
//////	
////
//////	return pRenderShape(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//////}
////
////
//////return;
////
//////debug.modifyCrosshairColor(gui_a1, text_a4, idColor_a5);
////
////
//////! could not do anything interesting with race car hud:
//////if (swfDebug.isHudSwf(gui_a1, swfDebug.swfRaceCarHudinfoName)) {
//////	swfDebug.modifyRaceCarHud(gui_a1, x_a2, y_a3, text_a4, idColor_a5); //! this doesn't work we can not change Y position.
////
//////	//swfDebug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, swfDebug.swfRaceCarHudinfoName);
//////	//swfDebug.modifyCrosshairColor(gui_a1, text_a4, idColor_a5);
//////	return pRenderShape(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//////}
////
////
//////return;
////
/////*if (y_a3 == 0x1F73F0525C0) {
////	return;
////}*/
////
//////debug.logRaceHudeInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//////debug.modifyHudReticleVals(gui_a1, x_a2, text_a4); // this works aside from the xy change
//////debug.modifyUnknown(gui_a1, y_a3); 
//////debug.logHudReticleInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//////debug.log_SWF_Data(gui_a1);
//////debug.OverideEquipmentArrowAndBarColors(gui_a1, text_a4, idColor_a5);
//////debug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, debug.swfReticuleName);
//////debug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, debug.swfWeaponinfoName);
////
//////debug.saveHudReticleSwfAddr(gui_a1);
//////debug.GetColorInfoFromRenderShape_Smth_4FDD30(text_a4);
////
//////debug.saveRenderShapeidDeclSWFptr(gui_a1);
////
////	return pRenderShape(a1, a2, a3, a4, a5, a6);
////}
////
////
//////! this func does calculation on the renderModelgui which is going to render the hud so let's try to use it:
//////! void __fastcall Calls_idSWF_Render_1C09690(__int64 gui_a1, __int64 x_a2, __int64 *y_a3, char text_a4, char idColor_a5, char a6)
//////typedef void(__fastcall* idSWF_Render_Caller)(__int64 gui_a1, __int64 x_a2, __int64* y_a3, char text_a4, char idColor_a5, char a6);
//////idSWF_Render_Caller pidSWF_Render_Caller = nullptr;
//////idSWF_Render_Caller pidSWF_Render_CallerTarget;
//////
//////void __fastcall idSWF_Render_CallerHook(__int64 gui_a1, __int64 x_a2, __int64* y_a3, char text_a4, char idColor_a5, char a6) {
//////
//////	//ObjectLocator::acquire_idSWF_idRenderModelGuiAddr(gui_a1);
//////	
//////	//? 1/2 the render gui Addr will be null, i'll try to stick with the render gui addr from idConsole
//////	//ObjectLocator::acquire_idSWF_ATL_idRenderModelGuiAddr(x_a2);
//////
//////	//debug.crosshairTest(); // this doesn't work it draws nothing and huge perf impact
//////
//////	return pidSWF_Render_Caller(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//////}
////
////
//////! trying to get material name so we can change color for elements we want
//////! void __fastcall renderSWF_Smth_4FCF80(__int64 idDeclSWF_Ptr_a1,__int64 x_a2,float* y_a3,float* text_a4,__int64 idMaterial2_a5,unsigned int a6,char scale_a7)
////typedef void(__fastcall* renderSWF)(__int64 idDeclSWF_Ptr_a1, __int64 a2, float* a3, float* a4, __int64 idMaterial2_a5, unsigned int a6, char a7);
////renderSWF prenderSWF = nullptr;
////renderSWF prenderSWFTarget;
////
////void __fastcall renderSWFHook(__int64 idDeclSWF_Ptr_a1, __int64 a2, float* a3, float* a4, __int64 idMaterial2_a5, unsigned int a6, char a7) {
////
////	//? the matr here will always be stencil something, never grenade, flame or anything like that...
////	/*if (PlayerStateChecker::isPlaying()) {
////
////		swfDebug.log_renderSWF_Smth_4FCF80_MatrName(idMaterial2_a5);
////
////	}*/
////	return prenderSWF(idDeclSWF_Ptr_a1, a2, a3, a4, idMaterial2_a5, a6, a7);
////}
////
////
////
////
////
//////! __int64 __fastcall idRenderModelGui::DrawString_6239F0(__int64 idMenuPtr_a1,float x_a2,float y_a3,char* text_a4,__int64 idColor_a5,char a6,float scale_a7)
////typedef __int64(__fastcall* idRenderModelGui_DrawString)(__int64 a1, float a2, float a3, const char* a4, __int64 a5, char a6, float a7);
////idRenderModelGui_DrawString pidRenderModelGui_DrawString = nullptr;
////idRenderModelGui_DrawString pidRenderModelGui_DrawStringTarget;
////
//////!DrawString(idRenderModelGuiAdrr, x, y, text, (__int64)&idColor, 0, scale);
////__int64 __fastcall idRenderModelGui_DrawStringHook(__int64 gui_a1, float x_a2, float y_a3, const char* text_a4, __int64 idColor_a5, char a6, float scale_a7) {
////	//? the reason why this is such a mess is because we can not just trigger drawstring or drawstretchPic with func pointersfrom our code whatever we do, it will have an impact on performance. however this way perf "seems" fine.
////
////	//! this should hopefully prevent message in the console being unreadable
////	if (id_ConsoleLocal.isConsoleOpened()) {
////		id_ConsoleLocal.setFont(idFontEnum::defaultCourrierF8);
////		return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
////	}
////	else {
////		id_ConsoleLocal.setFont(idFontEnum::ttSuper98); //! numeral font
////	}
////
////	//! this should make sure to always show the FPS counter if user chooses it
////	//? hopefully it's the only string in the game that has this scale...If you ever seem some weird scale strings it will be because of this:
////	if (id_ConsoleLocal.isRenderFpsCounter(scale_a7)) {
////		//logInfo("debug bookmark 1");
////		return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
////	}
////
////	if (PlayerStateChecker::isPlaying() && id_ConsoleLocal.isRenderStringFlag()) {
////		//logInfo("debug bookmark 2");
////		//DrawStringHookArgs args = id_ConsoleLocal.getDrawStringHookArgs();
////		DrawStringHookArgs args = id_ConsoleLocal.getDrawStringHookArgsV2();
////		//logInfo("idRenderModelGui_DrawStringHook args.str: %s", args.str.c_str());
////		strcpy((char*)text_a4, args.str.c_str());
////		x_a2 = args.x;
////		y_a3 = args.y;
////		idColor_a5 = (__int64)&args.IdColor;
////		scale_a7 = args.scale;
////	}
////
////	else { //? or return 1 or smth?		
////		//logInfo("debug bookmark 2.5");
////
////		//! attempting this if it false just uncomment the comment below
////		if (!id_ConsoleLocal.isRenderStretchedPicFlag()) {
////			strcpy((char*)text_a4, id_ConsoleLocal.getEmptyString().c_str());
////		}
////
////		//! this is what you want to uncomment if what is above fails
////		//strcpy((char*)text_a4, id_ConsoleLocal.getEmptyString().c_str());
////
////		//id_ConsoleLocal.raiseRenderStretchedPicFlag(); //? <= experiment........
////		//logInfo("idRenderModelGui_DrawStringHook else cond");
////		return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
////	}
////
////
////	//? (unsigned int*)(gui_a1 + 0x4D0) = colorPurple.PackColor(); // <= this doesn't work even with a6 set to 1 or 0.
////	//return 1;
////
////	/*std::string drawStringStrArg = text_a4;
////	logInfo("idRenderModelGui_DrawStringHook: drawStringStrArg: %s", drawStringStrArg.c_str());
////	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);*/
////
////	//idRenderModelGui::isDrawStringTriggered = 1;
////
////
////	//! this absolutely has impoact on perf.
////	//consoleLocal.testDraw();
////
////	//! it "feels' like there is a perf cost to this, i guess it's manageable but there should be not perf cost so NO.
////	//consoleLocal.testCrosshairObject();
////
////	//return consoleLocal.getIdColorPackColorWhite();
////	//return 1;
////
////	//std::string drawStringStrArg = "+";
////	//strcpy((char*)text_a4, g_plusSignStr.c_str());
////	//strcpy((char*)text_a4, drawStringStrArg.c_str());
////
////
////
////	//std::string drawStringStrArg = text_a4;
////	//logInfo("idRenderModelGui_DrawStringHook: drawStringStrArg: %s", drawStringStrArg.c_str());
////	//logInfo("idRenderModelGui_DrawStringHook: gui_a1: %p", (void*)gui_a1);
////
////	//gui.acquirePtr(idMenuPtr_a1);
////
////	//LI("idRenderModelGui_DrawStringHook x= %.2f y= %.2f %s", x_a2, y_a3, text_a4);
////	//const char* plusCh = "+";
////	//const char* dotCh = ".";
////	//const char* plusCh = "AAAA";
////
////
////	//return pidRenderModelGui_DrawString(idMenuPtr_a1, 800.00, 102.00, dotCh, (__int64)&colorRed, 0, 3.0f);
////	//return pidRenderModelGui_DrawString(idMenuPtr_a1, 800.00, 102.00, dotCh, idColor_a5, a6, 3);
////	// 
////	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
////}
////
////
////
////
//////! void __fastcall idRenderModelGui::DrawStretchPic_498ED0(__int64 gui_a1,float x_a2,float y_a3,float text_a4,float idColor_a5,float a6,float scale_a7,float a8,float a9,float a10,__int64 a11)
////typedef void(__fastcall* idRenderModelGui_DrawStretchPic_498ED0)(__int64 a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, __int64 a11);
////idRenderModelGui_DrawStretchPic_498ED0 pidRenderModelGui_DrawStretchPic_498ED0 = nullptr;
////idRenderModelGui_DrawStretchPic_498ED0 pidRenderModelGui_DrawStretchPic_498ED0Target;
////
//////! guiPtr, x, y, z, w, h, s1, t1, s2, t2, mapPtr
////void __fastcall idRenderModelGui_DrawStretchPic_498ED0Hook(__int64 a1, float x, float y, float z, float w, float h, float a7, float a8, float a9, float a10, __int64 matr) {
////
////	//? apparently uncommenting this will make the idConsole totally white, haven't figured out why.
////	//if (id_ConsoleLocal.isConsoleOpened()) {
////	//	id_ConsoleLocal.setFont(idFontEnum::defaultCourrierF8);
////	//	*(unsigned int*)(gui_a1 + 0x4D0) = colorWhite.PackColor(); //! set pic color	
////	//	//if (*(unsigned int*)(gui_a1 + 0x4D0) != colorWhite.PackColor()) {
////	//	//	*(unsigned int*)(gui_a1 + 0x4D0) = colorWhite.PackColor(); //! set pic color	
////	//	//}		
////	//	return pidRenderModelGui_DrawStretchPic_498ED0(gui_a1, x, y, z, w, h, scale_a7, a8, a9, a10, matr);
////	//}
////
////	//! giving up on rendering just one string and changing its color mid string, it just gets too bloated....
////	//if (PlayerStateChecker::isPlaying() && id_ConsoleLocal.getAmmoLetterIndex() >= 0) {
////	//	if (id_ConsoleLocal.getAmmoLetterIndex() >= 15) {
////	//		*(unsigned int*)(gui_a1 + 0x4D0) = colorWhite.PackColor(); //! set pic color	
////	//	}
////	//	else if (id_ConsoleLocal.getAmmoLetterIndex() >= 12) {
////	//		*(unsigned int*)(gui_a1 + 0x4D0) = colorPurple.PackColor(); //! set pic color	
////	//	}
////	//	else if (id_ConsoleLocal.getAmmoLetterIndex() >= 8) {
////	//		*(unsigned int*)(gui_a1 + 0x4D0) = colorYellow.PackColor(); //! set pic color	
////	//	}
////	//	else if (id_ConsoleLocal.getAmmoLetterIndex() >= 4) {
////	//		*(unsigned int*)(gui_a1 + 0x4D0) = colorOrange.PackColor(); //! set pic color	
////	//	}
////	//	else if (id_ConsoleLocal.getAmmoLetterIndex() >= 0) {
////	//		*(unsigned int*)(gui_a1 + 0x4D0) = colorRed.PackColor(); //! set pic color	
////	//	}
////	//	else {
////	//		*(unsigned int*)(gui_a1 + 0x4D0) = colorWhite.PackColor(); //! set pic color	
////
////	//	}
////	//	return pidRenderModelGui_DrawStretchPic_498ED0(gui_a1, x, y, z, w, h, scale_a7, a8, a9, a10, matr);
////	//}
////
////	//! by adding this if i was able to render more than the crosshair on the screen with perf metrics set to High:
////	if (PlayerStateChecker::isPlaying() && !id_ConsoleLocal.isRenderStretchedPicFlag() && !id_ConsoleLocal.isRenderStringFlag() && !id_ConsoleLocal.isConsoleOpened()) {
////
////		*(unsigned int*)(a1 + 0x4D0) = colorInvisible.PackColor(); //! set pic color	
////		return pidRenderModelGui_DrawStretchPic_498ED0(a1, x, y, z, w, h, a7, a8, a9, a10, matr);
////	}
////
////	//! draw crosshair
////	if (PlayerStateChecker::isPlaying() && id_ConsoleLocal.isRenderStretchedPicFlag()) {
////		//logInfo("debug bookmark 3");
////
////		auto args = id_ConsoleLocal.getdrawStretchHookPicArgs();
////		//logInfo("args.x: %2f", args.x);
////
////		*(unsigned int*)(a1 + 0x4D0) = args.packedColor; //! set pic color	
////		return pidRenderModelGui_DrawStretchPic_498ED0(a1, args.x, args.y, z, args.w, args.h, a7, a8, a9, a10, args.material);
////	}
////
////	return pidRenderModelGui_DrawStretchPic_498ED0(a1, x, y, z, w, h, a7, a8, a9, a10, matr);
////
////
////	//static __int64 iceNadeMatrAddr = 0;
////	//logInfo("idRenderModelGui_DrawStretchPic_498ED0Hook: guiptr: %p, x: %.2f, y: %.2f, z: %.2f, w: %.2f, h: %.2f matptr: %p", (void*)gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, (void*)a11);
////
////}
////
////
////
//////! this is used to hopefully intercet menus state, gamestate, game initialized and things like that
//////! void __fastcall idBroadcastManager::ReleaseBroadcastEvent_4899C0(__int64 gui_a1, __int64 x_a2, __int64 y_a3)
////typedef void(__fastcall* idBroadcastManager_ReleaseBroadcastEvent)(__int64 a1, __int64 a2, __int64 a3);
////idBroadcastManager_ReleaseBroadcastEvent pidBroadcastManager_ReleaseBroadcastEvent = nullptr;
////idBroadcastManager_ReleaseBroadcastEvent pidBroadcastManager_ReleaseBroadcastEventTarget;
////
////void __fastcall idBroadcastManager_ReleaseBroadcastEventHook(__int64 a1, __int64 a2, __int64 a3) {
////
////	//! Handle events
////	idHudEventManager::onReleasedBroadcastEvent(a3);
////
////	//if (a3) {
////	//	unsigned int potentialHudEventId = *(unsigned int*)a3;
////	//	if (potentialHudEventId == 11) {
////	//		logInfo("idBroadcastManager_ReleaseBroadcastEventHook: change weapon event detected !  event type: %hu", (__int16)a2);
////	//	}
////	//	else if (potentialHudEventId == 2) {
////	//		logInfo("idBroadcastManager_ReleaseBroadcastEventHook: change health event detected ! event type: %hu", (__int16)a2);
////	//	}
////	//	else if (potentialHudEventId == 6) {
////	//		logInfo("idBroadcastManager_ReleaseBroadcastEventHook: ammo change event detected ! event type: %hu", (__int16)a2);
////	//	}
////	//	else if (potentialHudEventId == 7) {
////	//		logInfo("idBroadcastManager_ReleaseBroadcastEventHook: ammo pickup event detected ! event type: %hu", (__int16)a2);
////	//	}
////	//	else if (potentialHudEventId == 0xE) {
////	//		logInfo("idBroadcastManager_ReleaseBroadcastEventHook: equipment updateColor event detected ! event type: %hu", (__int16)a2);
////	//	}
////	//	//? those are not usuable as event 0 fires all the time
////	//	/*else if (potentialHudEventId == 0) {
////	//		logInfo("idBroadcastManager_ReleaseBroadcastEventHook: menu activated event detected ! event type: %hu", (__int16)x_a2);
////	//	}
////	//	else if (potentialHudEventId == 1) {
////	//		logInfo("idBroadcastManager_ReleaseBroadcastEventHook: menu deactivated event detected ! event type: %hu", (__int16)x_a2);
////	//	}*/
////
////	//}
////	//if (PlayerStateChecker::isPlaying()){
////	//	if (y_a3) {
////	//		unsigned int potentialHudEventId = *(unsigned int*)y_a3;
////	//		if (potentialHudEventId == 11) {
////	//			logInfo("idBroadcastManager_ReleaseBroadcastEventHook: change weapon event detected !  event type: %hu", (__int16)x_a2);
////	//		}
////	//		else if (potentialHudEventId == 2) {
////	//			logInfo("idBroadcastManager_ReleaseBroadcastEventHook: change health event detected ! event type: %hu", (__int16)x_a2);
////	//		}
////	//		else if (potentialHudEventId == 6) {
////	//			logInfo("idBroadcastManager_ReleaseBroadcastEventHook: ammo change event detected ! event type: %hu", (__int16)x_a2);
////	//		}
////	//		else if (potentialHudEventId == 7) {
////	//			logInfo("idBroadcastManager_ReleaseBroadcastEventHook: ammo pickup event detected ! event type: %hu", (__int16)x_a2);
////	//		}
////	//		else if (potentialHudEventId == 0) {
////	//			logInfo("idBroadcastManager_ReleaseBroadcastEventHook: menu activated event detected ! event type: %hu", (__int16)x_a2);
////	//		}
////	//		else if (potentialHudEventId == 1) {
////	//			logInfo("idBroadcastManager_ReleaseBroadcastEventHook: menu deactivated event detected ! event type: %hu", (__int16)x_a2);
////	//		}
////	//		//logInfo("idBroadcastManager_ReleaseBroadcastEventHook: gui_a1: %llx , x_a2: %hu, y_a3: %llx", gui_a1, (__int16)x_a2, y_a3);
////	//	}
////
////
////
////	return pidBroadcastManager_ReleaseBroadcastEvent(a1, a2, a3);
////}
////
////
////
//////! this will hopefully let us change the color of ui elements at will
//////! __int64 __fastcall convertIdDeclUIColorToidColor_Mb_4D5AF0(__int64 idDeclUIColor_a1, __int64 idColor_a2, int y_a3)
////typedef __int64(__fastcall* convertIdDeclUIColorToidColor)(__int64 idDeclUIColor_a1, __int64 idColor_a2, int colorId_a3);
////convertIdDeclUIColorToidColor pconvertIdDeclUIColorToidColor = nullptr;
////convertIdDeclUIColorToidColor pconvertIdDeclUIColorToidColorTarget;
////
////__int64 __fastcall convertIdDeclUIColorToidColorHook(__int64 idDeclUIColor_a1, __int64 idColor_a2, int colorId_a3) {
////
////
////	//if (GameHudColorsManager::isEquipmentArrowFlag()) {
////	//	logInfo("convertIdDeclUIColorToidColorHook triggered for isEquipmentArrowFlag, idDeclUIColor_a1: %p idColor_a2 is: %p colorId_a3: %d", (void*)idDeclUIColor_a1, (void*)idColor_a2, colorId_a3);
////	//	colorId_a3 = SWF_NAMED_COLOR_INVASION_RED;
////	//	//colorId_a3 = SWF_NAMED_COLOR_DOOR_LOCK_BLUE; // <= this works
////	//}
////
////	//if (GameHudColorsManager::isEquipmentArrowOverideColor(colorId_a3)) {
////	//	logInfo("convertIdDeclUIColorToidColorHook triggered for EquipmentArrow, idDeclUIColor_a1: %p idColor_a2 is: %p colorId_a3: %d", (void*)idDeclUIColor_a1, (void*)idColor_a2, colorId_a3);
////	//	colorId_a3 = SWF_NAMED_COLOR_DOOR_LOCK_BLUE;
////	//	//return GameHudColorsManager::overideIdColor(idColor_a2, colorBlue);
////	//}
////
////	//x  it looks like we can use this only to change the color of the icons in the weaponinfo hud, which is weird but that's how it is and we can not change the color of the equipment arrow with this. great....
////	//! you can actually change the color of every hud element BUT, you have to do it at startup meaning with the mod loacing with the game, otherwise the only way to updateColor the colors for some of the hud is to change the color profile.
////
////	//enum_a3 = 95;
////
////	//if (enum_a3 == 2) { //! SWF_NAMED_COLOR_HUD_TEXT
////	//	//enum_a3 = -1; //! invalid color
////	//	//enum_a3 = 94; //! blue
////	//	enum_a3 = 95;//! 95 red
////	//}
////
////	//if (enum_a3 == 14) { //! rad suit
////	//	enum_a3 = 37;
////	//}
////	//else if (enum_a3 == 15) { //! rad suit gradient
////	//	enum_a3 = 38;
////	//}
////	//else if (enum_a3 == 258 || enum_a3 == 259) { //! bp
////	//	enum_a3 = 149;
////	//}
////
////	//enum_a3 = 64;
////
////
////	return pconvertIdDeclUIColorToidColor(idDeclUIColor_a1, idColor_a2, colorId_a3);
////}
////
////
////
////
////
////
//////! void __fastcall setSpriteInstanceColor_Smth_52F750(idSWFSpriteInstance* idSWFSpriteInstance_a1,unsigned int namedColorId_a2)
////typedef void(__fastcall* setSpriteInstanceColor)(__int64 idSWFSpriteInstance_a1, unsigned int namedColorId_a2);
////setSpriteInstanceColor psetSpriteInstanceColor = nullptr;
////setSpriteInstanceColor psetSpriteInstanceColorTarget = nullptr;
////
////void __fastcall setSpriteInstanceColorHook(__int64 idSWFSpriteInstance_a1, unsigned int namedColorId_a2) {
////
////
////	//! use this to refine search of hud elements based on their color:
////	if (GameHudColorsManager::isSpriteColorIdBeingDebugged(namedColorId_a2)) {
////		GameHudColorsManager::addSpriteInstanceAddrToDebugVec(idSWFSpriteInstance_a1);
////	}
////
////	//! using this just to identify clearly each element we have found previously and for which we have gotten an id.
////	/*if (GameHudColorsManager::isSpriteIdBeingDebugged(idSWFSpriteInstance_a1)) {
////		GameHudColorsManager::addSpriteInstanceAddrToDebugVec(idSWFSpriteInstance_a1);
////	}*/
////
////
////	//! this is great to get a log of every hud elements
////	//GameHudColorsManager::debugLogSpriteInstance(idSWFSpriteInstance_a1);
////
////	//! if we care about this hud element
////	GameHudColorsManager::acquireMonitoredSpriteInstanceAddr(idSWFSpriteInstance_a1);
////
////
////	//todo need to have the ini file or config check which elements are being watched
////	if (GameHudColorsManager::isSpriteInstanceOveridden(idSWFSpriteInstance_a1)) {
////		namedColorId_a2 = SWF_NAMED_COLOR_INVALID; //! this will prevent game from overiding our color.
////	}
////
////	//if (GameHudColorsManager::isEquipmentArrowSpriteInstance(idSWFSpriteInstance_a1)) {
////	//	GameHudColorsManager::acquireEquipmentArrowSprintInstanceAddr(idSWFSpriteInstance_a1);
////
////	//	namedColorId_a2 = -1; //? this may prevents the equipment arrow color to be changed if user changes color profile but i'm not sure....
////	//}
////
////
////	//? this works keep thatin mind:
////	/*if (GameHudColorsManager::isEquipmentArrowSpriteInstance(idSWFSpriteInstance_a1)) {
////		logInfo("setSpriteInstanceColorHook idSWFSpriteInstance_a1: %p", (void*)idSWFSpriteInstance_a1);
////		GameHudColorsManager::setEquipmentArrowFlag(true);
////	}
////	else {
////		GameHudColorsManager::setEquipmentArrowFlag(false);
////	}*/
////
////	//GameHudColorsManager::overideEquipmentArrowNamedColor(idSWFSpriteInstance_a1);
////
////
////	//? ids which modify the hud: (if it doesn't look log all the ids again and look the ones above or below the value
////	/*
////		INFO| print: name: left, fullPathHash: -108148670, visIndex: 17, health smth
////
////
////		*/
////
////
////		//? this works !:
////		//int hashId = *(int*)(idSWFSpriteInstance_a1 + 0x20);		
////		////if (hashId == -904400581) { // equipment arrow : no change.....
////		//if (hashId == -1637630621) { // equipment arrow
////		//	namedColorId_a2 = g_namedColorBlue;
////		//	logInfo("setSpriteInstanceColorHook found equipment arrow hash id");
////		//	return psetSpriteInstanceColor(idSWFSpriteInstance_a1, namedColorId_a2);
////
////		//}
////
////		//if (PlayerStateChecker::isPlaying()) {
////		//	//? add the visIndex to the log we never know
////		//	if (!MemHelper::isBadReadPtr((void*)strAddr) && !MemHelper::isBadReadPtr((void*)(idSWFSpriteInstance_a1 + 0x20))) {
////		//		unsigned int hashId = *(unsigned int*)(idSWFSpriteInstance_a1 + 0x20);
////		//		int visIndex = *(int*)(idSWFSpriteInstance_a1 + 0x8);
////		//		logInfo("setSpriteInstanceColorHook name: %s fullPathHash: %u visIndex: %d namedColorId_a2: %u", (const char*)strAddr, hashId, visIndex, namedColorId_a2);
////		//	}
////
////		//}
////
////
////	//namedColorId_a2 = 94;
////
////		/*SWF_NAMED_COLOR_KEYCARD_BLUE = 94,
////			SWF_NAMED_COLOR_KEYCARD_RED = 95,
////			SWF_NAMED_COLOR_KEYCARD_YELLOW = 96,*/
////
////			//! these don't work to change the arrow: 0 to 4
////			//! namedColorId_a2 0 doesnt seem to change the color of the equipment arrow, just the text of some elements like the inside of the dash (?!)
////			//if (true) { // adding only the one with color green light from default profile
////			////if (namedColorId_a2 == 2) { // adding only the one with color green light from default profile
////			//	
////
////			//	if (PlayerStateChecker::isPlaying()) {	
////			//		__int64 strAddr = *(__int64*)(idSWFSpriteInstance_a1 + 0x18);
////			//		if (!MemHelper::isBadReadPtr((void*)strAddr) && !MemHelper::isBadReadPtr((void*)(idSWFSpriteInstance_a1 + 0x20))) {
////			//			 int hashId = *(int*)(idSWFSpriteInstance_a1 + 0x20);
////			//			int visIndex = *(int*)(idSWFSpriteInstance_a1 + 0x8);
////			//			std::string name = (const char*)strAddr;
////
////			//			/*logInfo("setSpriteInstanceColorHook name: %s fullPathHash: %u visIndex: %d namedColorId_a2: %u", (const char*)strAddr, hashId, visIndex, namedColorId_a2);*/
////			//			//logWarn("trigg");
////
////			//			if (!isAlreadyInpathHashesDebugVec(hashId)) {					
////			//				logWarn("adding spriteDebug to vec...");
////			//				spriteDebug sprite = spriteDebug(hashId, visIndex, name);
////			//				//sprite.print();
////			//				spriteDebugVec.push_back(sprite);
////			//				
////			//				//pathHashesDebugVec.push_back(hashId);
////			//			}					
////			//		}
////			//	}
////
////			//	
////			//	 int hashId = *(int*)(idSWFSpriteInstance_a1 + 0x20);
////			//	if (hashDebugIndex < spriteDebugVec.size() && (hashId == spriteDebugVec[hashDebugIndex].fullPathHash)) {
////			//		namedColorId_a2 = g_namedColorDebug;
////
////			//	}
////			//	//if(namedColorId_a2 == )
////
////			//	//namedColorId_a2 = g_namedColorDebug; //SWF_NAMED_COLOR_KEYCARD_RED = 95,
////			//	//namedColorId_a2 = 96; SWF_NAMED_COLOR_KEYCARD_YELLOW = 96
////			//}
////
////	return psetSpriteInstanceColor(idSWFSpriteInstance_a1, namedColorId_a2);
////}
////
////
////
////
////
////
//////! void __fastcall idRenderModelGui::DrawStretchPic_623070(__int64 gui_a1,float* x_a2,__int64 y_a3,__int64 text_a4,float* idColor_a5,__int64 matr_a6,float scale_a7)
//////typedef void(__fastcall* idRenderModelGui_DrawStretchPic_623070)(__int64 gui_a1, float* x_a2, __int64 y_a3, __int64 text_a4, float* idColor_a5, __int64 matr_a6, float scale_a7);
//////idRenderModelGui_DrawStretchPic_623070 pidRenderModelGui_DrawStretchPic_623070 = nullptr;
//////idRenderModelGui_DrawStretchPic_623070 pidRenderModelGui_DrawStretchPic_623070Target;
//////
//////
//////void __fastcall idRenderModelGui_DrawStretchPic_623070Hook(__int64 gui_a1, float* x_a2, __int64 y_a3, __int64 text_a4, float* idColor_a5, __int64 matr_a6, float scale_a7) {
//////
//////	//logInfo("idRenderModelGui_DrawStretchPic_623070Hook: guiptr: %p,  matptr: %p", (void*)gui_a1, (void*)matr_a6);
//////	
//////	return pidRenderModelGui_DrawStretchPic_623070(gui_a1, x_a2, y_a3, text_a4, idColor_a5, matr_a6, scale_a7);
//////}
////
//////! char __fastcall GetPerfMetricsStr_Smth_48FE40(__int64 idConsoleLocal_a1, __int64 x_a2, float *y_a3)
//////typedef char (__fastcall* GetPerfMetricsStr)(__int64 idConsoleLocal_a1, __int64 x_a2, float* y_a3)
////
////
//////? don't need to hook drawchar as it's not called
//////! void __fastcall idRenderModelGui::DrawCharMb_622730(__int64 gui_a1, float x_a2, float y_a3, unsigned int text_a4, float idColor_a5)
//////typedef void(__fastcall* idRenderModelGui_DrawChar(__int64 gui_a1, float x_a2, float y_a3, unsigned int text_a4, float idColor_a5);
////
//////? this doesn't fucking work cause hooking func with variadic arg is almost impossible:
//////! trying to hook this cause rendering from GetPerfMetricsStr_Smth_48FE40 still has perf issues
//////! __int64 showPerfMetricsStrLine_4930A0(__int64 idConsoleLocal_a1, float *x_a2, int y_a3, float text_a4, __int64 idColor_a5, int a6, ...)
//////typedef __int64 (__fastcall* showPerfMetricsStrLine)(__int64 idConsoleLocal_a1, float* x_a2, int y_a3, float text_a4, __int64 idColor_a5, int a6, ...);
//////showPerfMetricsStrLine pshowPerfMetricsStrLine = nullptr;
//////showPerfMetricsStrLine pshowPerfMetricsStrLineTarger;
//////
//////__int64 showPerfMetricsStrLineHook(__int64 idConsoleLocal_a1, float* x_a2, int y_a3, float text_a4, __int64 idColor_a5, int a6, ...) {
//////
//////	//consoleLocal.testDraw();
//////
//////	va_list args;
//////	va_start(args, a6);
//////	
//////	va_end(args);
//////
//////	__int64 result = pshowPerfMetricsStrLine(idConsoleLocal_a1, x_a2, y_a3, text_a4, idColor_a5, a6, args);
//////
//////	return result;
//////}
////
//////! not useful and not triggered afaik
//////void __fastcall keySerializeEndHook(signed int gui_a1, unsigned int x_a2) {
//////	
//////	//spdlog::info("keySerializeEndHook called BUT WE NEED TO DO SOMETHING WITH IT....: gui_a1: {} x_a2: {}", gui_a1, x_a2 );
//////	return pkeySerializeEnd(gui_a1, x_a2);
//////}
////
////
//////! not useful atm
//////void** __fastcall inMenuDetectionHook(_int64 gui_a1) {
//////	spdlog::info("inMenuDetectionHook called...");
//////	return pinMenuDetection(gui_a1);
//////}
////
//////! not useful atm
//////char __fastcall inGameDetectionHook(__int64* gui_a1, __int64 x_a2) {
//////	spdlog::info("inGameDetectionHook called...");
//////	return pinGameDetection(gui_a1, x_a2);
//////}
////
////
