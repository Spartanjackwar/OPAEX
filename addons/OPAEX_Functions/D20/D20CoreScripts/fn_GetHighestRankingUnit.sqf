//Jack Moss, aka Spartanjackwar.
/*
Obtains the highest ranking unit in the mission.

Parameter 0: array of objects: array to search within.

Return: Object if found, or objnull for failure.

MUST be executed in nonscheduled environment.
Any client may execute this.

Dependencies:
	None
*/

params [
	[
		"_setOfUnits",
		allUnits,
		[[objNull]]
	]
];

_highestRankSoFar = 0;
_highestRankingUnit = objNull;
{
	_rankID = rankId _x;
	if (_rankID >= _highestRankSoFar) then {
		_highestRankSoFar = _rankID;
		_highestRankingUnit = _x;
	};
} forEach _setOfUnits;

_highestRankingUnit //return