//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: spawns a hostile banshee

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_D20_SpawnVehicle
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
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//Determine side and create the group.
_throwerSide = side _thrower;
_Side = independent;
switch (_throwerSide) do {
    case west: {_Side = east};
    case east: {_Side = west};
    default {_Side = sideEnemy}; //Default to renegade.
};
_unitsGroup = createGroup _Side;

//Figure out which banshee to spawn.
_variants = [
	"OPTRE_FC_Type26B_Banshee",
	"OPTRE_FC_Type26N_Banshee",
	"OPTRE_FC_Type27_Banshee"
];
_selection = selectRandom _variants;

[_unitsGroup, _selection, _d20] call OPAEX_fnc_D20_SpawnVehicle;