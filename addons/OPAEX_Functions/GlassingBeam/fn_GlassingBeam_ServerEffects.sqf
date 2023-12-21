//Jack Moss, aka Spartanjackwar.
/*
This function represents a glassing beam's destructive power.

Parameter 0: position: origin of bomb explosion
Parameter 1: int: kill radius.
Parameter 2: int: percentage of objects to kill in beam radius.

Return: Nothing

Must execute in a suspendable environment.
Server is passed the actual physical response to freezing.  Headless clients do nothing.
*/
if (!isServer or !canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

params [
	[
		"_origin",
		(getpos player),
		[[0.0, 0.0, 0.0]]
	],
	[
		"_destructionRadius",
		500,
		[1]
	],
	[
		"_destructionRate",
		100,
		[1]
	]
];
_center = _origin; //The original script used _center as the origin name, so I lazily use this line.

//Kill all the things inside the beam radius.
if (_destructionRadius > 0 && _destructionRate > 0) then
{
	private _objects = (nearestObjects [_center, [], _destructionRadius]);
	private _numberOfObjects = count _objects;
	private _n = ceil (_numberOfObjects/_destructionRate);
	for "_i" from 1 to _n do
	{
		private _idxStart = (_i-1)*_destructionRate;
		private _currentArrayLength = _numberOfObjects - _idxStart - 1; 
		_currentArrayLength = [_currentArrayLength, _destructionRate] select (_currentArrayLength > _destructionRate);
		{
			// Do not kill "invincible" units, logics, HCs and virtual curators.
			if ((isDamageAllowed _x) && !(_x isKindOf "Logic") && !(_x isKindOf "VirtualMan_F")) then
			{
				_x setDamage 1;
			};
		} forEach (_objects  select [_idxStart , _currentArrayLength]);
	};
	
};