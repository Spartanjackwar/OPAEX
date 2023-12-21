//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll visuals.  This one is the grunt birthday party.

Parameter 0: 3d array: position of the d20 greande.

Return: Nothing

Must be executed in scheduled environment.
Can execute on any client.
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

//Basics
_dropInterval = 0.1;
_timerPeriod = 1;
_lifetime = 1;
_positionOffset = [0, 0, 0];
_moveVelocity = [0, 0, 0];
_rotationVelocity = 0;
_weight = 1.1;
_volume = 0.8;
_rubbing = 0.5;
_size = [0.1, 0.1, 0.2, 0.2, 0.2, 0.2, 0.2];
_colour = [
	[1, 0, 0, 1],
	[0, 1, 0, 1],
	[0, 0, 1, 1]
];
_animSpeed = [1.5];
_randomDirectionPeriod = 0.2;
_randomDirectionIntensity = 0.2;
_onTimerScript = "";
_beforeDestroyScript = "";
_attachObject = objNull;
_attachAngle = 0;
_placeOnWaterSurface = 0;
_BounceOnGroundCollision = 0;
_emissiveColour = _colour;

//Random
_lifeTimeVar = 3;
_offsetPositionVar = [2, 2, 2];
_moveVelocityVar = [3, 3, 3];
_rotationVelocityVar = 10;
_sizeVar = 0.03;//0.3;
_colorVar = [2, 1, 1, 0];
_randomDirectionPeriodVar = 0;
_randomDirectionIntensityVar = 0;
_angleVar = 360;
_surfaceCollisionSpeedVar = 0;

//=======================================================
//Confetti effects.
_confetti = "#particlesource" createVehicleLocal _d20;
_confetti setParticleClass "Cmeasures3";
_confetti setParticleRandom [
	_lifeTimeVar,
	_offsetPositionVar,
	_moveVelocityVar,
	_rotationVelocityVar,
	_sizeVar,
	_colorVar,
	_randomDirectionPeriodVar,
	_randomDirectionIntensityVar,
	_angleVar,
	_surfaceCollisionSpeedVar
];
_confetti setParticleParams [
	[
		"\A3\data_f\ParticleEffects\Universal\Universal.p3d",
		16,
		14,
		5,
		1
	],
	"",
	"Billboard",
	_timerPeriod,
	_lifetime,
	_positionOffset,
	_moveVelocity,
	_rotationVelocity,
	_weight,
	_volume,
	_rubbing,
	_size,
	_colour,
	_animSpeed,
	_randomDirectionPeriod,
	_randomDirectionIntensity,
	_onTimerScript,
	_beforeDestroyScript,
	_attachObject,
	_attachAngle,
	_placeOnWaterSurface,
	_BounceOnGroundCollision,
	_emissiveColour
];
_confetti setDropInterval _dropInterval;

//Sound
[0, false, _d20, "OPAEX_Sound_D20_GBP", 300, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//Remove Confetti
sleep 1;
deleteVehicle _confetti;