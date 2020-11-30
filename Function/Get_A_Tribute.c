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

void Get_A_Tribute(struct User* User); // ���� �ޱ� �Լ�

void Get_A_Tribute(struct User* User) {

	if (strcmp(User->Class, "��") == 0) User->Card[Card_Class_Slave] += Give_To_King;
	else if (strcmp(User->Class, "����") == 0) User->Card[Card_Class_Farmer] += Give_To_Noble;
	else if (strcmp(User->Class, "���") == 0) User->Card[Card_Class_Noble] += Give_To_Farmer;
	else if (strcmp(User->Class, "�뿹") == 0) User->Card[Card_Class_King] += Give_To_Slave;

}