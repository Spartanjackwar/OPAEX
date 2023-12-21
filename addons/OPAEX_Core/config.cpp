class CfgPatches
{
 	class OPAEX_Core
 	{
		author = "Spartanjackwar";
		authors[] = {"Spartanjackwar"};
 		requiredAddons[] = {
			"OPTRE_Core", "A3_Armor_F_Gamma", "A3_Armor_F_Gamma_MBT_01"
		};
 		units[] = {};
 		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
 		requiredVersion = 0.1;
 	};
};

//187th for the rest of the file.
class 187th_SupplyImpact {
	class CannonFiredDust {
		simulation = "particles";
		type = "187th_CircleDustArtillery";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.5;
	};
};
class CfgCloudlets {
	class CircleDustArtillery;
	class 187th_CircleDustArtillery: CircleDustArtillery {
		circleRadius = 0.1;
		circleVelocity[] = {4, 0, 4};
		moveVelocity[] = {0, 0.15, 0};
		rotationVelocity = 0;
		
		weight = 0.053;
		volume = 0.04;
		rubbing = 0.1;
		
		lifeTime = 15;
		size[] = {3, 8, 10};
		color[] = {
			{0.205, 0.185, 0.15, 0.50}, //0.22, 0.1, 0.01
			{0.205, 0.185, 0.15, 0.25},
			{0.205, 0.185, 0.15, 0.01}
		};
	};
};

class cfgVehicles {
	//B_MBT_01_arty_F: B_MBT_01_arty_base_F: MBT_01_arty_base_F: MBT_01_base_F
	class MBT_01_arty_base_F;
	class B_MBT_01_arty_base_F: MBT_01_arty_base_F {
		class Turrets;
	};
	class B_MBT_01_arty_F: B_MBT_01_arty_base_F {
		class Turrets: Turrets {
			class MainTurret;
		};
	};
	class 187th_supplyPodLauncher: B_MBT_01_arty_F {
		displayName = "187th supply Launcher";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"187th_supplyPod_W"};
				magazines[] = {
					"187th_supplyPod_M",
					"187th_supplyPod_M"
				};
			};
		};
	};
};
class cfgWeapons {
	class CannonCore;
	class mortar_155mm_AMOS : CannonCore {
		class EventHandlers;
	};
	class 187th_supplyPod_W: mortar_155mm_AMOS {
		magazines[] = {"187th_supplyPod_M"};
		class EventHandlers: EventHandlers
		{
			class BarrierFired
			{
				fired = "[_this select 6] call OPAEX_fnc_AttachPod";
			};
		};
	};
}
class cfgMagazines {
	class 32Rnd_155mm_Mo_shells;
	class 187th_supplyPod_M: 32Rnd_155mm_Mo_shells {
		author = "Spartanjackwar";
		displayName = "SupplyPod";
		displayNameMFDFormat = "HE";
		ammo = "187th_supplyPod_A";
		count = 32;
	};
}
class cfgAmmo {
	class Sh_155mm_AMOS;
	class 187th_supplyPod_A: Sh_155mm_AMOS {
		//Damage handling.
		hit = 100;
		indirectHit = 0;
		indirectHitRange = 0.25;
		warheadName = "HE";
		typicalSpeed = 800;
		explosive = 0.8;
		timeToLive = 180;
		ace_frag_enabled = 0;
		
		//AI values
		dangerRadiusHit = 0;
		suppressionRadiusHit = 0;
		whistleDist = 0;
		
		//Visual Effects
		CraterEffects = "";
		CraterWaterEffects = "";
		ExplosionEffects = "187th_SupplyImpact";
		
		//Sounds
		soundHit1[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_01", 30, 0.1, 500}; // 2.51189
		soundHit2[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_02", 30, 0.1, 500};
		soundHit3[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_03", 30, 0.1, 500};
		soundHit4[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_04", 30, 0.1, 500};
		multiSoundHit[] = {
			"soundHit1", 0.25,
			"soundHit2", 0.25,
			"soundHit3", 0.25,
			"soundHit4", 0.25
		};
		SoundSetExplosion[] = {"", "", ""};
	};
}/*
		soundMetal9[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_01", 2.81838, 1, 75};
		soundMetal10[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_02", 2.81838, 1, 75};
		soundMetal11[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_03", 2.81838, 1, 75};
		soundMetal12[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_04", 2.81838, 1, 75};
		soundMetal13[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_05", 2.81838, 1, 75};
		soundMetal14[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_06", 2.81838, 1, 75};
		soundMetal15[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_07", 2.81838, 1, 75};
		soundMetal16[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_08", 2.81838, 1, 75};
		soundMetal17[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_09", 2.81838, 1, 75};
		soundMetal18[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_10", 2.81838, 1, 75};
		soundMetal19[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_11", 2.81838, 1, 75};
		soundMetal20[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_12", 2.81838, 1, 75};
		soundMetal21[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_13", 2.81838, 1, 75};
		soundMetal22[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_14", 2.81838, 1, 75};
		soundMetal23[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_15", 2.81838, 1, 75};
		soundMetal24[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_16", 2.81838, 1, 75};
		soundMetal25[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_18", 2.81838, 1, 75};
		soundMetal26[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_19", 2.81838, 1, 75};
		soundMetal27[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_20", 2.81838, 1, 75};
		soundMetal28[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_21", 2.81838, 1, 75};
		soundMetal29[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_22", 2.81838, 1, 75};
		soundMetal30[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_23", 2.81838, 1, 75};
		soundMetal31[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_24", 2.81838, 1, 75};
		soundMetal32[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_25", 2.81838, 1, 75};
		soundMetal33[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_26", 2.81838, 1, 75};
		soundMetal34[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_27", 2.81838, 1, 75};
		soundMetal35[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_28", 2.81838, 1, 75};
		soundMetal36[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_29", 2.81838, 1, 75};
		soundMetal37[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_30", 2.81838, 1, 75};
		soundMetal38[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_31", 2.81838, 1, 75};
		soundMetal39[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_01", 2.81838, 1, 75};
		soundMetal40[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_02", 2.81838, 1, 75};
		soundMetal41[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_03", 2.81838, 1, 75};
		soundMetal42[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_04", 2.81838, 1, 75};
		soundMetal43[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_05", 2.81838, 1, 75};
		soundMetal44[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_06", 2.81838, 1, 75};
		soundMetal45[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_07", 2.81838, 1, 75};
		soundMetal46[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_08", 2.81838, 1, 75};
		soundMetal47[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_09", 2.81838, 1, 75};
		soundMetal48[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_10", 2.81838, 1, 75};
		soundMetal49[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_11", 2.81838, 1, 75};
		soundMetal50[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_12", 2.81838, 1, 75};
		soundMetal51[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_13", 2.81838, 1, 75};
		soundMetal52[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_14", 2.81838, 1, 75};
		soundMetal53[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_15", 2.81838, 1, 75};
		soundMetal54[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_16", 2.81838, 1, 75};
		soundMetal55[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_17", 2.81838, 1, 75};
		soundMetal56[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_18", 2.81838, 1, 75};
		soundMetal57[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_19", 2.81838, 1, 75};
		soundMetal58[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_01", 2.81838, 1, 75};
		soundMetal59[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_02", 2.81838, 1, 75};
		soundMetal60[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_03", 2.81838, 1, 75};
		soundMetal61[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_04", 2.81838, 1, 75};
		soundMetal62[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_05", 2.81838, 1, 75};
		soundMetal63[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_06", 2.81838, 1, 75};
		soundMetal64[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_07", 2.81838, 1, 75};
		soundMetal65[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_08", 2.81838, 1, 75};
		soundMetal66[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_09", 2.81838, 1, 75};
		soundMetal67[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_10", 2.81838, 1, 75};
		soundMetal68[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_11", 2.81838, 1, 75};
		soundMetal69[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_12", 2.81838, 1, 75};
		soundMetal70[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_13", 2.81838, 1, 75};
		soundMetal71[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_14", 2.81838, 1, 75};
		soundVehiclePlate9[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_01", 1, 1, 75};
		soundVehiclePlate10[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_02", 1, 1, 75};
		soundVehiclePlate11[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_03", 1, 1, 75};
		soundVehiclePlate12[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_04", 1, 1, 75};
		soundVehiclePlate13[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_05", 1, 1, 75};
		soundVehiclePlate14[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_06", 1, 1, 75};
		soundVehiclePlate15[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_07", 1, 1, 75};
		soundVehiclePlate16[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_08", 1, 1, 75};
		soundVehiclePlate17[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_09", 1, 1, 75};
		soundVehiclePlate18[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_10", 1, 1, 75};
		soundVehiclePlate19[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_11", 1, 1, 75};
		soundVehiclePlate20[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_12", 1, 1, 75};
		soundVehiclePlate21[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_13", 1, 1, 75};
		soundVehiclePlate22[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_14", 1, 1, 75};
		soundVehiclePlate23[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_15", 1, 1, 75};
		soundVehiclePlate24[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_16", 1, 1, 75};
		soundVehiclePlate25[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_18", 1, 1, 75};
		soundVehiclePlate26[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_19", 1, 1, 75};
		soundVehiclePlate27[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_20", 1, 1, 75};
		soundVehiclePlate28[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_21", 1, 1, 75};
		soundVehiclePlate29[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_22", 1, 1, 75};
		soundVehiclePlate30[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_23", 1, 1, 75};
		soundVehiclePlate31[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_24", 1, 1, 75};
		soundVehiclePlate32[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_25", 1, 1, 75};
		soundVehiclePlate33[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_26", 1, 1, 75};
		soundVehiclePlate34[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_27", 1, 1, 75};
		soundVehiclePlate35[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_28", 1, 1, 75};
		soundVehiclePlate36[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_29", 1, 1, 75};
		soundVehiclePlate37[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_30", 1, 1, 75};
		soundVehiclePlate38[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_31", 1, 1, 75};
		soundVehiclePlate39[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_01", 1, 1, 75};
		soundVehiclePlate40[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_02", 1, 1, 75};
		soundVehiclePlate41[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_03", 1, 1, 75};
		soundVehiclePlate42[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_04", 1, 1, 75};
		soundVehiclePlate43[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_05", 1, 1, 75};
		soundVehiclePlate44[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_06", 1, 1, 75};
		soundVehiclePlate45[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_07", 1, 1, 75};
		soundVehiclePlate46[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_08", 1, 1, 75};
		soundVehiclePlate47[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_09", 1, 1, 75};
		soundVehiclePlate48[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_10", 1, 1, 75};
		soundVehiclePlate49[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_11", 1, 1, 75};
		soundVehiclePlate50[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_12", 1, 1, 75};
		soundVehiclePlate51[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_13", 1, 1, 75};
		soundVehiclePlate52[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_14", 1, 1, 75};
		soundVehiclePlate53[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_15", 1, 1, 75};
		soundVehiclePlate54[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_16", 1, 1, 75};
		soundVehiclePlate55[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_17", 1, 1, 75};
		soundVehiclePlate56[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_18", 1, 1, 75};
		soundVehiclePlate57[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_19", 1, 1, 75};
		soundVehiclePlate58[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_01", 1, 1, 75};
		soundVehiclePlate59[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_02", 1, 1, 75};
		soundVehiclePlate60[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_03", 1, 1, 75};
		soundVehiclePlate61[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_04", 1, 1, 75};
		soundVehiclePlate62[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_05", 1, 1, 75};
		soundVehiclePlate63[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_06", 1, 1, 75};
		soundVehiclePlate64[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_07", 1, 1, 75};
		soundVehiclePlate65[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_08", 1, 1, 75};
		soundVehiclePlate66[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_09", 1, 1, 75};
		soundVehiclePlate67[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_10", 1, 1, 75};
		soundVehiclePlate68[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_11", 1, 1, 75};
		soundVehiclePlate69[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_12", 1, 1, 75};
		soundVehiclePlate70[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_13", 1, 1, 75};
		soundVehiclePlate71[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_14", 1, 1, 75};
		soundWood9[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_01", 0.501187, 1, 75};
		soundWood10[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_02", 0.501187, 1, 75};
		soundWood11[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_03", 0.501187, 1, 75};
		soundWood12[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_04", 1.77828, 1, 75};
		soundWood13[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_05", 1.41254, 1, 75};
		soundWood14[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_18", 2.23872, 0.8, 75};
		soundWood15[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_19", 2.23872, 0.8, 75};
		soundWood16[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_20", 2.23872, 0.8, 75};
		soundWood17[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_09", 2.81838, 1, 75};
		soundWood18[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_10", 2.81838, 1, 75};
		soundWood19[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_11", 2.81838, 1, 75};
		soundWood20[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_12", 2.81838, 1, 90};
		soundWood21[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_13", 2.81838, 1, 75};
		soundWood22[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_14", 2.81838, 1, 75};
		soundWood23[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_15", 2.81838, 1, 87};
		soundWood24[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_16", 2.81838, 1, 75};
		soundWood25[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_17", 2.81838, 1, 75};
		soundWood26[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_18", 2.81838, 1, 85};
		soundWood27[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_19", 2.81838, 1, 75};
		soundWood28[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_20", 2.81838, 1, 75};
		soundWood29[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_21", 2.81838, 1, 75};
		soundWood30[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_22", 2.81838, 1, 75};
		soundWood31[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_23", 0.501187, 1, 75};
		soundWood32[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_24", 0.501187, 1, 75};
		soundWood33[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_25", 0.501187, 1, 75};
		soundWood34[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_26", 0.501187, 1, 75};
		soundWood35[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_27", 2.81838, 1, 75};
		soundWood36[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_28", 2.81838, 1, 75};
		soundWood37[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_29", 2.81838, 1, 75};
		soundWood38[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_30", 2.81838, 1, 75};
		soundWood39[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_31", 2.81838, 1, 75};
		soundWood40[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_32", 2.81838, 1, 75};
		soundWood41[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_33", 2.81838, 1, 90};
		soundWood42[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_34", 2.81838, 1, 75};
		soundWood43[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_35", 2.81838, 1, 95};
		soundWood44[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_36", 2.81838, 1, 75};
		soundWood45[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_37", 2.81838, 1, 75};
		soundWood46[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_38", 1.77828, 1, 75};
		soundWood47[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_39", 1.77828, 1, 75};
		soundWood48[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_40", 2.81838, 1, 75};
		soundWood49[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_41", 2.81838, 1, 76};
		soundWood50[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Wood_42", 2.81838, 1, 75};
		soundWood51[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_01", 2.81838, 1, 75};
		soundWood52[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_02", 2.81838, 1, 93};
		soundWood53[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_03", 2.81838, 1, 75};
		soundWood54[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_04", 2.81838, 1, 75};
		soundWood55[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_05", 2.81838, 1, 95};
		soundWood56[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_06", 2.81838, 1, 75};
		soundWood58[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_08", 2.81838, 1, 75};
		soundWood59[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_09", 2.81838, 1, 75};
		soundWood60[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_10", 2.81838, 1, 75};
		soundWood62[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_12", 2.81838, 1, 91};
		soundWood63[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_13", 2.81838, 1, 75};
		soundWood64[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_14", 2.81838, 1, 75};
		soundWood65[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_15", 2.81838, 1, 75};
		soundWood66[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_16", 2.81838, 1, 89};
		soundWood67[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_17", 2.81838, 1, 75};
		soundWood68[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_18", 2.81838, 1, 75};
		soundWood69[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_19", 2.81838, 1, 75};
		soundWood70[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_01", 2.81838, 1, 89};
		soundWood72[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_03", 2.81838, 1, 75};
		soundWood74[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_05", 2.81838, 1, 75};
		soundWood75[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_06", 2.81838, 1, 85};
		soundWood76[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_07", 2.81838, 1, 75};
		soundWood77[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_08", 2.81838, 1, 75};
		soundWood78[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_09", 1.41254, 1, 75};
		soundWood79[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_10", 1.41254, 1, 75};
		soundWood80[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_11", 2.81838, 1, 75};
		soundWood81[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_12", 2.81838, 1, 99};
		soundWood82[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_13", 2.81838, 1, 75};
		soundWood83[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_14", 2.81838, 1, 75};
		soundHitBuilding9[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_01", 2.81838, 1, 75};
		soundHitBuilding10[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_02", 2.81838, 1, 75};
		soundHitBuilding11[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_03", 2.81838, 1, 75};
		soundHitBuilding12[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_04", 2.81838, 1, 75};
		soundHitBuilding13[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_05", 2.81838, 1, 75};
		soundHitBuilding14[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_06", 2.81838, 1, 75};
		soundHitBuilding15[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_07", 2.81838, 1, 75};
		soundHitBuilding16[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_08", 2.81838, 1, 75};
		soundHitBuilding17[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_09", 2.81838, 1, 75};
		soundHitBuilding18[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_10", 2.81838, 1, 75};
		soundHitBuilding19[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_11", 2.81838, 1, 75};
		soundHitBuilding20[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_12", 2.81838, 1, 75};
		soundHitBuilding21[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_13", 2.81838, 1, 75};
		soundHitBuilding22[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_14", 2.81838, 1, 75};
		soundHitBuilding23[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_15", 2.81838, 1, 75};
		soundHitBuilding24[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_16", 2.81838, 1, 75};
		soundHitBuilding25[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_17", 2.81838, 1, 75};
		soundHitBuilding26[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_18", 2.81838, 1, 75};
		soundHitBuilding27[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_19", 2.81838, 1, 75};
		soundHitBuilding28[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_01", 2.81838, 1, 75};
		soundHitBuilding29[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_02", 2.81838, 1, 75};
		soundHitBuilding30[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_03", 2.81838, 1, 75};
		soundHitBuilding31[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_04", 2.81838, 1, 75};
		soundHitBuilding32[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_05", 2.81838, 1, 75};
		soundHitBuilding33[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_06", 2.81838, 1, 75};
		soundHitBuilding34[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_07", 2.81838, 1, 75};
		soundHitBuilding35[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_08", 2.81838, 1, 75};
		soundHitBuilding36[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_09", 2.81838, 1, 75};
		soundHitBuilding37[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_10", 2.81838, 1, 75};
		soundHitBuilding38[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_11", 2.81838, 1, 75};
		soundHitBuilding39[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_12", 2.81838, 1, 75};
		soundHitBuilding40[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_13", 2.81838, 1, 75};
		soundHitBuilding41[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_14", 2.81838, 1, 75};
		soundConcrete9[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_01", 1, 1, 75};
		soundConcrete10[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_02", 1, 1, 75};
		soundConcrete11[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_03", 1, 1, 75};
		soundConcrete12[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_04", 1, 1, 75};
		soundConcrete13[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_05", 1, 1, 75};
		soundConcrete14[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_06", 1, 1, 75};
		soundConcrete15[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_07", 1, 1, 75};
		soundConcrete16[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_08", 1, 1, 75};
		soundConcrete17[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_09", 1, 1, 75};
		soundConcrete18[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_10", 1, 1, 75};
		soundConcrete19[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_11", 1, 1, 75};
		soundConcrete20[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_12", 1, 1, 75};
		soundConcrete21[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_13", 1, 1, 75};
		soundConcrete22[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_14", 1, 1, 75};
		soundConcrete23[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_15", 1, 1, 75};
		soundConcrete24[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_16", 1, 1, 75};
		soundConcrete25[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_17", 1, 1, 75};
		soundConcrete26[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_18", 1, 1, 75};
		soundConcrete27[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_19", 1, 1, 75};
		soundConcrete28[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_01", 1, 1, 75};
		soundConcrete29[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_02", 1, 1, 75};
		soundConcrete30[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_03", 1, 1, 75};
		soundConcrete31[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_04", 1, 1, 75};
		soundConcrete32[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_05", 1, 1, 75};
		soundConcrete33[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_06", 1, 1, 75};
		soundConcrete34[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_07", 1, 1, 75};
		soundConcrete35[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_08", 1, 1, 75};
		soundConcrete36[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_09", 1, 1, 75};
		soundConcrete37[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_10", 1, 1, 75};
		soundConcrete38[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_11", 1, 1, 75};
		soundConcrete39[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_12", 1, 1, 75};
		soundConcrete40[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_13", 1, 1, 75};
		soundConcrete41[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_14", 1, 1, 75};
		soundMetalInt7[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\metal_07", 1.12202, 1, 35};
		soundMetalInt8[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\metal_08", 1.12202, 1, 35};
		soundMetalInt9[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_01", 1.41254, 1, 35};
		soundMetalInt10[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_02", 1.41254, 1, 35};
		soundMetalInt11[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_03", 1.41254, 1, 35};
		soundMetalInt12[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_04", 1.41254, 1, 35};
		soundMetalInt13[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_05", 1.41254, 1, 35};
		soundMetalInt14[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_06", 1.41254, 1, 35};
		soundMetalInt15[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_07", 1.41254, 1, 35};
		soundMetalInt16[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_08", 1.41254, 1, 35};
		soundMetalInt17[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_09", 1.41254, 1, 35};
		soundMetalInt18[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_10", 1.41254, 1, 35};
		soundMetalInt19[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_11", 1.41254, 1, 35};
		soundMetalInt20[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_12", 1.41254, 1, 35};
		soundMetalInt21[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_13", 1.41254, 1, 35};
		soundMetalInt22[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_14", 1.41254, 1, 35};
		soundMetalInt23[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_15", 1.41254, 1, 35};
		soundMetalInt24[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_16", 1.41254, 1, 35};
		soundMetalInt25[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_18", 1.41254, 1, 35};
		soundMetalInt26[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_19", 1.41254, 1, 35};
		soundMetalInt27[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_20", 1.41254, 1, 35};
		soundMetalInt28[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_21", 1.41254, 1, 35};
		soundMetalInt29[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_22", 1.41254, 1, 35};
		soundMetalInt30[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_23", 1.41254, 1, 35};
		soundMetalInt31[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_24", 1.41254, 1, 35};
		soundMetalInt32[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_25", 1.41254, 1, 35};
		soundMetalInt33[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_26", 1.41254, 1, 35};
		soundMetalInt34[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_27", 1.41254, 1, 35};
		soundMetalInt35[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_28", 1.41254, 1, 35};
		soundMetalInt36[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_29", 1.41254, 1, 35};
		soundMetalInt37[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_30", 1.41254, 1, 35};
		soundMetalInt38[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_31", 1.41254, 1, 35};
		soundMetalInt39[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_01", 1, 1, 35};
		soundMetalInt40[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_02", 1, 1, 35};
		soundMetalInt41[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_03", 1, 1, 35};
		soundMetalInt42[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_04", 1, 1, 35};
		soundMetalInt43[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_05", 1, 1, 35};
		soundMetalInt44[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_06", 1, 1, 35};
		soundMetalInt45[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_07", 1, 1, 35};
		soundMetalInt46[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_08", 1, 1, 35};
		soundMetalInt47[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_09", 1, 1, 35};
		soundMetalInt48[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_10", 1, 1, 35};
		soundMetalInt49[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_11", 1, 1, 35};
		soundMetalInt50[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_12", 1, 1, 35};
		soundMetalInt51[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_13", 1, 1, 35};
		soundMetalInt52[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_14", 1, 1, 35};
		soundMetalInt53[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_15", 1, 1, 35};
		soundMetalInt54[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_16", 1, 1, 35};
		soundMetalInt55[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_17", 1, 1, 35};
		soundMetalInt56[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_18", 1, 1, 35};
		soundMetalInt57[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_19", 1, 1, 35};
		soundMetalInt58[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_01", 1, 1, 35};
		soundMetalInt59[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_02", 1, 1, 35};
		soundMetalInt60[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_03", 1, 1, 35};
		soundMetalInt61[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_04", 1, 1, 35};
		soundMetalInt62[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_05", 1, 1, 35};
		soundMetalInt63[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_06", 1, 1, 35};
		soundMetalInt64[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_07", 1, 1, 35};
		soundMetalInt65[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_08", 1, 1, 35};
		soundMetalInt66[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_09", 1, 1, 35};
		soundMetalInt67[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_10", 1, 1, 35};
		soundMetalInt68[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_11", 1, 1, 35};
		soundMetalInt69[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_12", 1, 1, 35};
		soundMetalInt70[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_13", 1, 1, 35};
		soundMetalInt71[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_14", 1, 1, 35};
		soundVehiclePlateInt16[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_08", 1.2, 1, 35};
		soundVehiclePlateInt17[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_09", 1.2, 1, 35};
		soundVehiclePlateInt18[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_10", 1.2, 1, 35};
		soundVehiclePlateInt19[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_11", 1.2, 1, 35};
		soundVehiclePlateInt20[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_12", 1.2, 1, 35};
		soundVehiclePlateInt21[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_13", 1.2, 1, 35};
		soundVehiclePlateInt22[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_14", 1.2, 1, 35};
		soundVehiclePlateInt23[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_15", 1.2, 1, 35};
		soundVehiclePlateInt24[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_16", 1.2, 1, 35};
		soundVehiclePlateInt25[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_18", 1.2, 1, 35};
		soundVehiclePlateInt26[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_19", 1.2, 1, 35};
		soundVehiclePlateInt27[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_20", 1.2, 1, 35};
		soundVehiclePlateInt28[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_21", 1.2, 1, 35};
		soundVehiclePlateInt29[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_22", 1.2, 1, 35};
		soundVehiclePlateInt30[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_23", 1.2, 1, 35};
		soundVehiclePlateInt31[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_24", 1.2, 1, 35};
		soundVehiclePlateInt32[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_25", 1.2, 1, 35};
		soundVehiclePlateInt33[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_26", 1.2, 1, 35};
		soundVehiclePlateInt34[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_27", 1.2, 1, 35};
		soundVehiclePlateInt35[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_28", 1.2, 1, 35};
		soundVehiclePlateInt36[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_29", 1.2, 1, 35};
		soundVehiclePlateInt37[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_30", 1.2, 1, 35};
		soundVehiclePlateInt38[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Impact_Metal_31", 1.2, 1, 35};
		soundVehiclePlateInt39[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_01", 1.2, 1, 35};
		soundVehiclePlateInt40[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_02", 1.2, 1, 35};
		soundVehiclePlateInt41[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_03", 1.2, 1, 35};
		soundVehiclePlateInt42[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_04", 1.2, 1, 35};
		soundVehiclePlateInt43[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_05", 1.2, 1, 35};
		soundVehiclePlateInt44[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_06", 1.2, 1, 35};
		soundVehiclePlateInt45[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_07", 1.2, 1, 35};
		soundVehiclePlateInt46[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_08", 1.2, 1, 35};
		soundVehiclePlateInt47[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_09", 1.2, 1, 35};
		soundVehiclePlateInt48[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_10", 1.2, 1, 35};
		soundVehiclePlateInt49[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_11", 1.2, 1, 35};
		soundVehiclePlateInt50[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_12", 1.2, 1, 35};
		soundVehiclePlateInt51[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_13", 1.2, 1, 35};
		soundVehiclePlateInt52[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_14", 1.2, 1, 35};
		soundVehiclePlateInt53[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_15", 1.2, 1, 35};
		soundVehiclePlateInt54[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_16", 1.2, 1, 35};
		soundVehiclePlateInt55[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_17", 1.2, 1, 35};
		soundVehiclePlateInt56[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_18", 1.2, 1, 35};
		soundVehiclePlateInt57[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Generic_Distant_19", 1.2, 1, 35};
		soundVehiclePlateInt58[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_01", 1.2, 1, 35};
		soundVehiclePlateInt59[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_02", 1.2, 1, 35};
		soundVehiclePlateInt60[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_03", 1.2, 1, 35};
		soundVehiclePlateInt61[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_04", 1.2, 1, 35};
		soundVehiclePlateInt62[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_05", 1.2, 1, 35};
		soundVehiclePlateInt63[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_06", 1.2, 1, 35};
		soundVehiclePlateInt64[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_07", 1.2, 1, 35};
		soundVehiclePlateInt65[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_08", 1.2, 1, 35};
		soundVehiclePlateInt66[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_09", 1.2, 1, 35};
		soundVehiclePlateInt67[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_10", 1.2, 1, 35};
		soundVehiclePlateInt68[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_11", 1.2, 1, 35};
		soundVehiclePlateInt69[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_12", 1.2, 1, 35};
		soundVehiclePlateInt70[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_13", 1.2, 1, 35};
		soundVehiclePlateInt71[] = {"A3\Sounds_F_Enoch\Assets\Arsenal\Bullet_Impacts\Ricochet_Metal_14", 1.2, 1, 35};
		*/