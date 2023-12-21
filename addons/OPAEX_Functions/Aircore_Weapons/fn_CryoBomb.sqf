//Jack Moss, aka Spartanjackwar.
/*
Executes the cryobomb's server and client components.
Parameter 0: position: origin of bomb explosion
Parameter 1: int: radius
Parameter 2: int: number of seconds for 'EMP' to last.

Return: Nothing

Must execute in a suspendable environment.
Server is passed the actual physical response to freezing.  Headless clients do nothing.
All effects are locally spawned.

Dependencies:
	OPAEX_fnc_CryoBomb_ServerEffects
	OPAEX_fnc_CryoBomb_ClientEffects
*/
if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};
params [
	[
		"_OPAEX_CryoBomb_origin",
		(getpos player),
		[[0.0, 0.0, 0.0]]
	],
	[
		"_OPAEX_CryoBomb_radius",
		300,
		[1]
	],
	[
		"_OPAEX_CryoBomb_duration",
		30,
		[1]
	]
];

[
	_OPAEX_CryoBomb_origin,
	_OPAEX_CryoBomb_radius,
	_OPAEX_CryoBomb_duration
] remoteExec [
	"OPAEX_fnc_CryoBomb_ClientEffects", 
	[0, -2] select isDedicated, //Runs in SP, but will hit only clients when dedicated.
	False
];
 
[
	_OPAEX_CryoBomb_origin,
	_OPAEX_CryoBomb_radius,
	_OPAEX_CryoBomb_duration
] remoteExec [
	"OPAEX_fnc_CryoBomb_ServerEffects", 
	2, 
	False
];