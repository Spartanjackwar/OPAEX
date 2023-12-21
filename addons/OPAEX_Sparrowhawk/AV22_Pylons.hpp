class TransportPylonsComponent
{
	UIPicture = "\OPTRE_Vehicles_Air\Sparrowhawk\sparrowhawkPylonImage.paa";
	class pylons
	{
		class WingPylonRight1 //right tip
		{
			maxweight     = 560; //kg ,magazine with higher mass will not be allowed on this pylon
			hardpoints[]  = {"OPAEX_Hardpoint_AV22"}; // magazine with at least one same hardpoints name will be attachable
			attachment    = "OPTRE_6Rnd_C2GMLS_missiles"; // default magazine
			bay           = -1; // index of bay for animation
			priority      = 3; // pylon with higher priority is used to fire missile first, this can by changed in run time by script command setPylonsPriority
			UIposition[]  = {0.35, 0.1}; // x,y coordinates in 3DEN UI
			turret[]      = {}; // default owner of pylon/weapon, empty for driver
			//"CopilotTurret" is the only turret option in this case.
		};
		class WingPylonRight2: WingPylonRight1
		{
			priority      = 2;
			UIposition[]  = {0.30, 0.134}; // x,y coordinates in 3DEN UI
		};
		class WingPylonRight3: WingPylonRight1
		{
			priority      = 1;
			UIposition[]  = {0.35, 0.167}; // x,y coordinates in 3DEN UI
		};
		
		class WingPylonLeft3: WingPylonRight3
		{
			mirroredMissilePos = 3;
			UIposition[]  = {0.35, 0.4};
		};
		class WingPylonLeft2: WingPylonRight2
		{
			mirroredMissilePos = 2;
			UIposition[]  = {0.30, 0.434};
		};
		class WingPylonLeft1: WingPylonRight1 //left tip
		{
			mirroredMissilePos = 1;
			UIposition[]  = {0.35, 0.467};
		};
	};
	#include<AV22_PylonPresets.hpp>
};