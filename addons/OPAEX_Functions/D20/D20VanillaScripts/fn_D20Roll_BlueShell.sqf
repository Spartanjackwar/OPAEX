//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: shells the highest ranking player.

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
_target = [allUnits] call OPAEX_fnc_GetHighestRankingUnit;

//Announce the incoming barrage.
_msg = format ["OPAEX: %1 (%2) is targeted for blue shelling!", _target, name _target];
[0, false, _msg] call OPAEX_fnc_RemoteSystemChat;

//Attach a blue smoke
_smokeMarker = "SmokeShellBlue" createVehicle (position _target);
_smokeMarker attachTo [_target];
sleep 5;

//Shell the player
_shellSpawn = (getPosASL _target) vectorAdd [0, 0, 10];
[
	"Sh_82mm_AMOS",
	_shellSpawn,
	1,
	[3, 3, 3]
] spawn OPAEX_fnc_D20_SpawnCluster;

deleteVehicle _smokeMarker;