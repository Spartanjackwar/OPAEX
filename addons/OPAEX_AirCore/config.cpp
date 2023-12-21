//Jack Moss, aka Spartanjackwar
//This config is used to package all air weapons used by the various air vehicles of OPAEX.

class CfgPatches
{
 	class OPAEX_AirCore
 	{
		addonRootClass = "OPAEX";
		author = "Spartanjackwar";
		requiredAddons[] = {
			"A3_Weapons_F", "OPAEX_Core", "OPTRE_Core",
			"Extended_EventHandlers" //requiring CBA now!
		};
 		units[] = {};
 		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
 		requiredVersion = 0.1;
 	};
};

//Note: weapon 		classnames follow this form: OPAEX_W_classname
//Note: magazine 	classnames follow this form: OPAEX_M_classname
//Note: ammunition  classnames follow this form: OPAEX_A_classname

//ROOT EXTERNALS
class SensorTemplateIR;
class Mode_SemiAuto;

//INTERNALS
class cfgWeapons
{
	//EXTERNALS
	class OPTRE_missiles_C2GMLS;
	class OPTRE_missiles_Jackknife;
	class OPTRE_missiles_Anvil1;
	class OPTRE_missiles_Anvil2;
	class OPTRE_missiles_Anvil3;
	class OPTRE_bomblauncher_GBU;
	
	//INTERNALS
	#include<GBU1105_Cryobomb_Weapons.hpp>
	#include<Mk127_Illumination_Weapons.hpp>
};

class cfgMagazines
{
	//EXTERNALS
	class OPTRE_12Rnd_C2GMLS_missiles;
	class OPTRE_2Rnd_Jackknife_missile;
	class OPTRE_16Rnd_Anvil1_missiles;
	class OPTRE_12Rnd_Anvil2_missiles;
	class OPTRE_12Rnd_Anvil3_missiles;
	class OPTRE_4Rnd_GBU_bomb;
	
	//INTERNALS
	#include<GBU1105_Cryobomb_Magazines.hpp>
	#include<Mk127_Illumination_Magazines.hpp>
};

class cfgAmmo
{
	//EXTERNALS
	class OPTRE_M_ANVIL_1_Rocket;
	class M_AT;
	class OPTRE_M_ANVIL_2_IR: M_AT
	{
		class Components;
	};
	class OPTRE_M_ANVIL_3_LGM;
	class OPTRE_Bo_500lb;
	class OPTRE_Bo_1000lb;
	class OPTRE_Bo_2000lb;
	class OPTRE_Bo_GBU1071_LGB;
	class OPTRE_M_ASGM2_AA;
	
	//INTERNALS
	#include<GBU1105_Cryobomb_Ammo.hpp>
	#include<Mk127_Illumination_Ammo.hpp>
};
