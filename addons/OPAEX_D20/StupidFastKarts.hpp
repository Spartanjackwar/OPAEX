class OPAEX_Kart01: C_Kart_01_F {
	maxSpeed = 10000;
	enginePower = 100000;
	peakTorque = 360000;
	displayName = "Totally normal kart";
	
	class complexGearbox
	{
		GearboxRatios[] = {
			"R1", -20,
			"N", 0,
			"D1", 20,
			"D2", 10
			/*
			"D1", 5.88,
			"D2", 2.94,
			"D3", 1.96,
			"D4", 1.47,
			"D5", 1.77,
			"D6", 0.92,
			"D7", 0.84,
			"D8", 0.73,
			"D9", 0.65,
			"D10", 0.58
			*/
		};
		TransmissionRatios[] = {"High", 0.37};
		gearBoxMode = "auto";
		moveOffGear = 1;
		driveString = "D";
		neutralString = "N";
		reverseString = "R";
	};
	
	class Wheels
	{
		/*
		class LF: LF
		{
			longitudinalStiffnessPerUnitGravity = 430000;
			latStiffX = 150;
			latStiffY = 2200;
		};
		class LR: LR
		{
			longitudinalStiffnessPerUnitGravity = 430000;
			latStiffX = 150;
			latStiffY = 2200;
		};
		class RF: RF
		{
			longitudinalStiffnessPerUnitGravity = 430000;
			latStiffX = 150;
			latStiffY = 2200;
		};
		class RR: RR
		{
			longitudinalStiffnessPerUnitGravity = 430000;
			latStiffX = 150;
			latStiffY = 2200;
		};
		*/
		
		class LF
		{
			boneName = "wheel_1_1_damper";
			side = "left";
			center = "wheel_1_1_axis_fake";
			boundary = "wheel_1_1_bound";
			
			//Basics and driveline
			steering = 1;
			width = 0.12;
			mass = 15;
			MOI = 2.423;
			maxBrakeTorque = 10;
			maxHandBrakeTorque = 0;
			
			//Springs
			dampingRate = 0.5;
			dampingRateDamaged = 5;
			dampingRateDestroyed = 5000;
			suspTravelDirection[] = {0, -1, 0};
			suspForceAppPointOffset = "wheel_1_1_suspForce";
			tireForceAppPointOffset = "wheel_1_1_tireForce";
			maxCompression = 0.1;
			maxDroop = 0.1;
			sprungMass = 40;
			springStrength = 61375;
			springDamperRate = 3142;
			
			longitudinalStiffnessPerUnitGravity = 43000;
			latStiffX = 15;
			latStiffY = 220;
			//frictionVsSlipGraph[] = {{0, 2}, {0.5, 1}, {1, 1.7}};
			frictionVsSlipGraph[] = {
				{0, 4},
				{0.5, 2},
				{1, 1}
			};
		};
		class LR: LF
		{
			boneName = "wheel_1_2_damper";
			steering = 0;
			center = "wheel_1_2_axis_fake";
			boundary = "wheel_1_2_bound";
			maxBrakeTorque = 1400;
			width = 0.2;
			suspForceAppPointOffset = "wheel_1_2_suspForce";
			tireForceAppPointOffset = "wheel_1_2_tireForce";
			//frictionVsSlipGraph[] = {{0, 2.2}, {0.5, 1}, {1, 2.1}};
		};
		class RF: LF
		{
			boneName = "wheel_2_1_damper";
			center = "wheel_2_1_axis_fake";
			boundary = "wheel_2_1_bound";
			suspForceAppPointOffset = "wheel_2_1_suspForce";
			tireForceAppPointOffset = "wheel_2_1_tireForce";
			steering = 1;
			side = "right";
		};
		class RR: RF
		{
			boneName = "wheel_2_2_damper";
			steering = 0;
			center = "wheel_2_2_axis_fake";
			boundary = "wheel_2_2_bound";
			maxBrakeTorque = 1400;
			width = 0.2;
			suspForceAppPointOffset = "wheel_2_2_suspForce";
			tireForceAppPointOffset = "wheel_2_2_tireForce";
			//frictionVsSlipGraph[] = {{0, 2.2}, {0.5, 1}, {1, 2.1}};
		};
	
	};
};