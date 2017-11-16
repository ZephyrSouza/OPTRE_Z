class CfgMagazines 
{
	/*external*/ 
	class 30Rnd_120mm_APFSDS_shells;
	/*external*/ 
	class 30Rnd_120mm_HE_shells;
	
	class OPTRE_4Rnd_75mm_HE: 30Rnd_120mm_HE_shells
	{
		dlc = "OPTRE";
		ammo = "OPTRE_Sh_75mm_SAPHE";
		displayname = "75mm HE";
		displaynameshort = "75mm HE";
		tracersevery = 1;
		count=4;
	};
	class OPTRE_4Rnd_75mm_AT: 30Rnd_120mm_APFSDS_shells
	{
		dlc = "OPTRE";
		ammo = "OPTRE_Sh_75mm_APFSDS";
		displayname = "75mm APFSDS";
		displaynameshort = "75mm APFSDS";
		tracersevery = 1;
		count=4;
	};
};
