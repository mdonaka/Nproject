#include"init.h"
#include"title.h"
#include"gallery.h"
#include"game.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	//�V�[��
	Scene scene;

	//������
	init(Gallery, &scene);

	//���C�����[�v
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

	//DxLib�I��
	DxLib_End();
	return 0;
}

