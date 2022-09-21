#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 유저 구조체
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

void Print_Game_Result(struct User* user) {

	printf("\n\t\t\t\t\t\t\t\t\t\t\t게임의 결과는 다음과 같습니다!\n");
	for (int i = 0; i < Player; i++)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", user[i].name, user[i].Class);
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t수고하셨습니다!\n");

}