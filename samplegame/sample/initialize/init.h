#pragma once
#include<stdio.h>
#include"DxLib.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


//ƒV[ƒ“‚Ì—ñ‹“‘Ì
typedef enum _Scene{
	Title,
	Game,
	Gallery,
	Result
}Scene;

//‰Šú‰»
void init(Scene s, Scene *scene);
//DxLib‚Ì‰Šú‰»
void init_dx();