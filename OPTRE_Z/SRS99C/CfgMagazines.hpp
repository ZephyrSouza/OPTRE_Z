class CfgMagazines {

	class 30Rnd_556x45_Stanag; /*external*/ 
	
	class tb_30Rnd_556x45_B_Stanag : 30Rnd_556x45_Stanag {
		ammo = "TB_556x45_Ball";
		count = 4;
		descriptionshort = "Caliber: 45 ACP UMP Mag<br />Rounds: 30<br />Used in: HK UMP-45";
		displayname = "45 ACP 30rnd UMP Mag (Ball)";
		initspeed = 930;
		lastroundstracer = 0;
		picture = "\SRS99C\UI\gear_srs99c_Mag_x_CA";
		model = "SRS99C\SR99C_Mag";
		scope = 2;
		tracersevery = 0;
	};
	
	class tb_30Rnd_556x45_T_Stanag : tb_30Rnd_556x45_B_Stanag {
		ammo = "TB_556x45_Tracer";
		descriptionshort = "Caliber: 45 ACP UMP Mag<br />Rounds: 30<br />Used in: HK UMP-45";
		displayname = "45 ACP 30rnd UMP Mag (Tracer)";
		lastroundstracer = 0;
		scope = 2;
		tracersevery = 1;
	};
	
};