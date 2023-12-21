//Jack Moss, aka Spartanjackwar.
/*
This function intiates the event handlers for skeleton swapping on server load.

Return: Nothing

Server alone must execute this.  It will send to all clients.
Not intended for enduser use, as this is intended to just initialize on mission start.

Dependencies:
	OPAEX_fnc_SkeletonSwapHandlers
*/
//if (!isServer) exitWith {[] call OPAEX_fnc_Debug_Error_RunCondition;};

[] remoteExec [
	"OPAEX_fnc_SkeletonSwapHandlers",
	0,
	True //Shouldn't override any existing JIP due to autogen unique IDs.
];

//Log the event.
["OPAEX: SkeletonSwapHandlers initialized on all clients"] call BIS_fnc_logFormat;

//CBA Settings
//======================================================================================
[
	"OPAEX_SkeletonSwap_Enabled", //Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
	"CHECKBOX", //setting type
	"Enabled", //Pretty name shown inside the ingame settings menu. Can be stringtable entry.
	["OPAEX Settings", "Skeleton Swapping"], //Display name of the category where the setting can be found. Can be stringtable entry.
	true, //Range or default value.
	true, //"_isGlobal" flag. True to always synch between all clients in MP
	{  
		//intentionally empty
	} //function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;