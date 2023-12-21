//Jack Moss, aka Spartanjackwar.
/*
	This function pastes all variables from an object into another object.
	Note that this function would actually work on any two namespaces, not just object pairs.
	
	Parameter 0: namespace: Object to copy from
	Parameter 1: namespace: Object to copy to
	Returns: bool, true if there are any eventhandlers of the given type assigned to the object
	
	May be run on any client.  May run in unscheduled environments
	
	Dependencies:
		None
*/
params
[
	[
		"_copyUnit",
		objNull,
		[true, missionNamespace, objNull, grpNull, locationNull, controlNull, displayNull]
	],
	[
		"_pasteUnit",
		objNull,
		[true, missionNamespace, objNull, grpNull, locationNull, controlNull, displayNull]
	]
];

if (_namespace isEqualType true) then 
{ //From BIS_fnc_AddScriptedEventHandler, not sure why bools are allowed. Added this for consistency.
	_namespace = missionNamespace;
};

//Validate objects
if (isNull _copyUnit or isNull _pasteUnit) exitWith {False};

//Copy Vars
_Vars = allVariables _copyUnit;

{ //Paste vars
	_pasteUnit setVariable [_x, _copyUnit getVariable [_x]];
} ForEach _Vars;

True

