#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Decide_Divide_Class() {
	char input[255] = { 0 };

Divide:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t����� �����ðڽ��ϱ�? (\"������\"��� �Է��Ͻÿ�) :  ");
	gets_s(input, 255);

	if (strcmp(input, "������") == 0) {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t����� �����ڽ��ϴ�.\n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Divide;
	}

}

void Divide_Class(char* User1_Class, char* User2_Class, char* User3_Class, char* User4_Class, char* User1, char* User2, char* User3, char* User4) {

	int value = 0, index = 0, empty = 0;
	

	int User_Class_Num[4] = { 0 };

	for (int i = 0; i < 4; i++) {
		do {
			User_Class_Num[i] = rand() % 12 + 1;
			value = User_Class_Num[i];
			index = find(User_Class_Num, i, value);
		} while (index != -1);
	}
	
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ���� �� : %d\n", User1, User_Class_Num[0]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ���� �� : %d\n", User2,User_Class_Num[1]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ���� �� : %d\n", User3,User_Class_Num[2]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ���� �� : %d\n", User4,User_Class_Num[3]);


	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ����� �Է��Ͻÿ� : ", User1);
	gets_s(User1_Class, 255);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ����� �Է��Ͻÿ� : ", User2);
	gets_s(User2_Class, 255);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ����� �Է��Ͻÿ� : ", User3);
	gets_s(User3_Class, 255);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ����� �Է��Ͻÿ� : ", User4);
	gets_s(User4_Class, 255);

}

int find(int a[], int size, int value) {
	int index = 0;

	for (int i = 0; i < size; i++) {
		if (a[i] == value) {
			return i;
			break;
		}
	}

	if (index == 0) {
		return -1;
	}
}



