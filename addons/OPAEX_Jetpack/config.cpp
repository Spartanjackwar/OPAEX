class CfgPatches
{
	class OPAEX_Jetpack
	{
		author = "Spartanjackwar";
		authors[] = {"Spartanjackwar"};
 		requiredAddons[] = {
			"Extended_EventHandlers"
		};
		requiredVersion=0.1;
		units[]={};
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
		class Jetpack
		{
			file = "OPAEX_Functions\GlassingBeam";
			
		};
	};
};

class Extended_PreInit_EventHandlers {
	class OPAEX_ExecutionFlow {
		//Emergency variable used to stop all asynchronousExecutionLoops at any given time.
		init = "missionNamespace setVariable [""OPAEX_EmergencyStopAsyncLoops"", false, true];";
	};
};

class CfgVehicles
{
	//#include<modules.hpp>
};



