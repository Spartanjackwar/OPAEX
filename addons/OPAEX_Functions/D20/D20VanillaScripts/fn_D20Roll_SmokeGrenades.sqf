//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: deploys all the smoke greandes

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

_submunitions = 1;
_launchSpeed = [50, 50, 50];

//Spawn all the 40 mm types.
["SmokeShell", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["SmokeShellRed", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["SmokeShellGreen", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["SmokeShellYellow", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["SmokeShellPurple", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["SmokeShellBlue", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["SmokeShellOrange", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;