class CfgPatches
{
 	class OPAEX_MA5
 	{
		author = "Spartanjackwar";
 		requiredAddons[] = {
			"OPAEX_Core",
			"OPTRE_Core"
		};
 		units[] = {};
 		weapons[] = {};
		magazines[] = {"OPAEX_M_145x114_APFSDS_12Rnd"};
		ammo[] = {};
 		requiredVersion = 0.1;
 	};
};

class cfgWeapons {
	#include"FusionCoilGun\W_FusionCoilGun.hpp"
	#include"BarrierGun\W_BarrierGun.hpp"
};

class cfgMagazines {
	class OPTRE_4Rnd_145x114_APFSDS_Mag;
	
	class OPAEX_M_145x114_APFSDS_12Rnd: OPTRE_4Rnd_145x114_APFSDS_Mag {
		displayname = "12Rnd 14.5x114mm APFSDS Magazine (C)";
		displaynameshort = "APFSDS";
		descriptionshort = "4 Round Magazine<br/>14.5x114mm<br/>Armor Piercing Fin-Stabilized Disposable Shell";
		count = 12;
	};
	#include"FusionCoilGun\M_FusionCoilGun.hpp"
	#include"BarrierGun\M_BarrierGun.hpp"
};

class cfgMagazineWells {
	class 3UGL_40x36 {
		OPAEX_SRS[] = {
			"OPAEX_M_145x114_APFSDS_12Rnd"
		};
	};
	class CBA_40mm_3GL {
		OPAEX_SRS[] = {
			"OPAEX_M_145x114_APFSDS_12Rnd"
		};
	};
	class CBA_40mm_EGLM {
		OPAEX_SRS[] = {
			"OPAEX_M_145x114_APFSDS_12Rnd"
		};
	};
	class UGL_40x36 {
		OPAEX_SRS[] = {
			"OPAEX_M_145x114_APFSDS_12Rnd"
		};
	};
	class CBA_40mm_M203 {
		OPAEX_SRS[] = {
			"OPAEX_M_145x114_APFSDS_12Rnd"
		};
	};
};

class cfgAmmo {
	#include"FusionCoilGun\A_FusionCoilGun.hpp"
	#include"BarrierGun\A_BarrierGun.hpp"
};