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

_duration = 3;
_radius = 30;

//Basics
_dropInterval = _duration / 100;
_timerPeriod = 0;
_lifetime = _duration;
_positionOffset = [0, 0, 0];
_moveVelocity = [0, 0, 0.5];
_rotationVelocity = 1;
_weight = 50;
_volume = 40;
_rubbing = 0;
_size = [
	_radius / 2
];
_colour = [
	[0.33, 1, 0.33, 0.2],
	[0.33, 1, 0.33, 0.2],
	[0.33, 1, 0.33, 0.2],
	[0.66, 1, 0.66, 0.05]
];
_animSpeed = [1];
_randomDirectionPeriod = 0.2;
_randomDirectionIntensity = 0.2;
_onTimerScript = "";
_beforeDestroyScript = "";
_attachObject = objNull;
_attachAngle = 0;
_placeOnWaterSurface = false;
_BounceOnGroundCollision = -1; //-1 disables collision.  It's actually a coefficient from 0-1.
_emissiveColour = _colour;

//Random
_lifeTimeVar = 0;
_offsetPositionVar = [0, 0, 0];
_moveVelocityVar = [0, 0, 0];
_rotationVelocityVar = 0;
_sizeVar = 0;
_colorVar = [0, 0, 0, 0];
_randomDirectionPeriodVar = 0;
_randomDirectionIntensityVar = 0;
_angleVar = 360;
_surfaceCollisionSpeedVar = 0;

//=======================================================
//Confetti effects.
_smokeClouds = "#particlesource" createVehicle _d20;
_smokeClouds setParticleParams [
	[
		"A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 7, 48, 1
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
	_smokeClouds,
	_attachAngle,
	_placeOnWaterSurface,
	_BounceOnGroundCollision,
	_emissiveColour
];
_smokeClouds setParticleRandom [
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
_smokeClouds setParticleCircle [_radius, [0, 0, 0]];
_smokeClouds setDropInterval _dropInterval;

//Sound
[0, false, _d20, "OPAEX_Sound_D20_GBP", 300, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//Remove Confetti
sleep _duration;
deleteVehicle _smokeClouds;