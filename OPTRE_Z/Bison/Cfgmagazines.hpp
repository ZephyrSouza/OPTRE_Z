class CfgMagazines 
{
		class Default;

	/*external*/ class 40Rnd_105mm_APFSDS_T_Green;
	/*external*/ class 20Rnd_105mm_HEAT_MP_T_Green;
	
	
	class OPTRE_30Rnd_90mm_APTC : 40Rnd_105mm_APFSDS_T_Green {
		ammo = OPTRE_Sh_90mm_APTC;
		count = 30;
		displayname = "90mm APTC";
		displaynameshort = "APTC";
		tracersevery = 1;
	};

	class OPTRE_30Rnd_90mm_HE : 20Rnd_105mm_HEAT_MP_T_Green {
		ammo = OPTRE_Sh_90mm_HE;
		count = 30;
		displayname = "90mm HE";
		displaynameshort = "HE";
		tracersevery = 1;
		};
		
	class OPTRE_12Rnd_C2GMLS_missiles;
	class OPTRE_2Rnd_C2GMLS_missiles: OPTRE_12Rnd_C2GMLS_missiles
	{
		displayName 						= "2Rnd Class-2 Self-Guided Missiles";
		displayNameShort 					= "2Rnd Class-2 GMLS";
		count = 2;
	};
};
