#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 11.23

// 유저 구조체
struct User {
	char name[255];
	char Class[5];
	int Card[13];
};

int Pay_Card_Error(struct User* User, int Card_Kind, int Card_How);

int preCard_Class = 13; // 이전에 나온 카드의 계급과 비교하기 위한 변수
int Pay_Card_Num = 0; // 선언한 카드의 개수를 저장할 변수

int Pay_Card_Error(struct User* User, int Card_Kind, int Card_How) {

	if (Card_How == -1) {
		if (Card_Kind >= 13) {
			printf("잘못 입력하셨습니다\n");
			return -1;
		}

		else if (User->Card[Card_Kind] == 0) {
			printf("입력하신 카드는 가지고 있지 않습니다.\n");
			return -1;
		}

		else if (preCard_Class <= Card_Kind) {
			printf("입력하신 카드는 낼 수 없습니다.\n");
			return -1;
		}
	}

	else {
		if (User->Card[Card_Kind] < Card_How) {
			printf("소유하신 카드가 부족합니다.\n");
			return -1;
		}

		else if (Pay_Card_Num > User->Card[Card_Kind] || Card_How == 0) {
			printf("카드를 더 내셔야합니다.\n");
			return -1;
		}

		else if (Pay_Card_Num < User->Card[Card_Kind]) {
			printf("카드를 너무 많이 내셨습니다.\n");
			return -1;
		}
	}

	return 0;
}