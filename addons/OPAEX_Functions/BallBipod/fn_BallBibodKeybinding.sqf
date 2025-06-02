//Jack Moss, aka Spartanjackwar.
/*
Initializer to the Ballbipod system's settings.

Parameter 0: string: Name of the top-level category.

Return: Nothing

Can be executed in nonscheduled environment.
Requires global execution.
*/
params [
	[
		"_topSettingGroupName",
		"OPAEX Settings",
		[""]
	]
];

private _settingsCategoryNames = [_topSettingGroupName, "Ball Bipod"];
private _keybindNameAndTooltip = ["Activate bipod", "Hold this key to give your teammates a bipod with your cake."];
private _keybindNameAndTooltipToggle = ["Toggle bipod", "Hit this key to give your teammates a bipod with your cake."];

//Custom keybind for hijacking.
[
	"OPAEX",
	"OPAEX_BallBipod",
	_keybindNameAndTooltip,
	{
		_unit = player;
		[_unit] call OPAEX_fnc_BallBipodOn;
	}, //keydown script.
	{
		_unit = player;
		_index = _unit getVariable ["OPAEX_BallBipodHandler", -1];
		_brick = _unit getVariable ["OPAEX_BallBipodBrick", objNull];
		[_unit, _index, _brick] call OPAEX_fnc_BallBipodOff;
	}, //keyup script.
	[0x10D, [false, false, false]] //[Key, [shift, ctrl, alt]].  Note that 10D is custom user action 20.
] call CBA_fnc_addKeybind; //Refer to https://github.com/CBATeam/CBA_A3/blob/master/addons/keybinding/fnc_addKeybind.sqf

[
	"OPAEX",
	"OPAEX_BallBipod_Toggle",
	_keybindNameAndTooltip,
	{
		_unit = player;
		_index = _unit getVariable ["OPAEX_BallBipodHandler", -1];
		_brick = _unit getVariable ["OPAEX_BallBipodBrick", objNull];
		if (_index > -1) then {
			[_unit, _index, _brick] call OPAEX_fnc_BallBipodOff;
		} else {
			[_unit] call OPAEX_fnc_BallBipodOn;
		}
	}, //keydown script.
	{}, //keyup script.
	[0x10D, [true, false, false]] //[Key, [shift, ctrl, alt]].  Note that 10D is custom user action 20.
] call CBA_fnc_addKeybind; //Refer to https://github.com/CBATeam/CBA_A3/blob/master/addons/keybinding/fnc_addKeybind.sqf
