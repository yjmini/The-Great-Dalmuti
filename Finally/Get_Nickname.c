#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define USER_1 0
#define USER_2 1
#define USER_3 2
#define USER_4 3
#define Player 4
#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

// 유저 구조체
struct User {
	char name[30];
	int Class_Num;
	char Class[10];
	int deck[13];
	int Rank;
};


void Get_Nickname(struct User* user) {
	char input[30] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t닉네임 최대 30자(공백 포함)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\tuser1의 닉네임을 입력하세요 : ");
	gets_s(user[0].name, 30);
	gets_s(user[0].name, 30);
	printf("\n\n");

	for (int i = 1; i < Player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d의 닉네임을 입력하세요 : ", i + 1);
		gets_s(user[i].name, 30);
		printf("\n\n");
	}

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t이 닉네임이 맞습니까?\n\n");
	for (int i = 0; i < Player; i++)
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