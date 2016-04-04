#pragma once
#include<time.h>
#include"..\\initialize\\init.h"
#include"..\\initialize\collision.h"

typedef enum _StatusName{
	Wait,
	Zero,
	One,
	End
}StatusName;

typedef struct _Player{
	StatusName status;
	int point;
}Player;

typedef struct __Graph{
	int handle;
	int x;
	int y;
	int width;
	int height;
	int get;
	int hold;
	int number;
	int point;
}Graphs;

//game画面のメイン関数
void game(Scene *scene, Picture handle[15]);
//gameのメイン部分
void game_main(Graphs graph[30],Player player[4]);
//gameの描画部分
void draw_graph(Graphs graph[30]);
//ゲームのシステム部分
void main_funciton(Graphs graph[30],Player player[4]);
//カードを取る際の状態変化
void change_status(Graphs graph[30], int number, Player player[4], int pointX, int pointY);
//gameの状態表示部分
void game_sub();
//初期化
void init(int *flg, Graphs graph[15], Picture handle[15], Player player[4]);
//画像初期化
void init_graph(Graphs graph[15], Picture handle[15]);
//カードをランダム配置
void graph_randam(Graphs graph[30], Picture handle[15]);
//プレイヤー初期化
void init_player(Player player[4]);
