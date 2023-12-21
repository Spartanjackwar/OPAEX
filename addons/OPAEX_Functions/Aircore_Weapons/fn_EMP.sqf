//Jack Moss, aka Spartanjackwar.
/*
This function represents an EMP via removing a vehicle's ammo and fuel.
It is worth noting that this function uses parallel arrays.

Parameter 0: UnitList: array of entities.
Parameter 1: Duration: number of seconds for 'EMP' to last.  There is no infinity supported.
Parameter 2: TimerVisible: Bool, timer of if timer should be seen.

Note that this runs only on the server and also requires a scheduled environment.

Return: Nothing

Known Issues:
	Infantry lose all mags permanently. Don't call this on them. We will not check for infantry classes.
	Vehicles must reload after EMP ends since script doesn't reload the weapons.
*/
if (!isServer or !canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

//Parameters
params [
	[
		"_UnitList",
		[],
		[[objNull]]
	],
	[
		"_duration",
		30,
		[1]
	],
	[
		"_TimerVisible",
		False,
		[True]
	]
];
_FuelList = [];
_AmmoList = [];

{
	//Save fuel and ammo
	_FuelList pushBack fuel _x;
	_AmmoList pushBack magazinesAllTurrets _x;
	
	//Remove fuel and ammo
	[_x, 0] remoteExec ["setFuel", owner _x, False]; //_x setFuel 0;
	[_x, 0] remoteExec ["setVehicleAmmo", owner _x, False]; //_x setVehicleAmmo 0;
	
} ForEach _UnitList;

	
//Wait for timer
_EMPScriptHandle = [_duration, _TimerVisible, False] spawn OPAEX_fnc_Timer;
sleep _duration - 1; //Prevent early checks
waitUntil {sleep 1; scriptDone _EMPScriptHandle};

_index = 0;
{//Add fuel and ammo back to the units we removed from.
	_vehicle = _x;
	[_vehicle, _FuelList select _index] remoteExec ["setFuel", owner _vehicle, False]; //_vehicle setFuel (_FuelList select _index);
	
	//Add magazine where it's local
	{//_x becomes a magazine entry of this array form: [className, turretPath, ammoCount, id, creator]
		[_vehicle, [_x select 0, _x select 1, _x select 2]] remoteExec ["addMagazineTurret", owner _vehicle, False]; //_vehicle addMagazineTurret [_x select 0, _x select 1, _x select 2];
	} ForEach (_AmmoList select _index);
	
	_index = _index + 1; //i++, as we're doing this for each vehicle.
} ForEach _UnitList;