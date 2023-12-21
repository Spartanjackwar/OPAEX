//Jack Moss, aka Spartanjackwar.
/*
D20 grenade roll: Spawns a RGB soldier.

Parameter 0: 3d array: position of the d20 greande.
Parameter 1: object: thrower of the d20.

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.
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

//Do the visuals
[_d20, _thrower] remoteExec ["OPAEX_fnc_D20Visuals_None", 0, False];

//Create the unit
_group = createGroup civilian;
_unit = [_group, "C_Soldier_VR_F", _d20] call OPAEX_fnc_D20_SpawnUnit;

//Disable their AI.
_unit disableAI "autoTarget";

//Create the texture array.
_Textures = [];
_gradientCap = 10; //6*_gradientCap for texture count.
for "_i" from 0 to _gradientCap do {
	_nextTex = format ["#(argb,8,8,3)color(1,%1,0,1)", (_i / _gradientCap)];
	_Textures pushBack _nextTex;
};
for "_i" from _gradientCap to 0 step -1 do {
	_nextTex = format ["#(argb,8,8,3)color(%1,1,0,1)", (_i / _gradientCap)];
	_Textures pushBack _nextTex;
};
for "_i" from 0 to _gradientCap do {
	_nextTex = format ["#(argb,8,8,3)color(0,1,%1,1)", (_i / _gradientCap)];
	_Textures pushBack _nextTex;
};
for "_i" from _gradientCap to 0 step -1 do {
	_nextTex = format ["#(argb,8,8,3)color(0,%1,1,1)", (_i / _gradientCap)];
	_Textures pushBack _nextTex;
};
for "_i" from 0 to _gradientCap do {
	_nextTex = format ["#(argb,8,8,3)color(%1,0,1,1)", (_i / _gradientCap)];
	_Textures pushBack _nextTex;
};
for "_i" from _gradientCap to 0 step -1 do {
	_nextTex = format ["#(argb,8,8,3)color(1,0,%1,1)", (_i / _gradientCap)];
	_Textures pushBack _nextTex;
};

//Set their texture to RGB.
_unit setVariable ["OPAEX_ContinueAnimatingTexture", true, true];
_selections = [];
//_unit setObjectMaterial [0, "\a3\data_f\default.rvmat"];
for "_i" from 0 to (count getObjectTextures _unit) do {
	_selections pushBack _i;
};
[_unit, "OPAEX_ContinueAnimatingTexture", _unit, _selections, _Textures, [], 0.1] spawn OPAEX_fnc_animateTextureLooped;
	
//Do a funny animation
[_unit, "AmovPercMstpSnonWnonDnon_exercisekneeBendB"] remoteExec ["switchMove", 0];
[_unit, "AmovPercMstpSnonWnonDnon_exercisekneeBendB"] remoteExec ["playMoveNow", 0];

//Wait for a while and shut off the animation loop to keep it from overloading the scheduler forever, just in case someone is being silly with this script.
sleep 600;
_unit setVariable ["OPAEX_ContinueAnimatingTexture", false, true]; //Note that a deleted unit will also resolve to false, which is acceptable.