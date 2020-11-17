#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Revolution(int* User_Card, char* User_Class) {

	// 혁명발동 시 어떤 상황이 일어나는지 출력, 계급 변화, 조공 패스 추가하기

	char input[255] = { 0 };


	if (*(User_Card + 12) == 2) {
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t혁명을 일으키겠습니까? (\"예\" 혹은\"아니요\"라고 입력하시오): ");
		gets_s(input, 255);
		if (strcmp(input, "예") == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t혁명이 일어났습니다!");
			if (strcmp(*User_Class, "노예") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t계급의 변화가 생겼습니다.");
			}
			else if (strcmp(*User_Class, "왕") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t조공을 바치지 않아도 됩니다!");
			}
			else if (strcmp(*User_Class, "귀족") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t조공을 바치지 않아도 됩니다!");
			}
			else if (strcmp(*User_Class, "농민") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t조공을 바치지 않아도 됩니다!");
			}
		}
		else if (strcmp(input, "아니요") == 0) {
			system("cls");
		}
		else {
			printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
			Revolution(*User_Card, *User_Class);
		}
	}
	else {
		system("cls");
	}

	
}