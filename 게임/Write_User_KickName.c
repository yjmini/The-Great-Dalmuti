#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Write_User_Nickname(char* User1, char* User2, char* User3, char* User4) {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�г��� �ִ� 255��(��������)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1�� �г����� �Է����ּ��� : ");
	gets_s(User1, 255);
	gets_s(User1, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2�� �г����� �Է����ּ��� : ");
	gets_s(User2, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3�� �г����� �Է����ּ��� : ");
	gets_s(User3, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4�� �г����� �Է����ּ��� : ");
	gets_s(User4, 255);


Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t  �г����� �����Ͻðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\"��� �Է��Ͻÿ�) : ");
	gets_s(input, 255);

	if (strcmp(input, "�ƴϿ�") == 0) {
		system("cls");
	}
	else if (strcmp(input, "��") == 0) {
		system("cls");
		Write_User_Nickname(&User1, &User2, &User3, &User4);
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Check;
	}

}