class CfgWeapons {
	
/*extern*/
class OPTRE_missiles_ASGM2;


class OPTRE_missiles_ASGM4: OPTRE_missiles_ASGM2 
{
	displayName = "ASGM-4 Missiles";
	magazines[] = {OPTRE_8Rnd_ASGM4_rockets};
	lockAcquire = 0;
	magazineReloadTime=6;
	reloadTime=1;
	
	reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_magazine_Mortar",1,1,20};
	reloadSound[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",1,1,20};
	//soundFly[] = {"",1,1.5,700};
	
	//When to use prob
	maxRangeProbab = 0.2;
	midRangeProbab = 0.9;
	minRangeProbab = 0.3;
	
	maxRange = 2500;
	midRange = 1000;
	minRange = 300;

	class GunParticles
	{
		class FirstEffect
		{
			effectName = "MortarFired";
			positionName = "Usti Hlavne";
			directionName = "Konec Hlavne";
		};
				
	};	
	
	
};
	




};