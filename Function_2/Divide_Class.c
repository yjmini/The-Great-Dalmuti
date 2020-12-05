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

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%s��(��) ���� �� : %d\n", user1->name, num[0]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s��(��) ���� �� : %d\n", user2->name, num[1]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s��(��) ���� �� : %d\n", user3->name, num[2]);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s��(��) ���� �� : %d\n", user4->name, num[3]);

	if ((num[0] == num[1]) || (num[0] == num[2]) || (num[0] == num[3]) || (num[1] == num[2]) || (num[1] == num[3]) || (num[2] == num[3]))
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t���� ���ڰ� �־ �ٽ� �����ڽ��ϴ�.\n");
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
				strcpy(user1->Class, "�뿹");
				user1->Class_Num = Slave;
			}
			else if (max == num[1])
			{
				strcpy(user2->Class, "�뿹");
				user2->Class_Num = Slave;
			}
			else if (max == num[2])
			{
				strcpy(user3->Class, "�뿹");
				user3->Class_Num = Slave;
			}
			else if (max == num[3])
			{
				strcpy(user4->Class, "�뿹");
				user4->Class_Num = Slave;
			}
		}

		if (second == num[i])
		{
			if (second == num[0])
			{
				strcpy(user1->Class, "���");
				user1->Class_Num = Farmer;
			}
			else if (second == num[1])
			{
				strcpy(user2->Class, "���");
				user2->Class_Num = Farmer;
			}
			else if (second == num[2])
			{
				strcpy(user3->Class, "���");
				user3->Class_Num = Farmer;
			}
			else if (second == num[3])
			{
				strcpy(user4->Class, "���");
				user4->Class_Num = Farmer;
			}
		}

		if (third == num[i])
		{
			if (third == num[0])
			{
				strcpy(user1->Class, "����");
				user1->Class_Num = Noble;
			}
			else if (third == num[1])
			{
				strcpy(user2->Class, "����");
				user2->Class_Num = Noble;
			}
			else if (third == num[2])
			{
				strcpy(user3->Class, "����");
				user3->Class_Num = Noble;
			}
			else if (third == num[3])
			{
				strcpy(user4->Class, "����");
				user4->Class_Num = Noble;
			}
		}

		if (min == num[i])
		{
			if (min == num[0])
			{
				strcpy(user1->Class, "��");
				user1->Class_Num = King;
			}
			else if (min == num[1])
			{
				strcpy(user2->Class, "��");
				user2->Class_Num = King;
			}
			else if (min == num[2])
			{
				strcpy(user3->Class, "��");
				user3->Class_Num = King;
			}
			else if (min == num[3])
			{
				strcpy(user4->Class, "��");
				user4->Class_Num = King;
			}
		}
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t����� ������ ���� ���������ϴ�.\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ��� : %s\n", user1->name, user1->Class);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ��� : %s\n", user2->name, user2->Class);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ��� : %s\n", user3->name, user3->Class);

	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ��� : %s\n", user4->name, user4->Class);

	char buf[255] = { 0 };

OKAY:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t����� Ȯ���ϼ̽��ϱ�? (\"��\"��� �Է��Ͻÿ�) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "��") == 0) system("cls");
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
		goto OKAY;
	}

}