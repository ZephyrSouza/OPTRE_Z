class CfgAmmo {

	class B_127x99_Ball; /*external*/
	
	class TB_556x45_Ball : B_127x99_Ball {
	};
	
	class TB_556x45_Tracer : B_127x99_Ball {
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
		tracerendtime = 1.4;
		tracerscale = 1;
		tracerstarttime = 0.06;
	};
	
};		