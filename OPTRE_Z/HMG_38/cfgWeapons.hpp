class Mode_SemiAuto;
class Mode_Burst;	
class Mode_FullAuto;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class ItemCore;
	class muzzle_snds_H;
	class optic_Aco;
	class InventoryOpticsItem_Base_F;
	class InventoryMuzzleItem_Base_F;
	class MMG_01_hex_F;
	class UGL_F;
	class OPTRE_HMG38_Base: MMG_01_hex_F
	{
		class WeaponSlotsInfo;
	};
	
	class OPTRE_muzzleFlash_suppressed: ItemCore
	{
		scope 																					= 2;
		model 																					= "A3\Data_f\proxies\muzzle_flash\muzzle_flash_suppressor.p3d";
	};
	
	//ATTACHMENTS
	class OPTRE_HMG38_CarryHandle: optic_Aco
	{
		dlc = "OPTRE";
		author = "Article 2 Studios";
		displayName 																= "HMG38 Carry Handle";
		picture 																	= "HMG_38\icons\HMG_38_CarryHandle_Icon.paa";
		descriptionShort 															= "Carry Handle Sight";
		model									    								= "HMG_38\HMG38_CarryHandle.p3d";
		inertia 																	= 0.1;
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass 																	= 4;
			modelOptics 															= "\A3\Weapons_F\empty";
			optics 																	= 1;
			class OpticsModes
			{
				class HMG_38_CarryHandle_Irons
				{
					opticsID = 2;
					useModelOptics = false;
					opticsPPEffects[]={""};
					opticsFlare = false;
					opticsDisablePeripherialVision = false;
					opticsZoomMin=0.375;
					opticsZoomMax=1;
					opticsZoomInit=0.75;
					memoryPointCamera = "eye";
					visionMode[] = {}; /// Can be combined with NVG
					distanceZoomMin=300;
					distanceZoomMax=300;
				};
				class HMG_38_CarryHandle_Sight
				{
					opticsID = 1;
					useModelOptics = false;
					opticsPPEffects[]={"OpticsCHAbera2","OpticsBlur2"};
					opticsFlare = true;
					opticsDisablePeripherialVision = true;
					opticsZoomMin = 0.2;
					opticsZoomMax=0.2;
					opticsZoomInit=0.2;
					discretefov[] = {0.0700};
 					discreteInitIndex = 0;		
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal","NVG"}; /// Cannot be combined with NVG
					distanceZoomMin=300;
					distanceZoomMax=300;
				};
			};
		};
	};
	
	//WEAPONS
	
	class OPTRE_HMG38_Rifle: OPTRE_HMG38_Base
	{
		dlc = "OPTRE";
		author = "Article 2 Studios";
        scope                                                                   	= 2;
        scopeArsenal                                                                = 2;
		handAnim[] 																	= {"OFP2_ManSkeleton", "HMG_38\anim\HMG_38_HandAnim.rtm"};
		model																		= "HMG_38\HMG38.p3d";
		displayName 																= "HMG 38";
		baseWeapon 																	= "OPTRE_HMG38_Rifle";
		descriptionShort 															= "Insurection Era Rifle";
		picture 																	= "HMG_38\icons\HMG_38_Icon.paa";
		magazines[] 																= {"OPTRE_42Rnd_30x06_Mag","OPTRE_42Rnd_30x06_Mag_Tracer"};
        reloadAction                                                            	= "GestureReloadEBR";
		recoil																		= "recoil_ebr";
		reloadMagazineSound[]={"A3\sounds_f\weapons\reloads\new_MX",db-8,1, 30}; /// custom made sounds
		muzzles[]                                                          	 		= {"this", "OPTRE_HMGUGL"};
		
		class OPTRE_HMGUGL: UGL_F
		{
			displayName 														= "M301 Grenade Launcher";
			descriptionShort 													= "M301 GL";
			useModelOptics 														= 1;
			useExternalOptic 													= 1;
			cameraDir 															= "OP_look";
			discreteDistance[] 													= {100, 200, 300, 400};
			discreteDistanceCameraPoint[] 										= {"OP_eye"}; /// the angle of gun changes with zeroing
			discreteDistanceInitIndex 											= 0;
			reloadAction 														= "GestureReloadMXUGL";
			recoil = "recoil_gm6";
			magazines[] =
			{
				"UGL_FlareWhite_F",
				"UGL_FlareGreen_F",
				"UGL_FlareRed_F",
				"UGL_FlareYellow_F",
				"UGL_FlareCIR_F",
				"1Rnd_Smoke_Grenade_shell",
				"1Rnd_SmokeRed_Grenade_shell",
				"1Rnd_SmokeGreen_Grenade_shell",
				"1Rnd_SmokeYellow_Grenade_shell",
				"1Rnd_SmokePurple_Grenade_shell",
				"1Rnd_SmokeBlue_Grenade_shell",
				"1Rnd_SmokeOrange_Grenade_shell",
				"3Rnd_UGL_FlareWhite_F",
				"3Rnd_UGL_FlareGreen_F",
				"3Rnd_UGL_FlareRed_F",
				"3Rnd_UGL_FlareYellow_F",
				"3Rnd_UGL_FlareCIR_F",
				"3Rnd_Smoke_Grenade_shell",
				"3Rnd_SmokeRed_Grenade_shell",
				"3Rnd_SmokeGreen_Grenade_shell",
				"3Rnd_SmokeYellow_Grenade_shell",
				"3Rnd_SmokePurple_Grenade_shell",
				"3Rnd_SmokeBlue_Grenade_shell",
				"OPTRE_20mm_HE_Grenade_Shell"
			};
		};
        class GunParticles
        {
           class EffectShotCloud
           {
                positionName                                                    	= "Nabojnicestart";
                directionName                                                   	= "Nabojniceend";
                effectName                                                      	= "CaselessAmmoCloud";
           };
        };
		
		class WeaponSlotsInfo: WeaponSlotsInfo //Defines attachment slots
 		{
			mass 																	= 50;
			class MuzzleSlot: MuzzleSlot
			{
				compatibleitems[] 													= {"muzzle_snds_65_TI_blk_F"};
			};
			class CowsSlot: CowsSlot
			{
                compatibleitems[]                   								= 
				{
					"optic_Nightstalker",//VANILLA START
					"optic_tws",
					"optic_tws_mg",
					"optic_NVS",
					"optic_DMS",
					"optic_LRPS",
					"optic_ams",
					"optic_AMS_snd",
					"optic_AMS_khk",
					"optic_KHS_blk",
					"optic_KHS_tan",
					"optic_KHS_hex",
					"optic_KHS_old",
					"optic_SOS",
					"optic_MRCO",
					"optic_Arco",
					"optic_aco",
					"optic_ACO_grn",
					"optic_aco_smg",
					"optic_ACO_grn_smg",
					"optic_hamr",
					"optic_Holosight",
					"optic_Holosight_smg",
					"optic_Hamr_khk_F",
					"optic_SOS_khk_F",
					"optic_Arco_ghex_F",
					"optic_Arco_blk_F",
					"optic_DMS_ghex_F",
					"optic_ERCO_blk_F",
					"optic_ERCO_khk_F",
					"optic_ERCO_snd_F",
					"optic_LRPS_ghex_F",
					"optic_LRPS_tna_F",
					"optic_Holosight_blk_F",
					"optic_Holosight_khk_F",
					"optic_Holosight_smg_blk_F",
					"optic_Holosight_smg_khk_F",//VANILLA END
					"OPTRE_M392_Scope",//OPTRE START
					"OPTRE_BR55HB_Scope", 
					"OPTRE_M7_Sight", 
					"OPTRE_M393_Scope",
					"OPTRE_M393_ACOG",
					"OPTRE_M393_EOTECH",//OPTRE END
					"OPTRE_HMG38_CarryHandle"
				};
			};
			class PointerSlot: PointerSlot
			{
				compatibleitems[] 													= {};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]													= {"bipod_01_F_blk", "bipod_02_F_blk", "bipod_03_F_blk"};
			};
 		};
		
        modes[] 																	= {"FullAuto","Single","close","short","medium","far"};
        class Single: Mode_SemiAuto
        {
            sounds[] 																= {"StandardSound","SilencedSound"};
            class BaseSoundModeType
            {
                    weaponSoundEffect 												= "DefaultRifle";
                    closure1[] 														= {};
                    closure2[] 														= {};
                    soundClosure[] 													= {"closure1",0.5,"closure2",0.5};
            };
            class StandardSound: BaseSoundModeType
            {
                    begin1[] 														= {"HMG_38\sound\HMGShotOutdoor1.wss",1.0,1,2000};
                    begin2[] 														= {"HMG_38\sound\HMGShotOutdoor2.wss",1.0,1,2000};
					begin3[] 														= {"HMG_38\sound\HMGShotOutdoor3.wss",1.0,1,2000};
                    soundBegin[] 													= {"begin1",0.34,"begin2",0.33,"begin3",0.33};
				class SoundTails
				{
					class TailTrees
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_trees",1.0,1,1400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_forest",1.0,1,1400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*forest";
					};
					class TailInterior
					{
						sound[] 													= {"HMG_38\sound\HMGShotIndoor1",1.5848932,1,1400};
						frequency 													= 1;
						volume 														= "interior";
					};
					class TailMeadows
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_meadows",1.0,1,1400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_houses",1.0,1,1400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*houses";
					};
				};
            };
            class SilencedSound: BaseSoundModeType
            {
				begin1[] 															= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_01",1.0,1,400};
				begin2[] 															= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_02",1.0,1,400};
				begin3[] 															= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_03",1.0,1,400};
				soundBegin[] 														= {"begin1",0.33,"begin2",0.33,"begin3",0.34};
				class SoundTails
				{
					class TailTrees
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_trees",1.0,1,400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_forest",1.0,1,400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*forest";
					};
					class TailInterior
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_tail_interior",1.0,1,400};
						frequency 													= 1;
						volume 														= "interior";
					};
					class TailMeadows
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_meadows",1.0,1,400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_houses",1.0,1,400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*houses";
					};
				};
            };
            reloadTime 																= 0.065;
            dispersion 																= 0.00075;
			recoil 																	= "recoil_single_trg";
			recoilProne 															= "recoil_single_prone_trg";
			minRange																= 2;
			minRangeProbab															= 0.0099999998;
			midRange																= 200;
			midRangeProbab															= 0.0099999998;
			maxRange																= 400;
			maxRangeProbab															= 0.0099999998;
        };
        class FullAuto: Mode_FullAuto
        {
			sounds[] 																= {"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect 													= "DefaultRifle";
				closure1[] 															= {};
				closure2[] 															= {};
				soundClosure[] 														= {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
                    begin1[] 														= {"HMG_38\sound\HMGShotOutdoor1.wss",1.0,1,2000};
                    begin2[] 														= {"HMG_38\sound\HMGShotOutdoor2.wss",1.0,1,2000};
					begin3[] 														= {"HMG_38\sound\HMGShotOutdoor3.wss",1.0,1,2000};
                    soundBegin[] 													= {"begin1",0.34,"begin2",0.33,"begin3",0.33};
				class SoundTails
				{
					class TailTrees
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_trees",1.0,1,1400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_forest",1.0,1,1400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*forest";
					};
					class TailInterior
					{
						sound[] 													= {"HMG_38\sound\HMGShotIndoor1",1.5848932,1,1400};
						frequency 													= 1;
						volume 														= "interior";
					};
					class TailMeadows
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_meadows",1.0,1,1400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_tail_houses",1.0,1,1400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*houses";
					};
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[] 															= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_01",1.0,1,400};
				begin2[] 															= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_02",1.0,1,400};
				begin3[] 															= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_short_03",1.0,1,400};
				soundBegin[] 														= {"begin1",0.33,"begin2",0.33,"begin3",0.34};
				class SoundTails
				{
					class TailTrees
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_trees",1.0,1,400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_forest",1.0,1,400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*forest";
					};
					class TailInterior
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_tail_interior",1.0,1,400};
						frequency 													= 1;
						volume 														= "interior";
					};
					class TailMeadows
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_meadows",1.0,1,400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] 													= {"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\Silencer_TRG20_Tail_houses",1.0,1,400};
						frequency 													= 1;
						volume 														= "(1-interior/1.4)*houses";
					};
				};
			};
			reloadTime 																= 0.2;
			dispersion 																= 0.00005;
			recoil 																	= "recoil_single_ebr";
			recoilProne 															= "recoil_single_prone_ebr";
			minRange 																= 2;
			minRangeProbab 															= 0.3;
			midRange 																= 300;
			midRangeProbab 															= 0.7;
			maxRange 																= 1000;
			maxRangeProbab 															= 0.05;
		};
		class close: FullAuto
		{
			burst																	= 5;
			aiRateOfFire															= 0.5;
			aiRateOfFireDistance													= 50;
			minRange																= 0;
			minRangeProbab 															= 0.050000001;
			midRange																= 30;
			midRangeProbab															= 0.69999999;
			maxRange																= 50;
			maxRangeProbab															= 0.039999999;
			showToPlayer															= 0;
		};
		class short: close
		{
			burst																	= 3;
			aiRateOfFire															= 2;
			aiRateOfFireDistance													= 300;
			minRange																= 50;
			minRangeProbab															= 0.050000001;
			midRange																= 150;
			midRangeProbab															= 0.69999999;
			maxRange																= 300;
			maxRangeProbab															= 0.039999999;
		};
		class medium: close
		{
			burst																	= 2;
			aiRateOfFire															= 4;
			aiRateOfFireDistance													= 600;
			minRange																= 200;
			minRangeProbab															= 0.050000001;
			midRange																= 400;
			midRangeProbab															= 0.60000002;
			maxRange																= 600;
			maxRangeProbab															= 0.1;
		};
		class far: close
		{
			burst																	= 1;
			aiRateOfFire															= 6;
			aiRateOfFireDistance													= 700;
			minRange																= 350;
			minRangeProbab															= 0.039999999;
			midRange																= 550;
			midRangeProbab															= 0.5;
			maxRange																= 700;
			maxRangeProbab															= 0.0099999998;
		};
	};
};