//Jack Moss, aka Spartanjackwar.
/*
This function spawns a vehicle, acting as a wrapper for BIS_fnc_spawnVehicle

Parameter 0: group: group to spawn unit to.  Must not be grpNull.
Parameter 1: string/object: classname of the unit who we spawn or actual object to get classname of.
Parameter 2: 3D array: position of unit spawn

Return: Object, objNull if failure.

Can be executed anywhere.
Can be executed in a nonscheduled environment.

Dependencies:
	OPAEX_D20_DebugMode, bool, which is a mission namespace variable.
*/

//Setup parameters
params [
	[
		"_group",
		grpNull,
		[grpNull]
	],
	[
		"_unitClassName",
		objNull,
		["", objNull]
	],
	[
		"_position",
		[0.0, 0.0, 0.0],
		[[0.0, 0.0, 0.0]]
	]
];

//Parse _unitClassName if it's an object
if (_unitClassName isEqualType objNull) then
{
	_unitClassName = typeOf _unitClassName;
};

//Validate we're not spawning CAManBase type.
//Note, we changed to using Man as the class to check so that animals work.
if (_unitClassName isKindOf "Man") exitWith
{
	[_group, _unitClassName, _position] call OPAEX_fnc_D20_SpawnUnit //we'll return this too.
};

//Validate the classname exists and group is not grpNull.
_inMasterConfig = isClass (configFile >> "CfgVehicles" >> _unitClassName);
_inMissionConfig = isClass (MissionConfigFile >> "CfgVehicles" >> _unitClassName);
if (not _inMasterConfig and not _inMissionConfig or isNull _group) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	objNull
};

//Create unit
_newUnit = objNull;
_newUnit = ([_position, (random 360), _unitClassName, _group] call BIS_fnc_spawnVehicle) select 0;

//Return unit reference
["OPAEX: function returned %1", _newUnit] call BIS_fnc_logFormat;
_newUnit //Return statement