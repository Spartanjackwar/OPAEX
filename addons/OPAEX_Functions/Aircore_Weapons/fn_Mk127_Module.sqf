//Jack Moss, aka Spartanjackwar.
/*
Parses module input for the illumination bomb's script.
Parameter 0: logic: module entity.

Return: Nothing

Can be executed on any machine.
Can be run in non-scheduled environments.

Dependencies:
	OPAEX_fnc_DisruptorBomb
*/

//First parameter of a module is the logic entity itself.
_logic = param [
	0,
	objNull,
	[objNull]
];
//Validate _logic, as we cannot tolerate not being given an origin point.
if (isNull _logic) exitWith {};

//Attribute values are saved in module's object space under their class names
_origin = getPos _logic;
_BombPoint = _origin vectorAdd [0, 0, 1000];

_bomb = "OPAEX_A_Mk127" createVehicle _BombPoint;
_IlluminationPower = _logic getVariable ["IlluminationPower", 0.10];
_IlluminationRange = _logic getVariable ["IlluminationRange", 2000];

//Color parse
_R = _logic getVariable ["Red", 1.0];
_G = _logic getVariable ["Green", 1.0];
_B = _logic getVariable ["Blue", 1.0];
_RGB = [_R, _G, _B];

[_bomb, _IlluminationPower, _IlluminationRange, _RGB] spawn OPAEX_fnc_Mk127;