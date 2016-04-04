#include"game.h"


void game(Scene *scene, Picture handle[15]){
	static Graphs graph[30];
	static int init_flg=0;
	static Player player[4];

	//初期化
	init(&init_flg,graph,handle,player);

	//ゲームメイン部
	game_main(graph,player);

	//ゲーム状態表示部分
	game_sub();

	//デバグ用
	if (CheckHitKey(KEY_INPUT_X)){
		init_flg = 0;
		*scene = Title;
	}
	for (int i = 0; i < 30; i++){
		if (!graph[i].get){
			DrawFormatString(500, 15 * i, GetColor(0, 255, 255), "%d:%d", i, graph[i].handle);
		}
	}
}

void game_main(Graphs graph[30],Player player[4]){

	draw_graph(graph);
	main_funciton(graph,player);
}

void draw_graph(Graphs graph[30]){
	static int i;
	static int handleBack = LoadGraph("image\\Yinball.png");
	static int handleG;

	for (i = 0; i < 30; i++){
		//カードを取られていない
		if (graph[i].get == 0){
			//カードを開いている
			if (graph[i].hold == 0&&0){
				handleG = handleBack;
			}
			//カードに触れられていない
			else if (graph[i].hold == 1||1){
				handleG = graph[i].handle;
			}
			DrawExtendGraph(graph[i].x, graph[i].y, graph[i].x + graph[i].width, graph[i].y + graph[i].height, handleG, TRUE);
		}
		//カードを取られている
		else{}
	}
}

void main_funciton(Graphs graph[30],Player player[4]){
	static int i;//ループカウンタ
	static int pointX, pointY;//マウスの座標
	static int clickFlg;//現在のクリック状態

	//左クリックされたかどうか
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && !clickFlg){
		clickFlg = 1;
		GetMousePoint(&pointX, &pointY);
		for (i = 0; i < 30; i++){
			change_status(graph, i, player, pointX, pointY);
		}
	}
	else if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0){
		clickFlg = 0;
	}
	else{}
}

void change_status(Graphs graph[30], int number, Player player[4], int pointX, int pointY){
	static int i, g;
	static int getNumber[2] = {0};

	if (collision_rect(graph[number].x, graph[number].y, graph[number].width, graph[number].height, pointX, pointY)){
		if (graph[number].hold == 0 && graph[number].get == 0){
			for (i = 0; i < 4; i++){
				switch (player[i].status){
				case Wait:
					break;
				case Zero:
					graph[number].hold = 1;
					getNumber[0] = graph[number].number;
					player[i].status = One;
					break;
				case One:
					graph[number].hold = 1;
					getNumber[1] = graph[number].number;
					if (graph[getNumber[0]].handle == graph[number].handle){
						graph[getNumber[0]].get = 1;
						graph[number].get = 1;
						player[i].point += graph[number].point;
						player[i].status = Zero;
					}
					else{
						player[i].status = End;
					}
					break;
				case End:
					player[i].status = Wait;
					player[(i < 4) ? 0 : i + 1].status = Zero;
					graph[getNumber[0]].hold = 0;
					graph[getNumber[1]].hold = 0;
					break;
				default:
					break;
				}
			}
		}

	}
}

void game_sub(){
	DrawLine(500, 0, 500, 480, GetColor(255,0,0));
}

void init(int *flg, Graphs graph[30], Picture handle[15], Player player[4]){
	
	if (!*flg){
		*flg = 1;
		
		//グラフのその他情報初期化
		init_graph(graph, handle);

		//プレイヤー初期化
		init_player(player);
	}
	
}

void init_graph(Graphs graph[30], Picture handle[15]){

	int i;

	for (i = 0; i < 30; i++){
		graph[i].width = (SCREEN_WIDTH-142 - 7 * 10 ) / 6;
		graph[i].height = (SCREEN_HEIGHT - 6 * 12) / 5;
		graph[i].x = 10 + (graph[i].width + 10)*(i % 6);
		graph[i].y = 12 + (graph[i].height + 12)*(i % 5);
		//graph[i].handle = handle[i % 15];
		graph[i].get = 0;
		graph[i].hold = 0;
		graph[i].number = i;
	}
	graph_randam(graph, handle);
	graph[i].get = 1;
}

void graph_randam(Graphs graph[30], Picture handle[15]){
	int tmp[30] = { 0 };
	int i;
	int rnd;
	srand(time(NULL));

	for (i = 0; i < 30; i++){
		rnd = rand() % 30;
		if (tmp[rnd] == 0){
			graph[i].handle = handle[rnd % 15].handle;
			graph[i].point = handle[rnd % 15].point;
			tmp[rnd]++;
		}
		else{
			i--;
		}
	}
}

void init_player(Player player[4]){
	static int i;
	for (i = 0; i < 4; i++){
		player[i].point = 0;
		player[i].status = Wait;
	}
	player[0].status = Zero;
}
