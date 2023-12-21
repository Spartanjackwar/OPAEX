//Jack Moss, aka Spartanjackwar.
/*
Function to run an asynchronous loop that animates the textures and materials of an object.
Note that this can be network intensive if the delay is short.
This command is synchronized across all clients, and as such should be used sparringly.

Parameter 0: namespace: The namespace from which we monitor the loop variable.
Parameter 1: string: The variable name we monitor in the given namespace.
Parameter 2: object: The object we are animating the texture of.
Parameter 3: array of integers or strings: The selections on the object that we will be iterating through.
Parameter 4: array of strings: The array of textures to iterate through.  Can be empty, which will disable setting the textures.
Parameter 5: array of strings: The array of materials to iterate through.  Can be empty, which will disable setting the materials.
Parameter 6: float: The delay, in seconds, between texture iteration.  Minimum value is 0.01 for your own safety.

Return: Nothing.

Example:
	_tgt = player;
	_tgt setVariable ["OPAEX_ContinueAnimatingTexture", true];
	_tgt setObjectMaterial [0, "\a3\data_f\default.rvmat"];
	_Textures = [ 
		"#(argb,8,8,3)color(1,0,0,1)",
		"#(argb,8,8,3)color(1,1,0,1)",
		"#(argb,8,8,3)color(0,1,0,1)",
		"#(argb,8,8,3)color(0,1,1,1)",
		"#(argb,8,8,3)color(0,0,1,1)",
		"#(argb,8,8,3)color(1,0,1,1)"
	];
	[_tgt, "OPAEX_ContinueAnimatingTexture", _tgt, [0], _Textures, [], 0.1] spawn OPAEX_fnc_animateTextureLooped;
	
	sleep 10;
	_tgt setVariable ["OPAEX_ContinueAnimatingTexture", false];

Can be executed in a nonscheduled environment.
Can execute on any client.
*/
params [
	[
		"_namespace",
		missionNamespace,
		[true, missionNamespace, objNull, grpNull, locationNull, controlNull, displayNull]
	],
	[
		"_continueLoopVariableName",
		"OPAEX_ContinueAnimatingTexture",
		[""]
	],
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

//Validate object parameters.
if (isNull _target or _frameDelay < 0.01) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

private["_inputs", "_listSize", "_minimumDelay"];

//Peel the parameters that the normal animateTexture function doesn't expect.
_inputs = + _this; //Deep copy our parameters.
_inputs deleteRange [0, 2];

//Calculate the minimum time to wait before next loop execution.
_listSize = ((count _textureList) max (count _materialList));
_minimumDelay = _frameDelay *  _listSize;

//Run an asynchronous loop where we run the nonlooping version of the function.
[
	_namespace,
	_continueLoopVariableName,
	_minimumDelay,
	_inputs,
	OPAEX_fnc_animateTexture,
	true
] spawn OPAEX_fnc_asynchronousExecutionLoop;