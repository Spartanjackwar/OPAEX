//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Heals any unit inside a radius.  ACE compatible.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_D20Visuals_Party
*/

params [
	[
		"_d20",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_thrower",
		objNull,
		[objNull]
	]
];

//We cannot tolerate not being given a thrower
if (isNull _thrower) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

//Do the visuals
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Heal", 0, False];

_radius = 30;

//Find the units inside the radius that are soldiers
_nearbyEnts = _d20 nearEntities _radius;
_nearbyMen = [];
{//Filter out objects that are not infantry
	if (_x isKindOf "CAManBase") then
	{
		_nearbyMen pushback _x;
	};
} ForEach _nearbyEnts;

//Find out if ACE is on.
_ACEEnabled = (configFile >> "CfgPatches" >> "ace_medical") call BIS_fnc_getCfgIsClass;

//Heal the player using ACE or default set damage.
if (_ACEEnabled) then {
	{
		[_thrower, _x] call ace_medical_treatment_fnc_fullHeal;
	} forEach _nearbyMen;
} else {
	{
		_x setDamage 0;
	} forEach _nearbyMen;
};