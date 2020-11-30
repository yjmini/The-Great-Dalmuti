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

int Rank = 0; // 등수를 저장할 변수

void Reorganize_Class(struct User* User); // 계급 재편성 함수

void Reorganize_Class(struct User* User) {

	// 가지고 있는 패 중에서 0개인 카드의 종류를 카운트하여 저장할 변수
	int Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (User->Card[i] == 0) {
			Count += 1;
		}
	}

	if (Count == 13) {
		// 등수에 따라 계급 부여
		switch (Rank) {
		case 0:
			strcpy_s(User->Class, 5, "왕");
			break;
		case 1:
			strcpy_s(User->Class, 5, "귀족");
			break;
		case 2:
			strcpy_s(User->Class, 5, "농민");
			break;
		case 3:
			strcpy_s(User->Class, 5, "노예");
			break;
		}

		Rank++;
	}
}
