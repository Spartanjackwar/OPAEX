//class TransportCountermeasuresComponent {};
class TransportPylonsComponent
{
	UIPicture = "\OPAEX_Pelican\Pelican.paa";
	class pylons
	{
		class pylons1 //"left" launcher
		{
			maxweight     = 560; //kg ,magazine with higher mass will not be allowed on this pylon
			hardpoints[]  = {"OPAEX_Hardpoint_D77-TC"}; // magazine with at least one same hardpoints name will be attachable
			attachment    = "OPAEX_M_ANVIL1_16Rnd"; // default magazine
			bay           = -1; // index of bay for animation
			priority      = 2; // pylon with higher priority is used to fire missile first, this can by changed in run time by script command setPylonsPriority
			UIposition[]  = {0.10, 0.50}; // x,y coordinates in 3DEN UI
			turret[]      = {}; // default owner of pylon/weapon, empty for driver
		};
		class pylons2: pylons1 //"right" launcher
		{
			mirroredMissilePos = 1;
			UIposition[]  = {0.10, 0.10};
		};
		class pylons3 //Temporary rear launcher, until B-65 comes out.
		{
			maxweight     = 1000; //kg ,magazine with higher mass will not be allowed on this pylon
			hardpoints[]  = {"OPAEX_Hardpoint_B65"}; // magazine with at least one same hardpoints name will be attachable
			attachment    = "OPAEX_M_Mk127_1Rnd"; // default magazine
			bay           = -1; // index of bay for animation
			priority      = 1; // pylon with higher priority is used to fire missile first, this can by changed in run time by script command setPylonsPriority
			UIposition[]  = {0.20, 0.30}; // x,y coordinates in 3DEN UI
			turret[]      = {}; // default owner of pylon/weapon, empty for driver
		};
	};
	#include<pelicanPylonPresets.hpp>
};