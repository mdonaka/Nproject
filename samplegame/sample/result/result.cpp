#include"result.h"

void result(Scene *scene){
	SetMainWindowText("���ʉ��");
	DrawFormatString(20, 450, 0xffffff, "x�Ń^�C�g����ʂ�");

	if (CheckHitKey(KEY_INPUT_X)){
		*scene = Title;
	}
}