#pragma once
#include<stdio.h>
#include<string.h>
#include"DxLib.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

//�V�[���̗񋓑�
typedef enum _Scene{
	Title,
	Game,
	Gallery,
	Result
}Scene;

//�v���C���[�̏�Ԃ̗񋓑�
typedef enum _StatusName{
	Wait,
	Zero,
	One,
	Get,
	End
}StatusName;

//�摜(��)�̍\����
typedef struct _Picture{
	int handle;
	int point;
	char name[20];
}Picture;

//�v���C���[�̍\����
typedef struct _Player{
	StatusName status;
	int num;
	int point;
}Player;

//������
void init(Scene s, Scene *scene,Picture handle[15]);
//DxLib�̏�����
void init_dx();
//�n���h��������
void init_handle(Picture handle[15]);