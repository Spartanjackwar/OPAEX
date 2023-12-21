//Jack Moss, aka Spartanjackwar.
/*
Function to generate a set of terrain points in a circle.  Useful for terrain manipulating.
A circle is defined as (x - h)^2 + (y - k)^2 = r^2, where r is radius and (h,k) is the origin.
Funny thing is, a circle is also two half-circles.

Parameter 0: position: position to center on.  This is our perceived [0, 0] on a coordinate grid.
Parameter 1: float: Height change relative to the existing terrain at each point.
Parameter 2: float: circular diameter.  Negatives are converted to absolute values.
Parameter 3: float: Length of the loop step.  Leave as 1 unless you have a need for sub-meter diameters.
Return: array of 3D positons.

Example:
		private _pos = screenToWorld [0.5, 0.5];  
	private _points = [_pos, -3, 5] call OPAEX_fnc_Terrain_Circle;
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

private _newPositions = [];

//Generate the points by combining two half-circles.
_newPositions = ([_origin, _heightChange, _diameter, True, _stepLength] call OPAEX_fnc_Terrain_HalfCircle);
_newPositions append ([_origin, _heightChange, _diameter, false, _stepLength] call OPAEX_fnc_Terrain_HalfCircle);

_newPositions //return statement.
