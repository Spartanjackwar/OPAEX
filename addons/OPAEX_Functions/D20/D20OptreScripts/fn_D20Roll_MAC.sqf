//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: spawns a MAC shot.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	None
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

//We cannot tolerate not being given a thrower
if (isNull _thrower) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

//Do the visuals
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Strike", 0, False];

//Spawn MAC round 60000 meters in air above D20, and yeet it at 30 km/s.
_MAC = "OPTRE_MAC_Round" createVehicle (_d20 vectorAdd [0,0,60000]);
_MAC setVelocity [0,0,-30000];