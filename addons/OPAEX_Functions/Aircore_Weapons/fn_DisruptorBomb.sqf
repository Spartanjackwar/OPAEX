//Jack Moss, aka Spartanjackwar.
/*
Executes the disruptor bomb's server and client components.
Parameter 0: position: origin of bomb explosion
Parameter 1: int: radius
Parameter 2: int: number of seconds for 'EMP' to last.
Parameter 3: bool: if the timer should show up on screen.

Return: Nothing

Must execute in a suspendable environment.
Server is passed the actual physical response to freezing.  Headless clients do nothing.
All effects are locally spawned.

Dependencies:
	OPAEX_fnc_DisruptorBomb_ServerEffects
	OPAEX_fnc_DisruptorBomb_ClientEffects
*/
if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};
//Parameters
params [
	[
		"_OPAEX_DisruptorBomb_origin",
		(getpos player),
		[[0.0, 0.0, 0.0]]
	],
	[
		"_OPAEX_DisruptorBomb_radius",
		300,
		[1]
	],
	[
		"_OPAEX_DisruptorBomb_duration",
		30,
		[1]
	],
	[
		"_displayTimer",
		False,
		[True]
	]
];

[
	_OPAEX_DisruptorBomb_origin,
	_OPAEX_DisruptorBomb_radius,
	_OPAEX_DisruptorBomb_duration,
	_displayTimer
] remoteExec [
	"OPAEX_fnc_DisruptorBomb_ClientEffects", 
	[0, -2] select isDedicated, //Runs in SP, but will hit only clients when dedicated.
	False
];
 
[
	_OPAEX_DisruptorBomb_origin,
	_OPAEX_DisruptorBomb_radius,
	_OPAEX_DisruptorBomb_duration,
	_displayTimer
] remoteExec [
	"OPAEX_fnc_DisruptorBomb_ServerEffects", 
	2, 
	False
];