//Jack Moss, aka Spartanjackwar.
/*
	This function tests an object for a given eventHandler type.
	
	Parameter 0: object: Object to query events on.
	Parameter 1: string: name of handler
	Parameter 2: bool: is the handler a scripted event handler?
	Returns: bool, true if there are any eventhandlers of the given type assigned to the object
	
	Example:
		_isEHassigned = [player, "HandleDamage"] call OPAEX_fnc_HasEventHandler;
	
	Dependencies:
		None
*/
params
[
	"_unit",
	[
		"_EHType",
		"Killed",
		[""]
	],
	[
		"_isScriptedHandler",
		False,
		[True]
	]
];

//Validate object
if (isNull _unit) exitWith {False};

_testEHID = Nil;

if (!_isScriptedHandler) then {
	//Find if handler is MP or not.
	_isMPHandler = (toUpper _ehName find "MP" > -1);


	//Add and remove handler.
	if (_isMPHandler) then
	{
		_testEHID = _unit addMPEventHandler [_EHType, {comment "TestEhMP"}];
	} else {
		_testEHID = _unit addEventHandler [_EHType, {comment "TestEh"}];
	};
	_unit removeEventHandler [_EHType, _testEHID];
} else {
	_testEHID = [_unit, _EHType, {comment "TestEh"}] call BIS_fnc_addScriptedEventHandler;
	[_unit, _EHType, _testEHID] call BIS_fnc_removeScriptedEventHandler;
};

//Return statements
if (_testEHID > 1) exitWith {true};
False // _testEHID would be 1 here.