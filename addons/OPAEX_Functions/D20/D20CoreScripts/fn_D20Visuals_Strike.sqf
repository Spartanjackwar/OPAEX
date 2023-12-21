//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll visuals.  This one is the grunt birthday party.

Parameter 0: 3d array: position of the d20 greande.

Return: Nothing

Must be executed in scheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_RemoteSay3D
*/

params [
	[
		"_d20",
		[0,0,0],
		[[0,0,0]]
	]
];

if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	Nil
};

//Red smoke effect
_smoke = "SmokeShellRed" createVehicle _d20;

//Sound
[0, false, _d20, "OPAEX_Sound_D20_StrategicLaunchDetected", 1000, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//Remove smoke
sleep 10;
deleteVehicle _smoke;