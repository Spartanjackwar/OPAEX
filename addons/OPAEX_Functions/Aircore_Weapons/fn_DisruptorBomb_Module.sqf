//Jack Moss, aka Spartanjackwar.
/*
Parses module input for the disruptorBomb's script.
Parameter 0: logic: module entity.

Return: Nothing

Must execute in a suspendable environment.
Server is passed the actual physical response to freezing.  Headless clients do nothing.
All effects are locally spawned.

Dependencies:
	OPAEX_fnc_DisruptorBomb
*/

//First parameter of a module is the logic entity itself.
_logic = param [
	0,
	objNull,
	[objNull]
];
//Validate _logic, as we cannot tolerate not being given an origin point.
if (isNull _logic) exitWith {};

//Attribute values are saved in module's object space under their class names
_origin = getPos _logic;
_radius = _logic getVariable ["Radius", 150];
_duration = _logic getVariable ["Duration", 30];
_DisplayTimer = _logic getVariable ["DisplayTimer", false];

[_origin, _radius, _duration, _DisplayTimer] spawn OPAEX_fnc_DisruptorBomb;