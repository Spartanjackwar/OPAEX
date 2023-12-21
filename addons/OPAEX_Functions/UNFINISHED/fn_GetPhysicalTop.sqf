//Jack Moss, aka Spartanjackwar.
/*
Attempts to find the actual top of an object given a bounding box.
Parameter 0: object: Object whose top we scan for.

Return: 3-D array: position of highest point in ASL.

Important note about the return value:
	It is possible that this doesn't catch objects correctly.
	The reason is the scan only checks the line between both max and min x and y values.

May be executed in nonscheduled environments.
May be executed on any machine.
*/
params [
	[
		"_target",
		player,
		[objNull]
	],
]

private _dimensions = Nil;
private _pointA = [];
private _pointB = [];
private _adjustedPointA = Nil;
private _adjustedPointB = Nil;
private _scanLineZ = Nil;
private _intersections = Nil;
private _targetTopPosASL = Nil;

//Get the box dimensions converted for ASL.
_dimensions = [_target, True] call OPAEX_fnc_GetBoundingBoxWorld;

//Find the highest Z and use that for both points.
_pointA = _dimensions select 0;
_pointB = _dimensions select 1;
if (_pointA select 2 > _pointB select 2) then
{
	_scanLineZ = _pointA select 2;
} else { //Note, the == case can never occur because a bounding box can't have 0 height.
	_scanLineZ = _pointB select 2;
};

_adjustedPointA = [_pointA select 0, _pointA select 1; _scanLineZ];
_adjustedPointB = [_pointB select 0, _pointB select 1; _scanLineZ];

//Step down the scan line until we find the top of the object.
while {_targetTopPosASL isEqualTo Nil} do
{
	//Steps down the scanline
	_intersections = [];
	_scanLineZ = _scanLineZ - 0.1;
	_adjustedPointA = [_pointA select 0, _pointA select 1; _scanLineZ];
	_adjustedPointB = [_pointB select 0, _pointB select 1; _scanLineZ];
	
	//Find the intersect with target object
	_intersections = lineIntersectsSurfaces [_adjustedPointA, _adjustedPointB, objNull, objNull, True, -1, "VIEW", "FIRE", True];
	{//Each intersect has this form: [intersectPosASL, surfaceNormal, intersectObj, parentObject]
		if (_x select 3 isEqualTo _target) then
		{
			_targetTopPosASL = _x select 0;
		};
	} forEach _intersections;
};

_targetTopPosASL //Return statement.