//Jack Moss, aka Spartanjackwar.
/*
Obtains the highest scoring player in the mission.

Parameter 0: object, the unit to use as current score.

Return: Object if found, or objnull for failure.

MUST be executed in nonscheduled environment.
Any client may execute this.

Dependencies:
	None
*/

params [
	[
		"_comparisonUnit",
		player,
		[objNull]
	]
];


//Check single-player, and return with player.
if (not isMultiplayer) exitWith {
	player
};

//Get the list of all currently played units.
//_allPlayers = call BIS_fnc_listPlayers;
_headlessClients = entities "HeadlessClient_F";
_allPlayers = allPlayers - _headlessClients;

//Find our comparison score
_comparisonScore = nil;
if (isNull _comparisonUnit) then {
	_comparisonScore = 0;
} else {
	_comparisonScore = score _comparisonUnit;
};

//Find the next score in the set.
_highestUnit = objNull;
_index = _allPlayers findIf {(score _x) >= _comparisonScore};
if (_index isNotEqualTo -1) then {
	_highestUnit = _allPlayers select _index;
};

/*Fails to work in multiplayer environments
_highestUnit = objNull;
{
	_currentUnitScore = score _x;
	if (_currentUnitScore > _comparisonScore) then {
		_highestUnit = _x;
		breakWith _x; //Breaking return.
	};
} forEach _allPlayers;
*/

_highestUnit //Return.