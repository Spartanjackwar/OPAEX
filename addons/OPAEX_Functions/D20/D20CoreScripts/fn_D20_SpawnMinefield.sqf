//Jack Moss, aka Spartanjackwar.
/*
This function spawns a minefield.

Parameter 0: string: classname of the unit who we spawn.
Parameter 1: int: number of objects to spawn
Parameter 2: 3D array: max velocity with which objects should spawn.
Parameter 3: int: radius of the field

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
		"_position", //For centerpoint.
		[0.0, 0.0, 0.0],
		[[0.0, 0.0, 0.0]]
	],
	[
		"_number",
		5,
		[0]
	],
	[
		"_radius",
		50,
		[0]
	]
];

for "_i" from 0 to _number do{	
	_newPos = _position vectorAdd [random _radius, random _radius, 0];
	_ammoName createVehicle _newPos;
};