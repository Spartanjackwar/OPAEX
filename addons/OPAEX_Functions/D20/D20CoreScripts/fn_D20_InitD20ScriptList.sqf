//Jack Moss, aka Spartanjackwar.
/*
Initializer to the list of D20 scripts.
Loads the parallel array OPAEX_D20_ScriptList.
The original design of the D20 framework expected that the user would enter a CBA function to load multiple D20 classnames, hence the string split we begin with.
The revision of the framework concluded that auto-detection was possible and cheap while still fitting with the original functions.

Parameter 0: string: list of d20 greandes in single string form, delimited by the set {,.:; }.

Return: Nothing

Can be executed in nonscheduled environment.
Can be executed anywhere.
*/

params [
	[
		"_D20ListStringForm",
		"OPAEX_M_D20",
		[""]
	]
];

private["_delimiters", "_D20List", "_newScripts"];

//Rewrite the string list as an array of strings.
_delimiters = ",.:; ";
_D20List = _D20ListStringForm splitString _delimiters;

{//Append the new D20s to the global list
	OPAEX_D20_D20List pushback _x;
	
	//Append the script list with the new set of scripts
	_newScripts = [_x] call OPAEX_fnc_D20_ParseConfig;
	OPAEX_D20_ScriptList pushback _newScripts;
} forEach _D20List;

//Format of scriptList is [d20, d21, ...], where each entry is an array of scripts, thus looking more like [["D20Script1", "D20Script2"...], ["D21Script1", "D21Script2"...],...]
//Format of D20List is ["nameOfD20", "nameOfD21", ...] which is parallel to the ScriptList.