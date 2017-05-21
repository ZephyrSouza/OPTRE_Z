class CfgAmmo {
	/*external*/ class Sh_105mm_APFSDS_T_Green;
	/*external*/ class Sh_105mm_HEAT_MP_T_Green;

	class OPTRE_Sh_90mm_TUNGSTEN_APBC : Sh_105mm_APFSDS_T_Green {
		airfriction = -0.0021; //-0.0001
		caliber = 24;
		indirecthit = 0;
		indirecthitrange = 0;
		nvgonly = 0;
		

	};
		class OPTRE_Sh_90mm_S1_Canister : Sh_105mm_HEAT_MP_T_Green {
		airfriction = -0.0021;
		caliber = 10;
		nvgonly = 0;
		aiAmmoUsageFlags = "64 + 128"; //used against infantry and light vehicles

	};
	
	
	
};		