#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct user {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

extern Rank;

void Reorganize_Class(struct user* user) {

	// ������ �ִ� �� �߿��� 0���� ī���� ������ ī��Ʈ�Ͽ� ������ ����
	int Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (user->deck[i] == 0) {
			Count += 1;
		}
	}

	if (Count == 13) {
		// ����� ���� ��� �ο�
		switch (Rank) {
		case 0:
			strcpy(user->Class, "��");
			break;
		case 1:
			strcpy(user->Class, "����");
			break;
		case 2:
			strcpy(user->Class, "���");
			break;
		case 3:
			strcpy(user->Class, "�뿹");
			break;
		}

		Rank++;
	}
}