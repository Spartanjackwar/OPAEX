//Jack Moss, aka Spartanjackwar

//NOTE: Sparrowhawk selections are hiding, not activating.  So defining a noselaser hides the noselaser.
class CfgPatches
{
 	class OPAEX_Sparrowhawk
 	{
		addonRootClass = "OPAEX";
		author = "Spartanjackwar";
		requiredAddons[] = {
			"A3_Air_F","A3_Air_F_Beta", "A3_Weapons_F", "A3_Data_F",
			"OPTRE_Core", "OPTRE_Vehicles", "OPTRE_Vehicles_Pelican", //Mikero's claims it's in the pelican patch
			"OPAEX_Core", "OPAEX_AirCore",
			"Extended_EventHandlers" //requiring CBA for G indicator script
		};
 		units[] = {
			/*
			"OPTRE_AV22_Sparrowhawk_Base",
			"OPTRE_AV22_Sparrowhawk",
			"OPTRE_AV22A_Sparrowhawk",
			"OPTRE_AV22B_Sparrowhawk",
			"OPTRE_AV22C_Sparrowhawk"
			*/
			"OPAEX_AV22_Sparrowhawk_VTOL_Base",
			"OPAEX_AV22_Sparrowhawk_VTOL",
			"OPAEX_AV22A_Sparrowhawk_VTOL",
			"OPAEX_AV22B_Sparrowhawk_VTOL",
			"OPAEX_AV22C_Sparrowhawk_VTOL"
		};
 		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
 		requiredVersion = 0.1;
 	};
};

//==============================================================================================
//ROOT EXTERNALS
//These are found in the root of the config and thus declared here.
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
//==============================================================================================

class cfgVehicles
{
	//==============================================================================================
	//EXTERNALS
	class All {};
    class Static : All {};
    class Helicopter;
    class Helicopter_Base_F : Helicopter
    {
        class Turrets;
        class HitPoints;
        class ViewPilot;
        class CargoTurret;
        class Reflectors
        {
            class Right;
        };
    };
    class Helicopter_Base_H : Helicopter_Base_F
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class CopilotTurret;
        };
        class HitPoints : HitPoints
        {
            class HitHull;
            class HitFuel;
            class HitEngine;
            class HitAvionics;
            class HitVRotor;
            class HitHRotor;
            class HitGlass1;
            class HitGlass2;
            class HitGlass3;
            class HitGlass4;
            class HitGlass5;
            class HitGlass6;
        };
        class Components;
        class AnimationSources;
        class ViewOptics;
        class RotorLibHelicopterProperties;
    };
	class OPTRE_AV22_Sparrowhawk_Base: Helicopter_Base_H {
		class Turrets: Turrets {
			class CopilotTurret;
		};
	};
	
	//==============================================================================================
	//INTERNALS
	/* No longer needed due to OPTRE integration
	class OPTRE_AV22_Sparrowhawk_Base: Helicopter_Base_H
	{
		#include<AV22_Sparrowhawk_Base.hpp>
		#include<AV22_Texture.hpp>
		
		defaultUserMFDvalues[] = {0.082, 0.408, 0.039, 1}; //F/A-181X
		class MFD
		{
			#include<AV22_MFD.hpp>
		};
	};
	class OPTRE_AV22_Sparrowhawk: OPTRE_AV22_Sparrowhawk_Base
	{//50mm nose, 20mm side
		displayName = "AV-22 Sparrowhawk";
		author = "Article 2 Studios";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		side = 1;
		vehicleClass = "OPTRE_UNSC_Air_class";
		faction = "OPTRE_UNSC";
		crew = "OPTRE_UNSC_Airforce_Soldier_Airman";
		hiddenSelections[] = {
			"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7",
			"attach_noseLaser",
			"attach_CannonHeavy",
			"attach_Pylons",
			"attach_Decal1", "attach_Decal2"
		};
		hiddenSelectionsTextures[] = {
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_01_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_02_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_03_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_04_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_05_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\autocannon_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\feed_autocannon_co.paa"
		};
		weapons[] = {
			"OPTRE_GUA23B", 
			"CMFlareLauncher"
		};
		magazines[] = {
			"OPTRE_2000Rnd_20mm_HEIAP", "OPTRE_2000Rnd_20mm_HEIAP", 
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		textureList[] = {"colorgreen", 1, "colorRed", 1};
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[] = {
					"OPTRE_M230",
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"OPTRE_100Rnd_50mm_HE", "OPTRE_100Rnd_50mm_HE", "OPTRE_100Rnd_50mm_HE",
					"OPTRE_100Rnd_50mm_APFSDS",
					"Laserbatteries"
				};
			};
		};
		
		defaultUserMFDvalues[] = {0.082, 0.408, 0.039, 1}; //F/A-181X
		class MFD
		{
			#include<AV22_MFD.hpp>
		};
	};
	class OPTRE_AV22A_Sparrowhawk: OPTRE_AV22_Sparrowhawk
	{//AV-22A, SpLaser nose, 50mm side.
		displayName = "AV-22A Sparrowhawk";
		author = "Article 2 Studios";
		hiddenSelections[] = {
			"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7",
			//"attach_Pylons",
			"attach_Decal1", "attach_Decal2",
			
			//Gunner-controlled Nose-mounted weapons
			//"attach_noseLaser",  //Laser
			"attach_noseCannon", //50mm
			
			//Pilot-controlled Side-mounted weapons
			"attach_CannonLight", //20mm
			//"attach_CannonHeavy", //50mm
		};
		hiddenSelectionsTextures[] = {
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_01_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_02_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_03_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_04_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_05_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\autocannon_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\feed_autocannon_co.paa"
		};
		weapons[] = {
			"OPTRE_M9109",
			"CMFlareLauncher"
		};
		magazines[] = {
			"OPTRE_2500Rnd_50mm_HE",
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[] = {
					"OPTRE_M6_Laser", 
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery",
					"Laserbatteries"
				};
			};
		};
	};
	class OPTRE_AV22B_Sparrowhawk: OPTRE_AV22_Sparrowhawk
	{//AV-22B, SpLaser nose, 20mm side
		displayName = "AV-22B Sparrowhawk";
		author = "Article 2 Studios";
		hiddenSelections[] = {
			"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7",
			//"attach_Pylons",
			"attach_Decal1", "attach_Decal2",
			
			//Gunner-controlled Nose-mounted weapons
			//"attach_noseLaser",  //Laser
			"attach_noseCannon", //50mm
			
			//Pilot-controlled Side-mounted weapons
			//"attach_CannonLight", //20mm
			"attach_CannonHeavy", //50mm
		};
		hiddenSelectionsTextures[] = {
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_01_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_02_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_03_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_04_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_05_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\autocannon_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\feed_autocannon_co.paa"
		};
		weapons[] = {
			"OPTRE_GUA23B",
			"CMFlareLauncher"
		};
		magazines[] = {
			"OPTRE_2000Rnd_20mm_HEIAP", "OPTRE_2000Rnd_20mm_HEIAP",
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[] = {
					"OPTRE_M6_Laser",
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery",
					"Laserbatteries"
				};
			};
		};
	};
	class OPTRE_AV22C_Sparrowhawk: OPTRE_AV22_Sparrowhawk
	{//AV-22C, 50mm nose, 50mm side
		displayName = "AV-22C Sparrowhawk";
		author = "Article 2 Studios";
		hiddenSelections[] = {
			"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7",
			//"attach_Pylons",
			"attach_Decal1", "attach_Decal2",
			
			//Gunner-controlled Nose-mounted weapons
			"attach_noseLaser",  //Laser
			//"attach_noseCannon", //50mm
			
			//Pilot-controlled Side-mounted weapons
			"attach_CannonLight", //20mm
			//"attach_CannonHeavy", //50mm
		};
		hiddenSelectionsTextures[] = {
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_01_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_02_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_03_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_04_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_05_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\autocannon_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\feed_autocannon_co.paa"
		};
		weapons[] = {
			"OPTRE_M9109",
			"CMFlareLauncher"
		};
		magazines[] = {
			"OPTRE_2500Rnd_50mm_HE",
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[] = {
					"OPTRE_M230", 
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"OPTRE_100Rnd_50mm_HE", "OPTRE_100Rnd_50mm_HE", "OPTRE_100Rnd_50mm_HE",
					"OPTRE_100Rnd_50mm_APFSDS",
					"Laserbatteries"
				};
			};
		};
	};
	*/
	
	#include<AV22_Sparrowhawk_VTOL_Base.hpp>
	class OPAEX_AV22_Sparrowhawk_VTOL: OPAEX_AV22_Sparrowhawk_VTOL_Base
	{//50mm nose, 20mm side
		displayName = "AV-22 Sparrowhawk [VTOL]";
		author = "Spartanjackwar";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		side = 1;
		vehicleClass = "OPTRE_UNSC_Air_class";
		faction = "OPTRE_UNSC";
		crew = "OPTRE_UNSC_Airforce_Soldier_Airman";
		hiddenSelections[] = {
			"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7",
			"attach_noseLaser",
			"attach_CannonHeavy",
			"attach_Pylons",
			"attach_Decal1", "attach_Decal2"
		};
		/*
		hiddenSelectionsTextures[] = {
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_01_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_02_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_03_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_04_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_05_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\autocannon_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\feed_autocannon_co.paa"
		};
		*/
		weapons[] = {
			"OPTRE_GUA23B", 
			"CMFlareLauncher"
		};
		magazines[] = {
			"OPTRE_2000Rnd_20mm_HEIAP", "OPTRE_2000Rnd_20mm_HEIAP", 
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		textureList[] = {"colorgreen", 1, "colorRed", 1};
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[] = {
					"OPTRE_M230",
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"OPTRE_100Rnd_50mm_HE", "OPTRE_100Rnd_50mm_HE", "OPTRE_100Rnd_50mm_HE",
					"OPTRE_100Rnd_50mm_APFSDS",
					"Laserbatteries"
				};
			};
		};
		
		defaultUserMFDvalues[] = {0.082, 0.408, 0.039, 1}; //F/A-181X
		class MFD
		{
			#include<AV22_MFD_VTOL.hpp>
		};
	};
	class OPAEX_AV22A_Sparrowhawk_VTOL: OPAEX_AV22_Sparrowhawk_VTOL
	{//AV-22A, SpLaser nose, 50mm side.
		displayName = "AV-22A Sparrowhawk [VTOL]";
		author = "Spartanjackwar";
		hiddenSelections[] = {
			"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7",
			//"attach_Pylons",
			"attach_Decal1", "attach_Decal2",
			
			//Gunner-controlled Nose-mounted weapons
			//"attach_noseLaser",  //Laser
			"attach_noseCannon", //50mm
			
			//Pilot-controlled Side-mounted weapons
			"attach_CannonLight", //20mm
			//"attach_CannonHeavy", //50mm
		};
		/*
		hiddenSelectionsTextures[] = {
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_01_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_02_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_03_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_04_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_05_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\autocannon_co.paa",
			"OPTRE_Vehicles_Air\Sparrowhawk\data\feed_autocannon_co.paa"
		};
		*/
		weapons[] = {
			"OPTRE_M9109",
			"CMFlareLauncher"
		};
		magazines[] = {
			"OPTRE_2500Rnd_50mm_HE",
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[] = {
					"OPTRE_M6_Laser", 
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery",
					"Laserbatteries"
				};
			};
		};
	};
	class OPAEX_AV22B_Sparrowhawk_VTOL: OPAEX_AV22_Sparrowhawk_VTOL
	{//AV-22B, SpLaser nose, 20mm side
		displayName = "AV-22B Sparrowhawk [VTOL]";
		author = "Spartanjackwar";
		hiddenSelections[] = {
			"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7",
			//"attach_Pylons",
			"attach_Decal1", "attach_Decal2",
			
			//Gunner-controlled Nose-mounted weapons
			//"attach_noseLaser",  //Laser
			"attach_noseCannon", //50mm
			
			//Pilot-controlled Side-mounted weapons
			//"attach_CannonLight", //20mm
			"attach_CannonHeavy", //50mm
		};
		/*
		hiddenSelectionsTextures[] = {
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_01_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_02_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_03_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_04_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_05_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\autocannon_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\feed_autocannon_co.paa"
		};
		*/
		weapons[] = {
			"OPTRE_GUA23B",
			"CMFlareLauncher"
		};
		magazines[] = {
			"OPTRE_2000Rnd_20mm_HEIAP", "OPTRE_2000Rnd_20mm_HEIAP",
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[] = {
					"OPTRE_M6_Laser",
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery", "OPTRE_SpLaser_Battery",
					"Laserbatteries"
				};
			};
		};
	};
	class OPAEX_AV22C_Sparrowhawk_VTOL: OPAEX_AV22_Sparrowhawk_VTOL
	{//AV-22C, 50mm nose, 50mm side
		displayName = "AV-22C Sparrowhawk [VTOL]";
		author = "Spartanjackwar";
		hiddenSelections[] = {
			"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7",
			//"attach_Pylons",
			"attach_Decal1", "attach_Decal2",
			
			//Gunner-controlled Nose-mounted weapons
			"attach_noseLaser",  //Laser
			//"attach_noseCannon", //50mm
			
			//Pilot-controlled Side-mounted weapons
			"attach_CannonLight", //20mm
			//"attach_CannonHeavy", //50mm
		};
		/*
		hiddenSelectionsTextures[] = {
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_01_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_02_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_03_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_04_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\body_05_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\autocannon_co.paa", 
			"OPTRE_Vehicles_Air\Sparrowhawk\data\feed_autocannon_co.paa"
		};
		*/
		weapons[] = {
			"OPTRE_M9109",
			"CMFlareLauncher"
		};
		magazines[] = {
			"OPTRE_2500Rnd_50mm_HE",
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[] = {
					"OPTRE_M230", 
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"OPTRE_100Rnd_50mm_HE", "OPTRE_100Rnd_50mm_HE", "OPTRE_100Rnd_50mm_HE",
					"OPTRE_100Rnd_50mm_APFSDS",
					"Laserbatteries"
				};
			};
		};
	};
};