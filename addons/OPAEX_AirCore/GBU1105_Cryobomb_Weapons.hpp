class OPAEX_W_GBU1105: OPTRE_bomblauncher_GBU
{
	displayName = "GBU-1105 Laser Guided Bomb";
	descriptionShort = "Laser-Guided Bomb";
	ballisticsComputer = 8;
	magazines[] = {"OPAEX_M_GBU1105_1Rnd"};
	class EventHandlers
	{
		class OPAEX
		{ //Note that the 6th entry of the array pased by fired is the projectile.
			fired = "[(_this select 6), 150, 30] spawn OPAEX_fnc_CryoBomb_WeaponMethod";
		};
	};
};