#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Function.h"

char User1[255] = { 0 };
char User2[255] = { 0 };
char User3[255] = { 0 };
char User4[255] = { 0 };

char User1_Class[255] = { 0 };
char User2_Class[255] = { 0 };
char User3_Class[255] = { 0 };
char User4_Class[255] = { 0 };

int User1_Card[13] = { 0 };
int User2_Card[13] = { 0 };
int User3_Card[13] = { 0 };
int User4_Card[13] = { 0 };

int main() {
	srand(time(NULL));

	int input = 0;

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
		Write_User_Nickname(&User1, &User2, &User3, &User4);
		Decide_Divide_Class();
		Divide_Class(&User1_Class, &User2_Class, &User3_Class, &User4_Class, &User1, &User2, &User3, &User4);
		Print_Class(&User1_Class, &User2_Class, &User3_Class, &User4_Class, &User1, &User2, &User3, &User4);
		King_Order_To_Slave();
		Decide_Distribute_Card();
		Distribute_Card(&User1_Card, &User2_Card, &User3_Card, &User4_Card);
		Print_Card(&User1_Card, &User1, &User1_Class);
		Revolution(&User1_Card, &User1_Class);
		Print_Card(&User2_Card, &User2, &User2_Class);
		Revolution(&User2_Card, &User2_Class);
		Print_Card(&User3_Card, &User3, &User3_Class);
		Revolution(&User3_Card, &User3_Class);
		Print_Card(&User4_Card, &User4, &User4_Class);
		Revolution(&User4_Card, &User4_Class);
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
