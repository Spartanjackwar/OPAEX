//Custom sub-class which holds more sub-classes who hold arrays of each script.
class OPAEX_D20_Scripts
{//Sub-classes will be parsed by OPAEX_fnd_D20_InitVariables.  Refer there for further documentation.
	/*
	class Custom_D20_Example
	{
		//Each script set sub-class holds an array which is checked as Dependencies.
		Dependencies[] = {
			"OPTRE_FC_Core" //This checks cfgPatches >> OPTRE_FC_Core exists.
		};
		
		//Actual array of script names.
		scripts[] = {
			"Example_fnc_CustomScriptEvent1",
			"Example_fnc_CustomScriptEvent2"
		};
	};
	*/
	
	class OPAEX_D20_Vanilla
	{
		Dependencies[] = {
			//Intentionally empty.
		};
		Scripts[] = {
			//20 CSAT or BLUFOR depending on thrower side.
			"OPAEX_fnc_D20Roll_FireteamHostile",
			"OPAEX_fnc_D20Roll_FireteamFriendly",
			
			//APC on CSAT or BLUFOR depending on thrower side.
			"OPAEX_fnc_D20Roll_APCHostile",
			"OPAEX_fnc_D20Roll_APCFriendly",
			
			//It's an enderpearl from the popular game Minecraft.
			"OPAEX_fnc_D20Roll_Enderpearl",
			
			//Spawns a cessna on the grenade position.
			"OPAEX_fnc_D20Roll_Cessna",
			
			//Spawns a group of trees.
			"OPAEX_fnc_D20Roll_Trees",
			
			//It's self-explaining.
			"OPAEX_fnc_D20Roll_ClusterGrenade",
			"OPAEX_fnc_D20Roll_LightningPlayers",
			"OPAEX_fnc_D20Roll_DestroyBuildingsInRadius",
			"OPAEX_fnc_D20Roll_DropWeapons",
			"OPAEX_fnc_D20Roll_DropGear",
			"OPAEX_fnc_D20Roll_Harmless",
			"OPAEX_fnc_D20Roll_DropThrowerWithoutChute",
			"OPAEX_fnc_D20Roll_HealGrenade",
			"OPAEX_fnc_D20Roll_ClusterBomb",
			"OPAEX_fnc_D20Roll_ClusterD20",
			"OPAEX_fnc_D20Roll_TruckKun",
			"OPAEX_fnc_D20Roll_Kart",
			"OPAEX_fnc_D20Roll_Sofa",
			"OPAEX_fnc_D20Roll_RGBMan",
			
			//Throws the D20 back at you.
			"OPAEX_fnc_D20Roll_Yeetback",
			
			//It's thanos' snap, but it only hits players.
			"OPAEX_fnc_D20Roll_Snap",
			
			//Deploys bananas as a very short smoke screen.
			"OPAEX_fnc_D20Roll_BananaSmoke",
			
			//Throws countermeasures into the area.
			"OPAEX_fnc_D20Roll_ECMgrenade",
			
			//UGL rounds tossed around.
			"OPAEX_fnc_D20Roll_40mmFlares",
			"OPAEX_fnc_D20Roll_40mmExplosive",
			
			//Each smoke grenade tossed around
			"OPAEX_fnc_D20Roll_SmokeGrenades",
			
			//Chemlights of all colors thrown around
			"OPAEX_fnc_D20Roll_Chemlights",
			
			//Deploys a minefield of mines. Yes, the minefield is made of mines.
			"OPAEX_fnc_D20Roll_BoundingMines",
			"OPAEX_fnc_D20Roll_ATMines",
			"OPAEX_fnc_D20Roll_Mines",
			
			//Targets people based on rank and score anywhere on map.
			"OPAEX_fnc_D20Roll_BlueShell",
			"OPAEX_fnc_D20Roll_RedShell",
			
			//Spawns animals
			"OPAEX_fnc_D20Roll_Animal",
			
			//Spawns boats
			//"OPAEX_fnc_D20Roll_Carrier",
			//"OPAEX_fnc_D20Roll_Destroyer",
			"OPAEX_fnc_D20Roll_Submarine"
		};
	};
	
	class OPAEX_D20_OPTRE
	{
		Dependencies[] = {
			"OPTRE_Core"
		};
		Scripts[] = {
			"OPAEX_fnc_D20Roll_BananaGod",
			"OPAEX_fnc_D20Roll_Forklift",
			"OPAEX_fnc_D20Roll_Towcart",
			"OPAEX_fnc_D20Roll_WarthogEmpty",
			"OPAEX_fnc_D20Roll_ElephantEmpty",
			"OPAEX_fnc_D20Roll_MAC",
			"OPAEX_fnc_D20Roll_APCHostileOryx",
			"OPAEX_fnc_D20Roll_APCFriendlyOryx",
			"OPAEX_fnc_D20Roll_DropFusionCoilGun",
			"OPAEX_fnc_D20Roll_DropBarrierGun",
			"OPAEX_fnc_D20Roll_FireteamFriendly_UNSC",
			"OPAEX_fnc_D20Roll_FireteamHostile_UNSC"
		};
	};
	
	class OPAEX_D20_OPTREFC
	{
		Dependencies[] = {
			"OPTRE_FC_Core"
		};
		Scripts[] = {
			"OPAEX_fnc_D20Roll_Banshee",
			"OPAEX_fnc_D20Roll_EliteFireteam",
			"OPAEX_fnc_D20Roll_ElitePair",
			"OPAEX_fnc_D20Roll_EliteVespade",
			"OPAEX_fnc_D20Roll_SpartanHostile",
			"OPAEX_fnc_D20Roll_SpartanFriendly",
			"OPAEX_fnc_D20Roll_RedvsBlueLiterally"
		};
	};
	
	class OPAEX_D20_OPAEX
	{
		Dependencies[] = {
			"OPAEX_Core"
		};
		Scripts[] = {
			"OPAEX_fnc_D20Roll_CryoBomb",
			"OPAEX_fnc_D20Roll_IlluminationBomb",
			"OPAEX_fnc_D20Roll_DisruptionBomb",
			"OPAEX_fnc_D20Roll_GlassingBeam"
		};
	};

};
