#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

const char class[13][10] = { "조커", "달무티", "대주교","시종장","남작부인","수녀원장","기사","재봉사","석공","요리사","양치기","광부","노예" };

void Print_Card(struct User* User) {

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s의 카드 패\n", User->name);
	for (int i = 0; i < 13; i++) {
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d\n", i, class[i], User->deck[i]);
	}

}