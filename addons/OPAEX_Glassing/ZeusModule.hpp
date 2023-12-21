/*
class ace_zeus_moduleBase: Module_F
{
	author = "ACE-Team";
	category = "ACE";
	function = "ace_common_fnc_dummy";
	functionPriority = 1;
	isGlobal = 1;
	isTriggerActivated = 0;
	scope = 1;
	scopeCurator = 2;
};

class ace_zeus_RscGroupSide: RscDisplayAttributes
{
	onLoad = "['onLoad',_this,""""ace_zeus_RscGroupSide""""] call ace_zeus_fnc_zeusAttributes";
	onUnload = "['onUnload',_this,""""ace_zeus_RscGroupSide""""] call ace_zeus_fnc_zeusAttributes";
	class Controls: Controls
	{
		class Background: Background
		{
		};
		class Title: Title
		{
		};
		class Content: Content
		{
			class Controls
			{
				class groupSide: RscControlsGroupNoScrollbars
				{
					onSetFocus = "_this call ace_zeus_fnc_ui_groupSide";
					idc = 26422;
					x = 0;
					y = 0;
					w = "(26 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
					h = "(2.5 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
					class controls
					{
						class Title: RscText
						{
							idc = 31002;
							text = "Side:";
							x = 0;
							y = 0;
							w = "(10 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							h = "(2.5 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							colorBackground[] = {0, 0, 0, 0.5};
						};
						class Background: RscText
						{
							idc = 31000;
							x = "(10 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							y = 0;
							w = "(16 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							h = "(2.5 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							colorBackground[] = {1, 1, 1, 0.1};
						};
						class BLUFOR: RscActivePicture
						{
							idc = 31200;
							text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
							x = "(12.5 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							y = "(0.25 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							w = "(2 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							h = "(2 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							tooltip = "BLUFOR";
						};
						class OPFOR: BLUFOR
						{
							idc = 31201;
							text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_east_ca.paa";
							x = "(15.5 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							y = "(0.25 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							w = "(2 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							h = "(2 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							tooltip = "OPFOR";
						};
						class Independent: BLUFOR
						{
							idc = 31202;
							text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_guer_ca.paa";
							x = "(18.5 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							y = "(0.25 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							w = "(2 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							h = "(2 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							tooltip = "Independent";
						};
						class Civilian: BLUFOR
						{
							idc = 31203;
							text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_civ_ca.paa";
							x = "(21.5 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							y = "(0.25 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							w = "(2 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
							h = "(2 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
							tooltip = "Civilian";
						};
					};
				};
			};
		};
		class ButtonOK: ButtonOK
		{
		};
		class ButtonCancel: ButtonCancel
		{
		};
	};
};
*/
//==================================================================================================
class OPAEX_Zeus_moduleBase: Module_F
{
	scope = 1;
	scopeCurator = 2;
	author = "Spartanjackwar";
	category = "OPAEX";
	
	function = "";
	functionPriority = 1;
	isGlobal = 1;
	isTriggerActivated = 0;
	
	icon = "\a3\Modules_F_Curator\Data\iconLightning_ca.paa";
	portrait = "\a3\Modules_F_Curator\Data\portraitLightning_ca.paa";
};
class OPAEX_Zeus_Glassing: OPAEX_Zeus_moduleBase
{
	curatorCanAttach = 1;
	category = "OPAEX_Zeus";
	displayName = "Glassing";
	function = "ace_zeus_fnc_moduleSuppressiveFire";
};

class RscControlsGroupNoScrollbars;
class RscDisplayAttributes
{
	class Controls
	{
		class Background;
		class Title;
		class Content;
	}
};
class OPAEX_Rsc_Zeus_Glassing: RscDisplayAttributes
{
	onLoad = "[""""onLoad"""",_this,""""OPAEX_Rsc_Zeus_Glassing"""",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""""onUnload"""",_this,""""OPAEX_Rsc_Zeus_Glassing"""",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	
	class Controls: Controls
	{
		class Background: Background
		{
		};
		class Title: Title
		{
		};
		class Content: Content
		{
			class Controls
			{
				class groupSide: RscControlsGroupNoScrollbars
				{
					onSetFocus = "_this call ace_zeus_fnc_ui_groupSide";
					idc = 26422;
					x = 0;
					y = 0;
					w = "(26 * (((safeZoneW / safeZoneH) min 1.2)/ 40))";
					h = "(2.5 * ((((safeZoneW / safeZoneH) min 1.2)/ 1.2)/ 25))";
					class controls
					{
						
					};
				};
			};
		};
		class ButtonOK: ButtonOK
		{
		};
		class ButtonCancel: ButtonCancel
		{
		};
	};
};