//===============================================================================================
//Sound
//===============================================================================================
class Sounds
{
	class EngineLowOut
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_engine_idle_ext", 1, 1, 2100};
		frequency = "1.0 min (rpm + 0.5)";
		volume = "camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
	};
	class EngineHighOut
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_engine_max_ext", 1, 1.2, 2500};
		frequency = 1;
		volume = "camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
	};
	class ForsageOut
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_forsage_ext", 1.41254, 1.2, 2800};
		frequency = "1";
		volume = "engineOn*camPos*(thrust factor[0.4, 1.0])";
		cone[] = {3.14, 3.92, 2, 0.5};
	};
	class TurbineOut
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_turbine_ext", 1, 1, 1800};
		frequency = "rpm * (thrust/4 + 0.5)";
		volume = "camPos * 2 * rpm * thrust * (rpm factor[0, 0.4])";
	};
	class TurbineHighOut
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_turbine_ext", 1, 1, 1800};
		frequency = "1.7 * (rpm factor[-5,1])";
		volume = "0.8 * camPos * (rpm factor[-1,1]) * (rpm factor[0, 0.4])";
	};
	class WindNoiseOut
	{
		sound[] = {"A3\Sounds_F_EPC\CAS_02\noise", 0.562341, 1, 150};
		frequency = "(0.1+(1.2*(speed factor[1, 150])))";
		volume = "camPos*(speed factor[1, 150])";
	};
	class EngineLowInt
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_engine_idle_int", 0.630957, 1, 2100};
		frequency = "1.0 min (rpm + 0.5)";
		volume = "(1-camPos)*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
	};
	class EngineHighInt
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_engine_max_int", 0.630957, 1.2, 2500};
		frequency = 1;
		volume = "(1-camPos)*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
	};
	class ForsageInt
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_forsage_int", 0.794328, 1.2, 2800};
		frequency = "1";
		volume = "engineOn*(1-camPos)*(thrust factor[0.4, 1.0])";
		cone[] = {3.14, 3.92, 2, 0.5};
	};
	class TurbineInt
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_turbine_int", 0.630957, 1, 1800};
		frequency = "rpm * (thrust/4 + 0.5)";
		volume = "(1-camPos) * 2 * rpm * thrust * (rpm factor[0, 0.4])";
	};
	class TurbineHighInt
	{
		sound[] = {"A3\Sounds_F_Exp\vehicles\air\VTOL_02\VTOL_02_turbine_int", 0.630957, 1, 1800};
		frequency = "1.7 * (rpm factor[-5,1])";
		volume = "0.8 * (1-camPos) * (rpm factor[-1,1]) * (rpm factor[0, 0.4])";
	};
	class scrubLandInt
	{
		sound[] = {"A3\Sounds_F\vehicles\air\noises\wheelsInt", 1, 1, 100};
		frequency = 1;
		volume = "2 * (1-camPos) * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
	};
	class scrubLandExt
	{
		sound[] = {"A3\Sounds_F\dummysound", 1, 1, 100};
		frequency = 1;
		volume = "camPos * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
	};
	class RainExt
	{
		sound[] = {"A3\Sounds_F\vehicles\noises\rain1_ext", 1.77828, 1, 100};
		frequency = 1;
		volume = "camPos * rain * (speed factor[50, 0])";
	};
	class RainInt
	{
		sound[] = {"A3\Sounds_F\vehicles\noises\rain1_int", 1, 1, 100};
		frequency = 1;
		volume = "(1-camPos) * rain * (speed factor[50, 0])";
	};
	class WindInt
	{
		sound[] = {"A3\Sounds_F\vehicles\air\noises\wind_closed", 0.562341, 1, 50};
		frequency = 1;
		volume = "(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
	};
	class GStress
	{
		sound[] = {"A3\Sounds_F\vehicles\noises\vehicle_stress2c", 1.99526, 1, 50};
		frequency = 1;
		volume = "engineOn * (1-camPos) * (gmeterZ factor[1.0, 2.5])";
	};
	class SpeedStress
	{
		sound[] = {"A3\Sounds_F\vehicles\noises\vehicle_stress3", 0.501187, 1, 50};
		frequency = 1;
		volume = "(1-camPos)*(speed factor[60,80])";
	};
};