//Jack Moss, aka Spartanjackwar.
/*
Charging weapon framework controller.

Parameter 0: object: Unit that is involved with the laser.
Parameter 1: string: The weapon to handle.  Should actually be the muzzle.
Parameter 2: float: charge time of beam.  Note it is insensitive to units below 0.01 seconds and is sensitive to framerate.  Ideal usage should be in units of 0.1 seconds.
Parameter 3: 3D array of float: color of beam.  This is optional and defaults to red. [0,0,0] enables RGB mode.

Return: Nothing

Must be executed in scheduled environment.
Must execute on the server.
*/

params [
	[
		"_firingUnit",
		player,
		[objNull]
	],
	[
		"_muzzleToHandle",
		"OPAEX_SpartanLaser",
		[""]
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
private [
	"_isCharging",
	"_interruptedStatusMessage",
	"_interrupted",
	"_time",
	"_timeSinceLast",
	"_charged",
	"_chargeTime"
];

//Guard against non-server runs and non suspendible environments.
if (!canSuspend or !isServer) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};
if (isNull _firingUnit) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
};

//Check for already running loop via an isCharging variable stored on the firing unit.
_isCharging = _firingUnit getVariable ["OPAEX_IsCharging", false];
if (_isCharging) exitWith { //If we're already charging, then we're trying to interrupt an already running loop.
	_firingUnit setVariable ["OPAEX_IsCharging", false];
	Nil
};


//Set the loop isCharging variable for the given unit to true since we must be starting a new charge sequence.
_firingUnit setVariable ["OPAEX_IsCharging", true];

[//Start the charging visuals for all clients.
	_firingUnit,
	_chargeDuration,
	_beamColor
] remoteExecCall [
	"OPAEX_fnc_splaserChargeVisuals",
	0,
	_firingUnit //Passing in an object allows us to keep attached to it for JIP purposes.
];

//Run a loop in which we wait for the charge or an interrupt to trigger the client fire event.
_chargeTime = 0;
_interrupted = false;
waitUntil {
	//Increment the deltatime.
	_time = cba_missionTime;
	sleep .01;
	_timeSinceLast = cba_missionTime - _time;
	_chargeTime = _chargeTime + _timeSinceLast;
	if (OPAEX_Debug_Mode) then {
		systemChat format ["[OPAEX] Laser DEBUG: %1/%2", _chargeTime, _chargeDuration];
	};
	
	//Check the charge time vs. the duration
	_charged = _chargeTime >= _chargeDuration;
	
	//Check for interrupts.  Note that the string output is used to inform clients of what happened.
	_interruptedStatusMessage = [_firingUnit, _muzzleToHandle] call OPAEX_fnc_GetChargingStatus;
	if (_interruptedStatusMessage isNotEqualTo "") then {
		_interrupted = true;
	};
	
	//Check the loop continue conditions.
	_charged or _interrupted;
};

//Stop the charging sequence visuals for all clients regardless of outcome.
_firingUnit setVariable ["OPAEX_IsCharging", false];
[
	_firingUnit
] remoteExecCall [
	"OPAEX_fnc_splaserChargeVisualsStop",
	0,
	_firingUnit
];

//If not interrupted, reset the isCharging variable and send the owning client the fire event.
if (!_interrupted) then {
	_firingUnit setVariable ["OPAEX_IsCharging", false];
	[
		_firingUnit,
		_muzzleToHandle
	] remoteExecCall [
		"OPAEX_fnc_TriggerClientFire",
		owner _firingUnit,
		false
	];
} else {
	[
		_firingUnit,
		_interruptedStatusMessage
	] remoteExecCall [
		"OPAEX_fnc_ShowClientChargeStatus",
		owner _firingUnit,
		false
	];
	if (OPAEX_Debug_Mode) then {
		systemChat "[OPAEX] Laser DEBUG: Interrupted!";
	};
};

