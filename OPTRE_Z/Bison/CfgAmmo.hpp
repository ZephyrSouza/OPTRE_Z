class CfgAmmo {
	/*external*/ class Sh_105mm_APFSDS_T_Green;
	/*external*/ class Sh_120mm_HE_Tracer_Green;

	class OPTRE_Sh_90mm_APBC : Sh_105mm_APFSDS_T_Green {
		caliber = 24;
		hit =  425;
		

	};
		class OPTRE_Sh_90mm_HE : Sh_120mm_HE_Tracer_Green {
		caliber = 10;
		explosive = 0.8;
		inderecthit = 20;
		hit =  600;
		
		aiAmmoUsageFlags = "64 + 128"; //against infantry,light vehicles and air
		allowAgainstInfantry = 1;

	};
	
};		
