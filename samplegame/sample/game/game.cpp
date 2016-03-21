#include"game.h"


void game(Scene *scene){

	static int x = 140;
	static int flg = 0;

	SetMainWindowText("ゲーム");
	DrawFormatString(x, 450, 0xffffff, "xでタイトルへ");

	if (x <= 400 && flg == 0){
		x += 4;
	}
	else if (x >= 140){
		flg = 1;
		x -= 4;
	}
	else{
		flg = 0;
	}


	if (CheckHitKey(KEY_INPUT_X)){
		x = 140;
		*scene = Title;
	}
}
