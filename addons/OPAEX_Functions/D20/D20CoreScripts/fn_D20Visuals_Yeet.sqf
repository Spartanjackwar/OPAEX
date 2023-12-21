//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll visuals.  This one is the yeet sound with banana effects.
Note that if ACE isn't installed, oranges will be used.

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

//Find out if ACE is on.
_ACEEnabled = (configFile >> "CfgPatches" >> "ace_medical") call BIS_fnc_getCfgIsClass;

//Choose which model to use as the effect.
_model = "";
if (!_ACEEnabled) then {
	_model = "\A3\Props_F_Orange\Humanitarian\Supplies\Orange_01_F.p3d";
} else {
	_model = "\z\ace\addons\common\data\banana.p3d";
};

//Begin effect
_sizesBanana = [2.0, 0.0];
_bananaLifespan = 1.5;
_baseVelocity = [0, 0, 3];
_banana = "#particlesource" createVehiclelocal _d20; //Potentially make this global?
_banana setParticleRandom [0, [0, 0, 0], [5, 5, 5], 0, 0, [0, 0, 0, 0], 360, 0];
_banana setParticleParams [[_model, 1, 0, 1], "", "SpaceObject", 1, _bananaLifespan, [0, 0, 0], _baseVelocity, 3, 10, 7.9, 0, _sizesBanana, [[1,1,1,1]], [1], 1, 0, "", "", _d20];
_banana setDropInterval 0.01;

//Sound
[0, false, _d20, "OPAEX_Sound_D20_Yeet", 300, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//Remove effect
sleep 1;
deleteVehicle _banana;