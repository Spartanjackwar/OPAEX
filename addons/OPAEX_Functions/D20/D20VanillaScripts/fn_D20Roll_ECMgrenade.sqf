//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: ECM grenade.

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

_submunitions = 100;

//Spawn Chaff
["CMflare_Chaff_Ammo", _d20, _submunitions, [100,100,500]] call OPAEX_fnc_D20_SpawnCluster;

//Spawn Flare
["CMflareAmmo", _d20, _submunitions, [100,100,500]] call OPAEX_fnc_D20_SpawnCluster;