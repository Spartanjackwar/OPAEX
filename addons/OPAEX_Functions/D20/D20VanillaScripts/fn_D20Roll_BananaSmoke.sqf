//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: smoke grenade with banana effects.
Note that if ACE isn't installed, pumpkins will be used.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

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
	],
	[
		"_thrower",
		objNull,
		[objNull]
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
	//_model = "\A3\Props_F_Orange\Humanitarian\Supplies\Orange_01_F.p3d";
	_model = "\A3\Props_F_Orange\Humanitarian\Supplies\Pumpkin_01_F.p3d";
} else {
	_model = "\z\ace\addons\common\data\banana.p3d";
};

//Begin effect
_sizesBanana = [10.0, 0.0];
_bananaLifespan = 60;
_baseVelocity = [0, 0, 0];
_banana = "#particlesource" createVehicle _d20; //Potentially make this local?
_banana setParticleRandom [0, [0, 0, 0], [5, 5, 1], 0, 0, [0, 0, 0, 0], 360, 0];
_banana setParticleParams [[_model, 1, 0, 1], "", "SpaceObject", 1, _bananaLifespan, [0, 0, 0], _baseVelocity, 3, 10, 7.9, 0, _sizesBanana, [[1,1,1,1]], [1], 1, 0, "", "", _d20];
//_banana setParticleCircle [2, [0, 0, 5]]; //circles don't appear to work on space objects.
_banana setDropInterval 0.001;

//Sound
//playSound3D ["OPAEX_D20\GBPSound.ogg", objNull, false, _d20, 5, 1, 100];
//playSound3D [getMissionPath "d20\Yeet.ogg", objNull, false, _d20, 5, 1, 100];
//playSound3D [getMissionPath "d20\EldritchBananaGodBassBoost.ogg", objNull, false, _d20, 5, 1, 1000];
//playSound3D ["\OPAEX_D20\EldritchBananaGodBassBoost.ogg", objNull, false, _d20, 5, 1, 1000];
[0, false, _d20, "OPAEX_Sound_D20_EldritchBananaGodBassBoost", 1000, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//Remove effect
sleep 1;
deleteVehicle _banana;