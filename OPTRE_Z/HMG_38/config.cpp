enum
{
    DESTRUCTENGINE = 2,
    DESTRUCTDEFAULT = 6,
    DESTRUCTWRECK = 7,
    DESTRUCTTREE = 3,
    DESTRUCTTENT = 4,
    STABILIZEDINAXISX = 1,
    STABILIZEDINAXESXYZ = 4,
    STABILIZEDINAXISY = 2,
    STABILIZEDINAXESBOTH = 3,
    DESTRUCTNO = 0,
    STABILIZEDINAXESNONE = 0,
    DESTRUCTMAN = 5,
    DESTRUCTBUILDING = 1,
}; 
class CfgPatches
{
	class OPTRE_Weapons_HMG38
	{
		units[] = {};
		weapons[] = 
		{
			"OPTRE_HMG38_Rifle"
		};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Weapons_F"};
		author = "Article 2 Studios";
	};
};

#include "cfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"

