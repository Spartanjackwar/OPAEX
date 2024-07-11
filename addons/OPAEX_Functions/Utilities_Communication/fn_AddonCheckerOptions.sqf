//Jack Moss, aka Spartanjackwar.
/*
Initializer to the addon checker's settings.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client. Special handler for server is present.
*/

//CBA Settings
//======================================================================================
[//Enable/disable D20s.  Default to off.
	"OPAEX_ExpectedAddonsCheckerEnabled", //Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
	"CHECKBOX", //setting type
	"System enabled", //Pretty name shown inside the ingame settings menu. Can be stringtable entry.
	["OPAEX Settings", "AddonChecker"], //Display name of the category where the setting can be found. Can be stringtable entry.
	false, //Range or default value.
	true, //"_isGlobal" flag. True to always synch between all clients in MP
	{  
		//intentionally empty
	} //function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;

[
	"OPAEX_ExpectedAddonsList",
	"EDITBOX",
	"List of addons to ignore",
	["OPAEX Settings", "AddonChecker"],
	"",
	true
] call CBA_fnc_addSetting;

if (isServer) then {
	//Mission handler
	addMissionEventHandler ["OnUserConnected", {
		params ["_networkId", "_clientStateNumber", "_clientState"];
		private _owner = (getUserInfo _networkId) select 1;
		[
			nil
		] remoteExec [
			"OPAEX_fnc_AddonChecker",
			_owner,
			false
		];
	}];
}