class CfgAmmo {
	/*external*/ class M_Air_AA ; //M_Titan_AA_static;


	
class OPTRE_M_ASGM4_AA : M_Air_AA
	{
		// Used by: LAU-65 (Submunition)
		model = "LAU65D_pod\Rocket\ASGM4_missile_fly.p3d";
		initTime = 0.5;
		missileLockCone = 120;
		airFriction = 0.05;
		maxspeed = 600;
		fuseDistance = 50;
		maneuvrability = 15;
		sideAirFriction = 0.1;
		thrust = 385;
		thrustTime = 2.5;
		trackLead = 1;
		trackOversteer = 1;
		airLock = 1;
		irLock = 1;
		
		explosive = 0.6;
		indirectHit = 50;
		indirectHitRange = 7;
		hit = 200;

		
		//ai and usage
		aiAmmoUsageFlags = "128+256+512";
		weaponLockSystem = "2 + 16";
		missileLockMinDistance = 100;
		missileLockMaxDistance = 3000;
		
		

		
	}; 
	
	
	
	

	class OPTRE_M_ASGM4_AA_Lau_Base: OPTRE_M_ASGM4_AA
 	{
		// Used by: LAU-65 (Parentammo)
		model = "LAU65D_pod\Rocket\ASGM4_missile.p3d";
		
		

 		submunitionAmmo = "OPTRE_M_ASGM4_AA";
 		submunitionConeType[] = {"poissondisc", 1};
 		submunitionConeAngle = 0;
 		triggerTime = 0.5;
		//missileLockCone = 120;
		simulation = "shotMissile";
		weaponLockSystem = "2 + 16";
		access = 3;
		airFriction = 0;
		animated = 0;
		artilleryCharge = 1;
		artilleryDispersion = 1;
		artilleryLock = 0;
		audibleFire = 16;
		autoSeekTarget = 0;
		caliber = 1;
		//cartridge = "";
		//cmImmunity = 1;
		cost = 1000;
		dangerRadiusBulletClose = -1;
		dangerRadiusHit = -1;
		deflecting = 5;
		deflectionSlowDown = 0.8;
		directionalExplosion = 0;
		explosionAngle = 60;
		explosionForceCoef = 1;
		//explosionTime = 0;
		initTime = 5;
		isCraterOriented = 0;
		laserLock = 0;
		lockSeekRadius = 100;
		lockType = 0;
		maneuvrability = 1;
		manualControl = 0;
		maverickweaponIndexOffset = 0;
		maxControlRange = 350;
		//maxSpeed = 0;
		minDamageForCamShakeHit = 0.55;
		nvLock = 0;
		shadow = 0;
		shootDistraction = -1;
		sideAirFriction = 1;
		simulationStep = 0.05;
		thrust = 0;
		thrustTime = 1.5;
		timeToLive = 180;
		trackLead = 1;
		trackOversteer = 1;
		triggerDistance = 500;
		typicalSpeed = 900;
		underwaterHitRangeCoef = 1;
		visibleFire = 16;
		visibleFireTime = 10;
		waterEffectOffset = 0.45;
		whistleDist = 0;
		whistleOnFire = 0;
		
		
		//airLock = 1;
		//effectsMissile = "missile2";
		//suppressionRadiusBulletClose = -1;
		//suppressionRadiusHit = -1;
		//mineBoundingDist = 3;
		//mineBoundingTime = 3;
		//mineDiveSpeed = 1;
		//mineFloating = -1;
		//mineInconspicuousness = 10;
		//minePlaceDist = 0.5;
		//minimumSafeZone = 0.1;
		//minTimeToLive = 0;
		//irLock = 1;
		//explosive = 1;
		//fuseDistance = 0;
		//hit = 300;
		//indirectHit = 0;
		//indirectHitRange = 8;
		
		
 	};
/*	class OPTRE_M_ASGM4_AA_Lau_Base: R_230mm_HE//SubmunitionBase 
 	{
		model = "LAU65D_pod\Rocket\ASGM4_missile.p3d";
		
		
		
		
 		submunitionAmmo = "OPTRE_M_ASGM4_AA";
 		submunitionConeType[] = {"poissondisc", 1};  
 		submunitionConeAngle = 0;
 		triggerTime = 0.5;
		//maneuvrability = 0.1;
		//sideAirFriction = 0.001;
		//trackLead = 0;
		
		//fuseDistance = 50;
		//initTime = 0.5;
		missileLockCone = 120;
		//thrust = 385;
		//thrustTime = 2.5;
		//maxspeed = 600;
		//trackOversteer = 1;
		airFriction = -0.0005;
		irLock = 1;
		airLock = 1;
		weaponLockSystem = "2 + 16";
		artilleryLock = 0;
		simulation = "shotMissile";
 	}; */
	
};	





