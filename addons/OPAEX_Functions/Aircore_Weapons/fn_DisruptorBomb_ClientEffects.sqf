//Jack Moss, aka Spartanjackwar.
/*
This function represents a disruptor bomb visually
Parameter 0: position: origin of bomb explosion
Parameter 1: int: radius
Parameter 2: int: number of seconds for 'EMP' to last.
Parameter 3: bool: if the timer should show up on screen.

Return: Nothing

Must execute in a suspendable environment.
Must run on clients with an interface.
All effects are locally spawned.

Dependencies:
	None
*/
if (!hasInterface or !canSuspend) exitWith {
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

//whole-function-scoped variables.
_shockwave = Nil;
_light = Nil;
_ripple = Nil;
_interval = 3;
_lightRed = 0.1;
_lightGreen = 0.33;
_lightBlue = 1;
_colours = [
	[_lightRed, _lightGreen, _lightBlue, 0.25]
];
_coloursRipple = [
	[0, 0, 0, 1]
];
_sizesShockwave = [
	0,
	_OPAEX_DisruptorBomb_radius
];

//Light at origin point
_light = "#lightpoint" createVehicleLocal _OPAEX_DisruptorBomb_origin;
_light setLightAmbient[_lightRed, _lightGreen, _lightBlue];
_light setLightColor[_lightRed, _lightGreen, _lightBlue];
_light setLightBrightness 3; //Note, 100000 is visual-breaking bright, and 100 is still very bright.  33 too much too.
_light setLightDayLight true;
_FalloffStart = 50; //Perfect brightness range
_FalloffConstantCoef = 0; //We don't want to reduce brightness.
_FalloffLinearCoef = 5;
_FalloffQuadraticCoef = 0;
_FalloffLimitStart = _OPAEX_DisruptorBomb_radius; //100
_FalloffLimitEnd = (1.1 * _FalloffLimitStart);
_light setLightAttenuation
[//Calculated like this: 1 / (_FalloffConstantCoef + _FalloffLinearCoef*distance + _FalloffQuadraticCoef*distance^2)
	_FalloffStart,
	_FalloffConstantCoef,
	_FalloffLinearCoef,
	_FalloffQuadraticCoef,
	_FalloffLimitStart,
	_FalloffLimitEnd
];

//Client-side effect loop and particle source vehicles.
_effectDelay = 0.25 * _interval;
enableCamShake true;
"dynamicBlur" ppEffectEnable true;

_WaveVelocity = (_OPAEX_DisruptorBomb_radius - 1) / _interval;

//The visuals.
_distanceFromOrigin = _OPAEX_DisruptorBomb_origin distance (getPos Player);

//Blast shockwave
_shockwave = "#particlesource" createVehicleLocal _OPAEX_DisruptorBomb_origin;
_shockwave setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
_shockwave setParticleParams [["\A3\data_f\koule", 1, 0, 1], "", "SpaceObject", 1, _interval, [0, 0, 0], [0, 0, 1], 3, 10, 7.9, 0, _sizesShockwave, _colours, [1], 1, 0, "", "", _OPAEX_DisruptorBomb_origin];
_shockwave setDropInterval 999;

//Blast refraction wave.
_ripple = "#particlesource" createVehicleLocal _OPAEX_DisruptorBomb_origin;
_ripple setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
_ripple setParticleParams [["\A3\data_f\ParticleEffects\Universal\Refract.p3d", 1, 0, 1], "", "Billboard", 1, _interval, [0, 0, 0], [0, 0, 1], 3, 10, 7.9,0, _sizesShockwave, _coloursRipple, [1], 1, 0, "", "", _OPAEX_DisruptorBomb_origin];
_ripple setDropInterval 0.5;

//Lightning bolts for extra style.
_lifetime = 1;
_bolts = "#particlesource" createVehicleLocal _OPAEX_DisruptorBomb_origin;
_bolts setParticleParams
[
	["\A3\data_f\blesk1",1, 0, 1],
	"", "SpaceObject", 0, _lifetime, [0, 0, 0], [0, 0, 0], 0, 1.7, 1, 0,
	[
		_OPAEX_DisruptorBomb_radius / 200
	],
	[
		[1, 1, 1, 1]
	], [1], 1, 1, "", "", _bolts
];
_bolts setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 1, 1, 180];
_bolts setParticleCircle [1, [0, 0, 0]];
_bolts setDropInterval 0.5;

//The below sleep accounts for the fact that space objects speed up with proximity to the particle source regardless of the drop interval settings
sleep (_distanceFromOrigin / _WaveVelocity); //d = vT, for those with physics knowledge.

if (_distanceFromOrigin < _OPAEX_DisruptorBomb_radius) then
{ //Hit-by-the-wave effects.
	//Flash and shake the screen.
	cutText ["", "WHITE OUT", 1];
	titleCut ["", "WHITE IN", 1];
	addCamShake [1, 1, 25];
	setCamShakeParams [0, 5, 5, 5, True];
	
	//Blur screen
	"dynamicBlur" ppEffectAdjust [5];
	"dynamicBlur" ppEffectCommit _effectDelay;
	sleep _effectDelay;
	"dynamicBlur" ppEffectAdjust [0];
	"dynamicBlur" ppEffectCommit _effectDelay;
	sleep _effectDelay;
	
	sleep _interval - _effectDelay * 2;
} else {
	sleep _interval;
};

//Cleanup the shockwave
deleteVehicle _shockwave;

//Wait the duration and clean the ripples, light, and dynamic blur.
sleep _OPAEX_DisruptorBomb_duration;
deleteVehicle _ripple;
deleteVehicle _light;
deleteVehicle _bolts;
"dynamicBlur" ppEffectEnable false;