//Jack Moss, aka Spartanjackwar.
/*
D20 helper, specifically built for the barrier gun.

Parameter 0: object: bullet to spawn barrier in-place of.

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

_barriers = [
	"Land_OPTRE_M72_barrier",
	"Land_OPTRE_M72_barrierTan",
	"Land_OPTRE_M72_barrierBlk",
	"Land_OPTRE_M72S_barrier",
	"Land_OPTRE_M72S_barrierTan",
	"Land_OPTRE_M72S_barrierBlk"
];

_barrierType = selectRandom _barriers;
_newBarrier = createVehicle [_barrierType, [0,0,0]];
[_bullet, _newBarrier, [0,2,0]] call OPAEX_fnc_CopyPasteObjectMotionWithOffset;