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

#define Give_To_King 2
#define Give_To_Noble 1
#define Give_To_Farmer 1
#define Give_To_Slave 2

int Card_Class_King = 0; // 왕이 노예에게 줄 카드 계급
int Card_Class_Noble = 0; // 귀족이 농민에게 줄 카드 계급
int Card_Class_Farmer = 0; // 농민이 귀족에게 줄 카드 계급
int Card_Class_Slave = 0; // 노예가 왕에게 줄 카드 계급

void Pay_A_Tribute(struct User* User); // 조공 바치기 함수

void Pay_A_Tribute(struct User* User) {

	int count = 0;

	if (strcmp(User->Class, "왕") == 0) {
	KING:
		printf("노예에게 어떤 카드를 주겠습니까? : ");
		scanf_s("%d", &Card_Class_King);

		if (User->Card[Card_Class_King] == 0) {
			printf("카드가 부족합니다.\n");
			goto KING;
		}

		User->Card[Card_Class_King] -= Give_To_Slave;
	}
	else if (strcmp(User->Class, "귀족") == 0) {
	NOBLE:
		printf("농민에게 어떤 카드를 주겠습니까? : ");
		scanf_s("%d", &Card_Class_Noble);

		if (User->Card[Card_Class_Noble] == 0) {
			printf("카드가 부족합니다.\n");
			goto NOBLE;
		}

		User->Card[Card_Class_Noble] -= Give_To_Farmer;
	}
	else if (strcmp(User->Class, "농민") == 0) {
	FARMER:
		printf("귀족에게 어떤 카드를 주겠습니까? : ");
		scanf_s("%d", &Card_Class_Farmer);

		if (User->Card[Card_Class_Farmer] == 0) {
			printf("카드가 부족합니다.\n");
			goto FARMER;
		}
		for (int i = Card_Class_Farmer; i >= 0; i--) {
			if (User->Card[i] != 0) {
				count += 1;
			}
		}
		if (count != 0) {
			printf("입력하신 카드보다 작은 계급이 존재합니다.\n");
			goto FARMER;
		}

		User->Card[Card_Class_Farmer] -= Give_To_Noble;
	}
	else if (strcmp(User->Class, "노예") == 0) {
	SLAVE:
		printf("왕에게 어떤 카드를 주겠습니까? : ");
		scanf_s("%d", &Card_Class_Slave);

		if (User->Card[Card_Class_Slave] == 0) {
			printf("카드가 부족합니다.\n");
			goto SLAVE;
		}
		for (int i = Card_Class_Slave; i >= 0; i--) {
			if (User->Card[i] != 0) {
				count += 1;
			}
		}
		if (count != 0) {
			printf("입력하신 카드보다 작은 계급이 존재합니다.\n");
			goto SLAVE;
		}

		User->Card[Card_Class_Slave] -= Give_To_King;
	}

}