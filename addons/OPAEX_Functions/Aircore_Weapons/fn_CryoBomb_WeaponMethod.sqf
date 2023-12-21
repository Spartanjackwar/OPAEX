//Jack Moss, aka Spartanjackwar.
/*
Weapon-based cryobomb trigger script.  Waits for the bomb to be destroyed and then fires the cryobomb script.

Parameter 0: object: bomb that acts as the cryobomb
Parameter 1: int: radius of cryobomb
Parameter 2: int: duration of cryobomb

Return: Nothing

Must execute in a suspendable environment.
All effects are locally spawned.

Dependencies:
	OPAEX_fnc_CryoBomb
*/

if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	False //Would return false, but this script needs suspension.
};
params [
	[
		"_Bomb",
		objNull,
		[objNull]
	],
	[
		"_Radius",
		150,
		[1]
	],
	[
		"_Duration",
		30,
		[1]
	]
];

//We cannot tolerate not being given an origin point.
if (isNull _Bomb) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	False //Would return false, but this script needs suspension.
};

//Attribute values are saved in module's object space under their class names
waitUntil {sleep 0.1; (getPos _Bomb) select 2 < 5};
_origin = getPos _Bomb;

//Note, _radius and _duration have reasonable defaults in OPAEX_fnc_CryoBomb, so nils are valid.
[_origin, _radius, _duration] spawn OPAEX_fnc_CryoBomb; //Refer to OPAEX_Functions\Aircore_Weapons\fn_Cryobomb.sqf for more documentation