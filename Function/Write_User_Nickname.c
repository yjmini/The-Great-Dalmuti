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

void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4); // �г��� �Է� �Լ�

void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�г��� �ִ� 255��(��������)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1�� �г����� �Է����ּ��� : ");
	gets_s(User1->name, 255);
	gets_s(User1->name, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2�� �г����� �Է����ּ��� : ");
	gets_s(User2->name, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3�� �г����� �Է����ּ��� : ");
	gets_s(User3->name, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4�� �г����� �Է����ּ��� : ");
	gets_s(User4->name, 255);


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