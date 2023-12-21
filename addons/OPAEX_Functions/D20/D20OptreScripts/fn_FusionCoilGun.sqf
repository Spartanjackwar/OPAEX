//Jack Moss, aka Spartanjackwar.
/*
D20 helper, specifically built for the fusion-coil gun.

Parameter 0: object: bullet to spawn explosive in-place of.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client, but should be on server.
*/

params [
	[
		"_bullet",
		objNull,
		[objNull]
	]
];

if (isNull _bullet) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

_coils = [
	"Land_OPTRE_fusion_coil",
	"Land_OPTRE_barrel_hydrogen"
];

_coilType = selectRandom _coils;
_newcoil = createVehicle [_coilType, [0,0,0]];
[_bullet, _newcoil, [0,2,0]] call OPAEX_fnc_CopyPasteObjectMotionWithOffset;