#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ���� ����ü
struct User {
	char name[255];
	char Class[5];
	int Card[13];
	int Total_Card;
};

void Play_A_Card(struct User* User); // ī�� ���� �Լ�

int preCard_Class = 13; // ������ ���� ī���� ��ް� ���ϱ� ���� ����
int Declare_Card_Class = 13; // ����� ī���� ���
int Pay_Card_Num = 0; // ������ ī���� ������ ������ ����
int count = 0; // ���� ī��Ʈ�ϱ� ���� ����

void Play_A_Card(struct User* User) {

	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t����� ī���� ��ް� ����: %d %d\n", Declare_Card_Class, Pay_Card_Num);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t���� �÷��̾ �� ī���� ��� : %d\n", preCard_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t(����� ī���� ��ް� ���� �÷��̾ �� ī���� ����� 13�� ��� ����� �� ī�尡 ������ �˴ϴ�.");
DECIDE:
	printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 ���ðڽ��ϱ�? (\"����\" Ȥ�� \"�н�\" ��� �Է��Ͻÿ�) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "�н�") == 0) {
		count++;
		system("cls");
	}

	else if (strcmp(buf, "����") == 0) {
	PAY:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t� ī�带 ���ðڽ��ϱ�? : ");
		scanf_s("%d", &Card_Kind);

		if (Card_Kind >= 13) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�\n");
			goto PAY;
		}
		else if (User->Card[Card_Kind] == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� ������ ���� �ʽ��ϴ�.\n");
			goto PAY;
		}
		else if (Declare_Card_Class <= Card_Kind && preCard_Class <= Card_Kind) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� �� �� �����ϴ�.\n");
			goto PAY;
		}

		if (count % 3 == 0) Declare_Card_Class = Card_Kind;
		preCard_Class = Card_Kind;

		if (User->Card[0] > 0) {
		JOKER:
			printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 ���ðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\" ��� �Է��Ͻÿ�) : ");
			gets_s(buf, 255);

			if (strcmp(buf, "��") == 0) {
			HOW_:
				printf("\n\t\t\t\t\t\t\t\t\t\t\t�� ���� ���ðڽ��ϱ�? : ");
				scanf_s("%d", &Joker);

				if (Joker < User->Card[0]) {
					printf("\n\t\t\t\t\t\t\t\t\t\t\t�����Ͻ� ī�尡 �����մϴ�.\n");
					goto HOW_;
				}
			}
			else if (strcmp(buf, "�ƴϿ�") == 0) goto HOW;
			else {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
				goto JOKER;
			}
			User->Card[0] -= Joker;
		}

	HOW:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t�� ���� ���ðڽ��ϱ�? : ");
		scanf_s("%d", &Card_How);

		if (Joker > 0) {
			if (Pay_Card_Num > User->Card[Card_Kind] + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 �� ���ž��մϴ�.\n");
				goto HOW;
			}
			else if (Pay_Card_Num < User->Card[Card_Kind] + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 ���� ���̽��ϴ�.\n");
				goto HOW;
			}
			else User->Card[Card_Kind] -= Card_How;
		}

		if (User->Card[Card_Kind] < Card_How) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�����Ͻ� ī�尡 �����մϴ�.\n");
			goto HOW;
		}
		else if (Pay_Card_Num > Card_How) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 �� ���ž��մϴ�.\n");
			goto HOW;
		}
		else if (Pay_Card_Num < Card_How) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 ���� ���̽��ϴ�.\n");
			goto HOW;
		}

		if (count % 3 == 0) Pay_Card_Num = Card_How;
		User->Card[Card_Kind] -= Card_How;
		count++;
	}
	else {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
		goto DECIDE;
	}

	system("cls");
}