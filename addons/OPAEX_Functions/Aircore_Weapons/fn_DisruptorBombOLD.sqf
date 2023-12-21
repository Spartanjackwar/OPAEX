//Jack Moss, aka Spartanjackwar.
/*
This function represents a disruptor bomb via removing a vehicle's ammo and fuel and attaching.
Parameter 0: position: origin of bomb explosion
Parameter 1: int: radius
Parameter 2: int: number of seconds for 'EMP' to last.
Parameter 3: bool: if the timer should show up on screen.

Return: Nothing

Must execute in a suspendable environment.
Server is passed the actual physical response to freezing.  Headless clients do nothing.
All effects are locally spawned.

Dependencies:
	OPAEX_fnc_EMP
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

//Client-side light effects
if (hasInterface) then
{
	//Blast shockwaves
	//_shockwave = "#particlesource" createVehicleLocal _OPAEX_DisruptorBomb_origin;
	//_shockwave setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
	//_shockwave setParticleParams [["\A3\data_f\koule", 1, 0, 1], "", "SpaceObject", 1,_interval,[0,0,0],[0,0,1],3,10,7.9,0,_sizesShockwave,_colours, [1], 1, 0, "", "", _OPAEX_DisruptorBomb_origin];
	//_shockwave setDropInterval _interval;
	
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
	_FalloffLimitStart = 100;
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
};

//Server-only part of script.  This part is the physical reaction.
if (isServer) then
{//Freeze objects and EMP them server-side.
	_List = _OPAEX_DisruptorBomb_origin nearEntities _OPAEX_DisruptorBomb_radius;
	
	_EMPallowed = [];
	{//Filter out objects that are game logic or infantry from EMP.
		if (!(_x isKindOf "Logic") && !(_x isKindOf "Man")) then
		{
			_EMPallowed pushback _x;
		};
	} ForEach _List;

	//EMP the objects in list and wait for completion.
	_EMPScriptHandle = [_EMPallowed, _OPAEX_DisruptorBomb_duration, _displayTimer] spawn OPAEX_fnc_EMP;
};

//Client-side effect loop and particle source vehicles.
if (hasInterface) then
{
	//_timerScriptHandle = [_OPAEX_DisruptorBomb_duration, _displayTimer, False] spawn OPAEX_fnc_Timer;
	_effectDelay = 0.25 * _interval;
	enableCamShake true;
	"dynamicBlur" ppEffectEnable true;
	
	_WaveVelocity = (_OPAEX_DisruptorBomb_radius - 1) / _interval;
	
	_iterations = _OPAEX_DisruptorBomb_duration / (_interval + 2 * _effectDelay);
	_i = 0;
	
	//The visuals.
	//while {not scriptDone _timerScriptHandle} do
	while {_i < _iterations} do
	{
		_distanceFromOrigin = _OPAEX_DisruptorBomb_origin distance (getPos Player);
	
		//Blast shockwaves, which needs deleting and rebuilding each loop iteration because space objects don't follow the drop interval correctly.
		_shockwave = "#particlesource" createVehicleLocal _OPAEX_DisruptorBomb_origin;
		_shockwave setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
		//_shockwave setParticleParams [["\A3\data_f\koule", 1, 0, 1], "", "SpaceObject", 1, (_distanceFromOrigin / _WaveVelocity), [0, 0, 0], [0, 0, 1], 3, 10, 7.9, 0, _sizesShockwave, _colours, [1], 1, 0, "", "", _OPAEX_DisruptorBomb_origin];
		_shockwave setParticleParams [["\A3\data_f\koule", 1, 0, 1], "", "SpaceObject", 1, _interval, [0, 0, 0], [0, 0, 1], 3, 10, 7.9, 0, _sizesShockwave, _colours, [1], 1, 0, "", "", _OPAEX_DisruptorBomb_origin];
		_shockwave setDropInterval 999;
		
		//Blast refraction wave.  To sync with the above shockwave, has the be rebuilt each loop.
		_ripple = "#particlesource" createVehicleLocal _OPAEX_DisruptorBomb_origin;
		_ripple setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
		//_ripple setParticleParams [["\A3\data_f\ParticleEffects\Universal\Refract.p3d", 1, 0, 1], "", "Billboard", 1, (_distanceFromOrigin / _WaveVelocity), [0, 0, 0], [0, 0, 1], 3, 10, 7.9,0, _sizesShockwave, _coloursRipple, [1], 1, 0, "", "", _OPAEX_DisruptorBomb_origin];
		_ripple setParticleParams [["\A3\data_f\ParticleEffects\Universal\Refract.p3d", 1, 0, 1], "", "Billboard", 1, _interval, [0, 0, 0], [0, 0, 1], 3, 10, 7.9,0, _sizesShockwave, _coloursRipple, [1], 1, 0, "", "", _OPAEX_DisruptorBomb_origin];
		_ripple setDropInterval 999;
		
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
		deleteVehicle _shockwave;
		deleteVehicle _ripple;
	};
	deleteVehicle _light;
	"dynamicBlur" ppEffectEnable false;
};