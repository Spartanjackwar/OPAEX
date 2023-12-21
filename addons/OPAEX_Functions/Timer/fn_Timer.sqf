//Jack Moss, aka Spartanjackwar.
//Vespade is due some of the credit for the origin of the timer script.
/*
This function creates a timer.
If UITime is used, then the timer runs in real-time and is immune to game performance.
Note that this function MUST be called via spawn since we use sleep and waitUntil{} in it.

Parameter 0: Time, in seconds, for which we run the timer.
Parameter 1: Display, bool, determines if display is visible or not.
Parameter 2: UseUITime, bool, determines if display is visible to every client or not.

Return: Nothing
*/

//To catch incorrect environment execution, we will exit if we cannot suspend the script.
if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
};

//Setup parameters
params [
	[ //Time in seconds
		"_inputTime",
		30,
		[1]
	],
	[ //Should we display?
		"_useDisplay",
		True,
		[True]
	],
	[ //Should we use UITime?
		"_useUITime",
		True,
		[True]
	]
];

//Timer
_timer = _inputTime;
while {(_timer > .01)} do
{
	//Actual timer element, built via the time delta over .02 seconds.
	if (_useUITime) then 
	{ //Runs regardless of simulation.
		_time = diag_tickTime;
		uisleep .02;
		_timeSinceLast = diag_tickTime - _time;
		_timer = _timer - _timeSinceLast;
	} else { //Runs dependent on simulation.
		_time = diag_tickTime;
		sleep .02;
		_timeSinceLast = diag_tickTime - _time;
		_timer = _timer - _timeSinceLast;
	};
	
	if (_useDisplay and hasInterface) then {
		//Display.
		/*
		_display = [_timer, "HH:MM:SS.MS", true] call BIS_fnc_secondsToString;
		ms = [_display select 3, 0, 1] call BIS_fnc_trimString; //Trim the 3rd decimal place
		_display deleteAt 3; //Remove the old miliseconds
		_display = _display joinString ":", _ms;
		_display = _display joinString ".";
		*/
		_display = [_timer, "HH:MM:SS.MS", false] call BIS_fnc_secondsToString;
		hintSilent parseText format [
			"<t size='1.5'>Time Remaining:</t><br/><t size='2'>%1</t>",
			_display
		];
	};
};
waitUntil {_timer < 0.1};
if (_useDisplay and hasInterface) then {
	hintSilent parseText "<t size='1.5'>Time Remaining:</t><br/><t size='2'>00:00:00.00</t>";
	sleep 0.1;
	hintSilent "";
};

/*
_isactive = true;
_timer = 30;
while {(_timer > .01) and (_isActive)} do 
{ 
  
 _time = diag_tickTime; 
 _timeSinceLast = diag_tickTime - _time; 
 _timer = _timer - _timeSinceLast; 
  
  
 _display = [_timer, "HH:MM:SS.MS", true] call BIS_fnc_secondsToString;
_ms1 = (_display select 3 call BIS_fnc_numberText);
_ms2 = _ms1 toFixed 2;
 _display deleteAt 3; 
 _display pushback _ms2; 
 _display = _display joinString ":"; 
 hintSilent parseText format ["<t size='1.5'>Time Remaining:</t><br/><t size='2'>%1</t>", 
   
  [_timer, "HH:MM:SS.MS", true] call BIS_fnc_secondsToString joinString ":" 
 ]; 
}; 

*/