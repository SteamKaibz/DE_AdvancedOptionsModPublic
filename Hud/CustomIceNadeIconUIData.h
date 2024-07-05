#pragma once


#include <string>
#include "../DE/idLib.h"
#include "../DE/idColor.h"
#include "../DE/idPlayer.h"
#include "../DE/MaterialLib.h"
#include "../DE/GameHudColorsManager.h"


class CustomIceNadeIconUIData
{
public:
	const float m_starIconScale = .27f; // was .27 the lower the val the bigger the icon
	const float m_abilityAvailableStarIconWhiteBlend = .40f; // was .45
	const float m_abilityDisabledStarIconAlpha = .35f; // more than 35 seems too much
	const float m_iceNadeIconOffsetMul = .68f; // was .675f
	const float m_ExtraBorderAlpha = .1f;
	const float m_BorderAlpha = 1.0f;
	const float m_BackgroundAlpha = .3f;


	bool isRenderingAllowed;
	bool isIceOnCoolDown;
	swfRect_t outerIconBounds; //! rect containing the whole icenade icon
	swfRect_t innerIconBounds; //! rect containing only the actuall star like icon which needs to be scaled down to fit
	idColor extraBorderColor;
	idColor borderColor;
	idColor backgroundColor;
	idColor iconColor; //! the actual star like icon color
	__int64 extraBorderMrt;
	__int64 borderMrt;
	__int64 backgroundMrt;
	__int64 iconMrt;
	std::string cooldownText = "??";


	bool isIceNadeOnCoolDown();

	void updateIsRenderingAllowed(bool isAllowed);

	void updateIsIceNadeCooldownStatus();

	void updateMaterials();

	void updateCoords();

	void updateColors();

	void updateCooldownTimeLeftStr();
};