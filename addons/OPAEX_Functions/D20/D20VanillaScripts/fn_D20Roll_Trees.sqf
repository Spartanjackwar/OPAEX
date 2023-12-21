//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: spawns trees.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	None
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
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//Due to weirdness in the Z coords of the trees, I have an array for adjusting Z's, as given by sbondo1234's guide found at: https://steamcommunity.com/sharedfiles/filedetails/?id=1570052786
_trees = [
	"a3\plants_f\Tree\t_BroussonetiaP1s_F.p3d",
	"a3\plants_f\Tree\t_FicusB1s_F.p3d",
	"a3\plants_f\Tree\t_FicusB2s_F.p3d",
	"a3\plants_f\Tree\t_FraxinusAV2s_F.p3d",
	"a3\plants_f\Tree\t_OleaE1s_F.p3d",
	"a3\plants_f\Tree\t_OleaE2s_F.p3d",
	"a3\plants_f\Tree\t_PhoenixC1s_F.p3d",
	"a3\plants_f\Tree\t_PhoenixC3s_F.p3d",
	"a3\plants_f\Tree\t_PinusP3s_F.p3d",
	"a3\plants_f\Tree\t_PinusS1s_F.p3d",
	"a3\plants_f\Tree\t_PinusS2s_b_F.p3d",
	"a3\plants_f\Tree\t_PinusS2s_F.p3d",
	"a3\plants_f\Tree\t_poplar2f_dead_F.p3d",
	"a3\plants_f\Tree\t_PopulusN3s_F.p3d",
	"a3\plants_f\Tree\t_QuercusIR2s_F.p3d"
];
_zOffset = [
	5, 
	5, 
	6.5, 
	13.5, 
	6.5, 
	7, 
	5.5, 
	11, 
	7, 
	5.5, 
	10, 
	9, 
	10, 
	17, 
	11
];

//Get a random tree and adjust the position.
_index = floor random (count _trees);
_targetTree = _trees select _index;
_adjustedPosition = _d20 vectorAdd [0, 0, (_zOffset select _index) * 1.15];

//Spawn the tree.
[_targetTree, _adjustedPosition] call OPAEX_fnc_D20_SpawnSimpleObject;

//Again, but randomly in a radius.
_radius = 15;
{
	_randomPosition = _adjustedPosition vectorAdd [random _radius, random _radius, 0];
	[_targetTree, _randomPosition] call OPAEX_fnc_D20_SpawnSimpleObject;
} forEach _trees;