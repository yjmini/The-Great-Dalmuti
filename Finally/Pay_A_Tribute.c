#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ���� ����ü
struct User {
	char name[30];
	int Class_Num;
	char Class[10];
	int deck[13];
	int Rank;
};

#define USER_1 0
#define USER_2 1
#define USER_3 2
#define USER_4 3
#define Player 4
#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

extern char class[13][10];

void Pay_A_Tribute(struct User* user)
{
	int a = 0, b = 0;
	int A = 0, B = 0;
	int i = 0, j = 0;

	printf("��________�뿹\n\n");
	for (i; i < Player; i++) {
		if (user[i].Class_Num == Slave) {//���� ����� ī�� ������ ������
			printf("%s�� ī��\n\n", user[i].name);
			for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
				printf("%d. %s : %d��\n", k, class[k], user[i].deck[k]);
			printf("\n");
		AERO:
			printf("�ڽ��� ī�� �� ���ڰ� ���� ���� ī�� 2���� �տ��� �ּ���.(ī�� ��ȣ�� �����ÿ�, ��Ŀ�� ����)\n");
			scanf_s("%d %d", &a, &b);

			if (((user + i)->deck[a]) == 0)
				goto AERO;
			if (((user + i)->deck[b]) == 0)
				goto AERO;
			if (a > 12 || a < 1)
				goto AERO;
			if (b > 12 || b < 1)
				goto AERO;
			break;
		}
	}
	for (j; j < Player; j++) {
		if (user[j].Class_Num == King) {//���� ���� ī�� ������ ������
			printf("\n%s�� ī��\n\n", user[j].name);
			for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
				printf("%d. %s : %d��\n", k, class[k], user[j].deck[k]);
			printf("\n");
		BERO:
			printf("�ڽ��� ī�� �� ���� ���� ī�� 2���� �뿹���� �ּ���.(ī�� ��ȣ�� �����ÿ�, ��Ŀ�� ����)\n");
			scanf_s("%d %d", &A, &B);

			if (((user + j)->deck[A]) == 0)
				goto BERO;
			if (((user + j)->deck[B]) == 0)
				goto BERO;
			if (A > 12 || A < 1)
				goto BERO;
			if (B > 12 || B < 1)
				goto BERO;
			break;
		}
	}

	((user + i)->deck[a])--; ((user + i)->deck[b])--; ((user + i)->deck[A])++; ((user + i)->deck[B])++;
	((user + j)->deck[A])--; ((user + j)->deck[B])--; ((user + j)->deck[a])++; ((user + j)->deck[b])++;

	printf("\n���� ���� ī�带 Ȯ���ϼ���.\n\n");

	printf("%s�� ī��\n\n", user[i].name);
	for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
		printf("%d. %s : %d��\n", k, class[k], user[i].deck[k]);
	printf("\n");

	printf("%s�� ī��\n\n", user[j].name);
	for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
		printf("%d. %s : %d��\n", k, class[k], user[j].deck[k]);
	printf("\n");

	int c = 0, D = 0;
	int w = 0, e = 0;
	printf("����________���\n\n");

	for (w; w < Player; w++) {
		if (user[w].Class_Num == Farmer) {//���� ����� ī�� ������ ������
			printf("%s�� ī��\n\n", user[w].name);
			for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
				printf("%d. %s : %d��\n", k, class[k], user[w].deck[k]);
			printf("\n");
		CERO:
			printf("�ڽ��� ī�� �� ���ڰ� ���� ���� ī�� 1���� �������� �ּ���.(ī�� ��ȣ�� �����ÿ�, ��Ŀ�� ����)\n");
			scanf_s("%d", &c);
			if (((user + w)->deck[c]) == 0)
				goto CERO;
			if (c > 12 || c < 1)
				goto CERO;
			break;
		}
	}

	for (e; e < Player; e++) {
		if (user[e].Class_Num == Noble) {//���� ������ ī�� ������ ������
			printf("%s�� ī��\n\n", user[e].name);
			for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
				printf("%d. %s : %d��\n", k, class[k], user[e].deck[k]);
			printf("\n");
		DERO:
			printf("�ڽ��� ī�� �� ���� ���� ī�� 1���� ��ο��� �ּ���.(ī�� ��ȣ�� �����ÿ�, ��Ŀ�� ����)\n");
			scanf_s("%d", &D);

			if (((user + e)->deck[D]) == 0)
				goto DERO;
			if (D > 12 || D < 1)
				goto DERO;
			break;
		}
	}
	((user + w)->deck[c])--; ((user + w)->deck[D])++; ((user + e)->deck[D])--; ((user + e)->deck[c])++;

	printf("���� ���� ī�带 Ȯ���ϼ���.\n\n");

	printf("%s�� ī��\n\n", user[w].name);
	for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
		printf("%d. %s : %d��\n", k + 1, class[k], user[w].deck[k]);
	printf("\n");

	printf("%s�� ī��\n\n", user[e].name);
	for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
		printf("%d. %s : %d��\n", k + 1, class[k], user[e].deck[k]);
	printf("\n");

	Sleep(3000);
	system("cls");
}