#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t닉네임 최대 30자(공백포함)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1의 닉네임을 입력해주세요 : ");
	gets_s(User1->name, 30); 
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2의 닉네임을 입력해주세요 : ");
	gets_s(User2->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3의 닉네임을 입력해주세요 : ");
	gets_s(User3->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4의 닉네임을 입력해주세요 : ");
	gets_s(User4->name, 30);

Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t  닉네임을 확인하시겠습니까? (\"예\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "예") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto Check;
	}
}