#include"initialize\\init.h"
#include"title\\title.h"
#include"gallery\\gallery.h"
#include"game\\game.h"
#include"result\\result.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	
	int player_num;

	//�V�[��
	Scene scene;

	//�v���C���[
	Player player[4];

	//�摜�n���h��
	Picture handle[15];

	//������
	init(Title, &scene, handle);

	//���C�����[�v
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

	//DxLib�I��
	DxLib_End();
	return 0;
}

