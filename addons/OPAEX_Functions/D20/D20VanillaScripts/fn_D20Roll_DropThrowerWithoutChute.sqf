//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Drops the thrower without a chute

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_RemoteSay3D
	OPAEX_fnc_D20Visuals_Party
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

//Sound
//playSound3D [getMissionPath "d20\TeleportD20.ogg", _thrower, false, _d20, 5, 1, 100];
//playSound3D ["OPAEX_D20\TeleportD20.ogg", _thrower, false, _d20, 5, 1, 100];
[0, false, _d20, "OPAEX_Sound_D20_Enderpearl", 300, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//Yeet played into the air.
_pos = _d20 vectorAdd [0, 0, 1000];
[_pos, _thrower] call OPAEX_fnc_D20_TeleportThrower;