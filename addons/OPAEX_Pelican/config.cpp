//Pelican Pylon project

class CfgPatches
{
 	class OPAEX_Pelican
 	{
		addonRootClass = "OPAEX";
		author = "Spartanjackwar";
		requiredAddons[] = {
			"A3_Weapons_F", "OPAEX_Core", "OPTRE_Core", "OPTRE_Vehicles",
			"OPAEX_Aircore",
			"OPTRE_Vehicles_Pelican", //Without this, magazines are duplicated.
		};
 		units[] = {
			"OPAEX_Pelican_VTOL_Base", "OPAEX_Pelican_VTOL_Armed_Base",
			"OPAEX_Pelican_VTOL_Armed", "OPAEX_Pelican_VTOL_Armed_Marine",
			"OPAEX_Pelican_VTOL_Armed_Green", "OPAEX_Pelican_VTOL",
			"OPAEX_Pelican_VTOL_Marine", "OPAEX_Pelican_VTOL_Green"
		};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
 		requiredVersion = 0.1;
 	};
};

//----------------------------------------------------------------------
//ROOT EXTERNALS
//These are found in the root of the config and thus declared here.
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateActiveRadar;
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateLaser;
class SensorTemplateNV;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class Components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class Components;
};
class CargoTurret;
//----------------------------------------------------------------------

class cfgVehicles
{
	//EXTERNALS
	class All{};
	class Static: All{};
	class Helicopter;
	class Helicopter_Base_F: Helicopter
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
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class EventHandlers;
		class Turrets: Turrets
		{
			class CopilotTurret;
		};
		class HitPoints: HitPoints
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
	class OPTRE_Pelican_F: Helicopter_Base_H {
		class Turrets : Turrets {
			class CopilotTurret;
		};
		class UserActions
		{
			class ThrusterEngage;
			class ThrusterDisengage;
			class AirbrakeEngage;
		};
	};
	#include<VTOLPelicanBase.hpp>
	#include<VTOLPelicanBaseArmed.hpp>
};
