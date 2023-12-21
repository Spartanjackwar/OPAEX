class OPAEX_D20_A_M45BananaGod: OPTRE_8Gauge_HEDP
{
	//Stats
	hit = 100;
	indirectHit = 100;
	indirectHitRange = 4;
	warheadName = "HE";	
	explosive = 0.6;
	//caliber = 56.6667;
	caliber = 2;
	aiAmmoUsageFlags = "32 + 64 + 128 + 256 + 512";
	fuseDistance = 0;
	
	submunitionAmmo = "B_12Gauge_Pellets_Submunition_Deploy";
	submunitionConeType[] = {"random", 10};
	submunitionConeAngle = 3;
	
	//Effects
	explosionEffects = "VehicleExplosionEffectsBig";
	class CamShakeExplode
	{
		power = 7.74597;
		duration = 1.6;
		frequency = 20;
		distance = 23.2379;
	};
	class CamShakeHit
	{
		power = 60;
		duration = 0.6;
		frequency = 20;
		distance = 1;
	};
	class CamShakeFire
	{
		power = 2.51487;
		duration = 1.2;
		frequency = 20;
		distance = 50.5964;
	};
	class CamShakePlayerFire
	{
		power = 0.01;
		duration = 0.1;
		frequency = 20;
		distance = 1;
	};
};