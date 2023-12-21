//Credit for this goes to Leopard20#5297 in the Arma discord.  You're a gigachad.
/*
Returns the model-relative position of the muzzle position.

Parameter 0: string: weapon classname to find muzzle for.

Return: 3d array of float, containing the muzzle position, relative to the model center.

Can be executed in non-scheduled environment.
Can execute on any client.  Note that the running client locally builds the object.
*/

params [
	[
		"_wep",
		"",
		[""]
	]
];

private [
	"_cfg",
	"_model",
	"_obj",
	"_offset"
];

_offset = [0,0,0];

//Grab the weapon config and get the model from it.
_cfg = configFile >> "CfgWeapons" >> _wep;
_model = getText(_cfg >> "model");

//Build a simple object version of the gun, fetch the muzzle from it, and delete the object.
_obj = createSimpleObject [_model, [0,0,0], true];
_offset = _obj selectionPosition [getText(_cfg >> "muzzlePos"), "memory"];
deleteVehicle _obj;

//Return the offset.
_offset 