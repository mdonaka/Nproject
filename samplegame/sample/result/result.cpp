#include"result.h"

int player_nums;

void result(Scene *scene,Player player[4],int num){
	static int flg = 0;
	static int savei[6];

	player_nums = num;

	//������
	process(player,&flg,savei);

	//�`�敔
	draw(player,savei);

	if (CheckHitKey(KEY_INPUT_X)){
		flg = 0;
		*scene = Title;
	}
	
}

void process(Player player[4],int *flg,int savei[6]){

	SetMainWindowText("���ʉ��");	
	
	if (*flg == 0){
		maxin(player);
		save(player,savei);
		*flg = 1;
	}

}

void maxin(Player player[4]){
	sortPlayer(player, player_nums);
}

void save(Player player[4],int savei[6]){
	//�t�@�C���|�C���^
	FILE *fp;

	//0,1,2,3,4:�������� 5:�����N�O
	char savec[9][10];
	
	fopen_s(&fp,"result\\data.dat", "r");
	
	if (fp == NULL){
		return;
	}
	//�ǂݍ���
	for (int i = 0; i < 5; i++){
		fgets(savec[i], 4, fp);
		savei[i] = atoi(savec[i]);
	}
	for (int i = 0; i < player_nums; i++){
		savei[5 + i] = player[i].point;
	}
	fclose(fp);

	//�\�[�g
	sort(savei, 5+player_nums);

	//��������
	fopen_s(&fp, "result\\data.dat", "w");
	for (int i = 0; i < 5; i++){
		fprintf_s(fp,"%d\n",savei[5+player_nums-1-i]);
	}

	fclose(fp);
}

void draw(Player player[4],int savei[6]){

	DrawFormatString(20, 450, 0xffffff, "x�Ń^�C�g����ʂ�");
	DrawFormatString(20, 30, 0xffffff, "����̌���");
	DrawFormatString(300, 30, 0xffffff, "�ō����_");

	for (int i = 0; i < player_nums; i++){
		DrawFormatString(30, 70+30*i, 0xffffff, "%d��.�v���C���[%d:%d�_", i+1,player[player_nums-i-1].num+1, player[player_nums-i-1].point);
	}

	for (int i = 0; i < 5; i++){
		DrawFormatString(310, 70+30*i, 0xffffff, "%d. %d�_", i+1,savei[5+player_nums-i-1]);
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