//Armor
class OPAEX_D20_UNSC_M52D_Armor_BananaGod: OPTRE_UNSC_M52D_Armor_Demolitions
{
	author = "Spartanjackwar";
	scope = 1;
	displayName = "M52D Body Armor (BananaGod)";
	hiddenSelectionsTextures[] = {
		"OPAEX_D20\BananaGod\vest_Banana_co.paa",
		"OPAEX_D20\BananaGod\armor_Banana_co.paa",
		"OPAEX_D20\BananaGod\legs_Banana_co.paa",
		"optre_unsc_units\army\data\ghillie_woodland_co.paa",
		"OPAEX_D20\BananaGod\ODST_armor_Banana_co.paa"
	};
	class ItemInfo: ItemInfo
	{
		hiddenSelections[] = {"camo", "camo2", "camo3", "camo4", "camo5", "A_KneesMarLeft", "A_KneesMarRight", "A_Ghillie", "A_TacPad", "AS_LargeLeft", "AS_LargeRight", "AS_MediumLeft", "AS_MediumRight", "AS_ODSTCQBLeft", "AS_ODSTCQBRight", "AS_ODSTSniperLeft", "AS_ODSTSniperRight", "AS_SmallLeft", "AS_SmallRight", "AP_AR", "AP_BR", "AP_Canteen", "AP_GL", "AP_Knife", "AP_MGThigh", "AP_AR", "AP_Pack", "AP_Pistol", "AP_Rounds", "AP_SG", "AP_SMG", "AP_Sniper", "AP_Thigh", "AP_Frag", "AP_Smoke", "APO_AR", "APO_BR", "APO_Knife", "APO_SMG", "APO_Sniper"};
		hiddenSelectionsTextures[] = {
			"OPAEX_D20\BananaGod\vest_Banana_co.paa",
			"OPAEX_D20\BananaGod\armor_Banana_co.paa",
			"OPAEX_D20\BananaGod\legs_Banana_co.paa",
			"optre_unsc_units\army\data\ghillie_woodland_co.paa",
			"OPAEX_D20\BananaGod\ODST_armor_Banana_co.paa"
		};
		class HitpointsProtectionInfo: HitpointsProtectionInfo
		{
			class Neck: Neck
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Legs: Legs
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Arms: Arms
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Hands: Hands
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Chest: Chest
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Diaphragm: Diaphragm
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Abdomen: Abdomen
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Body: Body
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
		};
	};
};

//uniform
class OPAEX_D20_UNSC_Army_Uniform_BananaGod: OPTRE_UNSC_Army_Uniform_WDL
{
	displayName = "Cross-Branch BDU (BananaGod)";
	scope = 1;
	class ItemInfo: ItemInfo
	{
		uniformClass = "OPAEX_D20\BananaGod_UNSC_Army_Soldier_Banana";
	};
};


//Helmets
class OPAEX_D20_UNSC_CH252D_Helmet_BananaGod: OPTRE_UNSC_CH252D_Helmet
{
	author = "Spartanjackwar";
	scope = 1;
	displayName = "CH252D Helmet (BananaGod)";
	hiddenSelectionsTextures[] = {
		"OPAEX_D20\BananaGod\odst_helmet_Banana_co.paa",
		"optre_unsc_units\army\data\odst_helmet_visor_co.paa"
	};
	class ItemInfo: ItemInfo {
		passThrough = 0.0000001;
		class HitpointsProtectionInfo: HitpointsProtectionInfo
		{
			class Head: Head
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Face: Face
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Neck: Neck
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
		};
	};
};
class OPAEX_D20_UNSC_CH252D_Helmet_BananaGod_dp: OPTRE_UNSC_CH252D_Helmet_dp
{
	author = "Spartanjackwar";
	scope = 1;
	displayName = "CH252D Helmet (BananaGod)";
	hiddenSelectionsTextures[] = {
		"OPAEX_D20\BananaGod\odst_helmet_Banana_co.paa",
		"optre_unsc_units\army\data\odst_helmet_visor_ca.paa"
	};
	class ItemInfo: ItemInfo {
		passThrough = 0.0000001;
		class HitpointsProtectionInfo: HitpointsProtectionInfo
		{
			class Head: Head
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Face: Face
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
			class Neck: Neck
			{
				armor = 6666;
				passThrough = 0.0000001;
			};
		};
	};
};