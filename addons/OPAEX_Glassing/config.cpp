class CfgPatches
{
	class OPAEX_Glassing
	{
		author = "Spartanjackwar";
		authors[] = {"Spartanjackwar", "DarkLordAinsley"};
 		requiredAddons[] = {
			"OPAEX_Core", "A3_Modules_F"
		};
		requiredVersion=0.1;
		units[]={"OPAEX_Glassing_Module"};
		weapons[]={};
	};
};

class CfgCloudlets
{
	class SmokeTrailEffect1;
	class OPAEX_Glass_PE: SmokeTrailEffect1 //The Part-effect
	{
		interval = "0.001";
		lifeTimeVar = 0;
		/*
		particleShape = "\A3\data_f\cl_exp";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		*/
		/*
		particleShape = "\A3\data_f\ParticleEffects\Universal\smoke.p3d";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		*/
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		//particleFSIndex = 7;
		//particleFSFrameCount = 48;
		particleFSIndex = 12;
		particleFSFrameCount = 16;
		
		//color[] = {{1, 0.2, 0.66, 0.33}, {1, 0.2, 0.66, 0.33}};
		color[] = {{1, 0.38024, 0.36456, 1}};
		emissiveColor[] = {{1, 1, 1, 1}, {1, 1, 1, 1}};
		particleFSLoop = 0;
		sizeCoef = 8;
		animationSpeed[] = {1000}; // interpolated speed of animation in animation cycles per second. For example if particleFSFrameCount is 8 and animationSpeed at the time is 0.4 result in 8 * 0.5 = 4 frame changes per second. Value 1000 is a special value but only when combined with particleFSLoop 0. This will instruct the engine to play only the last frame of the given count, so if particleFSFrameCount is 5, animationSpeed[] is {1000} and particleFSLoop is 0 only 5th frame will be played.
		lifeTime = 200;
		moveVelocity[] = {0, -150, 0}; //X Y Z
		rubbing = 0;
		rotationVelocity = 10;
		moveVelocityVar[] = {0, 0, 0};
		moveVelocityVarConst[] = {0, 0, 0};
		positionvar[] = {0.01, 0, 0.01};
	};
	class OPAEX_Glass_Banana_PE: OPAEX_Glass_PE
	{
		//color[] = {{0.21, 0.50, 0.41, 1}};
		color[] = {{0.22, 0.272, 0.07, 1}};
	};
	class OPAEX_Glass_Blue_PE: OPAEX_Glass_PE
	{
		//color[] = {{0.3, 0.2, 1.0, 0.33}};
		color[] = {{0.623084, 0.7173012, 0.99176, 1}};
	};
	class OPAEX_Glass_heat_PE: OPAEX_Glass_PE //The Part-effect of the heat haze
	{
		particleShape = "\A3\data_f\ParticleEffects\Universal\Refract";
		
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		particleFSLoop = 1;
		sizecoef = 12;
		
		color[] = {{0,0,0,1}, {0,0,0,0.8}, {0,0,0,0.6}, {0,0,0,0.4}, {0,0,0,0.2}}; //Alpha is the only one with effect on haze.
	};
	class OPAEX_Glass_Interior_PE: OPAEX_Glass_PE
	{
		/*
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 7;
		particleFSFrameCount = 48;
		particleFSLoop = 1;
		*/
		//particleShape = "A3\data_f\laserBeam.p3d";
		particleShape = "A3\data_f\koule.p3d";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		particleType = "Spaceobject";
		
		color[] = {{1, 1, 1, 1}};
		emissiveColor[] = {{1, 1, 1, 1}, {1, 1, 1, 1}};
		sizeCoef = 2;
		positionvar[] = {0, 0, 0};
	};
};

class OPAEX_Glass_effects
{
	class OPAEX_Glass_CE //The Complex Effect
	{
		simulation = "particles"; //type of simulation - particles or light
		type = "OPAEX_Glass_PE";      //name of PE's class defined in CfgCloudlets or light's class defined in CfgLights
		position[] = {0, 0, 0};   //position related to the default position or memorypoint
		lifeTime = 599940;             //life time of emitter
		qualityLevel = -1;        //effect is only used when the the particle quality option particlesQuality in user settings matches this qualityLevel. -1 play everytime, 0 play only on low, 1 play only on normal, 2 play only on high. Default: -1
		start = 1;                //is used only if the lifeTime parameter is defined, if value is changed from negative to positive then the effect is triggered
		enabled = 1;              //1 effect is enabled, -1 effect is disabled
	};
	class OPAEX_Glass_heat_CE //The Complex Effect
	{
		simulation = "particles";
		type = "OPAEX_Glass_heat_PE";
		position[] = {0, 0, 0};
		lifeTime = 599940; //120
		qualityLevel = 0;
		start = 1;
		enabled = 1;
	};
	class OPAEX_Glass_Interior_CE: OPAEX_Glass_CE
	{
		type = "OPAEX_Glass_Interior_PE";
	};
};

class CfgFactionClasses
{
	class NO_CATEGORY;
	class OPAEX_Glassing: NO_CATEGORY
	{
		displayName = "Glassing Beams";
		side = 7; //from NO_CATEGORY
	};
};

class CfgAmmo
{
	class OPTRE_MAC_Round;
	class OPAEX_Glass_Round: OPTRE_MAC_Round
	{
		indirectHitRange = 1; //Limits the beam to blast radius of 4 meters for the initial shot.
		author = "spartanjackwar";
		//effectFly = "OPAEX_Glass_effects";
		coefGravity = 1; //Just to make sure
		//CraterEffects = "ArtyShellCrater";
		CraterEffects = "BombCrater";
		explosionEffects = "BombExplosion";
	};
};

class RscObject;
class RscText;
class RscFrame;
class RscLine;
class RscProgress;
class RscPicture;
class RscPictureKeepAspect;
class RscVideo;
class RscHTML;
class RscButton;
class RscShortcutButton;
class RscEdit;
class RscCombo;
class RscListBox;
class RscListNBox;
class RscXListBox;
class RscTree;
class RscSlider;
class RscXSliderH;
class RscActiveText;
class RscActivePicture;
class RscActivePictureKeepAspect;
class RscStructuredText;
class RscToolbox;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscControlsGroupNoVScrollbars;
class RscButtonTextOnly;
class RscButtonMenu;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscButtonMenuSteam;
class RscMapControl;
class RscMapControlEmpty;
class RscCheckBox;
class RscDisplayAttributes
{
	class ControlsBackground
	{
		class Map: RscMapControl {};
	};
	class Controls
	{
		class Background: RscText {};
		class Title: RscText {};
		class Content: RscControlsGroup {};
		class ButtonOK: RscButtonMenuOK {};
		class ButtonCustom: RscButtonMenu {};
		class ButtonCancel: RscButtonMenuCancel {};
	};
};
#include "GenericMenuDisplay.hpp"
#include "AttributeDisplays.hpp"
class RscDisplayAttributesModuleOPAEX_Glassing: RscDisplay_OPAEX_GenericMenuDisplay
{
	idd = 4000;
	scriptName = "RscDisplayAttributesModuleOPAEX_Glassing";
	scriptPath = "CuratorDisplays";
	onLoad = "['onLoad', _this, 'RscDisplayAttributesModuleOPAEX_Glassing', 'CuratorDisplays', true] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "['onUnload', _this, 'RscDisplayAttributesModuleOPAEX_Glassing', 'CuratorDisplays', true] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Title: Title {
			text = "Glassing Beam";
		};
		class Content: Content
		{
			class Controls: Controls
			{
				class DestructionRadius: Rsc_OPAEX_AttributeNumberFromXSlider {
					idc = 2301;
					x = 0;
					y = 0;
					class Controls: Controls {
						class AttributeSlider: AttributeSlider {
							sliderRange[] = {0, 5000};
							sliderStep = 100;
						};
						class AttributeName: AttributeName {
							text = "Destruction radius (meters):";
						};
					};
				};
				class Altitude: Rsc_OPAEX_AttributeNumberFromXSlider {
					idc = 2302;
					x = 0;
					y = 1 * (2 * GUI_GRID_H);
					class Controls: Controls {
						class AttributeSlider: AttributeSlider {
							sliderRange[] = {0, 5000};
						};
						class AttributeName: AttributeName {
							text = "Altitude (meters):";
						};
					};
				};
				class Duration: Rsc_OPAEX_AttributeNumberFromXSlider {
					idc = 2303;
					x = 0;
					y = 2 * (2 * GUI_GRID_H);
					class Controls: Controls {
						class AttributeSlider: AttributeSlider {
							sliderRange[] = {1, 3600};
						};
						class AttributeName: AttributeName {
							text = "Duration (seconds):";
						};
					};
				};
				class DestructionRate: Rsc_OPAEX_AttributeNumberFromXSlider {
					idc = 2304;
					x = 0;
					y = 3 * (2 * GUI_GRID_H);
					class Controls: Controls {
						class AttributeSlider: AttributeSlider {
							sliderRange[] = {0, 100};
							sliderStep = 10;
						};
						class AttributeName: AttributeName {
							text = "Kill percentage in radius:";
						};
					};
				};
				class ColorPreset: Rsc_OPAEX_AttributeNumberFromXListBox {
					idc = 2305;
					x = 0;
					y = 4 * (2 * GUI_GRID_H);
					class Controls: Controls {
						class AttributeBox: AttributeBox
						{
							class Items: Items
							{
								class Item0: Item0
								{
									text = "Reach redish purple";
									
									data = "0";
									value = 0;
								};
								class Item1: Item1
								{
									text = "Halo 3 Blue";
									
									data = "1";
									value = 1;
								};
								class Item2: Item1
								{
									text = "Banana camo...it's a bloody eyesore!";
									
									data = "2";
									value = 2;
								};
							};
						};
						class AttributeName: AttributeName
						{
							text = "Color preset:";
						};
					};
				};
			};
		};
		class ButtonOK: ButtonOK {};
		class ButtonCancel: ButtonCancel {};
	};
};
#include<module.hpp>