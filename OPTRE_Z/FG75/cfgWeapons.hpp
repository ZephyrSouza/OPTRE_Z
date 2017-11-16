class CfgWeapons {
	
/*extern*/
class cannon_120mm;
class player;
class OPTRE_cannon_120mm : cannon_120mm {
	class close;
	class far;
	class short;
	class medium;
	class gunParticles;
	
	class player : Player {
	reloadTime= 1.5;
		};
	};


class OPTRE_75mm: OPTRE_cannon_120mm {
	displayName ="M75 Smoothbore High-Velocity Cannon";
	magazines[] = {"OPTRE_4Rnd_75mm_HE", "OPTRE_4Rnd_75mm_AT"};
	magazineReloadTime= 14;
	reloadTime= 1.5;
	};
};