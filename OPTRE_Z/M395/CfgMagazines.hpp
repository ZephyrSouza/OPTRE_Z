class CfgMagazines {

	class 20Rnd_762x51_Mag; /*external*/ 
	
	class OPTREZ_15Rnd_762x51_Mag: 20Rnd_762x51_Mag
	{
		dlc = "OPTRE";
		model								= "\M395\M395_Mag.p3d";
		displayname							= "15Rnd 7.62x51mm Magazine";
		displaynameshort					= "7.62x51mm";
		ammo								= "OPTREZ_B_762x51_Ball";
		count								= 15;
		initspeed							= 900;
		picture 							= "\M395\icons\M395Mag_icon.paa";
		descriptionshort					= "15 Round Magazine<br>7.62x51mm";
		mass								= 10;
		tracersEvery 						= 0;
		lastRoundsTracer 					= 3;
	};
	class OPTREZ_15Rnd_762x51_Mag_Tracer: OPTREZ_15Rnd_762x51_Mag
	{
		dlc = "OPTRE";
		displayname							= "15Rnd 7.62x51mm Magazine (Tracers)";
		displaynameshort					= "7.62x51mm Tracer";
		ammo								= "OPTREZ_B_762x51_Tracer";
		descriptionshort					= "15 Round Magazine<br>7.62x51mm<br>Tracer";
		tracersEvery 						= 1;
		lastRoundsTracer 					= 15;
	};
	
};