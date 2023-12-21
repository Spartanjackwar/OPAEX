//Jack Moss, aka Spartanjackwar.
/*
Spartan laser charge visual sequence.

Parameter 0: object: Unit that is involved with the laser.
Parameter 1: float: charge time of beam.
Parameter 2: 3D array of float: color of beam.  This is optional and defaults to red. [0,0,0] enables RGB mode.

Return: Nothing

Can be executed in non-scheduled environment.
Can execute on any client.
*/

params [
	[
		"_firingUnit",
		player,
		[objNull]
	],
	[
		"_chargeDuration",
		3.5,
		[1.0]
	],
	[
		"_beamColor",
		[1000, 0, 0],
		[[0, 0, 0]]
	]
];
//Validate firing unit.
if (isNull _firingUnit) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
};

//Get the gun barrel offset
private _offset = [currentWeapon _firingUnit] call OPAEX_fnc_getMuzzleOffsetFromWeaponProxy; //[0, 0.43, 0.1];
_offset = [-(_offset select 1), -(_offset select 0) + 0.1, _offset select 2];

//Get the time
private _startTime = time;

//Draw a laser beam.
_aimingLaserHandler = addMissionEventHandler ["Draw3D",
	{
		_firingUnit = _thisArgs select 0;
		_offset = _thisArgs select 1;
		_duration = _thisArgs select 2;
		_startTime = _thisArgs select 3;
		_beamColor = _thisArgs select 4;
		
		//Check for RGB mode
		if (_beamColor isEqualTo [0, 0, 0]) then {
			//We cycle hue only in RGB mode, and then convert from HSV to RGB.
			private _V = 1; //Value, 0 <= V <= 1;
			private _S = 1; //Saturation, 0 <= S <= 1;
			private _hue = random 359; //Hue, or degree on the color wheel, 0 <= Hue < 360.
			private _C = _V * _S;
			private _Z = _C * (1 - abs((_hue/60) mod 2 - 1));
			private _M = _V - _C;
			
			private _colourPrime = [];
			if (_hue < 60) then {_colourPrime = [_C, _Z, 0];} else {
				if (_hue < 120) then {_colourPrime = [_Z, _C, 0];} else {
					if (_hue < 180) then {_colourPrime = [0, _C, _Z];} else {
						if (_hue < 240) then {_colourPrime = [0, _Z, _C];} else {
							if (_hue < 300) then {_colourPrime = [_Z, 0, _C];} else {
								_colourPrime = [_C, 0, _Z];
							};
						};
					};
				};
			};
			
			private _convertingFactor = 100; //While actual HSV to RGB multiplies to 255, arma uses 0 - 1 with larger than 1 values enhancing emmissivity.
			private _colorValueR = ((_colourPrime select 0) + _M) * 100;
			private _colorValueG = ((_colourPrime select 1) + _M) * 100;
			private _colorValueB = ((_colourPrime select 2) + _M) * 100;
			
			_beamColor = [_colorValueR, _colorValueG, _colorValueB];
		};
		
		//Figure out the time delta and ratio to resolve the desired scale behavior
		_timeDelta = time - _startTime;
		_timeRatio = _timeDelta / (_duration * 1.9);
		_scale = _timeRatio;
		if (_timeRatio >= 1) then {
			_scale = 10;
		};

		private _wepDir = _firingUnit weaponDirection (currentWeapon _firingUnit);
		drawLaser [
			_firingUnit modelToWorldWorld ([_firingUnit, _offset] call OPAEX_fnc_GetCurrentWeaponPosition), //Starting position
			_wepDir, //Orientation of laser
			_beamColor, //RGB colour of the beam.  Also functions as emisivity, so they are not 0-1 ranged.
			[], //Impact dot colour, which when empty uses beam colour.
			2 * _scale, //Dot size.
			_scale, //Beam thickness.
			-1, //Beam maximum length.
			false //Infared only bool.
		];
	},
	[_firingUnit, _offset, _chargeDuration, _startTime, _beamColor] //Arguments to pass to the handler.
];

//Store the local handler on the local copy of the object.
_firingUnit setVariable ["OPAEX_Splaser_AimingLaserHandler", _aimingLaserHandler, false];

