//Jack Moss, aka Spartanjackwar.
/*
Function to turn a unit into a balls-based bipod.

Parameter 0: object: Unit in the bipod stance.

Return: Nothing

Can be executed in nonscheduled environment.
Execute where parameter 0 is local. However, we do that for you if it isn't.
*/
params [
	[
		"_unit",
		player,
		[objNull]
	]
];

//Safe guard nonlocal runs.
if (!local _unit) exitWith {
	_this remoteExecCall ["OPAEX_fnc_BallBipodOn", _unit];
};

//Abort if in a vehicle.
if (vehicle _unit isNotEqualTo _unit) exitWith {
	nil
};

//Immediately start the entry sequence.
_unit switchMove "OPAEX_BallBipod_Entry";

//Put the brick on their nuts.
//private _brick = "Land_Brick_01_F" createVehicle getPosATL _unit;
//_brick attachTo[_unit, [0,0,0.2], "pelvis"];
_brick = "BallBipodInvisibleCube" createVehicle getPosATL _unit;
_brick attachTo[_unit, [0,0,0], "pelvis"];

//Begin the loop for the bipod.
_unit playMove "OPAEX_BallBipod_Standstill";
private _index = _unit addEventHandler ["AnimDone", {
	params ["_unit", "_anim"];
	//systemChat format["DONE: %1", _anim]; //Debug
	
	//If the anim has finished, attempt to restart it.
	if (_anim isEqualTo "opaex_ballbipod_standstill") then { //Anim name MUST BE LOWERCASE since Arma does that.
		if (alive _unit) then {
			_unit playMove "OPAEX_BallBipod_Standstill";
		} else {
			//Extract the object.
			_brick = _unit getVariable ["OPAEX_BallBipodBrick", objNull];
			
			//Invoke the shutoff.
			[_unit, _thisEventHandler, _brick] call OPAEX_fnc_BallBipodOff;
		};
	};
}];

//Store the index of the handler so we don't have infinite loops. Also the brick to avoid lingering objects.
_unit setVariable ["OPAEX_BallBipodHandler", _index, true];
_unit setVariable ["OPAEX_BallBipodBrick", _brick, true];