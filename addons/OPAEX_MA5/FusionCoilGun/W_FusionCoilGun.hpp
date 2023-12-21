class OPTRE_MA5B;
class OPAEX_D20_W_FusionCoilGun: OPTRE_MA5B {
	displayName = "MA5B ICWS Fusion Coil Rifle";
	descriptionShort = "UNSC Fusion Coil Rifle";
	magazines[] = {
		"OPAEX_D20_M_FusionCoilGun"
	};
	class EventHandlers
	{
		class BarrierFired
		{
			fired = "(_this select 6) call OPAEX_fnc_FusionCoilGun";
		};
	};
};

