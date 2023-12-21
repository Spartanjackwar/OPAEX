//Jack Moss, aka Spartanjackwar.
//Credits to Karel Moricky, who authored Bohemia's lightning strike module.
/*
Spawns lighting at a position. Unlike BIS, I don't use posATL format for lightning.

Parameter 0: 3d array: position of the impact.

Return: Nothing

Must be executed in a scheduled environment.
Can execute on any client, but should not be propagated across the network to multiple machines.

Dependencies:
	None
*/

params [
	[
		"_pos",
		[0,0,0],
		[[0,0,0]]
	]
];
_dir = random 360;

//--- Play sound (tied to the explosion effect)
_bolt = createvehicle ["LightningBolt",_pos,[],0,"CAN_COLLIDE"];
_bolt setpos _pos;
_bolt setdamage 1;

//Create lightflash
_light = "#lightpoint" createvehicle _pos;
_light setpos [_pos select 0,_pos select 1,(_pos select 2) + 10];
_light setLightDayLight true;
_light setLightBrightness 300;
_light setLightAmbient [0.05, 0.05, 0.1];
_light setlightcolor [1, 1, 2];

//Dim the lightflash
sleep 0.1;
_light setLightBrightness 0;
sleep (random 0.1);

//Pew pew lightning
_class = ["lightning1_F","lightning2_F"] call BIS_fnc_selectrandom;
_lightning = _class createvehicle [100,100,100];
_lightning setdir _dir;
_lightning setpos _pos;

_duration = 3 + random 1;
for "_i" from 0 to _duration do {
	_time = time + 0.1;
	_light setLightBrightness (100 + random 100);
};

deletevehicle _lightning;
deletevehicle _light;