//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: spawns the banana god himself.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_Lightning
	OPAEX_fnc_D20_SpawnUnit
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
//[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//lightning strike
[_d20] spawn OPAEX_fnc_Lightning;

//announce the bringer of death's arrival via systemChat
_msg = format ["OPAEX: %1 has summoned The Banana God Man himself!",name _thrower];
[0, false, _msg] call OPAEX_fnc_RemoteSystemChat;

//Make the sound of all sounds to annouce the god's coming.
[0, false, _d20, "OPAEX_Sound_D20_EldritchBananaGodBassBoost", 1000, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//spawn the man himself in a cloud of bananas
_ACEEnabled = (configFile >> "CfgPatches" >> "ace_medical") call BIS_fnc_getCfgIsClass;
_model = "";
if (!_ACEEnabled) then {
	_model = "\A3\Props_F_Orange\Humanitarian\Supplies\Pumpkin_01_F.p3d";
} else {
	_model = "\z\ace\addons\common\data\banana.p3d";
};
_sizesBanana = [10.0, 0.0];
_bananaLifespan = 2;
_baseVelocity = [0, 0, 1];
_banana = "#particlesource" createVehicle _d20;
_banana setParticleRandom [0, [0, 0, 0], [5, 5, 1], 0, 0, [0, 0, 0, 0], 360, 0];
_banana setParticleParams [[_model, 1, 0, 1], "", "SpaceObject", 1, _bananaLifespan, [0, 0, 0], _baseVelocity, 3, 10, 7.9, 0, _sizesBanana, [[1,1,1,1]], [1], 1, 0, "", "", _d20];
_banana setDropInterval 0.001;
sleep 1;
deleteVehicle _banana;

//set banana man on side inverse of the thrower, but on sideEnemy.  Also set identity.
_bananaGodGroupname = createGroup east;
_bananaGodClassname = "OPAEX_D20_UNSC_Army_Soldier_BananaGod";
_godHimself = [_bananaGodGroupname, _bananaGodClassname, _d20] call OPAEX_fnc_D20_SpawnUnit;
_godHimself addRating -666000;
_godHimself setAnimSpeedCoef 2;
[_godHimself, "BananaGod"] remoteExec ["setIdentity", 0, _godHimself];
