//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: wrapper for createSimpleObject.

Parameter 0: string/object: thrower of the d20.
Parameter 1: 3d array: position of the d20 greande.

Return: object created via createSimpleObject

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	None
*/

params [
	[
		"_objectClassName",
		objNull,
		["", objNull]
	],
	[
		"_d20",
		[0,0,0],
		[[0,0,0]]
	]
];

//Convert objects to names.
if (_objectClassName isEqualType objNull) then
{
	_objectClassName = typeOf _objectClassName;
};

//We cannot tolerate not being given a classname
if (_objectClassName isEqualTo "") exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

//Assume it exists and attempt the spawn.
_object = createSimpleObject [_objectClassName, _d20];
