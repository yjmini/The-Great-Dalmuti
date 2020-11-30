#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ���� ����ü
struct User {
	char name[255];
	char Class[5];
	int Card[13];
	int Total_Card;
};

#define USER_1 0
#define USER_2 1
#define USER_3 2
#define USER_4 3

#define Give_To_King 2
#define Give_To_Noble 1
#define Give_To_Farmer 1
#define Give_To_Slave 2

int Rank = 0; // ����� ������ ����

int main() {
	srand((unsigned int)time(NULL));

	struct User User[4] = { 0 };
	int input = 0, Revolution_Return = 0, Decide_Re_Game_Return = 0;

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
		Write_User_Nickname(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);
		Decide_Divide_Class();
		Divide_Class(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);
		King_Order_To_Slave();
		Card_Deal(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);
		Print_Card(&User[USER_1]); Check_Card(); Revolution_Return = Revolution(&User[USER_1]);
		Print_Card(&User[USER_2]); Check_Card(); Revolution_Return = Revolution(&User[USER_2]);
		Print_Card(&User[USER_3]); Check_Card(); Revolution_Return = Revolution(&User[USER_3]);
		Print_Card(&User[USER_4]); Check_Card(); Revolution_Return = Revolution(&User[USER_4]);

		if (Revolution_Return == 0) {
			Pay_A_Tribute(&User[USER_1]); Pay_A_Tribute(&User[USER_2]); Pay_A_Tribute(&User[USER_3]); Pay_A_Tribute(&User[USER_4]);
			Get_A_Tribute(&User[USER_1]); Get_A_Tribute(&User[USER_2]); Get_A_Tribute(&User[USER_3]); Get_A_Tribute(&User[USER_4]);
		}

		else if (Revolution_Return == 1) {
			for (int i = 0; i < 4; i++) {
				Revolution_Class_Change(&User[i]);
			}
		}

		while (Rank != 4) {
			for (int i = 0; i < 4; i++) {
				Print_Card(&User[i]);
				Play_A_Card(&User[i]);
				Reorganize_Class(&User[i]);
			}
		}

		for (int i = 0; i < 4; i++) Decide_Re_Game_Return = Decide_Re_Game(&User[i]);

		if (Decide_Re_Game_Return == 1) {
			// ī�� �й���� �ٽ� ����
		}

		break;
	case 2:
		system("cls");
		int _input = Print_Game_Role();
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