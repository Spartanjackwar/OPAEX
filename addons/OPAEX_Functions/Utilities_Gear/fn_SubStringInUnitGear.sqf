//Jack Moss, aka Spartanjackwar.
/*
This function checks the player for gear that contains a given substring.

Parameter 0: string: substring of the classname of gear item
Parameter 1: object: unit whose gear we search
Parameter 2: bool: if we want our substring check to be case-sensitive

Return: bool, true if string found, false otherwise.

Can be run on any machine.
Can be executed in nonscheduled environments.

Dependencies:
	BIS_fnc_inString
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
		objNull,
		[objNull]
	],
	[ //Should we be case-sensitive?
		"_isCaseSensitive",
		False,
		[True]
	]
];

//Validate parameters further
if (isNull _unitTarget) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	False
};
if (_gearTarget isEqualTo "") exitWith
{
	["OPAEX: function returned %1", True] call BIS_fnc_logFormat;
	True
};

scopeName "main"; //I know it's unusal to see a named scope, but optimization calls need for this.
private _result = False;

//Get the gear of the player.
private _gear = [];
_gear pushBack (headgear player);
_gear pushBack (vest player);
_gear pushBack (uniform player);
_gear pushBack (backpack player);

{ //Check for the first gear piece that has the substring _gearTarget.
	if ([_gearTarget, _x, _isCaseSensitive] call BIS_fnc_inString) then
	{
		_result = True;
		breakTo "main"; //return statement
	};
} ForEach _gear;

["OPAEX: function returned %1", _result] call BIS_fnc_logFormat;
_result //return statement