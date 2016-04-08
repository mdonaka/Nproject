#pragma once
#include<time.h>
#include"..\\initialize\\init.h"
#include"..\\initialize\collision.h"


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
	char name[20];
}Graphs;

//game画面のメイン関数
void game(Scene *scene, Picture handle[15],Player player[4],int num);
//gameのメイン部分
void game_main(Scene *scene,Graphs graph[30],Player player[4]);
//gameの描画部分
void draw_graph(Graphs graph[30]);
//ゲームのシステム部分
void main_funciton(Scene *scene,Graphs graph[30],Player player[4]);
//ゲーム終了判定
void game_end(Scene *scene, Graphs graph[30]);
//カードを取る際の状態変化
void change_status(Graphs graph[30], int number, Player player[4], int pointX, int pointY);
//gameの状態表示部分
void game_sub(Player player[4]);
//カードを取っているかの判定
int not_get(Graphs graph[30],int number);
//初期化
void init(int *flg, Graphs graph[15], Picture handle[15], Player player[4]);
//画像初期化
void init_graph(Graphs graph[15], Picture handle[15]);
//カードをランダム配置
void graph_randam(Graphs graph[30], Picture handle[15]);
//プレイヤー初期化
void init_player(Player player[4]);
//デバッグ
void game_debug(Scene *scene, Graphs graph[30], Player player[4]);