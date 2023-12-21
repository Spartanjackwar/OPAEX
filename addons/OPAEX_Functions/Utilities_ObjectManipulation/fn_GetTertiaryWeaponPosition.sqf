//Jack Moss, aka Spartanjackwar.
/*
Retrieves the position of the pistol proxy from a unit.  Intended only for infantry use!

Parameter 0: object: object to detect weapon position for.
Parameter 1: 3D array of floats: offset from gun center to use.

Return: ASL position of the unit's pistol proxy.

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
//TODO: make a function that finds the proxy name in case of other skeletons.
[_unit, "proxy:\a3\characters_f\proxies\pistol.001", _offset] call OPAEX_fnc_GetSelectionPosition;