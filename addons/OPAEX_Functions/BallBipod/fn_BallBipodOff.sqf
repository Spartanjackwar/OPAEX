//Jack Moss, aka Spartanjackwar.
/*
Function to shut off the ball bipod on a unit.

Parameter 0: object: Unit in the bipod stance.
Parameter 1: number: index of the handler to remove.
Parameter 2: object: brick to remove.

Return: Nothing

Can be executed in nonscheduled environment.
Execute anywhere.
*/
params [
	[
		"_unit",
		objNull,
		[objNull]
	],
	[
		"_index",
		-1,
		[1]
	],
	[
		"_brick",
		objNull,
		[objNull]
	]
];
//Abort non interfaced clients.
if (!(hasInterface) or (isDedicated)) exitWith {};

//Check index and brick exists.
if (_index <= -1) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
};
if (isNull _brick || isNull _unit) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
};

//Delete the nut brick.
deleteVehicle _brick;

//Remove the handler loop.
_unit removeEventHandler ["AnimDone", _index];

//Begin the anim exit, given life, since the loop has ended.
if (!alive _unit) exitWith {nil};
_unit playMove "OPAEX_BallBipod_Exit";

//Remove the variables!
_unit setVariable ["OPAEX_BallBipodHandler", nil, true];
_unit setVariable ["OPAEX_BallBipodBrick", nil, true];
