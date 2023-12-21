//Jack Moss, aka Spartanjackwar.
/*
D20 grenade initializer

Must be executed by the fired event handler.  Select 6 is the projectile, select 7 is the thrower.

Return: Nothing

Must execute in a suspendable environment.
Can be executed anywhere.
*/

//Defaults
private[
	"_d20",
	"_thrower",
	"_mag",
	"_invalidProjectile",
	"_invalidMag",
	"_isD20",
	"_index",
	"_d20Pos"
];
_d20 = objNull;
_thrower = objNull;

//Parameters, given by the fired event handler.
_d20 = _this select 6;
_mag = _this select 5;
_thrower = _this select 7;
_owningUnitOfHandler = _this select 0;
if (_owningUnitOfHandler isNotEqualTo _thrower) exitWith {};

if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	False //Would return false, but this script needs suspension.
};

//We cannot tolerate not being given a projectile or magazine
_invalidProjectile = isNull _d20;
_invalidMag = _mag isEqualTo "";
if (_invalidProjectile or _invalidMag) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	False //Would return false, but this script needs suspension.
};

//Since this script is executed by every throw, we need to check for valid D20s.
_isD20 = [_mag] call OPAEX_fnc_D20_IsMagazineAD20;
if (not _isD20) exitWith {
	nil
};

//Check this D20 exists in the list
_index = OPAEX_D20_D20List find _mag;
if (_index isEqualTO -1) then { //Since it doesn't exist, we must process it to the parallel lists.
	[_mag] call OPAEX_fnc_D20_InitD20ScriptList;
};

//Wait for explosion of grenade.
_d20Pos = Nil;
_d20Pos = getPos _d20;
WaitUntil {
	if (alive _d20) then {_d20Pos = getPos _d20}; //The if check keeps the position valid.
	(!alive _d20)
};

//Execute grenade
[
	_mag,
	_d20Pos,
	_thrower
] remoteExec [
	"OPAEX_fnc_D20_RandomSelector",
	2,
	False
];