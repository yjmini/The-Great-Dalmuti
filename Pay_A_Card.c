#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 11.21 


// ���� ����ü
struct User {
	char name[255];
	char Class[5];
	int Card[13];
};

void Play_A_Card(struct User* User);

int preCard_Class = 13; // ������ ���� ī���� ��ް� ���ϱ� ���� ����
int Pay_Card_Num = 0; // ������ ī���� ������ ������ ����
int count = 0; // ���� ī��Ʈ�ϱ� ���� ����

void Play_A_Card(struct User* User) {

	// �÷��̾ �� ī���� ��ް� ����, �׸��� ��Ŀ�� ������ ������ ����
	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 };

DECIDE:
	printf("ī�带 ���ðڽ��ϱ�? (\"����\" Ȥ�� \"�н�\" ��� �Է��Ͻÿ�) : ");
	gets_s(buf, 255);

	// �Է¹��� ���ڿ��� ���� ����
	if (strcmp(buf, "�н�") == 0) {
		count++;
		return 0;
	}
	else if (strcmp(buf, "����") == 0) {
	PAY:
		printf("� ī�带 ���ðڽ��ϱ�? : ");
		scanf_s("%d", &Card_Kind);

		if (Card_Kind >= 13) {
			printf("�߸� �Է��ϼ̽��ϴ�\n");
			goto PAY;
		}

		else if (User->Card[Card_Kind] == 0) {
			printf("�Է��Ͻ� ī��� ������ ���� �ʽ��ϴ�.\n");
			goto PAY;
		}

		else if (preCard_Class <= Card_Kind) {
			printf("�Է��Ͻ� ī��� �� �� �����ϴ�.\n");
			goto PAY;
		}

		preCard_Class = Card_Kind;

		if (User->Card[0] > 0) {
		JOKER:
			printf("� ���븦 ���ðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\" ��� �Է��Ͻÿ�) ");
			gets_s(buf, 255);

			if (strcmp(buf, "��") == 0) {
			HOW_:
				printf("�� ���� ���ðڽ��ϱ�? : ");
				scanf_s("%d", &Joker);

				if (Joker < User->Card[0]) {
					printf("�����Ͻ� ī�尡 �����մϴ�.\n");
					goto HOW_;
				}
			}
			else if (strcmp(buf, "�ƴϿ�") == 0) goto HOW;
			else {
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
				goto JOKER;
			}
			User->Card[0] -= Joker;
		}

	HOW:
		printf("%d���� ���ž��մϴ�.\n", Pay_Card_Num);
		printf("(0���� ��� �ڽ��� ���� ī���� ������ ������ �˴ϴ�.)\n");
		printf("�� ���� ���ðڽ��ϱ�? : ");
		scanf_s("%d", &Card_How);

		if (count % 3 == 0) {
			Pay_Card_Num = Card_How;
			count = 0;
		}

		if (User->Card[Card_Kind] < Card_How) {
			printf("�����Ͻ� ī�尡 �����մϴ�.\n");
			goto HOW;
		}

		if (Joker > 0) {
			if (Pay_Card_Num > User->Card[Card_Kind] + Joker) {
				printf("ī�带 �� ���ž��մϴ�.\n");
				goto HOW;
			}
			else if (Pay_Card_Num < User->Card[Card_Kind] + Joker) {
				printf("ī�带 �ʹ� ���� ���̽��ϴ�.\n");
				goto HOW;
			}
			else User->Card[Card_Kind] -= Card_How;
		}

		else if (Pay_Card_Num > User->Card[Card_Kind]) {
			printf("ī�带 �� ���ž��մϴ�.\n");
			goto HOW;
		}

		User->Card[Card_Kind] -= Card_How;
		count++;
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		goto DECIDE;
	}

	return 0;
}