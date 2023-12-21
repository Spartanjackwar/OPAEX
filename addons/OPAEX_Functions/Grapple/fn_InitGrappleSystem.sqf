//Jack Moss, aka Spartanjackwar.
/*
Initializer to the grapple system's settings.

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

_settingsCategoryNames = [_topSettingGroupName, "Grapple"];
_keybindNameAndTooltip = ["Grapple pull", "Hit this key to pull what you're looking at."];

//Custom keybind for hijacking.
[
	"OPAEX",
	"OPAEX_GrapplePull",
	_keybindNameAndTooltip,
	{
		[] spawn {
			_target = cursorTarget;
			_duration = 1;
			_hook = createVehicle ["Land_Can_V3_F", getPos _target, [], 0, "CAN_COLLIDE"];
			[player, _target, _hook, _duration, 1] spawn OPAEX_fnc_Grapple_PullTarget;
			sleep _duration;
			deleteVehicle _hook;
		};
	}, //keydown script
	{}, //keyup script.  Intentionally empty.
	[0x30, [true, false, false]] //[Key, [shift, ctrl, alt]].  Note that 30 is B.
] call CBA_fnc_addKeybind; //Refer to https://github.com/CBATeam/CBA_A3/blob/master/addons/keybinding/fnc_addKeybind.sqf