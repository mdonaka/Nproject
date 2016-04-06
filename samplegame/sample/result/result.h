#pragma once
#include"..\\initialize\\init.h"

//リザルト画面メイン関数
void result(Scene *scene,Player player[4]);
//処理部分
void process(Player player[4], int *max,int *flg);
//最大値抽出
void maxin(Player player[4], int *max);
//最大値記憶、プレイヤーソート
void save(int max);
//描画部
void draw(Player player[4]);
//バブルソート(数値)
void sort(int ar[],int n);
//バブルソート(プレイヤー点数)
void sortPlayer(Player player[], int n);