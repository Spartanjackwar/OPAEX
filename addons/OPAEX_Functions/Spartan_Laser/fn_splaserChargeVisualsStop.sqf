//Jack Moss, aka Spartanjackwar.
/*
Charging framework visuals stop sequence.

Parameter 0: object: Unit that is involved with the laser.

Return: Nothing

Can be executed in non-scheduled environment.
Can execute on any client.
*/

params [
	[
		"_firingUnit",
		player,
		[objNull]
	]
];

//Validate firing unit.
if (isNull _firingUnit) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
};

//Get the handler. TODO: allow dynamic variable names.
private _visualsHandle = _firingUnit getVariable ["OPAEX_Splaser_AimingLaserHandler", -1];

//Remove the laser beam draw.
removeMissionEventHandler ["Draw3D", _visualsHandle];

//Remove the handler id.
_firingUnit setVariable ["OPAEX_Splaser_AimingLaserHandler", -1];