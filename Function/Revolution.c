#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 유저 구조체
struct User {
	char name[255];
	char Class[5];
	int Card[13];
	int Total_Card;
};

int Revolution(struct User* User); // 혁명 함수

int Revolution(struct User* User) {

	char buf[255] = { 0 };

	if (strcmp(User->Class, "농노") == 0) {
		if (User->Card[0] == 2) {
		DECIDE:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s 플레이어 : 혁명을 일으키겠습니까? (\"예\" 혹은\"아니요\"라고 입력하시오): ", User->name);
			gets_s(buf, 255);

			if (strcmp(buf, "예") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t혁명이 일어났습니다!");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t계급이 뒤바뀌고 조공을 안내도 됩니다!\n");
				Sleep(3000);
				system("cls");
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
