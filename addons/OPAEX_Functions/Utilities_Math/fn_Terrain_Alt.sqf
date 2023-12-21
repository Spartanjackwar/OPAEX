//Jack Moss, aka Spartanjackwar.
/*
Function to manipulate terrain into the word ALT.  Hi Alt, I'm ALT!  (This is a 19th joke).

Parameter 0: position: position to center on.  This is our perceived [0, 0] on a coordinate grid.
Parameter 1: float: Height change relative to the existing terrain at each point.
Parameter 2: float: rough size of letters.  2*this is the spacing between letters.
Return: Nothing.

Example:
	TODO

Can be executed in a non-scheduled environment.
Must be executed on server.
*/
params [
	[
		"_origin",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_heightChange",
		-100,
		[1.0]
	],
	[
		"_bounds",
		100,
		[1.0]
	]
];

_pointsInA = [];
_pointsInL = [];
_pointsInT = [];

//Make the A
_leftLeg = [_origin, _heightChange, 3, _bounds, _bounds*1.34] call OPAEX_fnc_Terrain_Line;
_rightLeg = [_origin, _heightChange, -3, _bounds, _bounds*1.34] call OPAEX_fnc_Terrain_Line;
_leftLeg = _leftLeg select {(_x select 0) <= (_origin select 0)};
_rightLeg = _rightLeg select {(_x select 0) >= (_origin select 0)};
_bar = [_origin, _heightChange, 0, 0, _bounds/1.34] call OPAEX_fnc_Terrain_Line;
_pointsInA append _leftLeg;
_pointsInA append _rightLeg;
_pointsInA append _bar;

//Move the origin.
_origin = _origin vectorAdd [_bounds * 2, 0, 0];

//Make the L
//We need to generate a vertical line because the y = mx + b equation produces undefined verticals.
_vertical = [_origin, _heightChange, _bounds*2] call OPAEX_fnc_Terrain_LineVertical;
_LBar = [_origin, _heightChange, 0, -_bounds, _bounds*2] call OPAEX_fnc_Terrain_Line;
_LBar = _LBar select {(_x select 0) >= (_origin select 0)}; //Prune the left end of the L's bar.
_pointsInL append _vertical;
_pointsInL append _LBar;

//Move the origin again.
_origin = _origin vectorAdd [_bounds * 2, 0, 0];

//Make the T
_Tvertical = [_origin, _heightChange, _bounds*2] call OPAEX_fnc_Terrain_LineVertical;
_TBar = [_origin, _heightChange, 0, _bounds, _bounds*2] call OPAEX_fnc_Terrain_Line;
_pointsInL append _Tvertical;
_pointsInL append _TBar;

//Do the height setting! Welcome to the C-Alt!
setTerrainHeight [_pointsInA];
setTerrainHeight [_pointsInL];
setTerrainHeight [_pointsInT];