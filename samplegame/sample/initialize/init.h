#pragma once
#include<stdio.h>
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

//画像(元)の構造体
typedef struct _Picture{
	int handle;
	int point;
}Picture;

//初期化
void init(Scene s, Scene *scene,Picture handle[15]);
//DxLibの初期化
void init_dx();
//ハンドル初期化
void init_handle(Picture handle[15]);