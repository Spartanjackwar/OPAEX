//Jack Moss, aka Spartanjackwar.
/*
Executes the glassing beam's server and client components.

Parameter 0: position: origin of bomb explosion
Parameter 1: int: radius
Parameter 2: int: number of seconds for 'EMP' to last.
Parameter 3: bool: if the timer should show up on screen.

Return: Nothing

Must execute in a suspendable environment.
Server handles non visual effects.  Headless clients do nothing.
All effects are locally spawned.
*/
if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

params [
	[
		"_origin",
		(getpos player),
		[[0.0, 0.0, 0.0]]
	],
	[
		"_duration",
		30,
		[1]
	],
	[
		"_alt",
		1000,
		[1]
	],
	[
		"_destructionRadius",
		500,
		[1]
	],
	[
		"_destructionRate",
		100,
		[1]
	],
	[
		"_colorPreset",
		0,
		[1]
	]
];

[
	_origin,
	_duration,
	_alt,
	_destructionRadius,
	_destructionRate,
	_colorPreset
] remoteExec [
	"OPAEX_fnc_GlassingBeam_ClientEffects", 
	[0, -2] select isDedicated, //Runs in SP, but will hit only clients when dedicated.
	False
];

//Delay until impact.
sleep (_alt / 150);

[
	_origin,
	_destructionRadius,
	_destructionRate
] remoteExec [
	"OPAEX_fnc_GlassingBeam_ServerEffects", 
	2, 
	False
];