//Jack Moss, aka Spartanjackwar.
/*
This function swaps the player into a new unit.
This is intended to allow players to switch between OPTRE skeletons and Arma's skeleton.

It appears that event handlers registered to the player will have to be reregistered.
Unfortunately, no method exists for this purpose.
Retrieving eventhandler code from the player unit and reapplying it to the new unit cannot be done.

Parameter 1: string: classname of the unit who we switch into

Return: Bool, false is failed, true if success.

Client alone must execute this.  Can be executed in a nonscheduled environment.

Handlers invoked:
	OPAEX_EventHandler_SwapPlayerUnit
Dependencies:
	OPAEX_fnc_PasteUnitGear
	OPAEX_fnc_GetUnitIDInGroup
*/
if (!hasInterface) exitWith {
	["OPAEX: ERROR: required run conditions not met."] call BIS_fnc_logFormat;
	False
};

//Setup parameters
params [
	[
		"_unitClassName",
		"",
		[""]
	]
];

//Validate the classname exists.
if (not isClass (configFile >> "CfgVehicles" >> _unitClassName)) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	False
};

_result = False;

//Create unit
_previousUnit = player;
_pos = getPos _previousUnit;
_newUnit = objNull;
_newUnit = (createGroup side _previousUnit) createUnit [_unitClassName, _pos, [], 0, "CAN_COLLIDE"];

//Copy everything to the new unit
_result = [_previousUnit, _newUnit] call OPAEX_fnc_PasteUnitGear;

//These three lines seem hit-or-miss with functioning, so I've disabled them.
/*
_newUnit setRank (rank _previousUnit);
_newUnit addScore (score _previousUnit);
_newUnit setName (name _previousUnit);
*/

//We're going to do what is a generally bad practice: loop without sleeping.
_initialTime = serverTime;
_currentTime = serverTime;
_attemptCap = 10; //This is a delay in seconds, so I suspect network transfer is doable over 10 seconds.
while {_currentTime - _initialTime < _attemptCap} do {
	if (not isNull _newUnit) then 
	{//Swap into newUnit when unit exists
		selectPlayer _newUnit;
		_attemptCap = 0;
		systemChat "OPAEX: Swapping into new player body";
	};
	_currentTime = serverTime;
};
if !(_attemptCap isEqualTo 0) exitWith
{ //If we never acknowledged the switch as complete, then something went wrong.
	["OPAEX: ERROR: runtime error."] call BIS_fnc_error;
	False
};


[ //Call scripted handler in mission namespace to allow listen capabilities for other mods.
	missionNamespace,
	"OPAEX_EventHandler_SwapPlayerUnit",
	[ //Parameters to expect if you hook into this handler.
		_previousUnit, _newUnit
	]
] call BIS_fnc_callScriptedEventHandler;

//Move new unit into same group, and remove prior unit
_GroupRank = [_previousUnit] call OPAEX_fnc_GetUnitIDInGroup;
if (count units group _previousUnit > 1) then
{ //More than 1 unit in group, so attempt to remove old unit and replace it.
	deleteVehicle _previousUnit;
	_newUnit joinAsSilent [group _previousUnit, _GroupRank];
} else { //Solo group, join, then replace.
	[_newUnit] join group _previousUnit;
	deleteVehicle _previousUnit;
};

["OPAEX: function returned %1", _result] call BIS_fnc_logFormat;
_result //Return statement