//Jack Moss, aka Spartanjackwar.
/*
Spray-ranged sponge to erase tags.

No parameters.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.
*/
_unit = player;

//Grab the cast intersections.
private _startPosASL = eyePos _unit;
private _cameraPosASL =  AGLToASL positionCameraToWorld [0, 0, 0];
private _cameraDir = (AGLToASL positionCameraToWorld [0, 0, 1]) vectorDiff _cameraPosASL;
private _endPosASL = _startPosASL vectorAdd (_cameraDir vectorMultiply 2.5);
private _intersections = lineIntersectsSurfaces [
	_startPosASL,
	_endPosASL,
	_unit,
	objNull,
	true,
	1,
	"GEOM",
	"FIRE"
];

//Bail on failure to intercept.
if (_intersections isEqualTo []) exitWith {};

//Find first intercept position and call sponge closest one.
private _cleanPos = (_intersections select 0) select 0;

//Delete the first spray we find.
[_cleanPos, 2.5] call OPAEX_fnc_Sponge;