#include"initialize\\init.h"
#include"title\\title.h"
#include"gallery\\gallery.h"
#include"game\\game.h"
#include"result\\result.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	
	int player_num;

	//シーン
	Scene scene;

	//プレイヤー
	Player player[4];

	//画像ハンドル
	Picture handle[15];

	//初期化
	init(Title, &scene, handle);

	//メインループ
	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		if (CheckHitKey(KEY_INPUT_ESCAPE)){ break; }

		switch (scene){
		case Title:
			title(&scene,&player_num);
			break;
		case Game:
			game(&scene, handle, player, player_num);
			break;
		case Gallery:
			gallery(&scene, handle);
			break;
		case Result:
			result(&scene, player, player_num);
			break;
		default:
			break;
		}
	}

	//DxLib終了
	DxLib_End();
	return 0;
}

