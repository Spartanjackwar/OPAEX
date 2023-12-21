//Jack Moss, aka Spartanjackwar.
/*
D20 grenade debugging function which validates the D20 script list associated with the given D20.

Parameter 0: String: Classname of the D20.

Return: Nothing

Can be executed in a nonscheduled environment.
Can be executed anywhere.
*/
params [
	[
		"_D20Name",
		"OPAEX_M_D20",
		[""]
	]
];

private[
	"_scriptList",
	"_len",
	"_len",
	"_msg",
	"_blankCode",
	"_allValid",
	"_invalidName"
];

//Get the scripts
_scriptList = missionNamespace getVariable ["OPAEX_D20_ScriptList",[""]];
_len = count _scriptList;
_msg = "";
_blankCode = {};
_allValid = true;
_invalidName = "";

//Show the length
hintSilent parseText format [
	"<t size='2'>%1</t><br/><t size='1'>%2%3</t><br/><t size='1'>%3%4</t><br/>",
	"OPAEX_D20_ScriptList data:",
	"Name: ", _D20Name,
	"Length: ", _len
];

//Check each script isn't empty.
{
	_allValid = _x isNotEqualTo _blankCode;
	if (!_allValid) exitWith {
		_invalidName = _x;
	}
} ForEach _scriptList;

//Display result
if (_allValid) then {
	_msg = "All scripts valid!";
} else {
	_msg = format["Script invalid! %1 isn't valid.", _invalidName];
};
hintc _msg;