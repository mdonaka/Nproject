#include"result.h"

void result(Scene *scene){
	SetMainWindowText("結果画面");
	DrawFormatString(20, 450, 0xffffff, "xでタイトル画面へ");

	if (CheckHitKey(KEY_INPUT_X)){
		*scene = Title;
	}
}