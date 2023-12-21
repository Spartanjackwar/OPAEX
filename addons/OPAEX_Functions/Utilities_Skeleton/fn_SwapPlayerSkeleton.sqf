//Jack Moss, aka Spartanjackwar.
/*
This function checks the player for gear that contains a given substring and then swaps units via given classname.

Parameter 0: string: substring of the classname of gear item
Parameter 1: string: classname of unit to switch to
Parameter 2: bool: should we ignore swapping if you already have the skeleton you're asking for?
Parameter 3: string: substring of the classname of gear item to use as an abort.
Note that if parameter 2 is true, the behavior checks unit type.

Return: Bool, True if _gearTarget is found.  False otherwise.

Client must execute this.  Can be executed in nonscheduled environments.
*/
if (!hasInterface) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	False
};

params [
	[ //Gear classname to use
		"_gearTarget",
		"Mjolnir",
		[""]
	],
	[ //Unit classname to use
		"_unitTarget",
		"OPTRE_Spartan2_Soldier_Rifleman_AR",
		[""]
	],
	[ //Should we consider the previous skeleton?
		"_ignorePreviousSkeleton",
		False,
		[True]
	],
	[
		"_gearExclusionString",
		"_Human",
		[""]
	]
];
private _result = False;
private _condition = False;
private _exclusionAbort = False;
private _unitTargetExists = isClass (configFile >> "CfgVehicles" >> _unitTarget);

if (OPAEX_Debug_Mode) then {
	systemChat format["OPAEX: Swap was called with %1, %2, %3, %4", _gearTarget, _unitTarget, _ignorePreviousSkeleton, _gearExclusionString];
};

//Validate unit target is valid
if (_unitTarget isEqualTo "" or not _unitTargetExists) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	["OPAEX: function returned %1", _result] call BIS_fnc_logFormat;
	if (OPAEX_Debug_Mode) then {
		systemChat "aborted swap due to input rules";
	};
	_result
};

//Check the gear
_result = [_gearTarget, player, False] call OPAEX_fnc_SubStringInUnitGear;
private _targetSkeleton = [_unitTarget, True] call OPAEX_fnc_GetSkeleton;
if (_gearExclusionString isNotEqualTo "") then {
	_exclusionAbort = [_gearExclusionString, player, False] call OPAEX_fnc_SubStringInUnitGear;
};

//Abort sequence.
if (!_result or _exclusionAbort) exitWith {
	if (OPAEX_Debug_Mode) then {
		if (!_result) then {
			systemChat "aborted swap due to gear target substring find failure";
		} else {
			systemChat "aborted swap due to gear exclusion found.";
		};
	};
	False
};

//Determine if the swap check cares about the existing skeleton.
if (!_ignorePreviousSkeleton) then {
	private _currentSkeleton = [player, False] call OPAEX_fnc_GetSkeleton;
	_condition = (_targetSkeleton isNotEqualTo _currentSkeleton);
} else { //If skeleton is irrelevent, then the unit type matters and its model.
	_unitCurrent = typeOf player;
	_currentModel = (configFile >> "CfgVehicles" >> _unitCurrent >> "model") call BIS_fnc_getCfgData;
	_targetModel = (configFile >> "CfgVehicles" >> _unitTarget >> "model") call BIS_fnc_getCfgData;
	_condition = (_unitCurrent isNotEqualTo _unitTarget) and (_currentModel isNotEqualTo _targetModel);
};

if (_condition) then {
	//Notify player we're about to switch them.
	_msg = format ["OPAEX: Your gear and skeleton has a mismatch!  You will be switched momentarily to the %1 skeleton.", _targetSkeleton];
	systemChat _msg;
	
	//Swap the player
	_result = [_unitTarget] call OPAEX_fnc_SwapPlayerUnit;
} else {
	if (OPAEX_Debug_Mode) then {
		systemChat "aborted swap due to condition failure";
	};
};

["OPAEX: function returned %1", _result] call BIS_fnc_logFormat;
_result //return statement