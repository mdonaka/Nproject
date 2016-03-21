#include"init.h"

void init(Scene s, Scene *scene){
	*scene = s;
	init_dx();
}

void init_dx(){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
}
