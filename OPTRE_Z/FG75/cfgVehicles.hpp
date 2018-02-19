class Optics_Armored;
class Optics_Commander_02: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_MBT_03: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
////////////////////////////Inheritances classes/////////////////////////
class CfgVehicles
{
	class All;
	class AllVehicles: All
	{
		class ViewOptics;
		class NewTurret
		{
			class ViewGunner;
		};
	};
	class Land: AllVehicles{};
	class LandVehicle: Land
	{
		class ViewPilot;
		class CommanderOptics;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret{};
		};
		class UserActions;
	};

	class StaticCannon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class CargoTurret;
	};
	class OPTRE_StaticCannon_base: StaticCannon
	{
		author = "Article 2 Studios";
		simulation = "tank"; //well try this normal was tank and not tankX
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;
		selectionFireAnim = "zasleh";
		nameSound = "veh_staticCannon";
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"veh_staticCannon"};
				speechPlural[] = {"veh_staticCannons"};
			};
		};
		accuracy = 0.5;
		armor = 100;
		camShakeCoef = 0.4;
		hasCommander = 1;
		castCargoShadow = 1;
		mapSize = 8;
		cost = 150000;
		driverCanSee = "2+8+16+32";
		gunnerCanSee = "2+4+8+16+32";
		commanderCanSee = "2+4+8+16+32";
		irScanGround = 2;
		allowTabLock = 0;
		canUseScanners = 0;
		transportSoldier = 0;
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		class HitPoints
		{
			class HitHull
			{
				armor = 1;
				material = -1;
				name = "telo";
				passThrough = 0;
				explosionShielding = 0.2;
			};
			class HitTurret
			{
				armor = 0.1;
				material = -1;
				name = "HitTurret";
				visual = "Turret";
				passThrough = 0;
				radius = 0.1;
				explosionShielding = 0.2;
			};
			class HitGun
			{
				armor = 0.2;
				material = -1;
				name = "HitTurret";
				visual = "Gun";
				passThrough = 0;
				radius = 0.12;
				explosionShielding = 0.2;
			};
		};
		class AnimationSources
		{
			class recoil_gun
			{
				source = "user";
				animPeriod = 0;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev = -7.5;
				maxElev = 34.5;
				minTurn = -23;
				maxTurn = 23;
				initElev = 5;
				gunnerAction = "Mortar_Gunner";
				gunnerInAction = "ManActTestDriver";
				hideWeaponsGunner = 0;
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				maxHorizontalRotSpeed = 0.3;
				maxVerticalRotSpeed = 0.3;
				memoryPointsGetInGunner = "pos_gunner";
				memoryPointsGetInGunnerDir = "pos_gunner_dir";
				ejectDeadGunner = 1;
			//	turretInfoType = "RscWeaponZeroing";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1400,1600,1800,2000,2200,2400,2600,2800,3000,3200,3400,3600,3800,4000};
				discreteDistanceInitIndex = 0;
				gunnerOpticsColor[] = {};
				allowTabLock = 0;
				canUseScanners = 0;
				proxyType = "CPGunner";
				proxyIndex = 1;
				gunnerForceOptics = 0;
				usepip=1;
				
				class ViewGunner 
				{
					initAngleX = 0;
					minAngleX = -45;
					maxAngleX = 75;
					initAngleY = 0;
					minAngleY = -120;
					maxAngleY = 120;
					initFov = 0.4;
					minFov = 0.4;
					maxFov = 0.4;
				};
				class ViewOptics: Optics_Gunner_MBT_03
				{
					class Wide: Wide{};
					class Medium: Medium{};
					class Narrow: Narrow{};
				};
				turretInfoType = "RscOptics_MBT_03_gunner";
				commanding= 1;
				
			};
			class CargoTurret1: CargoTurret
			{
				gunnerAction 				= "passenger_inside_4";		/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "Compartment2";			/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos_cargo";				/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos_cargo_dir";			/// direction of get in action
				memoryPointGunnerOptics 	= "gunnerview";
				gunnerName 					= "Loader";		/// name of the position in the Action menu
				proxyIndex 					= 1;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -25;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 60;					/// what is the left-most possible turn of the turret
				minTurn 					= -60;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 2;					/// enables firing from vehicle functionality // is for in and out (change to out only later)
				ejectDeadGunner 			= 0;					/// seatbelts included	
				gunnerInAction				= "passenger_inside_4";	///Your sitting animation inside cargo(can be a FFV animation)
				startEngine = 0;
				allowLauncherIn = 1;
				allowLauncherOut = 1; // Only want out but in also for now
				
				commanding= 2;
			};
			
		};
		class UserActions{};
	};
	class OPTRE_FG75: OPTRE_StaticCannon_base
	{
		dlc = "OPTRE";
		scope = 2;
		scopeCurator = 2;
		side = 0;
		displayName = "FG75";
		model = "\FG75\FG75.p3d";
		faction = "OPTRE_Ins";
		vehicleClass = "OPTRE_UNSC_Static_class";
		editorSubcategory = "EdSubcat_Turrets";
		crew = "OPTRE_Ins_URF_Engineer";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"OPTRE_75mm"};
				magazines[] = {"OPTRE_4Rnd_75mm_HE","OPTRE_4Rnd_75mm_HE","OPTRE_4Rnd_75mm_HE","OPTRE_4Rnd_75mm_AT","OPTRE_4Rnd_75mm_AT","OPTRE_4Rnd_75mm_AT"};
				viewGunnerInExternal = 1;
				gunnerAction = "Mortar_Gunner";
				gunnerInAction = "Mortar_Gunner";
				forceHideGunner = 1;
				ejectDeadGunner = 1;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
				class ViewOptics: ViewOptics 
				{
					initAngleX = 0;
					minAngleX = -45;
					maxAngleX = 75;
					initAngleY = 0;
					minAngleY = -120;
					maxAngleY = 120;
					initFov = 0.4;
					minFov = 0.04167;
					maxFov = 0.4;
					thermalMode[] = {0,1};
					visionMode[] = {"Normal","NVG"};
				};
				class ViewGunner 
				{
					initAngleX = 0;
					minAngleX = -45;
					maxAngleX = 75;
					initAngleY = 0;
					minAngleY = -120;
					maxAngleY = 120;
					initFov = 0.4;
					minFov = 0.4;
					maxFov = 0.4;
				};
			};
			class CargoTurret1: CargoTurret1
			{
				gunnerType="OPTRE_Ins_URF_Engineer";
			};
		};
		
		class AnimationSources: AnimationSources
		{
			class revolving_rot {source = "revolving"; weapon = "OPTRE_75mm";};
			class revolving_recoil {source = "ammo"; weapon = "OPTRE_75mm";};
			class recoil {source = "reload"; weapon = "OPTRE_75mm";};
			
		};
		
	};
};