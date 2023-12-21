//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns a UNSC fireteam hostile to the thrower.

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

//Figure out the side to use and options
_throwerSide = side _thrower;
_fireteamSide = sideEmpty;
switch (_throwerSide) do {
    case west: {_fireteamSide = east};
    case east: {_fireteamSide = west};
    default {_fireteamSide = sideEnemy}; //Default to renegade.
};
_count = random [1, 15, 30];
_camo = selectRandom [
	"OLI",
	"SNO",
	"DES",
	"WDL",
	"TRO",
	"URB"
];

//Create group
_fireteamGroup = createGroup _fireteamSide;
_tempfireteamGroup = createGroup west;

//List of units that could form the fireteam
_fireteam = [
	"OPTRE_UNSC_Army_Soldier_AA_Specialist_WDL",
	"OPTRE_UNSC_Army_Soldier_Assist_Autorifleman_",
	"OPTRE_UNSC_Army_Soldier_AT_Specialist_",
	"OPTRE_UNSC_Army_Soldier_Autorifleman_",
	"OPTRE_UNSC_Army_Soldier_Breacher_",
	"OPTRE_UNSC_Army_Soldier_Crewman_",
	"OPTRE_UNSC_Army_Soldier_Demolitions_",
	"OPTRE_UNSC_Army_Soldier_Marksman_",
	"OPTRE_UNSC_Army_Soldier_Engineer_",
	"OPTRE_UNSC_Army_Soldier_ForwardObserver_",
	"OPTRE_UNSC_Army_Soldier_Grenadier_",
	"OPTRE_UNSC_Army_Soldier_Officer_",
	"OPTRE_UNSC_Army_Soldier_Medic_",
	"OPTRE_UNSC_Army_Soldier_Radioman_",
	"OPTRE_UNSC_Army_Soldier_Rifleman_AT_",
	"OPTRE_UNSC_Army_Soldier_Rifleman_BR_",
	"OPTRE_UNSC_Army_Soldier_Rifleman_Light_",
	"OPTRE_UNSC_Army_Soldier_Rifleman_AR_",
	"OPTRE_UNSC_Army_Soldier_Sniper_",
	"OPTRE_UNSC_Army_Soldier_SquadLead_",
	"OPTRE_UNSC_Army_Soldier_TeamLead_",
	"OPTRE_UNSC_Army_Soldier_UAV_Op_",
	"OPTRE_UNSC_Army_Soldier_Unarmed_"
];

for "_i" from 1 to _count do {//Spawn all of the units, appending the prefix to the name
	_unitType = (_fireteam select _i) + _camo;
	[_tempfireteamGroup, _unitType, _d20] call OPAEX_fnc_D20_SpawnUnit;
};

//Fix the normally-blue-units-shooting-each-other-when-spawned-on-redfor bug that Arma 3 has had for absolute years.
(units _tempfireteamGroup) joinSilent _fireteamGroup;
