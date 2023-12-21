//Jack Moss, aka Spartanjackwar
/*
	This function calculates the max width, max length, and max height of a bounding box.
	Unlike the non-offset version, this function can take an override on the bounding box.

	Parameter 0: Object to get boundingbox for.
	Parameter 1: 3DArray: The override for the bounding box dimensions.
	Parameter 2: Bool: check for if we must adjust for model centers.
	
	Return: array of three numbers: max width, max length, and max height, in that order.

	May be run on any client.  May run in unscheduled environments
*/
params [
	[
		"_target",
		player,
		[objNull]
	],
	[
		"_bbr",
		[[0, 0, 0], [0, 0, 0], 0],
		[[[0, 0, 0], [0, 0, 0], 0]]
	],
	[
		"_adjustForBoundingCenter",
		false,
		[false]
	]
];

//Nifty little command eh?  This gets the offset between model origin and bounding box center.
private _offset = [0, 0, 0];
if (_adjustForBoundingCenter) then {
	_offset = boundingCenter _target;
};

//Calculate dimensions
private _p1 = _bbr select 0;
private _p2 = _bbr select 1;
private _maxWidth = abs(_p2 select 0) + abs(_p1 select 0);
private _maxLength = abs(_p2 select 1) + abs(_p1 select 1);
private _maxHeight = abs(_p2 select 2) + abs(_p1 select 2);

//Account for offsets
private _width = _maxWidth - (_offset select 0);
private _length = _maxLength - (_offset select 1);
private _height = _maxHeight - (_offset select 2);
private _dimensions = [_width, _length, _height];

_dimensions //This is the return statement.