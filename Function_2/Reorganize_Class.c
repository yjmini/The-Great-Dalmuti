#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int Rank = 0; // 등수를 저장할 변수

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

void Reorganize_Class(struct User* User) {

	// 가지고 있는 패 중에서 0개인 카드의 종류를 카운트하여 저장할 변수
	int Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (User->deck[i] == 0) {
			Count += 1;
		}
	}

	if (Count == 13) {
		// 등수에 따라 계급 부여
		switch (Rank) {
		case 0:
			strcpy(User->Class, "왕");
			break;
		case 1:
			strcpy(User->Class, "귀족");
			break;
		case 2:
			strcpy(User->Class, "평민");
			break;
		case 3:
			strcpy(User->Class, "노예");
			break;
		}

		Rank++;
	}
}