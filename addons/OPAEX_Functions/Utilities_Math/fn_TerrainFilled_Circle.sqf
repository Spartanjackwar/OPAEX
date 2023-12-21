//Jack Moss, aka Spartanjackwar.
/*
Function to generate a set of terrain points in a solid circle.  Useful for terrain manipulating.

Parameter 0: position: position to center on.  This is our perceived [0, 0] on a coordinate grid.
Parameter 1: float: Height change relative to the existing terrain at each point.
Parameter 2: float: circular diameter.  Negatives are converted to absolute values.
Parameter 3: float: Length of the loop step.  Leave as 1 unless you have a need for sub-meter diameters.
Return: array of 3D positons.

Example:
	private _pos = creenToWorld [0.5, 0.5]; 
	private _points = [_pos, -3, 5] call OPAEX_fnc_TerrainFilled_Circle;
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
		"_diameter",
		3,
		[1.0]
	],
	[
		"_stepLength",
		1,
		[1.0]
	]
];

private [
	"_newPositions",
	"_rect",
	"_radius",
	"_negRadius"
];

//Split the diameter for the radii.
_radius = _diameter / 2;
_negRadius = -_radius;

//Get the rectangle that encompasses the circle
_rect = [_origin, _heightChange, _diameter, _diameter, _stepLength] call OPAEX_fnc_TerrainFilled_Rectangle;

//Cut out the points in the rectangle that are external to the circle.
_newPositions = _rect select {(_origin distance2D _x) <= _radius};

_newPositions //return statement.
