#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�г��� �ִ� 30��(��������)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1�� �г����� �Է����ּ��� : ");
	gets_s(User1->name, 30); 
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2�� �г����� �Է����ּ��� : ");
	gets_s(User2->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3�� �г����� �Է����ּ��� : ");
	gets_s(User3->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4�� �г����� �Է����ּ��� : ");
	gets_s(User4->name, 30);

Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t  �г����� Ȯ���Ͻðڽ��ϱ�? (\"��\"��� �Է��Ͻÿ�) : ");
	gets_s(input, 255);

	if (strcmp(input, "��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Check;
	}
}