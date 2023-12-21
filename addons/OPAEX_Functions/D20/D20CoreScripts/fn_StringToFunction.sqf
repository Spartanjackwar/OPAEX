//Jack Moss, aka Spartanjackwar.
/*
Parses a string into a variable given a namespace.
This function assumes your string is a function name invokable through some namespace.

Parameter 0: namespace: space to search for function.
Parameter 1: string: name of the script.

Return: code.  {} is returned for failures.

MUST be executed in nonscheduled environment.
Any client may execute this.

Dependencies:
	None
*/

params [
	[
		"_namespace",
		missionNamespace,
		[true, missionNamespace, objNull, grpNull, locationNull, controlNull, displayNull]
	],
	[
		"_varName",
		"",
		[""]
	]
];

private _translatedVar = {};

//We cannot tolerate not being given a name
//if ("" isEqualTo _varName or isNil _varName) exitWith {
if (isNil _varName) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	_translatedVar
};

//Grab the script
_translatedVar = _namespace getVariable [_varName, {}];

/*//Debug output, note that this is a very cluttering debug message that usually isn't needed.
if (missionNamespace getVariable ["OPAEX_D20_Debug_Mode", False]) then
{
	systemChat format ["\nOPAEX_DEBUG: Translated %1 to %2\n", _varName, _translatedVar];
};
*/

//Return the script.
_translatedVar //return statement.