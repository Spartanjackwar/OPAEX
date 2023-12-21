//Jack Moss, aka Spartanjackwar.
//Credits for the code this function is based on goes to the 2nd example at https://community.bistudio.com/wiki/joinAsSilent
//Sadly, there is no author name noted, so I can't name the person who deserves the credit.
/*
	This function returns the ID of a unit within a group.

	Parameter 1: object: unit to check.

	Return: Number, ID of unit within group.

	Any client may execute this.
	May be executed in a nonscheduled environment.

	Handlers invoked:
		None
		
	Dependencies:
		None
*/
//Setup parameters
params [
	[
		"_unit",
		player,
		[objNull]
	]
];

//Get variable name and make it blank so that the return from string conversion works
private _varName = vehicleVarName _unit;
_unit setVehicleVarName "";
private _str = str _unit;

//Reset variable name to prior value and grab the ID.
_unit setVehicleVarName _varName;
_id = parseNumber (_str select [(_str find ":") + 1]);

["OPAEX: function returned %1", _id] call BIS_fnc_logFormat;
_id //return statement.