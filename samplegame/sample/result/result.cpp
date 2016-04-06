#include"result.h"

void result(Scene *scene,Player player[4]){
	static int flg = 0;
	static int max = 0;

	//処理部
	process(player, &max,&flg);

	//描画部
	draw(player);

	if (CheckHitKey(KEY_INPUT_X)){
		flg = 0;
		*scene = Title;
	}
	
}

void process(Player player[4], int *max,int *flg){
	if (*flg == 0){
		maxin(player, max);
		save(*max);
		*flg = 1;
	}

}

void maxin(Player player[4],int *max){
	sortPlayer(player, 4);
	*max = player[3].point;
}

void save(int max){
	//ファイルポインタ
	FILE *fp;

	//0,1,2,3,4:書き込む 5:ランク外
	char savec[5][4];
	int savei[6];
	
	fopen_s(&fp,"result\\data.dat", "r");
	
	if (fp == NULL){
		return;
	}
	//読み込み
	for (int i = 0; i < 5; i++){
		fgets(savec[i], 4, fp);
		savei[i] = atoi(savec[i]);
	}
	savei[5] = max;
	fclose(fp);

	//ソート
	sort(savei, 6);

	//書き込み
	fopen_s(&fp, "result\\data.dat", "w");
	for (int i = 0; i < 5; i++){
		fprintf_s(fp,"%d\n",savei[5-i]);
	}

	fclose(fp);
}

void draw(Player player[4]){
	SetMainWindowText("結果画面");
	DrawFormatString(20, 450, 0xffffff, "xでタイトル画面へ");

	for (int i = 0; i < 4; i++){
		DrawFormatString(40, 200 + 20 * (3 - i), 0xff0000, "%d %d", player[i].num, player[i].point);
	}
}

void sort(int ar[], int n){
	int i,j;
	int tmp;

	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (ar[j] > ar[j + 1]){
				tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}
}

void sortPlayer(Player player[], int n){

	int i, j;
	Player tmp;

	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (player[j].point > player[j + 1].point){
				tmp = player[j];
				player[j] = player[j + 1];
				player[j + 1] = tmp;
			}
		}
	}
}