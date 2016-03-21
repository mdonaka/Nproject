#include"title.h"

void title(Scene *scene){

	SetMainWindowText("タイトル");
	DrawFormatString(20, 450, 0xffffff, "zでゲーム画面へ,cでギャラリー画面へ,aで結果画面へ(デバッグ)");

	if (CheckHitKey(KEY_INPUT_Z)){
		*scene = Game;
	}else if (CheckHitKey(KEY_INPUT_C)){
		*scene = Gallery;
	}else if (CheckHitKey(KEY_INPUT_A)){
		*scene = Result;
	}
}
