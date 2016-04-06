#include"title.h"

void title(Scene *scene){

	text();

	if (CheckHitKey(KEY_INPUT_Z)){
		*scene = Game;
	}
	else if (CheckHitKey(KEY_INPUT_C)){
		*scene = Gallery;
	}
	else if (CheckHitKey(KEY_INPUT_A)){
		//*scene = Result;
	}
}

void text(){
	static int font;
	static int flg = 0;
	if (flg == 0){
		font = CreateFontToHandle(NULL, 64, 5, DX_FONTTYPE_NORMAL);
		flg = 1;
	}

	ChangeFont("ＭＳ 明朝");

	SetMainWindowText("タイトル");
	DrawFormatString(20, 450, 0xffffff, "zでゲーム画面へ,cでギャラリー画面へ");
	DrawStringToHandle(150, 240 - 42, "神 経 衰 弱", GetColor(255, 100, 50), font);

}