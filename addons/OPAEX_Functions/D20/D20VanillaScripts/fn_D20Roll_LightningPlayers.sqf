//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Lightning strikes players in a radius about the d20.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_Lightning
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
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//Strike the grenade in case of no players nearby, just to communicate the effect.
[_d20] spawn OPAEX_fnc_Lightning;

//Strike the nearby players
_radius = 50;
_nearby = _d20 nearEntities _radius;
{
	if (isPlayer _x) then {
		[getpos _x] spawn OPAEX_fnc_Lightning;
	};
} forEach _nearby;