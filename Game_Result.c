#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 11.26

// 유저 구조체
struct User {
	char name[255];
	char Class[5];
	int Card[13];
};

int Game_Result(struct User* User);

int Rank = 1; // 등수를 저장할 변수

int Game_Result(struct User* User) {

	// 가지고 있는 패 중에서 0개인 카드의 종류를 카운트하여 저장할 변수
	int _Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (User->Card[i] == 0) {
			_Count += 1;
		}
	}

	if (_Count == 13) {
		printf("당신은 %d등 입니다.\n", Rank + 1);
	}

	// 등수에 따라 계급 부여
	switch (Rank) {
	case 0:
		strcpy_s(User->Class, 5, "왕");
		printf("당신의 새로운 계급 : ");
		puts(User->Class);
		break;
	case 1:
		strcpy_s(User->Class, 5, "귀족");
		printf("당신의 새로운 계급 : ");
		puts(User->Class);
		break;
	case 2:
		strcpy_s(User->Class, 5, "농민");
		printf("당신의 새로운 계급 : ");
		puts(User->Class);
		break;
	case 3:
		strcpy_s(User->Class, 5, "노예");
		printf("당신의 새로운 계급 : ");
		puts(User->Class);
		break;
	}

	Rank++;
	if (Rank + 1 == 4) Rank = 0;

OKAY:
	printf("확인하셨습니까? (\"예\" 라고 입력하시오): ");
	gets_s(buf, 255);

	if (strcmp(buf, "예") == 0) return 0;
	else {
		printf("잘못입력하셨습니다.\n");
		goto OKAY;
	}

	return 0;
}
