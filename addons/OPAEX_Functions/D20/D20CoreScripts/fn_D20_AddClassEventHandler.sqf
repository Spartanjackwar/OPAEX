//Jack Moss, aka Spartanjackwar.
/*
	This function inits the class event handlers that handle the d20.
	
	Return: Nothing

	Can be executed anywhere.
	Can be executed in a nonscheduled environment.

	Dependencies:
		None
*/

["CAManBase", "Fired", {
	//systemChat str _this; //Debug output that isn't needed.
	_this spawn OPAEX_fnc_D20_Fired;
}] call CBA_fnc_addClassEventHandler;