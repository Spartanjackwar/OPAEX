class OPAEX_W_Mk127: OPTRE_bomblauncher_GBU
{
	displayName = "Mk127 Illumination Bomb";
	descriptionShort = "Nonguided Illumination Flare";
	ballisticsComputer = 8;
	magazines[] = {"OPAEX_M_Mk127_1Rnd"};
	class EventHandlers
	{
		class OPEAX
		{ //Note that the 6th entry of the array pased by fired is the projectile.
			fired = "[(_this select 6), Nil, Nil, Nil] spawn OPAEX_fnc_Mk127";
		};
	};
	canLock = 0;
};