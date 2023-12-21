//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Drops a barrier gun on the floor.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.
*/

params [
	[
		"_d20",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_thrower",
		objNull,
		[objNull]
	]
];

//Do the visuals
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//Spawn the gun holder.
_groundHolder = "GroundWeaponHolder" createVehicle _d20;

//Spawn the gun.
_groundHolder addItemCargoGlobal  ["OPAEX_D20_W_Barriergun", 1];
_groundHolder addItemCargoGlobal  ["OPAEX_D20_M_Barriergun", 2];