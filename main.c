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

int Print_Game_Role(); 
void Get_Nickname(struct User* user);
// user1���� �г����� for���� ���� �� user1 �г����� �Է��� �ȵǼ� user1�� ���� �Է¹ް��س����ϴ�.
// switch-case�� �ۿ����� ����� �Է��� �޾����µ�, �Ƹ� �� �������� switch-case������ ���� �Է��� �ȵǴ� �� ���ƿ�. 
// user1 �г��� �Է¹��� �� gets_s �ι��� ������ ���ٸ� ���� �̰͵� �Է��� �ȵǼ� ������ ���ϱ� �Է��� �Ǵ��󱸿�.
// Ȥ�� �� ��ǻ�� �����ϼ��� �����ϱ� for�� �ȿ� �����ż� �����غ��ŵ� �����������ƿ�!
void Decide_Divide_Class(); 
void Divide_Class(struct User* user);
void share_card(int* src_deck[], int* des_deck[]);
int distribute_card(struct User* user);
void print_card(struct User* user);
// ī�� Ȯ���Ͽ����� �Է¹޴°� �߰��߾��
void King_Order_To_Slave(); 
int Revolution(struct User* user);
// ���ڿ� �񱳿��� Class_Num �񱳷� �ٲ���.
// ���� ���� ��� ��� �߰��߽��ϴ�.
void Pay_A_Tribute(struct User* User); 
// ��Ŀ�� 0������ �ϵ��� �߾��.
int Play_A_Card(struct User* User); 
int Reorganize_Class(struct User* User); 
void Print_Game_Result(struct User* user);

int preCard_Class = 13;
int Declare_Card_Class = 13;
int Pay_Card_Num = 0; 
int count = 0; 
int Rank = 0; 

int cards[] = { 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12 };

int p[4][20] = { 0 };

const char class[13][10] = { "��Ŀ", "�޹�Ƽ", "���ֱ�","������","���ۺ���","�������","���","�����","����","�丮��","��ġ��","����","�뿹" }; 

int main() {
	srand((unsigned int)time(NULL));

	struct User User[Player] = { 0 };
	int input = 0, Revolution_Return = 0;

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

		Get_Nickname(User);

		Decide_Divide_Class();
		Divide_Class(User);

		King_Order_To_Slave();
		
		distribute_card(User);
		print_card(User);

		if (Revolution(User) == -1) 
			Pay_A_Tribute(User);

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

				Play_A_Card(&User[User_Num[i]]);
				Reorganize_Class(&User[User_Num[i]]);

				if (count == 4) {
					Declare_Card_Class = 13; preCard_Class = 13; Pay_Card_Num = 0;
					count = 0;
					Play_A_Card(&User[User_Num[i]]);
					Reorganize_Class(&User[User_Num[i]]);
				}
			}
		}

		Print_Game_Result(User); 

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

void Get_Nickname(struct User* user) {
	char input[30] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�г��� �ִ� 30��(���� ����)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\tuser1�� �г����� �Է��ϼ��� : ");
	gets_s(user[0].name, 30); 
	gets_s(user[0].name, 30);
	printf("\n\n");

	for (int i = 1; i < Player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d�� �г����� �Է��ϼ��� : ", i + 1);
		gets_s(user[i].name, 30);
		printf("\n\n");
	}

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t�� �г����� �½��ϱ�?\n\n");
	for (int i = 0; i < Player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d : %s\n\n", i + 1, user[i].name);
	}


Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t�̴�� �����Ͻðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\"��� �Է��ϼ���) : ");
	gets_s(input, 30);

	if (strcmp(input, "��") == 0) {
		system("cls");
	}
	else if (strcmp(input, "�ƴϿ�") == 0) {
		system("cls");
		Get_Nickname(user);
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
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

void Divide_Class(struct User* user) {

divide:
	srand(time(NULL));
	int	num[4] = { 0 };

	int a = rand() % 80;
	int b = rand() % 80;
	int c = rand() % 80;
	int d = rand() % 80;
	int max = num[0], min = 100; //ū ���� �������� �� ���� min�� ������
	int second = 0, third = 0;

	num[0] = *(cards + a);
	num[1] = *(cards + b);
	num[2] = *(cards + c);
	num[3] = *(cards + d);

	for (int i = 0; i < Player; i++)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s��(��) ���� �� : %d\n", user[i].name, num[i]);
	}

	if ((num[0] == num[1]) || (num[0] == num[2]) || (num[0] == num[3]) || (num[1] == num[2]) || (num[1] == num[3]) || (num[2] == num[3]))
	{
		printf("\t\t\t\t\t\t\t\t\t\t\t���� ���ڰ� �־ �ٽ� �����ڽ��ϴ�.\n");
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
					strcpy(user[i].Class, "�뿹");
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
					strcpy(user[i].Class, "���");
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
					strcpy(user[i].Class, "����");
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
					strcpy(user[i].Class, "��");
					user[i].Class_Num = King;
				}
			}
		}
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t����� ������ ���� ���������ϴ�.\n");
	for (int i = 0; i < Player; i++)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ��� : %s\n", user[i].name, user[i].Class);
	}

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
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    ���� ����� �����̽��ϱ�? (\"������\"��� �Է��Ͻÿ�) : ");
	gets_s(input, 255);

	if (strcmp(input, "������") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Order;
	}
}

void share_card(int* src_deck[], int* des_deck[])
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

int distribute_card(struct User* user)
{
	srand(time(NULL));

	printf("\t\t\t\t\t\t\t\t\t\tī�� ��� ����� ������ �����ϴ�.\n\n");

	for (int i = 0; i < Player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t%s�� ī�� : ", user[i].name);
		share_card(cards, p[i]); //ī�� �̱�
		for (int j = 0; j < 20; j++) //ī�� ���
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	Sleep(3000);
	system("cls");

	printf("\n\t\t\t\t\t\t\t\t\t\t���� �� �� �ڽ��� ī�带 Ȯ���ϼ���.\n");

	return 0;
}

void print_card(struct User* user)
{	

	char input[255] = { 0 };
	for (int i = 0; i < 13; i++)
	{
		user[0].deck[i] = 0;
		user[1].deck[i] = 0;
		user[2].deck[i] = 0;
		user[3].deck[i] = 0;
	}
	for (int i = 0; i < Player; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (p[i][j] == 0)
				user[i].deck[0]++;
			else if (p[i][j] == 1)
				user[i].deck[1]++;
			else if (p[i][j] == 2)
				user[i].deck[2]++;
			else if (p[i][j] == 3)
				user[i].deck[3]++;
			else if (p[i][j] == 4)
				user[i].deck[4]++;
			else if (p[i][j] == 5)
				user[i].deck[5]++;
			else if (p[i][j] == 6)
				user[i].deck[6]++;
			else if (p[i][j] == 7)
				user[i].deck[7]++;
			else if (p[i][j] == 8)
				user[i].deck[8]++;
			else if (p[i][j] == 9)
				user[i].deck[9]++;
			else if (p[i][j] == 10)
				user[i].deck[10]++;
			else if (p[i][j] == 11)
				user[i].deck[11]++;
			else if (p[i][j] == 12)
				user[i].deck[12]++;
		}

		printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s�� ī�� ��>\n", user[i].name);
		for (int k = 0; k < 13; k++)
		{
			if (k == 0)
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t\t��Ŀ : %d��\n", user[i].deck[0]);
			}
			else
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t\t%d�� ī�� : %d��\n", k, user[i].deck[k]);
			}

		}

	CHECK:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ��\"�̶�� �Է��Ͻÿ�) : ");
		gets_s(input, 255);
		if (strcmp(input, "Ȯ��") == 0) {
			system("cls");
		}
		else {
			printf("\t\t\t\t\t\t\t\t\t\t\t�ٽ� �Է��ϼ���.\n");
			goto CHECK;
		}
	}

}

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

void Pay_A_Tribute(struct User* user) 
{	
	int a = 0, b = 0;
	int A = 0, B = 0;
	int i = 0, j = 0;

	printf("��________�뿹\n\n");
	for (i; i < Player; i++) {
		if (user[i].Class_Num == Slave) {//���� ����� ī�� ������ ������
			printf("%s�� ī��\n\n", user[i].name);
			for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
				printf("%d. %s : %d��\n", k, class[k], user[i].deck[k]);
			printf("\n");
		AERO:
			printf("�ڽ��� ī�� �� ���ڰ� ���� ���� ī�� 2���� �տ��� �ּ���.(ī�� ��ȣ�� �����ÿ�, ��Ŀ�� ����)\n");
			scanf_s("%d %d", &a, &b);

			if (((user + i)->deck[a]) == 0)
				goto AERO;
			if (((user + i)->deck[b]) == 0)
				goto AERO;
			if (a > 12 || a < 1)
				goto AERO;
			if (b > 12 || b < 1)
				goto AERO;
			break;
		}
	}
	for (j; j < Player; j++) {
		if (user[j].Class_Num == King) {//���� ���� ī�� ������ ������
			printf("\n%s�� ī��\n\n", user[j].name);
			for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
				printf("%d. %s : %d��\n", k, class[k], user[j].deck[k]);
			printf("\n");
		BERO:
			printf("�ڽ��� ī�� �� ���� ���� ī�� 2���� �뿹���� �ּ���.(ī�� ��ȣ�� �����ÿ�, ��Ŀ�� ����)\n");
			scanf_s("%d %d", &A, &B);

			if (((user + j)->deck[A]) == 0)
				goto BERO;
			if (((user + j)->deck[B]) == 0)
				goto BERO;
			if (A > 12 || A < 1)
				goto BERO;
			if (B > 12 || B < 1)
				goto BERO;
			break;
		}
	}

	((user + i)->deck[a])--; ((user + i)->deck[b])--; ((user + i)->deck[A])++; ((user + i)->deck[B])++;
	((user + j)->deck[A])--; ((user + j)->deck[B])--; ((user + j)->deck[a])++; ((user + j)->deck[b])++;

	printf("\n���� ���� ī�带 Ȯ���ϼ���.\n\n");

	printf("%s�� ī��\n\n", user[i].name);
	for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
		printf("%d. %s : %d��\n", k, class[k], user[i].deck[k]);
	printf("\n");

	printf("%s�� ī��\n\n", user[j].name);
	for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
		printf("%d. %s : %d��\n", k, class[k], user[j].deck[k]);
	printf("\n");

	int c = 0, D = 0;
	int w = 0, e = 0;
	printf("����________���\n\n");

	for (w; w < Player; w++) {
		if (user[w].Class_Num == Farmer) {//���� ����� ī�� ������ ������
			printf("%s�� ī��\n\n", user[w].name);
			for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
				printf("%d. %s : %d��\n", k, class[k], user[w].deck[k]);
			printf("\n");
		CERO:
			printf("�ڽ��� ī�� �� ���ڰ� ���� ���� ī�� 1���� �������� �ּ���.(ī�� ��ȣ�� �����ÿ�, ��Ŀ�� ����)\n");
			scanf_s("%d", &c);
			if (((user + w)->deck[c]) == 0)
				goto CERO;
			if (c > 12 || c < 1)
				goto CERO;
			break;
		}
	}

	for (e; e < Player; e++) {
		if (user[e].Class_Num == Noble) {//���� ������ ī�� ������ ������
			printf("%s�� ī��\n\n", user[e].name);
			for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
				printf("%d. %s : %d��\n", k, class[k], user[e].deck[k]);
			printf("\n");
		DERO:
			printf("�ڽ��� ī�� �� ���� ���� ī�� 1���� ��ο��� �ּ���.(ī�� ��ȣ�� �����ÿ�, ��Ŀ�� ����)\n");
			scanf_s("%d", &D);

			if (((user + e)->deck[D]) == 0)
				goto DERO;
			if (D > 12 || D < 1)
				goto DERO;
			break;
		}
	}
	((user + w)->deck[c])--; ((user + w)->deck[D])++; ((user + e)->deck[D])--; ((user + e)->deck[c])++;

	printf("���� ���� ī�带 Ȯ���ϼ���.\n\n");

	printf("%s�� ī��\n\n", user[w].name);
	for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
		printf("%d. %s : %d��\n", k + 1, class[k], user[w].deck[k]);
	printf("\n");

	printf("%s�� ī��\n\n", user[e].name);
	for (int k = 0; k < 13; k++)//�й�� ī�� ���, ex) 1.�޹�Ƽ : 1��
		printf("%d. %s : %d��\n", k + 1, class[k], user[e].deck[k]);
	printf("\n");

	Sleep(3000);
	system("cls");
}

int Play_A_Card(struct User* user) {

	if (user->Rank > 0) return 0;
	system("cls");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s�� ī�� ��\n", user->name);
	for (int i = 0; i < 13; i++) {
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d\n", i, class[i], user->deck[i]);
	}

	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 }, buf_[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t����� ī���� ��ް� ����: %d %d\n", Declare_Card_Class, Pay_Card_Num);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t���� �÷��̾ �� ī���� ��� : %d\n", preCard_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t(����� ī���� ��ް� ���� �÷��̾ �� ī���� ����� 13�� ��� ����� �� ī�尡 ������ �˴ϴ�.)");
DECIDE:
	printf("\n\t\t\t\t\t\t\t\t\t\t\tī�带 ���ðڽ��ϱ�? (��Ŀ�� ������ 12�� ������ ī�带 �� �� �ֽ��ϴ�. \"����\" Ȥ�� \"�н�\" ��� �Է��Ͻÿ�) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "�н�") == 0) {
		count++;
		system("cls");
	}

	else if (strcmp(buf, "����") == 0) {
	PAY:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t� ī�带 ���ðڽ��ϱ�? : ");
		scanf_s("%d", &Card_Kind);

		if (Card_Kind > 12) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�\n");
			goto PAY;
		}
		else if (user->deck[Card_Kind] == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� ������ ���� �ʽ��ϴ�.\n");
			goto PAY;
		}
		else if (Declare_Card_Class <= Card_Kind || preCard_Class <= Card_Kind) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t�Է��Ͻ� ī��� �� �� �����ϴ�.\n");
			goto PAY;
		}

		if (count % 3 == 0) {
			Declare_Card_Class = Card_Kind;
			preCard_Class = Card_Kind;
		}
		else preCard_Class = Card_Kind;

		if (user->deck[0] > 0) {
		JOKER:
			printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 ���ðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\" ��� �Է��Ͻÿ�) : ");
			gets_s(buf_, 255);

			if (strcmp(buf_, "��") == 0) {
			HOW_JOKER:
				printf("\n\t\t\t\t\t\t\t\t\t\t\t� ���븦 �� �� ���ðڽ��ϱ�? : ");
				scanf_s("%d", &Joker);

				if (Joker > user->deck[0]) {
					printf("\n\t\t\t\t\t\t\t\t\t\t\t�ʹ� ���� ���̽��ϴ�.\n");
					goto HOW_JOKER;
				}

				else {
					user->deck[0] -= Joker;
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
			else user->deck[Card_Kind] -= Card_How;
		}

		else {
			if (user->deck[Card_Kind] < Card_How) {
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
			else user->deck[Card_Kind] -= Card_How;
		}

		if (count % 3 == 0) Pay_Card_Num = Card_How;
		count++;
	}
	else {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
		goto DECIDE;
	}

	system("cls");
	return 0;
}

int Reorganize_Class(struct User* user) {

	if (user->Rank > 0) return 0;

	int Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (user->deck[i] == 0) {
			Count += 1;
		}
	}

	if (Count == 13) {
		// ����� ���� ��� �ο�
		switch (Rank) {
		case 0:
			strcpy(user->Class, "��");
			user->Rank = Rank;
			break;
		case 1:
			strcpy(user->Class, "����");
			user->Rank = Rank;
			break;
		case 2:
			strcpy(user->Class, "���");
			user->Rank = Rank;
			break;
		case 3:
			strcpy(user->Class, "�뿹");
			user->Rank = Rank;
			break;
		}

		Rank++;
	}

	return 0;
}

void Print_Game_Result(struct User* user) {

	printf("\n\t\t\t\t\t\t\t\t\t\t\t������ ����� ������ �����ϴ�!\n");
	for (int i = 0; i < Player; i++)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s�� ��� : %s\n", user[i].name, user[i].Class);
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t�����ϼ̽��ϴ�!\n");

}