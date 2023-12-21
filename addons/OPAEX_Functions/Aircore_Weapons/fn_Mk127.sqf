//Jack Moss, aka Spartanjackwar.
/*
This function creates an illumination flare with a parachute.

Parameter 0: Object, Dispenser which has chute attached.  CANNOT BE NULL.
Parameter 1: Number, Intensity of illumination flares.
Parameter 2: Number, range of illumination.
Parameter 3: 3-Number array, RGB value of flares.

Return: Nothing

Can be executed on any machine.
Cannot be run in non-scheduled environments!
*/
if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

params [
	[ //Dispenser
		"_bomb",
		objNull,
		[objNull]
	],
	[ //Illumination power?
		"_IlluminationPower",
		0.10,
		[1.0]
	],
	[ //Illumination range?
		"_IlluminationRange",
		2000.0,
		[1.0]
	],
	[
		"_RGB",
		[1.0, 1.0, 1.0],
		[[1.0, 1.0, 1.0]]
	]
];

[
	_bomb,
	_IlluminationPower,
	_IlluminationRange,
	_RGB
] remoteExec [
	"OPAEX_fnc_Mk127_ClientEffects", 
	[0, -2] select isDedicated, //Runs in SP, but will hit only clients when dedicated.
	False
];
 
[
	_bomb,
	_IlluminationPower,
	_IlluminationRange,
	_RGB
] remoteExec [
	"OPAEX_fnc_Mk127_ServerEffects", 
	2, 
	False
];