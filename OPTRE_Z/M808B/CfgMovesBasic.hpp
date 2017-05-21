class CfgMovesBasic
	{
		class Actions;
		class DefaultDie;
		class ManActions
		{
			Driver_OPTRE_M808B = "Driver_OPTRE_M808B";
			Cargo_1_OPTRE_M808B = "Cargo_1_OPTRE_M808B";
			Cargo_2_OPTRE_M808B = "Cargo_2_OPTRE_M808B";

		};
	};

	class CfgMovesMaleSdr: CfgMovesBasic
	{
		class States
		{
			class Crew;
			class Driver_OPTRE_M808B: Crew
			{
				file = "\M808B\data\Anim\Driver_OPTRE_M808B.rtm";
			};
			class Cargo_1_OPTRE_M808B: Crew
			{
				file = "\M808B\data\Anim\Cargo_1_OPTRE_M808B.rtm";
			};
			class Cargo_2_OPTRE_M808B: Crew
			{
				file = "\M808B\data\Anim\Cargo_2_OPTRE_M808B.rtm";
			};
		};	
	};