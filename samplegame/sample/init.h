#pragma once
#include"DxLib.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


//�V�[���̗񋓑�
typedef enum _Scene{
	Title,
	Game,
	Gallery
}Scene;

//������
void init(Scene s, Scene *scene);
//DxLib�̏�����
void init_dx();