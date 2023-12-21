class CfgPatches
{
	class OPAEX_Warthog
	{
		author = "Spartanjackwar";
 		requiredAddons[] = {"OPAEX_Core", "OPTRE_Core", "OPTRE_Vehicles"};
 		units[] = {
			"OPAEX_M12G1S_LRV"
		};
 		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
 		requiredVersion = 0.1;
	};
};

class cfgWeapons
{
	class OPTRE_M68_GAUSS;
	class OPAEX_W_2Gauge: OPTRE_M68_GAUSS
	{
		dlc = "OPAEX";
		displayname = "2-Gauge Shotgun";
		displaynameshort = "2-Gauge Shotgun";
		
		magazines[] = {"OPAEX_M_2Gauge_Pellets_2rnd"};
		magazineWells[] = {"OPAEX_W_2Gauge"}; //Note, vehicles don't support this.
	};
};

class cfgMagazineWells
{
	class OPAEX_W_2Gauge
	{
		OPAEX_M_2Gauge[] = {"OPAEX_M_2Gauge_Pellets_2rnd"};
	};
};

class cfgMagazines
{
	class OPTRE_6Rnd_8Gauge_Pellets;
	class OPAEX_M_2Gauge_Pellets_2rnd: OPTRE_6Rnd_8Gauge_Pellets
	{
		dlc = "OPAEX";
		displayname = "2rnd 2-Gauge Pellets";
		displaynameshort = "2-Gauge Pellets";
		descriptionshort = "2 Rounds of 2-Gauge Pellets";
		ammo = "OPAEX_A_2Gauge_Pellets";
		count = 2;
		initspeed = 500;
		mass = 227;
	};
};

class cfgAmmo
{
	class OPTRE_8Gauge_Pellets;
	class OPAEX_A_2Gauge_Pellets: OPTRE_8Gauge_Pellets
	{
		hit = 20; //Original from OPTRE_8Gauge_Pellets is 8, but since we can't do 500 pellets, we up the damage.
		submunitionAmmo = "B_12Gauge_Pellets_Submunition_Deploy";
		submunitionConeType[] = {"random", 25};
		submunitionConeAngle = 3;
	};
};

class cfgVehicles
{
	//Externals
	class LandVehicle;
	class Car: LandVehicle
	{
		class NewTurret;
	};
	class Car_F: Car
	{
		class AnimationSources
		{
			class HitLFWheel;
			class HitRFWheel;
			class HitLBWheel;
			class HitRBWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitLMWheel;
			class HitRMWheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class Gatling;
			class Gatling_flash;
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
			};
		};
		class HitPoints
		{
			class HitLFWheel;
			class HitLBWheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class HitFuel;
			class HitEngine;
			class HitBody;
		};
	};
	class OPTRE_M12_base;
	class OPTRE_M12_FAV: OPTRE_M12_base
	{
		class Turrets;
	};
	class OPTRE_M12_LRV: OPTRE_M12_FAV
	{
		class Turrets: Turrets
		{
			class CargoGunner_1;
			class MainTurret;
		};
	};
	class OPTRE_M12G1_LRV: OPTRE_M12_LRV
	{
		class Turrets: Turrets
		{
			class CargoGunner_1: CargoGunner_1{};
			class MainTurret: MainTurret
			{
				class ViewGunner;
				class ViewOptics;
			};
		};
	};
	
	//INTERNALS
	class OPAEX_M12G1S_LRV: OPTRE_M12G1_LRV
	{
		displayName = "M12G2 LRV Warthog (2-Gauge Shotgun)";
		hiddenSelections[] = {
			"Camo1",
			"Camo2",
			"clan",
			"clan_text",
			"insignia",
			//"_Ammobox",
			//"_Axe",
			//"_Cans",
			//"_FireExtinguisher",
			//"_Shovel"
		};
		class Turrets: Turrets
		{
			class CargoGunner_1: CargoGunner_1{};
			class MainTurret: MainTurret
			{
				weapons[] = {"OPAEX_W_2Gauge"};
				magazines[] = {
					"OPAEX_M_2Gauge_Pellets_2rnd", "OPAEX_M_2Gauge_Pellets_2rnd", 
					"OPAEX_M_2Gauge_Pellets_2rnd", "OPAEX_M_2Gauge_Pellets_2rnd", 
					"OPAEX_M_2Gauge_Pellets_2rnd", "OPAEX_M_2Gauge_Pellets_2rnd",
					"OPAEX_M_2Gauge_Pellets_2rnd", "OPAEX_M_2Gauge_Pellets_2rnd"
				};
				class ViewGunner: ViewGunner
				{
					//intentionally empty
				};
				class Viewoptics: ViewOptics
				{
					//intentionally empty
				};
			};
		};
	};
};