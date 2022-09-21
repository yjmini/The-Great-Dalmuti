#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ���� ����ü
struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

#define USER_1 0
#define USER_2 1
#define USER_3 2
#define USER_4 3
#define Player 4
#define Give_To_King 2
#define Give_To_Noble 1
#define Give_To_Farmer 1
#define Give_To_Slave 2
#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

int Print_Game_Role(); // ���� ��� ��� �Լ�
void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4); // �г��� �Է� �Լ�
void Decide_Divide_Class(); // ��� ������ ���� �Լ�
void _Divide_Class(struct User* user1, struct User* user2, struct User* user3, struct User* user4); // ��� ������ �Լ�
void King_Order_To_Slave(); // ���� �뿹���� ���� ��Ű�� �Լ�
int Revolution(struct User* User); // ���� �Լ�
void Revolution_Class_Change(struct User* User); // ���� - ��� �ٲٱ�
void Pay_A_Tribute(struct User* User); // ���� ��ġ�� �Լ�
void Get_A_Tribute(struct User* User); // ���� �ޱ� �Լ�
void Play_A_Card(struct User* User); // ī�� ���� �Լ�
void Reorganize_Class(struct User* User); // ��� ���� �Լ�
int Decide_Re_Game(struct User* User); // ���� ��� ������ ������ �Է¹޴� �Լ�
void Print_Card(struct User* User);
void share_card(char* src_deck[], char* des_deck[]);
void distribute_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4);
void print_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4);

int preCard_Class = 13; // ������ ���� ī���� ��ް� ���ϱ� ���� ����
int Declare_Card_Class = 13; // ����� ī���� ���
int Pay_Card_Num = 0; // ������ ī���� ������ ������ ����
int count = 0; // ���� ī��Ʈ�ϱ� ���� ����
int Rank = 0; // ����� ������ ����

char* ALL_card[80] = { 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12 };

int Card_Class_King = 0; // ���� �뿹���� �� ī�� ���
int Card_Class_King_ = 0; // ���� �뿹���� �� ī�� ���
int Card_Class_Noble = 0; // ������ ��ο��� �� ī�� ���
int Card_Class_Farmer = 0; // ����� �������� �� ī�� ���
int Card_Class_Slave = 0; // �뿹�� �տ��� �� ī�� ���
int Card_Class_Slave_ = 0; // �뿹�� �տ��� �� ī�� ���

char* cards[] = { 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12 };

char* p1[20] = { 0 };
char* p2[20] = { 0 };
char* p3[20] = { 0 };
char* p4[20] = { 0 };

const char class[13][10] = { "��Ŀ", "�޹�Ƽ", "���ֱ�","������","���ۺ���","�������","���","�����","����","�丮��","��ġ��","����","�뿹" }; //ī�� ���

int main() {
	srand((unsigned int)time(NULL));

	struct User User[Player] = { 0 };
	int input = 0, Revolution_Return = 0, Decide_Re_Game_Return = 0;

MAIN:
	printf("��ü ȭ������ �������ּ���.\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t������ �޹�Ƽ          \n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t     �λ��� �Ұ��� �մϴ�.       ");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t1. ���� ����\t2. ���� ���\t3. ���� ����\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t     ���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%d", &input);

	switch (input) {
	case 1:
		system("cls");

		Write_User_Nickname(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]); // �г����� �Է¹޴´�.

		// ��� �й踦 �Ѵ�.
		Decide_Divide_Class(); 
		_Divide_Class(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);

	ORDER:
		King_Order_To_Slave(); // ���� ����� ������.

		// ī�� �й� �� ���
		distribute_card(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);
		print_card(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);

		// �ݺ����� ���� ���ǿ� �´� ������ ������ ������ ���θ� �����.
		for (int i = 0; i < 4; i++) Revolution_Return = Revolution(&User[i]);

		// �����Լ��� ���ϰ��� ����
		// �����Լ��� ���ϰ� 0 : ���� ��ġ�� �� �ޱ�
		if (Revolution_Return == 0) {
			for (int i = 0; i < 4; i++) {
				Print_Card(&User[i]);
				Pay_A_Tribute(&User[i]);
				system("cls");
			}
			for (int i = 0; i < 4; i++) {
				Get_A_Tribute(&User[i]);
			}
		}
		// �����Լ��� ���ϰ� 1 : ���� �н� �� ��� �ڹٲ��
		else if (Revolution_Return == 1) {
			for (int i = 0; i < 4; i++) {
				Revolution_Class_Change(&User[i]);
			}
		}

		int User_Num[4] = { 0 };
		int _count = 0;

		for (int i = 0; i < 4; i++) {
			if (User[i].Class_Num == King) User_Num[0] = i;
			else if (User[i].Class_Num == Noble) User_Num[1] = i;
			else if (User[i].Class_Num == Farmer) User_Num[2] = i;
			else if (User[i].Class_Num == Slave) User_Num[3] = i;
		}

		while (Rank != 4) {
			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 13; j++) {
					if (User[i].deck[j] == 0) {
						_count += 1;
					}
				}
				if (_count == 13) {
					_count = 0;
					continue;
				}
				else _count = 0;

				Print_Card(&User[User_Num[i]]);
				Play_A_Card(&User[User_Num[i]]);
				Reorganize_Class(&User[User_Num[i]]);

				if (count == 4) {
					Declare_Card_Class = 13; preCard_Class = 13; Pay_Card_Num = 0;
					count = 0;
					Print_Card(&User[User_Num[i]]);
					Play_A_Card(&User[User_Num[i]]);
					Reorganize_Class(&User[User_Num[i]]);
				}
			}
		}

		for (int i = 0; i < 4; i++) Decide_Re_Game_Return = Decide_Re_Game(&User[i]);

		if (Decide_Re_Game_Return == 1) goto ORDER;

		break;
	case 2:
		system("cls");
		int _input = Print_Game_Role();
		switch (_input) {
		case 1:
			system("cls");
			goto MAIN;
			break;
		case 2:
			break;
		}
	case 3:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t     ������ �����ϰڽ��ϴ�.");
		break;
	}

	return 0;
}

int Print_Game_Role() {

	int input = 0;

	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t**********���� ���**********\n\n");
	printf("\t\t\t\t1. ����� ���ϱ� ���� ī�带 �� �徿 �̴´�. ���� ���� ���� ���� ����� ���� �ǰ� ������� ����, ���, �뿹�� �ȴ�.\n\n");
	printf("\t\t\t\t2. ����� ���� �Ǿ��ٸ� ���� �뿹���� ��Ű�� ���� ���� ��Ų��.\n\n");
	printf("\t\t\t\t3. �뿹�� ���� �����ٸ� ī�带 �÷��̾� ����ŭ �Ȱ��� �й��Ѵ�.\n");
	printf("\t\t\t\t\t3-1. �̶�, ��Ŀ�� 2���� �ִٸ� ������ ����ų �� �ִ�.\n");
	printf("\t\t\t\t\t3-2. �뿹�� ������ ����Ű�� ����� �������� �ٲ��. \n");
	printf("\t\t\t\t\t3-3. �ٸ� �ź��� ������ ����Ű�� ������ ��ġ�� �ʰ� ������ ����ȴ�.\n\n");
	printf("\t\t\t\t4. ī�带 �� �޾Ҵٸ� ���� ������ ���ľ� �Ѵ�. ������ ������ ���� ��Ģ���� ���ľ� �Ѵ�.\n");
	printf("\t\t\t\t\t4-1. �뿹�� �տ��� �ڽ��� ī�� �� ���ڰ� ���� ���� ī�� 2���� �����ϰ� �տ��� �ش�.\n");
	printf("\t\t\t\t\t4-2. ���� �뿹���� �ڻ��� ī�� �� ���� ������� �� ���� ī�� 2���� �ش�.\n");
	printf("\t\t\t\t\t4-3. ����� �������� �뿹�� ���� ������� ī�� 1��, ������ ��ο��� �հ� ���� ������� ī�� 1���� �ش�.\n\n");
	printf("\t\t\t\t5. ������ �� ���ƴٸ� ���� ���� �Ǿ� �����Ѵ�. ���ϴ� ī�带 ���ϴ� �� ��ŭ �� �� �ְ�, �̶� ���� ���� ���� ���� ī�忩�� �Ѵ�.\n\n");
	printf("\t\t\t\t6. ��� ������� ī�带 ���µ� ��Ģ�� �ִ�.\n");
	printf("\t\t\t\t\t6-1. ó�� ������ �÷��̾ �� ī���� ����ŭ �� �� �ִ�.\n");
	printf("\t\t\t\t\t6-2. �ٷ� �� �÷��̾ �� ī�忡 �����ִ� ������ ���� ���� ī�常 �� �� �ִ�.\n\n");
	printf("\t\t\t\t7. ���� ī�带 �� �� ���ų� ���� ���� �ʴٸ� �н��� �����Ѵ�.\n\n");
	printf("\t\t\t\t8. ���� ������ �ݺ��ؼ� ī�带 �� ó�� �� �о������ ����� ���ο� ���� �ǰ� �״��� ������� ����, ���, �뿹�� �ȴ�.\n\n");
	printf("\t\t\t\t9. ���ο� ���� ������ ��� ������ ������ �����Ѵ�.\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1. ���� ȭ��\t2. ���� ����\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%d", &input);

	return input;
}

void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�г��� �ִ� 30��(��������)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1�� �г����� �Է����ּ��� : ");
	gets_s(User1->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2�� �г����� �Է����ּ��� : ");
	gets_s(User2->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3�� �г����� �Է����ּ��� : ");
	gets_s(User3->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4�� �г����� �Է����ּ��� : ");
	gets_s(User4->name, 30);


Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t  �г����� Ȯ���Ͻðڽ��ϱ�? (\"��\"��� �Է��Ͻÿ�) : ");
	gets_s(input, 255);

	if (strcmp(input, "��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Check;
	}
}

void Decide_Divide_Class() {
	char input[255] = { 0 };

Divide:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t����� �����ðڽ��ϱ�? (\"������\"��� �Է��Ͻÿ�) :  ");
	gets_s(input, 255);

	if (strcmp(input, "������") == 0) {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t����� �����ڽ��ϴ�.\n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Divide;
	}

}

void _Divide_Class(struct User* user1, struct User* user2, struct User* user3, struct User* user4) {

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

void King_Order_To_Slave() {
	char Order[255] = { 0 };
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t    �뿹���� � ����� �����ڽ��ϱ�? : ");
	gets_s(Order, 255);

	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t   ������");
	Sleep(3000);
	system("cls");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t    ���� ��� : ");
	puts(Order);

Order:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    ���� ����� �����̽��ϱ�? (\"�������ϴ�.\"��� �Է��Ͻÿ�) : ");
	gets_s(input, 255);

	if (strcmp(input, "�������ϴ�.") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Order;
	}
}

void share_card(char* src_deck[], char* des_deck[])
{
	for (int i = 0; i < 20; i++) //�� ���� 20��
	{
		while (1)
		{

			int random_value = rand() % 80; //�������� 0~79 ����

			des_deck[i] = *(src_deck + random_value); //������ ��������� �̿��Ͽ� ���� ������ �ε����� ī�带 ������

			if (src_deck[random_value] != '-1') //�̹� ���� ī��� �����ϵ��� ��
			{
				src_deck[random_value] = '-1'; //���� ī��� -1���� �ٲ���
				break;
			}
		}
	}
}

void distribute_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4)
{
	srand(time(NULL));

	printf("\t\t\t\t\t\t\t\t\t\tī�� ��� ����� ������ �����ϴ�.\n\n");

	printf("\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user1->name);
	share_card(cards, p1); //ī�� �̱�
	for (int i = 0; i < 20; i++) //ī�� ���
	{
		printf("%d ", p1[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user2->name);
	share_card(cards, p2);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p2[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user3->name);
	share_card(cards, p3);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p3[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user4->name);
	share_card(cards, p4);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p4[i]);
	}
	printf("\n");

	Sleep(3000);
	system("cls");

	printf("\n\t\t\t\t\t\t\t\t\t\t���� �� �� �ڽ��� ī�带 Ȯ���ϼ���.\n");
	Sleep(3000);
	system("cls");
}

void print_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4)
{
	char input[255] = { 0 };
	for (int i = 0; i < 13; i++)
	{
		user1->deck[i] = 0;
		user2->deck[i] = 0;
		user3->deck[i] = 0;
		user4->deck[i] = 0;
	}
	for (int i = 0; i < 20; i++)
	{
		if (p1[i] == 0)
			user1->deck[0]++;
		else if (p1[i] == 1)
			user1->deck[1]++;
		else if (p1[i] == 2)
			user1->deck[2]++;
		else if (p1[i] == 3)
			user1->deck[3]++;
		else if (p1[i] == 4)
			user1->deck[4]++;
		else if (p1[i] == 5)
			user1->deck[5]++;
		else if (p1[i] == 6)
			user1->deck[6]++;
		else if (p1[i] == 7)
			user1->deck[7]++;
		else if (p1[i] == 8)
			user1->deck[8]++;
		else if (p1[i] == 9)
			user1->deck[9]++;
		else if (p1[i] == 10)
			user1->deck[10]++;
		else if (p1[i] == 11)
			user1->deck[11]++;
		else if (p1[i] == 12)
			user1->deck[12]++;
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user1->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d��\n", i, class[i], user1->deck[i]);
	}
CHECK1:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto CHECK1;
	}


	for (int i = 0; i < 20; i++)
	{
		if (p2[i] == 0)
			user2->deck[0]++;
		else if (p2[i] == 1)
			user2->deck[1]++;
		else if (p2[i] == 2)
			user2->deck[2]++;
		else if (p2[i] == 3)
			user2->deck[3]++;
		else if (p2[i] == 4)
			user2->deck[4]++;
		else if (p2[i] == 5)
			user2->deck[5]++;
		else if (p2[i] == 6)
			user2->deck[6]++;
		else if (p2[i] == 7)
			user2->deck[7]++;
		else if (p2[i] == 8)
			user2->deck[8]++;
		else if (p2[i] == 9)
			user2->deck[9]++;
		else if (p2[i] == 10)
			user2->deck[10]++;
		else if (p2[i] == 11)
			user2->deck[11]++;
		else if (p2[i] == 12)
			user2->deck[12]++;
	}


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user2->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d��\n", i, class[i], user2->deck[i]);
	}
CHECK2:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto CHECK2;
	}

	for (int i = 0; i < 20; i++)
	{
		if (p3[i] == 0)
			user3->deck[0]++;
		else if (p3[i] == 1)
			user3->deck[1]++;
		else if (p3[i] == 2)
			user3->deck[2]++;
		else if (p3[i] == 3)
			user3->deck[3]++;
		else if (p3[i] == 4)
			user3->deck[4]++;
		else if (p3[i] == 5)
			user3->deck[5]++;
		else if (p3[i] == 6)
			user3->deck[6]++;
		else if (p3[i] == 7)
			user3->deck[7]++;
		else if (p3[i] == 8)
			user3->deck[8]++;
		else if (p3[i] == 9)
			user3->deck[9]++;
		else if (p3[i] == 10)
			user3->deck[10]++;
		else if (p3[i] == 11)
			user3->deck[11]++;
		else if (p3[i] == 12)
			user3->deck[12]++;
	}


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user3->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d��\n", i, class[i], user3->deck[i]);
	}
CHECK3:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto CHECK3;
	}

	for (int i = 0; i < 20; i++)
	{
		if (p4[i] == 0)
			user4->deck[0]++;
		else if (p4[i] == 1)
			user4->deck[1]++;
		else if (p4[i] == 2)
			user4->deck[2]++;
		else if (p4[i] == 3)
			user4->deck[3]++;
		else if (p4[i] == 4)
			user4->deck[4]++;
		else if (p4[i] == 5)
			user4->deck[5]++;
		else if (p4[i] == 6)
			user4->deck[6]++;
		else if (p4[i] == 7)
			user4->deck[7]++;
		else if (p4[i] == 8)
			user4->deck[8]++;
		else if (p4[i] == 9)
			user4->deck[9]++;
		else if (p4[i] == 10)
			user4->deck[10]++;
		else if (p4[i] == 11)
			user4->deck[11]++;
		else if (p4[i] == 12)
			user4->deck[12]++;
	}


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user4->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d��\n", i, class[i], user4->deck[i]);
	}

CHECK4:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ��") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
		goto CHECK4;
	}

}

void Print_Card(struct User* User) {

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s�� ī�� ��\n", User->name);
	for (int i = 0; i < 13; i++) {
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d\n", i, class[i], User->deck[i]);
	}

}

int Revolution(struct User* User) {

	char buf[255] = { 0 };

	if (strcmp(User->Class, "�뿹") == 0) {
		if (User->deck[0] == 2) {
			DECIDE:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s �÷��̾� : ������ ����Ű�ڽ��ϱ�? (\"��\" Ȥ��\"�ƴϿ�\"��� �Է��Ͻÿ�): ", User->name);
			gets_s(buf, 255);

			if (strcmp(buf, "��") == 0) {
				User->deck[0] -= 2;
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ �Ͼ���ϴ�!");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t����� �ڹٲ�� ������ �ȳ��� �˴ϴ�!\n");
				Sleep(3000);
				system("cls");
				return 1;
			}
			else if (strcmp(buf, "�ƴϿ�") == 0) {
				system("cls");
			}
			else {
				printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
				goto DECIDE;
			}
		}
	}

	return 0;
}

void Revolution_Class_Change(struct User* User) {

	if (strcmp(User->name, "��") == 0) strcpy(User->Class, "�뿹");
	else if (strcmp(User->name, "����") == 0) strcpy(User->Class, "���");
	else if (strcmp(User->name, "���") == 0) strcpy(User->Class, "����");
	else if (strcmp(User->name, "�뿹") == 0) strcpy(User->Class, "��");

}

void Pay_A_Tribute(struct User* User) {

	int count = 0;

	if (strcmp(User->Class, "��") == 0) {
		KING:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�뿹���� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_King);

		if (User->deck[Card_Class_King] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
			goto KING;
		}

		if (User->deck[Card_Class_King] == 1) {
			User->deck[Card_Class_King] -= 1;
		KING_:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�뿹���� � ī�带 �ְڽ��ϱ�? : ");
			scanf_s("%d", &Card_Class_King_);

			if (User->deck[Card_Class_King_] == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
				goto KING_;
			}
			else User->deck[Card_Class_King_] -= 1;
		}

		else User->deck[Card_Class_King] -= Give_To_Slave;
	}
	else if (strcmp(User->Class, "����") == 0) {
		NOBLE:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t��ο��� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Noble);

		if (User->deck[Card_Class_Noble] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
			goto NOBLE;
		}

		User->deck[Card_Class_Noble] -= Give_To_Farmer;
	}
	else if (strcmp(User->Class, "���") == 0) {
		FARMER:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Farmer);

		if (User->deck[Card_Class_Farmer] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
			goto FARMER;
		}
		for (int i = Card_Class_Farmer - 1; i > 0; i--) {
			if (User->deck[i] > 0) {
				count += 1;
			}
		}
		if (count > 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī�庸�� ���� ����� �����մϴ�.\n");
			count = 0;
			goto FARMER;
		}

		User->deck[Card_Class_Farmer] -= Give_To_Noble;
	}
	else if (strcmp(User->Class, "�뿹") == 0) {
		SLAVE:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�ղ� � ī�带 �ְڽ��ϱ�? : ");
		scanf_s("%d", &Card_Class_Slave);

		if (User->deck[Card_Class_Slave] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
			goto SLAVE;
		}
		for (int i = Card_Class_Slave - 1; i > 0; i--) {
			if (User->deck[i] > 0) {
				count += 1;
			}
		}
		if (count > 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī�庸�� ���� ����� �����մϴ�.\n");
			count = 0;
			goto SLAVE;
		}

		if (User->deck[Card_Class_Slave] == 1) {
			User->deck[Card_Class_Slave] -= 1;
		SLAVE_:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�ղ� � ī�带 �ְڽ��ϱ�? : ");
			scanf_s("%d", &Card_Class_Slave_);

			if (User->deck[Card_Class_Slave_] == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�尡 �����մϴ�.\n");
				goto SLAVE_;
			}
			for (int i = Card_Class_Slave_ - 1; i > 0; i--) {
				if (User->deck[i] > 0) {
					count += 1;
				}
			}
			if (count > 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī�庸�� ���� ����� �����մϴ�.\n");
				count = 0;
				goto SLAVE_;
			}

			else User->deck[Card_Class_Slave_] -= 1;
		}

		else User->deck[Card_Class_Slave] -= Give_To_King;
	}

}

void Get_A_Tribute(struct User* User) {

	if (strcmp(User->Class, "��") == 0) {
		if (Card_Class_Slave_ > 0) {
			User->deck[Card_Class_Slave] += 1;
			User->deck[Card_Class_Slave_] += 1;
		}
		else User->deck[Card_Class_Slave] += Give_To_King;
	}

	else if (strcmp(User->Class, "����") == 0) User->deck[Card_Class_Farmer] += Give_To_Noble;
	else if (strcmp(User->Class, "���") == 0) User->deck[Card_Class_Noble] += Give_To_Farmer;

	else if (strcmp(User->Class, "�뿹") == 0) {
		if (Card_Class_King_ > 0) {
			User->deck[Card_Class_King] += 1;
			User->deck[Card_Class_King_] += 1;
		}
		else User->deck[Card_Class_King] += Give_To_Slave;
	}

}

void Play_A_Card(struct User* User) {
	
	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 }, buf_[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t����� ī���� ��ް� ����: %d %d\n", Declare_Card_Class, Pay_Card_Num);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t���� �÷��̾ �� ī���� ��� : %d\n", preCard_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t(����� ī���� ��ް� ���� �÷��̾ �� ī���� ����� 13�� ��� ����� �� ī�尡 ������ �˴ϴ�.)");
DECIDE:
	printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 ���ðڽ��ϱ�? (\"����\" Ȥ�� \"�н�\" ��� �Է��Ͻÿ�) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "�н�") == 0) {
		count++;
		system("cls");
	}

	else if (strcmp(buf, "����") == 0) {
	PAY:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t� ī�带 ���ðڽ��ϱ�? : ");
		scanf_s("%d", &Card_Kind);

		if (Card_Kind >= 13) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�\n");
			goto PAY;
		}
		else if (User->deck[Card_Kind] == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� ������ ���� �ʽ��ϴ�.\n");
			goto PAY;
		}
		else if (Declare_Card_Class <= Card_Kind && preCard_Class <= Card_Kind) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� �� �� �����ϴ�.\n");
			goto PAY;
		}

		if (count % 3 == 0) {
			Declare_Card_Class = Card_Kind;
			preCard_Class = Card_Kind;
		}
		else preCard_Class = Card_Kind;

		if (User->deck[0] > 0) {
		JOKER:
			printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 ���ðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\" ��� �Է��Ͻÿ�) : ");
			gets_s(buf_, 255);

			if (strcmp(buf_, "��") == 0) {
			HOW_JOKER:
				printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 �� �� ���ðڽ��ϱ�? : ");
				scanf_s("%d", &Joker);

				if (Joker > User->deck[0]) {
					printf("\n\t\t\t\t\t\t\t\t\t\t\t�ʹ� ���� ���̽��ϴ�.\n");
					goto HOW_JOKER;
				}

				else {
					User->deck[0] -= Joker;
					goto HOW_CARD;
				}
			}
			else if (strcmp(buf_, "�ƴϿ�") == 0) goto HOW_CARD;
			else {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
				goto JOKER;
			}
		}

	HOW_CARD:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� �� �� ���ðڽ��ϱ�? : ", class[Card_Kind]);
		scanf_s("%d", &Card_How);

		if (Joker > 0) {
			if (Pay_Card_Num > Card_How + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 �� ���ž��մϴ�.\n");
				goto HOW_CARD;
			}
			else if (Pay_Card_Num < Card_How + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 ���� ���̽��ϴ�.\n");
				goto HOW_CARD;
			}
			else User->deck[Card_Kind] -= Card_How;
		}

		else {
			if (User->deck[Card_Kind] < Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t�����Ͻ� ī�尡 �����մϴ�.\n");
				goto HOW_CARD;
			}
			else if (Pay_Card_Num > Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 %d�� �� ���ž��մϴ�.\n", Pay_Card_Num - Card_How);
				goto HOW_CARD;
			}
			else if (Pay_Card_Num > 0 && Pay_Card_Num < Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 %d�� �� ���̽��ϴ�.\n", Card_How - Pay_Card_Num);
				goto HOW_CARD;
			}
		}

		if (count % 3 == 0) {
			Pay_Card_Num = Card_How;
			User->deck[Card_Kind] -= Card_How;
		}
		else User->deck[Card_Kind] -= Card_How;
		count++;
	}
	else {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
		goto DECIDE;
	}

	system("cls");
}

void Reorganize_Class(struct User* User) {

	// ������ �ִ� �� �߿��� 0���� ī���� ������ ī��Ʈ�Ͽ� ������ ����
	int Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (User->deck[i] == 0) {
			Count += 1;
		}
	}

	if (Count == 13) {
		// ����� ���� ��� �ο�
		switch (Rank) {
		case 0:
			strcpy(User->Class, "��");
			break;
		case 1:
			strcpy(User->Class, "����");
			break;
		case 2:
			strcpy(User->Class, "���");
			break;
		case 3:
			strcpy(User->Class, "�뿹");
			break;
		}

		Rank++;
	}
}

int Decide_Re_Game(struct User* User) {
	char buf[255] = { 0 };

	if (strcmp(User->Class, "��") == 0) {
	PROCEED:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s �ղ����� ������ ��� �����Ͻðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\"��� �Է��Ͻÿ�): ", User->name);
		gets_s(buf, 255);

		if (strcmp(buf, "��") == 0) {
			return 1;
		}
		else if (strcmp(buf, "�ƴϿ�") == 0) {
			return 0;
		}
		else {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
			goto PROCEED;
		}
	}

	return 0;
}