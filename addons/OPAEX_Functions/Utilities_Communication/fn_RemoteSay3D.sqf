//Jack Moss, aka Spartanjackwar.
/*
Wrapper for say3D which remote executes the sound.
This is used to clean the sound call syntax in OPAEX.

Parameter 0: num: ID of client to cast to. 0 is global, 2 is server only. Negatives invert behavior.
Parameter 1: bool: if remote cast should target JIP players.
Parameter 2: obj or 3D array: source of sound
Parameter 3: string: classname of sound
Parameter 4: num: maximum hearable distance of sound.
Parameter 5: num: pitch multiplier
Parameter 6: bool: should radio filters be applied
Parameter 7: num: seconds offset from command to play the sound.

Parameters 0-3 should never be left out unless you want errors.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.
*/

params [
	[
		"_remoteTargetBehavior",
		0,
		[0]
	],
	[
		"_remoteTargetJIP",
		false,
		[true]
	],
	[
		"_soundSource",
		objNull,
		[objNull, [0,0,0]]
	],
	[
		"_soundName",
		"",
		[""]
	],
	[
		"_maxAudibleDistance",
		100,
		[1]
	],
	[
		"_soundPitch",
		1.0,
		[1.0]
	],
	[
		"_soundIsRadioSpeech",
		false,
		[true]
	],
	[
		"_soundPlayOffset",
		0,
		[0]
	]
];

//Convert positions to objects
_dummySourceObject = objNull;
_isSourcePosition = !(_soundSource isEqualType objNull);
if (_isSourcePosition) then {
	_dummySourceObject = "#particlesource" createVehicle _soundSource;
} else {
	_dummySourceObject = _soundSource;
};


[//Remotely execute the say3D.
	//Parameter format is <p1> say3D <p2>, which is why <p1> is not a part of the array.
	_dummySourceObject,
	[
		_soundName,
		_maxAudibleDistance,
		_soundPitch,
		_soundIsRadioSpeech,
		_soundPlayOffset
	]
] remoteExec [
	"say3D",
	_remoteTargetBehavior,
	_remoteTargetJIP
];


/*{
	_dummySourceObject say3D [
		_soundName,
		_maxAudibleDistance,
		_soundPitch,
		_soundIsRadioSpeech,
		_soundPlayOffset
	];
} remoteExec [
	"BIS_fnc_call",
	_remoteTargetBehavior,
	_remoteTargetJIP
];
//Remove the sound source from existence if and only if it is a dummy vehicle.
if (_isSourcePosition) then {
	deleteVehicle _dummySourceObject;
};*/