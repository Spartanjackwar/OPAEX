//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns an illumination bomb from OPAEX.

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
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//Setup the bomb and settings for it.
_bomb = "OPAEX_A_Mk127" createVehicle (_d20 vectorAdd [0,0,2000]);
_IlluminationPower = 0.10;
_IlluminationRange = 2000;

//Color parse
_R = 1.0;
_G = 1.0;
_B = 1.0;
_RGB = [_R, _G, _B];

//Drop the bomb script
[_bomb, _IlluminationPower, _IlluminationRange, _RGB] spawn OPAEX_fnc_Mk127;