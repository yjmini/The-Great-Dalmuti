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

int Card_Deal(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {

	// 카드 분배 과정에서 한 종류의 카드가 모두 소진되지 않았음에도 불과하고 다음 카드 배분으로 넘어가는 현상 수정하기
	// 카드 수를 초과해서 주는 현상 수정하기

	int Dalmuti = 1, Archbishop = 2, EarlMarshal = 3, Baroness = 4, Abbess = 5, Knight = 6, Seamstress = 7, Mason = 8, Cook = 9, Shepherdess = 10, Flush = 11, Peasant = 12, Jester = 2;
	char input[255] = { 0 };

DECIDE:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    카드를 배분하시겠습니까? (\"배분하기\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "배분하기") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto DECIDE;
	}

	User1->Card[1] = rand() % 2;
	Dalmuti -= User1->Card[1];
	if (Dalmuti == 0) goto ARCHBISHOP;

	User2->Card[1] = rand() % 2;
	Dalmuti -= User2->Card[1];
	if (Dalmuti == 0) goto ARCHBISHOP;

	User3->Card[1] = rand() % 2;
	Dalmuti -= User3->Card[1];
	if (Dalmuti == 0) goto ARCHBISHOP;

	User4->Card[1] = rand() % 2;
	Dalmuti -= User4->Card[1];

ARCHBISHOP:
	User1->Card[2] = rand() % 3;
	Archbishop -= User1->Card[2];
	if (Archbishop == 0) goto EARLMARSHAL;

	User2->Card[2] = rand() % 3;
	Archbishop -= User2->Card[2];
	if (Archbishop == 0) goto EARLMARSHAL;

	User3->Card[2] = rand() % 3;
	Archbishop -= User3->Card[2];
	if (Archbishop == 0) goto EARLMARSHAL;

	User4->Card[2] = rand() % 3;
	Archbishop -= User4->Card[2];

EARLMARSHAL:
	User1->Card[3] = rand() % 4;
	EarlMarshal -= User1->Card[3];
	if (EarlMarshal == 0) goto BARONESS;

	User2->Card[3] = rand() % 4;
	EarlMarshal -= User2->Card[3];
	if (EarlMarshal == 0) goto BARONESS;

	User3->Card[3] = rand() % 4;
	EarlMarshal -= User3->Card[3];
	if (EarlMarshal == 0) goto BARONESS;

	User4->Card[3] = rand() % 4;
	EarlMarshal -= User4->Card[3];

BARONESS:
	User1->Card[4] = rand() % 5;
	Baroness -= User1->Card[4];
	if (Baroness == 0) goto ABBESS;

	User2->Card[4] = rand() % 5;
	Baroness -= User2->Card[4];
	if (Baroness == 0) goto ABBESS;

	User3->Card[4] = rand() % 5;
	Baroness -= User3->Card[4];
	if (Baroness == 0) goto ABBESS;

	User4->Card[4] = rand() % 5;
	Baroness -= User4->Card[4];

ABBESS:
	User1->Card[5] = rand() % 6;
	Abbess -= User1->Card[5];
	if (Abbess == 0) goto KNIGHT;

	User2->Card[5] = rand() % 6;
	Abbess -= User2->Card[5];
	if (Abbess == 0) goto KNIGHT;

	User3->Card[5] = rand() % 6;
	Abbess -= User3->Card[5];
	if (Abbess == 0) goto KNIGHT;

	User4->Card[5] = rand() % 6;
	Abbess -= User4->Card[5];

KNIGHT:
	User1->Card[6] = rand() % 7;
	Knight -= User1->Card[6];
	if (Knight == 0) goto SEAMSTRESS;

	User2->Card[6] = rand() % 7;
	Knight -= User2->Card[6];
	if (Knight == 0) goto SEAMSTRESS;

	User3->Card[6] = rand() % 7;
	Knight -= User3->Card[6];
	if (Knight == 0) goto SEAMSTRESS;

	User4->Card[6] = rand() % 7;
	Knight -= User4->Card[6];

SEAMSTRESS:
	User1->Card[7] = rand() % 8;
	Seamstress -= User1->Card[7];
	if (Seamstress == 0) goto MASON;

	User2->Card[7] = rand() % 8;
	Seamstress -= User2->Card[7];
	if (Seamstress == 0) goto MASON;

	User3->Card[7] = rand() % 8;
	Seamstress -= User3->Card[7];
	if (Seamstress == 0) goto MASON;

	User4->Card[7] = rand() % 8;
	Seamstress -= User4->Card[7];

MASON:
	User1->Card[8] = rand() % 9;
	Mason -= User1->Card[8];
	if (Mason == 0) goto COOK;

	User2->Card[8] = rand() % 9;
	Mason -= User2->Card[8];
	if (Mason == 0) goto COOK;

	User3->Card[8] = rand() % 9;
	Mason -= User3->Card[8];
	if (Mason == 0) goto COOK;

	User4->Card[8] = rand() % 9;
	Mason -= User4->Card[8];

COOK:
	User1->Card[9] = rand() % 10;
	Cook -= User1->Card[9];
	if (Cook == 0) goto SHEPHERDESS;

	User2->Card[9] = rand() % 10;
	Cook -= User2->Card[9];
	if (Cook == 0) goto SHEPHERDESS;

	User3->Card[9] = rand() % 10;
	Cook -= User3->Card[9];
	if (Cook == 0) goto SHEPHERDESS;

	User4->Card[9] = rand() % 10;
	Cook -= User4->Card[9];

SHEPHERDESS:
	User1->Card[10] = rand() % 11;
	Shepherdess -= User1->Card[10];
	if (Shepherdess == 0) goto FLUSH;

	User2->Card[10] = rand() % 11;
	Shepherdess -= User2->Card[10];
	if (Shepherdess == 0) goto FLUSH;

	User3->Card[10] = rand() % 11;
	Shepherdess -= User3->Card[10];
	if (Shepherdess == 0) goto FLUSH;

	User4->Card[10] = rand() % 11;
	Shepherdess -= User4->Card[10];

FLUSH:
	User1->Card[11] = rand() % 12;
	Flush -= User1->Card[11];
	if (Flush == 0) goto PEASANT;

	User2->Card[11] = rand() % 12;
	Flush -= User2->Card[11];
	if (Flush == 0) goto PEASANT;

	User3->Card[11] = rand() % 12;
	Flush -= User3->Card[11];
	if (Flush == 0) goto PEASANT;

	User4->Card[11] = rand() % 12;
	Flush -= User4->Card[11];

PEASANT:
	User1->Card[12] = rand() % 13;
	Peasant -= User1->Card[12];
	if (Peasant == 0) goto JESTER;

	User2->Card[12] = rand() % 13;
	Peasant -= User2->Card[12];
	if (Peasant == 0) goto JESTER;

	User3->Card[12] = rand() % 13;
	Peasant -= User3->Card[12];
	if (Peasant == 0) goto JESTER;

	User4->Card[12] = rand() % 13;
	Peasant -= User4->Card[12];

JESTER:
	User1->Card[0] = rand() % 3;
	Jester -= User1->Card[0];
	if (Jester == 0) return 0;

	User2->Card[0] = rand() % 3;
	Jester -= User2->Card[0];
	if (Jester == 0) return 0;

	User3->Card[0] = rand() % 3;
	Jester -= User3->Card[0];
	if (Jester == 0) return 0;

	User4->Card[0] = rand() % 3;
	Jester -= User4->Card[12];

	return 0;
}
