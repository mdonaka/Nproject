#include"title.h"

void title(Scene *scene){

	SetMainWindowText("�^�C�g��");
	DrawFormatString(20, 450, 0xffffff, "z�ŃQ�[����ʂ�,c�ŃM�������[��ʂ�,a�Ō��ʉ�ʂ�(�f�o�b�O)");

	if (CheckHitKey(KEY_INPUT_Z)){
		*scene = Game;
	}else if (CheckHitKey(KEY_INPUT_C)){
		*scene = Gallery;
	}else if (CheckHitKey(KEY_INPUT_A)){
		*scene = Result;
	}
}
