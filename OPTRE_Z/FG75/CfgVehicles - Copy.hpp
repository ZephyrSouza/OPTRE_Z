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
	};
	class OPTRE_StaticCannon_base: StaticCannon
	{
		author = "Article 2 Studios";
		simulation = "tank";
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
		lib_attach_pos[] = {0,0,0};
		//cargoAction[] = {"Zis3_Loader","Zis3_Cargo1","Zis3_Cargo2"};
		transportSoldier = 0;
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		class HitPoints
		{
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 1;
				material = -1;
				name = "telo";
				passThrough = 1;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "NEzbytek";
				visual = "zbytek";
				passThrough = 1;
			};
			class HitLTrack
			{
				armor = 5;
				material = -1;
				name = "HitLTrack";
				visual = "LWheel";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 5;
				material = -1;
				name = "HitRTrack";
				visual = "RWheel";
				passThrough = 0;
			};
			class HitTurret
			{
				armor = 10;
				material = -1;
				name = "HitTurret";
				visual = "Turret";
				passThrough = 1;
			};
			class HitGun
			{
				armor = 10;
				material = -1;
				name = "HitGun";
				visual = "Gun";
				passThrough = 1;
			};
		};
		class AnimationSources
		{
			class recoil_gun
			{
				source = "user";
				animPeriod = 0;
			};
			class MainTurret_Hide: recoil_gun{};
			class MainGun_Hide: recoil_gun{};
			class left_stand_Hide: recoil_gun{};
			class right_stand_Hide: recoil_gun{};
			class wheel_1_1_Hide: recoil_gun{};
			class wheel_2_1_Hide: recoil_gun{};
			class Shield_up_Hide: recoil_gun{};
			class Shield_small: recoil_gun
			{
				animPeriod = 0.5;
			};
			class chassis_lift_rotate: Shield_small
			{
				animPeriod = 2;
			};
			class Shield_down_rotate: chassis_lift_rotate{};
			class left_stand_rotate: chassis_lift_rotate
			{
				initPhase = 1;
			};
			class left_brake_rotate: left_stand_rotate{};
			class left_handle_rotate: left_stand_rotate{};
			class left_handle_locker_translate: left_stand_rotate{};
			class right_stand_rotate: left_stand_rotate{};
			class right_brake_rotate: left_stand_rotate{};
			class right_handle_rotate: left_stand_rotate{};
			class right_handle_locker_translate: left_stand_rotate{};
			class wheel_1_1: recoil_gun
			{
				animPeriod = 0.01;
			};
			class wheel_2_1: wheel_1_1{};
			class SightX: recoil_gun
			{
				animPeriod = 0.001;
			};
			class Rotation_Chassis: recoil_gun
			{
				animPeriod = 1e-012;
				initPhase = 0;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev = -5;
				maxElev = 37;
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
				
			/*	class OpticsIn
				{
					class Wide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						minFov = 0.1;
						initFov = 0.1;
						maxFov = 0.1;
						visionMode[] = {"Normal"};
						thermalMode[] = {0,1};
						gunnerOpticsEffect[] = {};
					};
					class Narrow: Wide
					{
						minFov = 0.1;
						initFov = 0.1;
						maxFov = 0.1;
					};
				}; */
			};
			class CommanderOptics: CommanderOptics
			{
				allowTabLock = 0;
				canUseScanners = 0;
				body = "ObsTurret";
				gun = "ObsGun";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				gunnerOutOpticsModel = "";
				memoryPointGun = "kulas";
				outGunnermayfire = 0;
				selectionFireAnim = "zasleh";
				stabilizedInAxes = 3;
				memoryPointGunnerOutOptics = "commanderview";
				memoryPointsGetInGunner = "pos_commander";
				memoryPointsGetInGunnerDir = "pos_commander_dir";
				weapons[] = {"FakeWeapon"};
				magazines[] = {"FakeWeapon"};
				startEngine = 0;
				forceHideCommander = 0;
				animationSourceHatch = "";
				gunnerAction = "Mortar_Gunner";
				minTurn = 0;
				maxTurn = 0;
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				ejectDeadGunner = 1;
				castgunnerShadow = 1;
				hideWeaponsGunner = 0;
				gunnerForceOptics = 0;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
				class ViewOptics: ViewOptics
				{
					minAngleX = -10;
					minAngleY = -360;
					maxAngleY = 360;
					initFov = 0.4;
					minFov = 0.4;
					maxFov = 0.4;
				};
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
				crew = "OPTRE_Ins_URF_Engineer";
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
		};
		
		class AnimationSources: AnimationSources
		{
			class revolving_rot {source = "revolving"; weapon = "OPTRE_75mm";};
			class revolving_recoil {source = "ammo"; weapon = "OPTRE_75mm";};
			class recoil {source = "reload"; weapon = "OPTRE_75mm";};
			
		};
		
	};
};