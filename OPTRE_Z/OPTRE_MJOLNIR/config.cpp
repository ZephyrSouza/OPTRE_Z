class CfgPatches
{
	class OPTRE_MJOLNIR
	{
		units[] 																				= {"OPTRE_Spartan2_Soldier"};
		weapons[] 																				= {"OPTRE_Spartan2_MJOLNIR_Undersuit","OPTRE_Spartan2_MJOLNIR_Mk4Armor","OPTRE_Spartan2_MJOLNIR_Mk4Helmet"};																								
		requiredVersion 																		= 0.1;
		requiredAddons[] 																		= {"OPTRE_Core"};
		author[] 																				= {"Article 2 Studios"};
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
	class OPTRE_Spartan2_Soldier_Base: SoldierWB
	{
		dlc = "OPTRE";
		scope															= 1;
		scopeCurator													= 0;
		side 															= 1;		
		faction															= "OPTRE_UNSC";
		genericNames													= "NATOMen"; /// Standard names for lads of NATO (and European civils)
		identityTypes[] 												= {"LanguageENG_F","Miller","Kerry","EPA_B_Northgate","EPA_B_Hardy","EPA_B_James","EPA_B_McKay","LanguageGRE_F","Head_Greek","Head_African","Head_Euro","Head_Asian","Head_NATO", "G_IRAN_default"}; //G_IRAN_Default removes those pesky wacky glasses.  Everything else here serves to keep the UNSC diverse.  
		uniformAccessories[]											= {};
		nakedUniform 													= "U_BasicBody";
		movesFatigue													= "CfgMovesFatigueSpartan";
		modelSides[]   													= {6};
		displayName														= "-";
		canCarryBackPack 												= 1;
		oxygenCapacity 													= 160;
		portrait 														= "";
		picture 														= "";
		icon 															= "iconMan";
		accuracy 														= 2.3;
		sensitivity 													= 3;
		camouflage 														= 1.4;
		minFireTime 													= 7;
		primaryAmmoCoef 												= 0.4;
		secondaryAmmoCoef 												= 0.2;
		handgunAmmoCoef 												= 0.1;
		cost 															= 100000;
		class EventHandlers;
		author															= "Article 2 Studios";
		class Wounds /// changes material of skin according to damage
		{
			tex[] = {};
			mat[] = {
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",	

				"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",	
				
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",	
				
				"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",	
				
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"					
			};
		};

		class HitPoints: HitPoints
		{
			class HitFace: HitFace {};
			class HitNeck: HitNeck {};
			class HitPelvis : HitPelvis
			{
				armor = 1;
				passThrough = 0.5;
			};
			class HitAbdomen: HitAbdomen {};
			class HitDiaphragm: HitDiaphragm {};
			class HitChest: HitChest {};
			class HitArms: HitArms
			{
				armor = 1;
				passThrough = 0.5;
			};
			class HitHead: HitHead
			{
				armor = 1;
			};
			class HitBody: HitBody {};
			class HitHands: HitHands
			{
				armor = 1;
			};
			class HitLegs: HitLegs
			{
				armor = 1;
				passThrough = 0.5;
			};
		};

		armor					= 2; // keep constant among various soldiers so that the hit points armor coefficients remains on the same scale
		armorStructural			= 0.5; // divide all damage taken to total hit point, either directly or through hit point passThrough coefficient, must be adjusted for each model to achieve consistent total damage results
		explosionShielding		= 0.05; // for consistent explosive damage after adjusting = ( armorStructural / 10 )
	};
	class OPTRE_Spartan2_Soldier: OPTRE_Spartan2_Soldier_Base
	{
		dlc = "OPTRE";
		scope															= 2;
		scopeCurator													= 2;
		displayName														= "SPARTAN-II Super Soldier (MkIV)";
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
		class HitPoints: HitPoints
		{
			class HitArms: HitArms
			{
				armor = 8;
			};
			class HitHands: HitHands
			{
				armor = 8;
			};
			class HitLegs: HitLegs
			{
				armor = 8;
			};
		};
		editorSubcategory = "OPTRE_EditorSubcategory_MenS";
	};
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
		hiddenSelections[] 								= {"camo1","camo2","camo3"};
		hiddenSelectionsTextures[] 						= {"optre_mjolnir\data\arms_co.paa","optre_mjolnir\data\chest_co.paa","optre_mjolnir\data\legs_co.paa"};
		class ItemInfo: VestItem 
		{
			uniformModel 								= "\OPTRE_MJOLNIR\armormk4.p3d";
			//armor 									= 40;
			containerClass 								= "Supply100";
			mass 										= 20;
			passThrough 								= 0.1;
			hiddenSelections[] 							= {"camo"};
			hiddenSelectionsTextures[] 					= {"optre_mjolnir\data\undersuit_co.paa"};
			modelSides[] 								= {6};
			class HitpointsProtectionInfo
			{
				class Legs
				{
					hitpointName						= "HitLegs";
					armor								= 40;
					passThrough							= 0.1;
				};
				class Arms
				{
					hitpointName						= "HitArms";
					armor								= 40;
					passThrough							= 0.1;
				};
				class Hands
				{
					hitpointName						= "HitHands";
					armor								= 40;
					passThrough							= 0.1;
				};
				class Chest
				{
					hitpointName 						= "HitChest";
					armor 								= 40;
					passThrough 						= 0.1;
				};
				class Diaphragm
				{
					hitpointName 						= "HitDiaphragm";
					armor 								= 40;
					passThrough 						= 0.1;
				};
				class Abdomen
				{
					hitpointName 						= "HitAbdomen";
					armor 								= 40;
					passThrough 						= 0.1;
				};
				class Body
				{
					hitpointName 						= "HitBody";
					armor 								= 40;
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
		hiddenSelections[]   							= {"camo"};
		hiddenSelectionsTextures[]   					= {"optre_mjolnir\data\helmet_co.paa"};
		class ItemInfo: HeadgearItem 
		{
			uniformModel   								= "\OPTRE_MJOLNIR\helmetmk4.p3d";
			//armor   									= 8;
			mass   										= 10;
			modelSides[]   								= {6};
			passThrough   								= 0.25;
			hiddenSelections[]   						= {"camo"};
			hiddenSelectionsTextures[]   				= {"optre_mjolnir\data\helmet_co.paa"};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 30;
					passThrough = 0.25;
				};
			};
		};
	};
	// HELMETS END
	// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};