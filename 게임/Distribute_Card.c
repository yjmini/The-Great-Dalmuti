#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Decide_Distribute_Card() {
	char input[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t    카드를 배분하시겠습니까? (\"배분하기\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "배분하기") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		Decide_Distribute_Card();
	}
}

void Distribute_Card(int* User1_Card, int* User2_Card, int* User3_Card, int* User4_Card) {
	// 오류 고치기
	int Dalmuti = 1, Archbishop = 2, EarlMarshal = 3, Baroness = 4, Abbess = 5, Knight = 6, Seamstress = 7, Mason = 8, Cook = 9, Shepherdess = 10, Flush = 11, Peasant = 12, Jester = 2;

DALMUTI:
	*User1_Card = rand() % 2;
	Dalmuti -= *User1_Card;
	User1_Card++;
	if (Dalmuti == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto ARCHBISHOP;
	}

	*User2_Card = rand() % 2;
	Dalmuti -= *User2_Card;
	User2_Card++;
	if (Dalmuti == 0) {
		User3_Card++;
		User4_Card++;
		goto ARCHBISHOP;
	}

	*User3_Card = rand() % 2;
	Dalmuti -= *User3_Card;
	User3_Card++;
	if (Dalmuti == 0) {
		User4_Card++;
		goto ARCHBISHOP;
	}

	*User4_Card = rand() % 2;
	Dalmuti -= *User4_Card;
	User4_Card++;

ARCHBISHOP:
	*User1_Card = rand() % 3;
	Archbishop -= *User1_Card;
	User1_Card++;
	if (Archbishop == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto EARLMARSHAL;
	}

	*User2_Card = rand() % 3;
	Archbishop -= *User2_Card;
	User2_Card++;
	if (Archbishop == 0) {
		User3_Card++;
		User4_Card++;
		goto EARLMARSHAL;
	}

	*User3_Card = rand() % 3;
	Archbishop -= *User3_Card;
	User3_Card++;
	if (Archbishop == 0) {
		User4_Card++;
		goto EARLMARSHAL;
	}

	*User4_Card = rand() % 3;
	Archbishop -= *User4_Card;
	User4_Card++;

EARLMARSHAL:
	*User1_Card = rand() % 4;
	EarlMarshal -= *User1_Card;
	User1_Card++;
	if (EarlMarshal == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto BARONESS;
	}

	*User2_Card = rand() % 4;
	EarlMarshal -= *User2_Card;
	User2_Card++;
	if (EarlMarshal == 0) {
		User3_Card++;
		User4_Card++;
		goto BARONESS;
	}

	*User3_Card = rand() % 4;
	EarlMarshal -= *User3_Card;
	User3_Card++;
	if (EarlMarshal == 0) {
		User4_Card++;
		goto BARONESS;
	}

	*User4_Card = rand() % 4;
	EarlMarshal -= *User4_Card;
	User4_Card++;

BARONESS:
	*User1_Card = rand() % 5;
	Baroness -= *User1_Card;
	User1_Card++;
	if (Baroness == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto ABBESS;
	}

	*User2_Card = rand() % 5;
	Baroness -= *User2_Card;
	User2_Card++;
	if (Baroness == 0) {
		User3_Card++;
		User4_Card++;
		goto ABBESS;
	}

	*User3_Card = rand() % 5;
	Baroness -= *User3_Card;
	User3_Card++;
	if (Baroness == 0) {
		User4_Card++;
		goto ABBESS;
	}

	*User4_Card = rand() % 5;
	Baroness -= *User4_Card;
	User4_Card++;

ABBESS:
	*User1_Card = rand() % 6;
	Abbess -= *User1_Card;
	User1_Card++;
	if (Abbess == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto KNIGHT;
	}

	*User2_Card = rand() % 6;
	Abbess -= *User2_Card;
	User2_Card++;
	if (Abbess == 0) {
		User3_Card++;
		User4_Card++;
		goto KNIGHT;
	}

	*User3_Card = rand() % 6;
	Abbess -= *User3_Card;
	User3_Card++;
	if (Abbess == 0) {
		User4_Card++;
		goto KNIGHT;
	}

	*User4_Card = rand() % 6;
	Abbess -= *User4_Card;
	User4_Card++;

KNIGHT:
	*User1_Card = rand() % 7;
	Knight -= *User1_Card;
	User1_Card++;
	if (Knight == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto SEAMSTRESS;
	}

	*User2_Card = rand() % 7;
	Knight -= *User2_Card;
	User2_Card++;
	if (Knight == 0) {
		User3_Card++;
		User4_Card++;
		goto SEAMSTRESS;
	}

	*User3_Card = rand() % 7;
	Knight -= *User3_Card;
	User3_Card++;
	if (Knight == 0) {
		User4_Card++;
		goto SEAMSTRESS;
	}

	*User4_Card = rand() % 7;
	Knight -= *User4_Card;
	User4_Card++;

SEAMSTRESS:
	*User1_Card = rand() % 8;
	Seamstress -= *User1_Card;
	User1_Card++;
	if (Seamstress == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto MASON;
	}

	*User2_Card = rand() % 8;
	Seamstress -= *User2_Card;
	User2_Card++;
	if (Seamstress == 0) {
		User3_Card++;
		User4_Card++;
		goto MASON;
	}

	*User3_Card = rand() % 8;
	Seamstress -= *User3_Card;
	User3_Card++;
	if (Seamstress == 0) {
		User4_Card++;
		goto MASON;
	}

	*User4_Card = rand() % 8;
	Seamstress -= *User4_Card;
	User4_Card++;

MASON:
	*User1_Card = rand() % 9;
	Mason -= *User1_Card;
	User1_Card++;
	if (Mason == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto COOK;
	}

	*User2_Card = rand() % 9;
	Mason -= *User2_Card;
	User2_Card++;
	if (Mason == 0) {
		User3_Card++;
		User4_Card++;
		goto COOK;
	}

	*User3_Card = rand() % 9;
	Mason -= *User3_Card;
	User3_Card++;
	if (Mason == 0) {
		User4_Card++;
		goto COOK;
	}

	*User4_Card = rand() % 9;
	Mason -= *User4_Card;
	User4_Card++;

COOK:
	*User1_Card = rand() % 10;
	Cook -= *User1_Card;
	User1_Card++;
	if (Mason == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto SHEPHERDESS;
	}

	*User2_Card = rand() % 10;
	Cook -= *User2_Card;
	User2_Card++;
	if (Mason == 0) {
		User3_Card++;
		User4_Card++;
		goto SHEPHERDESS;
	}

	*User3_Card = rand() % 10;
	Cook -= *User3_Card;
	User3_Card++;
	if (Mason == 0) {
		User4_Card++;
		goto SHEPHERDESS;
	}

	*User4_Card = rand() % 10;
	Cook -= *User4_Card;
	User4_Card++;

SHEPHERDESS:
	*User1_Card = rand() % 11;
	Shepherdess -= *User1_Card;
	User1_Card++;
	if (Shepherdess == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto FLUSH;
	}

	*User2_Card = rand() % 11;
	Shepherdess -= *User2_Card;
	User2_Card++;
	if (Shepherdess == 0) {
		User3_Card++;
		User4_Card++;
		goto FLUSH;
	}

	*User3_Card = rand() % 11;
	Shepherdess -= *User3_Card;
	User3_Card++;
	if (Shepherdess == 0) {
		User4_Card++;
		goto FLUSH;
	}

	*User4_Card = rand() % 11;
	Shepherdess -= *User4_Card;
	User4_Card++;

FLUSH:
	*User1_Card = rand() % 12;
	Flush -= *User1_Card;
	User1_Card++;
	if (Flush == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto PEASANT;
	}

	*User2_Card = rand() % 12;
	Flush -= *User2_Card;
	User2_Card++;
	if (Flush == 0) {
		User3_Card++;
		User4_Card++;
		goto PEASANT;
	}

	*User3_Card = rand() % 12;
	Flush -= *User3_Card;
	User3_Card++;
	if (Flush == 0) {
		User4_Card++;
		goto PEASANT;
	}

	*User4_Card = rand() % 12;
	Flush -= *User4_Card;
	User4_Card++;

PEASANT:
	*User1_Card = rand() % 13;
	Peasant -= *User1_Card;
	User1_Card++;
	if (Peasant == 0) {
		User2_Card++;
		User3_Card++;
		User4_Card++;
		goto JESTER;
	}

	*User2_Card = rand() % 13;
	Peasant -= *User2_Card;
	User2_Card++;
	if (Peasant == 0) {
		User3_Card++;
		User4_Card++;
		goto JESTER;
	}

	*User3_Card = rand() % 13;
	Peasant -= *User3_Card;
	User3_Card++;
	if (Peasant == 0) {
		User4_Card++;
		goto JESTER;
	}

	*User4_Card = rand() % 13;
	Peasant -= *User4_Card;
	User4_Card++;

JESTER:
	*User1_Card = rand() % 3;
	Peasant -= *User1_Card;
	if (Peasant == 0) {
		return 0;
	}

	*User2_Card = rand() % 3;
	Peasant -= *User2_Card;
	if (Peasant == 0) {
		return 0;
	}

	*User3_Card = rand() % 3;
	Peasant -= *User3_Card;
	if (Peasant == 0) {
		return 0;
	}

	*User4_Card = rand() % 3;
	Peasant -= *User4_Card;
}