#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

int Revolution(struct User* User) {

	char buf[255] = { 0 };

	if (strcmp(User->Class, "�뿹") == 0) {
		if (User->deck[0] == 2) {
		DECIDE:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s �÷��̾� : ������ ����Ű�ڽ��ϱ�? (\"��\" Ȥ��\"�ƴϿ�\"��� �Է��Ͻÿ�): ", User->name);
			gets_s(buf, 255);

			if (strcmp(buf, "��") == 0) {
				User->deck[0] -= 2;
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ �Ͼ���ϴ�!");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t����� �ڹٲ�� ������ �ȳ��� �˴ϴ�!\n");
				Sleep(3000);
				system("cls");
				return 1;
			}
			else if (strcmp(buf, "�ƴϿ�") == 0) {
				system("cls");
			}
			else {
				printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
				goto DECIDE;
			}
		}
	}

	return 0;
}