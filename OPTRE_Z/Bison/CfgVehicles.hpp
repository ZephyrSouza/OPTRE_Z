class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
class Optics_Commander_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
/*	Vehicle classes	*/
class CfgVehicles {
	/*	A3 DEFAULT INHERITANCE TREE START */
	// Do not modify the inheritance tree, unless you want to alter game's internal configs, or REALLY know what you're doing.

	class Car;
	class Car_F: Car
	{
		class NewTurret;
		class Sounds;
		class HitPoints
		{
			class HitBody;
			class HitEngine;
			class HitFuel;
			class HitLFWheel;
			class HitLBWheel;
			class HitLMWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitRMWheel;
			class HitRF2Wheel;
		};
	};
	class Wheeled_APC_F: Car_F {};
	class APC_Wheeled_01_base_F: Wheeled_APC_F
	{
		class ViewOptics;
		class ViewCargo;
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
		class NewTurret;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
		class EventHandlers;
	};
	
	
	
/****************************** IFV - Bison ******************************/	
	

	class OPTRE_IFV_Bison_base: APC_Wheeled_01_base_F
	{
		dlc = "OPTRE";
		crew = "OPTRE_UNSC_Army_Soldier_Crewman_ARI";
		scope = 2;
		scopeCurator = 2;
		side = 1;
		faction = "OPTRE_UNSC";
		editorSubcategory = "EdSubcat_APCs";
		displayName = "IFV-90 Bison";
		accuracy = 0.25;
		author = "Article 2 Studios";
		
		// Model and look defines: paths to model, squad picture and map icon
		model = "\Bison\IFV_Bison.p3d";
		picture = "\A3\armor_f_beta\APC_Wheeled_01\Data\UI\APC_Wheeled_01_ACRV_ca.paa";
		icon = "\A3\armor_f_beta\APC_Wheeled_01\Data\UI\map_amw_CA.paa";
		
		#include "pip.hpp" //For rendertargets
		#include "physx.hpp"

		// AI references
		armorLights = 0.1;
		crewExplosionProtection = 0.9995;
		damageResistance = 0.00719;

		// Damage setup
		armor = 250;
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
	/*	class HitPoints: HitPoints {
			class HitHull: HitHull {	// Handle internal damage
				armor=0.8;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit = 0.14;
				explosionShielding = 2.0;
				radius = 0.25;
			};
			class HitEngine: HitEngine {
				armor=1;
				material=-1;
				name="motor";
				passThrough=0.8;
				minimalHit = 0.24;
				explosionShielding = 1;
				radius = 0.33;
			};
		}; */
		forceHideDriver = 1; // Disables turnout
		driverForceOptics = 0;
		driverAction = "Driver_OPTRE_Bison";
		driverInAction = "Driver_OPTRE_Bison";
		
		//Cargo
		cargoAction[] = {"passenger_apc_generic02b","passenger_apc_generic04","passenger_apc_generic04","passenger_apc_generic03","passenger_apc_generic03","passenger_apc_generic04","passenger_apc_generic02b","passenger_apc_generic04"};
		castCargoShadow = false;
		castDriverShadow = false;
		castGunnerShadow = false;		
		
		class Turrets: Turrets {
			
			// Cargo Turrets	Not yet used
			/*	class CargoTurret_01: CargoTurret
			{
				gunnerAction = "Gunner_OPTRE_Bison"; //"passenger_inside_2";
				gunnerCompartments = "Compartment1";
				memoryPointsGetInGunner = "pos cargo l";
				memoryPointsGetInGunnerDir = "pos cargo l dir";
				gunnerName = "Cargo Gunner (Left side)";
				proxyIndex = 1;
				maxElev = 15;
				minElev = -25;
				maxTurn = 10;
				minTurn = -50;
				isPersonTurret = 1;
				ejectDeadGunner = 0;
				enabledByAnimationSource = "CargoDoor";
				memoryPointGunnerOptics = "";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerAction = "passenger_inside_2";
				gunnerCompartments = "Compartment1";
				memoryPointsGetInGunner = "pos cargo r";
				memoryPointsGetInGunnerDir = "pos cargo r dir";
				gunnerName = "Cargo Gunner (Right side)";
				proxyIndex = 2;
				maxElev = 15;
				minElev = -25;
				maxTurn = 50;
				minTurn = -10;
				isPersonTurret = 1;
				ejectDeadGunner = 0;
				enabledByAnimationSource = "CargoDoor";
				memoryPointGunnerOptics = "";
			}; */
			
			
			

			class MainTurret: MainTurret {
			class Turrets {};
			
			    body = "mainTurret";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
			
			
				
				// Turret rotation speed
				maxVerticalRotSpeed=1.8;
				maxHorizontalRotSpeed = 1.8;
				
				// Main gun
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";

				// Weapons and magazines					//Ändra
				weapons[]={OPTRE_cannon_90mm,OPTRE_missiles_C2GMLS_2}; //Namn på vapnet ta bort _2
				magazines[]={OPTRE_30Rnd_90mm_APBC,OPTRE_30Rnd_90mm_HE,OPTRE_2Rnd_C2GMLS_missiles};

				// Turret servos						
				minElev=-2;
				maxElev=+20;
				initElev=0;
				soundServo[] = {"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner",0.56234133,1,30};
				soundServoVertical[] = {"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner_vertical",0.56234133,1,30};
				

				// FCS	
				
				turretInfoType = "RscOptics_APC_Wheeled_01_gunner";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex = 2;

				// Optics view
				memoryPointGunnerOptics= "gunnerview";				
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
				gunnerOutOpticsEffect[] = {};
				gunnerOpticsEffect[] = {};
				gunnerForceOptics = 0;
				
				isPersonTurret = 0;
				usepip=1;
				
				
				class ViewOptics: RCWSOptics
				{
					visionMode[] = {"Normal","TI"};
				};
				class OpticsIn: Optics_Gunner_APC_01
				{
					class Wide: Wide{};
					class Medium: Medium{};
					class Narrow: Narrow{};
				};
				
				class ViewGunner: ViewGunner
				{
					//maxAngleY = 60; //test
					//minAngleY = -240; //test
					maxAngleY = -90;
					minAngleY = -90;
					initAngleY = -90;

				};
				
				showCrewAim = 2;
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.4;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0.2;
						minimalHit = 0.1;
						explosionShielding = 0.2;
						radius = 0.25;
					};
					class HitGun
					{
						armor = 0.2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
						minimalHit = 0.1;
						explosionShielding = 0.4;
						radius = 0.25;
					};
				};
				

				// Gunner operations and animations
				gunnerAction = "Gunner_OPTRE_Bison";
				gunnerInAction = "Gunner_OPTRE_Bison";
				gunnerGetInAction = "GetInAMV_cargo";
				gunnerGetOutAction = "GetOutLow";
				castGunnerShadow = 0;
				stabilizedInAxes = 3;
				//inGunnerMayFire = 0;	// set to 0 to let gunner look around the internal compartment if modeled
				viewGunnerInExternal = 1; // Needed to make gunner possible to be killed with penetrating rounds.
				forceHideGunner = 1; // Disables turnout
				
				gunnerHasFlares = 1;
				
		
				

				
			};
		};
		
		

		
		
		
		
		
		
		/* RETEXTURABILITY	*/
		/*
			hiddenSelections[] ={"Camo1","Camo2"};
			hiddenSelectionsTextures[] = {"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_CO.paa","A3\armor_f_gamma\MBT_01\Data\MBT_01_tow_CO.paa"};
		*/


		class AnimationSources: AnimationSources
		{
			class muzzle_rot
			{
				source = "ammorandom";
				weapon = "OPTRE_cannon_90mm";
			};
			class muzzle_hide
			{
				source = "reload";
				weapon = "OPTRE_cannon_90mm";
			};
			class HideTurret
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class CargoDoorAnim
			{
				source = "user";
				animPeriod = 5;
				initPhase = 0;
				sound = "ServoRampSound_2"; //Fixa ljudet
			};
			class Missiles_revolving
			{
				source = "revolving";
				weapon = "OPTRE_missiles_C2GMLS_2"; //Namn på vapnet ta bort _2
			};
			class recoil_source 
			{
				source = "reload";
				weapon = "OPTRE_cannon_90mm";
			};
		};
		
		class UserActions
		{
			class CargoDoorOpen
			{
				userActionID = 60;
				displayName = "Open Cargo Door";
				displayNameDefault = "Open Cargo Door";
				textToolTip = "Open Cargo Door";
				position = "chargodoor_axis";
				radius = 6;
				priority = 2;
				onlyForPlayer = 0;
				condition = "((this animationPhase ""CargoDoor"" < 0.5) AND (alive this) AND (player in [gunner this, driver this]))";
				statement = "this animate [""CargoDoor"",1]";
				animPeriod = 5;
			};
			class CargoDoorClose: CargoDoorOpen
			{
				userActionID = 61;
				displayName = "Close Cargo Door";
				displayNameDefault = "Close Cargo Door";
				textToolTip = "Close Cargo Door";
				priority = 2;
				condition = "((this animationPhase ""CargoDoor"" > 0.5) AND (alive this) AND (player in [gunner this, driver this]))";
				statement = "this animate [""CargoDoor"",0]";
				animPeriod = 5;
			};
		};
		
		class EventHandlers: EventHandlers
		{
			fired = "[_this select 0,_this select 6,'missile_move','MissileBase'] call BIS_fnc_missileLaunchPositionFix; _this call (uinamespace getvariable 'BIS_fnc_effectFired');";
		};

		// Damage textures - for sections: zbytek, vez, zbran, vezVelitele, zbranVelitele,
		class Damage {
			tex[] = {};
			mat[] = {
				"Bison\data\Bison_90mm.rvmat",
				"Bison\data\Bison_90mm_damage.rvmat",
				"Bison\data\Bison_destruct.rvmat",
				
				"Bison\data\Bison_Body.rvmat",
				"Bison\data\Bison_Body_damage.rvmat",
				"Bison\data\Bison_destruct.rvmat",
				
				"Bison\data\Bison_CameraGlass.rvmat",
				"Bison\data\Bison_CameraGlass_damage.rvmat",
				"Bison\data\Bison_destruct.rvmat",
				
				"Bison\data\Bison_Interior.rvmat",
				"Bison\data\Bison_Interior_damage.rvmat",
				"Bison\data\Bison_destruct.rvmat",
				
				"Bison\data\Bison_Misc.rvmat",
				"Bison\data\Bison_Misc_damage.rvmat",
				"Bison\data\Bison_destruct.rvmat",
				
				"Bison\data\Bison_Seats.rvmat",
				"Bison\data\Bison_Seats_damage.rvmat",
				"Bison\data\Bison_destruct.rvmat",
				
				"Bison\data\Bison_WheelsCannon.rvmat",
				"Bison\data\Bison_WheelsCannon_damage.rvmat",
				"Bison\data\Bison_destruct.rvmat"
			};
		}; 

		smokeLauncherGrenadeCount = 6; //Number of smoke shells launched at once
		smokeLauncherVelocity = 14; //Velocity which smoke shells are launched at
		smokeLauncherOnTurret = 1; //0 if smoke launchers are on hull, 1 if on turret
		smokeLauncherAngle = 120; //Angle within which smoke grenades are launched (actual spacing may end up smaller so use slighty higher number)


		class ViewOptics: ViewOptics {
			visionMode[] = {"Normal","NVG"};
		};

		class Exhausts {
			class Exhaust1 {
				position = "exhaust_1";
				direction = "exhaust_1_dir";
				effect = "ExhaustsEffectAMV";
			};
			class Exhaust2 {
				position = "exhaust_2";
				direction = "exhaust_2_dir";
				effect = "ExhaustsEffectAMV";
			};
		};
		
		engineStartSpeed = 5;
		
				class Reflectors
		{
			class Left
			{
				color[] = {1900,1800,1700};
				ambient[] = {5,5,5};
				position = "Light_L";
				direction = "Light_L_end";
				hitpoint = "Light_L";
				selection = "Light_L";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				useFlare = 0;
				dayLight = 0;
				flareSize = 1.0;
				class Attenuation
				{
					start = 1.0;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			class Right: Left
			{
				position = "Light_R";
				direction = "Light_R_end";
				hitpoint = "Light_R";
				selection = "Light_R";
			};
			class Right2: Right
			{
				position = "light_R_flare";
				useFlare = 1;
			};
			class Left2: Left
			{
				position = "light_L_flare";
				useFlare = 1;
			};
			class Right3: Right2
			{
				position = "light_R_flare2";
				flareSize = 0.7;
				hitpoint = "Light_R2";
				selection = "Light_R2";
			};
			class Left3: Left2
			{
				position = "light_L_flare2";
				flareSize = 0.7;
				hitpoint = "Light_L2";
				selection = "Light_L2";
			};
		};
		aggregateReflectors[] = {{"Left","Left2","Left3","Right","Right2","Right3"}};
		
		explosionEffect = "FuelExplosionBig";
	

	/*	Faction variants	*/

			// Basic defines:knowledge required to recognize this type of target
		// Faction defines: side ID, faction class, crew, typical cargo
		/*side = 0;
		faction = "BIS_Tutorial";
		crew = "O_crew_F";
		typicalCargo[] = {"O_crew_F"};
				scope = 2;
		scopeCurator = 2;*/

		// 2 means available from Zeus, whereas 0 means hidden
		// Editor displayname	// accuracy > 4 is not possible to be fully recognized during game	// due to above will show only in editor
};

/****************************** IFV - Bison 40mm ******************************/	

	class OPTRE_IFV_Bison_40 : OPTRE_IFV_Bison_base 
	{
		displayName = "IFV-40 Bison";
		model = "\Bison\IFV_Bison_40.p3d";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret 
			{
				weapons[]={OPTRE_autocannon_40mm_CTWS,OPTRE_missiles_C2GMLS_2};
				magazines[]={60Rnd_40mm_GPR_Tracer_Green_shells,40Rnd_40mm_APFSDS_Tracer_Green_shells,OPTRE_2Rnd_C2GMLS_missiles};
			};
		};
		
		class AnimationSources: AnimationSources
		{
			class muzzle_rot
			{
				source = "ammorandom";
				weapon = "OPTRE_autocannon_40mm_CTWS";
			};
			class muzzle_hide
			{
				source = "reload";
				weapon = "OPTRE_autocannon_40mm_CTWS";
			};
			class recoil_source 
			{
				source = "reload";
				weapon = "OPTRE_autocannon_40mm_CTWS";
			};
		};
	
	};
	
	


};