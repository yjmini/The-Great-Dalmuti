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

void Divide_Class(struct User* User1, struct User* User2, struct User* User3, struct User* User4); // ��� ������ �Լ�
int find(int a[], int size, int value); // ��� ���� �� ���ڰ� �ߺ����� �ʵ��� �ϴ� �Լ�

void Divide_Class(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {

	int value = 0, index = 0, empty = 0;

	int User_Class_Num[4] = { 0 };

	for (int i = 0; i < 4; i++) {
		do {
			User_Class_Num[i] = rand() % 12 + 1;
			value = User_Class_Num[i];
			index = find(User_Class_Num, i, value);
		} while (index != -1);
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ���� �� : %d\n", User1->name, User_Class_Num[0]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ���� �� : %d\n", User2->name, User_Class_Num[1]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ���� �� : %d\n", User3->name, User_Class_Num[2]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ���� �� : %d\n", User4->name, User_Class_Num[3]);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ����� �Է��Ͻÿ� : ", User1->name);
	gets_s(User1->Class, 5);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ����� �Է��Ͻÿ� : ", User2->name);
	gets_s(User2->Class, 5);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ����� �Է��Ͻÿ� : ", User3->name);
	gets_s(User3->Class, 5);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ����� �Է��Ͻÿ� : ", User4->name);
	gets_s(User4->Class, 5);

	system("cls");
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

	return 0;
}