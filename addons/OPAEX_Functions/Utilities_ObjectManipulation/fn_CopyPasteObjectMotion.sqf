//Jack Moss, aka Spartanjackwar.
/*
Copies a given object's orientation and velocity.  This is intented for bullet copy-paste.

Parameter 0: object: object to copy from.
Parameter 1: object: object to copy to.

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
	]
];

[_copy, _paste, [0,0,0]] call OPAEX_fnc_CopyPasteObjectMotionWithOffset;