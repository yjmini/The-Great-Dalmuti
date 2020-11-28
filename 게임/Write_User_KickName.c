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

void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t닉네임 최대 255자(공백포함)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1의 닉네임을 입력해주세요 : ");
	gets_s(User1->name, 255);
	gets_s(User1->name, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2의 닉네임을 입력해주세요 : ");
	gets_s(User2->name, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3의 닉네임을 입력해주세요 : ");
	gets_s(User3->name, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4의 닉네임을 입력해주세요 : ");
	gets_s(User4->name, 255);


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
