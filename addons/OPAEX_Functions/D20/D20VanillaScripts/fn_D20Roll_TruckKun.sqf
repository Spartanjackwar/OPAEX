//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: spawns the ultimate god himself; truck-kun's summoning

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	OPAEX_fnc_D20_SpawnVehicle
*/

params [
	[
		"_d20",
		[0,0,0],
		[[0,0,0]]
	],
	[
		"_thrower",
		objNull,
		[objNull]
	]
];

//We cannot tolerate not being given a thrower
if (isNull _thrower) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

//Pick the truck to use.
_truckModel = selectRandom [
	"B_Truck_01_mover_F",
	"B_Truck_01_ammo_F",
	"B_Truck_01_cargo_F",
	"B_Truck_01_box_F",
	"B_Truck_01_flatbed_F",
	"B_Truck_01_medical_F",
	"B_Truck_01_repair_F",
	"B_Truck_01_transport_F",
	"B_Truck_01_covered_F",
	"O_Truck_02_ammo_F",
	"O_Truck_02_fuel_F",
	"O_Truck_02_medical_F",
	"O_Truck_02_box_F",
	"O_Truck_02_transport_F",
	"O_Truck_02_covered_F",
	"I_Truck_02_ammo_F",
	"I_Truck_02_fuel_F",
	"I_Truck_02_medical_F",
	"I_Truck_02_box_F",
	"I_Truck_02_transport_F",
	"I_Truck_02_covered_F",
	"C_Truck_02_fuel_F",
	"C_Truck_02_box_F",
	"C_Truck_02_transport_F",
	"C_Truck_02_covered_F",
	"C_Tractor_01_F",
	"O_Truck_03_ammo_F",
	"O_Truck_03_fuel_F",
	"O_Truck_03_medical_F",
	"O_Truck_03_repair_F",
	"O_Truck_03_transport_F",
	"O_Truck_03_covered_F",
	"O_Truck_03_device_F",
	"Land_Locomotive_01_v1_F",
	"Land_Locomotive_01_v2_F",
	"Land_Locomotive_01_v3_F"
];

//Pick the speed of obliteration.
_speed = random [1, 61.25, 175]; //m/s are used, so you may have a mach 0.5 truck.

//Figure out the distance to hit the thrower and the spawn position.
_splatterDist = _d20 distance (getPosASL _thrower);
_truckPos = _d20; //There used to be randomization for the spawn point.  I felt it was too random to leave the desired impact.

//Randomly select position.
//_altPos = [[_d20, _splatterDist, _splatterDist, 360, false]] call CBA_fnc_randPosArea;
//_truckPos = selectRandom [_d20, _altPos];

/*//Spawn the banana wall to obscure summoning.
_ACEEnabled = (configFile >> "CfgPatches" >> "ace_medical") call BIS_fnc_getCfgIsClass;
_model = "";
if (!_ACEEnabled) then {
	_model = "\A3\Props_F_Orange\Humanitarian\Supplies\Pumpkin_01_F.p3d";
} else {
	_model = "\z\ace\addons\common\data\banana.p3d";
};
_sizesBanana = [10.0, 0.0];
_bananaLifespan = 2;
_baseVelocity = [0, 0, 1];
_banana = "#particlesource" createVehicle _truckPos;
_banana setParticleRandom [0, [5, 5, 0], [0, 0, 5], 0, 0, [0, 0, 0, 0], 360, 0];
_banana setParticleParams [[_model, 1, 0, 1], "", "SpaceObject", 1, _bananaLifespan, [0, 0, 0], _baseVelocity, 3, 10, 7.9, 0, _sizesBanana, [[1,1,1,1]], [1], 1, 0, "", "", _d20];
_banana setDropInterval 0.001;
sleep 1;
*/

//Do the visuals (this call replaced the original in-script banana wall)
[_d20, 1] remoteExec ["OPAEX_fnc_D20Visuals_BananaWall", 0, False];

//Summon the truck facing the thrower and give it the speed to splatter them.
_truckGroup = (createGroup civilian);
_truckVec = _truckPos vectorFromTo (position _thrower);
_truckDir = _truckPos getDir (position _thrower);
_truckVel = [
	(sin _truckDir * _speed), 
	(cos _truckDir * _speed), 
	0
];
_truck = [_truckGroup, _truckModel, _truckPos] call OPAEX_fnc_D20_SpawnVehicle;
_truck setVectorDir _truckVec;
_truck setVelocity _truckVel;
_timeToSplatter = _splatterDist / _speed;

//Play the horn
[0, false, _truck, "OPAEX_Sound_D20_TruckHorn4", 1000, 1, false, 0] call OPAEX_fnc_RemoteSay3D;

//Remove the banana wall.
//deleteVehicle _banana;

//Await the truck's arrival + some seconds after.
sleep (_timeToSplatter + 3);

//Despawn the truck.
deleteVehicle _truck;
deleteGroup _truckGroup;
