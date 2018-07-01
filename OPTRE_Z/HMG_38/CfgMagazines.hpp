class CfgMagazines {

	class 150Rnd_93x64_Mag; /*external*/ 
	class 1Rnd_HE_Grenade_shell;
	
	class OPTRE_42Rnd_30x06_Mag: 150Rnd_93x64_Mag
	{
		author = "OPTRE";
		scope = 2;
		displayName = "HMG 38 30x06 Magazine";
		picture = "HMG_38\icons\HMG_38_Magazine_Icon.paa";
		count = 42;
		ammo = "OPTRE_B_30x06_Ball";
		initSpeed = 785;
		tracersEvery = 3;
		lastRoundsTracer = 6;
		descriptionshort = "42 <br>30x06<br>";
		mass = 10;
	};
	class OPTRE_42Rnd_30x06_Mag_Tracer: OPTRE_42Rnd_30x06_Mag
	{
		displayname							= "HMG 38 30x06 Magazine (Tracers)";
		displaynameshort					= "30x06mm Tracer";
		ammo								= "OPTRE_B_30x06_Ball_Tracer";
		descriptionshort					= "42 <br>30x06<br> Tracer";
		tracersEvery 						= 1;
		lastRoundsTracer 					= 15;
	};
		class OPTRE_20mm_HE_Grenade_Shell: 1Rnd_HE_Grenade_shell
	{
		author = "OPTRE";
		count = 3;
		displayName = "HMG 3GL 20mm HE";
		ammo = "G_20mm_HE";
		descriptionShort = "HMG 3GL 20mm HE";
		mass = 12;
		initSpeed = 500;
	};
};