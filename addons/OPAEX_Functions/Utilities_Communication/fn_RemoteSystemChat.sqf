//Jack Moss, aka Spartanjackwar.
/*
Wrapper for systemchat which remote executes.

Parameter 0: num: ID of client to cast to. 0 is global, 2 is server only. Negatives invert behavior.
Parameter 1: bool: if remote cast should target JIP players.
Parameter 2: string: message to send

Return: Nothing

Can be executed in nonscheduled environment.
Can execute on any client.

Dependencies:
	None
*/

params [
	[
		"_remoteTargetBehavior",
		0,
		[0]
	],
	[
		"_remoteTargetJIP",
		false,
		[true]
	],
	[
		"_message",
		"",
		[""]
	]
];

[//Remotely execute the systemChat
	_message
] remoteExec [
	"systemChat",
	_remoteTargetBehavior,
	_remoteTargetJIP
];