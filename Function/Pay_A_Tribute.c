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

#define Give_To_King 2
#define Give_To_Noble 1
#define Give_To_Farmer 1
#define Give_To_Slave 2

int Card_Class_King = 0; // ���� �뿹���� �� ī�� ���
int Card_Class_Noble = 0; // ������ ��ο��� �� ī�� ���
int Card_Class_Farmer = 0; // ����� �������� �� ī�� ���
int Card_Class_Slave = 0; // �뿹�� �տ��� �� ī�� ���

void Pay_A_Tribute(struct User* User); // ���� ��ġ�� �Լ�

void Pay_A_Tribute(struct User* User) {

	int count = 0;

	if (strcmp(User->Class, "��") == 0) {
	KING:
		printf("�뿹���� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_King);

		if (User->Card[Card_Class_King] == 0) {
			printf("ī�尡 �����մϴ�.\n");
			goto KING;
		}

		User->Card[Card_Class_King] -= Give_To_Slave;
	}
	else if (strcmp(User->Class, "����") == 0) {
	NOBLE:
		printf("��ο��� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Noble);

		if (User->Card[Card_Class_Noble] == 0) {
			printf("ī�尡 �����մϴ�.\n");
			goto NOBLE;
		}

		User->Card[Card_Class_Noble] -= Give_To_Farmer;
	}
	else if (strcmp(User->Class, "���") == 0) {
	FARMER:
		printf("�������� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Farmer);

		if (User->Card[Card_Class_Farmer] == 0) {
			printf("ī�尡 �����մϴ�.\n");
			goto FARMER;
		}
		for (int i = Card_Class_Farmer; i >= 0; i--) {
			if (User->Card[i] != 0) {
				count += 1;
			}
		}
		if (count != 0) {
			printf("�Է��Ͻ� ī�庸�� ���� ����� �����մϴ�.\n");
			goto FARMER;
		}

		User->Card[Card_Class_Farmer] -= Give_To_Noble;
	}
	else if (strcmp(User->Class, "�뿹") == 0) {
	SLAVE:
		printf("�տ��� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Slave);

		if (User->Card[Card_Class_Slave] == 0) {
			printf("ī�尡 �����մϴ�.\n");
			goto SLAVE;
		}
		for (int i = Card_Class_Slave; i >= 0; i--) {
			if (User->Card[i] != 0) {
				count += 1;
			}
		}
		if (count != 0) {
			printf("�Է��Ͻ� ī�庸�� ���� ����� �����մϴ�.\n");
			goto SLAVE;
		}

		User->Card[Card_Class_Slave] -= Give_To_King;
	}

}