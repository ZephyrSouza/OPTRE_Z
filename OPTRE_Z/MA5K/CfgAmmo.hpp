class CfgAmmo {

	class B_762x39_Ball_F; /*external*/
	
	class MA5K_762x39_Ball : B_762x39_Ball_F {
		ACE_bulletMass=4.0176;
	};
	
	class MA5K_762x39_Tracer : B_762x39_ball_F {
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
			ACE_bulletMass=4.0176;
		tracerendtime = 1.4;
		tracerscale = 1;
		tracerstarttime = 0.06;
	};
	
};		