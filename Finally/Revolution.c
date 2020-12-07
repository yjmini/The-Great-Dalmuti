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

int Revolution(struct User* user) {

	int n = 0;
	for (int i = 0; i < Player; i++) {
		if (user[i].Class_Num == Slave) {
			if (user[i].deck[0] == 2) {
				printf("혁명을 일으킬 수 있습니다. 혁명을 일으키겠습니까?(1. 예, 2. 아니요): ");
				scanf_s("%d", &n);

				if (n == 2)
					return -1;

				printf("계급이 뒤바뀌었습니다!!\n\n");
				for (int j = 0; j < Player; j++) {
					if (user[j].Class_Num == King) {
						strcpy(user[j].Class, "노예");
						user[j].Class_Num = Slave;
					}
					else if (user[j].Class_Num == Noble) {
						strcpy(user[j].Class, "평민");
						user[j].Class_Num = Farmer;
					}
					else if (user[j].Class_Num == Farmer) {
						strcpy(user[j].Class, "귀족");
						user[j].Class_Num = Noble;
					}
					else {
						strcpy(user[j].Class, "왕");
						user[j].Class_Num = King;
					}
				}
				printf("계급\n\n");
				for (int i = 0; i < Player; i++)
				{
					printf("%s의 계급 : %s\n", user[i].name, user[i].Class);
				}
				user[i].deck[0] = 0;
				return 0;
			}
		}
	}
	return -1;
}