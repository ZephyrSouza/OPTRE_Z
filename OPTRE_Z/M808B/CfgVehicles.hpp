/*	Vehicle classes	*/
class CfgVehicles {
	/*	A3 DEFAULT INHERITANCE TREE START */
	// Do not modify the inheritance tree, unless you want to alter game's internal configs, or REALLY know what you're doing.
	class LandVehicle;
	class Tank: LandVehicle {
		class NewTurret;
		class Sounds;
		class HitPoints;
	};
	class Tank_F: Tank {
		class Turrets {
			class MainTurret:NewTurret {
				class Turrets {
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints {
			class HitHull;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds {
			class Engine;
			class Movement;
		};
		class CargoTurret;
	};
	/*	A3 DEFAULT INHERITANCE TREE END	*/

	/*	Base class	*/
	// Include as many unique defines and classes common for all your vehicle classes as possible.
	class OPTRE_M808B_base: Tank_F {
		// Basic defines: vehicle class in editor, name displayed, knowledge required to recognize this type of target
		vehicleClass = "Armored";
		accuracy = 0.3;
		

		


		// Model and look defines: paths to model, squad picture and map icon
		model = "M808B\M808B.p3d";
		picture =	"\M808B\data\UI\M808B_MBT_ca.paa";
		icon	=	"\M808B\data\UI\map_M808B_ca.paa";

		#include "physx.hpp"
		#include "pip.hpp" //Egen

		// AI references
		cost	=2500000;
		damageResistance = 0.02;
		crewVulnerable = true;

		// Damage setup
		armor = 700;
		armorLights=1.0;
		armorStructural = 6;	// Two hulls of same type should take same amount of damage. Use armorStructural to counter the effect of vehicle size on its armor.

		//	Weak spots parameters
			// 	name: selection in HitPoints LOD - create selections first!
			// 	radius: radius of weak spot spheres generated around vertices in HitPoints LOD, tweak before armor
			// 	armor: multiplier of total vehicle armor required to destroy given component, tweak after radius
			// 	explosionShielding: multiplier of damage caused by explosive rounds, tweak after armor
			//	minimalHit: minimum hit required to receive damage, tweak after explosionSielding
			// 	passThrough: how much damage is passed to total vehicle damage
			// 	visual: section in Resource LODs and CfgModels section of model.cfg
			// 	material: unneeded, leave at -1

			// The values are sample. Every vehicle needs to be finetuned separately.
		class HitPoints: HitPoints {
			class HitHull: HitHull {	// Handle internal damage
				armor=0.6; //0.8
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit = 0.14;
				explosionShielding = 2.0;
				radius = 0.25;
			};
		/*	class HitEngine: HitEngine {
				armor=1;
				material=-1;
				name="motor";
				passThrough=0.8;
				minimalHit = 0.24;
				explosionShielding = 1;
				radius = 0.33;
			}; */
			class HitLTrack: HitLTrack {
				armor=0.5;
				material=-1;
				name="pas_L";
				passThrough=0;
				minimalHit = 0.08;
				explosionShielding = 1.44;
				radius = 0.3;
			};
			class HitRTrack: HitRTrack {
				armor=0.5;
				material=-1;
				name="pas_P";
				passThrough=0;
				minimalHit = 0.08;
				explosionShielding = 1.44;
				radius = 0.3;
			};
		}; 
		
		//Driver
		forceHideDriver = 1; // Disables turnout
		driverForceOptics = 0;
		driverAction = "Driver_OPTRE_M808B";
		driverInAction = "Driver_OPTRE_M808B";
		viewdriverInExternal = 1;
		getInAction 		= GetInLow; 
		getOutAction 		= GetOutLow; 
		
		
		
		//Cargo
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		cargoCanEject = 1;
	//	cargoAction[] = {"Cargo_1_OPTRE_M808B","Cargo_2_OPTRE_M808B"};
		hideWeaponsCargo = 0;
		castCargoShadow = true;
		
		
		class Turrets: Turrets {
			
			//Cargo Turrets
			class CargoTurret1: CargoTurret{
				gunnerAction 				= "passenger_inside_3";			/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "Compartment2";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo1";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo1 dir";			/// direction of get in action
				memoryPointGunnerOptics 	= "gunnerview";
				gunnerName 					= "Passenger Gunner 1";		/// name of the position in the Action menu
				proxyIndex 					= 1;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -25;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 45;					/// what is the left-most possible turn of the turret
				minTurn 					= -45;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 2;					/// enables firing from vehicle functionality // is for in and out (change to out only later)
				ejectDeadGunner 			= 0;					/// seatbelts included	
				gunnerInAction				= "passenger_inside_3";	///Your sitting animation inside cargo(can be a FFV animation)
				startEngine = 0;
				allowLauncherIn = 1;
				allowLauncherOut = 1; // Only want out but in also for now
			};

			class CargoTurret2: CargoTurret1{
				gunnerCompartments 			= "Compartment2";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo2";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo2 dir";			/// direction of get in action
				gunnerName 					= "Passenger Gunner 2";		/// name of the position in the Action menu
				proxyIndex 					= 2;						/// what cargo proxy is used according to index in the model
			}; 
			
			class CargoTurret3: CargoTurret1
			{
				proxyIndex 					= 3;
				gunnerName 					= "Passenger Gunner 3";
				gunnerCompartments 			= "Compartment3";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo3";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo3 dir";	
			};
			class CargoTurret4: CargoTurret1
			{
				proxyIndex 					= 4;
				gunnerName 					= "Passenger Gunner 4";
				gunnerCompartments 			= "Compartment3";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo4";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo4 dir";	
			};
			class CargoTurret5: CargoTurret1
			{
				proxyIndex 					= 5;
				gunnerName 					= "Passenger Gunner 5";
				gunnerCompartments 			= "Compartment4";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo5";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo6 dir";	
			};
			class CargoTurret6: CargoTurret1
			{
				proxyIndex 					= 6;
				gunnerName 					= "Passenger Gunner 6";
				gunnerCompartments 			= "Compartment4";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo6";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo6 dir";	
			};
			class CargoTurret7: CargoTurret1
			{
				proxyIndex 					= 7;
				gunnerName 					= "Passenger Gunner 7";
				gunnerCompartments 			= "Compartment5";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo7";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo7 dir";	
			};
			class CargoTurret8: CargoTurret1
			{
				proxyIndex 					= 8;
				gunnerName 					= "Passenger Gunner 8";
				gunnerCompartments 			= "Compartment5";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo8";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo8 dir";	
			};
		
		
			class MainTurret: MainTurret {
			class Turrets {};
			
				// Coaxial gun
				memoryPointGun = "usti hlavne2";
				selectionFireAnim = "zasleh2"; //vet ej
				
				// Turret rotation speed
				maxVerticalRotSpeed=90/45;
				maxHorizontalRotSpeed = 90/45;
				
				// Main gun
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";

				// Weapons and magazines					//Ändra
				weapons[]={OPTRE_M512_90mm,OPTRE_M247T_Coax};
				magazines[]={OPTRE_60Rnd_90mm_TUNGSTEN_APBC, OPTRE_60Rnd_90mm_S1_Canister, 2000Rnd_762x51_Belt_Green};

				// Turret servos						
				minElev=-6;
				maxElev=+24;
				initElev=0;
				soundServo[]= {"A3\Sounds_F\vehicles\armor\noises\servo_best", db-40, 1.0,50};
				

				// FCS	
				turretInfoType = "RscWeaponRangeZeroing";
				discreteDistance[] = {
					100,200,300,400,500,600,700,800,
					900,1000,1100,1200,1300,1400,1500,1600,
					1700,1800,1900,2000,2100,2200,2300,2400
				};
				discreteDistanceInitIndex = 5;	// start at 600 meters

				// Optics view
				memoryPointGunnerOptics= "gunnerview";				
				gunnerOutOpticsModel = "";
				gunnerOutOpticsEffect[] = {};
				gunnerOpticsEffect[] = {};

				// Field of view values: 1 = 120°
				class OpticsIn {
					class Wide: ViewOptics {
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=+30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=+100;
						initFov=0.3;
						minFov=0.3;
						maxFov=0.3;
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {2,3}; //green hot chili
						gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_MBT_01_m_F.p3d";				//"\A3\Weapons_F\Reticle\Optics_Gunner_MTB_02_w_F.p3d";
						gunnerOpticsEffect[] = {};
					};
					class Medium: Wide {
						gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_MBT_01_m_F.p3d";
						initFov=0.07;
						minFov=0.07;
						maxFov=0.07;
					};
					class Narrow: Wide {
						gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_MBT_01_m_F.p3d";
						initFov=0.028;
						minFov=0.028;
						maxFov=0.028;
					};
				};

				// Gunner operations and animations
				gunnerAction = "Driver_OPTRE_M808B";
				gunnerInAction = "Driver_OPTRE_M808B";
				gunnerGetInAction = "GetInAMV_cargo";
				gunnerGetOutAction = "GetOutLow";
				castGunnerShadow = 0;
				stabilizedInAxes = 3;
			//	inGunnerMayFire = 0;	// set to 0 to let gunner look around the internal compartment if modeled
				viewGunnerInExternal = 1; // Needed to make gunner possible to be killed with penetrating rounds.
				forceHideGunner = 1; // Disables turnout
				gunnerForceOptics = 0;
			//	isPersonTurret = 0;
				usepip=1;
				
//Dessa kan behöva fixas så att "name" är rätt
				class HitPoints {
					class HitTurret	{
						armor = 0.8;
						material = -1;
						name = "otocVez";
						visual="vez";
						passThrough = 0;
						minimalHit = 0.02;
						explosionShielding = 0.3;
						radius = 0.25;
					};
					class HitGun	{
						armor = 0.8;
						material = -1;
						name = "otocHlaven";          //name = "zbran";
						visual="Hlaven";
						passThrough = 0;
						minimalHit = 0;
						explosionShielding = 1;
						radius = 0.25;
					};
				};				
			};
		};
		/* RETEXTURABILITY	*/
			hiddenSelections[] ={"Camo1","Camo2","Camo3","Camo4","Camo5","Camo6"};
			hiddenSelectionsTextures[] = {"m808b\data\body_co.paa","m808b\data\decals_ca.paa","m808b\data\interior_co.paa","m808b\data\miscparts_co.paa","m808b\data\trackhousing_co.paa","m808b\data\turret_co.paa"};


		class AnimationSources : AnimationSources
		{
			class muzzle_rot_cannon {source = "ammorandom"; weapon = "OPTRE_M512_90mm";};
			class muzzle_rot_coax {source = "ammorandom"; weapon = "OPTRE_M247T_Coax";};
			class muzzle_rot_HMG {source = "ammorandom"; weapon = "HMG_NSVT";};    //kolla vad som ska med
			class recoil_source {source = "reload"; weapon = "OPTRE_M512_90mm";};
		};

		// Damage textures - for sections: zbytek, vez, zbran, vezVelitele, zbranVelitele,
	class Damage {
			tex[] = {};
			mat[] = {
				"M808B\data\M808B_Body.rvmat",
				"M808B\data\M808B_Body_damage.rvmat",
				"M808B\data\M808B_Body_destruct.rvmat",

				"M808B\data\M808B_Interior.rvmat",
				"M808B\data\M808B_Interior_damage.rvmat",
				"M808B\data\M808B_Interior_destruct.rvmat",

				"M808B\data\M808B_MiscParts.rvmat",
				"M808B\data\M808B_MiscParts_damage.rvmat",
				"M808B\data\M808B_MiscParts_destruct.rvmat",

				"M808B\data\M808B_TrackHousing.rvmat",
				"M808B\data\M808B_TrackHousing_damage.rvmat",
				"M808B\data\M808B_TrackHousing_destruct.rvmat",

				"M808B\data\M808B_Tracks.rvmat",
				"M808B\data\M808B_Tracks_damage.rvmat",
				"M808B\data\M808B_Tracks_destruct.rvmat",
				
				"M808B\data\M808B_Turret.rvmat",
				"M808B\data\M808B_Turret_damage.rvmat",
				"M808B\data\M808B_Turret_destruct.rvmat"
			};
		}; 
/*
		smokeLauncherGrenadeCount = 8; //Number of smoke shells launched at once
		smokeLauncherVelocity = 14; //Velocity which smoke shells are launched at
		smokeLauncherOnTurret = 1; //0 if smoke launchers are on hull, 1 if on turret
		smokeLauncherAngle = 120; //Angle within which smoke grenades are launched (actual spacing may end up smaller so use slighty higher number)
*/

		class ViewOptics: ViewOptics {
			visionMode[] = {"Normal","NVG"};
		};

		class Exhausts {
			class Exhaust1 {
				position = "exhaust_1";
				direction = "exhaust_1_dir";
				effect = "ExhaustsEffectBig";
			};
			class Exhaust2 {
				position = "exhaust_2";
				direction = "exhaust_2_dir";
				effect = "ExhaustsEffectBig";
			};
		};

		class Reflectors {
			class Left {
				color[] 	= {1900, 1300, 950};
				ambient[]	= {5,5,5};
				position 	= "Light_L";
				direction 	= "Light_L_end";
				hitpoint 	= "Light_L";
				selection	= "Light_L";
				size 		= 1;
				innerAngle 	= 100;
				outerAngle 	= 179;
				coneFadeCoef = 10;
				intensity 	= 1; //17.5
				useFlare 	= 0;
				dayLight 	= 0;
				flareSize 	= 1.0;
				class Attenuation {
					start 		= 1.0;
					constant 	= 0;
					linear 		= 0;
					quadratic 	= 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			class Right: Left {
				position 	= "Light_R";
				direction 	= "Light_R_end";
				hitpoint 	= "Light_R";
				selection 	= "Light_R";
			};
			class Right2: Right {
				position 	= "light_R_flare";
				useFlare 	= 1;
			};
			class Left2: Left {
				position 	= "light_L_flare";
				useFlare 	= 1;
			};
		};
		aggregateReflectors[] = {{"Left","Right","Left2","Right2"}};
		
		class Sounds
		{
			class Idle_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_ext_rpm1",0.794328,1,200};
				frequency = "0.95 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_ext_rpm2",0.891251,1,240};
				frequency = "0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_ext_rpm3",1.12202,1,280};
				frequency = "0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_ext_rpm4",1.25893,1,320};
				frequency = "0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_ext_rpm5",1.41254,1,360};
				frequency = "0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_ext_rpm6",1.58489,1,400};
				frequency = "0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume = "engineOn*camPos*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_ext_rpm7",1.77828,1,440};
				frequency = "0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume = "engineOn*camPos*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm1",1.12202,1,200};
				frequency = "0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm2",1.41254,1,200};
				frequency = "0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm3",1.77828,1,230};
				frequency = "0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm4",1.99526,1,290};
				frequency = "0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm5",1.77828,1,350};
				frequency = "0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm6",2.23872,1,400};
				frequency = "0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm7",2.51189,1,450};
				frequency = "0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class Idle_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_int_rpm1",0.501187,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_int_rpm2",0.354813,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_int_rpm3",0.398107,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_int_rpm4",0.446684,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_int_rpm5",0.501187,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_int_rpm6",0.562341,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_engine_int_rpm7",0.630957,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm1",0.630957,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm2",0.398107,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm3",0.446684,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm4",0.446684,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm5",0.501187,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm6",0.562341,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm7",0.630957,1};
				frequency = "0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class NoiseInt
			{
				sound[] = {"A3\sounds_f\vehicles\armor\noises\noise_tank_int_1",0.501187,1};
				frequency = "1";
				volume = "(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class NoiseExt
			{
				sound[] = {"A3\sounds_f\vehicles\armor\noises\noise_tank_ext_1",0.891251,1,50};
				frequency = "1";
				volume = "camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_hard_01",0.398107,1,140};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutH1
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_hard_02",0.446684,1,160};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutH2
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_hard_03",0.501187,1,180};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutH3
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_hard_04",0.562341,1,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutH4
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_hard_05",0.562341,1,220};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsOutS0
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_soft_01",0.316228,1,120};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutS1
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_soft_02",0.354813,1,140};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutS2
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_soft_03",0.398107,1,160};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutS3
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_soft_04",0.446684,1,180};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutS4
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_ext_treads_soft_05",0.501187,1,200};
				frequency = "1";
				volume = "engineOn*(camPos)*(grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInH0
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_hard_01",0.251189,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInH1
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_hard_02",0.281838,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInH2
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_hard_03",0.316228,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInH3
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_hard_04",0.354813,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInH4
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_hard_05",0.398107,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInS0
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_soft_01",0.316228,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInS1
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_soft_02",0.316228,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInS2
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_soft_03",0.354813,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInS3
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_soft_04",0.354813,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInS4
			{
				sound[] = {"A3\sounds_f\vehicles\armor\treads\v2_int_treads_soft_05",0.398107,1};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
		};

		soundGetIn[] = {"A3\sounds_f\vehicles\armor\noises\get_in_out",0.562341,1};
		soundGetOut[] = {"A3\sounds_f\vehicles\armor\noises\get_in_out",0.562341,1,20};
		soundDammage[] = {"",0.562341,1};
		buildCrash0[] = {"A3\sounds_f\Vehicles\crashes\crash_08",1,1,200};
		buildCrash1[] = {"A3\sounds_f\Vehicles\crashes\crash_09",1,1,200};
		buildCrash2[] = {"A3\sounds_f\Vehicles\crashes\crash_10",1,1,200};
		buildCrash3[] = {"A3\sounds_f\Vehicles\crashes\crash_11",1,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"A3\sounds_f\Vehicles\crashes\crash_08",1,1,200};
		WoodCrash1[] = {"A3\sounds_f\Vehicles\crashes\crash_09",1,1,200};
		WoodCrash2[] = {"A3\sounds_f\Vehicles\crashes\crash_10",1,1,200};
		WoodCrash3[] = {"A3\sounds_f\Vehicles\crashes\crash_11",1,1,200};
		WoodCrash4[] = {"A3\sounds_f\Vehicles\crashes\crash_01",1,1,200};
		WoodCrash5[] = {"A3\sounds_f\Vehicles\crashes\crash_08",1,1,200};
		soundWoodCrash[] = {"woodCrash0",0.166,"woodCrash1",0.166,"woodCrash2",0.166,"woodCrash3",0.166,"woodCrash4",0.166,"woodCrash5",0.166};
		ArmorCrash0[] = {"A3\sounds_f\Vehicles\crashes\crash_08",1,1,200};
		ArmorCrash1[] = {"A3\sounds_f\Vehicles\crashes\crash_09",1,1,200};
		ArmorCrash2[] = {"A3\sounds_f\Vehicles\crashes\crash_10",1,1,200};
		ArmorCrash3[] = {"A3\sounds_f\Vehicles\crashes\crash_11",1,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		
		
		
		
		memoryPointTrackFLL = "tyretrack_1_1_l"; //Track markers on ground
		memoryPointTrackFLR = "tyretrack_1_1_r";
		memoryPointTrackBLL = "tyretrack_1_2_l";
		memoryPointTrackBLR = "tyretrack_1_2_r";
		memoryPointTrackFRL = "tyretrack_2_1_l";
		memoryPointTrackFRR = "tyretrack_2_1_r";
		memoryPointTrackBRL = "tyretrack_2_2_l";
		memoryPointTrackBRR = "tyretrack_2_2_r";









		//};

	/*	Faction variants	*/

			// Basic defines:knowledge required to recognize this type of target
		// Faction defines: side ID, faction class, crew, typical cargo



		// 2 means available from Zeus, whereas 0 means hidden
		// Editor displayname	// accuracy > 4 is not possible to be fully recognized during game	// due to above will show only in editor
};
	class OPTRE_M808B_UNSC: OPTRE_M808B_Base
	{
		dlc = "OPTRE";
		crew = "OPTRE_UNSC_Army_Soldier_Crewman_ARI";
		scope = 2;
		scopeCurator = 2;
		side = 1;
		faction = "OPTRE_UNSC";
		displayName = "M808B Scorpion";
		
	};
	
};