simulation			= tankX;
enginePower			= 582;
maxOmega 			= 276;
peakTorque 			= 4832;
torqueCurve[] 		= {
	{0, 0},
	{(1600/2640), (2650/2850)},
	{(1800/2640), (2800/2850)},
	{(1900/2640), (2850/2850)},
	{(2000/2640), (2800/2850)},
	{(2200/2640), (2750/2850)},
	{(2400/2640), (2600/2850)},
	{(2640/2640), (2350/2850)}
};
thrustDelay			= 0.1;    	/// how much time does it take to get the full thrust (default 1), used to reduce initial wheel slipping
clutchStrength 		= 180.0;
fuelCapacity		= 1885;
brakeIdleSpeed		= 1.78; 	/// speed in m/s below which braking is applied
latency 			= 0.1;
tankTurnForce		= 600000; /// Random magic number, expected to be something like 11 x mass of vehicle

/// Gearbox and transmission
idleRpm = 700; // RPM at which the engine idles.
redRpm = 2640; // RPM at which the engine redlines.

engineLosses = 25; // power losses on the engine's crank-shaft (before the gearbox) in Nm. (Multiplied by the gear ratio)
transmissionLosses = 15; // power losses on wheel axis (in/after the gearbox) in Nm. (Constant)

class complexGearbox {
	GearboxRatios[]    = {"R2",-3.9,"N",0,"D1",4.7,"D2",3.5,"D3",2.6,"D4",2.0,"D5",1.5,"D6",1.125,"D7",0.85};
	TransmissionRatios[] = {"High",15};
	gearBoxMode        = "full-auto"; //gearbox can be of type: full-auto (only requires 'W' or 'S'), auto (requires shift between drive and reverse), semi-auto, manual
	moveOffGear        = 1; // defines what gear an automatic or semi-automatic gearbox will move off from stationary in. 1 by default.
	driveString        = "D"; // string to display in the HUD for forward gears.
	neutralString      = "N"; // string to display in the HUD for neutral gear.
	reverseString      = "R"; // string to display in the HUD for reverse gears.
	transmissionDelay  = 0.1;
};
/// end of gearbox

class Wheels {
	class L2 {
		boneName = "wheel_fl_2";
		center   = "wheel_fl_2_axis";
		boundary = "wheel_fl_2_bound";
		damping  = 75.0;
		steering = 0;
		side = "left";
		weight = 150;
		mass = 150;
		MOI = 25;
		latStiffX = 25;
		latStiffY = 280;
		longitudinalStiffnessPerUnitGravity = 100000;
		maxBrakeTorque = 40000;
		sprungMass = 4000.0;
		springStrength = 324000;
		springDamperRate = 36000;
		dampingRate = 1.0;
		dampingRateInAir = 8830.0;
		dampingRateDamaged = 10.0;
		dampingRateDestroyed = 10000.0;
		maxDroop = 0.15;
		maxCompression = 0.15;
	};
	class L3: L2 {
		boneName = "wheel_fl_3";
		center   = "wheel_fl_3_axis";
		boundary = "wheel_fl_3_bound";
	};
	class L4: L2 {
		boneName = "wheel_fl_4";
		center   = "wheel_fl_4_axis";
		boundary = "wheel_fl_4_bound";
	};
	class L5: L2 {
		boneName = "wheel_fl_5";
		center   = "wheel_fl_5_axis";
		boundary = "wheel_fl_5_bound";
	};
	class L6: L2 {
		boneName = "wheel_fl_6";
		center   = "wheel_fl_6_axis";
		boundary = "wheel_fl_6_bound";
	};
	class L7: L2 {
		boneName = "wheel_fl_7";
		center   = "wheel_fl_7_axis";
		boundary = "wheel_fl_7_bound";
	};
	class L10: L2 {
		boneName = "wheel_rl_2";
		center   = "wheel_rl_2_axis";
		boundary = "wheel_rl_2_bound";
	};
	class L11: L2 {
		boneName = "wheel_rl_3";
		center   = "wheel_rl_3_axis";
		boundary = "wheel_rl_3_bound";
	};
	class L12: L2 {
		boneName = "wheel_rl_4";
		center   = "wheel_rl_4_axis";
		boundary = "wheel_rl_4_bound";
	};
	class L13: L2 {
		boneName = "wheel_rl_5";
		center   = "wheel_rl_5_axis";
		boundary = "wheel_rl_5_bound";
	};
	class L1: L2 {
		boneName = "wheel_fl_1";
		center   = "wheel_fl_1_axis";
		boundary = "wheel_fl_1_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
	class L8: L2 {
		boneName = "wheel_fl_8";
		center   = "wheel_fl_8_axis";
		boundary = "wheel_fl_8_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
	class L9: L2 {
		boneName = "wheel_rl_1";
		center   = "wheel_rl_1_axis";
		boundary = "wheel_rl_1_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
	class L14: L2 {
		boneName = "wheel_rl_6";
		center   = "wheel_rl_6_axis";
		boundary = "wheel_rl_6_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};

	class R2 {
		boneName = "wheel_fr_2";
		center   = "wheel_fr_2_axis";
		boundary = "wheel_fr_2_bound";
		damping  = 75.0;
		steering = 0;
		side = "right";
		weight = 150;
		mass = 150;
		MOI = 25;
		latStiffX = 25;
		latStiffY = 280;
		longitudinalStiffnessPerUnitGravity = 100000;
		maxBrakeTorque = 40000;
		sprungMass = 4000.0;
		springStrength = 324000;
		springDamperRate = 36000;
		dampingRate = 1.0;
		dampingRateInAir = 8830.0;
		dampingRateDamaged = 10.0;
		dampingRateDestroyed = 10000.0;
		maxDroop = 0.15;
		maxCompression = 0.15;
	};
	class R3: R2 {
		boneName = "wheel_fr_3";
		center   = "wheel_fr_3_axis";
		boundary = "wheel_fr_3_bound";
	};
	class R4: R2 {
		boneName = "wheel_fr_4";
		center   = "wheel_fr_4_axis";
		boundary = "wheel_fr_4_bound";
	};
	class R5: R2 {
		boneName = "wheel_fr_5";
		center   = "wheel_fr_5_axis";
		boundary = "wheel_fr_5_bound";
	};
	class R6: R2 {
		boneName = "wheel_fr_6";
		center   = "wheel_fr_6_axis";
		boundary = "wheel_fr_6_bound";
	};
	class R7: R2 {
		boneName = "wheel_fr_7";
		center   = "wheel_fr_7_axis";
		boundary = "wheel_fr_7_bound";
	};
	class R10: R2 {
		boneName = "wheel_rr_2";
		center   = "wheel_rr_2_axis";
		boundary = "wheel_rr_2_bound";
	};
	class R11: R2 {
		boneName = "wheel_rr_3";
		center   = "wheel_rr_3_axis";
		boundary = "wheel_rr_3_bound";
	};
	class R12: R2 {
		boneName = "wheel_rr_4";
		center   = "wheel_rr_4_axis";
		boundary = "wheel_rr_4_bound";
	};
	class R13: R2 {
		boneName = "wheel_rr_5";
		center   = "wheel_rr_5_axis";
		boundary = "wheel_rr_5_bound";
	};
	class R1: R2 {
		boneName = "wheel_fr_1";
		center   = "wheel_fr_1_axis";
		boundary = "wheel_fr_1_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
	class R8: R2 {
		boneName = "wheel_fr_8";
		center   = "wheel_fr_8_axis";
		boundary = "wheel_fr_8_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
	class R9: R2 {
		boneName = "wheel_rr_1";
		center   = "wheel_rr_1_axis";
		boundary = "wheel_rr_1_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
	class R14: R2 {
		boneName = "wheel_rr_6";
		center   = "wheel_rr_6_axis";
		boundary = "wheel_rr_6_bound";
		sprungMass = 1500.0;
		springStrength = 37500;
		springDamperRate = 7500;
		maxDroop = 0;
		maxCompression = 0;
	};
};