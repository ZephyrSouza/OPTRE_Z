class CfgAmmo {

	class B_762x51_Ball; /*external*/
	
	class OPTREZ_B_762x51_Ball: B_762x51_Ball
	{
		hit 							= 10;
		typicalSpeed 					= 600;
		model 							= "\A3\Weapons_f\Data\bullettracer\tracer_red";
	};
	class OPTREZ_B_762x51_Tracer: OPTREZ_B_762x51_Ball
	{
		model 							= "\A3\Weapons_f\Data\bullettracer\tracer_red";
	};
	
};		