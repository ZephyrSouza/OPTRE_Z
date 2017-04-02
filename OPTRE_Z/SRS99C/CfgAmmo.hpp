class CfgAmmo {

	class B_127x108_Ball; /*external*/
	class B_127x108_APDS; /*external*/
	
	class SRS_127x108_Ball : B_127x108_Ball {
	};
	
	class SRS_127x108_Tracer : B_127x108_Ball {
	};
	class SRS_4Rnd_127x108_APDS : B_127x108_APDS {
		
	};
	class SRS_4Rnd_127x108_HVAP : B_127x108_APDS {
		hit 							= 75;
		//caliber 						= 15;
		//typicalSpeed 					= 700;		
	};
	class SRS_4Rnd_127x108_HEDP : B_127x108_APDS {
		hit 							= 50;
		indirectHit 					= 20;
		explosive 						= 0.75;
		indirectHitRange 				= 1;
		//caliber 						= 0.1;
		//typicalSpeed 					= 700;
		//timeToLive 						= 15;
		model 							= "\A3\Weapons_f\Data\bullettracer\tracer_red";
		tracerScale 					= 2;	
		explosionEffects 				= "ExploAmmoExplosion";
		craterEffects 					= "ExploAmmoCrater";
		explosionSoundEffect 			= "DefaultExplosion";
	};
	
};		