//Jack Moss, aka Spartanjackwar.
/*
Obtains the highest ranking player in the mission.

No Parameters.

Return: Object if found, or objnull for failure.

MUST be executed in nonscheduled environment.
Any client may execute this.

Dependencies:
	None
*/

//Get the list of all currently played units.
_allPlayers = call BIS_fnc_listPlayers;

//Find the highest rank among them.
_highestUnit = [_allPlayers] call OPAEX_fnc_GetHighestRankingUnit;
_highestUnit //Return.