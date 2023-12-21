//Jack Moss, aka Spartanjackwar.
/*
Obtains the highest ranking AI in the mission.

No Parameters.

Return: Object if found, or objnull for failure.

MUST be executed in nonscheduled environment.
Any client may execute this.

Dependencies:
	None
*/

//Get the list of all currently played units.
_allPlayers = call BIS_fnc_listPlayers;

//Get the list of all units.
_allUnits = allUnits;

//Exclude players from the all units list to find all the AI units.
_allAIUnits = _allUnits - _allPlayers;

//Find the highest rank among them.
_highestUnit = [_allAIUnits] call OPAEX_fnc_GetHighestRankingUnit;
_highestUnit //Return.