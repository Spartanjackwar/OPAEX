//Jack Moss, aka Spartanjackwar.
/*
Function to generate a set of terrain points along a line.  Useful for terrain manipulating.
If you remember geometry, a line is defined as y = mx + b, where b is y-axis intercept and m is slope.

Parameter 0: position: position to center on.  This is our perceived [0, 0] on a coordinate grid.
Parameter 1: float: Height change relative to the existing terrain at each point.
Parameter 2: float: slope.
Parameter 3: float: "B", or intercept along the Y-axis.
Parameter 4: float: circular bounds diameter.  Use as the length of the line.
	Note that 0 indicate "infinite" line going to world boundary.
Parameter 5: float: Length of the loop step.  Leave as 1 unless you have a need for sub-meter diameters.
Return: array of 3D positons.

Example:
	private _pos = creenToWorld [0.5, 0.5];
	_bar = [_pos, -3, 0, 0, 5] call OPAEX_fnc_Terrain_Line;
	setTerrainHeight [_bar];

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
		"_slope",
		1.0,
		[1.0]
	],
	[
		"_yAxisIntercept",
		0,
		[1.0]
	],
	[
		"_boundsDiameter",
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

//Check the bounds diameter for negatives and the 0 case.
if (_boundsDiameter < 0) then {
	_boundsDiameter = abs(_boundsDiameter);
} else {
	if (_boundsDiameter isEqualTo 0) then {
		private _worldSideLength = worldSize;
		_boundsDiameter = sqrt(_worldSideLength^2 + _worldSideLength^2); //Remember the pythagorean theorem?
	};
};

//Split the bounds diameter for the radii.
private _radius = _boundsDiameter / 2;
private _negRadius = -_radius;

//Generate the points.
for "_xStep" from _negRadius to _radius step _stepLength do {
	private ["_newHeight", "_nextPoint", "_yStep"];
	
	//Find Y.  We're using y = mx + b for this function.
	_yStep = _slope * _xStep + _yAxisIntercept;
	
	//Offset from the origin the X and Y steps.
	_nextPoint = _origin vectorAdd [_xStep, _yStep, 0];
	
	//Determine Z, which is the terrain height.
	_newHeight = (getTerrainHeight _nextPoint) + _heightChange;
	_nextPoint set [2, _newHeight];
	
	//Append the positions array with the [x, y, z] info.
	_newPositions pushBack _nextPoint;
};

_newPositions //return statement.
