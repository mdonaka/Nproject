#pragma once
#include<math.h>
#include"init.h"
#include"collision.h"

typedef struct _Graph{
	int handle;
	int x;
	int y;
	int width;
	int height;
	int clicked;
}Graph;

//�M�������[�̃��C���֐�
void gallery(Scene *scene);

//�X�N���[���ɕ`��
void draw(Graph graph[15]);

//�}�E�X�֌W
void mouse(Graph graph[15]);

//�N���b�N���̉摜�֌W�̊֐�
void graph_click(Graph graph[15], int graphStatus[15]);

//�N���b�N���̉摜�̊g��k��
void graph_scaling(Graph graph, int flg);

//������
void init(Graph graph[15]);

//�摜������
void init_graph(Graph graph[15]);

//DxLib������
void init_Dx();
