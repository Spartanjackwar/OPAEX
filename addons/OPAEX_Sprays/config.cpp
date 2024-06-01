//Jack Moss, aka Spartanjackwar

class CfgPatches
{
	class OPAEX_Sprays
	{
		author = "Spartanjackwar";
		authors[] = {"Spartanjackwar"};
 		requiredAddons[] = {
			"OPAEX_Core"
			//"ace_tagging" we actually do not need ACE for the items.  It is needed only for the spray can functionality.
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={
			"OPAEX_SprayCan",
			"OPAEX_BananaCan"
		};
	};
};

class cfgWeapons {
	/*class Land_Can_V3_F: Items_base_F
	{
		author = "Bohemia Interactive";
		mapSize = 0.05;
		class SimpleObject
		{
			eden = 1;
			animate[] = {};
			hide[] = {};
			verticalOffset = 0.041;
			verticalOffsetWorld = 0;
			init = "''";
		};
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Can_V3_F.jpg";
		_generalMacro = "Land_Can_V3_F";
		scope = 2;
		scopeCurator = 2;
		displayName = "Can (RedGull)";
		model = "\A3\Structures_F\Items\Food\Can_V3_F.p3d";
		icon = "iconObject_circle";
		editorSubcategory = "EdSubcat_Food";
	};
	class ACE_SpraypaintBlack: ACE_ItemCore
	{
		author = "jokoho48";
		displayname = "Spray Paint (Black)";
		descriptionShort = "A can of spray paint for tagging walls.";
		picture = "\z\ace\addons\tagging\UI\items\itemSpraypaintBlack.paa";
		model = "\z\ace\addons\tagging\data\SprayCan.p3d";
		scope = 2;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\z\ace\addons\tagging\data\spraycanBlack_co.paa"};
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass = 10;
		};
	};*/
	
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
	class OPAEX_ItemCore: CBA_MiscItem {
		//Intentionally Empty
	};
	class OPAEX_SprayCan: OPAEX_ItemCore { //I made my own rather than inherit from ACE to prevent a class dependence on ACE.
		author = "Spartanjackwar";
		scope = 2;
		
		displayname = "Spray Paint (OPAEX)";
		descriptionShort = "An item that lets you tag walls.";
		
		picture = "\OPAEX_Sprays\UI\Logo_X.paa";
		model = "\A3\Structures_F\Items\Food\Can_V3_F.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass = 0.1;
		};
	};
	class OPAEX_BananaCan: OPAEX_SprayCan {
		displayName = "Spray Paint (Bananas? Bananas!)";
		descriptionShort = "An item that lets you tag walls with bananas.  There are only bananas.";
		picture = "\OPAEX_Sprays\sprays\Bananas\Spray_Banana.paa";
	};
	class OPAEX_ChadCan: OPAEX_SprayCan {
		displayName = "Spray Paint (Based Chads)";
		descriptionShort = "An item that lets you tag walls with based chads.";
		picture = "\OPAEX_Sprays\sprays\Chads\Spray_Chad1.paa";
	};
	class OPAEX_ODSTChadCan: OPAEX_ChadCan {
		displayName = "Spray Paint (Chads ODST)";
		descriptionShort = "An item that lets you tag walls with based ODST chads.";
		picture = "\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadA.paa";
	};
	class OPAEX_ModLogoCan: OPAEX_SprayCan {
		displayName = "Spray Paint (Mod Logos)";
		descriptionShort = "An item that lets you tag walls with the logos of mega-based badass chads.";
	};
	class OPAEX_KilroyCan: OPAEX_SprayCan {
		displayName = "Spray Paint (Kilroys)";
		descriptionShort = "An item that lets you tag walls with kilroy-esque stuff.";
	};
	class OPAEX_RandomCan: OPAEX_SprayCan {
		displayName = "Spray Paint (Ultra random can)";
		descriptionShort = "An item that lets you tag walls with a random OPAEX spray.";
	};
	class OPAEX_19thCan: OPAEX_SprayCan {
		displayName = "Spray Paint (19th Fleet)";
		descriptionShort = "An item that lets you tag walls with 19th fleet logos.";
		picture = "\OPAEX_Sprays\sprays\19th\Spray_19_Logo.paa";
	};
};


/*Fun tag facts:
	The texutres can be any power of 2 up to 4096x4096.
	Icons support any power of 2 image up to 4096x4096.
	Icons can easily just be the actual spray image!
	Materials and textures are arrays because you can randomly cycle between them when spraying.
	
	Why do I start with random cans as parents in my spray class chain?
	It's so that I don't introduce icons into the chain to keep the convention that iconless items are randoms.
*/
class ACE_Tags {
	//Mod logos
	class OPAEX_Logo_Random {
		displayName = "Random";  // Name of your tag being displayed in the interaction menu
		requiredItem = "OPAEX_ModLogoCan";  // Required item to have in the inventory to be able to spray your tag (eg. `"ACE_SpraypaintBlack"`, `"ACE_SpraypaintRed"`, `"ACE_SpraypaintGreen"`, `"ACE_SpraypaintBlue"` or any custom item from `CfgWeapons`)
		materials[] = {}; // Optional: List of material variations (one is randomly selected). Keep empty if you don't need a custom material.
		textures[] = {
			"\OPAEX_Sprays\sprays\ModLogos\Spray_OPAEX.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_A2S.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_DingusElement.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_BlackElement.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_TCF.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_OPCOS.paa"
		};  // List of texture variations (one is randomly selected when tagging)
		icon = ""; //"\z\ace\addons\tagging\UI\icons\iconTaggingBlack.paa";  // Icon being displayed in the interaction menu
	};
	class OPAEX_Logo: OPAEX_Logo_Random {
		displayName = "OPAEX";
		textures[] = {"\OPAEX_Sprays\sprays\ModLogos\Spray_OPAEX.paa"};
		icon = "\OPAEX_Sprays\sprays\ModLogos\Spray_OPAEX.paa";
	};
	class OPAEX_Article2: OPAEX_Logo {
		displayName = "A2S";
		textures[] = {"\OPAEX_Sprays\sprays\ModLogos\Spray_A2S.paa"};
		icon = "\OPAEX_Sprays\sprays\ModLogos\Spray_A2S.paa";
	};
	class OPAEX_DingusElement: OPAEX_Logo {
		displayName = "Dingus Element";
		textures[] = {"\OPAEX_Sprays\sprays\ModLogos\Spray_DingusElement.paa"};
		icon = "\OPAEX_Sprays\sprays\ModLogos\Spray_DingusElement.paa";
	};
	class OPAEX_BlackElement: OPAEX_Logo {
		displayName = "Black Element";
		textures[] = {"\OPAEX_Sprays\sprays\ModLogos\Spray_BlackElement.paa"};
		icon = "\OPAEX_Sprays\sprays\ModLogos\Spray_BlackElement.paa";
	};
	class OPAEX_TheCarverFindings: OPAEX_Logo {
		displayName = "Carver Findings";
		textures[] = {"\OPAEX_Sprays\sprays\ModLogos\Spray_TCF.paa"};
		icon = "\OPAEX_Sprays\sprays\ModLogos\Spray_TCF.paa";
	};
	class OPAEX_OPCOS: OPAEX_Logo {
		displayName = "OPCOS";
		textures[] = {"\OPAEX_Sprays\sprays\ModLogos\Spray_OPCOS.paa"};
		icon = "\OPAEX_Sprays\sprays\ModLogos\Spray_OPCOS.paa";
	};
	
	//General sprays
	class OPAEX_General_Random: OPAEX_Logo_Random {
		displayName = "Random";
		requiredItem = "OPAEX_SprayCan";
		textures[] = {
			"\OPAEX_Sprays\sprays\Spray_UNSC.paa",
			"\OPAEX_Sprays\sprays\Spray_UNSC_PostWar.paa",
			"\OPAEX_Sprays\sprays\Spray_Fist.paa",
			"\OPAEX_Sprays\sprays\Spray_GmodMissing.paa",
			"\OPAEX_Sprays\sprays\Spray_Spartanjackwar.paa",
			"\OPAEX_Sprays\sprays\Spray_Div7.paa"
		};
	};
	class OPAEX_UNSC: OPAEX_General_Random {
		displayName = "UNSC";
		textures[] = {"\OPAEX_Sprays\sprays\Spray_UNSC.paa"};
		icon = "\OPAEX_Sprays\sprays\Spray_UNSC.paa";
	};
	class OPAEX_UNSC_PostWar: OPAEX_General_Random {
		displayName = "UNSC Post-war";
		textures[] = {"\OPAEX_Sprays\sprays\Spray_UNSC_PostWar.paa"};
		icon = "\OPAEX_Sprays\sprays\Spray_UNSC_PostWar.paa";
	};
	class OPAEX_Fist: OPAEX_General_Random {
		displayName = "Fist";
		textures[] = {"\OPAEX_Sprays\sprays\Spray_Fist.paa"};
		icon = "\OPAEX_Sprays\sprays\Spray_Fist.paa";
	};
	class OPAEX_MissingTexture: OPAEX_General_Random {
		displayName = "You forgot CSS";
		textures[] = {"\OPAEX_Sprays\sprays\Spray_GmodMissing.paa"};
		icon = "\OPAEX_Sprays\sprays\Spray_GmodMissing.paa";
	};
	class OPAEX_Spartanjackwar: OPAEX_General_Random {
		displayName = "Spartanjackwar";
		textures[] = {"\OPAEX_Sprays\sprays\Spray_Spartanjackwar.paa"};
		icon = "\OPAEX_Sprays\sprays\Spray_Spartanjackwar.paa";
	};
	class OPAEX_Div7: OPAEX_General_Random {
		displayName = "Division 7";
		textures[] = {"\OPAEX_Sprays\sprays\Spray_Div7.paa"};
		icon = "\OPAEX_Sprays\sprays\Spray_Div7.paa";
	};
	
	//Bananas
	class OPAEX_Banana_Random: OPAEX_Logo_Random {
		displayName = "Random";
		requiredItem = "OPAEX_BananaCan";
		textures[] = {
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana.paa",
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pog.paa",
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pirate.paa",
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pepe.paa",
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Knuckles.paa"
		};
	};
	class OPAEX_Banana: OPAEX_Banana_Random {
		displayName = "Banana";
		textures[] = {"\OPAEX_Sprays\sprays\Bananas\Spray_Banana.paa"};
		icon = "\OPAEX_Sprays\sprays\Bananas\Spray_Banana.paa";
	};
	class OPAEX_Banana_Pog: OPAEX_Banana_Random {
		displayName = "Poggers";
		textures[] = {"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pog.paa"};
		icon = "\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pog.paa";
	};
	class OPAEX_Banana_Pirate: OPAEX_Banana_Random {
		displayName = "Pirate";
		textures[] = {"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pirate.paa"};
		icon = "\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pirate.paa";
	};
	class OPAEX_Banana_Pepe: OPAEX_Banana_Random {
		displayName = "Pepe";
		textures[] = {"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pepe.paa"};
		icon = "\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pepe.paa";
	};
	class OPAEX_Banana_Knuckles: OPAEX_Banana_Random {
		displayName = "Knuckles";
		textures[] = {"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Knuckles.paa"};
		icon = "\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Knuckles.paa";
	};
	
	//Chads
	class OPAEX_Chad_Random: OPAEX_Logo_Random {
		displayName = "Random";
		requiredItem = "OPAEX_ChadCan";
		textures[] = { //I bet you forgot these can randomize.  Read the documentation friends.
			"\OPAEX_Sprays\sprays\Chads\Spray_Chad1.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_Chad2.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_Chad3.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_Chad4.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ChadJohnson.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ChadKerensky.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ChadFocht.paa"
		};
	};
	class OPAEX_Chad: OPAEX_Chad_Random {
		displayName = "Chad";
		textures[] = {"\OPAEX_Sprays\sprays\Chads\Spray_Chad1.paa"};
		icon = "\OPAEX_Sprays\sprays\Chads\Spray_Chad1.paa";
	};
	class OPAEX_Chad_Smile: OPAEX_Chad_Random {
		displayName = "Smile";
		textures[] = {"\OPAEX_Sprays\sprays\Chads\Spray_Chad2.paa"};
		icon = "\OPAEX_Sprays\sprays\Chads\Spray_Chad2.paa";
	};
	class OPAEX_Chad_Giga: OPAEX_Chad_Random {
		displayName = "Giga";
		textures[] = {"\OPAEX_Sprays\sprays\Chads\Spray_Chad3.paa"};
		icon = "\OPAEX_Sprays\sprays\Chads\Spray_Chad3.paa";
	};
	class OPAEX_Chad_Imposing: OPAEX_Chad_Random {
		displayName = "Imposing";
		textures[] = {"\OPAEX_Sprays\sprays\Chads\Spray_Chad4.paa"};
		icon = "\OPAEX_Sprays\sprays\Chads\Spray_Chad4.paa";
	};
	class OPAEX_Chad_Johnson: OPAEX_Chad_Random {
		displayName = "Johnson Chad";
		textures[] = {"\OPAEX_Sprays\sprays\Chads\Spray_ChadJohnson.paa"};
		icon = "\OPAEX_Sprays\sprays\Chads\Spray_ChadJohnson.paa";
	};
	class OPAEX_Chad_Kerensky: OPAEX_Chad_Random {
		displayName = "Aleksandr Sergeyevich Kerensky";
		textures[] = {"\OPAEX_Sprays\sprays\Chads\Spray_ChadKerensky.paa"};
		icon = "\OPAEX_Sprays\sprays\Chads\Spray_ChadKerensky.paa";
	};
	class OPAEX_Chad_Focht: OPAEX_Chad_Random {
		displayName = "Anastasius Focht";
		textures[] = {"\OPAEX_Sprays\sprays\Chads\Spray_ChadFocht.paa"};
		icon = "\OPAEX_Sprays\sprays\Chads\Spray_ChadFocht.paa";
	};
	
	//ODST Chads
	class OPAEX_ChadODST_Random: OPAEX_Logo_Random {
		displayName = "Random";
		requiredItem = "OPAEX_ODSTChadCan";
		textures[] = { //I bet you forgot these can randomize.  Read the documentation friends.
			"\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadA.paa",
			"\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadB.paa",
			"\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadC.paa",
			"\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadD.paa"
		};
	};
	class OPAEX_ChadODST_A: OPAEX_ChadODST_Random {
		displayName = "Chad";
		textures[] = {"\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadA.paa"};
		icon = "\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadA.paa";
	};
	class OPAEX_ChadODST_B: OPAEX_ChadODST_Random {
		displayName = "Stare";
		textures[] = {"\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadB.paa"};
		icon = "\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadB.paa";
	};
	class OPAEX_ChadODST_C: OPAEX_ChadODST_Random {
		displayName = "Imposing";
		textures[] = {"\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadC.paa"};
		icon = "\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadC.paa";
	};
	class OPAEX_ChadODST_D: OPAEX_ChadODST_Random {
		displayName = "Giga";
		textures[] = {"\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadD.paa"};
		icon = "\OPAEX_Sprays\sprays\ODSTChads\Spray_ODSTChadD.paa";
	};
	
	//Kilroys
	class OPAEX_Kilroy_Random: OPAEX_Logo_Random {
		displayName = "Random";
		requiredItem = "OPAEX_KilroyCan";
		textures[] = { //I bet you forgot these can randomize.  Read the documentation friends.
			"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Gnome.paa",
			"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Way3.paa",
			"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Racoon.paa"
		};
	};
	class OPAEX_Kilroy_Gnome: OPAEX_Kilroy_Random {
		displayName = "Gnome";
		textures[] = {"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Gnome.paa"};
		icon = "\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Gnome.paa";
	};
	class OPAEX_Kilroy_Way3: OPAEX_Kilroy_Random {
		displayName = "Way3";
		textures[] = {"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Way3.paa"};
		icon = "\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Way3.paa";
	};
	class OPAEX_Kilroy_Racoon: OPAEX_Kilroy_Random {
		displayName = "Racoon";
		textures[] = {"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Racoon.paa"};
		icon = "\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Racoon.paa";
	};
	
	//19th fleet
	class OPAEX_19th_Random: OPAEX_Logo_Random {
		displayName = "Random";
		requiredItem = "OPAEX_19thCan";
		textures[] = { //I bet you forgot these can randomize.  Read the documentation friends.
			"\OPAEX_Sprays\sprays\19th\Spray_19_FenA.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_FenB.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Hoplite.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Hop1.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Hop2.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Logo.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Wayfinder.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2Black.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2Shadow.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Wayfinder3.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Grif.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_FenLowVis.paa"
		};
	};
	class OPAEX_19th_FenrirA: OPAEX_19th_Random {
		displayName = "Fenrir 1";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_FenA.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_FenA.paa";
	};
	class OPAEX_19th_FenrirB: OPAEX_19th_Random {
		displayName = "Fenrir 2";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_FenB.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_FenB.paa";
	};
	class OPAEX_19th_Hoplite: OPAEX_19th_Random {
		displayName = "Hoplite";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_Hoplite.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_Hoplite.paa";
	};
	class OPAEX_19th_Hop1: OPAEX_19th_Random {
		displayName = "Hoplite 1";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_Hop1.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_Hop1.paa";
	};
	class OPAEX_19th_Hop2: OPAEX_19th_Random {
		displayName = "Hoplite 2";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_Hop2.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_Hop2.paa";
	};
	class OPAEX_19th: OPAEX_19th_Random {
		displayName = "19th";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_Logo.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_Logo.paa";
	};
	class OPAEX_19th_LowVis: OPAEX_19th_Random {
		displayName = "19th Low-Vis";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_Logo_LowVis.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_Logo_LowVis.paa";
	};
	class OPAEX_19th_Wayfinder: OPAEX_19th_Random {
		displayName = "Wayfinder";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_Wayfinder.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_Wayfinder.paa";
	};
	class OPAEX_19th_Wayfinder2: OPAEX_19th_Random {
		displayName = "Way 2";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2.paa";
	};
	class OPAEX_19th_Wayfinder2Black: OPAEX_19th_Random {
		displayName = "Way 2 Black";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2Black.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2Black.paa";
	};
	class OPAEX_19th_Wayfinder2Shadow: OPAEX_19th_Random {
		displayName = "Way 2 Shadow";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2Shadow.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2Shadow.paa";
	};
	class OPAEX_19th_Wayfinder3: OPAEX_19th_Random {
		displayName = "Way 3";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_Wayfinder3.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_Wayfinder3.paa";
	};
	class OPAEX_19th_Grif: OPAEX_19th_Random {
		displayName = "Grif approved";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_Grif.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_Grif.paa";
	};
	class OPAEX_19th_FenrirLowVis: OPAEX_19th_Random {
		displayName = "Fenrir low-vis";
		textures[] = {"\OPAEX_Sprays\sprays\19th\Spray_19_FenLowVis.paa"};
		icon = "\OPAEX_Sprays\sprays\19th\Spray_19_FenLowVis.paa";
	};
	
	//The ultimate random can.
	class OPAEX_Random: OPAEX_Logo_Random {
		displayName = "There is only random.";
		requiredItem = "OPAEX_RandomCan";
		textures[] = {
			"\OPAEX_Sprays\sprays\Spray_UNSC.paa",
			"\OPAEX_Sprays\sprays\Spray_UNSC_PostWar.paa",
			"\OPAEX_Sprays\sprays\Spray_Fist.paa",
			"\OPAEX_Sprays\sprays\Spray_GmodMissing.paa",
			"\OPAEX_Sprays\sprays\Spray_Spartanjackwar.paa",
			"\OPAEX_Sprays\sprays\Spray_Div7.paa",
			
			"\OPAEX_Sprays\sprays\ModLogos\Spray_OPAEX.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_A2S.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_DingusElement.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_BlackElement.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_TCF.paa",
			"\OPAEX_Sprays\sprays\ModLogos\Spray_OPCOS.paa",
			
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana.paa",
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pog.paa",
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pirate.paa",
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Pepe.paa",
			"\OPAEX_Sprays\sprays\Bananas\Spray_Banana_Knuckles.paa",
			
			"\OPAEX_Sprays\sprays\Chads\Spray_Chad1.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_Chad2.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_Chad3.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_Chad4.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ChadJohnson.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ChadKerensky.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ChadFocht.paa",
			
			"\OPAEX_Sprays\sprays\Chads\Spray_ODSTChadA.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ODSTChadB.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ODSTChadC.paa",
			"\OPAEX_Sprays\sprays\Chads\Spray_ODSTChadD.paa",
			
			"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Gnome.paa",
			"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Way3.paa",
			"\OPAEX_Sprays\sprays\Kilroy\Spray_Kilroy_Racoon.paa",
			
			"\OPAEX_Sprays\sprays\19th\Spray_19_FenLowVis.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_FenA.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_FenB.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Hoplite.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Hop1.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Hop2.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Logo.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Logo_LowVis.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Wayfinder.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2Black.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_WayFinder2Shadow.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Wayfinder3.paa",
			"\OPAEX_Sprays\sprays\19th\Spray_19_Grif.paa"
		};
	};
};