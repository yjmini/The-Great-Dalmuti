#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 11.23

// ���� ����ü
struct User {
	char name[255];
	char Class[5];
	int Card[13];
};

int Pay_Card_Error(struct User* User, int Card_Kind, int Card_How);

int preCard_Class = 13; // ������ ���� ī���� ��ް� ���ϱ� ���� ����
int Pay_Card_Num = 0; // ������ ī���� ������ ������ ����

int Pay_Card_Error(struct User* User, int Card_Kind, int Card_How) {

	if (Card_How == -1) {
		if (Card_Kind >= 13) {
			printf("�߸� �Է��ϼ̽��ϴ�\n");
			return -1;
		}

		else if (User->Card[Card_Kind] == 0) {
			printf("�Է��Ͻ� ī��� ������ ���� �ʽ��ϴ�.\n");
			return -1;
		}

		else if (preCard_Class <= Card_Kind) {
			printf("�Է��Ͻ� ī��� �� �� �����ϴ�.\n");
			return -1;
		}
	}

	else {
		if (User->Card[Card_Kind] < Card_How) {
			printf("�����Ͻ� ī�尡 �����մϴ�.\n");
			return -1;
		}

		else if (Pay_Card_Num > User->Card[Card_Kind] || Card_How == 0) {
			printf("ī�带 �� ���ž��մϴ�.\n");
			return -1;
		}

		else if (Pay_Card_Num < User->Card[Card_Kind]) {
			printf("ī�带 �ʹ� ���� ���̽��ϴ�.\n");
			return -1;
		}
	}

	return 0;
}