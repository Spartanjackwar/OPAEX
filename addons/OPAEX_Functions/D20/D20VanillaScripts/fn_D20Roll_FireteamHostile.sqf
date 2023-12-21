//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns a fireteam hostile to the thrower.

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

//Figure out the side to use
_throwerSide = side _thrower;
_fireteamSide = sideEmpty;
_fireteamUnitPrefix = "I";

switch (_throwerSide) do {
    case west: {_fireteamSide = east; _fireteamUnitPrefix = "O"};
    case east: {_fireteamSide = west; _fireteamUnitPrefix = "B"};
    default {_fireteamSide = sideEnemy}; //Default to renegade.
};

//Create group
_fireteamGroup = createGroup _fireteamSide;

//List of units that form the fireteam
_fireteam = [
	"_Soldier_SL_F",
	"_Soldier_AR_F",
	"_Soldier_M_F",
	"_Soldier_AT_F",
	"_Soldier_AAT_F",
	"_Soldier_A_F",
	"_medic_F",
	"_Soldier_F",
	"_Soldier_F",
	"_Soldier_F",
	"_Soldier_F",
	"_Soldier_F",
	"_Soldier_M_F",
	"_Soldier_GL_F",
	"_Soldier_GL_F",
	"_Soldier_AT_F",
	"_Soldier_AAT_F",
	"_Soldier_A_F",
	"_medic_F",
	"_Soldier_AR_F",
	"_Soldier_SL_F"
];

{//Spawn all of the units, appending the prefix to the name
	_unitType = _fireteamUnitPrefix + _x;
	[_fireteamGroup, _unitType, _d20] call OPAEX_fnc_D20_SpawnUnit;
}
forEach _fireteam;