class CfgPatches // you could also create a seperate file for this if it gets more complex.
{
	class OPTREZ_FG75
	{
		requiredaddons[] = {A3_Weapons_F};
		requiredversion = 0.1;
		units[] = {};
		weapons[] = {"OPTREZ_FG75"};
		magazines[] = {"RDS_30Rnd_122mmAT_D30", "RDS_30Rnd_122mmHE_D30"};
	};
};

#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"

