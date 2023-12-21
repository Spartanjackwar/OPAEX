class OPAEX_IlluminationBomb_Module: OPAEX_DisruptorBomb_Module
{
	displayName = "Illumination Bomb";
	
	function = "OPAEX_fnc_Mk127_Module";

	// Menu displayed when the module is placed or double-clicked on by Zeus
	//curatorInfoType = "RscDisplayAttributeModuleNuke"; //TODO: the resource for this shit.

	// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
	class Attributes: AttributesBase
	{
		// Module specific arguments
		class IlluminationPower: Edit
		{
			property = "OPAEX_IlluminationBomb_Module_IlluminationPower";
			displayName = "Illumination power of the bomb";
			tooltip = "Illumination power of the bomb";
			defaultValue = "0.10";
			validate = "number";
			type = "NUMBER";
		};
		class IlluminationRange: IlluminationPower
		{
			property = "OPAEX_IlluminationBomb_Module_IlluminationRange";
			displayName = "Illumination range of the bomb";
			tooltip = "Illumination range of the bomb";
			defaultValue = "2000";
		};
		class Red: IlluminationPower
		{
			property = "OPAEX_IlluminationBomb_Module_Red";
			displayName = "Red";
			tooltip = "Red component of the light";
			defaultValue = "1.0";
		};
		class Green: Red
		{
			property = "OPAEX_IlluminationBomb_Module_Green";
			displayName = "Green";
			tooltip = "Green component of the light";
			defaultValue = "1.0";
		};
		class Blue: Green
		{
			property = "OPAEX_IlluminationBomb_Module_Blue";
			displayName = "Blue";
			tooltip = "Blue component of the light";
			defaultValue = "1.0";
		};
		class ModuleDescription: ModuleDescription{}; // Module description should be shown last
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "UNSC Illumination Bomb"; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"Illumination bomb triggers on the spot of the module."
			};
			position = 1; // Position is taken into effect
			direction = 0; // Direction is not taken into effect
			optional = 1; // Synced entity is optional
			duplicate = 0; // Multiple entities of this type can be synced
			synced[] = {"Anything"};
		};
	};
};