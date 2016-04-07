#include"title.h"

void title(Scene *scene){

	static int flag = 0;
	text(&flag);

	if (CheckHitKey(KEY_INPUT_Z)){
		flag = 0;
		*scene = Game;
	}
	else if (CheckHitKey(KEY_INPUT_C)){
		*scene = Gallery;
	}
	else if (CheckHitKey(KEY_INPUT_A)){
		//*scene = Result;
	}
}

void text(int *flag){
	static int font;
	if (*flag == 0){
		font = CreateFontToHandle(NULL, 64, 5, DX_FONTTYPE_NORMAL);
		*flag = 1;
	}

	ChangeFont("ＭＳ 明朝");

	SetMainWindowText("タイトル");
	DrawFormatString(20, 450, 0xffffff, "zでゲーム画面へ,cでギャラリー画面へ");
	DrawStringToHandle(150, 240 - 42, "神 経 衰 弱", GetColor(255, 100, 50), font);

}