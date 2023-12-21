//Jack Moss, aka Spartanjackwar.
/*
Function to generate a set of terrain points in a solid rectangle.  Useful for terrain manipulating.

Parameter 0: position: position to center on.  This is our perceived [0, 0] on a coordinate grid.
Parameter 1: float: Height change relative to the existing terrain at each point.
Parameter 2: float: X side length.
Parameter 3: float: Y side length.
Parameter 4: float: Length of the loop step.  Leave as 1 unless you have a need for sub-meter diameters.
Return: array of 3D positons.

Example:
	private _pos = screenToWorld [0.5, 0.5]; 
	private _points = [_pos, -3, 3, 3] call OPAEX_fnc_TerrainFilled_Rectangle; 
	setTerrainHeight [_points];

Can be executed in a non-scheduled environment.
Can be executed on any machine.
*/
params [
	[
		"_origin",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_heightChange",
		-3,
		[1.0]
	],
	[
		"_width",
		3,
		[1.0]
	],
	[
		"_length",
		3,
		[1.0]
	],
	[
		"_stepLength",
		1,
		[1.0]
	]
];

private _newPositions = [];

//Split the sides.
private _halfWidth = _width / 2;
private _negHalfWidth = -_width;
private _halfLength = _length / 2;
private _negHalfLength = -_length;

//Generate the points.
for "_xStep" from _negHalfWidth to _halfWidth step _stepLength do {
	for "_yStep" from _negHalfLength to _halfLength step _stepLength do {
		private ["_newHeight", "_nextPoint"];
		
		//Offset from the origin the X and Y steps.
		_nextPoint = _origin vectorAdd [_xStep, _yStep, 0];
		
		//Determine Z, which is the terrain height.
		_newHeight = (getTerrainHeight _nextPoint) + _heightChange;
		_nextPoint set [2, _newHeight];
		
		//Append the positions array with the [x, y, z] info.
		_newPositions pushBack _nextPoint;
	};
};

_newPositions //return statement.
