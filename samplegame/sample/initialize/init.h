#pragma once
#include<stdio.h>
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

//�摜(��)�̍\����
typedef struct _Picture{
	int handle;
	int point;
}Picture;

//������
void init(Scene s, Scene *scene,Picture handle[15]);
//DxLib�̏�����
void init_dx();
//�n���h��������
void init_handle(Picture handle[15]);