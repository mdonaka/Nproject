#include"init.h"

void init(Scene s, Scene *scene,Picture handle[15]){
	*scene = s;
	init_dx();
	init_handle(handle);
}

void init_dx(){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
}

void init_handle(Picture handle[15]){
	int i;
	char tmp[99];
	char name[15][20] = { 
		"disc", "keyboard", "kuziran", "monokuroboo", "muropyon",
		"muroran", "�J���[���[����", "�t���b�s�[�f�B�X�N", "���H�働�S", "�Ă���(��)",
		"sample","sample","sample","sample","sample"};
	int point[15] = {
		1, 1, 2, 1, 1,
		3, 2, 1, 1, 1,
		0, 0, 0, 0, 0
	};
	for (i = 0; i < 15; i++){
		sprintf_s(tmp, 99,"image\\%s.png", name[i]);
		handle[i].point = point[i];
		handle[i].handle = LoadGraph(tmp);
	}
}