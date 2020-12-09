#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 유저 구조체
struct User {
	char name[30];
	int Class_Num;
	char Class[10];
	int deck[13];
	int Rank;
};

#define USER_1 0
#define USER_2 1
#define USER_3 2
#define USER_4 3
#define Player 4
#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

extern int Rank;

int Reorganize_Class(struct User* user) {

	if (user->Rank >= 1) return 0;

	int Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (user->deck[i] == 0) {
			Count += 1;
		}
	}

	if (Count == 13) {
		// 등수에 따라 계급 부여
		switch (Rank) {
		case 1:
			strcpy(user->Class, "왕");
			user->Class_Num = King;
			user->Rank = Rank;
			Rank++;
			break;
		case 2:
			strcpy(user->Class, "귀족");
			user->Class_Num = Noble;
			user->Rank = Rank;
			Rank++;
			break;
		case 3:
			strcpy(user->Class, "평민");
			user->Class_Num = Farmer;
			user->Rank = Rank;
			Rank++;
			break;
		case 4:
			strcpy(user->Class, "노예");
			user->Class_Num = Slave;
			user->Rank = Rank;
			Rank++;
			break;
		}
	}
	return 0;
}