class cfgWeapons
{

	class cannon_120mm;
	class OPTREZ_FG75: cannon_120mm
	
	{
		displayName = FG75;
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