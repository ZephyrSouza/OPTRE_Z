class CfgAmmo {
	/*external*/ class Sh_105mm_APFSDS_T_Green;
	/*external*/ class Sh_120mm_HE_Tracer_Green;

	class OPTRE_Sh_90mm_APTC : Sh_105mm_APFSDS_T_Green {
		caliber = 17;
		hit =  367;
		

	};
		class OPTRE_Sh_90mm_HE : Sh_120mm_HE_Tracer_Green {
		caliber = 10;
		explosive = 0.8;
		inderecthit = 43;
		hit =  185;
		
		aiAmmoUsageFlags = "64 + 128 + 256"; //used against infantry,light vehicles and air

	};
	
};		