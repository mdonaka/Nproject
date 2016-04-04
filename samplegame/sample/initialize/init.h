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

//初期化
void init(Scene s, Scene *scene,int handle[15]);
//DxLibの初期化
void init_dx();
//ハンドル初期化
void init_handle(int handle[15]);