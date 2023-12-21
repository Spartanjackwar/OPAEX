//Jack Moss, aka Spartanjackwar.
/*
Charging weapon framework client info event.  Only displays to players.

Parameter 0: object: Unit that is involved with the charging weapon.
Parameter 1: string: The message to display.
Return: Nothing

Can be executed in unscheduled environments.
Can execute on any client.
*/

params [
	[
		"_firingUnit",
		player,
		[objNull]
	],
	[
		"_msg",
		"ERROR with charging.",
		[""]
	]
];

//Guard against bad inputs.
if (isNull _firingUnit or !local _firingUnit) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
};

//Check if the firing unit is a player.
if (_firingUnit isEqualTo player) then {
	titleText [_msg, "PLAIN DOWN"];
};