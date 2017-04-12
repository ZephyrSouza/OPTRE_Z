#define _ARMA_
#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"
#include "CfgWeapons.hpp"

class CfgPatches
{
	class OPTRE_static_c
	{
		units[] = 
		{
			"OPTRE_LAU65D_pod"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Static_F","A3_Weapons_F","OPTRE_Core"};
	};
};

	//För att få med Proxy
	class CfgMovesBasic
	{
		class Actions;
		class DefaultDie;
		class ManActions
		{
			Gunner_OPTRE_Lau = "Gunner_OPTRE_Lau";
		};
	};

	class CfgMovesMaleSdr: CfgMovesBasic
	{
		class States
		{
			class Crew;
			class Gunner_OPTRE_Lau: Crew
			{
				file = "LAU65D_pod\data\Anim\Gunner_OPTRE_Lau.rtm";
			};
		};	
	};



class DefaultEventhandlers;
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class ViewPilot;
		class NewTurret;
	};
	class StaticWeapon: LandVehicle
	{
		class AnimationSources;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
				class HitPoints;
			};
		};
	};
	class StaticAAWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};

/****************************** AA - LAU ******************************/


	class OPTRE_LAU65D_pod: StaticAAWeapon
	{
		dlc = "OPTRE";
		scope = 2;
		scopeCurator = 2;
		side = 1;
		faction = "OPTRE_UNSC";
		vehicleClass = "OPTRE_UNSC_Static_class";
		editorSubcategory = "EdSubcat_Turrets";

		displayName = "LAU-65D/SGM-151";
		model = "\LAU65D_pod\LAU65D_pod.p3d";
		picture = "\LAU65D_pod\data\UI\LAU65D_ca.paa";
		icon = "\LAU65D_pod\data\UI\map_LAU65D_ca.paa";
		mapSize = 4;
		nameSound = "veh_static_AA_s";
		getInAction = "GetInlow";
		getOutAction = "GetOutlow";
		radarType = 2;

		

		
		class Turrets: Turrets 
		{
			class MainTurret: MainTurret 
			{

				ejectDeadGunner = 1;
				proxyType = "CPGunner";
				gunnerType= "OPTRE_UNSC_Army_Soldier_Rifleman_AR_WDL";
				proxyIndex = 1;
				weapons[] = {"OPTRE_missiles_ASGM4"};
				magazines[] = {
					"OPTRE_8Rnd_ASGM4_rockets",
					"OPTRE_8Rnd_ASGM4_rockets"
				};
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGun = "usti hlavne";
				body = "Turret_rot";
				animationSourceBody = "Turret_rot";
				animationSourceGun = "camElev";
				selectionFireAnim = "zasleh";
				memoryPointGunnerOptics = "eye";
				cameraDir = "look";
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
				gunnerForceOptics = 1;
				memoryPointsGetInGunner = "pos_gunner";
				memoryPointsGetInGunnerDir = "pos_gunner_dir";
				
				//gunnerInAction = "Gunner_OPTRE_Lau";
				gunnerAction = "Gunner_OPTRE_Lau"; 
				gunnerInAction = "ManActTestDriver";
				gunnergetInAction = "";
				gunnergetOutAction = "";
				stabilizedInAxes = "StabilizedInAxesNone";
				initElev = 0;
				minElev = -15; //KOlla på denna
				maxElev = 40; //KOlla på denna
			
				initCamElev = 0;
				minCamElev = -15;
				maxCamElev = 40;
				
				initTurn = 0;
				minTurn = -360;
				maxTurn = 360;
				
				discreteDistance[] = {1};
				discreteDistanceCameraPoint[] = {"eye"};
				discreteDistanceInitIndex = 0;
				
				class ViewOptics: ViewOptics 
				{
					initAngleX = 0;
					minAngleX = -45;
					maxAngleX = 75;
					initAngleY = 0;
					minAngleY = -120;
					maxAngleY = 120;
					initFov = 0.4;
					minFov = 0.04167;
					maxFov = 0.4;
					thermalMode[] = {0,1};
					visionMode[] = {"Normal","NVG","Ti"};
				};
				class ViewGunner 
				{
					initAngleX = 0;
					minAngleX = -45;
					maxAngleX = 75;
					initAngleY = 0;
					minAngleY = -120;
					maxAngleY = 120;
					initFov = 0.4;
					minFov = 0.4;
					maxFov = 0.4;
				};
				
		
				
			};
		};

		
		class Damage {
			tex[] = {};
			mat[] = {
				"LAU65D_pod\data\LAU-65D_pod_launcher.rvmat","LAU65D_pod\data\LAU-65D_pod_launcher_damage.rvmat","LAU65D_pod\data\LAU-65D_pod_launcher_destruct.rvmat",
				"LAU65D_pod\data\LAU-65D_pod_tripod.rvmat","LAU65D_pod\data\LAU-65D_pod_tripod_damage.rvmat","LAU65D_pod\data\LAU-65D_pod_tripod_destruct.rvmat"
				};
		};
		
		
		
		
	/*	
		class AnimationSources 
		{
			
			class muzzle_rot_missile {source = "ammorandom"; weapon = "OPTRE_missiles_ASGM4";};
			
		};

		class EventHandlers {
		//fired = "_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
		
		
		
		};
				*/
		
		
	};
	
	
	
	
};
