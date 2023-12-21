//Jack Moss, aka Spartanjackwar.
/*
Parses a config passed in for D20 logic.  This results in appending to lists and checks for mod dependencies.

Parameter 0: string: classname to retrieve from cfgMagazines for analysis.

Return: Array of strings, which represent the names of scripts to be called.

Must be executed in nonscheduled environment.
Can be executed anywhere.
*/

//Setup parameters
params [
	[
		"_currentD20",
		"",
		[""]
	]
];

private[
	"_CurrentD20Scripts",
	"_globalScriptsClasses",
	"_dependencyList",
	"_dependencyMissing",
	"_exists",
	"_itemScripts"
];
_CurrentD20Scripts = [];

//Check global config for the addition.
_globalScriptsClasses = (ConfigFile >> "cfgMagazines" >> _currentD20 >> "OPAEX_D20_Scripts") call BIS_fnc_getCfgSubClasses;

//Check dependencies of each script component class.
{
	//Get dependencies
	_dependencyList = (ConfigFile >> "cfgMagazines" >> _currentD20 >> "OPAEX_D20_Scripts" >> _x >> "Dependencies") call BIS_fnc_getCfgDataArray;
	_dependencyMissing = False;
	
	{//Check dependency patch exists
		_exists = (configFile >> "CfgPatches" >> _x) call BIS_fnc_getCfgIsClass;
		if (not _exists) exitWith {_dependencyMissing = True;};
	} forEach _dependencyList;
	
	//Retrieve scripts from item if dependencies are not missing
	if (not _dependencyMissing) then {
		_itemScripts = (ConfigFile >> "cfgMagazines" >> _currentD20 >> "OPAEX_D20_Scripts" >> _x >> "Scripts") call BIS_fnc_getCfgDataArray;
		{_CurrentD20Scripts pushBack _x} forEach _itemScripts;
	};
} forEach _globalScriptsClasses;

//Return list of scripts for the global list
_CurrentD20Scripts;