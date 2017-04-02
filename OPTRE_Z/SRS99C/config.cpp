class CfgPatches // you could also create a seperate file for this if it gets more complex.
{
	class OPTREZ_SRS99C
	{
		requiredaddons[] = {A3_Weapons_F};
		requiredversion = 0.1;
		units[] = {};
		weapons[] = {"OPTREZ_SRS99C"};
		magazines[] = {"SRS_4Rnd_127x108_B_Stanag", "SRS_4Rnd_127x108_T_Stanag","SRS_4Rnd_127x108_APDS","SRS_4Rnd_127x108_HVAP","SRS_4Rnd_127x108_HEDP"};
	};
};

#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"
#include "CfgWeapons.hpp"

