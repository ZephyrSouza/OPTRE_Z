class CfgPatches
{
	class RDS_StaticWeapons_Core
	{
		units[]=
		{
			"RDS_ZU23_AAF",
			"RDS_DSHKM_AAF",
			"RDS_DSHkM_Mini_TriPod",
			"RDS_KORD_AAF",
			"RDS_KORD_high_AAF",
			"RDS_AGS_AAF",
			"RDS_Metis_AAF",
			"RDS_SPG9_AAF",
			"RDS_Igla_AA_pod_AAF",
			"RDS_2b14_82mm_AAF",
			"RDS_D30_AAF",
			"RDS_D30_AT_AAF",

			"RDS_ZU23_CSAT",
			"RDS_DSHKM_CSAT",
			"RDS_DSHkM_Mini_TriPod_CSAT",
			"RDS_KORD_CSAT",
			"RDS_KORD_high_CSAT",
			"RDS_AGS_CSAT",
			"RDS_Metis_CSAT",
			"RDS_SPG9_CSAT",
			"RDS_Igla_AA_pod_CSAT",
			"RDS_2b14_82mm_CSAT",
			"RDS_D30_CSAT",
			"RDS_D30_AT_CSAT",

			"RDS_ZU23_FIA",
			"RDS_DSHKM_FIA",
			"RDS_DSHkM_Mini_TriPod_FIA",
			"RDS_KORD_FIA",
			"RDS_KORD_high_FIA",
			"RDS_AGS_FIA",
			"RDS_Metis_FIA",
			"RDS_SPG9_FIA",
			"RDS_Igla_AA_pod_FIA",
			"RDS_2b14_82mm_FIA",
			"RDS_D30_FIA",
			"RDS_D30_AT_FIA"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Static_F_Gamma","A3_CargoPoses_F","A3_Armor_F_Slammer","A3_Weapons_F"
		};
	};
};

#define ASSEMBLE_INFO(bagName, tripodName) \
		class assembleInfo \
		{ \
		        primary = 0; \
			base = ""; \
			assembleTo = ""; \
			dissasembleTo[] = {bagName, tripodName}; \
			displayName = ""; \
		};

#include "basicDefines.hpp"
#include "cfgWeapons.hpp"
#include "cfgVehicles.hpp"
#include "cfgFunctions.hpp"


#define SPEED_STATIC 1e10
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Hilux_Cargo01 = "Hilux_Cargo01";
		DShKM_Gunner = "DShKM_Gunner";
    		LowTripod_Gunner = "LowTripod_Gunner";
    		LowKORD_Gunner = "LowKORD_Gunner";
    		KORD_Gunner = "KORD_Gunner";
    		AGS_Gunner = "AGS_Gunner";
    		SPG_Gunner = "SPG_Gunner";
    		Metis_Gunner = "Metis_Gunner";
		D30_Commander = "D30_Commander";
		D30_Gunner = "D30_Gunner";
		D30_Cargo = "D30_Cargo";
		Mi17_Cargo02 = "Mi17_Cargo02";

		M119_Commander = "M119_Commander";
		M119_Gunner = "M119_Gunner";
		M119_Cargo = "M119_Cargo";
		M2_Gunner = "M2_Gunner";
		TOW_Gunner = "TOW_Gunner";
	};
};

class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class KIA_Hilux_Cargo01: Crew
		{
			actions = DeadActions;
			file=RDS_StaticW\Anim\KIA_Hilux_Cargo01.rtm;
			speed = 0.5;
			looped=false;
			terminal = 1;
			connectTo[] = {DeadState,0.1};
			soundEnabled=0;
		};
		class Hilux_Cargo01: Crew
		{
			file=RDS_StaticW\Anim\Hilux_Cargo01.rtm;
			interpolateTo[]={KIA_Hilux_Cargo01,1};
		};
		class DShKM_Gunner: Crew
		{
			file=RDS_StaticW\Anim\DShKM_Gunner.rtm;
			connectTo[]={Static_Dead,1};		//ToDo: own death anim?
			leftHandIKBeg = true;
			leftHandIKCurve[] = {1};
			leftHandIKEnd = true;
			rightHandIKCurve[] = {1}; 
			righHandIKBeg = true;
			righHandIKEnd = true;
		};
		class LowTripod_Gunner: DShKM_Gunner
		{
			file=RDS_StaticW\Anim\LowTripod_Gunner.rtm;
		};
		class LowKORD_Gunner: DShKM_Gunner
		{
			file=RDS_StaticW\Anim\sittingGunner.rtm;
			interpolateTo[]={KIA_SPG_Gunner,1};
		};
		class KORD_Gunner: DShKM_Gunner
		{
			file=RDS_StaticW\Anim\standingGunner.rtm;
		};
		class AGS_Gunner: Crew
		{
			file=RDS_StaticW\Anim\AGS_Gunner.rtm;
			connectTo[]={Static_Dead,1};		//ToDo: own death anim?
		};
		class KIA_SPG_Gunner: DefaultDie
		{
			actions = DeadActions;
			//file=RDS_StaticW\Anim\KIA_SPG9_gunner.rtm;
			file="\A3\cargoposes_F\Anim\gunner_static_low01_KIA.rtm";
			speed = 0.5;
			looped=false;
			terminal = 1;
			soundEnabled=0;
			connectTo[]=
			{
				"Unconscious",
				0.1
			};
		};
		class SPG_Gunner: Crew
		{
			file=RDS_StaticW\Anim\SPG9_gunner.rtm;
			interpolateTo[]={KIA_SPG_Gunner,1};
		};
		class Metis_Gunner: Crew
		{
			file=RDS_StaticW\Anim\Metis_Gunner.rtm;
			connectTo[] = {KIA_SPG_Gunner,0.1};
		};
		class KIA_Mi17_Cargo02: DefaultDie
		{
			actions="DeadActions";
			file="\RDS_StaticW\Anim\KIA_Mi17_Cargo02.rtm";
			speed=1;
			looped="false";
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"Unconscious",
				0.1
			};
		};
		class Mi17_Cargo02: Crew
		{
			file="\RDS_StaticW\Anim\Mi17_Cargo02_V0.rtm";
			speed=0.30000001;
			equivalentTo="Mi17_Cargo02";
			connectTo[]=
			{
				"Mi17_Cargo02",
				0.1,
				"Mi17_Cargo02_V1",
				0.1,
				"Mi17_Cargo02_V2",
				0.1,
				"Mi17_Cargo02_V3",
				0.1,
				"Mi17_Cargo02_V4",
				0.1,
				"Mi17_Cargo02_V5",
				0.1,
				"Mi17_Cargo02_V6",
				0.1
			};
			interpolateTo[]=
			{
				"KIA_Mi17_Cargo02",
				0.1
			};
			variantsAI[]=
			{
				"Mi17_Cargo02",
				0.40000001,
				"Mi17_Cargo02_V1",
				0.1,
				"Mi17_Cargo02_V2",
				0.1,
				"Mi17_Cargo02_V3",
				0.1,
				"Mi17_Cargo02_V4",
				0.1,
				"Mi17_Cargo02_V5",
				0.1,
				"Mi17_Cargo02_V6",
				0.1
			};
			variantAfter[]={5,10,20};
		};
		class Mi17_Cargo02_V1: Mi17_Cargo02
		{
			file="\RDS_StaticW\Anim\Mi17_Cargo02_V1.rtm";
			speed=0.27000001;
			connectTo[]=
			{
				"Mi17_Cargo02",
				0.1
			};
			interpolateTo[]=
			{
				"KIA_Mi17_Cargo02",
				0.1
			};
			variantAfter[]={3.7,3.7,3.7};
		};
		class Mi17_Cargo02_V2: Mi17_Cargo02
		{
			file="\RDS_StaticW\Anim\Mi17_Cargo02_V2.rtm";
			speed=0.345;
			connectTo[]=
			{
				"Mi17_Cargo02",
				0.1
			};
			interpolateTo[]=
			{
				"KIA_Mi17_Cargo02",
				0.1
			};
			variantAfter[]={3,3,3};
		};
		class Mi17_Cargo02_V3: Mi17_Cargo02
		{
			file="\RDS_StaticW\Anim\Mi17_Cargo02_V3.rtm";
			speed=0.2;
			connectTo[]=
			{
				"Mi17_Cargo02",
				0.1
			};
			interpolateTo[]=
			{
				"KIA_Mi17_Cargo02",
				0.1
			};
			variantAfter[]={5,5,5};
		};
		class Mi17_Cargo02_V4: Mi17_Cargo02
		{
			file="\RDS_StaticW\Anim\Mi17_Cargo02_V4.rtm";
			speed=0.20100001;
			connectTo[]=
			{
				"Mi17_Cargo02",
				0.1
			};
			interpolateTo[]=
			{
				"KIA_Mi17_Cargo02",
				0.1
			};
			variantAfter[]={5,5,5};
		};
		class Mi17_Cargo02_V5: Mi17_Cargo02
		{
			file="\RDS_StaticW\Anim\Mi17_Cargo02_V5.rtm";
			speed=0.197;
			connectTo[]=
			{
				"Mi17_Cargo02",
				0.1
			};
			interpolateTo[]=
			{
				"KIA_Mi17_Cargo02",
				0.1
			};
			variantAfter[]={5,5,5};
		};
		class Mi17_Cargo02_V6: Mi17_Cargo02
		{
			file="\RDS_StaticW\Anim\Mi17_Cargo02_V6.rtm";
			speed=0.345;
			connectTo[]=
			{
				"Mi17_Cargo02",
				0.1
			};
			interpolateTo[]=
			{
				"KIA_Mi17_Cargo02",
				0.1
			};
			variantAfter[]={3,3,3};
		};
		class D30_Commander: Crew
		{
			file=RDS_StaticW\Anim\D30_Commander.rtm;
			connectTo[]={Static_Dead,1};		//ToDo: own death anim?
		};
		class D30_Gunner: Crew
		{
			file=RDS_StaticW\Anim\D30_Gunner.rtm;
			connectTo[]={Static_Dead,1};		//ToDo: own death anim?
		};
		class D30_Cargo: Crew
		{
			file=RDS_StaticW\Anim\D30_Cargo.rtm;
			connectTo[]={Static_Dead,1};		//ToDo: own death anim?
		};

		class M119_Commander: Crew
		{
			file = "RDS_StaticW\Anim\M119_Commander.rtm";
			connectTo[] = {"Static_Dead",1};
		};
		class M119_Gunner: Crew
		{
			file = "RDS_StaticW\Anim\M119_Gunner.rtm";
			connectTo[] = {"Static_Dead",1};
		};
		class M119_Cargo: Crew
		{
			file = "RDS_StaticW\Anim\M119_Cargo.rtm";
			connectTo[] = {"Static_Dead",1};
		};
		class M2_Gunner: DShKM_Gunner
		{
			file = "RDS_StaticW\Anim\M2_Gunner.rtm";
		};
		class TOW_Gunner: Crew
		{
			file=RDS_StaticW\Anim\D30_Cargo.rtm;
			connectTo[] = {"Static_Dead",1};
		};



	};
};