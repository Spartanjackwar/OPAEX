//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns an animal.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_D20_SpawnVehicleEmpty
	OPAEX_fnc_D20Visuals_Party
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

if (isNull _thrower) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

//Do the visuals
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

_types = [
	//Snakes
	"Snake_random_F",
	"Snake_vipera_random_F",
	
	//Rabbits
	"Rabbit_F",
	
	//Chickens
	"Hen_random_F",
	"Cock_random_F",
	"Cock_white_F",
	
	//Goats+Sheep
	"Goat_random_F",
	"Sheep_random_F",
	
	//Dogs
	"Fin_sand_F",
	"Fin_blackwhite_F",
	"Fin_ocherwhite_F",
	"Fin_tricolour_F",
	"Fin_random_F",
	"Alsatian_Sand_F",
	"Alsatian_Black_F",
	"Alsatian_Sandblack_F",
	"Alsatian_Random_F",
	
	//Fish and aquatic creatures
	"Salema_F",
	"Ornate_random_F",
	"Mackerel_F",
	"Tuna_F",
	"Mullet_F",
	"CatShark_F",
	"Turtle_F"
];
_animal = selectRandom _types;
_grp = createGroup civilian;
//Make the animal
//[_animal, _d20] call OPAEX_fnc_D20_SpawnVehicleEmpty;

[_grp, _animal, _d20] call OPAEX_fnc_D20_SpawnUnit;