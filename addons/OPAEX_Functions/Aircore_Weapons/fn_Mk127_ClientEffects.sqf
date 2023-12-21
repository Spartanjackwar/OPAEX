//Jack Moss, aka Spartanjackwar.
/*
This function handles the illumination bomb's client effects

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
if (!hasInterface or !canSuspend) exitWith {
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

//Use paramters to determine attenuation parameters
_FalloffStart = _IlluminationRange; //Perfect brightness range
_FalloffConstantCoef = 0; //We don't want to reduce brightness.
_FalloffLinearCoef = 1; //We don't want a spotlight, but rather a wide light.
_FalloffQuadraticCoef = _IlluminationRange;
_FalloffLimitStart = _IlluminationRange;
_FalloffLimitEnd = (1.1 * _FalloffLimitStart);

//Create light
_light = "#lightpoint" createVehicleLocal (getPosATL _bomb);
_light attachTo [_bomb, [0, 0, 0]];
_light setLightBrightness _IlluminationPower;
_light setLightAmbient [_RGB select 0, _RGB select 1, _RGB select 2];
_light setLightColor [_RGB select 0, _RGB select 1, _RGB select 2];
_light setLightAttenuation
[//Calculated like this: 1 / (_FalloffConstantCoef + _FalloffLinearCoef*distance + _FalloffQuadraticCoef*distance^2)
	_FalloffStart,
	_FalloffConstantCoef,
	_FalloffLinearCoef,
	_FalloffQuadraticCoef,
	_FalloffLimitStart,
	_FalloffLimitEnd
];
_light setLightDayLight True;
_light setLightUseFlare True;
_light setLightFlareMaxDistance (1.1 * _IlluminationRange);
_light setLightFlareSize 30;

//Delete the light beneath cutoff altitude of 50 meters.
waitUntil {
	sleep 2;
	getPos _bomb select 2 < _cutoffAltitude;
};
deleteVehicle _light;
