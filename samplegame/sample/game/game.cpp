#include"game.h"


void game(Scene *scene){
	static int i;
	static Graphs graph[15];

	init(graph);
	for (i = 0; i < 30; i++){
		DrawExtendGraph(graph[i].x, graph[i].y, graph[i].x + graph[i].width, graph[i].y + graph[i].height, graph[i].handle, TRUE);
	}
	if (CheckHitKey(KEY_INPUT_X)){
		*scene = Title;
	}
}

void init(Graphs graph[15]){
	/*
	static int flg = 0;
	if (flg == 0){
		init_graph(graph);
		flg = 1;
	}
	*/
}

void init_graph(Graphs graph[15]){
	int i;
	int space;

	space = 10;

	for (i = 0; i < 30; i++){
		graph[i].width = 33 + (SCREEN_WIDTH - 7 * space - 33) / 6;
		graph[i].height = (SCREEN_HEIGHT - 6 * space) / 5;
		graph[i].x = space + (graph[i].width + space)*(i % 6);
		graph[i].y = space + (graph[i].height + space)*(i % 5);
		graph[i].handle = LoadGraph("image\\sample.png");
	}
}
/*
640*480
5x+6y=480
6x+7y+2z=640

504+70=574 640-574=66
x=84,y=10,z=33
*/