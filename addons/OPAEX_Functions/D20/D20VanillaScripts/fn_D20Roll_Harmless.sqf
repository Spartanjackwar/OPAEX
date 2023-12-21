//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: does nothing of interest, which should make users fear the d20 more.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_RemoteSay3D
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

//Do a creepy sound.
//playSound3D [getMissionPath "d20\EldritchBananaGodBassBoost.ogg", _thrower, false, _d20, 4]; //TODO: remove getMissionPath
//playSound3D ["\OPAEX_D20\EldritchBananaGodBassBoost.ogg", _thrower, false, _d20, 4];
[0, false, _d20, "OPAEX_Sound_D20_EldritchBananaGodBassBoost", 1000, 1, false, 0] call OPAEX_fnc_RemoteSay3D;