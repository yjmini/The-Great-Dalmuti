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

const char class[13][10] = { "��Ŀ", "�޹�Ƽ", "���ֱ�","������","���ۺ���","�������","���","�����","����","�丮��","��ġ��","����","���" }; //ī�� ���
void Print_Card(struct User* User); // ī�� �� ��� �Լ�

void Print_Card(struct User* User) {

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s�� ī�� ��\n", User->name);
	for (int i = 0; i < 13; i++) {
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d\n", i, class[i], User->Card[i]);
	}

}