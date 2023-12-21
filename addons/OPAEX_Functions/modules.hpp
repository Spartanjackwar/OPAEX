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

#include<Aircore_Weapons\CryoBomb_Module.hpp>
#include<Aircore_Weapons\DisruptorBomb_Module.hpp>
#include<Aircore_Weapons\IlluminationBomb_Module.hpp>