class OPAEX_D20_W_M45BananaGod: OPTRE_M45 {
	author = "spartanjackwar";
	scope = 1;
	displayName = "M45Ban BananaGod Shotgun";
	descriptionShort = "BananaGod Shotgun";
	magazines[] = {"OPAEX_D20_M45BananaGod_6666Rnd"};
	magazineWell[] = {};
	
	modes[] = {"Single"};
	class Single: Mode_SemiAuto
	{
		sounds[] = {"StandardSound"};
		class BaseSoundModeType
		{
			weaponSoundEffect = "DefaultRifle";
			closure1[] = {"", 1, 1, 200};
			closure2[] = {"", 1, 1, 200};
			soundClosure[] = {"closure1", 0.5};
		};
		class StandardSound: BaseSoundModeType
		{
			begin1[] = {"\OPTRE_Weapons\Shotgun\data\sounds\fire1.ogg", 1.3, 1, 1500};
			soundBegin[] = {"begin1", 1};
			class SoundTails
			{
				class TailForest
				{
					sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\M320\M320_tail_forest", 1, 1, 2200};
					frequency = 1;
					volume = "(1-interior/1.4)*forest";
				};
				class TailHouses
				{
					sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\M320\M320_tail_houses", 1, 1, 2200};
					frequency = 1;
					volume = "(1-interior/1.4)*houses";
				};
				class TailInterior
				{
					sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\M320\M320_tail_interior", 1.99526, 1, 2200};
					frequency = 1;
					volume = "interior";
				};
				class TailMeadows
				{
					sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\M320\M320_tail_meadows", 1, 1, 2200};
					frequency = 1;
					volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
				};
				class TailTrees
				{
					sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\M320\M320_tail_trees", 1, 1, 2200};
					frequency = 1;
					volume = "(1-interior/1.4)*trees";
				};
			};
		};
		//reloadTime = 1.11;
		reloadTime = 0.5;
		dispersion = 5e-005;
		autofire = 1;
		
		//AI Range
		minRange = 2;
		minRangeProbab = 0.2;
		midRange = 75;
		midRangeProbab = 0.35;
		maxRange = 200;
		maxRangeProbab = 0.45;
		
		
		distanceZoomMin = 60;
		distanceZoomMax = 60;
		
		recoil = "recoil_single_ksg";
		recoilProne = "recoil_single_prone_ksg";
		
		ace_barrelTwist = 177.8;
		ace_barrelLength = 607;
		ace_overheating_mrbs = 999999;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_arsenal_hide = 1;
		ace_twistDirection = 0;
	};
};