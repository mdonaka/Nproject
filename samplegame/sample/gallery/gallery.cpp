#include"gallery.h"


void gallery(Scene *scene){
	static Graph graph[15];

	//������
	init(graph);

	//�`��
	draw(graph);
	
	//x�Ń^�C�g����
	if (CheckHitKey(KEY_INPUT_X)){
		*scene = Title;
	}
}

void draw(Graph graph[15]){
	static int i;

	for (i = 0; i < 15; i++){
		DrawExtendGraph(graph[i].x, graph[i].y, graph[i].x + graph[i].width, graph[i].y + graph[i].height, graph[i].handle, TRUE);
	}
	DrawFormatString(20, 450, 0xff0000, "�N���b�N�Ŋg��B'x'�Ń^�C�g���ɖ߂�");

	mouse(graph);
}

void mouse(Graph graph[15]){
	int pointX, pointY;
	static int i;
	static int clickFlg;
	static int graphClickFlg=-1;//-1:�N���b�N����ĂȂ�,0-14:�摜���N���b�N����
	static int graphStatus[15] = { 0 };

	//���N���b�N���ꂽ���ǂ���
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && !clickFlg){
		GetMousePoint(&pointX, &pointY);
		clickFlg = 1;

		if (graphClickFlg >= 0){
			graphStatus[graphClickFlg] = 2;
			graphClickFlg = -1;
		}else{
			//�����蔻����Ȃĉ摜�̏�Ԃ�ύX����
			for (i = 0; i < 15; i++){
				if (collision_rect(graph[i].x, graph[i].y, graph[i].width, graph[i].height, pointX, pointY)){
					graphStatus[i] = 1;
					graphClickFlg = i;
				}else{
					graphStatus[i] = 0;
				}
			}
		}


	}else if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0){
		clickFlg = 0;
	}else{

	}
	graph_click(graph,graphStatus);
}

void graph_click(Graph graph[15],int graphStatus[15]){
	static int i;
	for (i = 0; i < 15; i++){
		switch (graphStatus[i]){
		case 0:
			break;
		case 1:
		case 2:
			graph_scaling(graph[i],graphStatus[i]);
		default:
			break;
		}
	}
}

void graph_scaling(Graph graph,int scaleFlg){
	static int x;
	static int y;
	static int width;
	static int height;
	static int flg=0;
	
	//������
	if (flg == 0){
		x = graph.x;
		y = graph.y;
		width = graph.width;
		height = graph.height;
		flg = 1;
	}

	if (scaleFlg == 1){
		/*
		���X�ɑ傫������
		if (10 < x){ x-=3; }
		if (width + x < SCREEN_WIDTH){ width+=6; }
		if (9 < y){ y-=2; }
		if (height + y < SCREEN_HEIGHT){ height+=4; }
		*/

		x = 0;
		y = 0;
		width = SCREEN_WIDTH;
		height = SCREEN_HEIGHT;
		
		DrawExtendGraph(x, y, x+width, y+height, graph.handle, TRUE);
	}else{
		DrawExtendGraph(graph.x, graph.y, graph.x + graph.width, graph.y + graph.height, graph.handle, TRUE);
		flg = 0;
	}
}

void init(Graph graph[15]){
	static int flg = 0;

	//DxLib�֌W������
	init_Dx();

	//�摜�֌W������(1��̂�)
	if (flg != 1){
		init_graph(graph);
		flg = 1;
	}

}

void init_graph(Graph graph[15]){
	int i;
	int spaceX,spaceY;

	spaceX = 10;
	spaceY = 9;


	for (i = 0; i < 15; i++){
		graph[i].width = (SCREEN_WIDTH-6*spaceX)/5;
		graph[i].height = (SCREEN_HEIGHT-50-4*spaceY)/3;
		graph[i].x = spaceX + (graph[i].width+ spaceX)*(i % 5);
		graph[i].y = spaceY + (graph[i].height + spaceY)*(i % 3);
		graph[i].handle = LoadGraph("image\\sample.png");
	}
}

void init_Dx(){
	SetMainWindowText("�M�������[");
}
