class OPAEX_Pelican_VTOL_Armed_Base: OPAEX_Pelican_VTOL_Base
{
	displayName = "D77H-TCI/AV Pelican [VTOL]";
	
	hiddenSelections[] = {"camo1", "camo3", "clan", "clan_text", "insignia"};
	
	class Turrets: Turrets
	{
		class CopilotTurret: CopilotTurret
		{
			gunnerAction = "pilot_Heli_Light_02";
			gunnerInAction = "pilot_Heli_Light_02";
			precisegetinout = 1;
			gunnerGetInAction = "pilot_Heli_Light_02_Enter";
			gunnerGetOutAction = "pilot_Heli_Light_02_Exit";
			memoryPointsGetInGunner = "Pos_Gunner";
			memoryPointsGetInGunnerDir = "Pos_Gunner_dir";
			canEject = 1;
			body = "mainTurret";
			gun = "mainGun";
			gunAxis = "Osa Hlavne";
			gunBeg = "Usti hlavne";
			gunEnd = "konec hlavne";
			animationSourceBody = "mainTurret";
			animationSourceGun = "mainGun";
			gunnerLeftHandAnimName = "";
			gunnerRightHandAnimName = "";
			maxHorizontalRotSpeed = 5;
			maxVerticalRotSpeed = 5;
			proxyindex = 1;
			isCopilot = 1;
			gunnerName = "Gunner";
			primaryGunner = 1;
			visionMode[] = {"Normal", "NVG", "Ti"};
			weapons[] = {"OPTRE_M638", "CMFlareLauncher", "Laserdesignator_mounted"};
			magazines[] = {"2000Rnd_20mm_shells", "2000Rnd_20mm_shells", "168Rnd_CMFlare_Chaff_Magazine", "Laserbatteries"};
			minElev = -90;
			maxElev = 30;
			initElev = 0;
			minTurn = -180;
			maxTurn = 180;
			initTurn = 0;
			stabilizedInAxes = "StabilizedInAxesBoth";
			startEngine = 0;
			class Viewoptics
			{
				minAngleX = -80;
				maxAngleX = 80;
				initAngleX = 0;
				minAngleY = -80;
				maxAngleY = 15;
				initAngleY = 0;
				initFov = 0.75;
				minFov = 0.25;
				maxFov = 0.75;
				visionMode[] = {"Normal", "NVG", "Ti"};
			};
			class OpticsIn
			{
				class Wide
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.466;
					minFov = 0.466;
					maxFov = 0.466;
					opticsDisplayName = "W";
					visionMode[] = {"Normal", "NVG", "Ti"};
					thermalMode[] = {0, 1};
					gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
				};
				class Medium: Wide
				{
					initFov = 0.093;
					minFov = 0.093;
					maxFov = 0.093;
					opticsDisplayName = "M";
					gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
				};
				class Narrow: Wide
				{
					initFov = 0.029;
					minFov = 0.029;
					maxFov = 0.029;
					opticsDisplayName = "N";
					gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
				};
			};
			class OpticsOut
			{
				class Monocular
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					minFov = 0.25;
					maxFov = 1.25;
					initFov = 0.75;
					visionMode[] = {"Normal", "NVG"};
					gunnerOpticsModel = "";
					gunnerOpticsEffect[] = {};
				};
			};
			class Components
			{
				class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
				{
					class Components: Components
					{
						class VehiclePrimaryGunnerDisplay
						{
							componentType = "TransportFeedDisplayComponent";
							source = "PrimaryGunner";
						};
						class VehicleMissileDisplay
						{
							componentType = "TransportFeedDisplayComponent";
							source = "Missile";
						};
						class SensorDisplay
						{
							componentType = "SensorsDisplayComponent";
							range[] = {4000, 2000, 16000, 8000};
							resource = "RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
				{
					defaultDisplay = "SensorDisplay";
					class Components: Components
					{
						class VehiclePrimaryGunnerDisplay
						{
							componentType = "TransportFeedDisplayComponent";
							source = "PrimaryGunner";
						};
						class VehicleMissileDisplay
						{
							componentType = "TransportFeedDisplayComponent";
							source = "Missile";
						};
						class SensorDisplay
						{
							componentType = "SensorsDisplayComponent";
							range[] = {4000, 2000, 16000, 8000};
							resource = "RscCustomInfoSensors";
						};
					};
				};
			};
			soundServo[] = {"", 0.01, 1};
			outGunnerMayFire = 1;
			commanding = -1;
			memoryPointGunnerOptics = "gunner1";
			selectionFireAnim = "";
			castGunnerShadow = 0;
			viewGunnerShadow = 0;
			turretAxis = "axisturret1";
			gunnerOpticsModel = "";
			gunnerOpticsEffect[] = {"TankCommanderOptics1", "BWTV"};
			gunnerForceOptics = 0;
			turretInfoType = "RscOptics_Heli_Attack_01_gunner";
			discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 1000, 1200, 1500, 1800, 2100};
			discreteDistanceInitIndex = 5;
			showAllTargets = 4;
		};
		class CargoTurret_01: CargoTurret
		{
			gunnerAction = "passenger_inside_2";
			gunnerCompartments = "Compartment2";
			memoryPointsGetInGunner = "pos_cargo_l";
			memoryPointsGetInGunnerDir = "pos_cargo_l_dir";
			gunnerName = "Passenger (Left door)";
			proxyIndex = 1;
			maxElev = 15;
			minElev = -25;
			maxTurn = 10;
			minTurn = -50;
			isPersonTurret = 1;
			ejectDeadGunner = 0;
			enabledByAnimationSource = "cargoDoors";
			memoryPointGunnerOptics = "";
		};
		class CargoTurret_02: CargoTurret_01
		{
			gunnerAction = "passenger_inside_2";
			gunnerCompartments = "Compartment2";
			memoryPointsGetInGunner = "pos_cargo_r";
			memoryPointsGetInGunnerDir = "pos_cargo_r_dir";
			gunnerName = "Passenger (Right door)";
			proxyIndex = 2;
			maxElev = 15;
			minElev = -25;
			maxTurn = 50;
			minTurn = -10;
			isPersonTurret = 1;
			ejectDeadGunner = 0;
			enabledByAnimationSource = "cargoDoors";
			memoryPointGunnerOptics = "";
		};
	};
};

class OPAEX_Pelican_VTOL_Armed: OPAEX_Pelican_VTOL_Armed_Base
{
	displayName = "D77H-TCI/AV Pelican [VTOL]";
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
class OPAEX_Pelican_VTOL_Armed_Marine: OPAEX_Pelican_VTOL_Armed
{
	displayName = "D77H-TCI/AV Pelican [VTOL] (Marine)";
	author = "Spartanjackwar";
	scope = 1;
	scopeCurator = 1;
	scopeArsenal = 1;
	crew = "OPTRE_UNSC_Marine_Pilot";
	
	hiddenSelectionsTextures[] = {"OPTRE_Vehicles\Pelican\data\PelicanExterior_Marine_CO.paa", ""};
};
class OPAEX_Pelican_VTOL_Armed_Green: OPAEX_Pelican_VTOL_Armed
{
	displayName = "D77H-TCI/AV Pelican [VTOL] (Green)";
	author = "Spartanjackwar";
	scope = 1;
	scopeCurator = 1;
	scopeArsenal = 1;

	hiddenSelectionsTextures[] = {"OPTRE_Vehicles\Pelican\data\PelicanExterior_green_CO.paa", ""};
};
