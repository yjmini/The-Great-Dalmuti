#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Header.h"
#include "Header_SGG.h"
#define player 4
#define Joker 2
#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

extern char Class[13][10];//ī�� ���

extern int cards[];
extern int p[4][20];
extern int preCard_Class;
extern int Declare_Card_Class;
extern int Pay_Card_Num;
extern int count;
extern int Rank;

struct user//���� ����ü
{
	char name[30]; //32����?
	int deck[13]; //0-12 �� ��
	char class[10]; //���
	int Class_Num;
};

int main(void)
{
	struct user user[player] = { 0 };
	int input = 0, Decide_Re_Game_Return = 0;

MAIN:
	printf("��ü ȭ������ �������ּ���.\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t������ �޹�Ƽ          \n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t     �λ��� �Ұ��� �մϴ�.       ");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t1. ���� ����\t2. ���� ���\t3. ���� ����\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t     ���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%d", &input);

	switch (input) {
	case 1:
		system("cls");

		Get_Nickname(user);
		Decide_Divide_Class();
		Divide_Class(user);

		distribute_card(user);
		print_card(user);

		int user_Num[4] = { 0 };
		int _count = 0;

		for (int i = 0; i < 4; i++) {
			if (user[i].Class_Num == King) user_Num[0] = i;
			else if (user[i].Class_Num == Noble) user_Num[1] = i;
			else if (user[i].Class_Num == Farmer) user_Num[2] = i;
			else if (user[i].Class_Num == Slave) user_Num[3] = i;
		}

		while (Rank != 4) {
			for (int i = 0; i < 4; i++) {

				Play_A_Card(&user[user_Num[i]]);
				Reorganize_Class(&user[user_Num[i]]);

				if (count == 4) {
					Declare_Card_Class = 13; preCard_Class = 13; Pay_Card_Num = 0;
					count = 0;
					Print_Card(&user[user_Num[i]]);
					Play_A_Card(&user[user_Num[i]]);
					Reorganize_Class(&user[user_Num[i]]);
				}
			}
		}

		for (int i = 0; i < 4; i++) Decide_Re_Game_Return = Decide_Re_Game(&user[i]);

		// if (Decide_Re_Game_Return == 1) goto ORDER;

		break;
	case 2:
		system("cls");
		int _input = Manual();
		switch (_input) {
		case 1:
			system("cls");
			goto MAIN;
			break;
		case 2:
			break;
		}
	case 3:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t     ������ �����ϰڽ��ϴ�.");
		break;
	}

	return 0;
}