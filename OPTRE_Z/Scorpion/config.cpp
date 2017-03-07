class CfgPatches
{
	class OPTRE_Vehicles_Scorpion
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
		magazines[] = {};
		ammo[] = {};
	};
};
class CfgVehicles {
	class LandVehicle;
	class Tank: LandVehicle {
		class NewTurret;
		class Sounds;
		class HitPoints;
	};
	class Tank_F: Tank {
		class Turrets {
			class MainTurret:NewTurret {
				class Turrets {
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints {
			class HitHull;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds {
			class Engine;
			class Movement;
		};
	};
	class OPTRE_M808_base: Tank_F
	{
		dlc = "OPTRE";
		author = "Article 2 Studios";
		displayName = "";
		class Library
		{
			libTextDesc = "The M808B Main Battle Tank, commonly known as the Scorpion, is the most common armored fighting vehicle employed by the UNSC, it is used in operations requiring heavy firepower or an anti-vehicular platform. Combining firepower, resilience and mobility, the Scorpion has proven itself formidable and earned the respect of friend and foe alike.";
		};
		model = "OPTRE_Vehicles\Scorpion\scorpion_base.p3d";
		//picture = "OPTRE_Vehicles\Scorpion\Data\picture.paa";
		//Icon = "OPTRE_Vehicles\Scorpion\Data\icon.paa";
		picture = "OPTRE_Vehicles\Warthog\Data\picture.paa";
		Icon = "OPTRE_Vehicles\Warthog\Data\icon.paa";
		mapSize = 11.44;
		#include "physx.hpp"
		transportMaxBackpacks = 4;
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		vehicleClass = "OPTRE_UNSC_Vehicle_class";
		transportSoldier = 0;
		crewVulnerable = 0;
		crewCrashProtection = 0;
		crewExplosionProtection = 0.9;
		fuelExplosionPower = 2;
		epeImpulseDamageCoef = 25;
		armor = 900;
		armorStructural = 6;
		cost = 500000;
		canFloat = 0;
		threat[] = {1,1,0.3};
		destrType = "DestructBuilding";
		ejectDeadGunner = 0;
		//Put reflectors and exhaust stuff here
		/*class AnimationSources: AnimationSources
		{
			class muzzle_rot_cannon
			{
				source = "ammoRandom";
				weapon = "OPTRE_M512";
			};
			class muzzle_rot_mg: muzzle_rot_cannon
			{
				weapon = "OPTRE_M247T";
			};
		};*/
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor = 0.6;
				material = -1;
				name = "HitHull";
				visual = "Hull";
				passThrough = 1;
				minimalHit = 0.2;
				explosionShielding = 0.2;
				radius = 0.25;
			};
			class HitEngine: HitEngine
			{
				armor = 0.6;
				material = -1;
				name = "HitEngine";
				passThrough = 0.5;
				minimalHit = 0.2;
				explosionShielding = 0.2;
				radius = 0.25;
			};
			class HitLTrack: HitLTrack
			{
				armor = 0.3;
				material = -1;
				name = "HitLTrack";
				visual = "trackLeft";
				passThrough = 0;
				minimalHit = 0.15;
				explosionShielding = 0.4;
				radius = 0.25;
			};
			class HitRTrack: HitRTrack
			{
				armor = 0.3;
				material = -1;
				name = "HitRTrack";
				visual = "trackRight";
				passThrough = 0;
				minimalHit = 0.15;
				explosionShielding = 0.4;
				radius = 0.25;
			};
		};
		class RenderTargets
		{
			class FrontView
			{
				renderTarget = "rendertarget0";
				class CameraView1
				{
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 0;
					fov = 1.2;
				};
			};
			class FrontViewNV
			{
				renderTarget = "rendertarget1";
				class CameraView1
				{
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 1;
					fov = 0.65;
				};
			};
			class FrontViewTI
			{
				renderTarget = "rendertarget2";
				class CameraView1
				{
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 2;
					fov = 0.7;
				};
			};
			class TurretViewTI
			{
				renderTarget = "rendertarget3";
				class CameraView1
				{
					pointPosition = "PIP2_pos";
					pointDirection = "PIP2_dir";
					renderQuality = 2;
					renderVisionMode = 2;
					fov = 0.7;
				};
			};
			class RearView
			{
				renderTarget = "rendertarget4";
				class CameraView1
				{
					pointPosition = "PIP1_pos";
					pointDirection = "PIP1_dir";
					renderQuality = 2;
					renderVisionMode = 0;
					fov = 0.7;
				};
			};
			class RearViewNV
			{
				renderTarget = "rendertarget5";
				class CameraView1
				{
					pointPosition = "PIP1_pos";
					pointDirection = "PIP1_dir";
					renderQuality = 2;
					renderVisionMode = 1;
					fov = 0.7;
				};
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				body = "turret";
				gun = "gun";
				animationsourcebody = "mainturret";
				animationSourceGun = "maingun";
				gunAxis = "gun_axis";
				gunBeg = "cannon_begin";
				gunEnd = "cannon_end";
				minElev = -10;
				maxElev = 60;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				turretAxis = "turret_axis";
				maxHorizontalRotSpeed = 1.5;
				maxVerticalRotSpeed = 1.5;
				gunnerAction = "mbt2_slot2a_in";
				gunnerInAction = "mbt2_slot2a_in";
				gunnerGetInAction = "GetInMRAP_01";
				gunnerGetOutAction = "GetOutMRAP_01";
				gunnerName = "Gunner";
				hideWeaponsGunner = 0;
				soundServo[] = {"",0.01,1};
				stabilizedInAxes = 3;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				commanding = 1;
				primaryGunner = 1;
				turretInfoType = "RscWeaponZeroing";
				memoryPointsGetInGunner = "Pos_Gunner";
				memoryPointsGetInGunnerDir = "Pos_Gunner_dir";
				gunnerLeftHandAnimName = "trigger";
				gunnerRightHandAnimName = "trigger";
				memoryPointGun = "coax_end";
				weapons[]={"cannon_120mm", "LMG_M200"};
				magazines[]={32Rnd_120mm_APFSDS_shells_Tracer_Red, 16Rnd_120mm_HE_shells_Tracer_Red, 2000Rnd_65x39_belt};
				memoryPointGunnerOptics = "gunnerview";
				gunnerOpticsShowCursor = 1;
				castGunnerShadow = 1;
				startEngine = 0;
				enableManualFire = 0;
				gunnerOpticsModel = "a3\weapons_f\Reticle\optics_empty";
				gunnerForceOptics = 0;
				hasGunner = 1;
				class ViewGunner: ViewOptics
				{
					initAngleX = -15;
					minAngleX = -45;
					maxAngleX = 45;
					initFov = 0.9;
					minFov = 0.42;
					maxFov = 0.9;
					visionMode[] = {};
				};
			};
		};
	};
	class OPTRE_M808_Green: OPTRE_M808_base
	{
		scope = 2;
		displayName = "M808B Scorpion";
	};
	class OPTRE_M808_Urban: OPTRE_M808_Green
	{
		displayName = "M808B Scorpion Urban";
		hiddenSelections[] = {"camo", "camo1", "glass"};
		hiddenSelectionsTextures[] = {"\OPTRE_Vehicles\Scorpion\data\Scorpion_Exterior_01_CO.paa","\OPTRE_Vehicles\Scorpion\data\Scorpion_Exterior_02_CO.paa"};
		hiddenSelectionsMaterials[] = {"\OPTRE_Vehicles\Scorpion\Data\scorpion_glass.rvmat"};
	};
};