#pragma once
#include<stdio.h>
#include<string.h>
#include"DxLib.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

//シーンの列挙体
typedef enum _Scene{
	Title,
	Game,
	Gallery,
	Result
}Scene;

//プレイヤーの状態の列挙体
typedef enum _StatusName{
	Wait,
	Zero,
	One,
	Get,
	End
}StatusName;

//画像(元)の構造体
typedef struct _Picture{
	int handle;
	int point;
	char name[20];
}Picture;

//プレイヤーの構造体
typedef struct _Player{
	StatusName status;
	int num;
	int point;
}Player;

//初期化
void init(Scene s, Scene *scene,Picture handle[15]);
//DxLibの初期化
void init_dx();
//ハンドル初期化
void init_handle(Picture handle[15]);