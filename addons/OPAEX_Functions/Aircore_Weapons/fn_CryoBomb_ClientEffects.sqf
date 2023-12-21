//Jack Moss, aka Spartanjackwar.
/*
This function represents a temporary cryobomb visually.
Parameter 0: position: origin of bomb explosion
Parameter 1: int: radius
Parameter 2: int: number of seconds for 'EMP' to last.

Return: Nothing

Must execute in a suspendable environment.
All effects are locally spawned.  This function must be run client-side.

Dependencies:
	OPAEX_fnc_Effect_setParticleArray, Not as of current.
*/
if (!hasInterface or !canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

//Get parameters
_OPAEX_CryoBomb_origin = _this select 0;
_OPAEX_CryoBomb_radius = _this select 1;
_OPAEX_CryoBomb_duration = _this select 2;
_clouds = Nil;
_shockwave = Nil;
_wave = Nil;

//Initialize arrays
_colours = [
	[0.33, 0.66, 1.0, 1],
	[0.50, 0.66, 1.0, 1],
	[0.50, 0.66, 1.0, 0.66],
	[0.50, 0.66, 1.0, 0.33]
];
_sizesShockwave = [
	0,
	0.33 * _OPAEX_CryoBomb_radius / 100,
	_OPAEX_CryoBomb_radius / 100,
	0.33 * _OPAEX_CryoBomb_radius / 10,
	_OPAEX_CryoBomb_radius / 10,
	_OPAEX_CryoBomb_radius
];
_sizesClouds = [
	_OPAEX_CryoBomb_radius / 10,
	_OPAEX_CryoBomb_radius / 5
];
_sizesWave = [
	_OPAEX_CryoBomb_radius / 10,
	_OPAEX_CryoBomb_radius / 100,
	_OPAEX_CryoBomb_radius / 1000
];

//Initial blast shockwave
_shockwave = "#particlesource" createVehicleLocal _OPAEX_CryoBomb_origin;
_shockwave setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
_shockwave setParticleParams [["\A3\data_f\koule", 1, 0, 1], "", "SpaceObject", 1,1,[0,0,0],[0,0,1],3,10,7.9,0,_sizesShockwave,_colours, [1], 1, 0, "", "", _OPAEX_CryoBomb_origin];
_shockwave setDropInterval _OPAEX_CryoBomb_duration;
sleep 0.2;

//Clouds initialization
/*
_clouds = [
	False, //is it a local vehicle?
	_OPAEX_CryoBomb_origin, //position
	_OPAEX_CryoBomb_duration / 4, //lifetime
	["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48, 1, "Billboard"],
	[//Render array
		1, //animation speed
		[//size
			_OPAEX_CryoBomb_radius / 5 / 10,
			2 * _OPAEX_CryoBomb_radius / 5 / 10,
			3 * _OPAEX_CryoBomb_radius / 5 / 10,
			4 * _OPAEX_CryoBomb_radius / 5 / 10,
			_OPAEX_CryoBomb_radius /10
		],
		0, //angle
		[0, 0, 0] //Vector direction
	],
	Nil, //Motion array
	Nil, //Physics array
	Nil, //Script array
	[//Color array
		[//Colors
			[0.33, 0.33, 1.0, 1], [0.33, 0.33, 1.0, 0]
		],
		[0.33, 0.33, 0.33, 1] //emmisive
	]
] spawn OPAEX_fnc_setParticleArray;
*/
_lifetime = ((_OPAEX_CryoBomb_radius - 1) / (_OPAEX_CryoBomb_duration + 1));
_clouds = "#particlesource" createVehicleLocal _OPAEX_CryoBomb_origin;
_clouds setParticleParams
[
	//["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48, 1],
	["A3\Data_F\ParticleEffects\Universal\smoke.p3d", 1, 0, 1],
	"", /*String*/
	"Billboard", /*String - Enum: Billboard, SpaceObject*/
	0, /*Number*/
	_lifetime, /*Number*/
	[0, 0, 0], /*3D Array of numbers as relative position to particleSource or (if object at index 18 is set) object. Or (if object at index 18 is set) String as memoryPoint of object.*/
	[0, 0, 0], /*3D Array of numbers.*/
	0, /*Number*/
	1.7, /*Number, w*/
	1, /*Number, v*/
	0, /*Number*/
	_sizesClouds, /*Array of Number*/
	_colours, /*Array of Array of RGBA Numbers*/
	[1], /*Array of Number*/
	1, /*Number*/
	1, /*Number*/
	"", /*String*/
	"", /*String*/
	_clouds /*Object*/
];
_cloudsSpeed = _OPAEX_CryoBomb_radius / (_lifetime + 1);
_clouds setParticleCircle [1, [_cloudsSpeed, _cloudsSpeed, 4]];
_clouds setDropInterval _OPAEX_CryoBomb_duration / 2000;

//Wave of ice on ground.
_wave = "#particlesource" createVehicleLocal _OPAEX_CryoBomb_origin;
_wave setParticleParams [
	["A3\Data_F\ParticleEffects\Universal\universal.p3d", 16, 7, 48],
	"",
	"Billboard",
	1,
	_OPAEX_CryoBomb_duration / 4,
	[0, 0, 0],
	[0, 0, 0],
	0,
	3,
	1,
	0,
	_sizesWave,
	_colours,
	[1,0.5], //Anim speed
	0.1,
	1,
	"",
	"",
	_wave
];
_wave setParticleRandom [0, [20, 20, 20], [5, 5, 0], 0, 0, [0, 0, 0, 0.1], 0, 0];
//_wave setParticleCircle [50, [-120, -120, 2.5]];
_wave setParticleCircle [_OPAEX_CryoBomb_radius, [0, 0, 0]];
_wave setDropInterval _OPAEX_CryoBomb_duration / 1000;

//Remove clouds and shockwave after duration.
sleep _OPAEX_CryoBomb_duration;
deleteVehicle _shockwave;
deleteVehicle _clouds;
deleteVehicle _wave;