//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: deploys some cluster bombs

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
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Strike", 0, False];

_submunitions = 10;
_launchSpeed = [500, 500, 50000];

//Spawn mk82 bombs in a cluster.
["Bo_Mk82", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;