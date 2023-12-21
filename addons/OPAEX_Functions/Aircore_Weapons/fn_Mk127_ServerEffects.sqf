//Jack Moss, aka Spartanjackwar.
/*
This function handles the illumination bomb's server execution

Parameter 0: object: bomb which is the illumination flare.
Parameter 1: int: power of illumination
Parameter 2: int: range for the illumination
Parameter 3: 3d array: color of flare and light.

Return: Nothing

Must execute in a suspendable environment.
Must be run server-side.

Dependencies:
	None
*/
if (!isServer or !canSuspend) exitWith {
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

_cutoffAltitude = 50;
_chute = Nil;

//Create parachute
_chute = createVehicle ["O_Parachute_02_F", _bomb modelToWorld [0,0,0],[],0,"CAN_COLLIDE"];
_chute setVelocity velocity _bomb;
_chute setDir getDir _bomb;

//Attach dispenser to chute.
[_bomb, _chute] call BIS_fnc_attachToRelative;


//Check if bomb is at ground level, but only check every couple seconds
waitUntil {
	sleep 2;
	getPos _bomb select 2 < 1;
};
detach _bomb;
deleteVehicle _chute;