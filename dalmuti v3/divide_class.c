#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define player 4
#define Joker 2

#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

extern char Class[13][10];//카드 계급

extern int cards[];
extern int p[4][20];

struct user//종합 구조체
{
	char name[30]; //32정도?
	int deck[13]; //0-12 몇 장
	char class[10]; //계급
	int Class_Num;
};


void Decide_Divide_Class() {
	char input[255] = { 0 };

Dicide:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t계급을 나누시겠습니까? (\"나눈다\"라고 입력하세요) :  ");
	gets_s(input, 255);

	if (strcmp(input, "나눈다") == 0) {
		printf("\n\t\t\t\t\t\t\t\t\t\t계급을 나누겠습니다.\n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t다시 입력하세요.\n");
		goto Dicide;
	}

}



void Divide_Class(struct user* user) {

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

	for (int i = 0; i < player; i++)
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

	//나중에 지울 거
	//printf("%d, %d", max, min);

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

	//나중에 지울 거 
	//printf("%d, %d, %d, %d", max, second, third, min);

	for (int i = 0; i < 4; i++)
	{
		if (max == num[i])
		{
			for (int i = 0; i < player; i++)
			{
				if (max == num[i])
				{
					strcpy(user[i].class, "노예");
					user[i].Class_Num = Slave;
				}
			}
		}

		if (second == num[i])
		{
			for (int i = 0; i < player; i++)
			{
				if (second == num[i])
				{
					strcpy(user[i].class, "평민");
					user[i].Class_Num = Farmer;
				}
			}
		}

		if (third == num[i])
		{
			for (int i = 0; i < player; i++)
			{
				if (third == num[i])
				{
					strcpy(user[i].class, "귀족");
					user[i].Class_Num = Noble;
				}
			}
		}

		if (min == num[i])
		{
			for (int i = 0; i < player; i++)
			{
				if (min == num[i])
				{
					strcpy(user[i].class, "왕");
					user[i].Class_Num = King;
				}
			}
		}
	}



	printf("\n\t\t\t\t\t\t\t\t\t\t\t계급은 다음과 같이 정해졌습니다.\n");
	for (int i = 0; i < player; i++)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", user[i].name, user[i].class);
	}
}