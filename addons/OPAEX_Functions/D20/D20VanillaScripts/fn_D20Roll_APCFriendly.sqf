//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns a APC friendly to the thrower.

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
_APCSide = side _thrower;
_APCUnit = "I_APC_Wheeled_03_cannon_F";
switch (_APCSide) do {
    case west: {_APCUnit = "B_APC_Wheeled_01_cannon_F"};
    case east: {_APCUnit = "O_APC_Wheeled_02_rcws_v2_F"};
    default {};
};

//Create group
_APCGroup = createGroup _APCSide;

//Spawn the unit
[_APCGroup, _APCUnit, _d20] call OPAEX_fnc_D20_SpawnVehicle;