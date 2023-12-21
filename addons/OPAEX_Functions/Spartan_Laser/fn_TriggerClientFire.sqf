//Jack Moss, aka Spartanjackwar.
/*
Charging weapon framework client fire event.

Parameter 0: object: Unit that is involved with the laser.
Parameter 1: string: The weapon to handle.  Should actually be the muzzle.
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
		"_muzzleToHandle",
		"OPAEX_SpartanLaser",
		[""]
	]
];

//Guard against bad inputs.
if (isNull _firingUnit or !local _firingUnit) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
};

//TODO: Run the firing visuals.

//Fire the weapon.
_firingUnit fire _muzzleToHandle;

//TODO: Stop the firing visuals.