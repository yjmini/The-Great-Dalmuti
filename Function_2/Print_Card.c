#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

const char class[13][10] = { "��Ŀ", "�޹�Ƽ", "���ֱ�","������","���ۺ���","�������","���","�����","����","�丮��","��ġ��","����","�뿹" };

void Print_Card(struct User* User) {

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s�� ī�� ��\n", User->name);
	for (int i = 0; i < 13; i++) {
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d\n", i, class[i], User->deck[i]);
	}

}