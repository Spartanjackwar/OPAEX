//Jack Moss, aka Spartanjackwar.
/*
Function to animate the textures and materials of an object.
Note that this can be network intensive if the delay is short.
This command is synchronized across all clients, and as such should be used sparringly.

Parameter 0: object: The object we are animating the texture of.
Parameter 1: array of integers or strings: The selections on the object that we will be iterating through.
Parameter 2: array of strings: The array of textures to iterate through.  Can be empty, which will disable setting the textures.
Parameter 3: array of strings: The array of materials to iterate through.  Can be empty, which will disable setting the materials.
Parameter 4: float: The delay, in seconds, between texture iteration.  Minimum value is 0.01 for your own safety.

Return: Nothing.

Example:
	_tgt = player;
	_tgt setObjectMaterial [0, "\a3\data_f\default.rvmat"];
	_Textures = [ 
		"#(argb,8,8,3)color(1,0,0,1)",
		"#(argb,8,8,3)color(1,1,0,1)",
		"#(argb,8,8,3)color(0,1,0,1)",
		"#(argb,8,8,3)color(0,1,1,1)",
		"#(argb,8,8,3)color(0,0,1,1)",
		"#(argb,8,8,3)color(1,0,1,1)"
	];
	[_tgt, [0], _Textures, [], 1] spawn OPAEX_fnc_animateTexture;

Must be executed in a scheduled environment.
Can execute on any client.
*/
params [
	[
		"_target",
		objNull,
		[objNull]
	],
	[
		"_selections",
		[0],
		[[0], [""]]
	],
	[
		"_textureList",
		[],
		[[""]]
	],
	[
		"_materialList",
		[],
		[[""]]
	],
	[
		"_frameDelay",
		0.1,
		[1.0]
	]
];

//I wasn't joking when I said this needs to be placed in a scheduled environment.
if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	Nil
};

//Validate object parameters.
if (isNull _target or _frameDelay < 0.01) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

private["_size"];

//Pad the size of the shortest array with nil until it equals the larger array's size.
_size = (count _materialList) max (count _textureList);
if ((count _materialList) >= (count _textureList)) then {
	_textureList resize _size;
} else {
	_materialList resize _size;
};

//systemChat str(time);
//Iterate the texure list.
for "_i" from 0 to (_size - 1) do {
	//Set the object texture globally.
	if (!isNil {_textureList select _i}) then {
		{
			_target setObjectTextureGlobal [_x, (_textureList select _i)];
		} ForEach _selections;
	};

	//Set the object material globally.
	if (!isNil {_materialList select _i}) then {
		{
			_target setObjectMaterialGlobal [_x, (_materialList select _i)];
		} ForEach _selections;
	};
	
	//Wait for the end of the frame delay.
	sleep _frameDelay;
};