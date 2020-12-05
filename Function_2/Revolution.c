#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

int Revolution(struct User* User) {

	char buf[255] = { 0 };

	if (strcmp(User->Class, "노예") == 0) {
		if (User->deck[0] == 2) {
		DECIDE:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s 플레이어 : 혁명을 일으키겠습니까? (\"예\" 혹은\"아니요\"라고 입력하시오): ", User->name);
			gets_s(buf, 255);

			if (strcmp(buf, "예") == 0) {
				User->deck[0] -= 2;
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