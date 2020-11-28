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

void Play_A_Card(struct User* User);

int preCard_Class = 13; // 이전에 나온 카드의 계급과 비교하기 위한 변수
int Pay_Card_Num = 0; // 선언한 카드의 개수를 저장할 변수
int count = 0, count_ = 0; // 턴을 카운트하기 위한 변수

void Play_A_Card(struct User* User) {

	// 플레이어가 낼 카드의 계급과 개수, 그리고 조커의 개수를 저장할 변수
	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 };

DECIDE:
	printf("카드를 내시겠습니까? (\"낸다\" 혹은 \"패스\" 라고 입력하시오) : ");
	gets_s(buf, 255);

	// 입력받은 문자열에 따라 진행
	if (strcmp(buf, "패스") == 0) {
		count++, count_++;
		return 0;
	}
	else if (strcmp(buf, "낸다") == 0) {
	PAY:
		printf("어떤 카드를 내시겠습니까? : ");
		scanf_s("%d", &Card_Kind);

		if (Error_(&User, Card_Kind, -1) == -1) goto PAY;

		if (count_ % 3 == 0) {
			preCard_Class = Card_Kind;
			count_ = 0;
		}

		if (User->Card[0] == 0) {
		JOKER:
			printf("어릿 광대를 내시겠습니까? (\"예\" 혹은 \"아니요\" 라고 입력하시오) : ");
			gets_s(buf, 255);

			if (strcmp(buf, "예") == 0) {
			HOW_:
				printf("몇 장을 내시겠습니까? : ");
				scanf_s("%d", &Joker);

				if (Error_(&User, 0, Joker) == -1) goto HOW_; // 조커 0장 입력했을 때 조건 설정하기
			}
			else if (strcmp(buf, "아니요") == 0) goto PRINT;
			else {
				printf("잘못 입력하셨습니다.\n");
				goto JOKER;
			}
			User->Card[0] -= Joker;
		}

	PRINT:
		if (Joker > 0) printf("입력하신 카드를 %d장을 내셔야합니다\n", Pay_Card_Num - Joker);
		else printf("입력하신 카드를 %d장을 내셔야합니다.\n", Pay_Card_Num);
		printf("(0장일 경우 자신이 내는 카드의 개수가 기준이 됩니다.)\n");

	HOW:
		printf("몇 장을 내시겠습니까? : ");
		scanf_s("%d", &Card_How);

		if (count % 3 == 0) {
			Pay_Card_Num = Card_How;
			count = 0;
		}

		if (Joker > 0) {
			if (Error_(&User, Card_Kind, Card_How + Joker) == -1) goto HOW;
		}

		else {
			if (Error_(&User, Card_Kind, Card_How) == -1) goto HOW;
		}

		User->Card[Card_Kind] -= Card_How;
		count++, count_++;
	}
	else {
		printf("잘못 입력하셨습니다.\n");
		goto DECIDE;
	}

	return 0;
}