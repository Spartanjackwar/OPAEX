//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: shells the next highest scoring player.

Parameter 0: position: Position of the d20 greande.
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

//Check validity of parameters.
if (isNull _thrower) exitWith {
	Nil
};

//Find the highest ranking player.
_target = [_thrower] call OPAEX_fnc_GetNextScoringPlayer;

//Announce the incoming barrage.
_msg = format ["OPAEX: %1 (%2) is targeted for red shelling!", _target, name _target];
[0, false, _msg] call OPAEX_fnc_RemoteSystemChat;

//Attach a red smoke, which needs to be made globally.
_smokeMarker = "SmokeShellRed" createVehicle (position _target);
_smokeMarker attachTo [_target];
sleep 5;

//Shell the player
_shellSpawn = (position _target) vectorAdd [0, 0, 10];
[
	"Sh_82mm_AMOS",
	_shellSpawn,
	1,
	[3, 3, 3]
] spawn OPAEX_fnc_D20_SpawnCluster;

deleteVehicle _smokeMarker;