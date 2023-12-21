//Jack Moss, aka Spartanjackwar.
/*
Looping function to run some code until a condition is satisfied.
Please note that I will not error check your code or parameters for you in the loop.

In you need to stop all OPAEX asynchronous loops for any reason, there is an emergency stop variable.
In case of emergency, run code:
	missionNamespace setVariable ["OPAEX_EmergencyStopAsyncLoops", true, true];

Parameter 0: namespace: Namespace from which we monitor the given variable name.
Parameter 1: string: Variable name that we use as a boolean.  Assumed to be False for your own safety.
	If you don't set the variable as True the loop will execute only once.
	This is because I assume your variable is false, until fetched otherwise, to prevent unstoppable loops.
Parameter 2: float: Delay between loop executions.  Can never be equal to or less than zero.
Parameter 3: array: The parameters that will be passed to the code.
Parameter 4: code: The code that we will execute in a loop.
Parameter 5: bool: If we should use spawn or call when invoking the code.  True uses spawn.

Return: Nothing

Example:
	_code = {
		_target = player;
		_pos = ((getCameraViewDirection _target) vectorMultiply 5) vectorAdd (getPos _target);
		[_pos, _target] spawn OPAEX_fnc_D20Roll_BananaGod;
	}
	player setVariable ["OPAEX_DoLoop", true, true];
	[player, "OPAEX_DoLoop", 1, [], _code, true] spawn OPAEX_fnc_asynchronousExecutionLoop;

Must be executed in scheduled environment.
Can execute on any client.
*/

params [
	[
		"_namespace",
		missionNamespace,
		[true, missionNamespace, objNull, grpNull, locationNull, controlNull, displayNull]
	],
	[
		"_continueLoopVariableName",
		"",
		[""]
	],
	[
		"_loopExecutionDelay",
		0.1,
		[1.0]
	],
	[
		"_codeParams",
		[],
		[[]]
	],
	[
		"_code",
		{},
		[{}]
	],
	[
		"_useScheduledEnvironment",
		true,
		[true]
	]
];

//I was serious when I said you need to run this in the scheduler.
if (!canSuspend) exitWith {
	[] call OPAEX_fnc_Debug_Error_RunCondition;
	Nil
};

//Validate object parameters.
if (_loopExecutionDelay <= 0) exitWith {
	[] call OPAEX_fnc_Debug_Error_InputRules;
	Nil
};

private ["_continue", "_emergencyStop"];

if (_useScheduledEnvironment) then {
	waitUntil {
		//Invoke the given code with the given parameters
		_codeParams spawn _code;
		
		//Begin the given delay
		sleep _loopExecutionDelay;
		
		//Check the loop exit conditions.
		_continue = _namespace getVariable [_continueLoopVariableName, false];
		_emergencyStop = missionNamespace getVariable ["OPAEX_EmergencyStopAsyncLoops", true];
		!_continue or _emergencyStop;
	};
} else {
	waitUntil {
		//Invoke the given code with the given parameters
		_codeParams call _code;
		
		//Begin the given delay
		sleep _loopExecutionDelay;
		
		//Check the loop exit conditions.
		_continue = _namespace getVariable [_continueLoopVariableName, false];
		_emergencyStop = missionNamespace getVariable ["OPAEX_EmergencyStopAsyncLoops", true];
		!_continue or _emergencyStop;
	};
};