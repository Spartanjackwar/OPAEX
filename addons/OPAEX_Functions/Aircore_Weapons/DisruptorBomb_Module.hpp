class OPAEX_DisruptorBomb_Module: OPAEX_CryoBomb_Module
{
	displayName = "Disruptor Bomb";
	
	function = "OPAEX_fnc_DisruptorBomb_Module";

	// Menu displayed when the module is placed or double-clicked on by Zeus
	//curatorInfoType = "RscDisplayAttributeModuleNuke"; //TODO: the resource for this shit.

	// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
	class Attributes: AttributesBase
	{
		// Module specific arguments
		class Radius: Edit
		{
			property = "OPAEX_DisruptorBomb_Module_Radius";
			displayName = "Radius of bomb's AOE";
			tooltip = "Radius of the bomb's disruption";
			defaultValue = "150";
			validate = "number";
			type = "NUMBER";
		};
		class Duration: Edit
		{
			property = "OPAEX_DisruptorBomb_Module_Duration";
			displayName = "Duration of bomb's effects in seconds";
			tooltip = "Duration of bomb's effects in seconds";
			defaultValue = "30";
			validate = "number";
			type = "NUMBER";
		};
		class DisplayTimer: Combo
		{
			property = "OPAEX_DisruptorBomb_Module_displayTimer";
			displayName = "Display Timer";
			tooltip = "Should we display a timer for the duration of the effect?";
			typeName = "BOOL"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			defaultValue = "False";
			class Values
			{
				class True	{name = "True";	value = true;};
				class False	{name = "False";value = false;};
			};
		};
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "UNSC Disruptor Bomb"; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"Disruptor bomb triggers on the spot of the module."
			};
			position = 1; // Position is taken into effect
			direction = 0; // Direction is not taken into effect
			optional = 1; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"Anything"};
		};
	};
};