//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns Opposing groups of red and blue spartans

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	None
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
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Party", 0, False];

//Determine side and create the group.
_bluesGroup = createGroup west;
_temptBluesGroup = createGroup west; //used to solve a red-on-red bug in AI behavior.
_redsGroup = createGroup east;

//Generate a group center position within a radius of the D20.
_radius = 30;
_formationRadius = 20; //used for determining distance between group memebers.
_bluesGroupPos = _d20 vectorAdd [random _radius, random _radius, 0];
_redsGroupPos = _d20 vectorAdd [random _radius, random _radius, 0];

//List of units that form the fireteams
_units = [
	"OPTRE_FC_Spartan_Automatic_Rifleman",
	"OPTRE_FC_Spartan_Corpsman",
	"OPTRE_FC_Spartan_Engineer",
	"OPTRE_FC_Spartan_Marksman",
	"OPTRE_FC_Spartan_Rifleman_AT",
	"OPTRE_FC_Spartan_Rifleman_BR",
	"OPTRE_FC_Spartan_Rifleman_AR",
	"OPTRE_FC_Spartan_Scout",
	"OPTRE_FC_Spartan_Scout_Sniper",
	"OPTRE_FC_Spartan_TeamLeader"
	//"OPTRE_FC_Spartan" I didn't feel like having an unarmed spartan was interesting.
];

//Spawn the reds
for "_i" from 0 to 5 do {
	_redsPos = _redsGroupPos vectorAdd [random _formationRadius, random _formationRadius, 0];
	_selection = selectRandom _units;
	_unit = [_temptBluesGroup, _selection, _redsPos] call OPAEX_fnc_D20_SpawnUnit;
	_unit addVest "OPTRE_FC_MJOLNIR_MKV_Armor_Sarge";
	_unit addHeadgear "OPTRE_FC_MJOLNIR_MKV_Helmet_Sarge";
};

//Switch reds to their real side, as just adding them to an East group doesn't work.
(units _temptBluesGroup) joinSilent _redsGroup;

//Spawn the blues
for "_i" from 0 to 5 do {
	_bluesPos = _bluesGroupPos vectorAdd [random _formationRadius, random _formationRadius, 0];
	_selection = selectRandom _units;
	_unit = [_bluesGroup, _selection, _bluesPos] call OPAEX_fnc_D20_SpawnUnit;
	_unit addVest "OPTRE_FC_MJOLNIR_MKV_Armor_Caboose";
	_unit addHeadgear "OPTRE_FC_MJOLNIR_MKV_Helmet_Caboose";
};
