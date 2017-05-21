class CfgMagazines 
{
		class Default;

	/*external*/ class 40Rnd_105mm_APFSDS_T_Green;
	/*external*/ class 20Rnd_105mm_HEAT_MP_T_Green;
	
	
	class OPTRE_60Rnd_90mm_TUNGSTEN_APBC : 40Rnd_105mm_APFSDS_T_Green {
		ammo = OPTRE_Sh_90mm_TUNGSTEN_APBC;
		count = 60;
		displayname = "90mm TUNGSTEN APBC";
		displaynameshort = "W-APBC";
		initspeed = 2000;
		lastroundstracer = 0;
		scope = 2;
		tracersevery = 1;
	};

	class OPTRE_60Rnd_90mm_S1_Canister : 20Rnd_105mm_HEAT_MP_T_Green {
		ammo = OPTRE_Sh_90mm_S1_Canister;
		count = 60;
		displayname = "90mm S1 Canister";
		displaynameshort = "Canister";
		initspeed = 2000;
		lastroundstracer = 0;
		scope = 2;
		tracersevery = 1;
		};
		
		
};
