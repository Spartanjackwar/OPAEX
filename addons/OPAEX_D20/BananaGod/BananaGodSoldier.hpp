class OPAEX_D20_UNSC_Army_Soldier_BananaGod: OPTRE_UNSC_Army_Soldier_WDL
{
	scope = 1;
	
	brakeDistance = 1; //+4
	maxSpeed = 40.2336; //24 was original.
	maxTurnAngularVelocity = 5; //+2
	
	armor = 666; //More or less the HP of the unit.  Usually 2, but this is a god.
	
	icon = "iconManOfficer";
	linkedItems[] = {
		"OPAEX_D20_UNSC_M52D_Armor_BananaGod",
		"OPAEX_D20_UNSC_CH252D_Helmet_BananaGod",
		"ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "OPTRE_NVG", "OPTRE_Biofoam", "OPTRE_NVG"
	};
	respawnLinkedItems[] = {
		"OPAEX_D20_UNSC_M52D_Armor_BananaGod",
		"OPAEX_D20_UNSC_CH252D_Helmet_BananaGod",
		"ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "OPTRE_NVG", "OPTRE_Biofoam", "OPTRE_NVG"
	};
	weapons[] = {
		"OPAEX_D20_W_M45BananaGod", 
		"Throw", 
		"Put"
	};
	respawnWeapons[] = {
		"OPAEX_D20_W_M45BananaGod", 
		"Throw", 
		"Put"
	};
	magazines[] = {
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd"
	};
	respawnMagazines[] = {
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd", 
		"OPAEX_D20_M45BananaGod_6666Rnd"
	};
	class HitPoints: HitPoints
	{
		class HitNeck: HitNeck
		{
			armor = 6666;
		};
		class HitPelvis: HitPelvis
		{
			armor = 6666;
		};
		class HitAbdomen: HitAbdomen
		{
			armor = 6666;
		};
		class HitDiaphragm: HitDiaphragm
		{
			armor = 6666;
		};
		class HitChest: HitChest
		{
			armor = 6666;
		};
		class HitArms: HitArms
		{
			armor = 6666;
		};
		class HitHands: HitHands
		{
			armor = 6666;
		};
		class HitLegs: HitLegs
		{
			armor = 6666;
		};
		class HitFace: HitFace
		{
			armor = 6666;
		};
		class HitHead: HitHead
		{
			armor = 6666;
		};
	};
	uniformClass = "OPAEX_D20_UNSC_Army_Uniform_BananaGod";
	hiddenSelectionsTextures[] = {
		"OPAEX_D20\BananaGod\Uniform_Banana_a_CO.paa",
		"OPAEX_D20\BananaGod\Uniform_Banana_b_CO.paa"
	};
};