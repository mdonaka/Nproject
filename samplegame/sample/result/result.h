#pragma once
#include"..\\initialize\\init.h"

//���U���g��ʃ��C���֐�
void result(Scene *scene,Player player[4]);
//��������
void process(Player player[4], int *max,int *flg,int savei[6]);
//�ő�l���o
void maxin(Player player[4], int *max);
//�ő�l�L���A�v���C���[�\�[�g
void save(int max,int savei[6]);
//�`�敔
void draw(Player player[4],int save[6]);
//�o�u���\�[�g(���l)
void sort(int ar[],int n);
//�o�u���\�[�g(�v���C���[�_��)
void sortPlayer(Player player[], int n);