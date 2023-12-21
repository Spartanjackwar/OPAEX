//Jack Moss, aka Spartanjackwar.
/*
Copies a given object's orientation and velocity.  This is intented for bullet copy-paste.

Parameter 0: object: object to copy from.
Parameter 1: object: object to copy to.
Parameter 2: 3d array: position offset from copy object.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client, but should be on server.
*/

params [
	[
		"_copy",
		objNull,
		[objNull]
	],
	[
		"_paste",
		objNull,
		[objNull]
	],
	[
		"_offset",
		[0,0,0],
		[[0,0,0]]
	]
];

if (isNull _copy || isnull _paste) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

_paste setPosWorld (_copy modelToWorldWorld _offset);
_paste setVectorDir vectorDir _copy;
_paste setVectorUp vectorUp _copy;
_paste setVelocity (velocity _copy);