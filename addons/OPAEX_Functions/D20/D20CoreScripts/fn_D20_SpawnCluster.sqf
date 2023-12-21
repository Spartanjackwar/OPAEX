//Jack Moss, aka Spartanjackwar.
/*
This function spawns a cluster of vehicles.  It is intended to be used for cluster grenades in the d20.

Parameter 0: string: classname of the unit who we spawn.
Parameter 1: int: number of objects to spawn
Parameter 2: 3D array: max velocity with which objects should spawn.
Parameter 2: 3D array: position of unit spawn

Return: Nothing

Can be executed anywhere.
Can be executed in a nonscheduled environment.

Dependencies:
	OPAEX_D20_DebugMode, bool, which is a mission namespace variable.
*/

//Setup parameters
params [
	[
		"_ammoName",
		"",
		[""]
	],
	[
		"_position",
		[0.0, 0.0, 0.0],
		[[0.0, 0.0, 0.0]]
	],
	[
		"_number",
		5,
		[0]
	],
	[
		"_speed",
		[10,10,20],
		[[0,0,0]]
	]
];

_i = 0;
while {_i < _number} do {
	//Spawn the ammo.
	_vehicleHandle = _ammoName createVehicle _position;
	
	//Set the speed to a random ammount capped by the max speed.
	_xAdjustedSpeed = random [((_speed select 0) * -1), 0, (_speed select 0)];
	_yAdjustedSpeed = random [((_speed select 1) * -1), 0, (_speed select 1)];
	_zAdjustedSpeed = random [0, ((_speed select 2) / 2), (_speed select 2)];
	_vehicleHandle setVelocity [_xAdjustedSpeed, _yAdjustedSpeed, _zAdjustedSpeed];
	
	//Increase iterations by 1
	_i = _i + 1;
};