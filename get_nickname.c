#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define player 4
#define Joker 2

extern char Class[13][10];//카드 계급

extern int cards[];
extern int p[4][20];

struct user//종합 구조체
{
	char name[30]; //32정도?
	int deck[13]; //0-12 몇 장
	char class[10]; //계급

};

void Get_Nickname(struct user* user) {
	char input[30] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t닉네임 최대 30자(공백 포함)\n\n\n");

	for (int i = 0; i < player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d의 닉네임을 입력하세요 : ", i + 1);
		gets_s(user[i].name, 30);
		printf("\n\n");
	}

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t이 닉네임이 맞습니까?\n\n");
	for (int i = 0; i < player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d : %s\n\n", i + 1, user[i].name);
	}


Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t이대로 진행하시겠습니까? (\"예\" 혹은 \"아니요\"라고 입력하세요) : ");
	gets_s(input, 30);

	if (strcmp(input, "예") == 0) {
		system("cls");
	}
	else if (strcmp(input, "아니요") == 0) {
		system("cls");
		Get_Nickname(user);
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t다시 입력하세요.\n");
		goto Check;
	}

}