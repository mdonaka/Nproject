#include"title.h"

void title(Scene *scene){

	SetMainWindowText("タイトル");
	DrawFormatString(20, 450, 0xffffff, "zでゲーム画面へ,cでギャラリー画面へ");

	if (CheckHitKey(KEY_INPUT_Z)){
		*scene = Game;
	}else if (CheckHitKey(KEY_INPUT_C)){
		*scene = Gallery;
	}
}
