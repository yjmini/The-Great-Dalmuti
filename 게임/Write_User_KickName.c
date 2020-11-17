#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Write_User_Nickname(char* User1, char* User2, char* User3, char* User4) {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t닉네임 최대 255자(공백포함)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1의 닉네임을 입력해주세요 : ");
	gets_s(User1, 255);
	gets_s(User1, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2의 닉네임을 입력해주세요 : ");
	gets_s(User2, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3의 닉네임을 입력해주세요 : ");
	gets_s(User3, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4의 닉네임을 입력해주세요 : ");
	gets_s(User4, 255);


Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t  닉네임을 수정하시겠습니까? (\"예\" 혹은 \"아니요\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "아니요") == 0) {
		system("cls");
	}
	else if (strcmp(input, "예") == 0) {
		system("cls");
		Write_User_Nickname(&User1, &User2, &User3, &User4);
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto Check;
	}

}