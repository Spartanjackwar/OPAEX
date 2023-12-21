#define G_TTL 2  //Defines lifetime for particle emitters.
#define M_SPEED 1000  //Defines speed for the beam in m/s.
#define M_SPEED_GEN2 2000  //Defines speed for the beam in m/s.

class CfgPatches
{
 	class OPAEX_M6GGNR
 	{
		author = "Spartanjackwar";
		authors[] = {"Spartanjackwar"};
 		requiredAddons[] = {
			"OPTRE_Core", "OPAEX_Core", "Extended_EventHandlers"
		};
 		units[] = {};
 		weapons[] = {"OPAEX_M6GGNR"};
		magazines[] = {"OPAEX_M6GGNR_Battery"};
		ammo[] = {"OPAEX_M6GGNR_Beam"};
 		requiredVersion = 0.1;
 	};
};

class Mode_SemiAuto;
class Mode_FullAuto;
class Mode_Burst;
class EventHandlers; //Not sure about this one

class CfgWeapons
{
	class OPTRE_M41_SSR_G;
	//class OPAEX_M6GGNR: OPTRE_M41_SSR
	class OPAEX_M6GGNR: OPTRE_M41_SSR_G
	{
		//model = "\OPTRE_Weapons\Rockets\M41_tube.p3d";
		//model = "\OPTRE_Weapons\data\spartan_laser.p3d";
		scope = 1;
		scopeArsenal = 0;
		
		dlc = "OPAEX";
		displayName = "[OPAEX] W/AV M6 G/GNR";
		descriptionShort = "Spartan Laser";
		effectsMissile = "splaser";
		baseWeapon = "OPAEX_M6GGNR";
		
		reloadTime = 0.01;
		magazineReloadTime = 4;
		autoReload = 1;
		
		magazines[] = {"OPAEX_M6GGNR_Battery"};
		magazineWell[] =  {"OPAEX_M6GGNR"};
		
		initSpeed = 0;
		ballisticsComputer = 0;
		
		modes[] = {"FullBurst", "MediumBurst", "ShortBurst"};
		recoil = "Empty";
		class FullBurst: Mode_Burst
		{
			sounds[] = {"StandardSound"};
			class StandardSound
			{
				begin1[] = {"OPTRE_Weapons\Vehicle\data\sounds\Laser_1.wss", 2.5, 1, 1500};
				soundBegin[] = {"begin1", 1};
			};
			soundContinuous = 1;
			soundBurst = 1;
			
			aiRateOfFire = 1;
			
			reloadTime = 0.01;
			magazineReloadTime = 4;
			autoReload = 1;
			autoFire = 0;
			burst = 10;
			
			displayName = "Full Burst";
			textureType = "fullAuto";
			showToPlayer = true;
			
			minRange = 50;
			minRangeProbab = 0.4;
			midRange = 1000;
			midRangeProbab = 0.4;
			maxRange = 1500;
			maxRangeProbab = 0.2;
		};
		class MediumBurst: FullBurst
		{	
			burst = 5;
			displayName = "Medium Burst";
			textureType = "burst";
		};
		class ShortBurst: FullBurst
		{
			burst = 2;
			displayName = "Short Burst";
			textureType = "semi";
		};
		/*
		class EventHandlers
		{
			class beamInit
			{
				//fired = "_this call OPAEX_fnc_spawnShot";
				fired = "_this call OPAEX_fnc_spawnShotSplaser";
			};
		};
		*/
	};
	
	class OPAEX_SpartanLaser: OPAEX_M6GGNR {
		author = "Mesa + Spartanjackwar, but mostly Mesa";
		baseWeapon = "OPAEX_SpartanLaser";
		scope = 2;
		scopeArsenal = 2;
		/*
		class WeaponSlotsInfo
		{
			mass = 150;
		};
		*/
		
		modes[] = {"pew"};
		class pew: ShortBurst {
			burst = 1; //Number of shots.
			multiplier = 1; //Ammo per shot.
			aiBurstTerminable = false;
			reloadTime = 2.5;
			
			displayName = "Charge-up laser";
			textureType = "fullAuto";
		};
		
		
		//ACE Overpressure
		ace_overpressure_angle = 0;
		ace_overpressure_range = 0;
		ace_overpressure_damage = 0;
		
		//UI Visuals
		displayname = "[OPAEX] Spartan laser";
		descriptionshort = "M6V Grindel/Galilean Non-Linear Rifle";
		pictureWire = "\OPAEX_M6GGNR\data\ui\splaserwire.paa";
		picture = "\OPAEX_M6GGNR\data\ui\essplaser.paa";
		
		//Rendering Visuals
		model = "\OPAEX_M6GGNR\data\spartan_laser.p3d";
		handAnim[] = 
		{
			"OFP2_ManSkeleton",
			"\OPAEX_M6GGNR\data\spartan_laser.rtm"
		};
		hiddenSelections[] = 
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[] = 
		{
			"OPAEX_M6GGNR\data\82nd_Spartan_Laser_Camo1_co.paa",
			"OPAEX_M6GGNR\data\82nd_Spartan_Laser_Camo2_co.paa"
		};
		class GunParticles {};
		cursor = "OPAEX_AnActualSpartanLaser";
		
		//Optics
		modelOptics[] = 
		{
			"\OPAEX_M6GGNR\data\ui\M6V_Optic_2x.p3d",
			"\OPAEX_M6GGNR\data\ui\M6V_Optic_4x.p3d",
			"\OPAEX_M6GGNR\data\ui\M6V_Optic_10x.p3d"
		};
		class OpticsModes
		{
			class StepScope
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] =
				{
					"OpticsCHAbera1",
					"OpticsBlur1"
				};
				opticsFlare = 0;
				opticsZoomMin = 0.125;
				opticsZoomMax = 0.041999999;
				opticsZoomInit = 0.125;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memoryPointCamera = "eye";
				cameraDir = "look";
				modelOptics[] = 
				{
					"\OPAEX_M6GGNR\data\ui\M6V_Optic_2x.p3d",
					"\OPAEX_M6GGNR\data\ui\M6V_Optic_4x.p3d",
					"\OPAEX_M6GGNR\data\ui\M6V_Optic_10x.p3d"
				};
				visionMode[] =
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[] = {0,1,7};
				opticsDisablePeripherialVision = 1;
				discretefov[] = {0.125,0.052499998,0.041999999};
				discreteInitIndex = 0;
			};
		};
		
	};
	
	class OPAEX_SpartanLaserRGB: OPAEX_SpartanLaser {
		displayname = "[OPAEX] Spartan laser RGB edition";
		descriptionshort = "M6V Grindel/Galilean Non-Linear Gamer Rifle";
		baseWeapon = "OPAEX_SpartanLaserRGB";
		hiddenSelectionsTextures[] = 
		{
			"OPAEX_M6GGNR\data\82nd_Spartan_Laser_Camo1RGB_co.paa",
			"OPAEX_M6GGNR\data\82nd_Spartan_Laser_Camo2_co.paa"
		};
	};
	
	/*
	class OPTRE_M6_Laser: OPTRE_M68_GAUSS
	{//OPTRE
		reloadTime = 0.01;
		magazineReloadTime = 5;
		autoReload = 1;
		displayName = "M6 Nonlinear Directed Energy Weapon";
		descriptionShort = "Laser";
		magazines[] = {"OPTRE_SpLaser_Battery"};
		class player: Mode_Burst
		{
			sounds[] = {"StandardSound"};
			class StandardSound
			{
				begin1[] = {"OPTRE_Weapons\Vehicle\data\sounds\Laser_1.wss", 2.5, 1, 1500};
				soundBegin[] = {"begin1", 1};
			};
			soundContinuous = 1;
			reloadTime = 0.01;
			magazineReloadTime = 5;
			autoReload = 1;
			burst = 100;
		};
	};
	*/
};

class CfgMagazines
{
	class OPTRE_M41_Twin_HEAT;
	class OPAEX_M6GGNR_Battery: OPTRE_M41_Twin_HEAT
	{
		dlc = "OPAEX";
		scope = 2;
		//displayName = "BA-53635/PLMD"; //"Series 6971 Battery cell";
		displayName = "Spartan laser battery";
		displayNameShort = "M6 G/GNR Battery"; //"Series 6971 Battery";
		ammo = "OPAEX_M6GGNR_Beam_Gen2"; //"OPTRE_25x130mm_Slug";
		
		initSpeed = M_SPEED_GEN2;
		muzzleImpulseFactor[] = {0, 0};
		tracersEvery = 1;
		lastRoundsTracer = 5;
		count = 5;
		mass = 200;
	};
};

class CfgAmmo
{
	class OPTRE_M41_Rocket_HEAT;
	class OPAEX_M6GGNR_Beam : OPTRE_M41_Rocket_HEAT
	{
		//model = "\OPTRE_Weapons\data\spartan_laser.p3d"; //Is the tracer model, but 190 meters long.
		//tracerScale = 3;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
		effectsMissile = "NewSplaserEffects"; //"splaser";
		effectsMissileInit = "NewSplaserEffects"; //"splaser";
		explosionEffects = "NewSplaserEffects";
		
		timeToLive = 1; //This makes the initial speed the maximum range.
		
		//Warhead
		caliber = 1;
		hit = 62.5;
		indirectHitRange = 1;
		indirectHit = 62.5;
		explosive = 0.33;
		fuseDistance = 0;
		submunitionAmmo = "ammo_Penetrator_120mm";
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionInitSpeed = 1000;
		submunitionParentSpeedCoef = 0;
		submunitionInitialOffset[] = {0, 0, 0};
		
		//Aero
		airFriction = 0;
		sideairFriction = 0;
		coefGravity = 0;
		maxSpeed = M_SPEED;
		typicalSpeed = M_SPEED;
		
		//Motor
		initTime = 0;
		thrustTime = 0.1;
		thrust = 1000000;
		
		//Sensor
		irLock = 0;
		airLock = 0;
		laserLock = 0;
		nvLock = 0;
		manualControl = 0;
		
		//Other stuff
		trackLead = 0;
		trackOversteer = 0;
		visibleFire = 1000;
		weaponLockSystem = "0";
		class ace_missileguidance
		{
			enabled = 0;
		};
		
		//Not sure if this works.
		tracerScale = 3;
		tracerStartTime = 0.05;
		tracerEndTime = 1;
		tracersEvery = 1;
	};
	class OPAEX_M6GGNR_Beam_Damageless: OPAEX_M6GGNR_Beam
	{
		model = "\OPTRE_Weapons\data\spartan_laser.p3d";
		caliber = 0;
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		submunitionAmmo = "";
	};
	class OPAEX_M6GGNR_Beam_Gen2: OPAEX_M6GGNR_Beam {
		//Produce a more explosive direct hit weapon.
		explosive = 1;
		hit = 100;
		indirectHit = 100;
		indirectHitRange = 2;
		caliber = 0;
		
		triggerOnImpact = 1;
		submunitionInitSpeed = 350;
		submunitionParentSpeedCoef = 0;
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionConeType[] = {"custom", {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}}};
		submunitionAmmo = "ammo_Penetrator_125mm_missile";
		
		visibleFire = M_SPEED_GEN2;
		maxSpeed = M_SPEED_GEN2;
		typicalSpeed = M_SPEED_GEN2;
	};
};

class cfgMagazineWells
{
	class OPAEX_M6GGNR
	{
		OPAEX_Splaser[] = {
			"OPAEX_M6GGNR_Battery"
		};
	};
};

class cfgWeaponCursors
{
	class throw;
	class OPAEX_AnActualSpartanLaser: throw
	{
		texture = "\OPAEX_M6GGNR\data\ui\splaser_reticle.paa";
	};
};

class Extended_respawn_EventHandlers {
	class CAManBase {
		class OPAEX_Event_RespawnActionClear {
			Respawn = "params['_new', '_old']; _new setVariable ['OPAEX_StopFireActionIDs', [], true];";
		};
		class OPAEX_Event_SpartanLaser {
			Respawn = "params['_new', '_old']; [_new, 'OPAEX_SpartanLaser', [100, 0, 0], 1.5] call OPAEX_fnc_Extended_InitPost_splaser;";
		};
		class OPAEX_Event_SpartanLaserRGB {
			Respawn = "params['_new', '_old']; [_new, 'OPAEX_SpartanLaserRGB', [0, 0, 0], 1.5] call OPAEX_fnc_Extended_InitPost_splaser;";
		};
	};
};

class Extended_EntityKilled_EventHandlers {
	class CAManBase {
		class OPAEX_Event_SpartanLaser {
			serverEntityKilled = "_actions = (_this select 0) getVariable ['OPAEX_StopFireActionIDs', []]; {(_this select 0) removeAllActions (_x select 0)} forEach _actions;";
		};
	};
};

class Extended_InitPost_EventHandlers { //Run after all inits, including PostInit. Scheduler allowed.
	class CAManBase {
		class OPAEX_Event_SpartanLaser { //Handles adding the action that prevents normal firing.
			serverInit = "[_this select 0, 'OPAEX_SpartanLaser', [100, 0, 0], 1.5] spawn OPAEX_fnc_Extended_InitPost_splaser"; //Used to be 3 seconds, but using an actual stopwatch says it was 6, so half of six is the 3 we wanted.
		};
		class OPAEX_Event_SpartanLaserRGB {
			serverInit = "[_this select 0, 'OPAEX_SpartanLaserRGB', [0, 0, 0], 1.5] spawn OPAEX_fnc_Extended_InitPost_splaser";
		};
	};
};

//==================================================================================================
//The Effects
//==================================================================================================
class CfgCloudlets
{
	class SmokeTrailEffect1;
	class splaser_PE: SmokeTrailEffect1 //The Part-effect
	{
		interval = "0.001"; //"0.00001";
		lifeTimeVar = 0;
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		color[] = {{1,0.2,0.2,0.33},{1,0.2,0.2,0.33}};
		emissiveColor[] = {{30,30,30,1},{30,30,30,0}};
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 16;
		particleFSLoop = 0;
		sizeCoef = 0.25;
		animationSpeed[] = {1000}; //interpolated speed of animation in animation cycles per second. For example if particleFSFrameCount is 8 and animationSpeed at the time is 0.4 result in 8 * 0.5 = 4 frame changes per second. Value 1000 is a special value but only when combined with particleFSLoop 0. This will instruct the engine to play only the last frame of the given count, so if particleFSFrameCount is 5, animationSpeed[] is {1000} and particleFSLoop is 0 only 5th frame will be played.
		
		moveVelocity[] = {0, 0, 0}; //X Y Z
		//moveVelocity[] = {speedX, speedY, speedZ}; //X Y Z
		rubbing = 0;
		rotationVelocity = 0;
		moveVelocityVar[] = {0, 0, 0};
		moveVelocityVarConst[] = {0, 0, 0};
	};
	class splaser_inner_PE: splaser_PE //The Part-effect of the inner laser
	{
		color[] = {{1,1,1,1},{1,0.2,0.2,1}};
		sizeCoef = 0.15;
	};
	class splaser_heat_PE: SmokeTrailEffect1 //The Part-effect
	{
		interval = "0.001";
		particleShape = "\A3\data_f\ParticleEffects\Universal\Refract";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		color[] = {{0,0,0,1},{0,0,0,0}}; //RGB doesn't affect refraction.  Alpha does though.
		animationSpeed[] = {10}; //No idea if this affects it.
		
		moveVelocity[] = {0, 0, 0}; //X Y Z
		//moveVelocity[] = {speedX, speedY, speedZ}; //X Y Z
		rubbing = 0;
		rotationVelocity = 1;
		moveVelocityVar[] = {0, 0, 0};
		moveVelocityVarConst[] = {0, 0, 0};
		/*
		damageType="Fire"; //damage type, only available option is "Fire" so far
		coreIntensity = 2; //damage coeficient in the center of fire
		coreDistance = 2; //how far can unit get damage
		damageTime = 0.01; //how often is unit getting damage
		*/
	};
};

class splaser
{//No longer used due to obscene performace impact, so this is legacy code.
	class splaser_CE //The Complex Effect
	{
		simulation = "particles"; //type of simulation - particles or light
		type = "splaser_PE";      //name of PE's class defined in CfgCloudlets or light's class defined in CfgLights
		position[] = {0, 0, 0};   //position related to the default position or memorypoint
		lifeTime = G_TTL;             //life time of emitter
		qualityLevel = -1;        //effect is only used when the the particle quality option particlesQuality in user settings matches this qualityLevel. -1 play everytime, 0 play only on low, 1 play only on normal, 2 play only on high. Default: -1
		start = 1;                //is used only if the lifeTime parameter is defined, if value is changed from negative to positive then the effect is triggered
		enabled = 1;              //1 effect is enabled, -1 effect is disabled
	};
   class splaser_inner_CE //The Complex Effect
	{
		simulation = "particles";
		type = "splaser_inner_PE";
		position[] = {0, 0, 0};
		lifeTime = G_TTL;
		qualityLevel = -1;
		start = 1;
		enabled = 1;
	};
   class splaser_heat_CE //The Complex Effect
	{
		simulation = "particles";
		type = "splaser_heat_PE";
		position[] = {0, 0, 0};
		lifeTime = G_TTL;
		qualityLevel = 0;
		start = 1;
		enabled = 1;
	};
};

class NewSplaserEffects
{//The new effect code, which just has the heat refraction.
	class splaser_heat_CE
	{
		simulation = "particles";
		type = "splaser_heat_PE";
		position[] = {0, 0, 0};
		lifeTime = G_TTL;
		qualityLevel = -1; //Honestly, this probably isn't the best thing to force on users.
		start = 1;
		enabled = 1;
	};
};
