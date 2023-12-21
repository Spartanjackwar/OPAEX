//Jack Moss, aka Spartanjackwar.
/*
This function represents a glassing beam visually

Parameter 0: position: origin of bomb explosion
Parameter 1: int: number of seconds for beam to last.  Note that 0 is infinite.
Parameter 2: int: altitude to begin the beam from.
Parameter 3: int: kill radius.
Parameter 4: int: percentage of objects to kill in beam radius.
Parameter 5: int: color preset to use for the beam.  Currently accepts 0 or 1, where 0 is red and 1 is bluish.

Return: Nothing

Must execute in a suspendable environment.
Must run on clients with an interface.
All effects are locally spawned.
*/

if (!hasInterface or !canSuspend) exitWith {
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

_center = _origin; //The original script used _center as the origin name, so I lazily use this line.
_lightRed = 0;
_lightGreen = 0;
_lightBlue = 0;

//The beam
private _beam = "#particlesource" createVehicleLocal (_center vectorAdd [0,0,_alt]);
if (_colorPreset isEqualTo 0) then
{
	_beam setParticleClass "OPAEX_Glass_PE";
	_lightRed = 1;
	_lightGreen = 0.38024;
	_lightBlue = 0.36456;
} else {
	if (_colorPreset isEqualTo 1) then
	{
		_beam setParticleClass "OPAEX_Glass_Blue_PE";
		_lightRed = 0.1;
		_lightGreen = 0;
		_lightBlue = 1;
	} else {
		_beam setParticleClass "OPAEX_Glass_Banana_PE";
		_lightRed = 0.623084;
		_lightGreen = 0.7173012;
		_lightBlue = 0.99176;
	};
};

//Adjust the lifetime to account for altitude.
//_beam set [4, (_alt / 150)];

//The beam of light
_lightAlt = _alt / 2;
private _light = "#lightpoint" createVehicleLocal (_center vectorAdd [0,0,_lightAlt]);
private _lightsArray = []; //Was planning to use multiple lights, but decided against
_lightsArray pushback _light;
{
	_x setLightAmbient[_lightRed, _lightGreen, _lightBlue];
	_x setLightColor[_lightRed, _lightGreen, _lightBlue];
	_x setLightBrightness 3; //Note, 100000 is visual-breaking bright, and 100 is still very bright.  33 too much too.
	_x setLightDayLight true;
	_FalloffStart = _lightAlt; //Perfect brightness range
	_FalloffConstantCoef = 0; //We don't want to reduce brightness.
	_FalloffLinearCoef = 1; //We don't want a spotlight, but rather a wide light.
	_FalloffQuadraticCoef = 2;
	_FalloffLimitStart = _lightAlt;
	_FalloffLimitEnd = (1.1 * _FalloffLimitStart);
	_x setLightAttenuation
	[//Calculated like this: 1 / (_FalloffConstantCoef + _FalloffLinearCoef*distance + _FalloffQuadraticCoef*distance^2)
		_FalloffStart,
		_FalloffConstantCoef,
		_FalloffLinearCoef,
		_FalloffQuadraticCoef,
		_FalloffLimitStart,
		_FalloffLimitEnd
	];
} ForEach _lightsArray;

//Delay until impact.
sleep (_alt / 150);
if (OPAEX_Debug_Mode) then {
	systemChat "Begun beaming";
};

//The shaking
//enableCamShake true;
[4] call BIS_fnc_earthquake;
//addCamShake [10, 10, 25];

//Dust cloud
_wave = "#particlesource" createVehicleLocal _center;
_wave setParticleParams [["A3\Data_F\ParticleEffects\Universal\universal.p3d", 16, 7, 48], "", "Billboard", 1, 7, [0, 0, 0],[0, 0, 0], 0, 1.5, 1, 1, [50, 100], [[0.1, 0.1, 0.1, 1], [0.5, 0.5, 0.5, 0.34], [1, 1, 1, 0.1], [1, 1, 1, 0]], [1,0.5], 0.1, 1, "", "", _center];
_wave setParticleRandom [2, [20, 20, 20], [5, 5, 0], 0, 0, [0, 0, 0, 0.1], 0, 0];
_wave setParticleCircle [50, [-8, -8, 5.5]];
_wave setDropInterval 0.1;

//Rock shower
_rocks = "#particlesource" createVehicleLocal _center;
_rocks setParticleParams ["\A3\Data_F\ParticleEffects\Pstone\Pstone", "", "SpaceObject", 1, 7, [0, 0, 0],[0, 0, 0.05], 1, 1000, 1, 1, [2], [[0.1, 0.1, 0.1, 0.5]], [1,0.5], 0.1, 1, "", "", _center];
_rocks setParticleRandom [2, [50, 50, 50], [1, 1, 25], 0.1, 1, [0, 0, 0, 0.1], 0, 0];
_rocks setParticleCircle [10, [0, 0, 0]];
_rocks setDropInterval 0.01;

//Add more shaking and erase light
enableCamShake true;
addCamShake [5, 10, 25];

_duration = _duration / 2;
sleep _duration; //DIAGTICKTIME?

//Deconstruct effects
{
	deleteVehicle _x;
} ForEach _lightsArray;
deleteVehicle _beam;
deleteVehicle _wave;
deleteVehicle _rocks;
enableCamShake false;

if (OPAEX_Debug_Mode) then {
	//systemChat ("Beam finished in " + (str (_duration + (_alt / 150))) + " seconds");
	systemChat ("Beam finished in " + str(_duration) + " seconds");
};