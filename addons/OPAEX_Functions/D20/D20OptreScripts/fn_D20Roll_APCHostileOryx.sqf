//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns an Oryx APC hostile to the thrower.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	None
*/

params [
	[
		"_d20",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_thrower",
		objNull,
		[objNull]
	]
];

//We cannot tolerate not being given a thrower
if (isNull _thrower) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

//Do the visuals
//[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//Figure out the side to use
_throwerSide = side _thrower;
_APCSide = sideEmpty;
_APCUnit = "OPTRE_M494_INS";
switch (_throwerSide) do {
    case west: {_APCSide = east; _APCUnit = "OPTRE_M494_INS"};
    case east: {_APCSide = west; _APCUnit = "OPTRE_M494"};
    default {_APCSide = sideEnemy}; //Default to renegade.
};

//Create group
_APCGroup = createGroup _APCSide;

//Spawn the units
[_APCGroup, _APCUnit, _d20] call OPAEX_fnc_D20_SpawnVehicle;