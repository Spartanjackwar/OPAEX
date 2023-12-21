//Jack Moss, aka Spartanjackwar.
/*
This function returns the skeleton classname of a unit.

Parameter 0: object/string: unit whose skeleton to check.
Parameter 1: bool: should the function treat parameter 0 as a string?

Return: String, classname of the skeleton in use.

Any machine may execute this.  Can be executed in nonscheduled environments.

Dependencies:
	None
*/
params
[
	[
		"_unit",
		Player,
		[objNull, ""] //Strings should only be passed when _classNameMode is True
	],
	[ //Should we regard unit as a string?
		"_classNameMode",
		False,
		[True]
	]
];

_skeleton = Nil;
_moves = Nil;

if (!_classNameMode) then
{
	_unitClassName = typeof _unit;
	//_moves = getText (configFile >> "CfgVehicles" >> _unitClassName >> "moves");
	_moves = (configFile >> "CfgVehicles" >> _unitClassName >> "moves") call BIS_fnc_getCfgData;
} else {
	//_moves = getText (configFile >> "CfgVehicles" >> _unit >> "moves");
	_moves = (configFile >> "CfgVehicles" >> _unit >> "moves") call BIS_fnc_getCfgData;
};

//_skeleton = getText (configFile >> _moves >> "skeletonName");
_skeleton = (configFile >> _moves >> "skeletonName") call BIS_fnc_getCfgData;

["OPAEX: function returned %1", _skeleton] call BIS_fnc_logFormat;
_skeleton //return the skeleton's name.