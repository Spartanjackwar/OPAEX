class TransportPylonsComponent
{
	UIPicture = "\OPTRE_Vehicles_Air\Hornet\HornetPylonPic.paa";
	class pylons
	{
		class pylons1 //"left" launcher
		{
			maxweight     = 560; //kg ,magazine with higher mass will not be allowed on this pylon
			hardpoints[]  = {"OPAEX_Hardpoint_AV14"}; // magazine with at least one same hardpoints name will be attachable
			attachment    = "OPTRE_6Rnd_C2GMLS_missiles"; // default magazine
			bay           = -1; // index of bay for animation
			priority      = 2; // pylon with higher priority is used to fire missile first, this can by changed in run time by script command setPylonsPriority
			UIposition[]  = {0.15, 0.2}; // x,y coordinates in 3DEN UI
			turret[]      = {}; // default owner of pylon/weapon, empty for driver
		};
		class pylons2: pylons1 //"right" launcher
		{
			mirroredMissilePos = 1;
			UIposition[]  = {0.35, 0.2};
		};
	};
	#include<HornetPylonPresets.hpp>
};