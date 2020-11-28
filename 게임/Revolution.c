#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// 유저 구조체
struct User {
	char name[255];
	char Class[5];
	int Card[13];
};

int Revolution(struct User* User) {

	char buf[255] = { 0 };

	if (strcmp(User->Class, "농노") == 0) {
		if (User->Card[0] == 2) {
			DECIDE:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s 플레이어 : 혁명을 일으키겠습니까? (\"예\" 혹은\"아니요\"라고 입력하시오): ", User->name);
			gets_s(buf, 255);

			if (strcmp(buf, "예") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t혁명이 일어났습니다!");
				// 계급 바꾸기, 조공 패스 추가하기
				return 1;
			}
			else if (strcmp(buf, "아니요") == 0) {
				system("cls");
			}
			else {
				printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
				goto DECIDE;
			}
		}
	}

	return 0;
}
