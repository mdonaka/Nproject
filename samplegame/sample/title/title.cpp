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

	ChangeFont("�l�r ����");

	SetMainWindowText("�^�C�g��");
	DrawFormatString(20, 430, 0xffffff, "2�L�[��2�l�v���C�A3�L�[��3�l�v���C�A4�L�[��4�l�v���C�A");
	DrawFormatString(20, 450, 0xffffff, "C�L�[�ŃM�������[��ʂ�");
	DrawStringToHandle(150, 240 - 42, "�_ �o �� ��", GetColor(255, 100, 50), font);

}