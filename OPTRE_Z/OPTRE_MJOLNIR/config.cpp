class CfgPatches
{
	class OPTRE_MJOLNIR
	{
		units[] 																				= {"OPTRE_Spartan2_Soldier"};
		weapons[] 																				= {"OPTRE_Spartan2_MJOLNIR_Undersuit","OPTRE_Spartan2_MJOLNIR_Mk4Armor","OPTRE_Spartan2_MJOLNIR_Mk4Helmet"};																								
		requiredVersion 																		= 0.1;
		requiredAddons[] 																		= {"OPTRE_Core"};
		author 																					= "Article 2 Studios";
		fileName 																				= "OPTRE_MJOLNIR.pbo";
	};
};

class CfgMovesFatigueSpartan
{
	staminaDuration=120;
	staminaCooldown=5;
	staminaRestoration=15;
	aimPrecisionSpeedCoef=0;
	terrainDrainSprint=0;
	terrainDrainRun=0;
	terrainSpeedCoef=1;
};

class CfgVehicles //This configures units and backpacks
{
	class Land;
	class Man: Land
	{
		class EventHandlers;
	};
	class CAManBase: Man
	{
		class HitPoints;
	};
	class SoldierWB: CAManBase
	{
		class HitPoints: HitPoints
		{
			class HitFace;
			class HitNeck;
			class HitHead;
			class HitPelvis;
			class HitAbdomen;
			class HitDiaphragm;
			class HitChest;
			class HitBody;
			class HitArms;
			class HitHands;
			class HitLegs;
		};
	};
	class OPTRE_UNSC_Soldier_Base: SoldierWB
	{
		class HitPoints: HitPoints
		{
			class HitFace
			{
				armor               = 1; // "Healthpoints" of this hitpoint is armor value (of hitpoint) * armor value ( coefficient of the total armor defined below for the whole object
				material            = -1; // damage material (-1 means "unused")
				name                = "face_hub"; // selection name from hit points LOD in object
				passThrough         = 0.1; // coefficient defining how much damage will pass into total damage when this hit point is damaged
				radius              = 0.08; // size of the hit point sphere, this is how it works: https://community.bistudio.com/wiki/Arma_3_Damage_Description
				explosionShielding  = 0.1; // multiplier of explosive damage (parameter: explosive > 0 in ammunition type)
				minimalHit          = 0.01; // minimal damage value that can be applied (based on armor value), damage below this threshold is ignored
                //example: total hit point armor = 2 and hitpoint class armor = 10 and minimalHit = 0.04  -> all damage below a hit value of 2*10*0.04= 0.8 is ignored
			};
			class HitNeck: HitFace
			{
				armor               = 1;
				material            = -1;
				name                = "neck";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.1;
				minimalHit          = 0.01;
			};
			class HitHead: HitNeck
			{
				armor               = 1;
				material            = -1;
				name                = "head";
				passThrough         = 0.1;
				radius              = 0.2;
				explosionShielding  = 0.1;
				minimalHit          = 0.01;
				depends             = "HitFace max HitNeck"; // returns the greater of HitFace and HitNeck.
                // for depends to work, HitHead must be inheriting from HitFace and HitNeck.
                // "max" is not the only operator you can use. + and *  are confirmed working. 
                // Other operators from the https://community.bistudio.com/wiki/Simple_Expression list may be usable as well.
			};
			class HitPelvis
			{
				armor               = 1;
				material            = -1;
				name                = "pelvis";
				passThrough         = 0.1;
				radius              = 0.2;
				explosionShielding  = 0.25;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitAbdomen: HitPelvis
			{
				armor               = 1;
				material            = -1;
				name                = "spine1";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 0.25;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor               = 1;
				material            = -1;
				name                = "spine2";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 2;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitChest: HitDiaphragm
			{
				armor               = 1;
				material            = -1;
				name                = "spine3";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 2;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitBody: HitChest
			{
				armor               = 1000; // not supposed to take damage directly
				material            = -1;
				name                = "body";
				passThrough         = 0.1;
				radius              = 0.16;
				explosionShielding  = 2;
				visual              = "injury_body";
				minimalHit          = 0.01;
				depends             = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest"; // depends work only for hit points defined in inheritance chain
                //arbitrary example for different operator usage: = "(2* (HitPelvis + HitAbdomen) * HitDiaphragm) max HitChest";
			};
			class HitArms
			{
				armor               = 1;
				material            = -1;
				name                = "arms";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.25;
				visual              = "injury_hands";
				minimalHit          = 0.01;
			};
			class HitHands: HitArms
			{
				armor               = 1;
				material            = -1;
				name                = "hands";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.25;
				visual              = "injury_hands";
				minimalHit          = 0.01;
				depends             = "HitArms";
			};
			class HitLegs
			{
				armor               = 1;
				material            = -1;
				name                = "legs";
				passThrough         = 0.1;
				radius              = 0.12;
				explosionShielding  = 0.25;
				visual              = "injury_legs";
				minimalHit          = 0.01;
			};			
			
			// ACE
			
			class HitLeftArm
			{
				armor               = 1;
				material            = -1;
				name                = "hand_l";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.25;
				visual              = "injury_hands";
				minimalHit          = 0.01;
			};
			class HitRightArm: HitLeftArm
			{
				name                = "hand_r";
			};
			class HitLeftLeg
			{
				armor               = 1;
				material            = -1;
				name                = "leg_l";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.25;
				visual              = "injury_hands";
				minimalHit          = 0.01;
			};
			class HitRightLeg: HitLeftLeg
			{
				name                = "leg_r";
			};
		};
	};
	
	// BASE UNITS START
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	class OPTRE_Spartan2_Soldier_Base: OPTRE_UNSC_Soldier_Base
	{
		dlc = "OPTRE";
		scope															= 1;
		scopeCurator													= 0;
		side 															= 1;		
		faction															= "OPTRE_UNSC";
		genericNames													= "NATOMen"; /// Standard names for lads of NATO (and European civils)
		identityTypes[] 												= {"LanguageENG_F","Kerry","EPA_B_Northgate","EPA_B_Hardy","EPA_B_James","EPA_B_McKay","LanguageGRE_F","Head_Greek","Head_African","Head_Euro","Head_Asian","Head_NATO", "G_IRAN_default"}; //G_IRAN_Default removes those pesky wacky glasses.  Everything else here serves to keep the UNSC diverse.  
		nakedUniform 													= "U_BasicBody";
		movesFatigue													= "CfgMovesFatigueSpartan";
		displayName														= "-";
		oxygenCapacity 													= 160;
		//portrait 														= "";
		//picture 														= "";
		cost 															= 100000;
		impactDamageMultiplier											= 0.025; //was 0.1
		author															= "Article 2 Studios";

		class HitPoints: HitPoints
		{
			class HitNeck: HitNeck
			{
				armor               = 12;
			};
			class HitPelvis: HitPelvis
			{
				armor               = 12;
			};
			class HitAbdomen: HitAbdomen
			{
				armor               = 12;
			};
			class HitDiaphragm: HitDiaphragm
			{
				armor               = 12;
			};
			class HitChest: HitChest
			{
				armor               = 12;
			};
			class HitArms: HitArms
			{
				armor               = 12;
			};
			class HitHands: HitHands
			{
				armor               = 12;
			};
			class HitLegs: HitLegs
			{
				armor               = 12;
			};
			
			// ACE
			
			class HitLeftArm: HitLeftArm
			{
				armor               = 12;
			};
			class HitRightArm: HitRightArm
			{
				armor               = 12;
			};
			class HitLeftLeg: HitLeftLeg
			{
				armor               = 12;
			};
			class HitRightLeg: HitRightLeg
			{
				armor               = 12;
			};
		};		
	};
	// BASE UNITS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	// UNITS START
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	class OPTRE_Spartan2_Soldier: OPTRE_Spartan2_Soldier_Base
	{
		dlc = "OPTRE";
		scope															= 2;
		scopeCurator													= 2;
		displayName														= "[SII] Unarmed";
		author															= "Article 2 Studios";
		vehicleClass													= "OPTRE_UNSC_Man_Special_class";
		uniformClass													= "OPTRE_Spartan2_MJOLNIR_Undersuit";
		model															= "\OPTRE_MJOLNIR\undersuit.p3d";
		weapons[]														= {"Throw","Put"};
		respawnWeapons[]												= {"Throw","Put"};
		Items[]															= {"OPTRE_Biofoam"};
		RespawnItems[]													= {"OPTRE_Biofoam"};
		magazines[]														= {};
		respawnMagazines[]												= {};
		linkedItems[] 													= {"OPTRE_Spartan2_MJOLNIR_Mk4Armor","OPTRE_Spartan2_MJOLNIR_Mk4Helmet","ItemMap","ItemCompass","ItemWatch","ItemRadio","OPTRE_NVG"};
		respawnLinkedItems[] 											= {"OPTRE_Spartan2_MJOLNIR_Mk4Armor","OPTRE_Spartan2_MJOLNIR_Mk4Helmet","ItemMap","ItemCompass","ItemWatch","ItemRadio","OPTRE_NVG"};
		hiddenSelections[] 												= {"camo"};
		hiddenSelectionsTextures[] 										= {"optre_mjolnir\data\undersuit_co.paa"};
		editorSubcategory 												= "OPTRE_EditorSubcategory_MenS"; //OPTRE_EditorSubcategory_MenS2
	};
	
	class OPTRE_Spartan2_Soldier_Scout: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		displayName														= "[SII] Scout";
		weapons[] 														= {"OPTRE_M7S","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_M7S","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Orange","OPTRE_M2_Smoke_Green"};
		respawnMagazines[] 												= {"OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Orange","OPTRE_M2_Smoke_Green"};
	
	};
	class OPTRE_Spartan2_Soldier_Rifleman_AR: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		displayName														= "[SII] Rifleman (MA5C)";
		weapons[] 														= {"OPTRE_MA5C","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_MA5C","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
		respawnMagazines[] 												= {"OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
	};
	class OPTRE_Spartan2_Soldier_Rifleman_BR: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		displayName														= "[SII] Rifleman (BR55)";
		weapons[] 														= {"OPTRE_BR55HB_ScopedRifle","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_BR55HB_ScopedRifle","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
		respawnMagazines[] 												= {"OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_36Rnd_95x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
	};
	class OPTRE_Spartan2_Soldier_Rifleman_AT: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		displayName														= "[SII] Rifleman (AT)";
		backpack 														= "OPTRE_ILCS_Rucksack_green";
		weapons[] 														= {"OPTRE_MA5C","OPTRE_M6G_SF","Throw","Put","OPTRE_M41_SSR"};
		respawnWeapons[] 												= {"OPTRE_MA5C","OPTRE_M6G_SF","Throw","Put","OPTRE_M41_SSR"};
		magazines[] 													= {"OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M41_Twin_HEAT","OPTRE_M41_Twin_HEAT","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
		respawnMagazines[] 												= {"OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M41_Twin_HEAT","OPTRE_M41_Twin_HEAT","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
		icon 															= "iconManAT";
	};
	class OPTRE_Spartan2_Soldier_Automatic_Rifleman: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		displayName														= "[SII] Automatic Rifleman";
		backpack														= "OPTRE_ILCS_Rucksack_green";
		weapons[] 														= {"OPTRE_M73","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_M73","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_200Rnd_95x40_Box","OPTRE_200Rnd_95x40_Box","OPTRE_200Rnd_95x40_Box","OPTRE_200Rnd_95x40_Box","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
		respawnMagazines[] 												= {"OPTRE_200Rnd_95x40_Box","OPTRE_200Rnd_95x40_Box","OPTRE_200Rnd_95x40_Box","OPTRE_200Rnd_95x40_Box","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
		icon 															= "iconManMG";
	};
	class OPTRE_Spartan2_Soldier_Marksman: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		displayName														= "[SII] Marksman";
		weapons[] 														= {"OPTRE_M392_DMR_ScopedRifle","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_M392_DMR_ScopedRifle","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
		respawnMagazines[] 												= {"OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_15Rnd_762x51_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
	
	};
	class OPTRE_Spartan2_Soldier_Scout_Sniper: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		displayName														= "[SII] Scout Sniper";
		weapons[] 														= {"OPTRE_SRS99D_SC_LS","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_SRS99D_SC_LS","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
		respawnMagazines[] 												= {"OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_4Rnd_145x114_APFSDS_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_M9_Frag","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Green"};
	
	};
	class OPTRE_Spartan2_Soldier_TeamLeader: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		displayName														= "[SII] Team Leader";
		backpack														= "OPTRE_ANPRC_521_Green";
		weapons[] 														= {"OPTRE_MA5CGL","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_MA5CGL","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_60rnd_762x51_Mag_Tracer","OPTRE_60rnd_762x51_Mag_Tracer","OPTRE_60rnd_762x51_Mag_Tracer","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Orange","OPTRE_M2_Smoke_Green"};
		respawnMagazines[] 												= {"OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_60rnd_762x51_Mag_Tracer","OPTRE_60rnd_762x51_Mag_Tracer","OPTRE_60rnd_762x51_Mag_Tracer","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","OPTRE_M9_Frag","OPTRE_M2_Smoke","OPTRE_M2_Smoke_Orange","OPTRE_M2_Smoke_Green"};
		icon 															= "iconManLeader";
	};
	class OPTRE_Spartan2_Soldier_Corpsman: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		attendant 														= 1;
		displayName														= "[SII] Corpsman";
		backpack 														= "OPTRE_ILCS_Rucksack_Medical_green";
		weapons[] 														= {"OPTRE_M7S","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_M7S","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag"};
		respawnMagazines[] 												= {"OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_60Rnd_5x23mm_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag"};
		icon 															= "iconManMedic";
	};
	class OPTRE_Spartan2_Soldier_Engineer: OPTRE_Spartan2_Soldier
	{
		dlc = "OPTRE";
		engineer 														= 1;
		displayName														= "[SII] Engineer";
		backpack														= "OPTRE_ILCS_Rucksack_Black_EXP";
		weapons[] 														= {"OPTRE_MA5CGL","OPTRE_M6G_SF","Throw","Put"};
		respawnWeapons[] 												= {"OPTRE_MA5CGL","OPTRE_M6G_SF","Throw","Put"};
		magazines[] 													= {"OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell"};
		respawnMagazines[] 												= {"OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_32Rnd_762x51_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","OPTRE_8Rnd_127x40_Mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell"};
		icon 															= "iconManExplosive";
	};
	// UNITS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};

class cfgWeapons
{
	class U_B_CombatUniform_mcam;
	class UniformItem;
	class V_PlateCarrier1_rgr;
	class VestItem;
	class HeadgearItem;
	class H_HelmetB;
		
	// UNIFORMS START
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	class OPTRE_Spartan2_MJOLNIR_Undersuit: U_B_CombatUniform_mcam
	{
		dlc = "OPTRE";
		scope											= 2;
		scopeArsenal									= 2;
		author											= "Article 2 Studios";
		displayName										= "MJOLNIR Ballistic Undersuit";
		//picture   									= "\OPTRE_UNSC_Units\Army\icons\army_uniform_wdl_hvy.paa";
		model											= "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel								= "-";
			uniformClass								= "OPTRE_Spartan2_Soldier";
			containerClass								= "Supply200";
			mass										= 10;
			modelSides[] 								= {6};
		};
	};
	// UNIFORMS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
	// VESTS START
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	class OPTRE_Spartan2_MJOLNIR_Mk4Armor: V_PlateCarrier1_rgr //The vest base class
	{	
		dlc = "OPTRE";
		scope 											= 2;
		scopeArsenal									= 2;
		author											= "Article 2 Studios";
		displayName  									= "MJOLNIR Mark IV Powered Assault Armor";
		//picture 										= "";
		model   										= "\OPTRE_MJOLNIR\armormk4.p3d";
		class ItemInfo: VestItem 
		{
			uniformModel 								= "\OPTRE_MJOLNIR\armormk4.p3d";
			//armor 									= 40;
			containerClass 								= "Supply200";
			mass 										= 20;
			passThrough 								= 0.1;
			modelSides[] 								= {6};
			class HitpointsProtectionInfo
			{
				class Neck
				{
					hitpointName						= "HitNeck";
					armor								= 100;
					passThrough							= 0.1;
				};
				class Legs
				{
					hitpointName						= "HitLegs";
					armor								= 100;
					passThrough							= 0.1;
				};
				class Arms
				{
					hitpointName						= "HitArms";
					armor								= 100;
					passThrough							= 0.1;
				};
				class Hands
				{
					hitpointName						= "HitHands";
					armor								= 100;
					passThrough							= 0.1;
				};
				class Chest
				{
					hitpointName 						= "HitChest";
					armor 								= 100;
					passThrough 						= 0.1;
				};
				class Diaphragm
				{
					hitpointName 						= "HitDiaphragm";
					armor 								= 100;
					passThrough 						= 0.1;
				};
				class Abdomen
				{
					hitpointName 						= "HitAbdomen";
					armor 								= 100;
					passThrough 						= 0.1;
				};
				class Body
				{
					hitpointName 						= "HitBody";
					armor 								= 100;
					passThrough 						= 0.1;
				};
			};
		};
	};
	// VESTS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	// HELMETS START
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	class OPTRE_Spartan2_MJOLNIR_Mk4Helmet: H_HelmetB
	{	
		dlc = "OPTRE";
		scope 											= 2;
		scopeArsenal									= 2;
		author											= "Article 2 Studios";
		displayName    									= "MJOLNIR Mark IV Powered Helmet";
		//picture   									= "\OPTRE_UNSC_Units\Army\icons\Army_Helmet_wdl.paa";
		model     										= "\OPTRE_MJOLNIR\helmetmk4.p3d";
		class ItemInfo: HeadgearItem 
		{
			uniformModel   								= "\OPTRE_MJOLNIR\helmetmk4.p3d";
			mass   										= 10;
			modelSides[]   								= {6};
			passThrough   								= 0.1;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName 						= "HitHead";
					armor 								= 80;
					passThrough 						= 0.1;
				};
				class Face
				{
					hitpointName 						= "HitFace";
					armor 								= 80;
					passThrough 						= 0.1;
				};
				class Neck
				{
					hitpointName 						= "HitNeck";
					armor 								= 80;
					passThrough 						= 0.1;
				};
			};
		};
	};
	class OPTRE_Spartan2_MJOLNIR_EVAHelmet: OPTRE_Spartan2_MJOLNIR_Mk4Helmet
	{	
		dlc = "OPTRE";
		scope 											= 1;
		scopeArsenal									= 1;
		author											= "Article 2 Studios";
		displayName    									= "MJOLNIR EVA Powered Helmet";
		//picture   									= "\OPTRE_UNSC_Units\Army\icons\Army_Helmet_wdl.paa";
		model     										= "\OPTRE_MJOLNIR\helmeteva.p3d";
		class ItemInfo: ItemInfo 
		{
			uniformModel   								= "\OPTRE_MJOLNIR\helmeteva.p3d";
		};
	};
	// HELMETS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};