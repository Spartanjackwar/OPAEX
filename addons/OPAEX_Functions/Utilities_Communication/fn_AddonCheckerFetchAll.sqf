//Jack Moss, aka Spartanjackwar.
/*
Function that spews out all addons loaded that aren't arma 3.

No parameters, as the only data needed is pulled from the mission namespace.
Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.
*/

private _mods = [];

//Find all non-Arma 3 addons
{
	if (!(["a3_", _x] call BIS_fnc_inString)) then {
		_mods pushback _x;
		diag_log _x; //Shovel mod into RPT file in case of failed copy-to-clipboard.
	}
} forEach activatedAddons;

//Attempt to dump the mod list to clipboard. Note that this may be too small, hence the above dump to RPT.
copyToClipboard str(_mods);