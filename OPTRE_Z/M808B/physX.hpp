/// PhysX part
numberPhysicalWheels = 20;
wheelCircumference = 2.23361;
simulation	= tankX;
normalSpeedForwardCoef=0.6;
slowSpeedForwardCoef=0.45;
terrainCoef = 8.0; // Higher slows speed on terrain
maxSpeed = 52;

// Tank Water Ford config
maxFordingDepth = 0;
waterResistance = 0;
waterDamageEngine = 0.2;
waterLeakiness = 10;

		enginePower = 1121;
		maxOmega = 554.16; //314.16;
		peakTorque = 7855; //5355;
		torqueCurve[] = {{"(0/8000)","(2300/2300)"},{"(1143/8000)","(2300/2300)"},{"(2286/8000)","(2300/2300)"},{"(3429/8000)","(2300/2300)"},{"(4572/8000)","(2300/2300)"},{"(5715/8000)","(2300/2300)"},{"(6858/8000)","(2300/2300)"},{"(8000/8000)","(2300/2300)"}};
		thrustDelay = 0.0; // kanske vill ändra
		clutchStrength = 50.0;
		
		idleRPM = 850;
		redRPM = 3000;


//thrustDelay			= 0.0;    	/// how much time does it take to get the full thrust (default 1), used to reduce initial wheel slipping
//clutchStrength 		= 50.0;
fuelCapacity		= 20;
fuelConsumptionRate = 100;
brakeIdleSpeed		= 0.0; 	/// speed in m/s below which braking is applied

tankTurnForce		= 735000; /// Random magic number, expected to be something like 11 x mass of vehicle
antiRollbarForceCoef = 24;
antiRollbarForceLimit = 42;
antiRollbarSpeedMin = 30;
antiRollbarSpeedMax = 75;

engineLosses = 25; // power losses on the engine's crank-shaft (before the gearbox) in Nm. (Multiplied by the gear ratio)
transmissionLosses = 15; // power losses on wheel axis (in/after the gearbox) in Nm. (Constant)

changeGearMinEffectivity[] = {0.5,0.15,0.95,0.95,0.95,0.95,0.95,0.95,0.95,0.95,0.95,0.95,0.9,0.9,0.9,0.9,0.9};
		class complexGearbox
		{
			GearboxRatios[] = {"R1",-0.4,"N",0,"D1",2.0}; //GearboxRatios[] = {"R1",-0.4,"N",0,"D1",2.0};
			TransmissionRatios[] = {"High",7.85};
			gearBoxMode = "auto";
			moveOffGear = 3;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
			transmissionDelay = 0.1;
		};
/// end of gearbox

class Wheels {
	class L2 {
		boneName = "wheel_podkoloL1";
		center   = "wheel_1_2_axis";
		boundary = "wheel_1_2_bound";
		damping  = 75.0;
		// tanks do not have steerable wheels
		steering = 0;
		/// We need to distinguish the side to apply the right thrust value
		side = "left";
		/// weight of the wheel is defined per wheel, it reduces overall mass of vehicle
		weight = 150;
		mass = 150;
		MOI = 11.5;	 //10.74466875;
		latStiffX = 25;
		latStiffY = 200;
		longitudinalStiffnessPerUnitGravity = 100000;
		maxBrakeTorque = 6000; //40000;
		sprungMass = 4125; 
		springStrength = 103125;  
		springDamperRate = 41250;
		dampingRate = 1.0;
		dampingRateInAir = 685;	 //8830.0;
		dampingRateDamaged = 10.0;
		dampingRateDestroyed = 10000.0;
		maxDroop = 0.15;	 //0.15;   glöm ej att ändra offset0,offset1
		maxCompression = 0.15; // 0.15;
		frictionVsSlipGraph[] = {{0.0,1.5},{0.5,1.5},{1,1.5}};
	};
	class L3: L2 {
		boneName = "wheel_podkolol2";
		center   = "wheel_1_3_axis";
		boundary = "wheel_1_3_bound";
	};
	class L4: L2 {
		boneName = "wheel_podkolol3";
		center   = "wheel_1_4_axis";
		boundary = "wheel_1_4_bound";
	};
	class L5: L2 {
		boneName = "wheel_podkolol4";
		center   = "wheel_1_5_axis";
		boundary = "wheel_1_5_bound";
	};
	class L6: L2 {
		boneName = "wheel_podkolol5";
		center   = "wheel_1_8_axis";
		boundary = "wheel_1_8_bound";
	};
	class L7: L2 {
		boneName = "wheel_podkolol6";
		center   = "wheel_1_9_axis";
		boundary = "wheel_1_9_bound";
	};

	class L8: L2 {
		boneName = "wheel_podkolol7";
		center   = "wheel_1_10_axis";
		boundary = "wheel_1_10_bound";
	};
	
	// Middle wheel try for better handling
	class L10: L2 {
		boneName = "wheel_podkolol10"; //Finns inte
		center   = "wheel_1_mid_axis";
		boundary = "wheel_1_mid_bound";	
	};

	// rear left wheel, usually Idler or Drive Sproket
	// Note, this wheel may not always be touching the ground, but we need it anyway!
	class L9: L2 {
		boneName = "wheel_podkolol9"; //Finns inte
		center   = "wheel_1_11_axis";
		boundary = "wheel_1_11_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};

	// front left wheel, usually Idler or Drive Sproket
	// Note, this wheel may not always be touching the ground, but we need it anyway!
	class L1: L2 {
		boneName = "";
		center   = "wheel_1_1_axis";
		boundary = "wheel_1_1_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};

	class R2: L2 {
		boneName = "wheel_podkolop1";
		center   = "wheel_2_2_axis";
		boundary = "wheel_2_2_bound";
		side = "right";
	};
	class R3: R2 {
		boneName = "wheel_podkolop2";
		center   = "wheel_2_3_axis";
		boundary = "wheel_2_3_bound";
	};
	class R4: R2 {
		boneName = "wheel_podkolop3";
		center   = "wheel_2_4_axis";
		boundary = "wheel_2_4_bound";
	};
	class R5: R2 {
		boneName = "wheel_podkolop4";
		center   = "wheel_2_5_axis";
		boundary = "wheel_2_5_bound";
	};
	class R6: R2 {
		boneName = "wheel_podkolop5";
		center   = "wheel_2_8_axis";
		boundary = "wheel_2_8_bound";
	};
	class R7: R2 {
		boneName = "wheel_podkolop6";
		center   = "wheel_2_9_axis";
		boundary = "wheel_2_9_bound";
	};
	class R8: R2 {
		boneName = "wheel_podkolop7";
		center   = "wheel_2_10_axis";
		boundary = "wheel_2_10_bound";
	};
	
	// Middle wheel try for better handling
	class R10: R2 {
		boneName = "wheel_podkolop10"; //Finns inte
		center   = "wheel_2_mid_axis";
		boundary = "wheel_2_mid_bound";	
	};
	
	// rear right wheel, usually Idler or Drive Sproket
	// Note, this wheel may not always be touching the ground, but we need it anyway!
	class R9: R2 {
		boneName = "wheel_podkolop9"; //Finns inte
		center   = "wheel_2_11_axis";
		boundary = "wheel_2_11_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
	// front right wheel, usually Idler or Drive Sproket
	// Note, this wheel may not always be touching the ground, but we need it anyway!
	class R1: R2 {
		boneName = "";
		center   = "wheel_2_1_axis";
		boundary = "wheel_2_1_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
};
/// End of PhysX