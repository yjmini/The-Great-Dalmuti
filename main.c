#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Header.h"
#define player 4
#define Joker 2


extern char Class[13][10];//ī�� ���

extern int cards[];
extern int p[4][20];

struct user//���� ����ü
{
	char name[30]; //32����?
	int deck[13]; //0-12 �� ��
	char class[10]; //���

};



int main(void)
{
	struct user user[4] = { 0 };

	Get_Nickname(user);
	Decide_Divide_Class();
	Divide_Class(user);
	distribute_card(user);
	print_card(user);

	return 0;
}