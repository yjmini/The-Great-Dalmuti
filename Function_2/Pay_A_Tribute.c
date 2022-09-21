#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

int Card_Class_King = 0; // ���� �뿹���� �� ī�� ���
int Card_Class_King_ = 0; // ���� �뿹���� �� ī�� ���
int Card_Class_Noble = 0; // ������ ��ο��� �� ī�� ���
int Card_Class_Farmer = 0; // ����� �������� �� ī�� ���
int Card_Class_Slave = 0; // �뿹�� �տ��� �� ī�� ���
int Card_Class_Slave_ = 0; // �뿹�� �տ��� �� ī�� ���

#define Give_To_King 2
#define Give_To_Noble 1
#define Give_To_Farmer 1
#define Give_To_Slave 2

void Pay_A_Tribute(struct User* User) {

	int count = 0;

	if (strcmp(User->Class, "��") == 0) {
	KING:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�뿹���� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_King);

		if (User->deck[Card_Class_King] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
			goto KING;
		}

		if (User->deck[Card_Class_King] == 1) {
			User->deck[Card_Class_King] -= 1;
		KING_:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�뿹���� � ī�带 �ְڽ��ϱ�? : ");
			scanf_s("%d", &Card_Class_King_);

			if (User->deck[Card_Class_King_] == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
				goto KING_;
			}
			else User->deck[Card_Class_King_] -= 1;
		}

		else User->deck[Card_Class_King] -= Give_To_Slave;
	}
	else if (strcmp(User->Class, "����") == 0) {
	NOBLE:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t��ο��� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Noble);

		if (User->deck[Card_Class_Noble] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
			goto NOBLE;
		}

		User->deck[Card_Class_Noble] -= Give_To_Farmer;
	}
	else if (strcmp(User->Class, "���") == 0) {
	FARMER:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Farmer);

		if (User->deck[Card_Class_Farmer] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
			goto FARMER;
		}
		for (int i = Card_Class_Farmer - 1; i > 0; i--) {
			if (User->deck[i] > 0) {
				count += 1;
			}
		}
		if (count > 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī�庸�� ���� ����� �����մϴ�.\n");
			count = 0;
			goto FARMER;
		}

		User->deck[Card_Class_Farmer] -= Give_To_Noble;
	}
	else if (strcmp(User->Class, "�뿹") == 0) {
	SLAVE:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�ղ� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Slave);

		if (User->deck[Card_Class_Slave] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
			goto SLAVE;
		}
		for (int i = Card_Class_Slave - 1; i > 0; i--) {
			if (User->deck[i] > 0) {
				count += 1;
			}
		}
		if (count > 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī�庸�� ���� ����� �����մϴ�.\n");
			count = 0;
			goto SLAVE;
		}

		if (User->deck[Card_Class_Slave] == 1) {
			User->deck[Card_Class_Slave] -= 1;
		SLAVE_:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�ղ� � ī�带 �ְڽ��ϱ�? : ");
			scanf_s("%d", &Card_Class_Slave_);

			if (User->deck[Card_Class_Slave_] == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
				goto SLAVE_;
			}
			for (int i = Card_Class_Slave_ - 1; i > 0; i--) {
				if (User->deck[i] > 0) {
					count += 1;
				}
			}
			if (count > 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī�庸�� ���� ����� �����մϴ�.\n");
				count = 0;
				goto SLAVE_;
			}

			else User->deck[Card_Class_Slave_] -= 1;
		}

		else User->deck[Card_Class_Slave] -= Give_To_King;
	}

}