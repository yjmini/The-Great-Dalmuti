#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

const char class[13][10] = { "��Ŀ", "�޹�Ƽ", "���ֱ�","������","���ۺ���","�������","���","�����","����","�丮��","��ġ��","����","�뿹" };

char* p1[20] = { 0 };
char* p2[20] = { 0 };
char* p3[20] = { 0 };
char* p4[20] = { 0 };

void print_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4)
{
	char input[255] = { 0 };
	for (int i = 0; i < 13; i++)
	{
		user1->deck[i] = 0;
		user2->deck[i] = 0;
		user3->deck[i] = 0;
		user4->deck[i] = 0;
	}
	for (int i = 0; i < 20; i++)
	{
		if (p1[i] == 0)
			user1->deck[0]++;
		else if (p1[i] == 1)
			user1->deck[1]++;
		else if (p1[i] == 2)
			user1->deck[2]++;
		else if (p1[i] == 3)
			user1->deck[3]++;
		else if (p1[i] == 4)
			user1->deck[4]++;
		else if (p1[i] == 5)
			user1->deck[5]++;
		else if (p1[i] == 6)
			user1->deck[6]++;
		else if (p1[i] == 7)
			user1->deck[7]++;
		else if (p1[i] == 8)
			user1->deck[8]++;
		else if (p1[i] == 9)
			user1->deck[9]++;
		else if (p1[i] == 10)
			user1->deck[10]++;
		else if (p1[i] == 11)
			user1->deck[11]++;
		else if (p1[i] == 12)
			user1->deck[12]++;
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user1->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d��\n", i, class[i], user1->deck[i]);
	}
CHECK1:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto CHECK1;
	}


	for (int i = 0; i < 20; i++)
	{
		if (p2[i] == 0)
			user2->deck[0]++;
		else if (p2[i] == 1)
			user2->deck[1]++;
		else if (p2[i] == 2)
			user2->deck[2]++;
		else if (p2[i] == 3)
			user2->deck[3]++;
		else if (p2[i] == 4)
			user2->deck[4]++;
		else if (p2[i] == 5)
			user2->deck[5]++;
		else if (p2[i] == 6)
			user2->deck[6]++;
		else if (p2[i] == 7)
			user2->deck[7]++;
		else if (p2[i] == 8)
			user2->deck[8]++;
		else if (p2[i] == 9)
			user2->deck[9]++;
		else if (p2[i] == 10)
			user2->deck[10]++;
		else if (p2[i] == 11)
			user2->deck[11]++;
		else if (p2[i] == 12)
			user2->deck[12]++;
	}


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user2->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d��\n", i, class[i], user2->deck[i]);
	}
CHECK2:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto CHECK2;
	}

	for (int i = 0; i < 20; i++)
	{
		if (p3[i] == 0)
			user3->deck[0]++;
		else if (p3[i] == 1)
			user3->deck[1]++;
		else if (p3[i] == 2)
			user3->deck[2]++;
		else if (p3[i] == 3)
			user3->deck[3]++;
		else if (p3[i] == 4)
			user3->deck[4]++;
		else if (p3[i] == 5)
			user3->deck[5]++;
		else if (p3[i] == 6)
			user3->deck[6]++;
		else if (p3[i] == 7)
			user3->deck[7]++;
		else if (p3[i] == 8)
			user3->deck[8]++;
		else if (p3[i] == 9)
			user3->deck[9]++;
		else if (p3[i] == 10)
			user3->deck[10]++;
		else if (p3[i] == 11)
			user3->deck[11]++;
		else if (p3[i] == 12)
			user3->deck[12]++;
	}


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user3->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d��\n", i, class[i], user3->deck[i]);
	}
CHECK3:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto CHECK3;
	}

	for (int i = 0; i < 20; i++)
	{
		if (p4[i] == 0)
			user4->deck[0]++;
		else if (p4[i] == 1)
			user4->deck[1]++;
		else if (p4[i] == 2)
			user4->deck[2]++;
		else if (p4[i] == 3)
			user4->deck[3]++;
		else if (p4[i] == 4)
			user4->deck[4]++;
		else if (p4[i] == 5)
			user4->deck[5]++;
		else if (p4[i] == 6)
			user4->deck[6]++;
		else if (p4[i] == 7)
			user4->deck[7]++;
		else if (p4[i] == 8)
			user4->deck[8]++;
		else if (p4[i] == 9)
			user4->deck[9]++;
		else if (p4[i] == 10)
			user4->deck[10]++;
		else if (p4[i] == 11)
			user4->deck[11]++;
		else if (p4[i] == 12)
			user4->deck[12]++;
	}


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user4->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d��\n", i, class[i], user4->deck[i]);
	}

CHECK4:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto CHECK4;
	}

}