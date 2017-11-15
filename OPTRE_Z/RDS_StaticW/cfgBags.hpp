

	class Bag_Base;
	class Weapon_Bag_Base: Bag_Base
	{
		class assembleInfo;
	};
	class RDS_DShkM_Gun_Bag: Weapon_Bag_Base
	{
		author="$STR_A3_Bohemia_Interactive";
		displayName="DShkM Gun Bag";
		_generalMacro="DSHKM_Ins";
		mass=380;
		model = "\RDS_StaticW\bags\StaticX.p3d";
		picture = "\RDS_StaticW\bags\staticX_CA.paa";
		icon = "\RDS_StaticW\bags\mapIcon_backpack_CA.paa";
		class assembleInfo
		{
			primary=0;
			base="";
			assembleTo="";
			dissasembleTo[]={};
			displayName="";
		};
		faction="IND_F";
	};
	class RDS_DShkM_TripodHigh_Bag: Weapon_Bag_Base
	{
		mass=420;
		author="$STR_A3_Bohemia_Interactive";
		displayName="DShkM High Tripod Bag";
		_generalMacro="DSHKM_AAF";
		model = "\RDS_StaticW\bags\StaticY.p3d";
		picture = "\RDS_StaticW\bags\staticY_CA.paa";
		icon = "\RDS_StaticW\bags\mapIcon_backpack_CA.paa";
		faction="IND_F";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_HMG_01_Wpn_assembleInfo0";
			assembleTo="RDS_DSHKM_AAF";
			base[]=
			{
				"RDS_DShkM_Gun_Bag"
			};
		};
	};
	class RDS_DShkM_TripodLow_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=300;
		displayName="DShkM Low Tripod Bag";
		class assembleInfo: assembleInfo
		{
			assembleTo="RDS_DSHkM_Mini_TriPod";
		};
	};
	class RDS_Kord_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="Kord Gun Bag";
		_generalMacro="RDS_KORD_AAF";
		mass=250;
	};
	class RDS_Kord_Tripod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=450;
		displayName="Kord Tripod Bag";
		_generalMacro="RDS_Kord_AAF";
		class assembleInfo: assembleInfo
		{
			assembleTo="RDS_Kord_AAF";
			base[]=
			{
				"RDS_Kord_Gun_Bag"
			};
		};
	};
	class RDS_Metis_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="Metis Gun Bag";
		_generalMacro="RDS_Metis";
		mass=80;
	};
	class RDS_Metis_Tripod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=70;
		displayName="Metis Tripod Bag";
		_generalMacro="RDS_Metis_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_AT_01_Wpn_assembleInfo0";
			assembleTo="RDS_Metis_AAF";
			base[]=
			{
				"RDS_Metis_Gun_Bag"
			};
		};
	};
	class RDS_AGS30_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="AGS30 Gun Bag";
		_generalMacro="RDS_AGS_AAF";
		mass=100;
	};
	class RDS_AGS30_Tripod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=60;
		displayName="AGS30 Tripod Bag";
		_generalMacro="RDS_AGS_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_gmg_01_Wpn_assembleInfo0";
			assembleTo="RDS_AGS_AAF";
			base[]=
			{
				"RDS_AGS30_Gun_Bag"
			};
		};
	};
	class RDS_SPG9_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="SPG9 Gun Bag";
		_generalMacro="RDS_SPG9_AAF";
		mass=470;
	};
	class RDS_SPG9_Tripod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=110;
		displayName="SPG9 Tripod Bag";
		_generalMacro="RDS_SPG9_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_AT_01_Wpn_assembleInfo0";
			assembleTo="RDS_SPG9_AAF";
			base[]=
			{
				"RDS_SPG9_Gun_Bag"
			};
		};
	};
	class RDS_Podnos_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="Podnos Gun Bag";
		_generalMacro="RDS_2b14_82mm_AAF";
		mass=162;
	};
	class RDS_Podnos_Bipod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=139;
		displayName="Podnos Bipod Bag";
		_generalMacro="RDS_2b14_82mm_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_Mortar_01_Wpn_assembleInfo0";
			assembleTo="RDS_2b14_82mm_AAF";
			base[]=
			{
				"RDS_Podnos_Gun_Bag"
			};
		};
	};



	class RDS_M2_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="M2 Gun Bag";
		_generalMacro="RDS_M2StaticMG_AAF";
		mass=382;
	};
	class RDS_M2_Tripod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=250;
		displayName="M2 Tripod Bag";
		_generalMacro="RDS_M2StaticMG_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_HMG_01_Wpn_assembleInfo0";
			assembleTo="RDS_M2StaticMG_AAF";
			base[]=
			{
				"RDS_M2_Gun_Bag"
			};
		};
	};
	class RDS_M2_MiniTripod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=200;
		displayName="M3 Minitripod Bag";
		_generalMacro="RDS_M2StaticMG_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_HMG_01_Wpn_assembleInfo0";
			assembleTo="RDS_M2StaticMG_AAF";
			base[]=
			{
				"RDS_M2_Gun_Bag"
			};
		};
	};
	class RDS_Mk19_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="Mk19 Gun Bag";
		_generalMacro="RDS_Mk19_AAF";
		mass=302;
	};
	class RDS_Mk19_Tripod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=139;
		displayName="Mk19 Tripod Bag";
		_generalMacro="RDS_Mk19_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_gmg_01_Wpn_assembleInfo0";
			assembleTo="RDS_MK19_TriPod_AAF";
			base[]=
			{
				"RDS_Mk19_Gun_Bag"
			};
		};
	};
	class RDS_Tow_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="TOW Gun Bag";
		_generalMacro="RDS_TOW_AAF";
		mass=302;
	};
	class RDS_TOW_Tripod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=139;
		displayName="TOW Tripod Bag";
		_generalMacro="RDS_TOW_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_AT_01_Wpn_assembleInfo0";
			assembleTo="RDS_TOW_TriPod_AAF";
			base[]=
			{
				"RDS_TOW_Gun_Bag"
			};
		};
	};
	class RDS_M252_Gun_Bag: RDS_DShkM_Gun_Bag
	{
		displayName="M252 Gun Bag";
		_generalMacro="RDS_M252_AAF";
		mass=162;
	};
	class RDS_M252_Bipod_Bag: RDS_DShkM_TripodHigh_Bag
	{
		mass=339;
		displayName="M252 Tripod Bag";
		_generalMacro="RDS_M252_AAF";
		class assembleInfo: assembleInfo
		{
			displayName="$STR_A3_CfgVehicles_B_Mortar_01_Wpn_assembleInfo0";
			assembleTo="RDS_M252_AAF";
			base[]=
			{
				"RDS_M252_Gun_Bag"
			};
		};
	};


/*
	class Tank_Gun_Bag: DShkM_Gun_Bag
	{
		mass=170;
		displayName="Bag full of gun parts";
		_generalMacro="V40ExTank";
	};
	class Tank_Wheele_Bag: DShkM_Gun_Bag
	{
		mass=170;
		displayName="Bag full of wheeles";
		_generalMacro="V40ExTank";
	};
	class Tank_Metal_Bag: DShkM_Gun_Bag
	{
		mass=170;
		displayName="Bag full of metal parts";
		_generalMacro="V40ExTank";
	};
	class Tank_Engine_Bag: DShkM_Gun_Bag
	{
		mass=170;
		displayName="Bag full of engine parts";
		_generalMacro="V40ExTank";
	};
	class Vodka_Bag: DShkM_TripodHigh_Bag
	{
		mass=139;
		displayName="Bag full of vodka";
		_generalMacro="V40ExTank";
		class assembleInfo: assembleInfo
		{
			assembleTo="V40ExTank";
			base[]=
			{
				"Tank_Gun_Bag",
				"Tank_Wheele_Bag",
				"Tank_Metal_Bag",
				"Tank_Engine_Bag"
			};
		};
	};*/