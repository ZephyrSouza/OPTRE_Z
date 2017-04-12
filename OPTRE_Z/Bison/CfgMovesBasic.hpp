class CfgMovesBasic
	{
		class Actions;
		class DefaultDie;
		class ManActions
		{
			Driver_OPTRE_Bison = "Driver_OPTRE_Bison";
			Gunner_OPTRE_Bison = "Gunner_OPTRE_Bison";
		};
	};

	class CfgMovesMaleSdr: CfgMovesBasic
	{
		class States
		{
			class Crew;
			class Driver_OPTRE_Bison: Crew
			{
				file = "Bison\data\Anim\Driver_OPTRE_Bison.rtm";
			};
			class Gunner_OPTRE_Bison: Crew
			{
				file = "Bison\data\Anim\Gunner_OPTRE_Bison.rtm";
			};
		};	
	};