#include"init.h"

void init(Scene s, Scene *scene,int handle[15]){
	*scene = s;
	init_dx();
	init_handle(handle);
}

void init_dx(){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
}

void init_handle(int handle[15]){
	int i;
	for (i = 0; i < 15; i++){
		handle[i] = LoadGraph("image\\sample.png");
	}
}