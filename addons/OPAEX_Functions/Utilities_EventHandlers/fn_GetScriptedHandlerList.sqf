//Jack Moss, aka Spartanjackwar.
//Special credit: Karel Moricky and Killzone_Kid, both of who authored BIS_fnc_addScriptedEventHandler, whose implementation taught me how to make this function.
/*
	This function returns all scripted event handlers added to the given namespace.
	Note that there may be more than 1 code type attached per handler name.
	As far as I am aware, it is unlikely that any method to query the handlers for the hardcoded addEventHandler command exists.
	
	Parameter 0: namespace: Anything that can act as a namespace to search within, like an object.
	
	Returns: array of handler names
	
	May be run on any machine.  May be run in unscheduled environments.
	
	Dependencies:
		None
*/
params [
	[
		"_namespace",
		objNull,
		[true, missionNamespace, objNull, grpNull, locationNull, controlNull, displayNull]
	]
];

if (_namespace isEqualType true) then 
{
	_namespace = missionNamespace;
};

//Get all variables in the namespace
_variables = allVariables _namespace;
_handlers = [];

{ //Grab all the handlers
	if (["BIS_fnc_addScriptedEventHandler_", _x, true] call BIS_fnc_inString) then
	{ //Note that _x will be the variable name.  The variable itself is an array of code type.
		_handlers pushBack _x;
	};
} ForEach _variables;

_handlers //Return the list of scriptedEventHandler names