class CfgMagazines
{
	class Default;
	class CA_Magazine: Default{};
	class VehicleMagazine: CA_Magazine{};
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

};