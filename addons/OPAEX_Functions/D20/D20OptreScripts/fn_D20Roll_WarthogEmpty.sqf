//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: spawns a warthog, but its empty.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_D20_SpawnVehicle
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

//Randomly choose the variant.
_variants = [
	"OPTRE_M12_FAV",
	"OPTRE_M12_FAV_black",
	"OPTRE_M12_FAV_tan",
	"OPTRE_M12_FAV_snow",
	"OPTRE_M12_FAV_Marine",
	"OPTRE_M12_FAV_ins",
	"OPTRE_M12_FAV_PD",
	
	"OPTRE_M813_TT",
	"OPTRE_M813_TT_black",
	"OPTRE_M813_TT_tan",
	"OPTRE_M813_TT_snow",
	"OPTRE_M813_TT_Marine",
	
	"OPTRE_M12_LRV",
	"OPTRE_M12_LRV_black",
	"OPTRE_M12_LRV_tan",
	"OPTRE_M12_LRV_snow",
	"OPTRE_M12_LRV_Marine",
	"OPTRE_M12_LRV_ins",
	
	"OPTRE_M12G1_LRV",
	"OPTRE_M12G1_LRV_black",
	"OPTRE_M12G1_LRV_tan",
	"OPTRE_M12G1_LRV_snow",
	"OPTRE_M12G1_LRV_Marine",
	
	"OPTRE_M12A1_LRV",
	"OPTRE_M12A1_LRV_black",
	"OPTRE_M12A1_LRV_tan",
	"OPTRE_M12A1_LRV_snow",
	"OPTRE_M12A1_LRV_Marine",
	"OPTRE_M12A1_LRV_ins",
	
	"OPTRE_M12R_AA",
	"OPTRE_M12R_AA_black",
	"OPTRE_M12R_AA_tan",
	"OPTRE_M12R_AA_snow",
	"OPTRE_M12R_AA_Marine",
	"OPTRE_M12R_AA_ins",
	
	"OPTRE_M12_FAV_APC",
	
	"OPTRE_M914_RV",
	"OPTRE_M914_RV_black",
	"OPTRE_M914_RV_tan",
	"OPTRE_M914_RV_snow",
	"OPTRE_M914_RV_Marine",
	"OPTRE_M914_RV_ins",
	
	"OPTRE_M12_CIV",
	"OPTRE_M12_CIV2",
	
	//Yes, I'm cruel enough to throw in wrecked hogs too.  Have to get that maximum chaos.
	"OPTRE_Objects_Wreck_Warthog",
	"OPTRE_Objects_Wreck_Warthog_MG",
	"OPTRE_Objects_Wreck_Warthog_Armed",
	"OPTRE_Objects_Wreck_Warthog_TT",
	"OPTRE_Objects_Wreck_Warthog_APC"
];
_selection = selectRandom _variants;

//Spawn the thing.
[_selection, _d20] call OPAEX_fnc_D20_SpawnVehicleEmpty;