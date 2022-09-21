#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ���� ����ü
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

extern int Declare_Card_Class;
extern int Pay_Card_Num;
extern int preCard_Class;
extern int count;

extern char class[13][10];

int Play_A_Card(struct User* user) {

	if (user->Rank >= 1) return 0;
	system("cls");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s�� ī�� ��\n", user->name);
	for (int i = 0; i < 13; i++) {
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d\n", i, class[i], user->deck[i]);
	}

	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 }, buf_[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t����� ī���� ��ް� ����: %d %d\n", Declare_Card_Class, Pay_Card_Num);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t���� �÷��̾ �� ī���� ��� : %d\n", preCard_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t(����� ī���� ��ް� ���� �÷��̾ �� ī���� ����� 13�� ��� ����� �� ī�尡 ������ �˴ϴ�.)");
DECIDE:
	printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 ���ðڽ��ϱ�? (��Ŀ�� ������ 12�� ������ ī�带 �� �� �ֽ��ϴ�. \"����\" Ȥ�� \"�н�\" ��� �Է��Ͻÿ�) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "�н�") == 0) {
		count++;
		system("cls");
	}

	else if (strcmp(buf, "����") == 0) {
	PAY:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t� ī�带 ���ðڽ��ϱ�? : ");
		scanf_s("%d", &Card_Kind);

		if (Card_Kind > 12) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�\n");
			goto PAY;
		}
		else if (user->deck[Card_Kind] == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� ������ ���� �ʽ��ϴ�.\n");
			goto PAY;
		}
		else if (Declare_Card_Class <= Card_Kind || preCard_Class <= Card_Kind) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� �� �� �����ϴ�.\n");
			goto PAY;
		}

		if (count % 3 == 0) {
			Declare_Card_Class = Card_Kind;
			preCard_Class = Card_Kind;
		}
		else preCard_Class = Card_Kind;

		if (user->deck[0] > 0) {
		JOKER:
			printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 ���ðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\" ��� �Է��Ͻÿ�) : ");
			gets_s(buf_, 255);

			if (strcmp(buf_, "��") == 0) {
			HOW_JOKER:
				printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 �� �� ���ðڽ��ϱ�? : ");
				scanf_s("%d", &Joker);

				if (Joker > user->deck[0]) {
					printf("\n\t\t\t\t\t\t\t\t\t\t\t�ʹ� ���� ���̽��ϴ�.\n");
					goto HOW_JOKER;
				}

				else {
					user->deck[0] -= Joker;
					goto HOW_CARD;
				}
			}
			else if (strcmp(buf_, "�ƴϿ�") == 0) goto HOW_CARD;
			else {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
				goto JOKER;
			}
		}

	HOW_CARD:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s��(��) �� �� ���ðڽ��ϱ�? : ", class[Card_Kind]);
		scanf_s("%d", &Card_How);

		if (Joker > 0) {
			if (Pay_Card_Num > Card_How + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 �� ���ž��մϴ�.\n");
				goto HOW_CARD;
			}
			else if (Pay_Card_Num < Card_How + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 ���� ���̽��ϴ�.\n");
				goto HOW_CARD;
			}
			else user->deck[Card_Kind] -= Card_How;
		}

		else {
			if (user->deck[Card_Kind] < Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t�����Ͻ� ī�尡 �����մϴ�.\n");
				goto HOW_CARD;
			}
			else if (Pay_Card_Num > Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 %d�� �� ���ž��մϴ�.\n", Pay_Card_Num - Card_How);
				goto HOW_CARD;
			}
			else if (Pay_Card_Num > 0 && Pay_Card_Num < Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 %d�� �� ���̽��ϴ�.\n", Card_How - Pay_Card_Num);
				goto HOW_CARD;
			}
			else user->deck[Card_Kind] -= Card_How;
		}

		if (count % 3 == 0) Pay_Card_Num = Card_How;
		count++;
	}
	else {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
		goto DECIDE;
	}

	system("cls");
	return 0;
}