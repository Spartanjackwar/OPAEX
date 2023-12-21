//Jack Moss, aka Spartanjackwar.
/*
Places a model above units surrounding a given unit, and attaches said model to said units.

Parameter 0: object: origin unit from where we check
Parameter 1: int: radius of search in meters
Parameter 2: object or string: Which object to spawn above surrounding units.  Can be a classname.
Parameter 3: list of strings: list of type names to filter out of the search.

Return: List of markerObject references if success.  Nil if failure.

Can be executed in non-scheduled environments.
Execute only on the client.

Dependencies:
	None
*/
params [
	[
		"_originUnit",
		player,
		[objNull]
	],
	[//Search radius, in meters
		"_searchRadius",
		500,
		[1]
	],
	[
		"_markerObject",
		"Sign_Arrow_F",
		[objNull, ""]
	],
	[
		"_filterList",
		["Logic"],
		[[""]] //Array of strings
	],
];
//Local options
_offsetHeight = 2; //Height above the units to spawn the arrow.

//Locally sourced parameters
_list = (getPos _originUnit) nearEntities _searchRadius;
_markerObjectType = "";
_result = Nil;

//Validate the originUnit exists, exit if it doesn't.
if (isNull _originUnit) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	["OPAEX: function returned %1", _result] call BIS_fnc_logFormat;
	_result
};

//Parse _markerObject's type into a string typename
if (objNull isEqualType _markerObject) then
{
	_markerObjectType = typeOf _markerObject
} else {
	_markerObjectType = _markerObject
};

//Validate the name exists, exit if it doesn't.
if ((_markerObjectType isEqualTo "") or (not isClass (configFile >> "CfgVehicles" >> _markerObjectType))) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	["OPAEX: function returned %1", _result] call BIS_fnc_logFormat;
	_result
};

//Filter list of types
_filteredList = _list select {not _x in _filterList}; //Select can filter lists.  Neat eh?

_result = []; //We know that at least the name exists, so I assume the createVehicleLocal will work.
{//Spawn the object above the units found.
	_pos = (getPosATL _x) vectorAdd [0,0,_offsetHeight];
	_markerRef = _markerObjectType createVehicleLocal _pos;
	[_markerRef, _x] call BIS_fnc_attachToRelative;
	_result pushBack _markerRef;
} ForEach _filteredList;


["OPAEX: function returned %1", _result] call BIS_fnc_logFormat;
_result //Return statement