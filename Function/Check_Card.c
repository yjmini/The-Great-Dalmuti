#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


void Check_Card(); //카드 패 확인 함수

void Check_Card() {

	char buf[255] = { 0 };

OKAY:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t카드 패를 확인하셨습니까? (\"예\"라고 입력하시오) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "예") == 0) system("cls");
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
		goto OKAY;
	}

}