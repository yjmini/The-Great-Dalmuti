#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Print_Class(char* User1_Class, char* User2_Class, char* User3_Class, char* User4_Class, char* User1, char* User2, char* User3, char* User4) {

	char input[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t계급표\n\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", User1, User1_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", User2, User2_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", User3, User3_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", User4, User4_Class);

OK:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t   확인하셨습니까? (\"확인 완료\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "확인 완료") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto OK;
	}

}