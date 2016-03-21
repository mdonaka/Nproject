#include"initialize\\init.h"
#include"title\\title.h"
#include"gallery\\gallery.h"
#include"game\\game.h"
#include"result\\result.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	//シーン
	Scene scene;

	//初期化
	init(Title, &scene);

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
		case Result:
			result(&scene);
			break;
		default:
			break;
		}
	}

	//DxLib終了
	DxLib_End();
	return 0;
}

