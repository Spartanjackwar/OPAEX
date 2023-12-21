//================================================================================
//Sensors
class SensorsManagerComponent
{
	class Components
	{
		class IRSensorComponent: SensorTemplateIR
		{
			class AirTarget
			{
				minRange = 0;
				maxRange = 2000;
				objectDistanceLimitCoef = 1;
				viewDistanceLimitCoef = 1;
			};
			class GroundTarget
			{
				minRange = 0;
				maxRange = 2000;
				objectDistanceLimitCoef = 1;
				viewDistanceLimitCoef = 1;
			};
			maxTrackableSpeed = 600;
			animDirection = "Light_L";
			angleRangeHorizontal = 46;
			angleRangeVertical = 34;
			aimdown = -0.25;
			nightRangeCoef = 1.33;  //range increased by 33% at night
		};
		class VisualSensorComponent: SensorTemplateVisual
		{
			class AirTarget
			{
				minRange = 0;
				maxRange = 2000;
				objectDistanceLimitCoef = 1;
				viewDistanceLimitCoef = 1;
			};
			class GroundTarget
			{
				minRange = 0;
				maxRange = 2000;
				objectDistanceLimitCoef = 1;
				viewDistanceLimitCoef = 1;
			};
			maxTrackableSpeed = 600;
			animDirection = "Light_L";
			angleRangeHorizontal = 46;
			angleRangeVertical = 34;
			aimdown = -0.25;
			nightRangeCoef = 0.5;  //range halved at night
			maxFogSeeThrough= 0.95;  //approx. the normal visibility in fog
		};
		class ActiveRadarSensorComponent: SensorTemplateActiveRadar
		{
			componentType = "ActiveRadarSensorComponent";
			class AirTarget
			{
				minRange = 0;
				maxRange = 8000;
				objectDistanceLimitCoef = -1;
				viewDistanceLimitCoef = -1;
			};
			class GroundTarget
			{
				minRange = 0;
				maxRange = 8000;
				objectDistanceLimitCoef = -1;
				viewDistanceLimitCoef = -1;
			};
			maxTrackableSpeed = 1360; //was 600, note that this is m/s
			angleRangeHorizontal = 90; //was 180
			angleRangeVertical = 90; //was 90
			groundNoiseDistanceCoef = -1;
			maxGroundNoiseDistance = -1;
			minSpeedThreshold = 0; //m/s
			maxSpeedThreshold = 1000; //m/s
			aimDown = 30;
			animDirection = "Light_L";
			typeRecognitionDistance = 5000;
			minTrackableATL = 50;
		};
		class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
		{
			class AirTarget
			{
				minRange = 0;
				maxRange = 8000;
				objectDistanceLimitCoef = -1;
				viewDistanceLimitCoef = -1;
			};
			class GroundTarget
			{
				minRange = 0;
				maxRange = 8000;
				objectDistanceLimitCoef = -1;
				viewDistanceLimitCoef = -1;
			};
			maxTrackableSpeed = 1360;
			angleRangeHorizontal = 360; //was 180
			angleRangeVertical = 90;
			groundNoiseDistanceCoef = -1;
			maxGroundNoiseDistance = -1;
			minSpeedThreshold = 0;
			maxSpeedThreshold = 0;
			aimDown = 30;
			animDirection = "Light_L";
		};
		class LaserSensorComponent: SensorTemplateLaser
		{
		};
		class NVSensorComponent: SensorTemplateNV
		{
		};
	};
};
//================================================================================
//Displays
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