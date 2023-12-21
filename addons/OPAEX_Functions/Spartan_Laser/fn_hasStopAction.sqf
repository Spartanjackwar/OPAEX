//Jack Moss, aka Spartanjackwar.
/*
Function to check if a unit has an action that prevents firing for a specific gun.
Note that we store a list of action info in the unit to allow working with multiple stop fire instances.
Each action info is a 2D array containing the actionID and weapon name, in that order.

Parameter 0: object: Unit that is involved.
Parameter 1: string: Weapon classname that we must halt.
Parameter 2: string: Variable name that we use to store the action ID list.  Assumed that it was attached to the given unit.

Return: bool.

Can be executed in non-scheduled environment.
Can execute on any client.
*/

params [
	[
		"_firingUnit",
		player,
		[objNull]
	],
	[
		"_weaponToStop",
		"",
		[""]
	],
	[
		"_actionIDStoreName",
		"OPAEX_StopFireActionIDs",
		[""]
	]
];

private [
	"_actionInfoList",
	"_foundWeapon"
];
_foundWeapon = false;

//Get the unit's action info.
_actionInfoList = _firingUnit getVariable [_actionIDStoreName, []];

//Check if weapon is in the list.
{
	private _muzzle = _x select 1;
	if (_muzzle isEqualTo _weaponToStop) exitWith {_foundWeapon = true};
} forEach _actionInfoList;

_foundWeapon //return statement.