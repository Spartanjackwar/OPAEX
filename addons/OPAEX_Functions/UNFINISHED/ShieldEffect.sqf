n = 0;
onEachFrame {
	n = if (n ＞ 30) then [{0},{n + 1}];
	_tex = [0, format [
		"\a3\data_f\Caustics\caustics_anim_0%1.paa", 
		(if (n ＞ 9) then [{""},{"0"}]) + str n 
	]];
	player setObjectTexture _tex;
	unitBackpack player setObjectTexture _tex;
}; //https://www.youtube.com/watch?v=eif_GEbQs9w