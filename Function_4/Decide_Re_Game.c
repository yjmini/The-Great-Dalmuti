#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ���� ����ü
struct user {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

int Decide_Re_Game(struct user* user) {
	char buf[255] = { 0 };

	if (strcmp(user->Class, "��") == 0) {
	PROCEED:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s �ղ����� ������ ��� �����Ͻðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\"��� �Է��Ͻÿ�): ", user->name);
		gets_s(buf, 255);

		if (strcmp(buf, "��") == 0) {
			return 1;
		}
		else if (strcmp(buf, "�ƴϿ�") == 0) {
			return 0;
		}
		else {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
			goto PROCEED;
		}
	}

	return 0;
}