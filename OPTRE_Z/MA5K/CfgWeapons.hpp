class Mode_SemiAuto;
class Mode_FullAuto; /*external*/

class CfgWeapons 
{
	class InventoryOpticsItem_Base_F; // external 
	class ItemCore; // external 
	
	class OPTREZ_MA5K_base 
	{
		ace_overheating_mrbs = 20000; //Mean Rounds Between Stoppages (this will be scaled based on the barrel temp)
        ace_overheating_slowdownFactor = 1; //Slowdown Factor (this will be scaled based on the barrel temp)
        ace_overheating_allowSwapBarrel = 0; // 1 to enable barrel swap. 0 to disable. Meant for machine guns where you can easily swap the barrel without dismantling the whole weapon.
        ace_overheating_dispersion = 0.75; //Dispersion Factor (this will be scaled based on the barrel temp)
		pictureWire = "\OPTRE_Weapons\data\Pictures\WireWeaponIcons\Prime\Sniper\SNIPER.paa";
		ODST_1    = "OPTRE_ODST_HUD_AmmoCount_Snipor";
		Glasses    = "OPTRE_GLASS_HUD_AmmoCount_Snipor"; 
		Eye    = "OPTRE_ODST_EYE_AmmoCount_Snipor";
		HUD_BulletInARows = 4;
		HUD_TotalPosibleBullet    = 4;
		access = 3;
		afmax = 0;
		aidispersioncoefx = 4;
		aidispersioncoefy = 5;
		airateoffire = 0.5;
		airateoffiredistance = 500;
		ammo = "";
		autofire = 1;
		autoreload = 0;
		backgroundreload = 0;
		ballisticscomputer = 0;
		bullet1[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_01",0.794328,1,15};
		bullet10[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_02",0.707946,1,15};
		bullet11[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_03",0.707946,1,15};
		bullet12[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_04",0.707946,1,15};
		bullet2[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_02",0.794328,1,15};
		bullet3[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_03",0.794328,1,15};
		bullet4[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_04",0.794328,1,15};
		bullet5[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_01",0.794328,1,15};
		bullet6[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_02",0.794328,1,15};
		bullet7[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_03",0.794328,1,15};
		bullet8[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_04",0.794328,1,15};
		bullet9[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_01",0.707946,1,15};		
		candrop = 1;
		canlock = 0;
		canshootinwater = 0;
		cartridgepos = "nabojnicestart";
		cartridgevel = "nabojniceend";
		count = 0;
		cursor = "arifle";
		cursoraim = "CursorAim";
		cursoraimon = "";
		cursorsize = 1;
		cmimmunity = 1;
		descriptionshort = "Sub Machinegun<br />Caliber: 11.43×23mm";
		detectrange = 0;
		dexterity = 1.64;
		discretedistance[] = {100, 300, 400, 600, 800};
		discretedistanceinitindex = 1;
		dispersion = 0.0001;
		displayname = "[UNSC] MA5K";
		disposableweapon = 0;
		distancezoommax = 300;
		distancezoommin = 300;
		drySound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_dry",0.562341,1,15};
		emptysound[] = {"", 1, 1};
		enableattack = 1;
		ffcount = 3;
		fffrequency = 11;
		ffmagnitude = 0.5;
		fireanims[] = {};
		firelightduration = 0.05;
		firelightintensity = 0.012;
		firespreadangle = "3.0f";
		flash = "muzzleFlash";
		flashsize = 0.5;
		forceoptics = 0;
		handanim[] = {"OFP2_ManSkeleton","MA5K\anim\Handanim_MA5K.rtm"};
		hiddenselections[] = {};
		hiddenselectionstextures[] = {};
		hiddenunderwaterselections[] = {};
		hiddenunderwaterselectionstextures[] = {};
		htmax = 600;
		htmin = 1;
		initspeed = 0;
		irdistance = 0;
		irdotintensity = 0.001;
		irlaserend = "laser dir";
		irlaserpos = "laser pos";
		laser = 0;
		lockacquire = 1;
		lockedtargetsound[] = {"\A3\sounds_f\dummysound", 0.000316228, 6};
		lockingtargetsound[] = {"\A3\sounds_f\dummysound", 0.000316228, 2};
		magazinereloadtime = 0;
		magazines[] = {"MA5K_60Rnd_762x39_B_Stanag", "MA5K_60Rnd_762x39_T_Stanag"};
		maxleadspeed = 23;
		maxrange = 500;
		maxrangeprobab = 0.04;
		maxrecoilsway = 0.008;
		memorypointcamera = "eye";
		mfact = 1;
		mfmax = 0;
		midrange = 150;
		midrangeprobab = 0.58;
		minrange = 1;
		minrangeprobab = 0.3;
		model = "Ma5K\MA5K";
		modelmagazine = "";
		modeloptics = "-";
		modelspecial = "";
		multiplier = 1;
		muzzleend = "konec hlavne";
		muzzlepos = "usti hlavne";
		muzzles[] = {"this"};
		namesound = "rifle";
		optics = 0;
		opticsdisableperipherialvision = 0.67;
		opticsflare = 0;
		opticsid = 0;
		opticsppeffects[] = {};
		opticszoominit = 0.75;
		opticszoommax = 1.1;
		opticszoommin = 0.375;
		picture = "\MA5K\UI\MainBody_Icon";
		primary = 10;
		recoil = "recoil_smg_01";
		recoilprone = "assaultRifleBase";
		reloadaction = "GestureReloadKatiba";
		reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons\SMG\Vermin\reload_vermin",1,1,10};
		reloadsound[] = {"", 1, 1};
		reloadtime = .05;
		scope = 2;
		selectionfireanim = "zasleh";
		showaimcursorinternal = 1;
		showempty = 1;
		shownunderwaterselections[] = {};
		showswitchaction = 0;
		showtoplayer = 1;
		simulation = "Weapon";
		sound[] = {};
		soundbegin[] = {"sound", 1};
		soundbeginwater[] = {"sound", 1};
		soundbullet[] = {"bullet1", 0.083, "bullet2", 0.083, "bullet3", 0.083, "bullet4", 0.083, "bullet5", 0.083, "bullet6", 0.083, "bullet7", 0.083, "bullet8", 0.083, "bullet9", 0.083, "bullet10", 0.083, "bullet11", 0.083, "bullet12", 0.083};
		soundburst = 1;
		soundclosure[] = {"sound", 1};
		soundcontinuous = 0;
		soundend[] = {"sound", 1};
		soundloop[] = {"sound", 1};
		swaydecayspeed = 2;
		tbody = 100;
		texturetype = "default";
		type = 1;
		uipicture = "\A3\weapons_f\data\UI\icon_regular_CA.paa";
		useaction = 0;
		useactiontitle = "";
		useasbinocular = 0;
		usemodeloptics = 1;
		value = 4;
		weaponinfotype = "RscWeaponZeroing";
		weaponlockdelay = 0;
		weaponlocksystem = 0;
		weaponpoolavailable = 1;
		weaponsoundeffect = "";
		weight = 0;
		class Library {
			libtextdesc = "The UMP has been adopted by various agencies such as the U.S. Customs and Border Protection. Heckler & Koch developed the UMP as a lighter and cheaper successor to the MP5, though both remain in production.";
		};
		
		class GunClouds {
			access = 0;
			cloudletaccy = 0;
			cloudletalpha = 0.3;
			cloudletanimperiod = 1;
			cloudletcolor[] = {1, 1, 1, 0};
			cloudletduration = 0.05;
			cloudletfadein = 0;
			cloudletfadeout = 0.1;
			cloudletgrowup = 0.05;
			cloudletmaxyspeed = 100;
			cloudletminyspeed = -100;
			cloudletshape = "cloudletClouds";
			cloudletsize = 1;
			deltat = 0;
			initt = 0;
			interval = -0.02;
			size = 0.3;
			sourcesize = 0.02;
			timetolive = 0;
			class Table {
				class T0 {
					color[] = {1, 1, 1, 0};
					maxt = 0;
				};
			};
		};
		class WeaponSlotsInfo {
			allowedslots[] = {901};
			mass = 4;
			class MuzzleSlot {
				access = 1;
				compatibleitems[] = {"muzzle_snds_L"};
				displayname = "Muzzle Slot";
				linkproxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				scope = 0;
			};
			class CowsSlot {
				access = 1;
				compatibleitems[] = {""};
				displayname = "Optics Slot";
				linkproxy = "\A3\data_f\proxies\weapon_slots\TOP";
				scope = 2;
			};
			class PointerSlot {};
		};	
                class ItemInfo
                {
                        priority = 1;
                        RMBhint = "XMX";
                        onHoverText = "TODO XMX DSS";
                };

		class GunParticles {
			class FirstEffect {
				directionname = "Konec hlavne";
				effectname = "RifleAssaultCloud";
				positionname = "Usti hlavne";
			};
		};
		
		
					 /*
						I've added the new stuff bellow and deleted what was here before. 
					 */
                    modes[] = {"Single","FullAuto"}; // Firing modes such as must have a defined class bellow "Single", "Burst"
					
                    class Single: Mode_SemiAuto // here we create a sub class for a our single fire mode, all we need for this weapon is single fire and silenced this is what you double clicked on in the lynx called "single"
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
								begin1[] 														= {"\MA5K\sound\AssaultRifle_1.wss",1.0,1,2000};
								begin2[] 														= {"\MA5K\sound\AssaultRifle_2.wss",1.0,1,2000}; 
                                    soundBegin[] = {"begin1",0.34,"begin2",0.33};
									class SoundTails
									{
										class TailForest
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_forest",1.0,1,2200};
											frequency = 1;
											volume = "(1-interior/1.4)*forest";
										};
										class TailHouses
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_houses",1.0,1,2200};
											frequency = 1;
											volume = "(1-interior/1.4)*houses";
										};
										class TailInterior
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_interior",1.9952624,1,2200};
											frequency = 1;
											volume = "interior";
										};
										class TailMeadows
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_meadows",1.0,1,2200};
											frequency = 1;
											volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
										};
										class TailTrees
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_trees",1.0,1,2200};
											frequency = 1;
											volume = "(1-interior/1.4)*trees";
										};
									};
                            };
							class SilencedSound: BaseSoundModeType
							{
								begin1[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_01",1.0,1,300};
								begin2[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_02",1.0,1,300};
								begin3[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_03",1.0,1,300};
								soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
								class SoundTails
								{
									class TailInterior
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",1.0,1,300};
										frequency = 1;
										volume = "interior";
									};
									class TailTrees
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",1.0,1,300};
										frequency = 1;
										volume = "(1-interior/1.4)*trees";
									};
									class TailForest
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",1.0,1,300};
										frequency = 1;
										volume = "(1-interior/1.4)*forest";
									};
									class TailMeadows
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",1.0,1,300};
										frequency = 1;
										volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
									};
									class TailHouses
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",1.0,1,300};
										frequency = 1;
										volume = "(1-interior/1.4)*houses";
									};
								};
							};
                            reloadtime = .05;			//0.6
                            dispersion = 0.00015;
							recoil = "recoil_smg_01";
							recoilprone = "assaultRifleBase";
                            minRange = 2;
                            minRangeProbab = 0.25;
                            midRange = 800;
                            midRangeProbab = 0.75;
                            maxRange = 2000;
                            maxRangeProbab = 0.25;
                    };
                    class FullAuto: Mode_FullAuto // here we create a sub class for a our single fire mode, all we need for this weapon is single fire and silenced this is what you double clicked on in the lynx called "single"
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
								begin1[] 														= {"\MA5K\sound\AssaultRifle_1.wss",1.0,1,2000};
								begin2[] 														= {"\MA5K\sound\AssaultRifle_2.wss",1.0,1,2000}; 
                                    soundBegin[] = {"begin1",0.34,"begin2",0.33};
									class SoundTails
									{
										class TailForest
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_forest",1.0,1,2200};
											frequency = 1;
											volume = "(1-interior/1.4)*forest";
										};
										class TailHouses
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_houses",1.0,1,2200};
											frequency = 1;
											volume = "(1-interior/1.4)*houses";
										};
										class TailInterior
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_interior",1.9952624,1,2200};
											frequency = 1;
											volume = "interior";
										};
										class TailMeadows
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_meadows",1.0,1,2200};
											frequency = 1;
											volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
										};
										class TailTrees
										{
											sound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\GM6_Lynx\GM6_tail_trees",1.0,1,2200};
											frequency = 1;
											volume = "(1-interior/1.4)*trees";
										};
									};
                            };
							class SilencedSound: BaseSoundModeType
							{
								begin1[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_01",1.0,1,300};
								begin2[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_02",1.0,1,300};
								begin3[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_03",1.0,1,300};
								soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
								class SoundTails
								{
									class TailInterior
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",1.0,1,300};
										frequency = 1;
										volume = "interior";
									};
									class TailTrees
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",1.0,1,300};
										frequency = 1;
										volume = "(1-interior/1.4)*trees";
									};
									class TailForest
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",1.0,1,300};
										frequency = 1;
										volume = "(1-interior/1.4)*forest";
									};
									class TailMeadows
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",1.0,1,300};
										frequency = 1;
										volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
									};
									class TailHouses
									{
										sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",1.0,1,300};
										frequency = 1;
										volume = "(1-interior/1.4)*houses";
									};
								};
							};
                            reloadtime = .05;			//0.6
                            dispersion = 0.00015;
							recoil = "recoil_smg_01";
							recoilprone = "assaultRifleBase";
                            minRange = 2;
                            minRangeProbab = 0.25;
                            midRange = 800;
                            midRangeProbab = 0.75;
                            maxRange = 2000;
                            maxRangeProbab = 0.25;
                    };
	};

	class OPTRE_SRS99dd_Scope: ItemCore
    {
		dlc = "OPTRE";
        scope                                                                   = 2;
        displayName                                                             = "[UNSC] Oracle N-variant SRS99C Scope";
		picture 																= "SRS99C\UI\gear_srs99c_Scope_x_CA.paa";
        model                                                                   = "SRS99C\SR99C_Scope.p3d";
        descriptionShort                                                        = "Oracle N-variant SRS99D Sniper Rifle 5-10x56 Scope";
        weaponInfoType                                                          = "RscOptics_nightstalker";
        modelOptics                                                     		= "SRS99C\SR99C_Scope.p3d";       
		inertia                                                                 = 0;		
		class ItemInfo: InventoryOpticsItem_Base_F
        {
            mass                                                            = 10;
            opticType                                                       = 1;
            optics                                                          = 1;
            modelOptics                                                     = "SRS99C\SR99C_Scope.p3d";
            class OpticsModes
            {
                class SRS99_Scope_View
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
					modelOptics[]                                   = {"SRS99C\Sniper_Oracle10_Optic"};
					opticsPPEffects[] 								= {"OpticsCHAbera1","OpticsBlur1"};
					visionMode[]                                    = {"Normal","NVG","TI"};
					thermalMode[] 									= {5,6};
					opticsFlare 									= 1;
					opticsDisablePeripherialVision 					= 1;
				};
            };
        };
    };
};