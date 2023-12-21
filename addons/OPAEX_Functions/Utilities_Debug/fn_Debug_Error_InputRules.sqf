//Jack Moss, aka Spartanjackwar.
/*
This function handles the logging of errors via BIS_fnc_error

No Parameters.
Return: Nothing

Can be executed anywhere.
Can be executed in a nonscheduled environment.

Dependencies:
	None
*/

//Setup parameters
params [];

if (OPAEX_Debug_Mode) then {
	["[OPAEX] (%1) ERROR: parameters outside input rules.", _fnc_scriptNameParent] call BIS_fnc_error;
};
Nil //Return statement