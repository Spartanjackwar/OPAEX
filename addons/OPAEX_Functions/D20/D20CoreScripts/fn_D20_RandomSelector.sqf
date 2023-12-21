//Jack Moss, aka Spartanjackwar.
/*
D20 grenade random selector.  All scripts are considered equally in this function.

Parameter 0: String: Classname of the D20.
Parameter 1: 3d Array: position of grenade to pass to scripts.
Parameter 2: object: thrower of grenade to pass to scripts.

Return: Bool, true for success, false for failure.

Can be executed in nonscheduled environment.
Requires server execution.
*/

params [
	[
		"_D20Name",
		"OPAEX_M_D20",
		[""]
	],
	[
		"_d20Pos",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_thrower",
		objNull,
		[objNull]
	]
];

if (!isServer) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	False
};

//Grab the D20
_scriptList = missionNamespace getVariable "OPAEX_D20_D20List";
_indexOfD20 = _scriptList find _D20Name;

//Validate thrower and D20.
if ((isNull _thrower) or (_indexOfD20 isEqualTo -1)) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	False
};

//Grab list of scripts
_D20ParallelScriptList = missionNamespace getVariable ["OPAEX_D20_ScriptList",[""]];
_scriptList = _D20ParallelScriptList select _indexOfD20;
_lengthOfScriptList = count _scriptList;

//Pick random script from list of scripts
_randomScriptName = selectRandom _scriptList;
_randomScript = missionNamespace getVariable [_randomScriptName, ""];
//_randomScript = [missionNamespace, _randomScriptName] call OPAEX_fnc_StringToFunction;

//If enabled...
if (OPAEX_D20_Enabled) then { //Do the D20 selection if and only if we're enabled.
	//Debug output if debugging is enabled.
	_debugIsOn = missionNamespace getVariable ["OPAEX_D20_Debug_Mode", False];
	if (_debugIsOn) then {//Debug is enabled via: missionNamespace setVariable ["OPAEX_D20_Debug_Mode", True];
		
		//Test D20 invokation of scripts by changing the following namespace variable.
		_forcedScriptName = missionNamespace getVariable ["OPAEX_D20_Debug_ForcedSelection", ""];
		_forcedScript = missionNamespace getVariable [_forcedScriptName, ""];
		//_forcedScript = [missionNamespace, _forcedScriptName] call OPAEX_fnc_StringToFunction;
		_blankCode = {};
		if (!isNil _forcedScriptName) then {
			[_d20Pos, _thrower] spawn _forcedScript;
			_randomScriptName = _forcedScriptName;
		} else {
			[_d20Pos, _thrower] spawn _randomScript;
		};
		
		hintSilent parseText format [
			"<t size='2'>%1</t><br/><t size='1'>%2%3</t><br/><t size='1'>%4%5</t><br/><t size='1'>%6%7</t><br/><t size='1'>%8%9</t>",
			"OPAEX_D20_ScriptList data:",
			"Length: ", _lengthOfScriptList,
			"ScriptName: ", _randomScriptName,
			"Position: ", _d20Pos,
			"Thrower: ", _thrower
		];
	} else { //Execute script without debug mode.
		[_d20Pos, _thrower] spawn _randomScript;
	};
} else { //Notify users they must enable the D20 while also ratting out the potential D20 abusers.
	//Get the name of the user
	_msg = format ["OPAEX: %1 threw a D20 which isn't enabled in this mission's addon settings.",name _thrower];
	
	//Send the message via systemChat
	[0, false, _msg] call OPAEX_fnc_RemoteSystemChat;
};

["OPAEX: function returned %1", True] call BIS_fnc_logFormat;
True //return statement.