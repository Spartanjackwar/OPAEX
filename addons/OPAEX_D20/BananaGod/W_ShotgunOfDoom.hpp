class OPAEX_D20_W_M45BananaGod: OPTRE_M45 {
	author = "spartanjackwar";
	scope = 1;
	displayName = "M45Ban BananaGod Shotgun";
	descriptionShort = "BananaGod Shotgun";
	magazines[] = {"OPAEX_D20_M45BananaGod_6666Rnd"};
	magazineWell[] = {};
	
	modes[] = {"Single"};
	class Single: Single {
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
		
		class WeaponSlotsInfo: WeaponSlotsInfo {
 			class MuzzleSlot: MuzzleSlot {
				compatibleitems[]+= {
					"OPTRE_M7_Sight"
				};
			};
 		};
		
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

class OPAEX_D20_W_M45BananaGod_Optic: OPAEX_D20_W_M45BananaGod {
	class LinkedItems {
		class LinkedItemsOptic {
			slot = "CowsSlot";
			item = "OPTRE_M7_Sight";
		};
	};
};