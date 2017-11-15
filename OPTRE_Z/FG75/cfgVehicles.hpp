#define crewMacro(sideN,factionN,crewN) \
		side=sideN; \
		faction=factionN; \
		crew=crewN; \
		typicalCargo[]= {crewN};

//Faction Name Macro
#define mF1 IND_F
//Crew Name Macro 
#define mC1 I_Soldier_F
//FIA
#define mF2 BLU_G_F
#define mC2 B_G_Soldier_F
//CSAT
#define mF3 OPF_F
#define mC3 O_Soldier_F

class CfgVehicles
{
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets;
		class MainTurret;
	};
	class StaticMGWeapon: StaticWeapon{};
	class StaticATWeapon:StaticWeapon {};
	class StaticAAWeapon:StaticWeapon {};
	class StaticCannon: StaticWeapon {class ViewOptics;};

	class StaticGrenadeLauncher:StaticWeapon {class ViewOptics;};
	class StaticMortar:StaticWeapon{};
//#########################ZU23
	// D30
	class OPTREZ_FG75: StaticCannon
	{
		accuracy = 0.12;
		cost = 10000;
		availableForSupportTypes[]= {};
		artilleryScanner = 0;
		displayName= "FG75";

		model="\FG75\FG75";
		//icon= "RDS_StaticW\data\map_ico\icomap_d30_CA.paa";
		//picture="\RDS_StaticW\data\ico\d30_CA.paa";
		//UiPicture="\RDS_StaticW\data\ico\d30_CA.paa";

		mapSize = 4.5;
		cargoAction[] = {D30_Cargo,D30_Commander};
		typicalCargo[]={I_Soldier_F,I_Soldier_F,I_Soldier_F};
		transportSoldier = 2;
		gunnerHasFlares = true;
		
		memoryPointsGetInCargo = "pos_cargo_dir";
		memoryPointsGetInCargoDir = "pos_cargo";		
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunBeg="Usti hlavne";
				gunEnd="Konec hlavne";
				weapons[]={OPTREZ_cannon_FG75};
				magazines[] = 	
				{
					"RDS_30Rnd_122mmAT_D30",
					"RDS_30Rnd_122mmHE_D30",
					"RDS_30Rnd_122mmWP_D30"
				};
				gunnerAction = "D30_Gunner";
				//gunnerOpticsModel = "\RDS_StaticW\2Dscope_D30";
				//gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";
				
				minElev=-9;
				maxelev = 80;
				minTurn=-180;
				maxTurn=180;
				class ViewOptics: ViewOptics
				{
					initFov=0.096; minFov=0.096; maxFov=0.096; //FOV 11 deg
				};
			};
		};
		class AnimationSources
		{
			class recoil_source
			{
				source="reload";
				weapon="RDS_D30";
			};
			class leftT_source {source="user";animPeriod = 1;initPhase=-2.3; };
			class rightT_source: leftT_source {initPhase=0; };
			class leftW_source: leftT_source {initPhase=-1.7; };
			class rightW_source: leftW_source {};
			class maingunT_source {source="user";animPeriod = 1;initPhase=0; };
			class mainTurretT_source: maingunT_source {};
			class szpilki_source {source="user";animPeriod = 0.1;initPhase=0; };
		};
		//class Damage
		//{
		//	tex[]={};
		//	mat[]={
		//		"RDS_StaticW\D30\data\d30.rvmat",
		//		"RDS_StaticW\D30\data\d30_damage.rvmat",
		//		"RDS_StaticW\D30\data\d30_destruct.rvmat"
		//	};
		//};
		class Library {libTextDesc = $STR_LIB_D30;};
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 450;
	};
};