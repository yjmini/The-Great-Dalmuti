#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

int preCard_Class = 13; // ������ ���� ī���� ��ް� ���ϱ� ���� ����
int Declare_Card_Class = 13; // ����� ī���� ���
int Pay_Card_Num = 0; // ������ ī���� ������ ������ ����
int count = 0; // ���� ī��Ʈ�ϱ� ���� ����

const char class[13][10] = { "��Ŀ", "�޹�Ƽ", "���ֱ�","������","���ۺ���","�������","���","�����","����","�丮��","��ġ��","����","�뿹" };

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

void Play_A_Card(struct User* User) {

	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 }, buf_[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t����� ī���� ��ް� ����: %d %d\n", Declare_Card_Class, Pay_Card_Num);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t���� �÷��̾ �� ī���� ��� : %d\n", preCard_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t(����� ī���� ��ް� ���� �÷��̾ �� ī���� ����� 13�� ��� ����� �� ī�尡 ������ �˴ϴ�.)");
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
		else if (User->deck[Card_Kind] == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� ������ ���� �ʽ��ϴ�.\n");
			goto PAY;
		}
		else if (Declare_Card_Class <= Card_Kind && preCard_Class <= Card_Kind) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� �� �� �����ϴ�.\n");
			goto PAY;
		}

		if (count % 3 == 0) {
			Declare_Card_Class = Card_Kind;
			preCard_Class = Card_Kind;
		}
		else preCard_Class = Card_Kind;

		if (User->deck[0] > 0) {
		JOKER:
			printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 ���ðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\" ��� �Է��Ͻÿ�) : ");
			gets_s(buf_, 255);

			if (strcmp(buf_, "��") == 0) {
			HOW_JOKER:
				printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 �� �� ���ðڽ��ϱ�? : ");
				scanf_s("%d", &Joker);

				if (Joker > User->deck[0]) {
					printf("\n\t\t\t\t\t\t\t\t\t\t\t�ʹ� ���� ���̽��ϴ�.\n");
					goto HOW_JOKER;
				}

				else {
					User->deck[0] -= Joker;
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
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� �� �� ���ðڽ��ϱ�? : ", class[Card_Kind]);
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
			else User->deck[Card_Kind] -= Card_How;
		}

		else {
			if (User->deck[Card_Kind] < Card_How) {
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
		}

		if (count % 3 == 0) {
			Pay_Card_Num = Card_How;
			User->deck[Card_Kind] -= Card_How;
		}
		else User->deck[Card_Kind] -= Card_How;
		count++;
	}
	else {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
		goto DECIDE;
	}

	system("cls");
}