class CfgPatches
{
	class unit_testing
	{
		units[] 																				= {"testing_soldier"};
		weapons[] 																				= {"testing_uniform","testing_vest","testing_headgear"};																								
		requiredVersion 																		= 0.1;
		requiredAddons[] 																		= {"OPTRE_Core"};
		author 																					= "Scorch052";
		fileName 																				= "unit_testing.pbo";
	};
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
	class testing_soldier_base: OPTRE_UNSC_Soldier_Base
	{
		scope															= 1;
		scopeCurator													= 0;
		side 															= 1;		
		faction															= "OPTRE_UNSC";
		genericNames													= "NATOMen"; /// Standard names for lads of NATO (and European civils)
		identityTypes[] 												= {"LanguageENG_F","Kerry","EPA_B_Northgate","EPA_B_Hardy","EPA_B_James","EPA_B_McKay","LanguageGRE_F","Head_Greek","Head_African","Head_Euro","Head_Asian","Head_NATO", "G_IRAN_default"}; //G_IRAN_Default removes those pesky wacky glasses.  Everything else here serves to keep the UNSC diverse.  
		nakedUniform 													= "U_BasicBody";
		displayName														= "-";
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
		weapons[]														= {"Throw","Put"};
		respawnWeapons[]												= {"Throw","Put"};
		Items[]															= {};
		RespawnItems[]													= {};
		magazines[]														= {};
		respawnMagazines[]												= {};
		linkedItems[] 													= {"testing_vest","testing_headgear","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnLinkedItems[] 											= {"testing_vest","testing_headgear","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	// BASE UNITS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	// UNITS START
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	class testing_soldier: testing_soldier_base
	{
		scope															= 2;
		scopeCurator													= 2;
		displayName														= "! UNIT FOR TESTING !";
		uniformClass													= "testing_uniform";
		model															= "\unit_testing\uniform.p3d";
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
	class testing_uniform: U_B_CombatUniform_mcam
	{
		scope											= 2;
		scopeArsenal									= 2;
		displayName										= "! UNIFORM FOR TESTING !";
		model											= "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel								= "-";
			uniformClass								= "testing_soldier";
			containerClass								= "Supply100";
			mass										= 1;
			modelSides[] 								= {6};
		};
	};
	// UNIFORMS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
	// VESTS START
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	class testing_vest: V_PlateCarrier1_rgr //The vest base class
	{	
		scope 											= 2;
		scopeArsenal									= 2;
		displayName  									= "! VEST FOR TESTING !";
		model   										= "\unit_testing\vest.p3d";
		class ItemInfo: VestItem 
		{
			uniformModel 								= "\unit_testing\vest.p3d";
			containerClass 								= "Supply100";
			mass 										= 10;
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
	class testing_helmet: H_HelmetB
	{	
		scope 											= 2;
		scopeArsenal									= 2;
		displayName    									= "! HEADGEAR FOR TESTING !";
		model     										= "\unit_testing\headgear.p3d";
		class ItemInfo: HeadgearItem 
		{
			uniformModel   								= "\unit_testing\headgear.p3d";
			mass   										= 1;
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
	// HELMETS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};