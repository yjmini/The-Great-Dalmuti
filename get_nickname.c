#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define player 4
#define Joker 2

extern char Class[13][10];//ī�� ���

extern int cards[];
extern int p[4][20];

struct user//���� ����ü
{
	char name[30]; //32����?
	int deck[13]; //0-12 �� ��
	char class[10]; //���

};

void Get_Nickname(struct user* user) {
	char input[30] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�г��� �ִ� 30��(���� ����)\n\n\n");

	for (int i = 0; i < player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d�� �г����� �Է��ϼ��� : ", i + 1);
		gets_s(user[i].name, 30);
		printf("\n\n");
	}

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t�� �г����� �½��ϱ�?\n\n");
	for (int i = 0; i < player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d : %s\n\n", i + 1, user[i].name);
	}


Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t�̴�� �����Ͻðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\"��� �Է��ϼ���) : ");
	gets_s(input, 30);

	if (strcmp(input, "��") == 0) {
		system("cls");
	}
	else if (strcmp(input, "�ƴϿ�") == 0) {
		system("cls");
		Get_Nickname(user);
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto Check;
	}

}