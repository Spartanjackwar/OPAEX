//Jack Moss, aka Spartanjackwar
//This config is used to package all animations of OPAEX.

class CfgPatches {
 	class OPAEX_Anims {
		addonRootClass = "OPAEX";
		author = "Spartanjackwar";
		requiredAddons[] = {
			"A3_Data_F_Enoch_Loadorder",
			"OPAEX_Core"
		};
 		units[] = {"BallBipodInvisibleCube"};
 		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
 		requiredVersion = 0.1;
 	};
};

class cfgVehicles {
	//invisible cube of DOOM
	class Constructions_base_F;
	class BallBipodInvisibleCube: Constructions_base_F {
		author = "Spartanjackwar";
		scope = 2;
		scopeCurator = 2;
		displayName = "BallBipodInvisibleCube";
		model = "\OPAEX_Anims\invisible cube of DOOM.p3d";
		
		hiddenSelections[] = {"TheOnlySelection"};
		hiddenSelectionTextures[] = {""};
	};
};

class CfgMovesBasic;
class CfgMovesMaleSdr: CfgMovesBasic {
	skeletonName = "OFP2_ManSkeleton";
	gestures = "CfgGesturesMale";
	class States {
		class CutSceneAnimationBaseSit;
		class OPAEX_BallBipod: CutSceneAnimationBaseSit {
			speed = -7; //The negative duration of the animation in seconds.
			looped = 0;
			canBlendStep = 0; //Sliding effect on/off
			minPlayTime= 6; //Minimun time before the animation can be interrupted
			
			file = "OPAEX_Anims\Ball Bipod Animation OFP2MAN.rtm";
			InterpolateTo[] = {"AmovPercMstpSnonWnonDnon", 2}; //Next animation after this one
		};
		class OPAEX_BallBipod_Online: OPAEX_BallBipod { //Other rig.
			file = "OPAEX_Anims\Ball Bipod Animation ONLINE.rtm";
		};
		
		class OPAEX_BallBipod_Entry: OPAEX_BallBipod {
			InterpolateTo[] = {
				"AmovPercMstpSnonWnonDnon", 2
			};  //Next edges that can follow this one that will be interpolated to
			connectTo[] = {
				"OPAEX_BallBipod_Standstill", 2,
				"OPAEX_BallBipod_Exit", 2
			}; //Next edges that can follow this anim.
		};
		class OPAEX_BallBipod_Standstill: OPAEX_BallBipod_Entry {
			file = "OPAEX_Anims\ballBipod STANDSTILL.rtm";
			looped = 1;
			minPlayTime= 0.1;
			speed = -0.1;
			//speed = -5.33;
			
			connectTo[] = {
				"OPAEX_BallBipod_Exit", 2
			};
		};
		class OPAEX_BallBipod_Exit: OPAEX_BallBipod_Entry {
			file = "OPAEX_Anims\ballBipod RETURN.rtm";
			speed = -4.67
			
			connectTo[] = {};
		};
	};
};