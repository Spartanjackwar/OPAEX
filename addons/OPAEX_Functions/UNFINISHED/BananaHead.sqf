if (!hasInterface) exitWith {};

private _unit = player;

_lifetime = 3;
_sizes = [
	1,
	0
];

//Check for insignia
private _OPCOS_Secret_SecretInsignia = "Banana";
private _insignia = ([_unit] call BIS_fnc_getUnitInsignia);
private _OPCOS_Secret_WearingSecretInsignia = ([_OPCOS_Secret_SecretInsignia, _insignia, true] call BIS_fnc_inString);

if (_OPCOS_Secret_WearingSecretInsignia) then {
	OPCOS_BananaHead = "#particlesource" createVehicle (position _unit);
	OPCOS_BananaHead setParticleParams [
		["\z\ace\addons\common\data\banana.p3d", 1, 0, 1], 
		"", 
		"SpaceObject", 
		1,
		_lifetime,
		[0,0,0],
		[0,0,1],
		3,
		10,
		7.9,
		0,
		_sizes,
		[[1,1,1,1]],
		[1],
		1,
		0,
		"",
		"",
		_unit
	];
	OPCOS_BananaHead attachto [_unit, [-0.05, -0.05, 0.15], "head"]; //z is up
} else {
	deleteVehicle OPCOS_BananaHead;
};