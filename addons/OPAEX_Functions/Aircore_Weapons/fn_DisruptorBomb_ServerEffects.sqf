//Jack Moss, aka Spartanjackwar.
/*
This function represents a disruptor bomb via removing a vehicle's ammo and fuel and attaching.
Parameter 0: position: origin of bomb explosion
Parameter 1: int: radius
Parameter 2: int: number of seconds for 'EMP' to last.
Parameter 3: bool: if the timer should show up on screen.

Return: Nothing

Must execute in a suspendable environment.
Server is passed the actual physical response to freezing.  Headless clients do nothing.

Dependencies:
	OPAEX_fnc_EMP
*/
if (!isServer or !canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

//Parameters
params [
	[
		"_OPAEX_DisruptorBomb_origin",
		[0.0, 0.0, 0.0],
		[[0.0, 0.0, 0.0]]
	],
	[
		"_OPAEX_DisruptorBomb_radius",
		300,
		[1]
	],
	[
		"_OPAEX_DisruptorBomb_duration",
		30,
		[1]
	],
	[
		"_displayTimer",
		False,
		[True]
	]
];

//Freeze objects and EMP them server-side.
_List = _OPAEX_DisruptorBomb_origin nearEntities _OPAEX_DisruptorBomb_radius;

_EMPallowed = [];
{//Filter out objects that are game logic or infantry from EMP.
	if (!(_x isKindOf "Logic") && !(_x isKindOf "Man")) then
	{
		_EMPallowed pushback _x;
	};
} ForEach _List;

//EMP the objects in list and wait for completion.
_EMPScriptHandle = [_EMPallowed, _OPAEX_DisruptorBomb_duration, _displayTimer] spawn OPAEX_fnc_EMP;