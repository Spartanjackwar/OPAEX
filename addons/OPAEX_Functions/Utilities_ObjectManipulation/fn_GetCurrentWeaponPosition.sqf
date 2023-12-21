//Jack Moss, aka Spartanjackwar.
/*
Retrieves the position of the currently wielded weapon proxy from a unit.  Intended only for infantry use!

Parameter 0: object: object to detect weapon position for.
Parameter 1: 3D array of floats: offset from gun center to use.

Return: Model-relative position of the unit's weapon proxy.  Note that it is possible that no weapon is in use, in which case we return [0,0,0].

Can be executed in nonscheduled environments.
Can execute anywhere.
*/

params [
	[
		"_unit",
		objNull,
		[objNull]
	],
	[
		"_offset",
		[0,0,0],
		[[0,0,0]]
	]
];

//Get the weapons of the unit.
_rifle = primaryWeapon _unit;
_launcher = secondaryWeapon _unit;
_pistol = handgunWeapon _unit;

//Check which weapon we're using.
_current = currentWeapon _unit;
if (_current isEqualTo _rifle) exitWith {
	[_unit, _offset] call OPAEX_fnc_GetPrimaryWeaponPosition;
};
if (_current isEqualTo _launcher) exitWith {
	[_unit, _offset] call OPAEX_fnc_GetSecondaryWeaponPosition;
};
if (_current isEqualTo _pistol) exitWith {
	[_unit, _offset] call OPAEX_fnc_GetTertiaryWeaponPosition;
};

//Since it's possible to not actually have a current weapon we need a fallback return.
[0,0,0]