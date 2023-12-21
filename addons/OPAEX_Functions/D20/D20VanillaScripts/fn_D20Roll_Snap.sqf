//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Thanos snaps the players of a server.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.
*/

params [
	[
		"_d20",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_thrower",
		objNull,
		[objNull]
	]
];

//We cannot tolerate not being given a thrower
if (isNull _thrower) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

//Do the visuals
//[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//Grab all players.
_allPlayers = call BIS_fnc_listPlayers;

//Coin toss which half to eliminate.
//Note, I have no idea if there is an order to the player list.
//I'm going to be lazy here and ignore that concern.
_toss = floor(random 1);
_startIndex = 0;
_endIndex = floor((count _allPlayers) / 2);
if (_toss == 1) then {
	_startIndex = (count _allPlayers) / 2;
	_endIndex = (count _allPlayers) - 1;
};


//Fade into white
[
	["", "WHITE OUT", 1]
] remoteExec [
	"titleText",
	0,
	False
];


//Play the snap sound.
[0, false, _d20, "OPAEX_Sound_D20_Snap", 300, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//Whiteout the screen
[
	[
		"<t color='#799627' size='1'>The inevitable Banana God snapped his fingers...</t><br/>(Half the players are dead!)",
		"WHITE IN",
		7,
		true,
		true
	]
] remoteExec [
	"titleText",
	0,
	False
];

//Yeet the array's inhabitants from existence, but only if they are allowed to die.
for "_i" from _startIndex to _endIndex do {
	_target = _allplayers select _i;
	if (isDamageAllowed _target) then {
		_target setDamage 1;
	};
};