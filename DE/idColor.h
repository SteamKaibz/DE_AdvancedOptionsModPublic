#pragma once


struct idColor {
	float r, g, b, a;
	int PackColor() const
	{
		int v1; // edx
		unsigned __int8 v2; // al
		int v3; // er9
		int v4; // edx
		unsigned __int8 v5; // al
		int v6; // er8
		int v7; // edx
		unsigned __int8 v8; // al
		int v9; // edx
		int v10; // ecx
		unsigned __int8 v11; // al

		v1 = (int)(float)(this->r * 255.0);
		if (v1 >= 0)
		{
			v2 = (int)(float)(this->r * 255.0);
			if (v1 > 255)
				v2 = -1;
		}
		else
		{
			v2 = 0;
		}
		v3 = v2;
		v4 = (int)(float)(this->g * 255.0);
		if (v4 >= 0)
		{
			v5 = (int)(float)(this->g * 255.0);
			if (v4 > 255)
				v5 = -1;
		}
		else
		{
			v5 = 0;
		}
		v6 = v5;
		v7 = (int)(float)(this->b * 255.0);
		if (v7 >= 0)
		{
			v8 = (int)(float)(this->b * 255.0);
			if (v7 > 255)
				v8 = -1;
		}
		else
		{
			v8 = 0;
		}
		v9 = v8;
		v10 = (int)(float)(this->a * 255.0);
		if (v10 >= 0)
		{
			v11 = v10;
			if (v10 > 255)
				v11 = -1;
		}
		else
		{
			v11 = 0;
		}
		return v3 | ((v6 | ((v9 | (v11 << 8)) << 8)) << 8);
	}

	/*void set(float _r, float _g, float _b, float _a) {
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}*/
};


//! custom colors test:
//static idColor colorCustom1 = idColor{ 1.00f, 1.00f, 0.00f, 1.00f };
//static idColor colorCustom2 = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };



static idColor colorOverrideBloodPunch1 = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static idColor colorOverrideBloodPunch2 = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static idColor colorFuel3Pip = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static idColor colorFragGrenadeAvailable = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static idColor colorFragGrenadeCoolDown = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static idColor colorIceGrenadeAvailable = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static idColor colorIceGrenadeCoolDown = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static idColor colorWeaponBar = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static idColor colorRadMeterColor = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };



//! use colors for ini file:

static constexpr idColor 	colorRed = idColor{ 1.00f, 0.00f, 0.00f, 1.00f };
static constexpr idColor 	colorGreen = idColor{ 0.00f, 1.00f, 0.00f, 1.00f };
//static constexpr idColor 	colorBlue = idColor{ 0.53f, 0.70f, 1.00f, 1.00f };
//static constexpr idColor 	colorBlue = idColor{ 0.0f, 0.80f, 1.00f, 1.00f };
static constexpr idColor 	colorBlue = idColor{ 0.53f, 0.81f, 0.98f, 1.00f }; // colorSkyBlue
static constexpr idColor 	colorBlueLowAlpaha = idColor{ 0.53f, 0.81f, 0.98f, .3f }; // colorSkyBlue
static constexpr idColor 	colorBlueLowAlpha2 = idColor{ 0.53f, 0.81f, 0.98f, .1f }; // colorSkyBlue
static constexpr idColor 	colorBlueExtraBorderTrans = idColor{ 0.53f, 0.81f, 0.98f, .9f }; // colorSkyBlue
//static constexpr idColor 	colorBlue = idColor{ 0.00f, 0.00f, 1.00f, 1.00f };
static constexpr idColor 	colorYellow = idColor{ 1.00f, 1.00f, 0.00f, 1.00f };
static constexpr idColor 	colorMagenta = idColor{ 1.00f, 0.00f, 1.00f, 1.00f };
static constexpr idColor 	colorCyan = idColor{ 0.00f, 1.00f, 1.00f, 1.00f };
static constexpr idColor 	colorOrange = idColor{ 1.00f, 0.50f, 0.00f, 1.00f };
static constexpr idColor 	colorPurple = idColor{ 1.00f, 0.0f, 0.72f, 1.00f }; // colorBrightFuchsia
//static constexpr idColor 	colorPurple = idColor{ 0.60f, 0.00f, 0.60f, 1.00f };
static constexpr idColor 	colorPink = idColor{ 0.73f, 0.40f, 0.48f, 1.00f };
static constexpr idColor 	colorBrown = idColor{ 0.40f, 0.35f, 0.08f, 1.00f };
static constexpr idColor 	colorWhite = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static constexpr idColor 	colorLtGrey = idColor{ 0.75f, 0.75f, 0.75f, 1.00f };
static constexpr idColor 	colorMdGrey = idColor{ 0.50f, 0.50f, 0.50f, 1.00f };
static constexpr idColor 	colorMdGreyTrans = idColor{ 0.50f, 0.50f, 0.50f, .5f };
static constexpr idColor 	colorDkGrey = idColor{ 0.25f, 0.25f, 0.25f, 1.00f };
static constexpr idColor 	colorVeryDkGrey = idColor{ 0.1f, 0.1f, 0.1f, 1.00f };
static constexpr idColor 	colorBlack = idColor{ 0.00f, 0.00f, 0.00f, 1.00f };

// Variations
static constexpr idColor colorLightBlue = { 0.11f, 0.43f, .99f, 1.00f }; // Light Blue
//static constexpr idColor colorLightBlue = { 0.70f, 0.85f, 1.00f, 1.00f }; // Light Blue
static constexpr idColor colorDarkBlue = { 0.00f, 0.00f, 0.25f, 1.00f }; // Darker Blue
static constexpr idColor colorLightGreen = { 0.50f, 1.00f, 0.50f, 1.00f }; // ligth Green
static constexpr idColor colorDarkGreen = { 0.00f, 0.74f, 0.215f, 1.00f }; // Darker Green
//static constexpr idColor colorDarkGreen = { 0.00f, 0.50f, 0.00f, 1.00f }; // Darker Green
static constexpr idColor colorLightRed = { 1.00f, 0.50f, 0.50f, 1.00f }; // Lighter Red
static constexpr idColor colorLightYellow = { 1.00f, 1.00f, 0.50f, 1.00f }; // Lighter Yellow
static constexpr idColor colorDarkPurple = { 0.30f, 0.00f, 0.30f, 1.00f }; // Darker Purple
static constexpr idColor colorLightPink = { 1.00f, 0.70f, 0.78f, 1.00f }; // Lighter Pink
static constexpr idColor colorDarkBrown = { 0.20f, 0.17f, 0.04f, 1.00f }; // DarkBrown

static constexpr idColor 	colorInvisible = idColor{ 1.00000f, 1.00000f, 1.00000f, 0.00f };


//! custom ice nade icon colors

static idColor iceNadeIcon_IconColor = idColor{ 1.00000f, 1.00000f, 1.00000f, 1.00f };
static idColor iceNadeIcon_BackgroundColor = idColor{ 1.00000f, 1.00000f, 1.00000f, 1.00f };
static idColor iceNadeIcon_OutlineColor = idColor{ 1.00000f, 1.00000f, 1.00000f, 1.00f };
static idColor iceNadeIcon_ExtraBorderColor = idColor{ 1.00000f, 1.00000f, 1.00000f, 1.00f };

static constexpr idColor 	colorTransparentWhite = idColor{ 1.00000f, 1.00000f, 1.00000f, 0.1f };
static constexpr idColor 	colorEmpty = idColor{ 0.25f, 0.25f, 0.25f, 1.00f };

static constexpr idColor 	colorFullArmor = idColor{ 0.00f, 1.00f, 0.00f, 1.00f };
static constexpr idColor 	colorBelowFullArmor = idColor{ 0.00000f, 0.40000f, 0.00000f, 1.00f };

static constexpr idColor 	colorFullHealth = idColor{ 0.00000f, 0.80000f, 1.00000f, 1.00f };
static constexpr idColor 	colorBelowFullHealth = idColor{ 0.00f, 0.00f, 1.00f, 1.00f };
static constexpr idColor 	color75PercHealth = idColor{ 1.00000f, 1.00000f, 0.00000f, 1.00f };
static constexpr idColor 	color50PercHealth = idColor{ 1.00000f, 0.60000f, 0.00000f, 1.00f };
static constexpr idColor 	color25PercHealth = idColor{ 1.00000f, 0.00000f, 0.00000f, 1.00f };

static constexpr idColor 	colorIceNadeAvailable = idColor{ 0.00000f, 0.80000f, 1.00000f, 1.00f };

static constexpr idColor 	color2FragNadeAvailable = idColor{ 0.00f, 1.00f, 0.00f, 1.00f };
static constexpr idColor 	color1FragNadeAvailable = idColor{ 0.00000f, 0.40000f, 0.00000f, 1.00f };

static constexpr idColor 	color2BloodPunchAvailable = idColor{ 1.00000f, 1.00000f, 0.00000f, 1.00f };
static constexpr idColor 	color1BloodPunchAvailable = idColor{ 0.80000f, 0.80000f, 0.00000f, 1.00f };

static constexpr idColor 	colorFlameBelchAvailable = idColor{ 1.00000f, 1.00000f, 0.00000f, 1.00f };

//? let's not use fuel indicator on the crosshair as it will be on the ammo pool UI indicator
static constexpr idColor 	color3FluelAmmoAvailable = idColor{ 1.00000f, 0.00000f, 0.00000f, 1.00f };
static constexpr idColor 	color2FluelAmmoAvailable = idColor{ 1.00000f, 0.60000f, 0.00000f, 1.00f };
static constexpr idColor 	color1FluelAmmoAvailable = idColor{ 1.00000f, 1.00000f, 0.00000f, 1.00f };


//! non constant cause pulse colors
static  idColor 	colorFragPulse = idColor{ 0.00000f, 1.00000f, 0.00000f, 0.00f };
static  idColor 	colorIcePulse = idColor{ 1.00000f, 1.00000f, 1.00000f, 0.00f };


//! non constant cause it's need to prevent constructor error with crosshair:
static  idColor colorWhiteAlt = idColor{ 1.00f, 1.00f, 1.00f, 1.00f };
static  idColor colorOrangeNonConstTest = idColor{ 1.00f, 0.50f, 0.00f, 1.00f };


//! Hud Colors:
//static constexpr idColor colorIconDeactivated = idColor{ 0.4f, 0.4f, 0.4f, 1.00f };
//static constexpr idColor colorFragIconDeactivated = idColor{ 0.00000, 0.20000, 0.00000, 1.00f };
static constexpr idColor colorIceNadeDeactivatedBg = idColor{ 0.15686f, 0.20392f, 0.24314f, 1.00f };
static constexpr idColor colorIceNadeDeactivatedIcon = idColor{ 0.31373f, 0.40392f, 0.48627f, 1.00f };
static constexpr idColor colorIceNadeCoolDownText = idColor{ 0.70196f, 0.81961f, 1.00000f, 1.00f };

static constexpr idColor colorHudAmmoBgBlackTansparent = idColor{ 0.00000f, 0.00000f, 0.00000f, 0.7f }; //! attempt to make text pop up more
//static constexpr idColor colorHudAmmoBgBlackTansparent = idColor{ 0.00000f, 0.00000f, 0.00000f, 0.4f }; //! attempt to make text pop up more
