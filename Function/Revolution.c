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

int Revolution(struct User* User); // ���� �Լ�

int Revolution(struct User* User) {

	char buf[255] = { 0 };

	if (strcmp(User->Class, "���") == 0) {
		if (User->Card[0] == 2) {
		DECIDE:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s �÷��̾� : ������ ����Ű�ڽ��ϱ�? (\"��\" Ȥ��\"�ƴϿ�\"��� �Է��Ͻÿ�): ", User->name);
			gets_s(buf, 255);

			if (strcmp(buf, "��") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ �Ͼ���ϴ�!");
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