//Jack Moss, aka Spartanjackwar.
/*
This function clears a unit's loadout completely.
Works on infantry only, vehicles will cause a silent return of False.

Parameter 0: object: unit whose loadout we copy

Return: Bool, false is failed, true if success.

May be executed on any machine.
Can be executed in nonscheduled environments.

Dependencies:
	None
*/
//Setup parameters
params [
	[
		"_unit",
		objNull,
		[objNull]
	]
];

//Validate unit is valid.
if (isNull _unit or !(isNull objectParent _unit)) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	["OPAEX: function returned %1", False] call BIS_fnc_logFormat;
	False
};

[{
	removeGoggles _unit;
	removeHeadgear _unit;
	removeBackpack _unit;
	removeVest _unit;
	removeUniform _unit;

	//Delete GPS, radio, compass, watch, map, and binoculars.
	removeAllAssignedItems _unit;

	//Remove weapons
	_unit removeWeapon (primaryWeapon _unit);
	_unit removeWeapon (secondaryWeapon _unit);
}] remoteExec ["call", (owner _unit), False]; //Remote exec allows handling locality of units.

["OPAEX: function returned %1", True] call BIS_fnc_logFormat;
True //Return statement.