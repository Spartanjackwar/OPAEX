_pelican = _this select 0;
_veh = _this select 1; 
_loaded = false; 
	
switch true do {
		
	case (_veh isKindOf "OPTRE_M808B_base") : {
		_veh attachTo [_pelican,[0,-7.2, -0.37105]];
		_veh setDir 180; 
		_loaded = true; 
	};
	case (_veh isKindOf "OPTRE_M12A1_LRV" or _veh isKindOf "OPTRE_M12_LRV" or _veh isKindOf "OPTRE_M12G1_LRV" or _veh isKindOf "OPTRE_M12R_AA") : {
		_veh attachTo [_pelican,[0,-5,0.12]]; 
		//0 = [vehicle player, 15, 0] call BIS_fnc_setPitchBank; 
		_loaded = true;  		
	};		
	case (_veh isKindOf "OPTRE_M12_FAV") : {
		_veh attachTo [_pelican,[0,-4.5,0.86]];  
		_loaded = true;  
	};		
	case (_veh isKindOf "OPTRE_M813_TT") : {
		_veh attachTo [_pelican,[0,-3.8,.44]];  
		_loaded = true;  
	};
	case (_veh isKindOf "OPTRE_M413_base" or _veh isKindOf "B_APC_Wheeled_01_cannon_F") : {
		_veh attachTo [_pelican,[0,-3.6,0.30]];  
		_loaded = true;  
	};
	/*case (_veh isKindOf "OPTRE_falcon_base") : {
		_veh attachTo [_pelican,[0,-4.8,-0.1]];  
		_loaded = true;  
	};
	case (_veh isKindOf "optre_hornet_base") : {
		_veh attachTo [_pelican,[0,-5,-0.35]];  
		_loaded = true;  
	};*/
};
	
if (_loaded) then {
	_pelican setVariable ["OPTRE_Pelican_AttachedToVehiclesEffect", [vehicle player], true];
	titleText ["-------------------------------------------<br/><t color='#ff0000' size='1.5'>VEHICLE LOADED!</t><br/>-------------------------------------------<br/>", "PLAIN DOWN", -1, true, true];
	playSound "FD_Finish_F";
} else {
	titleText ["-------------------------------------------<br/><t color='#ff0000' size='1.5'>CAN NOT LOAD!</t><br/>-------------------------------------------<br/>Your vehicle has not been design to be mag lifted by the pelican.", "PLAIN DOWN", -1, true, true];
	//hint "Your vehicle has not been design to be lifted by the pelican operation aborted.";
	playSound "FD_CP_Not_Clear_F";
};