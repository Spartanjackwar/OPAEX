//Jack Moss, aka Spartanjackwar.
/*
Removes sprays.

Parameter 0: 3d array: position of clean scan origin.
Parameter 1: number: radius of the clean.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.
*/
params [
	[
		"_cleanPos",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_radiusOfClean",
		2.5,
		[0]
	]
];

//Get the sprays
//private _objs = nearestObjects [_cleanPos, ["UserTexture1m_F"], _radiusOfClean];
private _objs = nearestObjects [_cleanPos, [], _radiusOfClean];
_objsCleanedBecauseOfBugWithScanning = [];
{
	if (typeOf _x isKindOf ["UserTexture1m_F", configFile >> "CfgVehicles"]) then {
		_objsCleanedBecauseOfBugWithScanning pushBack _x;
	};
} ForEach _objs;

//Remove each spray we encounter.
{
	//Remove the spray.
	deleteVehicle _x;
} ForEach _objsCleanedBecauseOfBugWithScanning;