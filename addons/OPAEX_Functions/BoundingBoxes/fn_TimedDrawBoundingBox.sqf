//Jack Moss, aka Spartanjackwar.
//Vespade is due all the credit for the origin of the timer script.  I added minutes to it.
/*
	This function temporarily draws the edges of an object's bounding box from BoundingBoxReal.
	Note that this function MUST be called via spawn since we use sleep and waitUntil{} in it.

	Parameter 0: Object: object whose box we draw.
	Parameter 1: Number: Seconds for which we draw the box.
	Parameter 2: bool: If we should display the timer
	
	Return: False if the script aborted due to inability to suspend. True otherwise.
*/

//To catch incorrect environment execution, we will exit if we cannot suspend the script.
if (!canSuspend) exitWith {False};

//Setup parameters
params ["_object", "_inputTime", "_displayTimer"];

//Validate object
if (isNull _object) exitWith {False};

//Init Draw3D handler
_drawHandle = _object call OPAEX_fnc_DrawBoundingBox;

//Timer
[_inputTime, _displayTimer, False] call OPAEX_fnc_Timer;

//Delete Draw3D handler.
removeMissionEventHandler["Draw3D", _drawHandle];

True