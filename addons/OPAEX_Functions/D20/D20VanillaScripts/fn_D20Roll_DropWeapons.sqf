//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Drops weapons of thrower onto the floor.

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
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_Yeet", 0, False];

if (_thrower isKindOf "CAManBase") then {
	//Get thrower weapons.
	_weapons = weapons _thrower;
	
	//Drop thrower weapons onto D20 position and remove thrower weapons.
	{
		_groundHolder = "GroundWeaponHolder" createVehicle _d20;
		_groundHolder addWeaponCargoGlobal [_x, 1];
		_thrower removeWeaponGlobal  _x;
	} forEach _weapons; //TODO: inject remote exec for non local units if the global versions are still buggered.
};