//Jack Moss, aka Spartanjackwar.
/*
Function that spews out addons loaded that don't meet an expected set.

No parameters, as the only data needed is pulled from the mission namespace.
Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.
*/

//Verify system is on.
private _isEnabled = missionNamespace getVariable ["OPAEX_ExpectedAddonsCheckerEnabled", false];
if (!_isEnabled) exitWith {nil;};

//Grab list of addons.
private _modsExpected = missionNamespace getVariable ["OPAEX_ExpectedAddonsList", []];
private _mods = [];
private _sideMods = [];

//Find all non-Arma 3 addons
{
	if (!(["a3_", _x] call BIS_fnc_inString)) then {_mods pushback _x;}
} forEach activatedAddons;

//Find the set containing only the side mods.
_sideMods = _mods - _modsExpected;

//Send the message that the user is loading an unexpected mod.
{
	_msg = "[OPAEX addonChecker]: " + profileNameSteam + " loaded unexpected mod: " + _x;
	[0, false, _msg] call OPAEX_fnc_RemoteSystemChat;
} forEach _sideMods;