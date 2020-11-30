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

int Card_Deal(struct User* User1, struct User* User2, struct User* User3, struct User* User4); // 카드 배분 함수

int Card_Deal(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {

	// 오류덩어리

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

DALMUTI:
	User1->Card[1] = rand() % 2;
	Dalmuti -= User1->Card[1];
	User1->Total_Card += User1->Card[1];
	if (Dalmuti == 0) goto ARCHBISHOP;

	do {
		User2->Card[1] = rand() % 2;
	} while (User2->Card[1] > Dalmuti);
	Dalmuti -= User2->Card[1];
	User2->Total_Card += User2->Card[1];
	if (Dalmuti == 0) goto ARCHBISHOP;

	do {
		User3->Card[1] = rand() % 2;
	} while (User3->Card[1] > Dalmuti);
	Dalmuti -= User3->Card[1];
	User3->Total_Card += User3->Card[1];
	if (Dalmuti == 0) goto ARCHBISHOP;

	do {
		User4->Card[1] = rand() % 2;
	} while (User4->Card[1] > Dalmuti);
	Dalmuti -= User4->Card[1];
	User4->Total_Card += User4->Card[1];

	if (Dalmuti != 0) {
		User1->Total_Card -= User1->Card[1]; User2->Total_Card -= User2->Card[1]; User3->Total_Card -= User3->Card[1]; User4->Total_Card -= User4->Card[1];
		User1->Card[1] = 0; User2->Card[1] = 0; User3->Card[1] = 0; User4->Card[1] = 0;
		Dalmuti = 1;
		goto DALMUTI;
	}

ARCHBISHOP:
	User1->Card[2] = rand() % 3;
	Archbishop -= User1->Card[2];
	User1->Total_Card += User1->Card[2];
	if (Archbishop == 0) goto EARLMARSHAL;

	do {
		User2->Card[2] = rand() % 3;
	} while (User2->Card[2] > Archbishop);
	Archbishop -= User2->Card[2];
	User2->Total_Card += User2->Card[2];
	if (Archbishop == 0) goto EARLMARSHAL;

	do {
		User3->Card[2] = rand() % 3;
	} while (User3->Card[2] > Archbishop);
	Archbishop -= User3->Card[2];
	User3->Total_Card += User3->Card[2];
	if (Archbishop == 0) goto EARLMARSHAL;

	do {
		User4->Card[2] = rand() % 3;
	} while (User4->Card[2] > Archbishop);
	Archbishop -= User4->Card[2];
	User4->Total_Card += User4->Card[2];

	if (Archbishop != 0) {
		User1->Total_Card -= User1->Card[2]; User2->Total_Card -= User2->Card[2]; User3->Total_Card -= User3->Card[2]; User4->Total_Card -= User4->Card[2];
		User1->Card[2] = 0; User2->Card[2] = 0; User3->Card[2] = 0; User4->Card[2] = 0;
		Archbishop = 2;
		goto ARCHBISHOP;
	}

EARLMARSHAL:
	User1->Card[3] = rand() % 4;
	EarlMarshal -= User1->Card[3];
	User1->Total_Card += User1->Card[3];
	if (EarlMarshal == 0) goto BARONESS;

	do {
		User2->Card[3] = rand() % 4;
	} while (User2->Card[3] > EarlMarshal);
	EarlMarshal -= User2->Card[3];
	User2->Total_Card += User2->Card[3];
	if (EarlMarshal == 0) goto BARONESS;

	do {
		User3->Card[3] = rand() % 4;
	} while (User3->Card[3] > EarlMarshal);
	EarlMarshal -= User3->Card[3];
	User3->Total_Card += User3->Card[3];
	if (EarlMarshal == 0) goto BARONESS;

	do {
		User4->Card[3] = rand() % 4;
	} while (User4->Card[3] > EarlMarshal);
	EarlMarshal -= User4->Card[3];
	User4->Total_Card += User4->Card[3];

	if (EarlMarshal != 0) {
		User1->Total_Card -= User1->Card[3]; User2->Total_Card -= User2->Card[3]; User3->Total_Card -= User3->Card[3]; User4->Total_Card -= User4->Card[3];
		User1->Card[3] = 0; User2->Card[3] = 0; User3->Card[3] = 0; User4->Card[3] = 0;
		EarlMarshal = 3;
		goto EARLMARSHAL;
	}

BARONESS:
	User1->Card[4] = rand() % 5;
	Baroness -= User1->Card[4];
	User1->Total_Card += User1->Card[4];
	if (Baroness == 0) goto ABBESS;

	do {
		User2->Card[4] = rand() % 5;
	} while (User2->Card[4] > Baroness);
	Baroness -= User2->Card[4];
	User2->Total_Card += User2->Card[4];
	if (Baroness == 0) goto ABBESS;

	do {
		User3->Card[4] = rand() % 5;
	} while (User3->Card[4] > Baroness);
	Baroness -= User3->Card[4];
	User3->Total_Card += User3->Card[4];
	if (Baroness == 0) goto ABBESS;

	do {
		User4->Card[4] = rand() % 5;
	} while (User4->Card[4] > Baroness);
	Baroness -= User4->Card[4];
	User4->Total_Card += User4->Card[4];

	if (Baroness != 0) {
		User1->Total_Card -= User1->Card[4]; User2->Total_Card -= User2->Card[4]; User3->Total_Card -= User3->Card[4]; User4->Total_Card -= User4->Card[4];
		User1->Card[4] = 0; User2->Card[4] = 0; User3->Card[4] = 0; User4->Card[4] = 0;
		Baroness = 4;
		goto BARONESS;
	}

ABBESS:
	User1->Card[5] = rand() % 6;
	Abbess -= User1->Card[5];
	User1->Total_Card += User1->Card[5];
	if (Abbess == 0) goto KNIGHT;

	do {
		User2->Card[5] = rand() % 6;
	} while (User2->Card[5] > Abbess);
	Abbess -= User2->Card[5];
	User2->Total_Card += User2->Card[5];
	if (Abbess == 0) goto KNIGHT;

	do {
		User3->Card[5] = rand() % 6;
	} while (User3->Card[5] > Abbess);
	Abbess -= User3->Card[5];
	User3->Total_Card += User3->Card[5];
	if (Abbess == 0) goto KNIGHT;

	do {
		User4->Card[5] = rand() % 6;
	} while (User4->Card[5] > Abbess);
	Abbess -= User4->Card[5];
	User4->Total_Card += User4->Card[5];

	if (Abbess != 0) {
		User1->Total_Card -= User1->Card[5]; User2->Total_Card -= User2->Card[5]; User3->Total_Card -= User3->Card[5]; User4->Total_Card -= User4->Card[5];
		User1->Card[5] = 0; User2->Card[5] = 0; User3->Card[5] = 0; User4->Card[5] = 0;
		Abbess = 5;
		goto ABBESS;
	}

KNIGHT:
	do {
		User1->Card[6] = rand() % 7;
	} while ((User1->Total_Card += User1->Card[6]) > 20);
	Knight -= User1->Card[6];
	User1->Total_Card += User1->Card[6];
	if (Knight == 0) goto SEAMSTRESS;

	do {
		User2->Card[6] = rand() % 7;
	} while (User2->Card[6] > Knight && (User2->Total_Card += User2->Card[6]) > 20);
	Knight -= User2->Card[6];
	User2->Total_Card += User2->Card[6];
	if (Knight == 0) goto SEAMSTRESS;

	do {
		User3->Card[6] = rand() % 7;
	} while (User3->Card[6] > Knight && (User3->Total_Card += User3->Card[6]) > 20);
	Knight -= User3->Card[6];
	User3->Total_Card += User3->Card[6];
	if (Knight == 0) goto SEAMSTRESS;

	do {
		User4->Card[6] = rand() % 7;
	} while (User4->Card[6] > Knight && (User4->Total_Card += User4->Card[6]) > 20);
	Knight -= User4->Card[6];
	User4->Total_Card += User4->Card[6];

	if (Knight != 0) {
		User1->Total_Card -= User1->Card[6]; User2->Total_Card -= User2->Card[6]; User3->Total_Card -= User3->Card[6]; User4->Total_Card -= User4->Card[6];
		User1->Card[6] = 0; User2->Card[6] = 0; User3->Card[6] = 0; User4->Card[6] = 0;
		Knight = 6;
		goto KNIGHT;
	}

SEAMSTRESS:
	do {
		User1->Card[7] = rand() % 8;
	} while ((User1->Total_Card += User1->Card[7]) > 20);
	Seamstress -= User1->Card[7];
	User1->Total_Card += User1->Card[7];
	if (Seamstress == 0) goto MASON;

	do {
		User2->Card[7] = rand() % 8;
	} while (User2->Card[7] > Seamstress && (User2->Total_Card += User1->Card[7]) > 20);
	Seamstress -= User2->Card[7];
	User2->Total_Card += User2->Card[7];
	if (Seamstress == 0) goto MASON;

	do {
		User3->Card[7] = rand() % 8;
	} while (User3->Card[7] > Seamstress && (User3->Total_Card += User3->Card[7]) > 20);
	Seamstress -= User3->Card[7];
	User3->Total_Card += User3->Card[7];
	if (Seamstress == 0) goto MASON;

	do {
		User4->Card[7] = rand() % 8;
	} while (User4->Card[7] > Seamstress && (User4->Total_Card += User4->Card[7]) > 20);
	Seamstress -= User4->Card[7];
	User4->Total_Card += User4->Card[7];

	if (Seamstress != 0) {
		User1->Total_Card -= User1->Card[7]; User2->Total_Card -= User2->Card[7]; User3->Total_Card -= User3->Card[7]; User4->Total_Card -= User4->Card[7];
		User1->Card[7] = 0; User2->Card[7] = 0; User3->Card[7] = 0; User4->Card[7] = 0;
		Seamstress = 7;
		goto SEAMSTRESS;
	}

MASON:
	do {
		User1->Card[8] = rand() % 9;
	} while ((User1->Total_Card += User1->Card[8]) > 20);
	Mason -= User1->Card[8];
	User1->Total_Card += User1->Card[8];
	if (Mason == 0) goto COOK;

	do {
		User2->Card[8] = rand() % 9;
	} while (User2->Card[8] > Mason && (User2->Total_Card += User2->Card[8]) > 20);
	Mason -= User2->Card[8];
	User2->Total_Card += User2->Card[8];
	if (Mason == 0) goto COOK;

	do {
		User3->Card[8] = rand() % 9;
	} while (User3->Card[8] > Mason && (User3->Total_Card += User3->Card[8]) > 20);
	Mason -= User3->Card[8];
	User3->Total_Card += User3->Card[8];
	if (Mason == 0) goto COOK;

	do {
		User4->Card[8] = rand() % 9;
	} while (User4->Card[8] > Mason && (User4->Total_Card += User4->Card[8]) > 20);
	Mason -= User4->Card[8];
	User4->Total_Card += User4->Card[8];

	if (Mason != 0) {
		User1->Total_Card -= User1->Card[8]; User2->Total_Card -= User2->Card[8]; User3->Total_Card -= User3->Card[8]; User4->Total_Card -= User4->Card[8];
		User1->Card[8] = 0; User2->Card[8] = 0; User3->Card[8] = 0; User4->Card[8] = 0;
		Mason = 8;
		goto MASON;
	}

COOK:
	do {
		User1->Card[9] = rand() % 10;
	} while ((User1->Total_Card += User1->Card[9]) > 20);
	Cook -= User1->Card[9];
	User1->Total_Card += User1->Card[9];
	if (Cook == 0) goto SHEPHERDESS;

	do {
		User2->Card[9] = rand() % 10;
	} while (User2->Card[9] > Cook && (User2->Total_Card += User2->Card[9]) > 20);
	Cook -= User2->Card[9];
	User2->Total_Card += User2->Card[9];
	if (Cook == 0) goto SHEPHERDESS;

	do {
		User3->Card[9] = rand() % 10;
	} while (User3->Card[9] > Cook && (User3->Total_Card += User3->Card[9]) > 20);
	Cook -= User3->Card[9];
	User3->Total_Card += User3->Card[9];
	if (Cook == 0) goto SHEPHERDESS;

	do {
		User4->Card[9] = rand() % 10;
	} while (User4->Card[9] > Cook && (User4->Total_Card += User4->Card[9]) > 20);
	Cook -= User4->Card[9];
	User4->Total_Card += User4->Card[9];

	if (Cook != 0) {
		User1->Total_Card -= User1->Card[9]; User2->Total_Card -= User2->Card[9]; User3->Total_Card -= User3->Card[9]; User4->Total_Card -= User4->Card[9];
		User1->Card[9] = 0; User2->Card[9] = 0; User3->Card[9] = 0; User4->Card[9] = 0;
		Cook = 9;
		goto COOK;
	}

SHEPHERDESS:
	do {
		User1->Card[10] = rand() % 11;
	} while ((User1->Total_Card += User1->Card[10]) > 20);
	Shepherdess -= User1->Card[10];
	User1->Total_Card += User1->Card[10];
	if (Shepherdess == 0) goto FLUSH;

	do {
		User2->Card[10] = rand() % 11;
	} while (User2->Card[10] > Shepherdess && (User2->Total_Card += User2->Card[10]) > 20);
	Shepherdess -= User2->Card[10];
	User2->Total_Card += User2->Card[10];
	if (Shepherdess == 0) goto FLUSH;

	do {
		User3->Card[10] = rand() % 11;
	} while (User3->Card[10] > Shepherdess && (User3->Total_Card += User3->Card[10]) > 20);
	Shepherdess -= User3->Card[10];
	User3->Total_Card += User3->Card[10];
	if (Shepherdess == 0) goto FLUSH;

	do {
		User4->Card[10] = rand() % 11;
	} while (User4->Card[10] > Shepherdess && (User4->Total_Card += User4->Card[10]) > 20);
	Shepherdess -= User4->Card[10];
	User4->Total_Card += User4->Card[10];

	if (Shepherdess != 0) {
		User1->Total_Card -= User1->Card[10]; User2->Total_Card -= User2->Card[10]; User3->Total_Card -= User3->Card[10]; User4->Total_Card -= User4->Card[10];
		User1->Card[10] = 0; User2->Card[10] = 0; User3->Card[10] = 0; User4->Card[10] = 0;
		Shepherdess = 10;
		goto SHEPHERDESS;
	}

FLUSH:
	do {
		User1->Card[11] = rand() % 12;
	} while ((User1->Total_Card += User1->Card[11]) > 20);
	Flush -= User1->Card[11];
	User1->Total_Card += User1->Card[11];
	if (Flush == 0) goto PEASANT;

	do {
		User2->Card[11] = rand() % 12;
	} while (User2->Card[11] > Flush && (User2->Total_Card += User2->Card[11]) > 20);
	Flush -= User2->Card[11];
	User2->Total_Card += User2->Card[11];
	if (Flush == 0) goto PEASANT;

	do {
		User3->Card[11] = rand() % 12;
	} while (User3->Card[11] > Flush && (User3->Total_Card += User3->Card[11]) > 20);
	Flush -= User3->Card[11];
	User3->Total_Card += User3->Card[11];
	if (Flush == 0) goto PEASANT;

	do {
		User4->Card[11] = rand() % 12;
	} while (User4->Card[11] > Flush && (User4->Total_Card += User4->Card[11]) > 20);
	Flush -= User4->Card[11];
	User4->Total_Card += User4->Card[11];

	if (Flush != 0) {
		User1->Total_Card -= User1->Card[11]; User2->Total_Card -= User2->Card[11]; User3->Total_Card -= User3->Card[11]; User4->Total_Card -= User4->Card[11];
		User1->Card[11] = 0; User2->Card[11] = 0; User3->Card[11] = 0; User4->Card[11] = 0;
		Flush = 11;
		goto FLUSH;
	}

PEASANT:
	do {
		User1->Card[12] = rand() % 13;
	} while ((User1->Total_Card += User1->Card[12]) > 20);
	Peasant -= User1->Card[12];
	User1->Total_Card += User1->Card[12];
	if (Peasant == 0) goto JESTER;

	do {
		User2->Card[12] = rand() % 13;
	} while (User2->Card[12] > Peasant && (User2->Total_Card += User2->Card[12]) > 20);
	Peasant -= User2->Card[12];
	User2->Total_Card += User2->Card[12];
	if (Peasant == 0) goto JESTER;

	do {
		User3->Card[12] = rand() % 13;
	} while (User3->Card[12] > Peasant && (User3->Total_Card += User3->Card[12]) > 20);
	Peasant -= User3->Card[12];
	User2->Total_Card += User2->Card[12];
	if (Peasant == 0) goto JESTER;

	do {
		User4->Card[12] = rand() % 13;
	} while (User4->Card[12] > Peasant && (User4->Total_Card += User4->Card[12]) > 20);
	Peasant -= User4->Card[12];

	if (Peasant != 0) {
		User1->Total_Card -= User1->Card[12]; User2->Total_Card -= User2->Card[12]; User3->Total_Card -= User3->Card[12]; User4->Total_Card -= User4->Card[12];
		User1->Card[12] = 0; User2->Card[12] = 0; User3->Card[12] = 0; User4->Card[12] = 0;
		goto PEASANT;
	}

JESTER:
	do {
		User1->Card[0] = rand() % 3;
	} while ((User1->Total_Card += User1->Card[0]) > 20);
	Jester -= User1->Card[0];
	User1->Total_Card += User1->Card[0];
	if (Jester == 0) return 0;

	do {
		User2->Card[0] = rand() % 3;
	} while (User2->Card[0] > Jester && (User2->Total_Card += User2->Card[0]) > 20);
	Jester -= User2->Card[0];
	User2->Total_Card += User2->Card[0];
	if (Jester == 0) return 0;

	do {
		User3->Card[0] = rand() % 3;
	} while (User3->Card[0] > Jester && (User3->Total_Card += User3->Card[0]) > 20);
	Jester -= User3->Card[0];
	User3->Total_Card += User3->Card[0];
	if (Jester == 0) return 0;

	do {
		User4->Card[0] = rand() % 3;
	} while (User4->Card[0] > Jester && (User4->Total_Card += User4->Card[0]) > 20);
	Jester -= User4->Card[12];
	User4->Total_Card += User4->Card[0];

	if (Jester != 0) {
		User1->Total_Card -= User1->Card[0]; User2->Total_Card -= User2->Card[0]; User3->Total_Card -= User3->Card[0]; User4->Total_Card -= User4->Card[0];
		User1->Card[0] = 0; User2->Card[0] = 0; User3->Card[0] = 0; User4->Card[0] = 0;
		Jester = 2;
		goto JESTER;
	}

	return 0;
}