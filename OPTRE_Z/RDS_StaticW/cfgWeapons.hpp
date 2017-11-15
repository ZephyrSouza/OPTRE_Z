#define RHA(mm,speed) caliber=(mm/((15*speed)/1000));
class Mode_SemiAuto;
class Mode_Burst;

class CfgAmmo
{
	class BulletCore;
	class BulletBase: BulletCore {};
	class B_35mm_AA;
	class RDS_B_23mm_AA: B_35mm_AA //2 bullets at once
	{
		hit=84;indirectHit=30;indirectHitRange=0.3;
		visibleFire=32;
		audibleFire=32;
		visibleFireTime=4;
		explosive = 0.6;
		airLock=1;
		cost = 150;

		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
		tracerScale=1.85;
		tracerStartTime = 0.1; // seconds
		tracerEndTime = 2; // seconds

		airFriction = -0.000824;
		muzzleEffect = "";
		caliber = 1.11;
	};

	class RDS_B_127x107_Ball: BulletBase
	{
		hit=28;indirectHit=0;indirectHitRange=0;
		cartridge="FxCartridge_127";
		visibleFire=20;
		audibleFire=22;
		visibleFireTime=3;
		cost = 20;
		airLock=1;
		caliber = 2.07;

		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
		tracerScale=1.5;
		tracerStartTime = 0.1; // seconds
		tracerEndTime = 2.3; // seconds

		airFriction = -0.0006;
	};
	class RDS_B_127x108_Ball: BulletBase
	{
		hit=30;indirectHit=0;indirectHitRange=0;
		cartridge="FxCartridge_127";
		visibleFire=21;
		audibleFire=22;
		visibleFireTime=3;
		cost = 20;
		airLock=1;
		airFriction = -0.00055;
		muzzleEffect = "BIS_Effects_HeavySniper";
		caliber = 2.07;
	};
	class RDS_B_127x108_APHE: BulletBase
	{
		hit=24;indirectHit=5;indirectHitRange=0.1;
		cartridge="FxCartridge_127";
		visibleFire=22;
		audibleFire=22;
		explosive = 0.1;
		visibleFireTime=3;
		cost = 20;
		airLock=1;
		model="\A3\Weapons_f\Data\bullettracer\tracer_green";
		tracerScale=1.5;
		tracerStartTime = 0.05; // seconds
		tracerEndTime = 2.3; // seconds
		airFriction = -0.00055;
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ExploAmmoExplosion";
		muzzleEffect = "BIS_Effects_HeavyCaliber";
		caliber = 2.07;
	};
	class G_40mm_HE;
	class RDS_G_30mm_HE: G_40mm_HE {
		caliber = 1.5;
		hit = 8;
		indirecthit = 10;
		indirecthitrange = 5.5;
		whistledist = 5.5;
	};
	class MissileBase;
	class M_Titan_AA: MissileBase {};
	class RDS_M_Strela_AA: M_Titan_AA // Strela-2M
	{
		//model=\ca\weapons\strela_Rocket;
		hit=66;indirectHit=50;indirectHitRange=8;
		maneuvrability=10;
		simulationStep = 0.002;
		trackOversteer = 0.75;
		trackLead = 0;
		airLock=true;
		irLock = true;
		cost=7500;
		maxSpeed=580; // m/s
		initTime = 0.250000;
		thrustTime = 1.5;
		thrust = 609;
		fuseDistance = 120;
		timeToLive = 15;
		CraterEffects = "AAMissileCrater";
		explosionEffects = "AAMissileExplosion";
//		smokeTrail = 3;
		effectsMissile = "missile3";
		whistleDist = 16;
	};
	class RDS_M_Igla_AA: RDS_M_Strela_AA
	{
		hit=70;indirectHit=50;indirectHitRange=8; // same as Stinger, stronger than strela
		maneuvrability=14;
		trackOversteer = 0.85;
		sideAirFriction = 0.75;
		cost=10000;
		maxSpeed=800;
		initTime = 0.250000;
		thrust = 840;
	};
	class M_Titan_AT: MissileBase {};
	class RDS_M_AT5_AT: M_Titan_AT //AT-5 Spandrel /Konkurs 9M113
	{
		hit=480;indirectHit=12;indirectHitRange=1.2; // 600mm vs RHA
		irLock=true;

		manualControl=true;
		maxControlRange=4000;
		trackOversteer = 0.95;
		trackLead = 0.9;
		maneuvrability = 8;

		timeToLive = 25;
		simulationStep = 0.005000;
		sideAirFriction = 0.050000;
		maxSpeed = 200;
		initTime = 0.25;
		thrustTime = 1.500000;
		thrust = 210;
		deflecting = 0;
		fuseDistance = 5;
		whistleDist = 2;
	};
	class RDS_M_AT13_AT: RDS_M_AT5_AT //AT-13 Saxhorn-2 / Metis-M 9K115-2
	{
		hit=670;indirectHit=16;indirectHitRange=1.5; // tandem warhead, 850mm RHA
		whistleDist = 3;
	};
	class RDS_M_TOW_AT: M_Titan_AT
	{
		model = "\RDS_StaticW\TOW\tow";
		hit = 580;
		indirectHit = 12;
		indirectHitRange = 1.2;
		cost = 8000;
		irLock = 1;
		manualControl = 1;
		trackOversteer = 0.95;
		trackLead = 0.9;
		timeToLive = 9;
		maneuvrability = 10;
		simulationStep = 0.005;
		sideAirFriction = 0.05;
		maxControlRange = 3750;
		maxSpeed = 296;
		initTime = 0.151;
		thrustTime = 1.45;
		thrust = 300;
		deflecting = 0;
		fuseDistance = 5;
		effectsMissile = "missile2";
		whistleDist = 2;
	};
	class RDS_M_TOW2_AT: RDS_M_TOW_AT
	{
		hit = 850;
		indirectHit = 20;
		indirectHitRange = 2;
		maxSpeed = 329;
		thrust = 334;
		whistleDist = 4;
	};


	class RocketCore;
	class RocketBase: RocketCore{};
	class RDS_R_PG9_AT: RocketBase
	{
		hit=320;indirectHit=10;indirectHitRange=1;
		model=\RDS_StaticW\SPG9\PG9_Projectile;
		initTime = 0.05;
		timeToLive=3;
		cost=400;
		maxSpeed=700;
		thrustTime=1;
		thrust=500;
		fuseDistance = 5;
		CraterEffects = "ATRocketCrater";
		explosionEffects = "ATRocketExplosion";
		smokeTrail = 2;
		effectsMissile = "missile2";
		whistleDist = 2;
		effectsmissileinit = "RocketBackEffectsStaticRPG";
	};
	class RDS_R_OG9_HE: RDS_R_PG9_AT
	{
		hit=120;indirectHit=30;indirectHitRange=10;
		model=\RDS_StaticW\SPG9\OG9_Projectile;
		cost=200;
		fuseDistance = 12;
		CraterEffects = "ATRocketCrater";
		explosionEffects = "ATRocketExplosion";
		whistleDist = 20;
	};
	class ShellCore;
	class ShellBase: ShellCore {};
	class Sh_155mm_AMOS: ShellBase {};
	class RDS_Sh_122_HE: Sh_155mm_AMOS
	{
		cost=100;
		artilleryLock = 1;
		hit = 300;
		indirectHit = 105;
		indirectHitRange = 28;
	};
	class RDS_Sh_122_WP: RDS_Sh_122_HE
	{
		hit = 60;
		indirectHit = 50;
		indirectHitRange = 30;
		explosive = 0.8;
		ExplosionEffects = "WPExplosion";
		CraterEffects = "ExploAmmoCrater";
		//soundHit[] = {"\ca\weapons\data\sound\explosion\grenade_new1",3.16228,1};
	};
	class Sh_155mm_AMOS_LG;
	class RDS_Sh_122_LASER: Sh_155mm_AMOS_LG {};
	class Flare_82mm_AMOS_White;
	class RDS_Sh_122_ILLUM: Flare_82mm_AMOS_White
	{
		hit = 8;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		ExplosionEffects = "";
		soundHit[] = {"",0,1};
		CraterEffects = "";
		whistleDist = 0;
	};
	class Smoke_120mm_AMOS_White;
	class RDS_Sh_122_SMOKE: Smoke_120mm_AMOS_White
	{
		hit = 8;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0.1;
		ExplosionEffects = "";
		soundHit[] = {"",0,1};
		CraterEffects = "";
		whistleDist = 0;
	};
	class Sh_120mm_APFSDS;
	class RDS_Sh_122_AT: Sh_120mm_APFSDS
	{
		allowAgainstInfantry=1;
		airfriction = "-3.96e-005";
		hit = 350;
		RHA(530,740)
		typicalspeed = 740;
		model = "\A3\Weapons_f\Data\bullettracer\shell_tracer_green";
	};

	class RDS_Sh_105_HE: Sh_155mm_AMOS
	{
		artilleryLock = 1;
		hit = 260;
		indirectHit = 85;
		indirectHitRange = 25;
	};

	class RDS_Sh_105_WP: RDS_Sh_105_HE
	{
		hit = 60;
		indirectHit = 50;
		indirectHitRange = 30;
		explosive = 0.8;
		ExplosionEffects = "WPExplosion";
		CraterEffects = "ExploAmmoCrater";
	};
	class RDS_Sh_105_LASER: Sh_155mm_AMOS_LG {};
	class RDS_Sh_105_ILLUM: Flare_82mm_AMOS_White
	{
		hit = 8;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		ExplosionEffects = "";
		soundHit[] = {"",0,1};
		CraterEffects = "";
		whistleDist = 0;
	};
	class RDS_Sh_105_SMOKE: Smoke_120mm_AMOS_White
	{
		hit = 8;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0.1;
		ExplosionEffects = "";
		soundHit[] = {"",0,1};
		CraterEffects = "";
		whistleDist = 0;
	};
};

class CfgMagazines
{
	class Default;
	class CA_Magazine: Default{};
	class VehicleMagazine: CA_Magazine{};
	class RDS_2000Rnd_23mm_AZP85: VehicleMagazine
	{
		scope=2;
		displayName="23mm AZP-85";
		ammo="RDS_B_23mm_AA";
		count=2000;
		initSpeed=980;
		maxLeadSpeed=600;
		tracersEvery=3;
		nameSound="cannon";
	};
	class RDS_40Rnd_23mm_AZP85: RDS_2000Rnd_23mm_AZP85
	{
		count=100;
	};

	class RDS_50Rnd_127x107_DSHKM: VehicleMagazine
	{
		scope = public;
		displayName = $STR_DN_DSHKM;
		ammo=RDS_B_127x107_Ball;
		count=50;
		initSpeed = 850;
		maxLeadSpeed=200;
		tracersEvery= 3;
		lastRoundsTracer = 5;
		nameSound="mgun";
	};
	class RDS_150Rnd_127x107_DSHKM: RDS_50Rnd_127x107_DSHKM
	{
		count=150;
	};
	class RDS_150Rnd_127x108_KORD: RDS_150Rnd_127x107_DSHKM
	{
		displayName = $STR_DN_KORD;
	};
	class RDS_50Rnd_127x108_KORD: RDS_50Rnd_127x107_DSHKM
	{
		displayName = $STR_DN_KORD;
	};
	class RDS_29Rnd_30mm_AGS30: VehicleMagazine
	{
		scope = public;
		displayName = High Explosive;
		ammo=RDS_G_30mm_HE;
		count=29;
		initSpeed = 185;
		maxLeadSpeed=100;
		nameSound="grenadelauncher";
	};
	class RDS_6Rnd_AT13: VehicleMagazine
	{
		scope = public;
		displayName = $STR_MN_AT13;
		ammo=RDS_M_AT13_AT;
		initSpeed = 55.1688;
		count=6;
		maxLeadSpeed=10;
		nameSound="missiles";
	};
	class CA_LauncherMagazine: CA_Magazine{};
	class RDS_PG9_AT: CA_LauncherMagazine
	{
		scope = 2;
		model="\RDS_StaticW\SPG9\PG9";
		displayName = $STR_MN_PG9;
		ammo=RDS_R_PG9_AT;
		count = 1;
		//picture="\CA\weapons\Data\Equip\m_pg9_ca.paa";
		type = 3 * 256; //3 * WeaponSlotItem
		initSpeed = 435;
		nameSound="sabot";
	};
	class RDS_OG9_HE: CA_LauncherMagazine
	{
		scope = 2;
		model="\RDS_StaticW\SPG9\OG9";
		displayName = $STR_MN_OG9;
		ammo=RDS_R_OG9_HE;
		count = 1;
		//picture="\CA\weapons\data\equip\M_og9_CA.paa";
		type = 3 * 256; //3 * WeaponSlotItem
		initSpeed = 316;
		nameSound="heat";
	};
	class RDS_Strela : CA_LauncherMagazine
	{
		scope = public;
		displayName = $STR_MN_9K32;
		ammo=RDS_M_Strela_AA;
		type = 6 * WeaponSlotItem;
		//picture="\CA\weapons\data\equip\m_strela_ca.paa";
		//modelSpecial = "\ca\weapons\strela_launcher_loaded";
		//model = "\ca\weapons\strela_proxy";
		initSpeed = 40;
		descriptionShort = $STR_DSS_1Rnd_Strela;
		maxLeadSpeed=320;  // BX, let AA soldiers attack chopers in cruise speed
	};
	class RDS_Igla : RDS_Strela
	{
		displayName = $STR_MN_IGLA;
		ammo=RDS_M_Igla_AA;
		type = 6 * WeaponSlotItem;
		//picture="\Ca\weapons\IGLA\Data\equip\M_IGLA_CA.paa"; //TODO
		modelSpecial = "\RDS_StaticW\igla\igla_loaded";
		model = "\RDS_StaticW\igla\igla";
		maxLeadSpeed = 320;
		descriptionShort = $STR_DSS_1Rnd_IGLA;
	};
	class RDS_2Rnd_Igla:RDS_Igla
	{
		count = 2;
	};
	class 32Rnd_155mm_Mo_shells;
	class RDS_30Rnd_122mmHE_D30: 32Rnd_155mm_Mo_shells //VehicleMagazine
	{
		scope = 2;
		displayName = "3OF56 HE";
		ammo = "RDS_Sh_122_HE";
		count = 30;
		nameSound = "heat";
		//initSpeed = 389;
		displayNameShort = "FRAG HE";
	};
	class RDS_30Rnd_122mmWP_D30: RDS_30Rnd_122mmHE_D30
	{
		displayName = "122mm WP";
		displayNameShort = "WP";
		ammo = "RDS_Sh_122_WP";
	};
	class RDS_30Rnd_122mmLASER_D30: RDS_30Rnd_122mmHE_D30
	{
		displayName = "3OF69M Laser Guided";
		displayNameShort = "Laser Guided";
		ammo = "RDS_Sh_122_LASER";
	};
	class RDS_30Rnd_122mmSMOKE_D30: RDS_30Rnd_122mmHE_D30
	{
		displayName = "D-462 Smoke";
		displayNameShort = "Smoke";
		ammo = "RDS_Sh_122_SMOKE";
	};
	class RDS_30Rnd_122mmILLUM_D30: RDS_30Rnd_122mmHE_D30
	{
		displayName = "S-463 Ilumination";
		displayNameShort = "Ilumination";
		ammo = "RDS_Sh_122_ILLUM";
	};
	class RDS_30Rnd_122mmAT_D30: RDS_30Rnd_122mmHE_D30
	{
		displayName = "BK-6M HEAT";
		displayNameShort = "HEAT";
		ammo = "RDS_Sh_122_AT";
		initSpeed = 740;
	};

	class RDS_30Rnd_105mmHE_M119: 32Rnd_155mm_Mo_shells //VehicleMagazine
	{
		scope = 2;
		displayName = "M1 HE";
		ammo = "RDS_Sh_105_HE";
		count = 30;
		nameSound = "heat";
		//initSpeed = 389;
		displayNameShort = "FRAG HE";
	};
	class RDS_30Rnd_105mmWP_M119: RDS_30Rnd_105mmHE_M119
	{
		displayName = "M60A2 WP";
		displayNameShort = "WP";
		ammo = "RDS_Sh_105_WP";
	};
	class RDS_30Rnd_105mmLASER_M119: RDS_30Rnd_105mmHE_M119
	{
		displayName = "M67 AT Laser Guided";
		displayNameShort = "Laser Guided";
		ammo = "RDS_Sh_105_LASER";
	};
	class RDS_30Rnd_105mmSMOKE_M119: RDS_30Rnd_105mmHE_M119
	{
		displayName = "M84 Smoke";
		displayNameShort = "Smoke";
		ammo = "RDS_Sh_105_SMOKE";
	};
	class RDS_30Rnd_105mmILLUM_M119: RDS_30Rnd_105mmHE_M119
	{
		displayName = "M314 Ilumination";
		displayNameShort = "Ilumination";
		ammo = "RDS_Sh_105_ILLUM";
	};



	class RDS_48Rnd_40mm_MK19: VehicleMagazine
	{
		scope = 2;
		displayName = "Mk. 19 40mm";
		ammo = "G_40mm_HE";
		count = 48;
		initSpeed = 240;
		maxLeadSpeed = 100;
		nameSound = "grenadelauncher";
	};

	class RDS_6Rnd_TOW_HMMWV: VehicleMagazine
	{
		scope = 2;
		displayName = "BGM-71A TOW";
		ammo = "RDS_M_TOW_AT";
		initSpeed = 55.1688;
		count = 6;
		maxLeadSpeed = 10;
		nameSound = "missiles";
	};
	class RDS_2Rnd_TOW: RDS_6Rnd_TOW_HMMWV
	{
		count = 2;
	};
	class RDS_6Rnd_TOW2: RDS_6Rnd_TOW_HMMWV
	{
		ammo = "RDS_M_TOW2_AT";
		displayName = "BGM-71E TOW-2A";
	};
	class RDS_2Rnd_TOW2: RDS_6Rnd_TOW2
	{
		count = 2;
	};

};

class cfgWeapons
{

	class MGunCore;
	class MGun: MGunCore {};
	class GMG_F: MGun {};
	class GMG_20mm: GMG_F {};
	class CannonCore;
	class MissileLauncher;
	class RDS_2A14: CannonCore
	{
		scope=1;
		displayName="2A14";
		nameSound="cannon";
		cartridgePos="cartridge_pos";
		cartridgeVel="cartridge_dir";
		cursor="emptyCursor";
		cursorAim="mg";
		cursorAimOn="";
		cursorSize=1;
		canLock=2;
		class gunParticles
		{
			class effect1
			{
				positionName="cartridge_pos";
				directionName="cartridge_dir";
				effectName="MachineGunCartridge1";
			};
		};
		magazines[]=
		{
			"RDS_40Rnd_23mm_AZP85",
			"RDS_2000Rnd_23mm_AZP85"
		};
		magazineReloadTime=9;
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		class manual: CannonCore
		{
			displayName="2A14";
			autoFire=1;
			sounds[] = {StandardSound};
 			class StandardSound
 			{
				weaponSoundEffect = "DefaultRifle";
				begin1[] = {"\RDS_StaticW\zu23\Data\Sound\2a14_1shot",1,1,1400};
				soundBegin[] = {"begin1",1};
			};
			reloadTime=0.059999999;
			dispersion=0.00050000002;
			multiplier=2;
			soundContinuous=0;
			showToPlayer=1;
			burst=1;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=50;
			minRange=1;
			minRangeProbab=0.0099999998;
			midRange=2;
			midRangeProbab=0.0099999998;
			maxRange=3;
			maxRangeProbab=0.0099999998;
		};
		class close: manual
		{
			showToPlayer=0;
			soundBurst=0;
			burst=15;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.050000001;
			midRange=300;
			midRangeProbab=0.57999998;
			maxRange=600;
			maxRangeProbab=0.30000001;
		};
		class short: close
		{
			burst=10;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
			minRange=400;
			minRangeProbab=0.30000001;
			midRange=600;
			midRangeProbab=0.57999998;
			maxRange=900;
			maxRangeProbab=0.30000001;
		};
		class medium: close
		{
			burst=7;
			aiRateOfFire=3;
			aiRateOfFireDistance=600;
			minRange=700;
			minRangeProbab=0.30000001;
			midRange=900;
			midRangeProbab=0.57999998;
			maxRange=1200;
			maxRangeProbab=0.30000001;
		};
		class far: close
		{
			burst=4;
			aiRateOfFire=5;
			aiRateOfFireDistance=1000;
			minRange=1000;
			minRangeProbab=0.30000001;
			midRange=1200;
			midRangeProbab=0.40000001;
			maxRange=1500;
			maxRangeProbab=0.0099999998;
		};
	};


	class RDS_DSHKM: MGun
	{
		ballisticscomputer = 1;


		class GunParticles
		{
			class effect1
			{
				positionName="usti hlavne";
				directionName="konec hlavne";
				effectName="MachineGunCloud";
			};
			class effect2
			{
				positionName="machinegun_eject_pos";
				directionName="machinegun_eject_dir";
				effectName="MachineGunCartridge2";
			};
		};

		scope = protected;
		displayName = $STR_DN_DSHKM;
		magazines[] = {RDS_50Rnd_127x107_DSHKM,RDS_150Rnd_127x107_DSHKM};
		magazineReloadTime = 6;
		aiDispersionCoefY=21; //7.0;
		aiDispersionCoefX=21;
		canLock = 0;
		modes[] = {manual,close, short, medium, far};
		class manual: MGun
		{
                        displayName = $STR_DN_DSHKM;
                        autoFire = 1;
			sounds[] = {StandardSound};
 			class StandardSound
 			{
				weaponSoundEffect = "DefaultRifle";
				begin1[] = {"\RDS_StaticW\DShKM\data\dshk_2",db15,1,1600};
				soundBegin[] = {"begin1",1};
			};
	                reloadTime = 0.1;
	                dispersion=0.0015;

			showToPlayer = true;
                        burst = 1;
			aiRateOfFire = 0.5;
			aiRateOfFireDistance = 50;
			minRange=1;minRangeProbab=0.01;
			midRange=2;midRangeProbab=0.01;
			maxRange=3;maxRangeProbab=0.01;
		}
		class close: manual
		{
                        showToPlayer = false;
                        soundBurst = false;
                        burst = 10; //Rg 6;
			aiRateOfFire = 0.5;
			aiRateOfFireDistance = 50;
			minRange=0;minRangeProbab=0.05;
			midRange=20;midRangeProbab=0.58;
			maxRange=100;maxRangeProbab=0.04;
		};
		class short: close
		{
			burst = 8; //Rg 6;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 300; //Rg 200;
			minRange=50;minRangeProbab=0.05;
			midRange=150;midRangeProbab=0.58; //Rg 100;
			maxRange=300;maxRangeProbab=0.04; //Rg 200;
		};
		class medium: close
		{
			burst = 4; //Rg 8;
			aiRateOfFire = 3; //Rg 4;
			aiRateOfFireDistance = 600; //Rg 400;
			minRange=200;minRangeProbab=0.05;
			midRange=500;midRangeProbab=0.58; //Rg 300;
			maxRange=800;maxRangeProbab=0.04; //Rg 400;
		};
		class far: close
		{
			burst = 5; //Rg 7;
			aiRateOfFire = 5; //Rg 7;
			aiRateOfFireDistance = 1000; //Rg 600;
			minRange=600;minRangeProbab=0.05;
			midRange=800;midRangeProbab=0.4; //Rg 500;
			maxRange=1200;maxRangeProbab=0.01; //Rg 600;
		};
	};
	class RDS_KORD: MGun
	{
		ballisticscomputer = 1;
		class GunParticles
		{
			class effect1
			{
				positionName="usti hlavne";
				directionName="konec hlavne";
				effectName="MachineGunCloud";
			};
			class effect2
			{
				positionName="machinegun_eject_pos";
				directionName="machinegun_eject_dir";
				effectName="MachineGunCartridge2";
			};
		};
		scope = protected;
		displayName = $STR_DN_KORD;
		magazines[] = {RDS_150Rnd_127x108_KORD,RDS_50Rnd_127x108_KORD};
		magazineReloadTime = 6;
		aiDispersionCoefY=15; //7.0;// better that DShKM
		aiDispersionCoefX=15;   // better that DShKM
		canLock = 0;
		modes[] = {manual,close, short, medium, far};
		class manual: MGun
		{
                        displayName = $STR_DN_KORD;
                        autoFire = 1;
			sounds[] = {StandardSound};
 			class StandardSound
 			{
				weaponSoundEffect = "DefaultRifle";
				begin1[] = {"\RDS_StaticW\DShKM\data\dshk_2",db15,1,1600};
				soundBegin[] = {"begin1",1};
			};
	                reloadTime = 0.086;
	                dispersion=0.00085; // better that DShKM

			showToPlayer = true;
                        burst = 1;
			aiRateOfFire = 0.5;
			aiRateOfFireDistance = 50;
			minRange=1;minRangeProbab=0.01;
			midRange=2;midRangeProbab=0.01;
			maxRange=3;maxRangeProbab=0.01;
		}
		class close: manual
		{
                        showToPlayer = false;
                        soundBurst = false;
                        burst = 10; //Rg 6;
			aiRateOfFire = 0.5;
			aiRateOfFireDistance = 50;
			minRange=0;minRangeProbab=0.05;
			midRange=20;midRangeProbab=0.58;
			maxRange=100;maxRangeProbab=0.04;
		};
		class short: close
		{
			burst = 8; //Rg 6;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 300; //Rg 200;
			minRange=50;minRangeProbab=0.05;
			midRange=150;midRangeProbab=0.58; //Rg 100;
			maxRange=300;maxRangeProbab=0.04; //Rg 200;
		};
		class medium: close
		{
			burst = 4; //Rg 8;
			aiRateOfFire = 3; //Rg 4;
			aiRateOfFireDistance = 600; //Rg 400;
			minRange=200;minRangeProbab=0.05;
			midRange=500;midRangeProbab=0.58; //Rg 300;
			maxRange=800;maxRangeProbab=0.04; //Rg 400;
		};
		class far: close
		{
			burst = 5; //Rg 7;
			aiRateOfFire = 5; //Rg 7;
			aiRateOfFireDistance = 1000; //Rg 600;
			minRange=600;minRangeProbab=0.05;
			midRange=800;midRangeProbab=0.4; //Rg 500;
			maxRange=1200;maxRangeProbab=0.01; //Rg 600;
		};
	};

	class RDS_AGS30: GMG_20mm {
		autoreload = 1;
		canlock = 0;
		cursorsize = 1;
		dispersion = 0.006;
		displayname = $STR_DN_AGS30;
		magazinereloadtime = 6;
		magazines[] = {"RDS_29Rnd_30mm_AGS30"};
		class manual: GMG_F {
			sounds[] = {StandardSound};
 			class StandardSound
 			{
				weaponSoundEffect = "DefaultRifle";
				begin1[] = {"RDS_StaticW\AGS30\data\AGS30_shot1_a",3.16228, 1, 1200};
				soundBegin[] = {"begin1",1};
			};
			displayname =$STR_DN_AGS30;
			soundbegin[] = {"begin1", 1};
			soundburst = 0;
			soundcontinuous = 0;
			weaponsoundeffect = "DefaultRifle";
		};
		reloadtime = 0.4;
		scope = 1;
	};
	class RDS_MK19: RDS_AGS30
	{
		displayName = "Mk19";
		magazines[] = {"RDS_48Rnd_40mm_MK19"};
	};


	class missiles_titan: MissileLauncher {};
	class RDS_AT13LauncherSingle: missiles_titan
	{
		displayName = $STR_DN_AT13LAUNCHERSINGLE;
		minRange=10;minRangeProbab=0.6;
		midRange=1000;midRangeProbab=0.7;
		maxRange=2000;maxRangeProbab=0.001;
		reloadTime = 16;
		magazines[]={RDS_6Rnd_AT13};
		lockedtargetsound[] = {"\RDS_StaticW\data\alarm_loop1", 0.000316228, 6};
		lockingtargetsound[] = {"\RDS_StaticW\data\alarm_loop1", 0.000316228, 2};
	};
	class RDS_TOWLauncher: missiles_titan
	{
		displayName = "M220 TOW";
		minRange = 10;
		minRangeProbab = 0.6;
		midRange = 1400;
		midRangeProbab = 0.7;
		maxRange = 4000;
		maxRangeProbab = 0.001;
		sounds[] = {StandardSound};
 		class StandardSound
 		{
			weaponSoundEffect = "DefaultRifle";
			begin1[] = {"\RDS_StaticW\TOW\Javelin1",31.6228,1,1000};
			soundBegin[] = {"begin1",1};
		};
		lockedtargetsound[] = {"\RDS_StaticW\data\alarm_loop1", 0.000316228, 6};
		lockingtargetsound[] = {"\RDS_StaticW\data\alarm_loop1", 0.000316228, 2};

		reloadTime = 1;
		canLock = 1;
		magazineReloadTime = 30;
		magazines[] = {"RDS_2Rnd_TOW","RDS_2Rnd_TOW2"};
		aiRateOfFire = 5;
		aiRateOfFireDistance = 500;
	};
	class RDS_TOWLauncherSingle: RDS_TOWLauncher
	{
		reloadTime = 8;
		magazines[] = {"RDS_6Rnd_TOW_HMMWV","RDS_6Rnd_TOW2"};
	};



	class RocketPods;
	class RDS_SPG9: RocketPods
	{
		scope = 2;
		displayName=$STR_DN_SPG9;
		type = WeaponHardMounted;
		reloadTime = 3;
		magazineReloadTime=10;
		modelOptics = "";
		magazines[]={RDS_PG9_AT,RDS_OG9_HE};
		sounds[] = {StandardSound};
 		class StandardSound
 		{
			weaponSoundEffect = "DefaultRifle";
			begin1[] ={"\RDS_StaticW\SPG9\data\RocketLauncher_Shot04_A",db20,1,1100};
			soundBegin[] = {"begin1",1};
		};
		drySound[]={"\RDS_StaticW\SPG9\data\Javelin_dry_v1",db-80,1,10};
		reloadMagazineSound[]={"\RDS_StaticW\SPG9\data\flare_reload",db-70,1,20};
		soundfly[] = {"A3\Sounds_F\weapons\Rockets\rocket_fly_1", 1, 1.9, 700};
		recoil=launcherBase;
		aiRateOfFire = 10.000000;
		aiRateOfFireDistance = 450;
		minRange = 50;
		midRange = 450;
		maxRange = 800;
		//cursorAim = \ca\Weapons\Data\clear_empty;
		cursor = Rocket; //\ca\UI\Data\cursor_w_rocket_gs;
		cursorSize = 1;
	};
	class RDS_Igla_twice:missiles_titan
	{
		//cursor = "EmptyCursor";
		//cursoraim = "Missile";
		displayName=$STR_DN_IGLA_TWICE;
		minRange=500;minRangeProbab=0.30;
		midRange=3100;midRangeProbab=0.8;
		maxRange=5200;maxRangeProbab=0.10;
		aiRateOfFire=5.0;
		aiRateOfFireDistance=3100;
		lockedtargetsound[] = {"\RDS_StaticW\data\alarm_loop1", 0.000316228, 6};
		lockingtargetsound[] = {"\RDS_StaticW\data\alarm_loop1", 0.000316228, 2};

		reloadTime = 4;
		magazineReloadTime = 30;
		magazines[]={RDS_2Rnd_Igla};
	};
	class mortar_155mm_AMOS: CannonCore {};
	class RDS_D30: mortar_155mm_AMOS
	{
		scope = protected;
		displayName = $STR_DN_D30;

		magazines[] = 	
		{
			"RDS_30Rnd_122mmHE_D30",
			"RDS_30Rnd_122mmWP_D30",
			"RDS_30Rnd_122mmLASER_D30",
			"RDS_30Rnd_122mmSMOKE_D30",
			"RDS_30Rnd_122mmILLUM_D30"
		};
		ballisticscomputer = 2;
		reloadTime = 6;
		magazineReloadTime = 2;

		class GunParticles {
			class Effect1 
			{
				directionname = "Konec hlavne";
				effectname = "ArtilleryFired1";
				positionname = "Usti hlavne";
			};
		};

		modes[] = {"Single1","Single2","Single3","Burst1","Burst2","Burst3"};


/*
		class Single1: Mode_SemiAuto
		{
			displayName = "Semi (close)";
			sounds[] = {StandardSound};
 			class StandardSound
 			{
				weaponSoundEffect = "DefaultRifle";
				begin1[] = {"A3\Sounds_F\weapons\Cannons\cannon_2", 2.51189, 1, 1500};
				soundBegin[] = {"begin1",1};
			};
			reloadSound[]={"\RDS_StaticW\D30\data\gun120reload",db0,1,20};
			soundServo[] = {"",0.0001,1};
			reloadTime = 4;
			minRange = 0;
			midRange = 0;
			maxRange = 0;
			artilleryDispersion = 0.7;
			artilleryCharge = 0.35;
		};
		class Single2: Single1
		{
			displayName = "Semi (medium)";
			artilleryCharge = 0.7;
		};
		class Single3: Single1
		{
			displayName = "Semi (far)";
			artilleryCharge = 1;
		};
		class Burst1: Mode_Burst
		{
			showToPlayer = 0;
			displayName = "Burst (close)";
			burst = 4;
			sounds[] = {StandardSound};
 			class StandardSound
 			{
				weaponSoundEffect = "DefaultRifle";
				begin1[] = {"A3\Sounds_F\weapons\Cannons\cannon_3", 2.51189, 1, 1500};
				soundBegin[] = {"begin1",1};
			};
			reloadSound[]={"\RDS_StaticW\D30\data\gun120reload",db0,1,20};
			soundServo[] = {"",0.0001,1};
			soundBurst = 0;
			reloadTime = 3;
			minRange = 60;
			minRangeProbab = 0.5;
			midRange = 290;
			midRangeProbab = 0.7;
			maxRange = 665;
			maxRangeProbab = 0.5;
			artilleryDispersion = 0.93;
			artilleryCharge = 0.35;
		};
		class Burst2: Burst1
		{
			showToPlayer = 0;
			displayName = "Burst (medium)";
			minRange = 230;
			minRangeProbab = 0.4;
			midRange = 1175;
			midRangeProbab = 0.6;
			maxRange = 2660;
			maxRangeProbab = 0.4;
			artilleryCharge = 0.7;
		};
		class Burst3: Burst1
		{
			showToPlayer = 0;
			displayName = "Burst (far)";
			minRange = 540;
			minRangeProbab = 0.3;
			midRange = 2355;
			midRangeProbab = 0.4;
			maxRange = 5500;
			maxRangeProbab = 0.3;
			artilleryCharge = 1;
		};
*/
	};
	class RDS_M119: RDS_D30
	{
		scope = protected;
		displayName = M119;

		magazines[] = 	
		{
			"RDS_30Rnd_105mmHE_M119",
			"RDS_30Rnd_105mmWP_M119",
			"RDS_30Rnd_105mmLASER_M119",
			"RDS_30Rnd_105mmSMOKE_M119",
			"RDS_30Rnd_105mmILLUM_M119"
		};
	};
	class cannon_120mm;
	class RDS_D30AT: cannon_120mm
	{
		displayName = $STR_DN_D30;
		magazines[] = 	
		{
			"RDS_30Rnd_122mmAT_D30",
			"RDS_30Rnd_122mmHE_D30",
			"RDS_30Rnd_122mmWP_D30"
		};
		reloadTime = 6;
		magazineReloadTime = 4;

		class GunParticles {
			class Effect1 
			{
				directionname = "Konec hlavne";
				effectname = "ArtilleryFired1";
				positionname = "Usti hlavne";
			};
		};


	};
};