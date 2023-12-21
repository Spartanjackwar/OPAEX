class CfgVehicles
{
	//EXTERNALS
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit; // Default edit box (i.e., text input field)
			class Combo; // Default combo box (i.e., drop-down menu)
			class Checkbox; // Default checkbox (returned value is Bool)
			class CheckboxNumber; // Default checkbox (returned value is Number)
			class ModuleDescription; // Module description
			class Units; // Selection of units on which the module is applied
		};
		// Description base classes, for more information see below
		class ModuleDescription
		{
			class AnyBrain;
		};
	};
	
	//INTERNALS
	class OPAEX_Glassing_Module: Module_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "Glassing Beam";
		category = "Effects";
		icon = "\a3\Modules_F_Curator\Data\iconLightning_ca.paa";
		portrait = "\a3\Modules_F_Curator\Data\portraitLightning_ca.paa";

		function = "OPAEX_fnc_GlassingBeam_Module";
		functionPriority = 1; // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
		isGlobal = 0; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		isTriggerActivated = 1;
		isDisposable = 1; //1 = no repeat
		is3DEN = 0;
		curatorCanAttach = 1;

		//Menu displayed when the module is placed or double-clicked on by Zeus
		//curatorInfoType = "RscDisplayAttributesModuleOPAEX_Glassing";

		// Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
		class Attributes: AttributesBase {
			// Arguments shared by specific module type (have to be mentioned in order to be present)
			class Units: Units {
				property = "OPAEX_Glassing_Module_Units";
			};
			// Module specific arguments
			class colorPreset: Combo {
				property = "OPAEX_Module_Glassing_ColorPreset";
				displayName = "Glassing beam color preset";
				tooltip = "The color preset to use.";
				typeName = "NUMBER";
				defaultValue = "0";
				class Values
				{
					class Reach	 {name = "Reach Red"; value = 0;};
					class H2Blue {name = "Halo 3 Blue"; value = 1;};
					class Banana {name = "Banana camo...it's a bloody eyesore!"; value = 2;};
				};
			};
			class altitude: Edit {
				property = "OPAEX_Module_Glassing_Altitude";
				displayName = "Start altitude";
				tooltip = "Altitude where the beam starts.";
				defaultValue = "1000";
				validate = "number";
				type = "NUMBER";
			};
			class destructionRadius: Edit {
				property = "OPAEX_Module_Glassing_DestructionRadius";
				displayName = "AOE Radius";
				tooltip = "Radius of the beam's cleansing of the heretics.";
				defaultValue = "333";
				validate = "number";
				type = "NUMBER";
			};
			class duration: Edit {
				property = "OPAEX_Module_Glassing_Duration";
				displayName = "Duration";
				tooltip = "Length of time to run the beam in seconds.";
				defaultValue = "30";
				validate = "number";
				type = "NUMBER";
			};
			class destructionPercentage: Combo {
				property = "OPAEX_Module_Glassing_destructionPercentage";
				displayName = "Glassing beam yield"; //Argument label
				tooltip = "The strength, in percentage of destruction, of the resulting holy wrath"; // Tooltip description
				typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "100"; // Default attribute value. WARNING: This is an expression, and its returned value will be used
				class Values
				{
					class 0 {name = "0 percent death"; value = 0;};
					class 10 {name = "10 percent death"; value = 10;};
					class 20 {name = "20 percent death"; value = 20;};
					class 30 {name = "30 percent death"; value = 30;};
					class 40 {name = "40 percent death"; value = 40;};
					class 50 {name = "50 percent death"; value = 50;};
					class 60 {name = "60 percent death"; value = 60;};
					class 70 {name = "70 percent death"; value = 70;};
					class 80 {name = "80 percent death"; value = 80;};
					class 90 {name = "90 percent death"; value = 90;};
					class 100 {name = "100 percent death"; value = 100;};
				};
			};
			class Name: Edit {
				displayName = "Glassing Beam";
				tooltip = "Covenant glassing beam of death";
				// Default text filled in the input box
				// Because it's an expression, to return a String one must have a string within a string
				defaultValue = """The forbidden glass""";
			};
			class ModuleDescription: ModuleDescription{}; // Module description should be shown last
		};

		// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
		class ModuleDescription: ModuleDescription
		{
			description = "Covenant glassing beam for exacting holy wrath"; // Short description, will be formatted as structured text
			sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
	 
			class LocationArea_F
			{
				description[] = { // Multi-line descriptions are supported
					"Beam triggers on the spot of the module.",
					"Beam emitter will last 200 seconds."
				};
				position = 1; // Position is taken into effect
				direction = 0; // Direction is not taken into effect
				optional = 1; // Synced entity is optional
				duplicate = 0; // Multiple entities of this type can be synced
				synced[] = {"Anything"};
			};
		};
	};
};