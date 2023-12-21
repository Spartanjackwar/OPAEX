//Jack Moss, aka Spartanjackwar.
/*
Charging weapon framework's interrupt checking function.

Parameter 0: object: Unit that is involved with the laser.
Parameter 1: string: The weapon to handle.  Should actually be the muzzle.

Return: String or nil.  Nil if interrupt is not present.

Can be executed in unscheduled environments.
Can execute on any client.
*/

params [
	[
		"_firingUnit",
		player,
		[objNull]
	],
	[
		"_muzzleToHandle",
		"OPAEX_SpartanLaser",
		[""]
	]
];

//Check for already charging, also known as an interrupt, case.
private _isCharging = _firingUnit getVariable ["OPAEX_IsCharging", false];
if (!_isCharging) exitWith {
	"You cancelled the charging sequence.";
};

//Check for animation cancel case.
private _animState = animationState _firingUnit;
private _animCancel = ( _animState find "slow" >= 0) or (_animState find "meva" >= 0) or (_animState find "sras" >= 0 and _animState find "mrun" >= 0) or (_animState find "adve" >= 0) or (_animState find "halofreefall" >= 0);
if (_animCancel) exitWith {
	"Your animation state cancelled the shot!  Keep the gun raised!";
};

//Check for gun switched case.
if (currentMuzzle _firingUnit isNotEqualTo _muzzleToHandle) exitWith {
	"You switched guns!  Charging sequence aborted.";
};

//Check for out-of-ammo case.
private _hasAmmo = (_firingUnit ammo _muzzleToHandle) > 0;
if (!_hasAmmo) exitWith {
	"You have no ammo!";
};

//TODO: Check for the during-Reload case.

//Check for dead case.
private _isDead = !(alive _firingUnit);
if (_isDead) exitWith {
	"You're dead, so the charging sequence has stopped.";
};

"";
