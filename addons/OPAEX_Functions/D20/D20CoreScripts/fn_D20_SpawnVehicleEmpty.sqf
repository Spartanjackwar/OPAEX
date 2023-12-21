//Jack Moss, aka Spartanjackwar.
/*
This function spawns a vehicle, acting as a wrapper for createVehicle

Parameter 0: string/object: classname of the unit who we spawn or actual object to get classname of.
Parameter 1: 3D array: position of unit spawn

Return: Object, objNull if failure.

Can be executed anywhere.
Can be executed in a nonscheduled environment.

Dependencies:
	OPAEX_D20_DebugMode, bool, which is a mission namespace variable.
*/

//Setup parameters
params [
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
if (_unitClassName isKindOf "CAManBase") exitWith
{
	[] call OPAEX_fnc_Debug_Error_InputRules;
	objNull
};

//Validate the classname exists and group is not grpNull.
_inMasterConfig = isClass (configFile >> "CfgVehicles" >> _unitClassName);
_inMissionConfig = isClass (MissionConfigFile >> "CfgVehicles" >> _unitClassName);
if (not _inMasterConfig and not _inMissionConfig) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	objNull
};

//Create unit
_newUnit = objNull;
_newUnit = _unitClassName createVehicle _position;
_newUnit setDir (random 360);

//Return unit reference
["OPAEX: function returned %1", _newUnit] call BIS_fnc_logFormat;
_newUnit //Return statement