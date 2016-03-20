#pragma once
#include<math.h>
#include"init.h"
#include"collision.h"

typedef struct _Graph{
	int handle;
	int x;
	int y;
	int width;
	int height;
	int clicked;
}Graph;

//ギャラリーのメイン関数
void gallery(Scene *scene);

//スクリーンに描く
void draw(Graph graph[15]);

//マウス関係
void mouse(Graph graph[15]);

//クリック時の画像関係の関数
void graph_click(Graph graph[15], int graphStatus[15]);

//クリック時の画像の拡大縮小
void graph_scaling(Graph graph, int flg);

//初期化
void init(Graph graph[15]);

//画像初期化
void init_graph(Graph graph[15]);

//DxLib初期化
void init_Dx();
