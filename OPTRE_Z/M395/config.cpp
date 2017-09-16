class CfgPatches // you could also create a seperate file for this if it gets more complex.
{
	class OPTREZ_M395
	{
		requiredaddons[] = {A3_Weapons_F};
		requiredversion = 0.1;
		units[] = {};
		weapons[] = {"OPTREZ_M395"};
		magazines[] = {"OPTREZ_15Rnd_762x51_Mag", "OPTREZ_15Rnd_762x51_Mag_Tracer"};
	};
};

#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"
#include "CfgWeapons.hpp"

