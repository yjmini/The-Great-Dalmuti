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

int Rank = 0; // ����� ������ ����

void Reorganize_Class(struct User* User); // ��� ���� �Լ�

void Reorganize_Class(struct User* User) {

	// ������ �ִ� �� �߿��� 0���� ī���� ������ ī��Ʈ�Ͽ� ������ ����
	int _Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (User->Card[i] == 0) {
			_Count += 1;
		}
	}

	if (_Count == 13) {
		// ����� ���� ��� �ο�
		switch (Rank) {
		case 0:
			strcpy_s(User->Class, 5, "��");
			break;
		case 1:
			strcpy_s(User->Class, 5, "����");
			break;
		case 2:
			strcpy_s(User->Class, 5, "���");
			break;
		case 3:
			strcpy_s(User->Class, 5, "�뿹");
			break;
		}

		Rank++;
		if (Rank + 1 == 4) Rank = 0;
	}
}