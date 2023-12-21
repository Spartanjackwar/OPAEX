//Jack Moss, aka Spartanjackwar. TODO: fix.
/*
The array to build a particle effect in a .sqf.
Normally, I'd recommend learning to use C++ for particles instead.
That said, this function is intended to allow easier use of script-based particle effects.
Designate non-existence by making parameters Nil.  This gets set to default values.

Note that when I use "int" in the following documentation, I mean any number, even floats.

NEW parameter list:
Parameter 0: localVehicle: bool.  Determines if return should be a local vehicle or global vehicle.
Parameter 1: position: int.  Position to build particlesource vehicle at.
Parameter 2: lifetime in seconds.
parameter 3: filetype array consisting of _particleShape, _Ntieth, _Index, _FrameCount, _Loop, _type
parameter 4: render array consisting of _animSpeed, _size, _angle, _vectorDir
parameter 5: motion array consisting of _obj, _position, _moveVelocity, _rotationVelocity
parameter 6: physics array consisting of _weight, _volume, _rubbing, _onSurface, _surfCoef
parameter 7: script array consisting of _timer, _onTimer, _onDestroy
parameter 8: colour array consisting of _colour, _emissive

Standard parameter list:
Parameter 0: localVehicle: bool.  Determines if return should be a local vehicle or global vehicle.
Parameter 1: Array containing particle file system info.  See below:
[
	Shape, 				str: What file to use for effect.
	Ntieth, 			int: Rows of decals in ParticleShape.
	Index, 				int: Row index of effect in ParticleShape.
	FrameCount			int: number of frames after ParticleShape[Index] to cycle through.
	Loop				bool: Should we loop?  1 = True, 0 = False.
]
Parameter  2: Type		str: 'Billboard' or 'SpaceObject'. Defines display type.
Parameter  3: Timer		int: Seconds between onTimer script executions
Parameter  4: lifeTime	int: Seconds the particle exists.
Parameter  5: position	pos: [x,y,z] in m relative to parameter18. Can be string for mempoints
Parameter  6: moveVel	vel: [x,y,z] in m/s relative to parameter18. Is a vector. Handles movement.
Parameter  7: rotVel	vel: [x,y,z] in m/s relative to parameter18. Is a vector. Handles rotation.
Parameter  8: weight	int: weight in kilograms.
Parameter  9: volume	int: volume in m^3.  Used with weight for density.  Doesn't affect size.
Parameter 10: rubbing	int: impact of wind on particle.
Parameter 11: size		int: array of sizes over time. [size1, size2, size3,...]
Parameter 12: colour	int: array of colour.  [R, G, B, A]
Parameter 13: animSpeed	int: array of speeds in cycles per second.  Works similar to size.
Parameter 14: rndDirPer	int: number of seconds between random direction changes.
Parameter 15: rndDirInt	int: intensity of random direction changes
Parameter 16: onTimer	str: script to execute when particle timer cycles.
Parameter 17: onDestroy	str: script to execute when particle is deleted
Parameter 18: object	obj: object to which the particles are attached.  Usually "this".
Parameter 19: angle		int: starting angle in radians.  Recall that 2pi is 360.
Parameter 20: onSurface	bool: should particles bounce on surfacce impact? 1 = True, 0 = False.
Parameter 21: surfCoef	int: coefficient of bounce collision.
Parameter 22: emmisive	int: array of arrays of colour. Alpha does not currently work on this one.
Parameter 23: vectorDir vel: [x,y,z] as a unitless vector.  Determines SpaceObject default direction.

Return: Vehicle for particle effect.

Dependencies:
	None
*/

Params[ //Form ["_Variable", [DefaultValue], [array of default values]]
	["_localVehicle",
		True,
		[True]
	],
	
	["_Position",
		[0,0,0]
		//[[0,0,0]]
	],
	
	["_lifeTime", 
		60,
		[0]
	], //lifeTime
	
	["_fileArray",
		["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 1, 1, "Billboard"]
		//[["", 0, 0, 0, 0, ""]]
	], //_particleShape, _Ntieth, _Index, _FrameCount, _Loop, _type
	
	["_renderArray",
		[[1], [1], 0, [0, 0, 0]]
		//[[0, [0], 0, [0, 0, 0]]]
	], //_animSpeed, _size, _angle, _vectorDir
	
	["_motionArray",
		["this", [0, 0, 0], [0, 0, 0], [0, 0, 0]]
		//[["", [0, 0, 0], [0, 0, 0], [0, 0, 0]]]
	], //_obj, _position, _moveVelocity, _rotationVelocity
	
	["_physicsArray",
		[1, 1, 0.05, 0, 0]
		//[[0, 0, 0.00, 0, 0]]
	], //_weight, _volume, _rubbing, _onSurface, _surfCoef
	
	["_scriptArray",
		[0, "", ""]
		//[[0, "", ""]]
	], //_timer, _onTimer, _onDestroy
	
	["_colourArray",
		[[[1, 1, 1, 1]], [[0, 0, 0, 1]]]
		//[[[[0, 0, 0, 0], [0, 0, 0, 0]]]]
	] //_colour, _emissive
];

_AnimationName = ""; //str: Obsolete.  Will throw error if not empty.
_randomDirectionPer = 0;
_randomDirectionIntensity = 0;

_particleShape = _fileArray select 0;
_Ntieth = _fileArray select 1;
_Index = _fileArray select 2;
_FrameCount = _fileArray select 3;
_Loop = _fileArray select 4;
//_AnimationName would go here, but we know the value already.
_type = _fileArray select 5;
_timer = _scriptArray select 0;
//_lifeTime = _this select 0; Already done via above.
_position = _motionArray select 1;
_moveVelocity = _motionArray select 2;
_rotationVelocity = _motionArray select 3;
_weight = _physicsArray select 0;
_volume = _physicsArray select 1;
_rubbing = _physicsArray select 2;
_size = _renderArray select 1;
_colour = _colourArray select 0;
_animSpeed = _renderArray select 0;
//_randomDirectionPer = _this select 13;
//_randomDirectionIntensity = _this select 14;
_onTimer = _scriptArray select 1;
_onDestroy = _scriptArray select 2;
_obj = _motionArray select 0;
_angle = _renderArray select 2;
_onSurface = _physicsArray select 3;
_surfCoef = _physicsArray select 4;
_emissive = _colourArray select 1;
_vectorDir = _renderArray select 3;

//Build vehicle
_particle = Nil;
if (_localVehicle) then {
	_particle = "#particlesource" createVehicleLocal _Position;
} else {
	_particle = "#particlesource" createVehicle _Position;
};

//Apply parameters
_particle setParticleParams
[
	[
		_particleShape,
		_Ntieth,
		_Index,
		_FrameCount,
		_Loop
	],
	_animationName,
	_type,
	_timer,
	_lifeTime,
	_position,
	_moveVelocity,
	_rotationVelocity,
	_weight,
	_volume,
	_rubbing,
	_size,
	_colour,
	_animSpeed,
	_randomDirectionPer,
	_randomDirectionIntensity,
	_onTimer,
	_onDestroy,
	_obj,
	_angle,
	_onSurface,
	_surfCoef,
	_emissive,
	_vectorDir
];
_particle