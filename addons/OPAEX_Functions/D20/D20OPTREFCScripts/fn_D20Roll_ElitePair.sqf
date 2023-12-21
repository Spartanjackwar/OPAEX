//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: spawns hostile elite pair.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_D20_SpawnUnit
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


//List of units that form the fireteam
_units = [
	"OPTRE_FC_Elite_Minor",
	"OPTRE_FC_Elite_Minor"
];

{//Spawn all of the units
	[_unitsGroup, _x, _d20] call OPAEX_fnc_D20_SpawnUnit;
}
forEach _units;