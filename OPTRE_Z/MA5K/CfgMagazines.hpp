class CfgMagazines {

	class 30Rnd_556x45_Stanag; /*external*/ 
	
	class MA5K_60Rnd_762x39_B_Stanag : 30Rnd_556x45_Stanag {
		ammo = "MA5K_762x39_Ball";
		count = 60;
		descriptionshort = "Caliber: 12.7x108<br />Rounds: 4<br />Used in: MA5K";
		displayname = "7.62x39 MA5K Magazine";
		initspeed = 930;
		lastroundstracer = 0;
		picture = "\MA5K\UI\Mag_Icon";
		model = "MA5K\MA5K_Mag";
		scope = 2;
		tracersevery = 0;
	};
	
	class MA5K_60Rnd_762x39_T_Stanag : MA5K_60Rnd_762x39_B_Stanag {
		ammo = "MA5K_762x39_Tracer";
		descriptionshort = "Caliber: 12.7x108<br />Rounds: 4<br />Used in: MA5K";
		displayname = "7.62x39 MA5K Magazine (Tracer)";
		lastroundstracer = 0;
		scope = 2;
		tracersevery = 1;
	};
	
};