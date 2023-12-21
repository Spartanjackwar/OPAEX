class OPAEX_CryoBomb_Module: Module_F
{
	scope = 2;
	scopeCurator = 2;
	displayName = "Cryobomb";
	category = "Effects";
	icon = "\a3\Modules_F_Curator\Data\iconLightning_ca.paa";
	portrait = "\a3\Modules_F_Curator\Data\portraitLightning_ca.paa";

	function = "OPAEX_fnc_CryoBomb_Module";
	functionPriority = 1; // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	isGlobal = 1; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
	isTriggerActivated = 1;
	isDisposable = 1; //1 = no repeat
	is3DEN = 0;

	// Menu displayed when the module is placed or double-clicked on by Zeus
	//curatorInfoType = "RscDisplayAttributeModuleNuke"; //TODO: the resource for this shit.

	// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
	class Attributes: AttributesBase
	{
		// Module specific arguments
		class Radius: Edit
		{
			property = "OPAEX_Cryobomb_Module_Radius";
			displayName = "Radius of bomb's AOE";
			tooltip = "Radius of the bomb's freezing";
			validate = "number";
			type = "NUMBER";
		};
		class Duration: Edit
		{
			property = "OPAEX_Cryobomb_Module_Duration";
			displayName = "Duration of bomb's effects in seconds";
			tooltip = "Duration of bomb's effects in seconds";
			validate = "number";
			type = "NUMBER";
		};
		/*
		class Name: Edit
		{
			displayName = "CryoBomb";
			tooltip = "UNSC CryoBomb";
			// Default text filled in the input box
			// Because it's an expression, to return a String one must have a string within a string
			defaultValue = """Warning: Do not eat the iced split-jaws""";
		};
		*/
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "UNSC CryoBomb"; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"CryoBomb triggers on the spot of the module.  Warning: Do not eat the iced split-jaws"
			};
			position = 1; // Position is taken into effect
			direction = 0; // Direction is not taken into effect
			optional = 1; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"Anything"};
		};
	};
};