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

	ChangeFont("�l�r ����");

	SetMainWindowText("�^�C�g��");
	DrawFormatString(20, 450, 0xffffff, "z�ŃQ�[����ʂ�,c�ŃM�������[��ʂ�");
	DrawStringToHandle(150, 240 - 42, "�_ �o �� ��", GetColor(255, 100, 50), font);

}