//Jack Moss, aka Spartanjackwar.
/*
Wrapper for the charging weapon framework's extended initPost.
This function is needed since string expressions don't support all types.

Parameter 0: object: the unit firing the laser.
Parameter 1: string: Muzzle name of the weapon to use a charge sequence for.
Parameter 2: 3D array of floats: Colour values of the beam.  [0, 0, 0] is RGB gamer mode.
Parameter 3: float: Length in seconds of the charge time for the laser.

Return: Nothing

Can be executed in nonscheduled environments.
Needs to be executed on the server.
*/
params [
	[
		"_firingUnit",
		objNull,
		[objNull]
	],
	[
		"_muzzle",
		"OPAEX_SpartanLaser",
		[""]
	],
	[
		"_beamColor",
		[100, 0, 0],
		[[0, 0, 0]]
	],
	[
		"_chargeDuration",
		3,
		[1]
	]
];

//Ensure that the server is our current machine.
if (!isServer) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

private [
	"_weaponToStop"
];
_weaponToStop = _muzzle;
//_beamColor = [121, 150, 39] apply {(_x / 255) * 10}; //Banana

[
	_firingUnit,
	_weaponToStop,
	{
		params ['_target', '_muzzle', '_chargeDuration', '_beamColor'];
		[
			_target,_muzzle, _chargeDuration, _beamColor
		] remoteExec [
			"OPAEX_fnc_ChargedWeaponController",
			2
		];
	},
	[_firingUnit, _muzzle, _chargeDuration, _beamColor]
] remoteExec [
	"OPAEX_fnc_stopFireAction",
	0,
	_firingUnit //Passing in an object allows us to keep attached to it for JIP purposes.
];