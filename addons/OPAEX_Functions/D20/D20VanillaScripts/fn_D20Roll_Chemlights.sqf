//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: deploys all the chemlights

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

_submunitions = 10;
_launchSpeed = [50, 50, 50];

//Spawn all the 40 mm types.
["Chemlight_blue", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["Chemlight_yellow", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["Chemlight_red", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;
["Chemlight_green", _d20, _submunitions, _launchSpeed] call OPAEX_fnc_D20_SpawnCluster;