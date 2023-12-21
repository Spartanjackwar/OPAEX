//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll visuals.  This one is a banana wall.
Note that if ACE isn't installed, oranges will be used.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: float: Lifetime of the particle emitter

Return: Nothing

Must be executed in scheduled environment.
Can execute on any client, but should execute everywhere.
*/

params [
	[
		"_d20",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_emmiterLifetime",
		1,
		[1]
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
	_model = "\A3\Props_F_Orange\Humanitarian\Supplies\Pumpkin_01_F.p3d";
} else {
	_model = "\z\ace\addons\common\data\banana.p3d";
};

//Locally build the particle emitter.
_sizesBanana = [10.0, 0.0];
_bananaLifespan = 2;
_baseVelocity = [0, 0, 1];
_banana = "#particlesource" createVehicleLocal _d20;
_banana setParticleRandom [0, [5, 5, 0], [0, 0, 5], 0, 0, [0, 0, 0, 0], 360, 0];
_banana setParticleParams [[_model, 1, 0, 1], "", "SpaceObject", 1, _bananaLifespan, [0, 0, 0], _baseVelocity, 3, 10, 7.9, 0, _sizesBanana, [[1,1,1,1]], [1], 1, 0, "", "", _d20];
_banana setDropInterval 0.001;

//Await the lifetime.
sleep _emmiterLifetime;
deleteVehicle _banana;