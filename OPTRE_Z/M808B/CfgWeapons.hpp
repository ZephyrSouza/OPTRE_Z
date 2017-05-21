class CfgWeapons {
	
/*extern*/
class cannon_120mm;
class OPTRE_cannon_120mm : cannon_120mm {
	class close;
	class far;
	class short;
	class medium;
	class player;
	class gunParticles;
	};


class  OPTRE_M512_90mm : OPTRE_cannon_120mm {
	magazinereloadTime=4.0;
	displayName = 90mm Smoothbore H-Velocity Cannon;
	magazines[] = {OPTRE_60Rnd_90mm_TUNGSTEN_APBC, OPTRE_60Rnd_90mm_S1_Canister};
	//cartridgePos = "nabojnicestart";
	//cartridgeVel = "nabojniceend";

	
	class close : close {
		reloadTime=2.0;		
	};
	class far : far {
		reloadTime=2.0;		
	};
	class short : short {
		reloadTime=2.0;		
	};
	class medium : medium {
		reloadTime=2.0;		
	};
	class player : player {
		reloadTime=2.0;		
	};
	
	class gunParticles: gunParticles {
		class ejectshellcase {
		directionName = "nabojniceend";
		effectName = "OPTRE_90mmShellcase";
		positionName = "nabojnicestart";
		};
	};
	
	
};

class LMG_coax;
class OPTRE_LMG_coax : LMG_coax {
	class GunParticles {
		class effect1;
	};
	class close;
	class far;
	class short;
	class medium;
	class player;
	class manual;
};



class OPTRE_M247T_Coax: OPTRE_LMG_coax {
	displayName = M247T Medium Machine Gun;
	magazines[] = {2000Rnd_762x51_Belt_Green};
	muzzleEnd = "konec hlavne2";
	muzzlePos = "usti hlavne2";
	selectionFireAnim = "zasleh2";
	class GunParticles {
		class effect1 {
			directionName = "konec hlavne2";
			effectName = "MachineGunCloud";
			positionName = "usti hlavne2";
		};
	};

	class close: close {
		muzzleEnd = "konec hlavne2";
		muzzlePos = "usti hlavne2";
		selectionFireAnim = "zasleh2";
	};
	class far: far {
		muzzleEnd = "konec hlavne2";
		muzzlePos = "usti hlavne2";
		selectionFireAnim = "zasleh2";
	};
	class short: short {
		muzzleEnd = "konec hlavne2";
		muzzlePos = "usti hlavne2";
		selectionFireAnim = "zasleh2";
	};
	class medium: medium {
		muzzleEnd = "konec hlavne2";
		muzzlePos = "usti hlavne2";
		selectionFireAnim = "zasleh2";
	};
	class player: player {
		muzzleEnd = "konec hlavne2";
		muzzlePos = "usti hlavne2";
		selectionFireAnim = "zasleh2";
	};
	class manual: manual {
		muzzleEnd = "konec hlavne2";
		muzzlePos = "usti hlavne2";
		selectionFireAnim = "zasleh2";
	};
};
};