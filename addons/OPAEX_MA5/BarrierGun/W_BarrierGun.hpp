class OPAEX_D20_W_BarrierGun: OPTRE_MA5B {
	displayName = "MA5B ICWS Barrier Rifle";
	descriptionShort = "UNSC Barrier Rifle";
	magazines[] = {
		"OPAEX_D20_M_BarrierGun"
	};
	class EventHandlers
	{
		class BarrierFired
		{
			fired = "(_this select 6) call OPAEX_fnc_BarrierGun";
		};
	};
};

