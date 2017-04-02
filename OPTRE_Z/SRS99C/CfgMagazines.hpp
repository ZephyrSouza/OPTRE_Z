class CfgMagazines {

	class 5Rnd_127x108_Mag; /*external*/ 
	
	class SRS_4Rnd_127x108_B_Stanag : 5Rnd_127x108_Mag {
		ammo = "SRS_127x108_Ball";
		count = 4;
		descriptionshort = "Caliber: 12.7x108<br />Rounds: 4<br />Used in: SRS99C";
		displayname = "12.7x108 SRS99C Magazine";
		initspeed = 930;
		lastroundstracer = 0;
		picture = "\SRS99C\UI\gear_srs99c_Mag_x_CA";
		model = "SRS99C\SR99C_Mag";
		scope = 2;
		tracersevery = 0;
	};
	
	class SRS_4Rnd_127x108_T_Stanag : SRS_4Rnd_127x108_B_Stanag {
		ammo = "SRS_127x108_Tracer";
		descriptionshort = "Caliber: 12.7x108<br />Rounds: 4<br />Used in: SRS99C";
		displayname = "12.7x108 SRS99C Magazine (Tracer)";
		lastroundstracer = 0;
		scope = 2;
		tracersevery = 1;
	};
		class SRS_4Rnd_127x108_APDS : SRS_4Rnd_127x108_B_Stanag {
		ammo = "SRS_4Rnd_127x108_APDS";
		descriptionshort = "Caliber: 12.7x108<br />Rounds: 4<br />Used in: SRS99C";
		displayname = "12.7x108 SRS99C Magazine APDS";
		lastroundstracer = 0;
		scope = 2;
		tracersevery = 1;
	};
		class SRS_4Rnd_127x108_HVAP : SRS_4Rnd_127x108_B_Stanag {
		ammo = "SRS_4Rnd_127x108_HVAP";
		descriptionshort = "Caliber: 12.7x108<br />Rounds: 4<br />Used in: SRS99C";
		displayname = "12.7x108 SRS99C Magazine HVAP";
		lastroundstracer = 0;
		scope = 2;
		tracersevery = 1;
	};
			class SRS_4Rnd_127x108_HEDP : SRS_4Rnd_127x108_B_Stanag {
		ammo = "SRS_4Rnd_127x108_HEDP";
		descriptionshort = "Caliber: 12.7x108<br />Rounds: 4<br />Used in: SRS99C";
		displayname = "12.7x108 SRS99C Magazine HEDP";
		lastroundstracer = 0;
		scope = 2;
		tracersevery = 1;
	};
	
};