//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns a hostile spartan.

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
	"OPTRE_FC_Spartan_Automatic_Rifleman",
	"OPTRE_FC_Spartan_Corpsman",
	"OPTRE_FC_Spartan_Engineer",
	"OPTRE_FC_Spartan_Marksman",
	"OPTRE_FC_Spartan_Rifleman_AT",
	"OPTRE_FC_Spartan_Rifleman_BR",
	"OPTRE_FC_Spartan_Rifleman_AR",
	"OPTRE_FC_Spartan_Scout",
	"OPTRE_FC_Spartan_Scout_Sniper",
	"OPTRE_FC_Spartan_TeamLeader"
	//"OPTRE_FC_Spartan" I didn't feel like having an unarmed spartan was interesting.
];

_selection = selectRandom _units;

//Spawn one of the units
[_unitsGroup, _selection, _d20] call OPAEX_fnc_D20_SpawnUnit;