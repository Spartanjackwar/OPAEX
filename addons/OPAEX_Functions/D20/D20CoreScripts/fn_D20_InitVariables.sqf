//Jack Moss, aka Spartanjackwar.
/*
Initializer to the D20's settings.
Loads shared variable dependencies.

Return: Nothing

Can be executed in nonscheduled environment.
Requires server execution.

Dependencies:
	OPAEX_fnc_D20_InitD20ScriptList
	OPAEX_fnc_D20_AddClassEventHandler
	
	OPAEX_D20_Enabled, bool, which is a global variable.
	OPAEX_D20_D20List, array of string, which is a global variable.
	OPAEX_D20_ScriptList, array of code, which is a global variable.
	OPAEX_Debug_Mode, bool, which is a global variable.
	OPAEX_D20_Debug_Mode, bool, which is a global variable.
	OPAEX_D20_Debug_ForcedSelection, string, which is a global variable.
		Note the globals here are usually mission namespace.
*/

OPAEX_D20_D20List = [];
OPAEX_D20_ScriptList = [];

//CBA Settings
//======================================================================================
[//Enable/disable D20s.  Default to off.
	"OPAEX_D20_Enabled", //Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
	"CHECKBOX", //setting type
	"Enabled", //Pretty name shown inside the ingame settings menu. Can be stringtable entry.
	["OPAEX Settings", "D20"], //Display name of the category where the setting can be found. Can be stringtable entry.
	false, //Range or default value.
	true, //"_isGlobal" flag. True to always synch between all clients in MP
	{  
		//intentionally empty
	} //function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;

[//Debug mode
	"OPAEX_Debug_Mode",
	"CHECKBOX",
	"Debug mode",
	["OPAEX Settings", ""],
	false,
	false
] call CBA_fnc_addSetting;

[//Debug mode
	"OPAEX_D20_Debug_Mode",
	"CHECKBOX",
	"D20-specific debug mode",
	["OPAEX Settings", "D20"],
	false,
	false
] call CBA_fnc_addSetting;

[//Debug mode selection
	"OPAEX_D20_Debug_ForcedSelection",
	"EDITBOX",
	"Debug mode forced selection",
	["OPAEX Settings", "D20"],
	"",
	false
] call CBA_fnc_addSetting;

["OPAEX_M_D20"] call OPAEX_fnc_D20_InitD20ScriptList;

if (isServer) then {
	publicVariable "OPAEX_D20_ScriptList";
	publicVariable "OPAEX_D20_D20List";
};

//Invoke the event handler setup to run the D20.
call OPAEX_fnc_D20_AddClassEventHandler;

//TODO: trigger event handler for D20List init finish, so others can hook into it.