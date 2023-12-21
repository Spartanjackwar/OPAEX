//Jack Moss, aka Spartanjackwar.
/*
Parses module input for the GlassingBeam's script.
Parameter 0: logic: module entity.

Return: Nothing

Must execute in a suspendable environment.
Server handles non visual effects.  Headless clients do nothing.
All effects are locally spawned.
*/

//First parameter of a module is the logic entity itself.
_logic = param [
	0,
	objNull,
	[objNull]
];
//Validate _logic, as we cannot tolerate not being given an origin point.
if (isNull _logic) exitWith {};

//Check for trigger sync activation
_activated = param [
	2,
	true,
	[true]
];

if (_activated) then {//Wait for any synced triggers
	//Attribute values are saved in module's object space under their class names
	_origin = getPos _logic;
	_duration = _logic getVariable ["duration", 30];
	_alt = _logic getVariable ["altitude", 1000];
	_destructionRadius = _logic getVariable ["destructionRadius", 333];
	_destructionRate = _logic getVariable ["destructionPercentage", 100];
	_colorPreset = _logic getVariable ["colorPreset", 0];
	
	if (OPAEX_Debug_Mode) then {
		systemChat str [_origin, _duration, _alt, _destructionRadius, _destructionRate, _colorPreset];
	};
	
	[_origin, _duration, _alt, _destructionRadius, _destructionRate, _colorPreset] spawn OPAEX_fnc_GlassingBeam;
};