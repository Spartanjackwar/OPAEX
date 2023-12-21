//Jack Moss, aka Spartanjackwar.
/*
This function teleports a user to a position, effectively just a setPos wrapper.

Parameter 0: 3D array: position to teleport.
Parameter 1: object: thrower of d20.

Return: Nothing

Can be executed anywhere.
Can be executed in a nonscheduled environment.

Dependencies:
	None
*/

//Setup parameters
params [
	[
		"_position",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_thrower",
		player,
		[objNull]
	]
];

//Validate the thrower exists.
if (isNull _thrower) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

//Teleport unit
_thrower setPos _position;

//Return nil, just in case some nucklehead didn't read the documentation I wrote.
["OPAEX: function returned %1", Nil] call BIS_fnc_logFormat;
Nil //Return statement