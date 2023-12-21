//Jack Moss, aka Spartanjackwar.
//Credits for most of this function actually belongs to whomever wrote example 1 on the Biki.
/*
Function to flatten terrain to a set height in a rectangular pattern.

Parameter 0: position: position to start from.
Parameter 1: int: X side length.
Parameter 2: int: Y side length.
Parameter 3: float: New terrain height.
Parameter 4: bool: Should we adjust objects to the new height?

Return: Nothing

Example:
	private["_desiredTerrainHeight", "_positionsAndHeights"];
	_desiredTerrainHeight = 150;
	_positionsAndHeights = [getPosWorld player, 50, 50, _desiredTerrainHeight] call OPAEX_fnc_flattenTerrain;

Can be executed in a non-scheduled environment.
Must be executed on the server.
*/
params [
	[
		"_origin",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_xSideLength",
		50,
		[1]
	],
	[
		"_ySideLength",
		50,
		[1]
	],
	[
		"_height",
		10,
		[1.0]
	],
	[
		"_adjustObjects",
		true,
		[true]
	]
];

//Catch nonserver execution and present it to the server.
if (!isServer) exitWith {
	[
		_this
	] remoteExec [
		"OPAEX_fnc_flattenTerrain",
		2,
		False
	];
	//This server execution guard is not normally my typical guard code, but I figured it'd be worth experimenting with.
};

private _newPositions = [];

for "_xStep" from 0 to _xSideLength do
{
	for "_yStep" from 0 to _ySideLength do
	{
		private _newHeight = _origin vectorAdd [_xStep, _yStep, 0];
		_newHeight set [2, _height];
		_newPositions pushBack _newHeight;
	};
};

setTerrainHeight [_newPositions, _adjustObjects];
