//Jack Moss, aka Spartanjackwar
/*
	This function calculates the center of the top face of a bounding box.

	Parameter 0: 3D Array: Box point 0 to get the center for.
	Parameter 1: 3D Array: Box point 1 to get the center for.
	Return: array of three numbers: x, y, and z, in that order.
	
	May run in unscheduled environments.
	May be run on any client.
*/

params [
	[
		"_box1",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_box2",
		[0,0,0],
		[[0,0,0]]
	]
];
//Find the midpoint between box1 and box2.
private _box = [
	((_box2 select 0) + (_box1 select 0))/2,
	((_box2 select 1) + (_box1 select 1))/2,
	(_box2 select 2) + (_box1 select 2)
];


//Calculate the center.  Offsets are assumed handled in the parmeters.
private _width  = (_box select 0) / 2;
private _length = (_box select 1) / 2;
private _height = (_box select 2); //Note, that we don't need to half since we just want the top face.
private _center = [_width, _length, _height];

_center  //This is the return statement.