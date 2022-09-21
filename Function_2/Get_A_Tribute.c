#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define Give_To_King 2
#define Give_To_Noble 1
#define Give_To_Farmer 1
#define Give_To_Slave 2

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

void Get_A_Tribute(struct User* User) {

	if (strcmp(User->Class, "��") == 0) {
		if (Card_Class_Slave_ > 0) {
			User->deck[Card_Class_Slave] += 1;
			User->deck[Card_Class_Slave_] += 1;
		}
		else User->deck[Card_Class_Slave] += Give_To_King;
	}

	else if (strcmp(User->Class, "����") == 0) User->deck[Card_Class_Farmer] += Give_To_Noble;
	else if (strcmp(User->Class, "���") == 0) User->deck[Card_Class_Noble] += Give_To_Farmer;

	else if (strcmp(User->Class, "�뿹") == 0) {
		if (Card_Class_King_ > 0) {
			User->deck[Card_Class_King] += 1;
			User->deck[Card_Class_King_] += 1;
		}
		else User->deck[Card_Class_King] += Give_To_Slave;
	}

}