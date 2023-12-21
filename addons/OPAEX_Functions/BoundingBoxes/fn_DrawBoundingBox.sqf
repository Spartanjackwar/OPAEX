//Jack Moss, aka Spartanjackwar.
//KillzoneKid also deserves most credit here, as I merely adapted his code slightly.
/*
This function draws the edges of an object's bounding box from BoundingBoxReal.
Please note that you must delete the handler, or you will quickly add lag to all clients.
Because of the above, it is highly recommended that OPAEX_fnc_TimedDrawBoundingBox is used instead.

Parameter 0: Object whose box we draw.
Return: A handle to the bounding box draw3D event handler.
*/

//Retrieve and set parameters.
private ["_object","_bb","_bbx","_bby","_bbz","_arr","_y","_z","_color", "_Handle"];
_object = _this;
_color = [0, 1, 0, 1]; //RGBA

//Box builder code block.  Use "call _bb" to invoke this.  Intended to operate on [x, y, z] inputs.
_bb = {
	_bbx = [(_this select 0) select 0, (_this select 1) select 0];
	_bby = [(_this select 0) select 1, (_this select 1) select 1];
	_bbz = [(_this select 0) select 2, (_this select 1) select 2];
	_arr = [];
	0 = { //Loop for y coords
		_y = _x;
		0 = { //loop for z coords
			_z = _x;
			0 = { //loop for x coords
				0 = _arr pushBack (_object modelToWorld [_x,_y,_z]);
			} count _bbx;
		} count _bbz;
		reverse _bbz;
	} count _bby;
	_arr pushBack (_arr select 0);
	_arr pushBack (_arr select 1);
	_arr //this is a return statement, but for only this code block.
};

//Retrieve the box dimensions and call the box builder
//_dimensions = _object call OPAEX_fnc_GetBoundingBoxDimensions;
_bboxr = boundingBoxReal _object call _bb;

//Add draw3d handler.
_Handle = addMissionEventHandler ["Draw3D", {
	params["_bboxr"];
	for "_i" from 0 to 7 step 2 do { //I don't know why 7 is used or step 2.
		drawLine3D [
			_bboxr select _i,
			_bboxr select (_i + 2),
			[0, 1, 0, 1]
		];
		drawLine3D [
			_bboxr select (_i + 2),
			_bboxr select (_i + 3),
			[0, 1, 0, 1]
		];
		drawLine3D [
			_bboxr select (_i + 3),
			_bboxr select (_i + 1),
			[0, 1, 0, 1]
		];
	};
}, [_bboxr]];

_Handle