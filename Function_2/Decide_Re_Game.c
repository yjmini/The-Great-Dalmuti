#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

int Decide_Re_Game(struct User* User) {
	char buf[255] = { 0 };

	if (strcmp(User->Class, "��") == 0) {
	PROCEED:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s �ղ����� ������ ��� �����Ͻðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\"��� �Է��Ͻÿ�): ", User->name);
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