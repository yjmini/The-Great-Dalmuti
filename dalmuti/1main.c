#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Header.h"
#define player 4
#define Joker 2


extern char Class[13][10];//카드 계급

extern int cards[];
extern int p[4][20];

struct user//종합 구조체
{
	char name[30]; //32정도?
	int deck[13]; //0-12 몇 장
	char class[10]; //계급

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