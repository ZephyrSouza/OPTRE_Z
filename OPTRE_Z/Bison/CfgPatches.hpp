/*	Addon description	*/
class CfgPatches {
	// Avoid confusing users by keeping class name match the PBO name and path.
	class OPTRE_IFV_Bison {
		// List addons defining config classes you want to use, define new vehicles available in editor and weapon classes
		units[] = {"OPTRE_IFV_Bison_base"};
		weapons[] = {};
		requiredAddons[] = {"A3_Armor_F","A3_Armor_F_Beta","A3_Weapons_F","OPTRE_Core"};
	};
};
