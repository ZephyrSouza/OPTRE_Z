class CfgPatches
{
	class RDS_StaticWeapons_Aggressors
	{
		units[]=
		{
			"RDS_ZU23_CAG_ME",
			"RDS_DSHKM_CAG_ME",
			"RDS_DSHkM_Mini_TriPod_CAG_ME",
			"RDS_KORD_CAG_ME",
			"RDS_KORD_high_CAG_ME",
			"RDS_AGS_CAG_ME",
			"RDS_Metis_CAG_ME",
			"RDS_SPG9_CAG_ME",
			"RDS_Igla_AA_pod_CAG_ME",
			"RDS_2b14_82mm_CAG_ME",
			"RDS_D30_CAG_ME",
			"RDS_D30_AT_CAG_ME",

			"RDS_ZU23_CAG_EUR",
			"RDS_DSHKM_CAG_EUR",
			"RDS_DSHkM_Mini_TriPod_CAG_EUR",
			"RDS_KORD_CAG_EUR",
			"RDS_KORD_high_CAG_EUR",
			"RDS_AGS_CAG_EUR",
			"RDS_Metis_CAG_EUR",
			"RDS_SPG9_CAG_EUR",
			"RDS_Igla_AA_pod_CAG_EUR",
			"RDS_2b14_82mm_CAG_EUR",
			"RDS_D30_CAG_EUR",
			"RDS_D30_AT_CAG_EUR",

			"RDS_ZU23_CAG_AFR",
			"RDS_DSHKM_CAG_AFR",
			"RDS_DSHkM_Mini_TriPod_CAG_AFR",
			"RDS_KORD_CAG_AFR",
			"RDS_KORD_high_CAG_AFR",
			"RDS_AGS_CAG_AFR",
			"RDS_Metis_CAG_AFR",
			"RDS_SPG9_CAG_AFR",
			"RDS_Igla_AA_pod_CAG_AFR",
			"RDS_2b14_82mm_CAG_AFR",
			"RDS_D30_CAG_AFR",
			"RDS_D30_AT_CAG_AFR"

		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"RDS_StaticWeapons_Core",
			"caf_ag_faction_me",
			"caf_ag_faction_eur",
			"caf_ag_faction_afr"
		};
	};
};

#include "basicDefines.hpp"

#define crewMacro(factionN,crewN) \
		side=0; \
		faction=factionN; \
		crew=crewN; \
		typicalCargo[]= {crewN};

#define crewMacro2(factionN,crewN) \
		side=0; \
		faction=factionN; \
		crew=crewN; \
		typicalCargo[]= {crewN,crewN};

#define crewMacro3(factionN,crewN) \
		side=0; \
		faction=factionN; \
		crew=crewN; \
		typicalCargo[]= {crewN,crewN,crewN};


class CfgVehicles
{

	class RDS_ZU23_AAF;
	class RDS_DSHKM_AAF;
	class RDS_DSHkM_Mini_TriPod;
	class RDS_KORD_AAF;
	class RDS_KORD_high_AAF;
	class RDS_AGS_AAF;
	class RDS_Metis_AAF;
	class RDS_SPG9_AAF;
	class RDS_Igla_AA_pod_AAF;
	class RDS_2b14_82mm_AAF;
	class RDS_D30_AAF;
	class RDS_D30_AT_AAF;

	//Middle East

	//Faction Name Macro
	#define mF1 caf_ag_me_t
	//Crew Name Macro
	#define mC1 CAF_AG_ME_T_AK74
	class RDS_ZU23_CAG_ME: RDS_ZU23_AAF {crewMacro(mF1,mC1)};
	class RDS_DSHKM_CAG_ME: RDS_DSHKM_AAF {crewMacro(mF1,mC1)};
	class RDS_DSHkM_Mini_TriPod_CAG_ME: RDS_DSHkM_Mini_TriPod {crewMacro(mF1,mC1)};
	class RDS_KORD_CAG_ME: RDS_KORD_AAF {crewMacro(mF1,mC1)};
	class RDS_KORD_high_CAG_ME: RDS_KORD_high_AAF {crewMacro(mF1,mC1)};
	class RDS_AGS_CAG_ME: RDS_AGS_AAF {crewMacro(mF1,mC1)};
	class RDS_Metis_CAG_ME: RDS_Metis_AAF {crewMacro(mF1,mC1)};
	class RDS_SPG9_CAG_ME: RDS_SPG9_AAF {crewMacro(mF1,mC1)};
	class RDS_Igla_AA_pod_CAG_ME: RDS_Igla_AA_pod_AAF {crewMacro(mF1,mC1)};
	class RDS_2b14_82mm_CAG_ME: RDS_2b14_82mm_AAF {crewMacro2(mF1,mC1)};
	class RDS_D30_CAG_ME: RDS_D30_AAF {crewMacro3(mF1,mC1)};
	class RDS_D30_AT_CAG_ME: RDS_D30_AT_AAF {crewMacro3(mF1,mC1)};

	//East Europe

	//Faction Name Macro
	#define mF2 caf_ag_eeur_r
	//Crew Name Macro
	#define mC2 CAF_AG_eeur_r_AK74
	class RDS_ZU23_CAG_EUR: RDS_ZU23_AAF {crewMacro(mF2,mC2)};
	class RDS_DSHKM_CAG_EUR: RDS_DSHKM_AAF {crewMacro(mF2,mC2)};
	class RDS_DSHkM_Mini_TriPod_CAG_EUR: RDS_DSHkM_Mini_TriPod {crewMacro(mF2,mC2)};
	class RDS_KORD_CAG_EUR: RDS_KORD_AAF {crewMacro(mF2,mC2)};
	class RDS_KORD_high_CAG_EUR: RDS_KORD_high_AAF {crewMacro(mF2,mC2)};
	class RDS_AGS_CAG_EUR: RDS_AGS_AAF {crewMacro(mF2,mC2)};
	class RDS_Metis_CAG_EUR: RDS_Metis_AAF {crewMacro(mF2,mC2)};
	class RDS_SPG9_CAG_EUR: RDS_SPG9_AAF {crewMacro(mF2,mC2)};
	class RDS_Igla_AA_pod_CAG_EUR: RDS_Igla_AA_pod_AAF {crewMacro(mF2,mC2)};
	class RDS_2b14_82mm_CAG_EUR: RDS_2b14_82mm_AAF {crewMacro2(mF2,mC2)};
	class RDS_D30_CAG_EUR: RDS_D30_AAF {crewMacro3(mF2,mC2)};
	class RDS_D30_AT_CAG_EUR: RDS_D30_AT_AAF {crewMacro3(mF2,mC2)};

	//Africa

	//Faction Name Macro
	#define mF3 caf_ag_afr_p
	//Crew Name Macro
	#define mC3 CAF_AG_afr_p_AK74
	class RDS_ZU23_CAG_AFR: RDS_ZU23_AAF {crewMacro(mF3,mC3)};
	class RDS_DSHKM_CAG_AFR: RDS_DSHKM_AAF {crewMacro(mF3,mC3)};
	class RDS_DSHkM_Mini_TriPod_CAG_AFR: RDS_DSHkM_Mini_TriPod {crewMacro(mF3,mC3)};
	class RDS_KORD_CAG_AFR: RDS_KORD_AAF {crewMacro(mF3,mC3)};
	class RDS_KORD_high_CAG_AFR: RDS_KORD_high_AAF {crewMacro(mF3,mC3)};
	class RDS_AGS_CAG_AFR: RDS_AGS_AAF {crewMacro(mF3,mC3)};
	class RDS_Metis_CAG_AFR: RDS_Metis_AAF {crewMacro(mF3,mC3)};
	class RDS_SPG9_CAG_AFR: RDS_SPG9_AAF {crewMacro(mF3,mC3)};
	class RDS_Igla_AA_pod_CAG_AFR: RDS_Igla_AA_pod_AAF {crewMacro(mF3,mC3)};
	class RDS_2b14_82mm_CAG_AFR: RDS_2b14_82mm_AAF {crewMacro2(mF3,mC3)};
	class RDS_D30_CAG_AFR: RDS_D30_AAF {crewMacro3(mF3,mC3)};
	class RDS_D30_AT_CAG_AFR: RDS_D30_AT_AAF {crewMacro3(mF3,mC3)};

};