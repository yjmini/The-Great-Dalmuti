#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 유저 구조체
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

extern int cards[];

void Divide_Class(struct User* user) {

divide:
	srand(time(NULL));
	int	num[4] = { 0 };

	int a = rand() % 80;
	int b = rand() % 80;
	int c = rand() % 80;
	int d = rand() % 80;
	int max = num[0], min = 100; //큰 수를 기준으로 해 놔야 min이 구해짐
	int second = 0, third = 0;

	num[0] = *(cards + a);
	num[1] = *(cards + b);
	num[2] = *(cards + c);
	num[3] = *(cards + d);

	for (int i = 0; i < Player; i++)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s이(가) 뽑은 수 : %d\n", user[i].name, num[i]);
	}

	if ((num[0] == num[1]) || (num[0] == num[2]) || (num[0] == num[3]) || (num[1] == num[2]) || (num[1] == num[3]) || (num[2] == num[3]))
	{
		printf("\t\t\t\t\t\t\t\t\t\t\t같은 숫자가 있어서 다시 나누겠습니다.\n");
		Sleep(2000);
		system("cls");
		goto divide;
	}

	for (int i = 0; i < 4; i++) {
		if (max < num[i]) {
			max = num[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (min > num[i]) {
			min = num[i];
		}
	}

	if ((((max != num[0]) && (min != num[0])) && ((max != num[1]) && (min != num[1]))))
	{
		if (num[0] > num[1])
		{
			second = num[0];
			third = num[1];
		}
		else if (num[0] < num[1])
		{
			second = num[1];
			third = num[0];
		}
	}
	else if ((((max != num[0]) && (min != num[0])) && ((max != num[2]) && (min != num[2]))))
	{
		if (num[0] > num[2])
		{
			second = num[0];
			third = num[2];
		}
		else if (num[0] < num[2])
		{
			second = num[2];
			third = num[0];
		}
	}
	else if ((((max != num[0]) && (min != num[0])) && ((max != num[3]) && (min != num[3]))))
	{
		if (num[0] > num[3])
		{
			second = num[0];
			third = num[3];
		}
		else if (num[0] < num[3])
		{
			second = num[3];
			third = num[0];
		}
	}
	else if ((((max != num[1]) && (min != num[1])) && ((max != num[2]) && (min != num[2]))))
	{
		if (num[1] > num[2])
		{
			second = num[1];
			third = num[2];
		}
		else if (num[1] < num[2])
		{
			second = num[2];
			third = num[1];
		}
	}
	else if ((((max != num[1]) && (min != num[1])) && ((max != num[3]) && (min != num[3]))))
	{
		if (num[1] > num[3])
		{
			second = num[1];
			third = num[3];
		}
		else if (num[1] < num[3])
		{
			second = num[3];
			third = num[1];
		}
	}
	else if ((((max != num[2]) && (min != num[2])) && ((max != num[3]) && (min != num[3]))))
	{
		if (num[2] > num[3])
		{
			second = num[2];
			third = num[3];
		}
		else if (num[2] < num[3])
		{
			second = num[3];
			third = num[2];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (max == num[i])
		{
			for (int i = 0; i < Player; i++)
			{
				if (max == num[i])
				{
					strcpy(user[i].Class, "노예");
					user[i].Class_Num = Slave;
				}
			}
		}

		if (second == num[i])
		{
			for (int i = 0; i < Player; i++)
			{
				if (second == num[i])
				{
					strcpy(user[i].Class, "평민");
					user[i].Class_Num = Farmer;
				}
			}
		}

		if (third == num[i])
		{
			for (int i = 0; i < Player; i++)
			{
				if (third == num[i])
				{
					strcpy(user[i].Class, "귀족");
					user[i].Class_Num = Noble;
				}
			}
		}

		if (min == num[i])
		{
			for (int i = 0; i < Player; i++)
			{
				if (min == num[i])
				{
					strcpy(user[i].Class, "왕");
					user[i].Class_Num = King;
				}
			}
		}
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t계급은 다음과 같이 정해졌습니다.\n");
	for (int i = 0; i < Player; i++)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", user[i].name, user[i].Class);
	}

	char buf[255] = { 0 };

OKAY:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t계급을 확인하셨습니까? (\"예\"라고 입력하시오) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "예") == 0) system("cls");
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
		goto OKAY;
	}
}