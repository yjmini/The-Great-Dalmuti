#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ���� ����ü
struct User {
	char name[30];
	int Class_Num;
	char Class[10];
	int deck[13];
	int Rank;
};

#define USER_1 0
#define USER_2 1
#define USER_3 2
#define USER_4 3
#define Player 4
#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

int Revolution(struct User* user) {

	int n = 0;
	for (int i = 0; i < Player; i++) {
		if (user[i].Class_Num == Slave) {
			if (user[i].deck[0] == 2) {
				printf("������ ����ų �� �ֽ��ϴ�. ������ ����Ű�ڽ��ϱ�?(1. ��, 2. �ƴϿ�): ");
				scanf_s("%d", &n);

				if (n == 2)
					return -1;

				printf("����� �ڹٲ�����ϴ�!!\n\n");
				for (int j = 0; j < Player; j++) {
					if (user[j].Class_Num == King) {
						strcpy(user[j].Class, "�뿹");
						user[j].Class_Num = Slave;
					}
					else if (user[j].Class_Num == Noble) {
						strcpy(user[j].Class, "���");
						user[j].Class_Num = Farmer;
					}
					else if (user[j].Class_Num == Farmer) {
						strcpy(user[j].Class, "����");
						user[j].Class_Num = Noble;
					}
					else {
						strcpy(user[j].Class, "��");
						user[j].Class_Num = King;
					}
				}
				printf("���\n\n");
				for (int i = 0; i < Player; i++)
				{
					printf("%s�� ��� : %s\n", user[i].name, user[i].Class);
				}
				user[i].deck[0] = 0;
				return 0;
			}
		}
	}
	return -1;
}