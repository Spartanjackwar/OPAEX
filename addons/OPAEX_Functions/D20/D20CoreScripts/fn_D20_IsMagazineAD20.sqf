//Jack Moss, aka Spartanjackwar.
/*
Checks that the scripts in a magazine exists.

Parameter 0: 3d Array: position of grenade to pass to scripts.

Return: Nothing

Must execute in a suspendable environment.
Can be executed anywhere.
*/

params [
	[
		"_mag",
		"",
		[""]
	]
];

private["_result", "_result2"];
_result = isClass (configFile >> "CfgMagazines" >> _mag >> "OPAEX_D20_Scripts");
_result2 = isClass (missionConfigFile >> "CfgMagazines" >> _mag >> "OPAEX_D20_Scripts");
_result or _result2 //return statement