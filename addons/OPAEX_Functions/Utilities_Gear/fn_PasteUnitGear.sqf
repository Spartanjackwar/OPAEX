//Jack Moss, aka Spartanjackwar.
/*
This function copies a unit's loadout into another unit.
Only works on infantry who are not in vehicles.
Will handle vehicles by silently returning false.

Note that this is intended for copy units that were edited after spawning, as there is an easier method of doing this otherwise.
Instead of using this to paste a new unit, use this: _pasteTarget setUnitLoadout (getUnitLoadout _copyTarget);
Note, this function's method should account for unfilled mags correctly, unlike the loadout method.

Parameter 0: object: unit whose loadout we copy
Parameter 1: object: unit who we paste loadout to

Return: Bool, false is failed, true if success.

Client must execute this.  Can be executed in nonscheduled environments.

Dependencies:
	OPAEX_fnc_ClearUnitGear
*/
if (!hasInterface) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	False
};

//Setup parameters
params [
	[
		"_copyTarget",
		objNull,
		[objNull]
	],
	[
		"_pasteTarget",
		objNull,
		[objNull]
	]
];

//Validate input for null values.
if (isNull _copyTarget or isNull _pasteTarget) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	["OPAEX: function returned %1", False] call BIS_fnc_logFormat;
	False
};
//Validate input for noninfantry.
if (!(isNull objectParent _copyTarget) or !(isNull objectParent _pasteTarget)) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	["OPAEX: function returned %1", False] call BIS_fnc_logFormat;
	False
};

//Prepare copy by clearing first to prevent override failures.
[_pasteTarget] call OPAEX_fnc_ClearUnitGear;

//Copy gear and weapons
_g = goggles _copyTarget;
_h = headgear _copyTarget;
_v = vest _copyTarget;
_u = uniform _copyTarget;
_b = backpack _copyTarget;
_a = assignedItems _copyTarget;
_vestItems = vestItems _copyTarget;
_uniformItems = uniformItems _copyTarget;
_backpackItems = backpackItems _copyTarget;
_w = weapons _copyTarget;

//Paste gear
_pasteTarget addGoggles _g;
_pasteTarget addHeadgear _h;
_pasteTarget addVest _v;
_pasteTarget addUniform _u;
_pasteTarget addBackpack _b;
{ //Paste the GPS, map, radio, compass, watch, and binoculars.
	_pasteTarget addItem _x;
	_pasteTarget assignItem _x;
} ForEach _a;
{ //Paste the vest contents, assuming unequal capacities don't exist.
	_pasteTarget addItemToVest _x;
} forEach _vestItems;
{ //Paste the uniform contents, assuming unequal capacities don't exist.
	_pasteTarget addItemToUniform _x;
} forEach _uniformItems;
{ //Paste the backpack contents, assuming unequal capacities don't exist.
	_pasteTarget addItemToBackpack _x;
} forEach _backpackItems;

{ //Add weapons, note that this is the only part of this script that needs local units
	_pasteTarget addWeapon _x;
} forEach _w;

["OPAEX: function returned %1", True] call BIS_fnc_logFormat;
True //Return statement.