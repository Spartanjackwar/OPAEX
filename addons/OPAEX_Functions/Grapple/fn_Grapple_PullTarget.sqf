//Jack Moss, aka Spartanjackwar.
/*
Function to pull one object towards another over an interpolated time length.

Parameter 0: object: The object we are pulling towards.
Parameter 1: object: The object we are pulling.
Parameter 2: object: The object we attach our grapple target to.
Parameter 3: float: The length of time, in seconds, for which we perform the motion interpolation.
Parameter 4: float: The length, in meters, in front of the grapple source that we stop at.  Accepts negatives, which is behind the grapple source.

Return: Nothing.

Must be executed in a scheduled environment.
Must execute on the server!
*/
params [
	[
		"_grappleSource",
		player,
		[objNull]
	],
	[
		"_grappleTarget",
		objNull,
		[objNull]
	],
	[
		"_hook",
		objNull,
		[objNull]
	],
	[
		"_duration",
		5.0,
		[1.0]
	],
	[
		"_detatchOffset",
		0,
		[1.0]
	]
];

//I wasn't kidding when I said this needs to be server executed.
if (!isServer) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	Nil
};

//Validate object parameters.
if (isNull _grappleSource or isNull _grappleTarget or isNull _hook) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};
 
/*
[] spawn {
	_duration = 1;
	_target = P2;
	_hook = createVehicle ["Land_Can_V3_F", getPos _target, [], 0, "CAN_COLLIDE"];
	[player, _target, _hook, _duration] spawn OPAEX_fnc_Grapple_PullTarget;
	sleep _duration;
	deleteVehicle _hook;
};
*/

//Grab the time range.
_startTime = time;
_endTime = _startTime + _duration;

//Attach the grapple target to the hook.
//_grappleTarget attachTo [_hook, [0, 0, 0]];
[_grappleTarget, _hook] call BIS_fnc_attachToRelative;

//Grab start values before starting, as dynamically adjusting these would cause unwanted acceleration.
_BegPos = getPosASL _grappleTarget;
_BegVel = velocity _grappleTarget;
_BegDir = vectorDir _grappleTarget;
_BegVectorUp = vectorUp _grappleTarget;
_startVals = [_BegPos, _BegVel, _BegDir, _BegVectorUp];

//Add the handler that will manage the movement sequence.
_interpolationHandler = addMissionEventHandler ["EachFrame",
    {
		//Reassign the variable names for the sake of readability.
		_grappleSource = _thisArgs select 0;
		_grappleTarget = _thisArgs select 1;
		_hook = _thisArgs select 2;
		_startTime = _thisArgs select 3;
		_endTime = _thisArgs select 4;
		_detatchOffset = _thisArgs select 5;
		_startVals = _thisArgs select 6;
		
		//Break apart the start value array for the sake of readability.
		_BegPos = _startVals select 0;
		_BegVel = _startVals select 1;
		_BegDir = _startVals select 2;
		_BegVectorUp = _startVals select 3;
		
		//Figure out our current interval from the time we're currently observing.
		_interval = linearConversion [_startTime, _endTime, time, 0, 1];
		//systemChat str(_interval); //DEBUG.
		
		//If we're beyond the interval, break the loop and remove the hook to signal the end of the sequence.
		if (_interval > 1) exitWith {
			detach _grappleTarget;
			//deleteVehicle _hook;
		};

		//Grab end values.
		//_EndPos = getPosASL _grappleSource;
		_EndPos = (vectorDir _grappleSource vectorMultiply _detatchOffset) vectorAdd (getPosASL _grappleSource);
		_EndVel = velocity _grappleSource;
		_EndDir = _BegDir; //_BegPos vectorFromTo _EndPos;
		_EndVectorUp = _BegVectorUp;

		//Do the actual interpolation transformation.
		_hook setVelocityTransformation [
			_BegPos, _EndPos, //positionASL
			_BegVel, _EndVel, //velocity
			_BegDir, _EndDir, //Orientation vector, also known as vectorDir.
			_BegVectorUp, _EndVectorUp, //VectorUp, which is the other orientation vector.
			_interval //Where we are in the sequence.
		];
    },
    [_grappleSource, _grappleTarget, _hook, _startTime, _endTime, _detatchOffset, _startVals] //Arguments to pass to the handler.
];

//Wait for the death of the hook.
sleep _duration;

//Remove the frame handler.
removeMissionEventHandler ["EachFrame", _interpolationHandler];