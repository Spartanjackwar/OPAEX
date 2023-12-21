//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Acts like an enderpearl from the popular game Minecraft.

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

/*playSound3D [ //I have found playSound3D incapable of addon paths, so use say3D instead.
	"\OPAEX_D20\TeleportD20.ogg",
	_thrower, //Source of sound
	false,	//isInside bool
	_d20,	//sound position, overrides sound source
	5,		//volume multiplier
	1,		//pitch multiplier
	100,	//audible distance (meters)
	0 		//offset until play
];*/


//_d20 say3D ["OPAEX_Sound_D20_Enderpearl", 100, 1, false, 0];
[0, false, _d20, "OPAEX_Sound_D20_Enderpearl", 300, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

[_d20, _thrower] call OPAEX_fnc_D20_TeleportThrower;