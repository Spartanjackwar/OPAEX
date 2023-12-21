//Jack Moss, aka Spartanjackwar.
/*
This function intiates the event handlers for the arsenals so that skeleton swapping can occur.

Return: Nothing

Client alone must execute this.  Not intended for user use.
Intented use is call by the OPAEX_fnc_ServerInit_SkeletonSwapHandlers.
Can be executed in nonscheduled environments.
*/
if (!hasInterface) exitWith {["OPAEX: ERROR: required run conditions not met."] call BIS_fnc_error};

missionnamespace setVariable ["OPAEX_SkeletonSwap_Presets", { //This code block is called in the handlers to resolve skeleton options.
	//Check for spartan skeleton requirement
	_result = ["MJOLNIR", "OPTRE_Spartan2_Soldier_Rifleman_AR", False, "_Human"] call OPAEX_fnc_SwapPlayerSkeleton;
	
	if (!_result) then
	{ //Check for elite skeleton requirement since we aren't spartan
		_resultElite = ["FC_Elite_", "OPTRE_FC_Elite_Minor", True, ""] call OPAEX_fnc_SwapPlayerSkeleton;
		//Note that since the elites actually use the same skeleton as spartans, but have a different model, they need special handling, hence the _ignorePreviousSkeleton in OPAEX_fnc_SwapPlayerSkeleton.
		
		if (!_resultElite) then
		{//Since you're not spartan or elite, return to normal, but make sure it's the correct side.
			["", "B_soldier_F", False, ""] call OPAEX_fnc_SwapPlayerSkeleton;
			/*
			if (playerSide isEqualTo west) then {["B_", "B_soldier_F"] call OPAEX_fnc_SwapPlayerSkeleton;} else {
				if (playerSide isEqualTo east) then {["O_", "O_Soldier_F"] call OPAEX_fnc_SwapPlayerSkeleton;} else {
					if (playerSide isEqualTo independent) then {["I_", "I_Soldier_02_F"] call OPAEX_fnc_SwapPlayerSkeleton;} else {
						if (playerSide isEqualTo civilian) then {["", "C_man_1"] call OPAEX_fnc_SwapPlayerSkeleton;};
					};
				};
			};
			*/
		};
	};
}];

missionnamespace setVariable ["OPAEX_SkeletonSwap_Notification", { //Notify users OPAEX skeleton swapping is ready
	systemChat "OPAEX: If you close the arsenal wearing MJOLNIR, you'll be swapped into the correct skeleton.";
}];

//Actual arsenal handlers.
_EHHandle = [missionnamespace,"arsenalClosed", {
	if (OPAEX_SkeletonSwap_Enabled) then {
		_code = missionnamespace getVariable "OPAEX_SkeletonSwap_Presets";
		[] call _code;
	};
}] call BIS_fnc_addScriptedEventhandler;

_EHHandle2 = ["ace_arsenal_displayClosed", {
	if (OPAEX_SkeletonSwap_Enabled) then {
		_code = missionnamespace getVariable "OPAEX_SkeletonSwap_Presets";
		[] call _code;
	};
}] call CBA_fnc_addEventHandler;

//Handlers for notifying users on arsenal opening, since I doubt any of them read changelogs, documentation, or Steam Workshop pages.
_EHHandle = [missionnamespace,"arsenalOpened", {
	if (OPAEX_SkeletonSwap_Enabled) then {
		_notification = missionnamespace getVariable "OPAEX_SkeletonSwap_Notification";
		[] call _notification;
	};
}] call BIS_fnc_addScriptedEventhandler;

_EHHandle2 = ["ace_arsenal_displayOpened", {
	if (OPAEX_SkeletonSwap_Enabled) then {
		_notification = missionnamespace getVariable "OPAEX_SkeletonSwap_Notification";
		[] call _notification;
	};
}] call CBA_fnc_addEventHandler;

//TODO: investigate if display event handlers can call functions on-click.
//onLBSelChanged >> params ["_control", "_selectedIndex"];