
#define crewMacro(sideN,factionN,crewN) \
		side=sideN; \
		faction=factionN; \
		crew=crewN; \
		typicalCargo[]= {crewN};

//Faction Name Macro
#define mF1 IND_F
//Crew Name Macro 
#define mC1 I_Soldier_F
//FIA
#define mF2 BLU_G_F
#define mC2 B_G_Soldier_F
//CSAT
#define mF3 OPF_F
#define mC3 O_Soldier_F

class CfgVehicles
{
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets;
		class MainTurret;
	};
	class StaticMGWeapon: StaticWeapon{};
	class StaticATWeapon:StaticWeapon {};
	class StaticAAWeapon:StaticWeapon {};
	class StaticCannon: StaticWeapon {class ViewOptics;};

	class StaticGrenadeLauncher:StaticWeapon {class ViewOptics;};
	class StaticMortar:StaticWeapon{};
//#########################ZU23

	class RDS_ZU23_base: StaticCannon
	{
		mapSize = 2.5;
		cargoAction[]=
		{
			"Hilux_Cargo01"
		};
		displayname="ZU-23";
		model="\RDS_StaticW\ZU23\zu23";
		class Library
		{
			libTextDesc="ZU-23";
		};
		icon= "\RDS_StaticW\data\map_ico\icomap_zu23_CA.paa";
		picture="\RDS_StaticW\data\ico\zu23_CA.paa";
		UiPicture="\RDS_StaticW\data\ico\zu23_CA.paa";
		transportSoldier=1;
		memoryPointsGetInCargo="pos_cargo_dir";
		memoryPointsGetInCargoDir="pos_cargo";
		memoryPointsGetInDriver="pos_driver_dir";
		memoryPointsGetInDriverDir="pos_driver";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minTurn=-180;
				maxTurn=180;
				initTurn=0;
				minElev=-10;
				maxElev=85;
				initElev=0;
				weapons[]={RDS_2A14};
				magazines[]=
				{	
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85,
					RDS_40Rnd_23mm_AZP85
				};
				gunnerAction="Hilux_Cargo01";
				selectionFireAnim = "zasleh";
				gunnerOpticsModel="\RDS_StaticW\zu23\2Dscope_RUAA5";
				gunnerOpticsEffect[]=
				{
					"OpticsCHAbera1",
					"OpticsBlur2"
				};
				gunnerForceOptics=0;
				memoryPointsGetInGunner="pos_gunner_dir";
				memoryPointsGetInGunnerDir="pos_gunner";
				class ViewGunner
				{
					initAngleX=5;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.69999999;
					minFov=0.25;
					maxFov=1.1;
				};
				class ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.093000002;
					minFov=0.093000002;
					maxFov=0.093000002;
				};
			};
		};
		class AnimationSources
		{
			class muzzle_source
			{
				source="reload";
				weapon="RDS_2A14";
			};
			class fire_anim
			{
				source="revolving";
				weapon="RDS_2A14";
			};
		};

	};
	class RDS_ZU23_AAF: RDS_ZU23_base
	{
		scope=2;
		crewMacro(2,mF1,mC1)
	};

	// DSHKM
	class RDS_DSHKM_base: StaticMGWeapon
	{

		begin1[] = {"RDS_StaticW\m2hb", 0.562341, 1, 1100};
		begin2[] = {"RDS_StaticW\m2hb", 0.562341, 1, 1100};
		soundbegin[] = {"begin1", 0.5, "begin2", 0.5};

		sound[]={"RDS_StaticW\DShKM\data\dshk_2",db25,1,1300};
		reloadMagazineSound[]={"RDS_StaticW\DShKM\data\M60gun_reload",db-30,1,35};
		model="\RDS_StaticW\DShKM\DShKM_mg";
		icon= "\RDS_StaticW\data\map_ico\icomap_DShKM_CA.paa";
		picture="\RDS_StaticW\data\ico\dshkm_mg_ca.paa";
		UiPicture="\RDS_StaticW\data\ico\dshkm_mg_ca.paa";
		mapSize = 2;
		displayName=$STR_DN_DSHKM;

		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerLeftHandAnimName="otochlaven_shake";
				gunnerRightHandAnimName="otochlaven_shake";
				minElev=-20;
				maxelev = 60;
				minturn = -180;
				maxturn = 180;
				weapons[]={RDS_DSHKM};
				turretInfoType="RscWeaponZeroing";
				discreteDistance[]={100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex=2;
				magazines[]=				
				{													RDS_50Rnd_127x107_DSHKM,
					RDS_50Rnd_127x107_DSHKM,
					RDS_50Rnd_127x107_DSHKM,
					RDS_50Rnd_127x107_DSHKM
				};
				gunnerAction = "DShKM_Gunner";
				selectionFireAnim = "zasleh";
				gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
				class ViewOptics
				{
					initAngleX=0; minAngleX=-30; maxAngleX=+30;
					initAngleY=0; minAngleY=-100; maxAngleY=+100;
					initFov=0.7; minFov=0.25; maxFov=1.1;
				};
			};
		};
		class AnimationSources
		{
			class muzzle_source
			{
				source="reload";
				weapon="RDS_DSHKM";
			};
			class ReloadAnim{source="reload";weapon="RDS_DSHKM";};
			class ReloadMagazine{source="reloadmagazine";weapon="RDS_DSHKM";};
			class Revolving{source="revolving";weapon="RDS_DSHKM";};
		};
		class Library {libTextDesc = $STR_LIB_DSHKM;};
	};

	class RDS_DSHKM_AAF: RDS_DSHKM_base
	{
		scope = 2;
		crewMacro(2,mF1,mC1)
		ASSEMBLE_INFO(RDS_DShkM_Gun_Bag,RDS_DShkM_TripodHigh_Bag)
	};

	class RDS_DSHkM_Mini_TriPod: RDS_DSHKM_base 
	{
		scope=2;
		crewMacro(2,mF1,mC1)
		displayname = "DSHkM Minitripod";
		model = "RDS_StaticW\DShKM\DShKM_mg2";
		class Turrets: Turrets 
		{
			class MainTurret: MainTurret 
			{
				gunneraction = "LowTripod_Gunner";
				initturn = 0;
				maxturn = 90;
				memorypointsgetingunner = "pos_gunner";
				memorypointsgetingunnerdir = "pos_gunner_dir";
				minturn = -90;
			};
		};
		ASSEMBLE_INFO(RDS_DShkM_Gun_Bag,RDS_DShkM_TripodLow_Bag)
	};

	//KORD
	class RDS_KORD_Base: StaticMGWeapon
	{
		model="\RDS_StaticW\KORD\kord";
		icon="RDS_StaticW\data\map_ico\icomap_kord_CA.paa";
		picture="\RDS_StaticW\data\ico\kord_CA.paa";
		UiPicture="\RDS_StaticW\data\ico\kord_CA.paa";
		mapSize=3;
		begin1[]=
		{
			"RDS_StaticW\KORD\data\m2hb",
			0.56234133,
			1,
			1100
		};
		begin2[]=
		{
			"RDS_StaticW\KORD\data\m2hb",
			0.56234133,
			1,
			1100
		};
		soundBegin[]=
		{
			"begin1",
			0.5,
			"begin2",
			0.5
		};
		reloadMagazineSound[]=
		{
			"RDS_StaticW\DShKM\data\M60gun_reload",
			0.031622775,
			1,
			25
		};
		displayName="$STR_DN_KORD_LOW";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerLeftHandAnimName="otochlaven_shake";
				gunnerRightHandAnimName="otochlaven_shake";
				minElev=-20;
				maxelev = 15;
				weapons[]=
				{
					"RDS_KORD"
				};
				magazines[]=
				{
					"RDS_50Rnd_127x108_KORD",
					"RDS_50Rnd_127x108_KORD",
					"RDS_50Rnd_127x108_KORD",
					"RDS_50Rnd_127x108_KORD"
				};
				gunnerAction="LowKORD_Gunner";
				minTurn=-60;
				maxTurn=60;
				initTurn=0;
				optics=1;
				turretInfoType="RscWeaponZeroing";
				discreteDistance[]={100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex=2;
				selectionFireAnim = "zasleh";
				gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
				class ViewOptics
				{
					initAngleX=0; minAngleX=-30; maxAngleX=+30;
					initAngleY=0; minAngleY=-100; maxAngleY=+100;
					initFov=0.7; minFov=0.25; maxFov=1.1;
				};
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source="reload";
				weapon="RDS_KORD";
			};
			class ReloadMagazine
			{
				source="reloadmagazine";
				weapon="RDS_KORD";
			};
			class Revolving
			{
				source="revolving";
				weapon="RDS_KORD";
			};
		};
		armorStructural=10;
		class Library
		{
			libTextDesc="$STR_LIB_KORD";
		};
	};
	class RDS_KORD_AAF: RDS_KORD_Base
	{
		scope=2;
		crewMacro(2,mF1,mC1)
		ASSEMBLE_INFO(RDS_Kord_Gun_Bag,RDS_Kord_Tripod_Bag)
	};
	class RDS_KORD_high_AAF: RDS_KORD_Base
	{
		scope=2;
		crewMacro(2,mF1,mC1)
		displayName="$STR_DN_KORD";
		model="\RDS_StaticW\KORD\KORD_6u16sp";
		icon="RDS_StaticW\data\map_ico\icomap_kord6u16sp_CA.paa";
		picture="\RDS_StaticW\data\ico\kord6u16sp_ca.paa";
		UiPicture="\RDS_StaticW\data\ico\kord6u16sp_ca.paa";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev=-7;
				maxelev = 45;
				gunnerAction="KORD_Gunner";
				minTurn=-180;
				maxTurn=180;
				initTurn=0;
			};
		};
	};
	//M2
 	class RDS_M2StaticMG_base: StaticMGWeapon {

		model="\RDS_StaticW\m2\m2_mg";
		picture="\RDS_StaticW\data\ico\m2_mg_CA.paa";
		icon= "\RDS_StaticW\data\map_ico\icomap_M2_CA.paa";
		mapSize = 3;

		begin1[]={"RDS_StaticW\M2\data\M2_single_1", db5, 1, 1400};
		begin2[]={"RDS_StaticW\M2\data\M2_single_2", db5, 1, 1400};
		soundBegin[]={begin1,0.5, begin2, 0.5};

		reloadMagazineSound[]={"\RDS_StaticW\M2\data\reload-belt-1",db-25,1,40};

		displayName=$STR_DN_M2_MG;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				optics=1;
				turretInfoType="RscWeaponZeroing";
				discreteDistance[]=				{100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex=2;
				gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";

				gunnerLeftHandAnimName="otochlaven_shake";
				gunnerRightHandAnimName="otochlaven_shake";
				selectionFireAnim = "zasleh";
				minElev=-20;
				minTurn=-180;
				maxTurn=180;
				weapons[] = {HMG_M2};
				magazines[]=											{
					100Rnd_127x99_mag_Tracer_Yellow,
					100Rnd_127x99_mag_Tracer_Yellow,
					100Rnd_127x99_mag_Tracer_Yellow,
					100Rnd_127x99_mag_Tracer_Yellow
				};
				gunnerAction = "M2_Gunner";
			};
		};
		class AnimationSources
		{
			class ReloadAnim{source="reload";weapon="HMG_M2";};
			class ReloadMagazine{source="reloadmagazine";weapon="HMG_M2";};
			class Revolving{source="revolving";weapon="HMG_M2";};
		};
		armorStructural=10.0;
		class Library {libTextDesc = $STR_LIB_M2_MG;};

		ASSEMBLE_INFO(RDS_M2_Gun_Bag,RDS_M2_Tripod_Bag)
	};

 	class RDS_M2StaticMG_MiniTripod_base: RDS_M2StaticMG_base {
		displayName=$STR_DN_m2hd_minitripod;
		model="\RDS_StaticW\m2\m2_mg2";
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				gunnerLeftHandAnimName="otochlaven_shake";
				gunnerRightHandAnimName="otochlaven_shake";
				gunneraction = "LowTripod_Gunner";
				initturn = 0;
				maxturn = 90;
				minturn = -90;
			};
		};
		ASSEMBLE_INFO(RDS_M2_Gun_Bag,RDS_M2_MiniTripod_Bag)
	};

	class RDS_M2StaticMG_AAF: RDS_M2StaticMG_base {scope=2;crewMacro(2,mF1,mC1)};
	class RDS_M2StaticMG_MiniTripod_AAF: RDS_M2StaticMG_MiniTripod_base {scope=2;crewMacro(2,mF1,mC1)};



	// AGS
	class RDS_AGS_base: StaticGrenadeLauncher
	{
		model="\RDS_StaticW\AGS30\AGS_static";
		icon= "RDS_StaticW\data\map_ico\icomap_ags_CA.paa";
		picture="\RDS_StaticW\data\ico\ags_static_CA.paa";
		UiPicture="\RDS_StaticW\data\ico\ags_static_CA.paa";
		mapSize = 2;
		armor=150;

		sound[]={"RDS_StaticW\AGS30\data\AGS30_shot1_a",db25,1,1200};
		reloadMagazineSound[]={"RDS_StaticW\DShKM\data\M60gun_reload",db-30,1,35};

		displayName=$STR_DN_AGS30;

		gunnerHasFlares = true;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev=-10;maxelev = 32;
				minTurn=-90; maxTurn=+90; initTurn=0;
				weapons[]={RDS_AGS30};
				magazines[]=
				{
					RDS_29Rnd_30mm_AGS30,
					RDS_29Rnd_30mm_AGS30,
					RDS_29Rnd_30mm_AGS30,
					RDS_29Rnd_30mm_AGS30,
					RDS_29Rnd_30mm_AGS30,
					RDS_29Rnd_30mm_AGS30
				};
				gunnerAction = "AGS_Gunner";
				gunnerOpticsModel = \RDS_StaticW\optika_AGS30;
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				gunnerForceOptics = 0;

				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";				

				class ViewGunner
				{
					initAngleX=5; minAngleX=-30; maxAngleX=+30;
					initAngleY=0; minAngleY=-100; maxAngleY=+100;
					initFov=0.7; minFov=0.25; maxFov=1.1;
				};
				class ViewOptics : ViewOptics
				{
					initFov=0.250; minFov=0.250; maxFov=0.250; // FOV 28 deg
				};
			};
		};
		class Library {libTextDesc = $STR_LIB_AGS30;};
		ASSEMBLE_INFO(RDS_AGS30_Gun_Bag,RDS_AGS30_Tripod_Bag)
	};
	class RDS_AGS_AAF:RDS_AGS_base
	{
		scope = 2;
		crewMacro(2,mF1,mC1)
	};
	//Mk19
	class RDS_MK19_TriPod_base: StaticGrenadeLauncher
	{
		displayName=$STR_DN_mk19_tripod;
		model = "\RDS_StaticW\Mk19_minitripod\mk19_stat";
		picture = "\RDS_StaticW\Data\ico\mk19_stat_CA.paa";
		icon = "\RDS_StaticW\Data\map_ico\icomap_mk19_stat_CA.paa";
		mapSize = 2.5;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerLeftHandAnimName="otochlaven";
				gunnerRightHandAnimName="otochlaven";
				gunnerOpticsModel="\A3\weapons_f\reticle\optics_empty";
				minElev = -10;
				minTurn = -90;
				maxTurn = 90;
				initTurn = 0;
				weapons[]={RDS_MK19};
				magazines[]=
				{
					RDS_48Rnd_40mm_MK19,
					RDS_48Rnd_40mm_MK19,
					RDS_48Rnd_40mm_MK19,
					RDS_48Rnd_40mm_MK19
				};
				gunnerAction = "LowTripod_Gunner";
			};
		};
		ASSEMBLE_INFO(RDS_Mk19_Gun_Bag,RDS_Mk19_Tripod_Bag)
	};
	class RDS_MK19_TriPod_AAF:RDS_MK19_TriPod_base
	{
		scope = 2;
		crewMacro(2,mF1,mC1)
	};

	//Metis
	class RDS_Metis_Base: StaticATWeapon
	{
		ASSEMBLE_INFO(RDS_Metis_Gun_Bag,RDS_Metis_Tripod_Bag)
		scope = 0;
		displayname = $STR_DN_AT13;
		model = "\RDS_StaticW\metis_at_13\metis.p3d";
		class Library {libTextDesc = $STR_LIB_AT13;};
		icon="RDS_StaticW\data\map_ico\icomap_metis_at13_CA.paa";
		picture="\RDS_StaticW\data\ico\metis_at13_CA.paa";
		UiPicture="\RDS_StaticW\data\ico\metis_at13_CA.paa";
		mapSize = 1.5;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]={RDS_AT13LauncherSingle};
				magazines[]={RDS_6Rnd_AT13};
				gunnerAction = "Metis_Gunner";
				gunnerOpticsModel = "\RDS_StaticW\2Dscope_Metis";
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";				
				minTurn=-45; maxTurn=+45; initTurn=0;
				minElev=-10; maxElev=+40; initElev=0;
				ejectDeadGunner = 0;
				gunnerForceOptics = 0;
				class ViewGunner
				{
					initAngleX=5; minAngleX=-30; maxAngleX=+30;
					initAngleY=0; minAngleY=-100; maxAngleY=+100;
					initFov=0.7; minFov=0.25; maxFov=1.1;
				};
				class ViewOptics
				{
					initAngleX=0; minAngleX=-30; maxAngleX=+30;
					initAngleY=0; minAngleY=-100; maxAngleY=+100;
					initFov=0.078; minFov=0.078; maxFov=0.078; // 6x zoom
					visionMode[]=
					{
						"Normal",
						"TI"
					};
					thermalMode[]={4,5};
				};
			};
		};
	};
	class RDS_Metis_AAF: RDS_Metis_Base
	{
		scope = 2;
		crewMacro(2,mF1,mC1)
	};


	class RDS_TOW_TriPod_base: StaticATWeapon
	{
		mapSize = 2.5;
		picture = "\RDS_StaticW\data\Ico\tow_static_CA.paa";
		icon = "\RDS_StaticW\data\map_ico\icomap_tow_static_CA.paa";
		//sound[] = {"Ca\sounds\Weapons\cannon\Javelin1",31.6228,1,1200};

		displayname = $STR_dn_tow_tripod;

		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
				minElev = -10;
				minturn = -180;
				maxturn = 180;
				weapons[] = {"RDS_TOWLauncherSingle"};
				magazines[] = {"RDS_6Rnd_TOW_HMMWV"};
				gunnerAction = "TOW_Gunner";
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.2;
					minFov = 0.025;
					maxFov = 0.2;
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {0,1};
				};
				gunnerOpticsModel = "\RDS_StaticW\TOW\TOW_TI";
			};
		};
		model = "\RDS_StaticW\TOW\TOW_static";
		ASSEMBLE_INFO(RDS_Tow_Gun_Bag,RDS_Tow_Tripod_Bag)
	};
	class RDS_TOW_TriPod_AAF: RDS_TOW_TriPod_Base {scope=2;crewMacro(2,mF1,mC1)};

	//SPG9
	class RDS_SPG9_base: StaticATWeapon
	{
		displayName=$STR_DN_SPG9;
		model = "\RDS_StaticW\spg9\spg9.p3d";
		icon= "RDS_StaticW\data\map_ico\icon_spg9_CA.paa";
		picture="\RDS_StaticW\data\ico\spg9_CA.paa";
		UiPicture="\RDS_StaticW\data\ico\spg9_CA.paa";
		mapSize = 3;
		nameSound="cannon";
		transportSoldier = 0;
		gunnerHasFlares = true;
		class AnimationSources
		{
			class ReloadAnim{source="reload";weapon="RDS_SPG9";};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]={RDS_SPG9};
				magazines[]=
				{
					RDS_OG9_HE,RDS_OG9_HE,RDS_OG9_HE,RDS_OG9_HE,RDS_OG9_HE,RDS_OG9_HE,RDS_OG9_HE,RDS_OG9_HE,RDS_OG9_HE,RDS_OG9_HE,
					RDS_PG9_AT,RDS_PG9_AT,RDS_PG9_AT,RDS_PG9_AT,RDS_PG9_AT
				};
				gunnerAction = "SPG_Gunner";
				gunnerOpticsModel = "\RDS_StaticW\2Dscope_SPG_4";
				gunnerOpticsEffect[] = 				{"OpticsCHAbera1","OpticsBlur2","TankGunnerOptics1"};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";				
				minTurn=-45; maxTurn=+45; initTurn=0;
				minElev=-10; maxElev=+40; initElev=0;
				ejectDeadGunner = 0;
				gunnerForceOptics = 0;
				class ViewGunner
				{
					initAngleX=5; minAngleX=-30; maxAngleX=+30;
					initAngleY=0; minAngleY=-100; maxAngleY=+100;
					initFov=0.7; minFov=0.25; maxFov=1.1;
				};
				class ViewOptics
				{
					initAngleX=0; minAngleX=-30; maxAngleX=+30;
					initAngleY=0; minAngleY=-100; maxAngleY=+100;
					initFov=0.111; minFov=0.111; maxFov=0.111; // 4.2x zoom
				};
			};
		};
		class Library {libTextDesc = $STR_LIB_SPG9;};
		ASSEMBLE_INFO(RDS_SPG9_Gun_Bag,RDS_SPG9_Tripod_Bag)
	};
	class RDS_SPG9_AAF:RDS_SPG9_base
	{
		scope = 2;
		crewMacro(2,mF1,mC1)
	};
	//Igla

	class RDS_Igla_AA_pod_Base : StaticAAWeapon
	{
		gunnercansee = "2+4+8+32";
		displayName=$STR_DN_IGLA_AA_POD_EAST;
		mapsize = 2.8;
		model = "RDS_StaticW\igla\igla_AA_pod";
		icon = "RDS_StaticW\data\map_ico\icomap_igla_aa_pod_CA.paa";
		picture="\RDS_StaticW\data\ico\igla_aa_pod_ca.paa";
		UiPicture="\RDS_StaticW\data\ico\igla_aa_pod_ca.paa";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minTurn=-180;
				maxTurn=180;
				gunneraction = "Mi17_Cargo02";
				gunneropticseffect[] = {"OpticsCHAbera1", "OpticsBlur2"};
				gunneropticsmodel = "\RDS_StaticW\optika_TOW";
				magazines[] = {
					"RDS_2Rnd_Igla",
 					"RDS_2Rnd_Igla",
 					"RDS_2Rnd_Igla",
 					"RDS_2Rnd_Igla",
 					"RDS_2Rnd_Igla",
 					"RDS_2Rnd_Igla",
					"RDS_2Rnd_Igla",
 					"RDS_2Rnd_Igla",
					"RDS_2Rnd_Igla",
 					"RDS_2Rnd_Igla"
				};
				maxelev = 120;
				memorypointsgetingunner = "pos_gunner";
				memorypointsgetingunnerdir = "pos_gunner_dir";
				minelev = -10;
				weapons[] = {"RDS_Igla_twice"};
				class ViewOptics
				{
					initanglex = 0;
					initangley = 0;
					initfov = 0.155;
					maxanglex = 30;
					maxangley = 100;
					maxfov = 0.155;
					minanglex = -30;
					minangley = -100;
					minfov = 0.047;
				};
			};
		};
	};

	class RDS_Igla_AA_pod_AAF : RDS_Igla_AA_pod_Base
	{
		scope=2;
		crewMacro(2,mF1,mC1)
	};	
	
	//Podnos Mortar 
	class RDS_2b14_82mm_Base: StaticMortar
	{
		availableForSupportTypes[]={"Artillery"};
		displayname="$STR_DN_2B14";
		class Library
		{
			libTextDesc="$STR_LIB_2B14";
		};
		model="\RDS_StaticW\podnos_2b14_82mm\podnos_2b14_82mm";
		transportSoldier=1;
		cargoAction[]=
		{
			"D30_Cargo"
		};
		icon="RDS_StaticW\data\map_ico\icomap_podnos_2b14_CA.paa";
		picture="\RDS_StaticW\data\ico\podnos_2b14_ca.paa";
		UiPicture="\RDS_StaticW\data\ico\podnos_2b14_ca.paa";
		mapSize=1.5;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
				gunnerAction="D30_Cargo";
				/*weapons[]=
				{
					"2B14"
				};
				discreteDistance[]=											{100,200,300,400,500,700,1000,1600,2000,2400,2800};
				discreteDistanceInitIndex=5;
				turretInfoType="RscWeaponRangeArtillery";
				gunnerOpticsModel = "\RDS_StaticW\2Dscope_D30";*/
				weapons[]=
				{
					"mortar_82mm"
				};
				magazines[]=
				{
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_Flare_white",
					"8Rnd_82mm_Mo_Smoke_white"
				};
				initElev=0;
				initTurn=0;
				minElev=-15;
				maxElev=35;
				minTurn=-180;
				maxTurn=180;
			};
		};
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;
		artilleryScanner = 1;
		ASSEMBLE_INFO(RDS_Podnos_Gun_Bag,RDS_Podnos_Bipod_Bag)
	};
	class RDS_2b14_82mm_AAF: RDS_2b14_82mm_Base
	{
		scope=2;
		crewMacro(2,mF1,mC1)
	};
	class RDS_M252_base: RDS_2b14_82mm_Base
	{
		displayname="$STR_DN_m252";
		class Library
		{
			libTextDesc="$STR_LIB_m252";
		};

		model = "\RDS_StaticW\M252_81mm_Mortar\81Mortar";
		picture = "\RDS_StaticW\data\ico\mortar_m251_CA.paa";
		icon = "\RDS_StaticW\data\map_ico\icomap_mortar_m251_CA.paa";
		ASSEMBLE_INFO(RDS_M252_Gun_Bag,RDS_M252_Bipod_Bag)
	};
	class RDS_M252_AAF: RDS_M252_Base
	{
		scope=2;
		crewMacro(2,mF1,mC1)
	};

	// D30
	class RDS_D30_base: StaticCannon
	{
		accuracy = 0.12;
		cost = 10000;
		availableForSupportTypes[]=
		{
			"Artillery"
		};
		artilleryScanner = 1;
		displayName=$STR_DN_D30;

		model="\RDS_StaticW\D30\D30";
		icon= "RDS_StaticW\data\map_ico\icomap_d30_CA.paa";
		picture="\RDS_StaticW\data\ico\d30_CA.paa";
		UiPicture="\RDS_StaticW\data\ico\d30_CA.paa";

		mapSize = 4.5;
		cargoAction[] = {D30_Cargo,D30_Commander};
		typicalCargo[]={I_Soldier_F,I_Soldier_F,I_Soldier_F};
		transportSoldier = 2;
		gunnerHasFlares = true;
		
		memoryPointsGetInCargo = "pos_cargo_dir";
		memoryPointsGetInCargoDir = "pos_cargo";		
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunBeg="Usti hlavne";
				gunEnd="Konec hlavne";
				weapons[]={RDS_D30};
				magazines[] = 	
				{
					"RDS_30Rnd_122mmHE_D30",
					"RDS_30Rnd_122mmWP_D30",
					"RDS_30Rnd_122mmLASER_D30",
					"RDS_30Rnd_122mmSMOKE_D30",
					"RDS_30Rnd_122mmILLUM_D30"
				};
				gunnerAction = "D30_Gunner";
				gunnerOpticsModel = "\RDS_StaticW\2Dscope_D30";
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";
				
				minElev=-9;
				maxelev = 80;
				minTurn=-180;
				maxTurn=180;
				class ViewOptics: ViewOptics
				{
					initFov=0.096; minFov=0.096; maxFov=0.096; //FOV 11 deg
				};
			};
		};
		class AnimationSources
		{
			class recoil_source
			{
				source="reload";
				weapon="RDS_D30";
			};
			class leftT_source {source="user";animPeriod = 1;initPhase=-2.3; };
			class rightT_source: leftT_source {initPhase=0; };
			class leftW_source: leftT_source {initPhase=-1.7; };
			class rightW_source: leftW_source {};
			class maingunT_source {source="user";animPeriod = 1;initPhase=0; };
			class mainTurretT_source: maingunT_source {};
			class szpilki_source {source="user";animPeriod = 0.1;initPhase=0; };
		};
		class Damage
		{
			tex[]={};
			mat[]={
				"RDS_StaticW\D30\data\d30.rvmat",
				"RDS_StaticW\D30\data\d30_damage.rvmat",
				"RDS_StaticW\D30\data\d30_destruct.rvmat"
			};
		};
		class Library {libTextDesc = $STR_LIB_D30;};
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 450;
	};
	class RDS_D30_AAF: RDS_D30_base {scope=2;crewMacro(2,mF1,mC1)};

	class RDS_D30_AT_AAF: RDS_D30_AAF
	{
		displayName=D-30 AT;
		availableForSupportTypes[]={};
		artilleryScanner = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]={RDS_D30AT};
				magazines[] = 	
				{
					"RDS_30Rnd_122mmAT_D30",
					"RDS_30Rnd_122mmHE_D30",
					"RDS_30Rnd_122mmWP_D30"
				};
			};
		};
		class AnimationSources
		{
			class recoil_source
			{
				source="reload";
				weapon="RDS_D30AT";
			};
			class leftT_source {source="user";animPeriod = 1;initPhase=-2.3; };
			class rightT_source: leftT_source {initPhase=0; };
			class leftW_source: leftT_source {initPhase=-1.7; };
			class rightW_source: leftW_source {};
			class maingunT_source {source="user";animPeriod = 1;initPhase=0; };
			class mainTurretT_source: maingunT_source {};
			class szpilki_source {source="user";animPeriod = 0.1;initPhase=0; };
		};
	};
	class RDS_M119_base : RDS_D30_base
	{
		displayName=$STR_DN_M119;

		model="\RDS_StaticW\M119_Howitzer\M119";
		picture="\RDS_StaticW\data\ico\M119_CA.paa";
		icon= "\RDS_StaticW\data\map_ico\icomap_m119_CA.paa";
		cargoAction[] = {M119_Cargo,M119_Commander};

		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]={RDS_M119};
				magazines[] = 	
				{
					"RDS_30Rnd_105mmHE_M119",
					"RDS_30Rnd_105mmWP_M119",
					"RDS_30Rnd_105mmLASER_M119",
					"RDS_30Rnd_105mmSMOKE_M119",
					"RDS_30Rnd_105mmILLUM_M119"
				};
				gunnerAction = "M119_Gunner";
				gunnerOpticsModel = \RDS_StaticW\M119_Howitzer\optika_M119;
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";				
				class ViewOptics:ViewOptics
				{
					initFov=0.155; minFov=0.155; maxFov=0.155; // 3x zoom from 50 deg FOV
				};
			};
		};
		class AnimationSources
		{
			class recoil_source
			{
				source="reload";
				weapon="RDS_M119";
			};
		};

		class Library {libTextDesc = $STR_LIB_M119;};
	};

	class RDS_M119_AAF: RDS_M119_base {scope=2;crewMacro(2,mF1,mC1)};



	#include "cfgBags.hpp"

	class RDS_ZU23_FIA: RDS_ZU23_AAF {crewMacro(1,mF2,mC2)};
	class RDS_DSHKM_FIA: RDS_DSHKM_AAF {crewMacro(1,mF2,mC2)};
	class RDS_DSHkM_Mini_TriPod_FIA: RDS_DSHkM_Mini_TriPod {crewMacro(1,mF2,mC2)};
	class RDS_KORD_FIA: RDS_KORD_AAF {crewMacro(1,mF2,mC2)};
	class RDS_KORD_high_FIA: RDS_KORD_high_AAF {crewMacro(1,mF2,mC2)};
	class RDS_AGS_FIA: RDS_AGS_AAF {crewMacro(1,mF2,mC2)};
	class RDS_Metis_FIA: RDS_Metis_AAF {crewMacro(1,mF2,mC2)};
	class RDS_SPG9_FIA: RDS_SPG9_AAF {crewMacro(1,mF2,mC2)};
	class RDS_Igla_AA_pod_FIA: RDS_Igla_AA_pod_AAF {crewMacro(1,mF2,mC2)};
	class RDS_2b14_82mm_FIA: RDS_2b14_82mm_AAF {crewMacro(1,mF2,mC2)};
	class RDS_D30_FIA: RDS_D30_AAF {crewMacro(1,mF2,mC2)};
	class RDS_D30_AT_FIA: RDS_D30_AT_AAF {crewMacro(1,mF2,mC2)};

	class RDS_ZU23_CSAT: RDS_ZU23_AAF {crewMacro(0,mF3,mC3)};
	class RDS_DSHKM_CSAT: RDS_DSHKM_AAF {crewMacro(0,mF3,mC3)};
	class RDS_DSHkM_Mini_TriPod_CSAT: RDS_DSHkM_Mini_TriPod {crewMacro(0,mF3,mC3)};
	class RDS_KORD_CSAT: RDS_KORD_AAF {crewMacro(0,mF3,mC3)};
	class RDS_KORD_high_CSAT: RDS_KORD_high_AAF {crewMacro(0,mF3,mC3)};
	class RDS_AGS_CSAT: RDS_AGS_AAF {crewMacro(0,mF3,mC3)};
	class RDS_Metis_CSAT: RDS_Metis_AAF {crewMacro(0,mF3,mC3)};
	class RDS_SPG9_CSAT: RDS_SPG9_AAF {crewMacro(0,mF3,mC3)};
	class RDS_Igla_AA_pod_CSAT: RDS_Igla_AA_pod_AAF {crewMacro(0,mF3,mC3)};
	class RDS_2b14_82mm_CSAT: RDS_2b14_82mm_AAF {crewMacro(0,mF3,mC3)};
	class RDS_D30_CSAT: RDS_D30_AAF {crewMacro(0,mF3,mC3)};
	class RDS_D30_AT_CSAT: RDS_D30_AT_AAF {crewMacro(0,mF3,mC3)};
};