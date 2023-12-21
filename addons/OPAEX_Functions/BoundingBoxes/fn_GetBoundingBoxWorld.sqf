//Jack Moss, aka Spartanjackwar.
/*
Gets an object's bounding box in world-coordinates.
Parameter 0: object: Object whose top we scan for.
Parameter 1: bool: Whether or not the coordinates returned are in ASL or AGL.  False for AGL.

Return: array of two coordinates, which looks like this form: [[x,y,z],[x,y,z]]

May be executed in nonscheduled environments.
May be executed anywhere.

Dependencies:
	None
*/
params [
	[
		"_target",
		player,
		[objNull]
	],
	[
		"_isASL",
		true,
		[true]
	]
];

_dimensionA = [];
_dimensionB = [];
_bbr = Nil;
_convertedBoundingBoxLine = [];

//boundingBoxReal returns an array in the form [[x,y,z],[x,y,z]]
//This is because the bounding box is recorded as a diagonal line.
_bbr = boundingBoxReal _target;

if (_isASL) then
{//Find the world-coordinate ASL location of the box.
	_dimensionA pushBack _target modelToWorldWorld _bbr select 0;
	_dimensionB pushBack _target modelToWorldWorld _bbr select 1;
} else {//Find the world-coordinate AGL location of the box, accounting for vectorUp.
	_dimensionA pushBack _target modelToWorld _bbr select 0;
	_dimensionB pushBack _target modelToWorld _bbr select 1;
};

//Append the points to an array
_convertedBoundingBoxLine pushBack _dimensionA;
_convertedBoundingBoxLine pushBack _dimensionB;

_convertedBoundingBoxLine //return statement