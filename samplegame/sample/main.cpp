#include"init.h"
#include"title.h"
#include"gallery.h"
#include"game.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	//シーン
	Scene scene;

	//初期化
	init(Gallery, &scene);

	//メインループ
	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		if (CheckHitKey(KEY_INPUT_ESCAPE)){ break; }

		switch (scene){
		case Title:
			title(&scene);
			break;
		case Game:
			game(&scene);
			break;
		case Gallery:
			gallery(&scene);
			break;
		default:
			break;
		}
	}

	//DxLib終了
	DxLib_End();
	return 0;
}

