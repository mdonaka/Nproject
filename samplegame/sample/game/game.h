#pragma once
#include<time.h>
#include"..\\initialize\\init.h"
#include"..\\initialize\collision.h"

typedef enum _StatusName{
	Wait,
	Zero,
	One,
	End
}StatusName;

typedef struct _Player{
	StatusName status;
	int point;
}Player;

typedef struct __Graph{
	int handle;
	int x;
	int y;
	int width;
	int height;
	int get;
	int hold;
	int number;
	int point;
}Graphs;

//game��ʂ̃��C���֐�
void game(Scene *scene, Picture handle[15]);
//game�̃��C������
void game_main(Graphs graph[30],Player player[4]);
//game�̕`�敔��
void draw_graph(Graphs graph[30]);
//�Q�[���̃V�X�e������
void main_funciton(Graphs graph[30],Player player[4]);
//�J�[�h�����ۂ̏�ԕω�
void change_status(Graphs graph[30], int number, Player player[4], int pointX, int pointY);
//game�̏�ԕ\������
void game_sub();
//������
void init(int *flg, Graphs graph[15], Picture handle[15], Player player[4]);
//�摜������
void init_graph(Graphs graph[15], Picture handle[15]);
//�J�[�h�������_���z�u
void graph_randam(Graphs graph[30], Picture handle[15]);
//�v���C���[������
void init_player(Player player[4]);
