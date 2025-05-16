class CfgPatches
{
 	class OPAEX_D20
 	{
		author = "Spartanjackwar";
 		requiredAddons[] = {
			"OPAEX_Core",
			"A3_Weapons_F",
			"A3_Data_F",
			"A3_Data_F_Kart",
			"OPTRE_UNSC_Units_Army"
		};
 		units[] = {
			"OPAEX_D20_UNSC_Army_Soldier_BananaGod"
		};
 		weapons[] = {"Throw"};
		magazines[] = {
			"OPAEX_M_D20",
			"OPAEX_M_D20_GL",
			"OPAEX_M_D20_3GL"
		};
		ammo[] = {
			"OPAEX_A_D20",
			"OPAEX_A_D20_bullet",
			"OPAEX_A_D20_GL"
		};
 		requiredVersion = 0.1;
 	};
};

class Mode_SemiAuto;

class cfgWeapons
{
	class GrenadeLauncher;
	class HeadgearItem;
	
	class Throw: GrenadeLauncher 
	{
		muzzles[] += {"OPAEX_W_D20"};  //I rarely use += with Arma3, but this is the time where you NEED it.
		class ThrowMuzzle;
		class OPAEX_W_D20: ThrowMuzzle
		{
			magazines[] = {"OPAEX_M_D20"};
		};
	};
	
	class OPTRE_UNSC_M52A_Armor_Base;
	class OPTRE_UNSC_M52A_Armor1_WDL: OPTRE_UNSC_M52A_Armor_Base {
		class ItemInfo;
	};
	class OPTRE_UNSC_M52D_Armor: OPTRE_UNSC_M52A_Armor1_WDL {
		class ItemInfo: ItemInfo {
			class HitpointsProtectionInfo;
		};
	};
	class OPTRE_UNSC_M52D_Armor_Demolitions: OPTRE_UNSC_M52D_Armor {
		class ItemInfo: ItemInfo {
			class HitpointsProtectionInfo: HitpointsProtectionInfo {
				class Neck;
				class Legs;
				class Arms;
				class Hands;
				class Chest;
				class Diaphragm;
				class Abdomen;
				class Body;
			};
		};
	};
	
	class H_HelmetB;
	class OPTRE_UNSC_CH252_Helmet_Base: H_HelmetB {
		class ItemInfo;
	};
	class OPTRE_UNSC_CH252D_Helmet_Base: OPTRE_UNSC_CH252_Helmet_Base {
		class ItemInfo: ItemInfo {
			class HitpointsProtectionInfo;
		};
	};
	class OPTRE_UNSC_CH252D_Helmet: OPTRE_UNSC_CH252D_Helmet_Base {
		class ItemInfo: ItemInfo {
			class HitpointsProtectionInfo: HitpointsProtectionInfo {
				class Head;
				class Face;
				class Neck;
			};
		};
	};
	class OPTRE_UNSC_CH252D_Helmet_dp: OPTRE_UNSC_CH252D_Helmet_Base {
		class ItemInfo: ItemInfo {
			class HitpointsProtectionInfo {
				class Head;
				class Face;
				class Neck;
			};
		};
	};
	class U_B_CombatUniform_mcam;
	class OPTRE_UNSC_Army_Uniform_WDL: U_B_CombatUniform_mcam {
		class ItemInfo;
	};
	#include"BananaGod\BananaGodArmor.hpp"
	
	class arifle_Mk20_F;
	class OPTRE_Shotgun_Base: arifle_Mk20_F {
		class WeaponSlotsInfo;
	};
	class OPTRE_M45: OPTRE_Shotgun_Base {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot;
			class CowsSlot;
			class PointerSlot;
			class UnderBarrelSlot;
 		};
		class Single;
	};
	#include"BananaGod\W_ShotgunOfDoom.hpp"
	#include"D20GMG\W_D20GMG.hpp"
};

class Extended_Fired_EventHandlers
{
	class Throw {
		class OPAEX_D20_Fired
		{
			serverFired = "_this spawn OPAEX_fnc_D20_Fired"; //TODO: Doublecheck for duplication error.
		};
	};
};

class CfgFactionClasses {
	class OPTRE_UNSC;
	class OPAEX_Cursed: OPTRE_UNSC
	{
		dlc = "OPAEX";
		displayName = "Cursed Stuff";
		author = "Spartanjackwar";
		side = 2;
		//icon = "\OPTRE_Core\data\icon_UNSC_ca.paa";
		//flag = "\OPTRE_Core\Data\flag_UNSC_ca.paa";
	};
};

class CfgEditorCategories
{
	class OPAEX_3DENCAT_Men_Cursed
	{
		displayName = "Cursed men";
	};
};
class CfgEditorSubcategories {
	class OPAEX_3DENSUBCAT_Men_Cursed {
		displayName = "Men (Cursed)";
	};
};
//================================================================================
class CfgVehicles
{
	class SoldierWB;
	class OPTRE_UNSC_Soldier_Base: SoldierWB {
		class HitPoints;
	};
	class OPTRE_UNSC_Army_Soldier_WDL: OPTRE_UNSC_Soldier_Base {
		class HitPoints: HitPoints {
			class HitNeck;
			class HitPelvis;
			class HitAbdomen;
			class HitDiaphragm;
			class HitChest;
			class HitArms;
			class HitHands;
			class HitLegs;
			class HitFace;
			class HitHead;
		};
	};
	#include"BananaGod\BananaGodSoldier.hpp"
	
	/*
	class C_Kart_01_F_Base;
	class C_Kart_01_F: C_Kart_01_F_Base {
		class Wheels {
			class LF;
			class LR;
			class RF;
			class RR;
		};
	};
	//#include"StupidFastKarts.hpp"
	*/
};

class cfgMagazines
{
	/*
	class HandGrenade: CA_Magazine
	{
		author = "Bohemia Interactive";
		mass = 10;
		scope = 2;
		value = 1;
		picture = "\A3\Weapons_F\Data\UI\gear_M67_CA.paa";
		model = "\A3\Weapons_f\ammo\Handgrenade";
		type = 256;
		ammo = "GrenadeHand";
		count = 1;
		initSpeed = 18;
		nameSound = "handgrenade";
		maxLeadSpeed = 6.94444;
		descriptionShort = "Type: Defensive Grenade<br />Rounds: 1<br />Used in: Hand";
		displayName = "M67 Fragmentation Grenade";
		displayNameShort = "M67";
	};
	*/
	class 1Rnd_HE_Grenade_shell;
	class HandGrenade;
	class OPAEX_M_D20: HandGrenade
	{
		author = "Spartanjackwar";
		descriptionShort = "Type: Random grenade that does random things. <br />Rounds: 1<br />Used in: Hand";
		displayName = "Cursed D20 Grenade";
		displayNameShort = "D20";
		
		//Ensure all scopes work
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		
		ammo = "OPAEX_A_D20"; //Note the name scheme: M for magazine, A for ammo.
		
		#include"AllScriptsD20.hpp"
	};
	class OPAEX_M_D20_GL: 1Rnd_HE_Grenade_shell {
		author = "Spartanjackwar";
		displayName = "Cursed D20 GL";
		displayNameShort = "D20";
		descriptionShort = "Type: Random grenade that does random things. <br />Caliber: Yes.<br />Rounds: 1<br />Used in: Any M203 equivalent.";
		ammo = "OPAEX_A_D20_GL";
		
		#include"AllScriptsD20.hpp"
	};
	class OPAEX_M_D20_3GL: OPAEX_M_D20_GL {
		displayName = "Cursed D20 3GL";
		displayNameShort = "3x D20";
		descriptionShort = "Type: Random grenade that does random things. <br />Caliber: Yes.<br />Rounds: 3<br />Used in: Any M203 equivalent.";
		ammo = "OPAEX_A_D20_GL";
		count = 3;
	};
	
	class OPTRE_6Rnd_8Gauge_HEDP;
	#include"BananaGod\M_ShotgunOfDoom.hpp"
	#include"D20GMG\M_D20GMG.hpp"
};

class cfgMagazineWells {
	class UGL_40x36 {
		OPAEX_D20[] = {"OPAEX_M_D20_GL"};
	};
	class CBA_40mm_M203 {
		OPAEX_D20[] = {"OPAEX_M_D20_GL"};
	};
	class CBA_40mm_EGLM {
		OPAEX_D20[] = {"OPAEX_M_D20_GL"};
	};
	class 3UGL_40x36 {
		OPAEX_D20[] = {"OPAEX_M_D20_3GL"};
	};
	class CBA_40mm_3GL {
		OPAEX_D20[] = {"OPAEX_M_D20_3GL"};
	};
};

class cfgAmmo
{
	/*
	class GrenadeHand: Grenade
	{
		hit = 8;
		indirectHit = 8;
		indirectHitRange = 6;
		dangerRadiusHit = 60;
		suppressionRadiusHit = 24;
		typicalspeed = 18;
		model = "\A3\Weapons_f\ammo\Handgrenade_throw";
		visibleFire = 0.5;
		audibleFire = 0.05;
		visibleFireTime = 1;
		fuseDistance = 0;
		ace_frag_enabled = 1;
		ace_frag_skip = 0;
		ace_frag_force = 1;
		ace_frag_classes[] = {"ace_frag_tiny_HD"};
		ace_frag_metal = 210;
		ace_frag_charge = 185;
		ace_frag_gurney_c = 2843;
		ace_frag_gurney_k = "3/5";
	};
	*/
	class BulletBase;
	class GrenadeHand;
	class G_40mm_HE;
	class OPAEX_A_D20: GrenadeHand {
		#include"D20AmmoValues.hpp"
	};
	class OPAEX_A_D20_bullet: BulletBase {
		#include"D20AmmoValues.hpp"
	};
	class OPAEX_A_D20_GL: G_40mm_HE {
		#include"D20AmmoValues.hpp"
	};
	
	class OPTRE_8Gauge_HEDP;
	#include"BananaGod\A_ShotgunOfDoom.hpp"
};

class cfgSounds
{
	class OPAEX_Sound_D20_Enderpearl
	{
		name = "OPAEX_Sound_D20_Enderpearl";
		sound[] = {"\OPAEX_D20\TeleportD20.ogg", db+15, 1.0, 300}; //path, decibles, pitch, distance.
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_GBP
	{
		name = "OPAEX_Sound_D20_GBP";
		sound[] = {"\OPAEX_D20\GBPSound.ogg", db+10, 1.0, 300}; //path, decibles, pitch.
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_EldritchBananaGodBassBoost
	{
		name = "OPAEX_Sound_D20_EldritchBananaGodBassBoost";
		sound[] = {"\OPAEX_D20\EldritchBananaGodBassBoost.ogg", db+15, 1.0, 1000};
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_Yeet
	{
		name = "OPAEX_Sound_D20_Yeet";
		sound[] = {"\OPAEX_D20\Yeet.ogg", db+10, 1.0, 300};
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_StrategicLaunchDetected
	{
		name = "OPAEX_Sound_D20_StrategicLaunchDetected";
		sound[] = {"\OPAEX_D20\StrategicLaunchDetectedButLouder.ogg", db+15, 1.0, 1000};
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_Snap
	{
		name = "OPAEX_Sound_D20_Snap";
		sound[] = {"\OPAEX_D20\Snap.ogg", db+10, 1.0, 300};
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_TruckHorn
	{
		name = "OPAEX_Sound_D20_TruckHorn";
		sound[] = {"A3\Sounds_F\weapons\horns\MRAP_02_horn_1", db+10, 1.0, 300};
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_TruckHorn2
	{
		name = "OPAEX_Sound_D20_TruckHorn2";
		sound[] = {"A3\Sounds_F\weapons\horns\truck_horn_2", db+10, 1.0, 300};
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_TruckHorn3
	{
		name = "OPAEX_Sound_D20_TruckHorn3";
		sound[] = {"A3\Sounds_F\weapons\horns\truck_horn_3", db+10, 1.0, 300};
		titles[] = {0, ""};
	};
	class OPAEX_Sound_D20_TruckHorn4
	{
		name = "OPAEX_Sound_D20_TruckHorn4";
		sound[] = {"\OPAEX_D20\Truckhorn.ogg", db+10, 1.0, 300};
		titles[] = {0, ""};
	};
};

class cfgIdentities {
	class BananaGod {
		name = "Banana God";
		face = "whiteHead_01";
		glasses = "None";
		speaker = "Male00ENG";
		pitch = 1;
		nameSound = "Kerry";
	};
};
