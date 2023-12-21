//Jack Moss, aka Spartanjackwar.
/*
This function represents a temporary cryobomb via removing a vehicle's ammo and fuel and attaching.
Parameter 0: position: origin of bomb explosion
Parameter 1: int: radius
Parameter 2: int: number of seconds for 'EMP' to last.

Return: Nothing

Must execute in a suspendable environment.
Server is passed the actual physical response to freezing.  Headless clients do nothing.
All effects are locally spawned.

Dependencies:
	OPAEX_fnc_Effect_setParticleArray, Not as of current.
	BIS_fnc_attachToRelative
	OPAEX_fnc_EMP
*/
if (!isServer or !canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

//Get parameters
_OPAEX_CryoBomb_origin = _this select 0;
_OPAEX_CryoBomb_radius = _this select 1;
_OPAEX_CryoBomb_duration = _this select 2;

//Init local values
_fakeCenter = Nil;
_FreezeList = [];
_EMPallowed = [];

//Get objects to freeze
_FreezeList = _OPAEX_CryoBomb_origin nearEntities _OPAEX_CryoBomb_radius;

//Create invisible helipad to act as object for attachement to.
_fakeCenter = "Land_HelipadEmpty_F" createVehicle _OPAEX_CryoBomb_origin;

{//Freeze objects in list.
	if !(_x isKindOf "Air") then 
	{//If not air vehicle, attach to the origin object
		//Execute where it's local
		[[_x, _fakeCenter, True], BIS_fnc_attachToRelative] remoteExec ["call", owner _x, False];
	};
} ForEach _FreezeList;

{ //Filter out objects that are game logic or infantry from EMP due to magazine retention issues.
	if (!(_x isKindOf "Logic") && !(_x isKindOf "Man")) then
	{
		_EMPallowed pushback _x;
	};
} ForEach _FreezeList;

//EMP the objects in list and wait for completion.
_EMPScriptHandle = [_EMPallowed, _OPAEX_CryoBomb_duration, False] spawn OPAEX_fnc_EMP;
sleep _OPAEX_CryoBomb_duration - 1; //This sleep prevents early checking since spawn is psuedo-parallelized.
waitUntil {sleep 1; scriptDone _EMPScriptHandle}; //Sleep prevents per-frame checks, saving performance

//Cleanup everything.
{//Unfreeze objects in list.
	detach _x;
} ForEach _FreezeList;
deleteVehicle _fakeCenter;