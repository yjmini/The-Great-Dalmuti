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

	printf("\t\t\t\t\t\t\t\t\t\t카드 배분 결과는 다음과 같습니다.\n\n");

	printf("\t\t\t\t\t\t\t\t\t%s의 카드 : ", user1->name);
	share_card(cards, p1); //카드 뽑기
	for (int i = 0; i < 20; i++) //카드 출력
	{
		printf("%d ", p1[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s의 카드 : ", user2->name);
	share_card(cards, p2);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p2[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s의 카드 : ", user3->name);
	share_card(cards, p3);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p3[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s의 카드 : ", user4->name);
	share_card(cards, p4);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p4[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t\t이제 한 명씩 자신의 카드를 확인하세요.\n");
	Sleep(2000);
	system("cls");
}