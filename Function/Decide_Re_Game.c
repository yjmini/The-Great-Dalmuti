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

int Decide_Re_Game(struct User* User); // ���� ��� ������ ������ �Է¹޴� �Լ�

int Decide_Re_Game(struct User* User) {
	char buf[255] = { 0 };

	if (strcmp(User->Class, "��") == 0) {
	PROCEED:
		printf("������ ��� �����Ͻðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\"��� �Է��Ͻÿ�): ");
		gets_s(buf, 255);

		if (strcmp(buf, "��") == 0) {
			return 1;
		}
		else if (strcmp(buf, "�ƴϿ�") == 0) {
			return 0;
		}
		else {
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			goto PROCEED;
		}
	}

	return 0;
}