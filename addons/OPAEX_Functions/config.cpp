class CfgPatches
{
	class OPAEX_Functions
	{
		author = "Spartanjackwar";
		authors[] = {"Spartanjackwar"};
 		requiredAddons[] = {
			"OPAEX_Core", "A3_Modules_F", "Extended_EventHandlers" //requiring CBA now!
		};
		requiredVersion=0.1;
		units[]={
			"OPAEX_CryoBomb_Module",
			"OPAEX_DisruptorBomb_Module",
			"OPAEX_IlluminationBomb_Module"
		};
		weapons[]={};
	};
};

/*
Function class is of the following form:
class FolderName
{
	file = "filepath_to_folder_here";
	class function_Name{};
	class second_function_Name{};
};
*/
class CfgFunctions 
{
	class OPAEX
	{
		class GlassingBeam
		{
			file = "OPAEX_Functions\GlassingBeam";
			class GlassingBeam {};
			class GlassingBeam_ClientEffects {};
			class GlassingBeam_ServerEffects {};
			class GlassingBeam_Module {};
		};
		class BoundingBoxes
		{
			file = "\OPAEX_Functions\BoundingBoxes";
			class IsBoundingBoxContained{};
			class GetBoundingBoxTopCenter{};
			class GetBoundingBoxDimensions{};
			class GetBoundingBoxDimensionsOffset{};
			class GetBoundingBoxWorld{};
			class DrawBoundingBox{};
			class TimedDrawBoundingBox{};
		};
		class Timer
		{
			file = "\OPAEX_Functions\Timer";
			class Timer{};
		};
		class PelicanMagLiftSystem
		{
			file = "\OPAEX_Functions\PelicanMagLiftSystem";
			//class PelicanLoadValidate{};
			//class PelicanUnLoadValidate{};
		};
		class Spartan_Laser
		{
			file = "\OPAEX_Functions\Spartan_Laser";
			class ChargedWeaponController {};
			class Extended_InitPost_splaser {};
			class ShowClientChargeStatus {};
			class splaserChargeVisuals {};
			class splaserChargeVisualsStop {};
			class TriggerClientFire {};
			class stopFireAction {};
			class hasStopAction {};
			class GetChargingStatus {};
		};
		class Particles
		{
			file = "\OPAEX_Functions\Particles";
			//class setParticleArray{};
		};
		class Aircore_Weapons
		{
			file = "\OPAEX_Functions\Aircore_Weapons";
			class Mk127{}; //Named for the M127A1
			class Mk127_Module{};
			class Mk127_ServerEffects{};
			class Mk127_ClientEffects{};
			
			class CryoBomb{};
			class CryoBomb_Module{};
			class CryoBomb_ServerEffects{};
			class CryoBomb_ClientEffects{};
			class CryoBomb_WeaponMethod{};
			
			class DisruptorBomb{};
			class DisruptorBomb_Module{};
			class DisruptorBomb_ServerEffects{};
			class DisruptorBomb_ClientEffects{};
			
			class EMP{};
		};
		class Utilities_Communication
		{
			file = "\OPAEX_Functions\Utilities_Communication";
			class RemoteSay3D{};
			class RemoteSystemChat{};
			class AddonChecker{};
			class AddonCheckerOptions{};
			class AddonCheckerFetchAll{};
		};
		class Utilities_Debug
		{
			file = "\OPAEX_Functions\Utilities_Debug";
			class Debug_Error_InputRules {};
			class Debug_Error_RunCondition {};
		};
		class Utilities_Draw
		{
			file = "\OPAEX_Functions\Utilities_Draw";
			//SoonTM.
		};
		class Utilities_ObjectManipulation
		{
			file = "\OPAEX_Functions\Utilities_ObjectManipulation";
			class CopyPasteObjectMotion {};
			class CopyPasteObjectMotionWithOffset {};
			class GetSelectionPosition {};
			class GetPrimaryWeaponPosition {};
			class GetSecondaryWeaponPosition {};
			class GetTertiaryWeaponPosition {};
			class GetCurrentWeaponPosition {};
			class animateTexture {};
			class animateTextureLooped {};
			class getMuzzleOffsetFromWeaponProxy {};
		};
		class Utilities_EventHandlers
		{
			file = "\OPAEX_Functions\Utilities_EventHandlers";
			class GetScriptedHandlerList{};
			class HasEventHandler{};
			class PasteObjectVariables{};
		};
		class Utilities_Gear
		{
			file = "\OPAEX_Functions\Utilities_Gear";
			class ClearUnitGear{};
			class PasteUnitGear{};
			class SubStringInUnitGear{};
		};
		class Utilities_Math {
			file = "\OPAEX_Functions\Utilities_Math";
			//Outline shape getters
			class Terrain_Circle {};
			class Terrain_HalfCircle {};
			class Terrain_Line {};
			class Terrain_LineVertical {};
			
			//Filled shape getters
			class TerrainFilled_Rectangle {};
			class TerrainFilled_Circle {};
			class TerrainFilled_HalfCircle {};
			
			class Terrain_Alt {};
		};
		class Utilities_ExecutionFlow
		{
			file = "\OPAEX_Functions\Utilities_ExecutionFlow";
			class asynchronousExecutionLoop{};
		};
		class Utilities_Skeleton
		{
			file = "\OPAEX_Functions\Utilities_Skeleton";
			class GetSkeleton{};
			class ServerInit_SkeletonSwapHandlers{};
			class SkeletonSwapHandlers{};
			class SwapPlayerSkeleton{};
			class SwapPlayerUnit{};
			class GetUnitIDInGroup{}; //May need to make a new category for this one.
		};
		class Grapple
		{
			file = "\OPAEX_Functions\Grapple";
			class InitGrappleSystem {};
			class Grapple_PullTarget {};
		};
		class D20
		{
			file = "\OPAEX_Functions\D20";
			class D20_Fired {};
			class D20_Fired_Particles {};
		};
		class D20_Core
		{
			file = "\OPAEX_Functions\D20\D20CoreScripts";
			class D20_AddClassEventHandler {};
			//class D20_InitVariables {preInit = 1;};
			class D20_InitVariables {};
			class D20_InitD20ScriptList {};
			class D20_ParseConfig {};
			class D20_RandomSelector {};
			class D20_SpawnCluster {};
			class D20_SpawnClusterD20 {};
			class D20_SpawnMinefield {};
			class D20_SpawnSimpleObject {};
			class D20_SpawnUnit {};
			class D20_SpawnVehicle {};
			class D20_SpawnVehicleEmpty {};
			class D20_TeleportThrower {};
			class D20_IsMagazineAD20 {};
			
			class D20Visuals_Party {};
			class D20Visuals_Strike {};
			class D20Visuals_Yeet {};
			class D20Visuals_Heal {};
			class D20Visuals_BananaWall {};
			
			class lightning {};
			class StringToFunction {};
			class GetHighestRankingAI {};
			class GetHighestRankingPlayer {};
			class GetHighestRankingUnit {};
			class GetNextScoringPlayer {};
			class DebugD20ScriptList {};
		};
		class D20_Vanilla
		{
			file = "\OPAEX_Functions\D20\D20VanillaScripts";
			class D20Roll_40mmExplosive {};
			class D20Roll_40mmFlares {};
			class D20Roll_APCFriendly {};
			class D20Roll_APCHostile {};
			class D20Roll_ATMines {};
			class D20Roll_BananaSmoke {};
			class D20Roll_BoundingMines {};
			class D20Roll_Cessna {};
			class D20Roll_Chemlights {};
			class D20Roll_ClusterBomb {};
			class D20Roll_ClusterGrenade {};
			class D20Roll_ClusterD20 {};
			class D20Roll_DestroyBuildingsInRadius {};
			class D20Roll_DropThrowerWithoutChute {};
			class D20Roll_DropWeapons {};
			class D20Roll_ECMgrenade {};
			class D20Roll_Enderpearl {};
			class D20Roll_FireteamFriendly {};
			class D20Roll_FireteamHostile {};
			class D20Roll_Harmless {};
			class D20Roll_HealGrenade {};
			class D20Roll_LightningPlayers {};
			class D20Roll_Mines {};
			class D20Roll_SmokeGrenades {};
			class D20Roll_Snap {};
			class D20Roll_Trees {};
			class D20Roll_Yeetback {};
			class D20Roll_TruckKun {};
			class D20Roll_RedShell {};
			class D20Roll_BlueShell {};
			class D20Roll_Animal {};
			class D20Roll_Carrier {};
			class D20Roll_Destroyer {};
			class D20Roll_DropGear {};
			class D20Roll_Kart {};
			class D20Roll_Submarine {};
			class D20Roll_Sofa {};
			class D20Roll_RGBMan {};
		};
		class D20_OPTRE
		{
			file = "\OPAEX_Functions\D20\D20OPTREScripts";
			class D20Roll_ElephantEmpty {};
			class D20Roll_Forklift {};
			class D20Roll_MAC {};
			class D20Roll_Towcart {};
			class D20Roll_WarthogEmpty {};
			class D20Roll_BananaGod {};
			class D20Roll_APCFriendlyOryx {};
			class D20Roll_APCHostileOryx {};
			class BarrierGun {};
			class FusionCoilGun {};
			class D20Roll_DropBarrierGun {};
			class D20Roll_DropFusionCoilGun {};
			class D20Roll_FireteamFriendly_UNSC {};
			class D20Roll_FireteamHostile_UNSC {};
		};
		class D20_OPTREFC
		{
			file = "\OPAEX_Functions\D20\D20OPTREFCScripts";
			class D20Roll_Banshee {};
			class D20Roll_EliteFireteam {};
			class D20Roll_ElitePair {};
			class D20Roll_EliteVespade {};
			class D20Roll_RedvsBlueLiterally {};
			class D20Roll_SpartanFriendly {};
			class D20Roll_SpartanHostile {};
		};
		class D20_OPAEX
		{
			file = "\OPAEX_Functions\D20\D20OPAEXScripts";
			class D20Roll_CryoBomb {};
			class D20Roll_IlluminationBomb {};
			class D20Roll_DisruptionBomb {};
			class D20Roll_GlassingBeam {};
		};
	};
};

//REQUIRES CBA
class Extended_GetIn_EventHandlers {
	class OPTRE_Pelican_F
    {
        class OPAEX_Gmeter
        {
			GetIn = "[] spawn OPAEX_fnc_G";
        };
    };
	/*
	class OPAEX_Pelican_VTOL_Base
    {
        class OPAEX_Gmeter
        {
			GetIn = "[] spawn OPAEX_fnc_G";
        };
    };
	*/
	class OPAEX_VTOL_Hornet_base
    { //Doesn't link to OPTRE_Hornet_base yet, so it's necessary to specify.
        class OPAEX_Gmeter
        {
			GetIn = "[] spawn OPAEX_fnc_G";
        };
    };
	class OPTRE_Hornet_base
    {
        class OPAEX_Gmeter
        {
			GetIn = "[] spawn OPAEX_fnc_G";
        };
    };
	class OPTRE_falcon_base
    {
        class OPAEX_Gmeter
        {
			GetIn = "[] spawn OPAEX_fnc_G";
        };
    };
};

class Extended_PreInit_EventHandlers {
	class OPAEX_D20_Options {
		init = "call OPAEX_fnc_D20_InitVariables";
	};
	class OPAEX_Skeleton_Options {
		init = "call OPAEX_fnc_ServerInit_SkeletonSwapHandlers";
	};
	class OPAEX_Grapple {
		//init = "[] call OPAEX_fnc_InitGrappleSystem";
	};
	class OPAEX_ExecutionFlow {
		//Emergency variable used to stop all asynchronousExecutionLoops at any given time.
		init = "missionNamespace setVariable [""OPAEX_EmergencyStopAsyncLoops"", false, true];";
	};
	class OPAEX_AddonChecker_Options {
		init = "call OPAEX_fnc_AddonCheckerOptions";
	};
};

class CfgVehicles
{
	#include<modules.hpp>
};
