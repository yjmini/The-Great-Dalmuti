#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

int preCard_Class = 13; // 이전에 나온 카드의 계급과 비교하기 위한 변수
int Declare_Card_Class = 13; // 선언된 카드의 계급
int Pay_Card_Num = 0; // 선언한 카드의 개수를 저장할 변수
int count = 0; // 턴을 카운트하기 위한 변수

const char class[13][10] = { "조커", "달무티", "대주교","시종장","남작부인","수녀원장","기사","재봉사","석공","요리사","양치기","광부","노예" };

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

void Play_A_Card(struct User* User) {

	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 }, buf_[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t선언된 카드의 계급과 개수: %d %d\n", Declare_Card_Class, Pay_Card_Num);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t이전 플레이어가 낸 카드의 계급 : %d\n", preCard_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t(선언된 카드의 계급과 이전 플레이어가 낸 카드의 계급이 13일 경우 당신이 낸 카드가 기준이 됩니다.)");
DECIDE:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 내시겠습니까? (\"낸다\" 혹은 \"패스\" 라고 입력하시오) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "패스") == 0) {
		count++;
		system("cls");
	}

	else if (strcmp(buf, "낸다") == 0) {
	PAY:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t어떤 카드를 내시겠습니까? : ");
		scanf_s("%d", &Card_Kind);

		if (Card_Kind >= 13) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다\n");
			goto PAY;
		}
		else if (User->deck[Card_Kind] == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드는 가지고 있지 않습니다.\n");
			goto PAY;
		}
		else if (Declare_Card_Class <= Card_Kind && preCard_Class <= Card_Kind) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드는 낼 수 없습니다.\n");
			goto PAY;
		}

		if (count % 3 == 0) {
			Declare_Card_Class = Card_Kind;
			preCard_Class = Card_Kind;
		}
		else preCard_Class = Card_Kind;

		if (User->deck[0] > 0) {
		JOKER:
			printf("\n\t\t\t\t\t\t\t\t\t\t\t어릿 광대를 내시겠습니까? (\"예\" 혹은 \"아니요\" 라고 입력하시오) : ");
			gets_s(buf_, 255);

			if (strcmp(buf_, "예") == 0) {
			HOW_JOKER:
				printf("\n\t\t\t\t\t\t\t\t\t\t\t어릿 광대를 몇 장 내시겠습니까? : ");
				scanf_s("%d", &Joker);

				if (Joker > User->deck[0]) {
					printf("\n\t\t\t\t\t\t\t\t\t\t\t너무 많이 내셨습니다.\n");
					goto HOW_JOKER;
				}

				else {
					User->deck[0] -= Joker;
					goto HOW_CARD;
				}
			}
			else if (strcmp(buf_, "아니요") == 0) goto HOW_CARD;
			else {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
				goto JOKER;
			}
		}

	HOW_CARD:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s를 몇 장 내시겠습니까? : ", class[Card_Kind]);
		scanf_s("%d", &Card_How);

		if (Joker > 0) {
			if (Pay_Card_Num > Card_How + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 더 내셔야합니다.\n");
				goto HOW_CARD;
			}
			else if (Pay_Card_Num < Card_How + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 많이 내셨습니다.\n");
				goto HOW_CARD;
			}
			else User->deck[Card_Kind] -= Card_How;
		}

		else {
			if (User->deck[Card_Kind] < Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t소유하신 카드가 부족합니다.\n");
				goto HOW_CARD;
			}
			else if (Pay_Card_Num > Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 %d장 더 내셔야합니다.\n", Pay_Card_Num - Card_How);
				goto HOW_CARD;
			}
			else if (Pay_Card_Num > 0 && Pay_Card_Num < Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 %d장 더 내셨습니다.\n", Card_How - Pay_Card_Num);
				goto HOW_CARD;
			}
		}

		if (count % 3 == 0) {
			Pay_Card_Num = Card_How;
			User->deck[Card_Kind] -= Card_How;
		}
		else User->deck[Card_Kind] -= Card_How;
		count++;
	}
	else {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
		goto DECIDE;
	}

	system("cls");
}