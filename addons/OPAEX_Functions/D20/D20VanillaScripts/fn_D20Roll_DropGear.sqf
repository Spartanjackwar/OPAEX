//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Drops gear of thrower onto the floor.

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
	//Get thrower stuff.
	_vest = (vest _thrower);
	_unif = (uniform _thrower);
	_helm = (headgear _thrower);
	_pack = (backpack _thrower);
	_goggles = (goggles _thrower);
	/*
	_vestItems = vestItems _thrower;
	_unifItems = uniformItems _thrower;
	_packItems = backpackItems _thrower;
	_items = _vestItems + _unifItems + _packItems + (magazines _thrower);
	*/
	_items = itemsWithMagazines _thrower;
	
	//Drop thrower items onto D20 position and remove them from thrower.
	_groundHolder = "GroundWeaponHolder" createVehicle _d20;
	_groundHolder addBackpackCargoGlobal  [_pack, 1];
	_groundHolder addItemCargoGlobal  [_vest, 1];
	_groundHolder addItemCargoGlobal  [_helm, 1];
	_groundHolder addItemCargoGlobal  [_unif, 1];
	_groundHolder addItemCargoGlobal  [_goggles, 1];
	
	//Fill the ground gear with the original items.
	{
		_groundHolder addItemCargoGlobal [_x, 1];
	} forEach _items;
	
	//Remove the original gear from the thrower
	removeBackpackGlobal _thrower;
	removeVest _thrower;
	removeHeadgear _thrower;
	removeUniform _thrower;
	removeGoggles _thrower;
};