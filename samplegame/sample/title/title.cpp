#include"title.h"

void title(Scene *scene,int *num){

	static int flag = 0;
	text(&flag);
	
	
	if (CheckHitKey(KEY_INPUT_Z)){
//		flag = 0;
//		*scene = Game;
	}
	else if (CheckHitKey(KEY_INPUT_2)){
		*num = 2;
		flag = 0;
		*scene = Game;
	}
	else if (CheckHitKey(KEY_INPUT_3)){
		*num = 3;
		flag = 0;
		*scene = Game;
	}
	else if (CheckHitKey(KEY_INPUT_4)){
		*num = 4;
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
	DrawFormatString(20, 430, 0xffffff, "2キーで2人プレイ、3キーで3人プレイ、4キーで4人プレイ、");
	DrawFormatString(20, 450, 0xffffff, "Cキーでギャラリー画面へ");
	DrawStringToHandle(150, 240 - 42, "神 経 衰 弱", GetColor(255, 100, 50), font);

}