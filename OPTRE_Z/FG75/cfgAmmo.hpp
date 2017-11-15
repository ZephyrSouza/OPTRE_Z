#define RHA(mm,speed) caliber=(mm/((15*speed)/1000));
class Mode_SemiAuto;
class Mode_Burst;

class CfgAmmo
{
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