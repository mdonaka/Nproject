#pragma once
#include"..\\initialize\\init.h"

//���U���g��ʃ��C���֐�
void result(Scene *scene,Player player[4]);
//��������
void process(Player player[4],int *flg,int savei[6]);
//�ő�l���o
void maxin(Player player[4]);
//�v���C���[�\�[�g
void save(Player player[4],int savei[6]);
//�`�敔
void draw(Player player[4],int save[6]);
//�o�u���\�[�g(���l)
void sort(int ar[],int n);
//�o�u���\�[�g(�v���C���[�_��)
void sortPlayer(Player player[], int n);