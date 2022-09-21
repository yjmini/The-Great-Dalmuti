#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 유저 구조체
struct user {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

int Decide_Re_Game(struct user* user) {
	char buf[255] = { 0 };

	if (strcmp(user->Class, "왕") == 0) {
	PROCEED:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s 왕께서는 게임을 계속 진행하시겠습니까? (\"예\" 혹은 \"아니요\"라고 입력하시오): ", user->name);
		gets_s(buf, 255);

		if (strcmp(buf, "예") == 0) {
			return 1;
		}
		else if (strcmp(buf, "아니요") == 0) {
			return 0;
		}
		else {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
			goto PROCEED;
		}
	}

	return 0;
}