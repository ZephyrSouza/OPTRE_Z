class CfgPatches // you could also create a seperate file for this if it gets more complex.
{
	class OPTREZ_MA5K
	{
		requiredaddons[] = {A3_Weapons_F};
		requiredversion = 0.1;
		units[] = {};
		weapons[] = {"OPTREZ_MA5K"};
		magazines[] = {"MA5K_60Rnd_762x39_B_Stanag", "MA5K_60Rnd_762x39_T_Stanag"};
	};
};

#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"
#include "CfgWeapons.hpp"

