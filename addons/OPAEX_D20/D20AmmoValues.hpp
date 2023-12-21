author = "Spartanjackwar";

//Ensure no grenade damage
hit = 0;
indirectHit = 0;
explosive = 0;

//Ensure ACE, if enabled, does not attempt to make this grenade lethal.
ace_frag_enabled = 0;
ace_frag_metal = 0;
ace_frag_charge = 0;
ace_frag_force = 0;

//Visuals
model = "\A3\Weapons_f\ammo\Handgrenade_throw"; //TODO: make an actual D20 maybe?
CraterEffects = "NoCrater";
//explosionEffects = "OPAEX_D20ExplosionEffect";
explosionEffects = "";
explosionSoundEffect = "";
SoundSetExplosion[] = {"", 1.0, 1, 2000};
soundHit1[] = {"", 0.85, 1, 1900};