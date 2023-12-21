//Jack Moss, aka Spartanjackwar.
/*
D20 grenade initializer

Must be executed by the fired event handler.  Select 6 is the projectile, select 7 is the thrower.

Return: Nothing

Must execute in a suspendable environment.
Can be executed anywhere.

Dependencies:
	OPAEX_D20_Debug_Mode, bool, which is a mission namespace variable.
*/

if (missionNamespace getVariable ["OPAEX_D20_Debug_Mode", False]) then
{
	systemChat ("D20_Fired_Particles debug: " + str(_this));
};

_d20 = _this select 6;
_thrower = _this select 0;

_fuseAlt = 1; //Altitude, in meters, AGLS for which the greande logic saves the position.

if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	False //Would return false, but this script needs suspension.
};

//We cannot tolerate not being given a thrower
if (isNull _d20) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	False //Would return false, but this script needs suspension.
};

//Since this script is executed by every throw, we need to check for D20s explicitly.
if (not (_d20 isKindOf "OPAEX_A_D20")) exitWith
{
	//Intentionally empty.
};

//Wait for grenade to explode
_d20Pos = Nil;
//waitUntil {_d20Pos = getPos _d20; not alive _d20};
waitUntil {_d20Pos = getPos _d20; _d20Pos select 2 < _fuseAlt};

//Execute grenade
[
	_d20Pos,
	_thrower
] remoteExec [
	"OPAEX_fnc_D20_RandomSelector",
	2,
	False
];