//Jack Moss, aka Spartanjackwar
/*
	This function determines if one bounding box dimensions can fit inside, or equate to, another box.

	Parameter 0: 3DArray: Smaller bounding box dimensions
	Parameter 1: 3DArray: Larger bounding box dimensions
	
	Return: boolean.  False if any dimensions of param0 > param1.
*/

params [
	[
		"_Box0",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_Box1",
		[0,0,0],
		[[0,0,0]]
	]
];

//Calculate delta of dimensions.
_width = (_Box1 select 0) - (_Box0 select 0);
_length = (_Box1 select 1) - (_Box0 select 1);
_height = (_Box1 select 2) - (_Box0 select 2);

//If any delta are negative, return false.  Otherwise, return true.
if (_width < 0 or _length < 0 or _height < 0) then
{
	False //This is a return satement.
} else {
	True //This is a return satement.
};