#include"title.h"

void title(Scene *scene){

	SetMainWindowText("�^�C�g��");
	DrawFormatString(20, 450, 0xffffff, "z�ŃQ�[����ʂ�,c�ŃM�������[��ʂ�");

	if (CheckHitKey(KEY_INPUT_Z)){
		*scene = Game;
	}else if (CheckHitKey(KEY_INPUT_C)){
		*scene = Gallery;
	}
}
