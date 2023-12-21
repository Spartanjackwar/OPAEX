//Jack Moss, aka Spartanjackwar.
/*
Function to generate a set of terrain points in a solid half-circle.  Useful for terrain manipulating.

Parameter 0: position: position to center on.  This is our perceived [0, 0] on a coordinate grid.
Parameter 1: float: Height change relative to the existing terrain at each point.
Parameter 2: float: circular diameter.  Negatives are converted to absolute values.
Parameter 3: bool: Should we invert the semicircle?
Parameter 4: float: Length of the loop step.  Leave as 1 unless you have a need for sub-meter diameters.
Return: array of 3D positons.

Example:
	private _pos = creenToWorld [0.5, 0.5];
	private _points = [_pos, -3, 5, false] call OPAEX_fnc_TerrainFilled_HalfCircle;
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
		"_invert",
		false,
		[true]
	],
	[
		"_stepLength",
		1,
		[1.0]
	]
];

private [
	"_newPositions",
	"_rect"
];

//Get the points in the circle
_circle = [_origin, _heightChange, _diameter, _stepLength] call OPAEX_fnc_TerrainFilled_Circle;

//Cut out the half of the rectangle we don't need.
if (!_invert) then {
	_newPositions = _circle select {(_x select 1) >= (_origin select 1)};
} else {
	_newPositions = _circle select {(_x select 1) <= (_origin select 1)};
};
_newPositions //return statement.
