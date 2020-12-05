#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

char* cards[] = { 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12 };

char* p1[20] = { 0 };
char* p2[20] = { 0 };
char* p3[20] = { 0 };
char* p4[20] = { 0 };

void distribute_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4)
{
	srand(time(NULL));

	printf("\t\t\t\t\t\t\t\t\t\tī�� ��� ����� ������ �����ϴ�.\n\n");

	printf("\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user1->name);
	share_card(cards, p1); //ī�� �̱�
	for (int i = 0; i < 20; i++) //ī�� ���
	{
		printf("%d ", p1[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user2->name);
	share_card(cards, p2);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p2[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user3->name);
	share_card(cards, p3);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p3[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user4->name);
	share_card(cards, p4);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p4[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t\t���� �� �� �ڽ��� ī�带 Ȯ���ϼ���.\n");
	Sleep(2000);
	system("cls");
}