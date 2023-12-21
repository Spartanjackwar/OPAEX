//Jack Moss, aka Spartanjackwar.
/*
Function to stop a specific gun from firing.
Note that we store a list of action info in the unit to allow working with multiple stop fire instances.
Each action info is a 2D array containing the actionID and weapon name, in that order.

Parameter 0: object: Unit that is involved.
Parameter 1: string: Weapon classname that we must halt.
Parameter 2: code: code to run when the fired action occurs.
Parameter 3: anything: arguments to pass to parameter 4 in the addAction
Parameter 4: string: Variable name that we use to store the action ID list.  Attaches to the given unit.

Return: int, id for the added action.  Note that this is also stored in the 0th param's namespace too.  -1 is used for errors.

Can be executed in non-scheduled environment.
Can execute on any client.
*/

params [
	[
		"_firingUnit",
		player,
		[objNull]
	],
	[
		"_weaponToStop",
		"",
		[""]
	],
	[
		"_codeToExec",
		{},
		[{}]
	],
	
	"_codeToExecArgs",
	
	[
		"_actionIDStoreName",
		"OPAEX_StopFireActionIDs",
		[""]
	]
];

private[
	"_actionID",
	"_actionInfo",
	"_actionIDList",
	"_condition",
	"_actionArgs"
];

//Setup the condition and get the action list.
_actionIDList = _firingUnit getVariable [_actionIDStoreName, []];
_condition = format[ //Note that _target is a special variable given to addAction conditions.  So is _caller.
	//"((currentWeapon _target) isEqualTo '%1') and (_target == _caller)",
	"(_this isEqualTo _originalTarget) and ((currentMuzzle _target) isEqualTo '%1')",
	_weaponToStop
];

//Validate that we don't already monitor this weapon on this unit.
if ([_firingUnit, _weaponToStop, _actionIDStoreName] call OPAEX_fnc_hasStopAction) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	-1;
};

//Append the code to the arguments so that the addaction will correctly pass it into the future script scope.
_actionArgs = [_codeToExecArgs, _codeToExec];

//Create the override action
_actionID = _firingUnit addAction [
	"", //Title
	{
		_codeToExec = (_this select 3) select 1;
		_codeToExecArgs = (_this select 3) select 0;
		_codeToExecArgs spawn _codeToExec;
	},
	_actionArgs,
	0, //Priority of action.
	false, //Should we show a text indication?
	false, //Should we hide when used?
	"DefaultAction", //Action to override/bind to.
	_condition,
	-1
];

//Store the action ID and muzzle name to ensure we can check for double-adds.
_actionInfo = [_actionID, _weaponToStop];
_actionIDList pushBack _actionInfo;
_firingUnit setVariable [_actionIDStoreName, _actionIDList, false];

//Return the action ID for convenience.
_actionID 