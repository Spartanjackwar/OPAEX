//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: throws back a Grenade at the thrower.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_D20_Fired
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
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Yeet", 0, False];

_maxHeight = 25;
_g = 9.81;
_ammo = "OPAEX_A_D20";
_mag = "OPAEX_M_D20";

//Get Vvert
_velVert = sqrt(_maxHeight * (2 * _g));

//Get distance to user.
_dist = _d20 distance (getpos _thrower);

//Get VHorz.
_velHorz = _dist * _g / (2 * _velVert);

//Get vector from D20 to user.
_modifierVector = _d20 VectorFromTo (getpos _thrower);

//Apply the vectors by component multiplication.
_newGrenade = _ammo createVehicle _d20;
_newGrenade setVelocity [
	_velHorz * (_modifierVector select 0),
	_velHorz * (_modifierVector select 1),
	_velVert
];

//Fired handler mockup, allowing _thrower and _newGrenade to proceed.
[
	_thrower,
	Nil,
	Nil,
	Nil,
	Nil,
	_mag,
	_newGrenade
] spawn OPAEX_fnc_D20_Fired;