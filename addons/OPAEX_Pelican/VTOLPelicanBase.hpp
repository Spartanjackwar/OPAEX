class OPAEX_Pelican_VTOL_Base: OPTRE_Pelican_F
{
	#include<pelicanHUDVTOL.hpp>
	//===============================================================================================
	//Basics
	//===============================================================================================
	dlc = "OPAEX";
	scope = 0;
	author = "Spartanjackwar";
	displayName = "Pelican_base [VTOL]";
	simulation = "airplanex";
	
	#include<VTOLPelicanAerodynamics.hpp>
	#include<VTOLPelicanSounds.hpp>
	
	//===============================================================================================
	//Engine
	//===============================================================================================
	maxSpeed = 1138; //700;
	landingSpeed = 0;
	
	altNoForce = 100000; //Pelican is a spaceship lads, Karmen line or bust.
	altFullForce = 100000; //Fusion drives are powered by Deuterium and thus have no thrust losses.
	thrustCoef[] = {2};
	throttleToThrustLogFactor = 2;
	
	vtol = 4;
	maxOmega = 2000;
	
	//===============================================================================================
	//Visuals and Memory Points
	//===============================================================================================
	memoryPointLDust = "engine_4";
	memoryPointRDust = "engine_1";
	leftDustEffect = "LDustEffects";
	rightDustEffect = "RDustEffects";
	memoryPointLMissile = "Rocket_1";
	memoryPointRMissile = "Rocket_2";
	memoryPointGun = "kulomet"; //Not actually in the memory LOD.
	selectionRotorStill = "vrtule staticka"; //Not actually in the memory LOD.
	selectionRotorMove = "vrtule blur"; //Not actually in the memory LOD.
	
	lightOnGear = 0;
	headGforceLeaningFactor[] = {0.005, 0.001, 0.025};
	
	unitInfoType = "RscUnitInfoAirPlane";
	
	class WingVortices
	{
		class WingTipLeft
		{
			effectName = "WingVortices";
			position = "positionlight_red_1_pos";
		};
		class WingTipRight
		{
			effectName = "WingVortices";
			position = "positionlight_green_1_pos";
		};
	};
	
	//===============================================================================================
	//Miscellaneous
	//===============================================================================================
	minGunElev = 0;
	maxGunElev = 0;
	minGunTurn = 0;
	maxGunTurn = 0;
	gunAimDown = 0;
	
	steerAheadSimul = 1;
	steerAheadPlan = 2;
	wheelSteeringSensitivity = 0.7;
	brakeDistance = 500;
	
	//gearRetracting = 1;
	formationX = 100;
	formationZ = 100;
	
	cabinOpening = 1;
	getInRadius = 1.2;
	durationGetIn = 0.99;
	durationGetOut = 0.99;
	ejectSpeed[] = {0, 40, 0};
	ejectDamageLimit = 0.45;
	
	numberPhysicalWheels = 3;
	fuelExplosionPower = 10;
	epeImpulseDamageCoef = 10;
	
	class Turrets: Turrets {};
	class UserActions: UserActions {	
		class ThrusterEngage: ThrusterEngage
		{
			condition = "false";
		};
		class ThrusterDisengage: ThrusterDisengage
		{
			condition = "false";
		};
		class AirbrakeEngage: AirbrakeEngage
		{
			condition = "false";
		};
	};
};
class OPAEX_Pelican_VTOL: OPAEX_Pelican_VTOL_Base
{
	displayName = "D77H-TCI Pelican [VTOL]";
	author = "Spartanjackwar";
	scope = 2;
	scopeCurator = 2;
	scopeArsenal = 2;
	side = 1;
	vehicleClass = "OPTRE_UNSC_Air_class";
	faction = "OPTRE_UNSC";
	crew = "OPTRE_UNSC_Airforce_Soldier_Airman";
	
	accuracy = 1.5;
	availableForSupportTypes[] = {"Drop", "Transport"};
};
class OPAEX_Pelican_VTOL_Marine: OPAEX_Pelican_VTOL
{
	displayName = "D77H-TCI Pelican [VTOL] (Marine)";
	author = "Spartanjackwar";
	scope = 1;
	scopeCurator = 1;
	scopeArsenal = 1;
	crew = "OPTRE_UNSC_Marine_Pilot";
	
	hiddenSelectionsTextures[] = {"OPTRE_Vehicles\Pelican\data\PelicanExterior_Marine_CO.paa", ""};
};
class OPAEX_Pelican_VTOL_Green: OPAEX_Pelican_VTOL
{
	displayName = "D77H-TCI Pelican [VTOL] (Green)";
	author = "Spartanjackwar";
	scope = 1;
	scopeCurator = 1;
	scopeArsenal = 1;

	hiddenSelectionsTextures[] = {"OPTRE_Vehicles\Pelican\data\PelicanExterior_green_CO.paa", ""};
};
