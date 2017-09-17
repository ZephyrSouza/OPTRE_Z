class Mode_SemiAuto;	// External class reference
class Mode_Burst;	// External class reference
class Mode_FullAuto;	// External class reference
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
	
class CfgWeapons
{
            class ItemCore;
            class InventoryOpticsItem_Base_F;
			class InventoryFlashLightItem_Base_F;
			class InventoryMuzzleItem_Base_F;
     
            //ATTACHMENTS
     
			class muzzle_snds_acp;
			class OPTRE_M395_MuzzleBase: muzzle_snds_acp
			{
				dlc = "OPTRE";
			   scope                                                                   = 2;
			   displayName                                                             = "M395 Muzzle";
			   picture = "\M395\icons\M395__Muzzle_Icon.paa";
			   model                                                                   = "\M395\M395BaseMuzzle.p3d";
			   descriptionShort                                                        = "M395 Muzzle";
			   inertia                                                                 = 0.1;
				class ItemInfo: InventoryMuzzleItem_Base_F
				{
					mass = 5;
					class MagazineCoef
					{
						initSpeed 		= 0.65;
					};
					class AmmoCoef
					{
						// bullet ballistic modifiers
						hit				= 1;
						typicalSpeed	= 1;
						airFriction		= 1;
					
						// AI modifiers
						visibleFire		= 0.5;
						audibleFire		= 0.3;
						visibleFireTime	= 0.5;
						audibleFireTime	= 0.5;
						cost			= 1;
					}; 
					muzzleEnd 			= "zaslehPoint"; // memory point in muzzle supressor's model
					alternativeFire 	= "muzzleFlash";  // class in cfgWeapons with model of muzzle flash	
					soundTypeIndex		= 0; /// defines the position in sound[] array in the rifle
					class MuzzleCoef
					{
						dispersionCoef			= 1;
						artilleryDispersionCoef	= 1;
		
						fireLightCoef			= 0.1f;

						recoilCoef				= 0.8f;
						recoilProneCoef			= 0.8f;

						minRangeCoef = 1.0f; minRangeProbabCoef = 1.0f;
						midRangeCoef = 1.0f; midRangeProbabCoef = 1.0f;
						maxRangeCoef = 1.0f; maxRangeProbabCoef = 1.0f;
					};			
				};
			};
            class OPTRE_M395_Scope: ItemCore
            {
					dlc = "OPTRE";
                    scope                                                                   = 2;
                    displayName                                                             = "M395 Optic";
					picture 																= "\M395\icons\M395__Scope_Icon.paa";
                    model                                                                   = "\M395\M395Optic.p3d";
                    descriptionShort                                                        = "M395 Optic";
                    weaponInfoType                                                          = "RscOptics_nightstalker";
                    modelOptics                                                     		= "\M395\M395Optic.p3d";
                    class ItemInfo: InventoryOpticsItem_Base_F
                    {
                            mass                                                            = 10;
                            opticType                                                       = 1;
                            optics                                                          = 1;
                            modelOptics                                                     = "\M395\M395Optic.p3d";
                            class OpticsModes
                            {
                                    class M395_Scope_View
                                    {
											opticsID = 1;
											useModelOptics = 1;
                                            opticsZoomMin                                   = 0.01;
                                            opticsZoomMax                                   = 0.25;
                                            opticsZoomInit                                  = 0.25;
											discretefov[] 									= {0.25,0.05,0.025,0.01};
											discreteinitIndex 								= 0;
											discreteDistance[] 								= {100,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
											discreteDistanceInitIndex 						= 1;
											distanceZoomMin 								= 100;
											distanceZoomMax 								= 2000;
                                            memoryPointCamera                               = "opticView";
                                            modelOptics[]                                   = {"\M395\M395_optic5.p3d"};
											opticsPPEffects[] 								= {"OpticsCHAbera1","OpticsBlur1"};
                                            visionMode[]                                    = {"Normal","NVG"};
											thermalMode[] 									= {5,6};
											opticsFlare 									= 1;
											opticsDisablePeripherialVision 					= 1;
                                    };
                            };
                    };
                    inertia                                                                 = 0;
            };
            //MainRifle	
	class Rifle_Long_Base_F;
	class DMR_02_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class srifle_DMR_02_F: DMR_02_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				iconPosition[]={0.40000001,0.69999999};
				iconScale=0.2;
			};
		};
	};
	class OPTRE_M395_DMR: srifle_DMR_02_F
	{
		dlc = "OPTRE";
		scope 										= 2;
		scopeArsenal 								= 2;
		handAnim[] 									= {"OFP2_ManSkeleton", "\M395\anim\Handanim_M395.rtm"};
		model										= "\M395\M395.p3d";
		displayName 								= "[OPTREZ] M395 DMR";
		descriptionShort 							= "UNSC Marksman Rifle";
		picture 									= "\M395\icons\M395_Icon.paa";
		selectionFireAnim    = "muzzleFlash";
		ODST_1																	= "OPTRE_ODST_HUD_AmmoCount_DMR";
		Glasses																	= "OPTRE_GLASS_HUD_AmmoCount_DMR";
		Eye																		= "OPTRE_EYE_HUD_AmmoCount_DMR";
		HUD_BulletInARows														= 1;
		HUD_TotalPosibleBullet													= 15;	
		magazines[] 								= {"OPTREZ_15Rnd_762x51_Mag","OPTREZ_15Rnd_762x51_Mag_Tracer"};
		drySound[] 									= {"A3\sounds_f\weapons\Other\dry_1",0.56234133,1,10};
		modelOptics 								= "-";
		dexterity 									= 3.25;
		muzzlePos									= "usti hlavne";
       	muzzleEnd									= "konec hlavne";
		reloadAction 								= "GestureReloadTRG";
		inertia										= 0.6;
		maxZeroing 									= 1000;
		discreteDistance[] 							= {100,200,300,400,500,600,700,800,900,1000};
		maxRecoilSway 								= 0.0125;
		swayDecaySpeed 								= 1.25;
		deployedPivot    							= "bipod";
		recoil = "recoil_mx";
		class GunParticles
		{
		   class SecondEffect
		   {
			positionName 							= "Nabojnicestart";
			directionName 							= "Nabojniceend";
			effectName 								= "CaselessAmmoCloud";
		   };
		};
		modes[] 									= {"Single"};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultRifle";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"M395\sound\DMR_1.ogg",2.5,1,1500};
				soundBegin[] = {"begin1",1};
				class SoundTails
				{
					class TailInterior
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_interior",2.2387211,1,1800};
						frequency = 1;
						volume = "interior";
					};
					class TailTrees
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_trees",1.0,1,1800};
						frequency = 1;
						volume = "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_forest",1.0,1,1800};
						frequency = 1;
						volume = "(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_meadows",1.0,1,1800};
						frequency = 1;
						volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\mx_tail_houses",1.0,1,1800};
						frequency = 1;
						volume = "(1-interior/1.4)*houses";
					};
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_01",0.7943282,1,400};
				begin2[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_02",0.7943282,1,400};
				begin3[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_03",0.7943282,1,400};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin1",0.34};
				class SoundTails
				{
					class TailInterior
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_tail_interior",1.0,1,400};
						frequency = 1;
						volume = "interior";
					};
					class TailTrees
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_trees",1.0,1,400};
						frequency = 1;
						volume = "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_forest",1.0,1,400};
						frequency = 1;
						volume = "(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_meadows",1.0,1,400};
						frequency = 1;
						volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_mx_tail_houses",1.0,1,400};
						frequency = 1;
						volume = "(1-interior/1.4)*houses";
					};
				};
			};
			reloadTime = 0.041;
			dispersion = 0.00005;
			recoil = "recoil_single_mx";
			recoilProne = "recoil_single_prone_mx";
			minRange = 2;
			minRangeProbab = 0.3;
			midRange = 300;
			midRangeProbab = 0.7;
			maxRange = 1000;
			maxRangeProbab = 0.05;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo //Defines attachment slots
 		{
			class MuzzleSlot: MuzzleSlot
			{
				access 								= 1;
				compatibleitems[] 					= {"OPTRE_M395_MuzzleBase"};
				displayname 						= "Muzzle Slot";
				linkproxy 							= "\A3\data_f\proxies\weapon_slots\MUZZLE";
				scope 								= 2;
			};
			class CowsSlot: CowsSlot
			{
                compatibleitems[]                    = 
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
					"OPTRE_M395_Scope",
					"OPTRE_SRS99_Scope"//OPTRE END
				};
				linkproxy 							= "\A3\data_f\proxies\weapon_slots\TOP";
			};
			class PointerSlot: PointerSlot
			{
				compatibleitems[] 					= {};
				linkproxy 							= "\A3\data_f\proxies\weapon_slots\SIDE";
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]					= {"bipod_01_F_blk", "bipod_02_F_blk", "bipod_03_F_blk"};
				linkProxy 							= "\A3\Data_F_Mark\Proxies\Weapon_Slots\UNDERBARREL";
			};
			mass = 75;
 		};
	};
};