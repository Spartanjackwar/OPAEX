//Jack Moss, aka Spartanjackwar.  Credit for the matrix math goes to Leopard20#5297 in the Arma discord.
/*
Retrieves the position of some given proxy or selection from an object.
This works even under rotation.

Parameter 0: object: object to detect weapon position for.
Parameter 1: string: name of selection/proxy to find position of.
Parameter 2: 3D array of floats: offset from gun center to use.

Return: model-relative position of the offset from unit's selection/proxy.

Example:
	//To get the gun's muzzle.
	private _unit = player;
	_offset = [currentWeapon _unit] call OPAEX_fnc_getMuzzleOffestFromWeaponProxy;
	_pos = [_unit, _offset] call OPAEX_fnc_getSelectionPosition;

Can be executed in nonscheduled environments.
Can execute anywhere.
*/

params [
	[
		"_unit",
		objNull,
		[objNull]
	],
	[
		"_selection",
		"head",
		[""]
	],
	[
		"_offset",
		[0,0,0],
		[[0,0,0]]
	]
];

private [
	"_vx",
	"_selectionPos",
	"_matrix"
];

//Map the offset to a 3d array of 1d arrays of floats.  Useful for matrix math.
_offset = _offset apply {[_x]};

//Grab the vectors needed for the transpose matrix
_unit selectionVectorDirAndUp [_selection, "Memory"] params ["_vy", "_vz"];
_vx = _vy vectorCrossProduct _vz;

//Grab the selection position and do some matrix math with it.
_selectionPos = _unit selectionPosition _selection;
_matrix = matrixTranspose [_vx, _vy, _vz];
_selectionPos = _selectionPos vectorAdd flatten(_matrix matrixMultiply _offset);

_selectionPos //return statement.