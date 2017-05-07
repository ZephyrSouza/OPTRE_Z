class CfgWeapons {
	
/*extern*/
class cannon_105mm;
class OPTRE_cannon_105mm: cannon_105mm
 {
	class close;
	class far;
	class short;
	class medium;
	class player;
	};


class  OPTRE_cannon_90mm : OPTRE_cannon_105mm {
	magazinereloadTime=6.0;
	displayName = 90mm Semi-Automatic Gun;
	magazines[] = {OPTRE_30Rnd_90mm_HE,OPTRE_30Rnd_90mm_APBC};
	
	class close : close {
		reloadTime=4.0;		
	};
	class far : far {
		reloadTime=4.0;		
	};
	class short : short {
		reloadTime=4.0;		
	};
	class medium : medium {
		reloadTime=4.0;		
	};
	class player : player {
		reloadTime=4.0;		
	};
	
	
};
class OPTRE_missiles_C2GMLS;   
class OPTRE_missiles_C2GMLS_2 : OPTRE_missiles_C2GMLS //This should be changed so that just the new magazine is added to the weapon
{
	magazines[] = {"OPTRE_2Rnd_C2GMLS_missiles","OPTRE_12Rnd_C2GMLS_missiles"};
};


class autocannon_40mm_CTWS;
class OPTRE_autocannon_40mm_Base: autocannon_40mm_CTWS
{
	class GunParticles;
};

class OPTRE_autocannon_40mm_CTWS: OPTRE_autocannon_40mm_Base
{
	class GunParticles: GunParticles
	{
		class Shell {};
	};
};



};