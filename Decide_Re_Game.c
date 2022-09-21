#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//11.26

// 유저 구조체
struct User {
	char name[255];
	char Class[5];
	int Card[13];
};

int Decide_Re_Game(struct User* User);

int Decide_Re_Game(struct User* User) {
	char buf[255] = { 0 };

	if (strcmp(User->Class, "왕") == 0) {
	PROCEED:
		printf("게임을 계속 진행하시겠습니까? (\"예\" 혹은 \"아니요\"라고 입력하시오): ");
		gets_s(buf, 255);

		if (strcmp(buf, "예") == 0) {
			// 카드 분배부터 다시 시작
		}
		else if (strcmp(buf, "아니요") == 0) {
			return 0;
		}
		else {
			printf("잘못 입력하셨습니다.\n");
			goto PROCEED;
		}
	}

	return 0;
}
