#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

char* ALL_card[80] = { 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12 };

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

void Divide_Class(struct User* user1, struct User* user2, struct User* user3, struct User* user4) {

divide:
	srand(time(NULL));
	int	num[4] = { 0 };

	int a = rand() % 80;
	int b = rand() % 80;
	int c = rand() % 80;
	int d = rand() % 80;
	int max = num[0], min = INT_MAX;
	int second = 0, third = 0;

	num[0] = *(ALL_card + a);
	num[1] = *(ALL_card + b);
	num[2] = *(ALL_card + c);
	num[3] = *(ALL_card + d);

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%s이(가) 뽑은 수 : %d\n", user1->name, num[0]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s이(가) 뽑은 수 : %d\n", user2->name, num[1]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s이(가) 뽑은 수 : %d\n", user3->name, num[2]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s이(가) 뽑은 수 : %d\n", user4->name, num[3]);

	if ((num[0] == num[1]) || (num[0] == num[2]) || (num[0] == num[3]) || (num[1] == num[2]) || (num[1] == num[3]) || (num[2] == num[3]))
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t같은 숫자가 있어서 다시 나누겠습니다.\n");
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
			if (max == num[0])
			{
				strcpy(user1->Class, "노예");
				user1->Class_Num = Slave;
			}
			else if (max == num[1])
			{
				strcpy(user2->Class, "노예");
				user2->Class_Num = Slave;
			}
			else if (max == num[2])
			{
				strcpy(user3->Class, "노예");
				user3->Class_Num = Slave;
			}
			else if (max == num[3])
			{
				strcpy(user4->Class, "노예");
				user4->Class_Num = Slave;
			}
		}

		if (second == num[i])
		{
			if (second == num[0])
			{
				strcpy(user1->Class, "평민");
				user1->Class_Num = Farmer;
			}
			else if (second == num[1])
			{
				strcpy(user2->Class, "평민");
				user2->Class_Num = Farmer;
			}
			else if (second == num[2])
			{
				strcpy(user3->Class, "평민");
				user3->Class_Num = Farmer;
			}
			else if (second == num[3])
			{
				strcpy(user4->Class, "평민");
				user4->Class_Num = Farmer;
			}
		}

		if (third == num[i])
		{
			if (third == num[0])
			{
				strcpy(user1->Class, "귀족");
				user1->Class_Num = Noble;
			}
			else if (third == num[1])
			{
				strcpy(user2->Class, "귀족");
				user2->Class_Num = Noble;
			}
			else if (third == num[2])
			{
				strcpy(user3->Class, "귀족");
				user3->Class_Num = Noble;
			}
			else if (third == num[3])
			{
				strcpy(user4->Class, "귀족");
				user4->Class_Num = Noble;
			}
		}

		if (min == num[i])
		{
			if (min == num[0])
			{
				strcpy(user1->Class, "왕");
				user1->Class_Num = King;
			}
			else if (min == num[1])
			{
				strcpy(user2->Class, "왕");
				user2->Class_Num = King;
			}
			else if (min == num[2])
			{
				strcpy(user3->Class, "왕");
				user3->Class_Num = King;
			}
			else if (min == num[3])
			{
				strcpy(user4->Class, "왕");
				user4->Class_Num = King;
			}
		}
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t계급은 다음과 같이 정해졌습니다.\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", user1->name, user1->Class);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", user2->name, user2->Class);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", user3->name, user3->Class);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", user4->name, user4->Class);

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