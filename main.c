#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

char User1[255] = { 0 };
char User2[255] = { 0 };
char User3[255] = { 0 };
char User4[255] = { 0 };

char User1_Class[4] = { 0 };
char User2_Class[4] = { 0 };
char User3_Class[4] = { 0 };
char User4_Class[4] = { 0 };

char Class[4][4] = { "��", "����", "���", "�뿹" };

int Print_Game_Role();
void Write_User_Nickname();
void Decide_Divide_Class();
void Divide_Class();
void King_Order_To_Slave();
void Pay_A_Tribute();

int main() {
	srand(time(NULL));

	int input = 0;

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
		Write_User_Nickname();
		Decide_Divide_Class();
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

void Write_User_Nickname() {
	int input = 0;

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t�г��� �ִ� 255��(��������)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1�� �г����� �Է����ּ��� : ");
	gets_s(User1, 255);
	gets_s(User1, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2�� �г����� �Է����ּ��� : ");
	gets_s(User2, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3�� �г����� �Է����ּ��� : ");
	gets_s(User3, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4�� �г����� �Է����ּ��� : ");
	gets_s(User4, 255);

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t  �г����� �����Ͻðڽ��ϱ�? (1. ��, 2. �ƴϿ�) : ");
	scanf_s("%d", &input);

	if (input == 1) {
		system("cls");
		Write_User_Nickname();
	}
	else system("cls");

}

void Decide_Divide_Class() {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t����� �����ðڽ��ϱ�? (\"������\"��� �Է��Ͻÿ�) :  ");
	gets_s(input, 255);
	gets_s(input, 255);

	if (strcmp(input, "������") == 0) {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t����� �����ڽ��ϴ�.");
		Divide_Class();
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		Divide_Class();
	}

}

void Divide_Class() {
	
	char input[255] = { 0 };
	
	int User1_Class_Num = rand() % 4;
	for (int i = 0; i < 4; i++) User1_Class[i] = Class[User1_Class_Num][i];

	int User2_Class_Num = rand() % 4;
	while (User1_Class_Num == User2_Class_Num) User2_Class_Num = rand() % 4;
	for (int i = 0; i < 4; i++) User2_Class[i] = Class[User2_Class_Num][i];

	int User3_Class_Num = rand() % 4;
	while (User1_Class_Num == User3_Class_Num && User2_Class_Num == User3_Class_Num) User3_Class_Num = rand() % 4;
	for (int i = 0; i < 4; i++) User3_Class[i] = Class[User3_Class_Num][i];

	int User4_Class_Num = rand() % 4;
	while (User1_Class_Num == User4_Class_Num && User2_Class_Num == User4_Class_Num && User3_Class_Num == User4_Class_Num) User4_Class_Num = rand() % 4;
	for (int i = 0; i < 4; i++) User4_Class[i] = Class[User4_Class_Num][i];

	puts(User1_Class);
	printf("\n");
	puts(User2_Class);
	printf("\n");
	puts(User3_Class);
	printf("\n");
	puts(User4_Class);
	printf("\n");
	

OK:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t   Ȯ���ϼ̽��ϱ�? (\"Ȯ�� �Ϸ�\"��� �Է��Ͻÿ�) : ");
	gets_s(input, 255);

	if (strcmp(input, "Ȯ�� �Ϸ�") == 0) {
		system("cls");
		King_Order_To_Slave();
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto OK;
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
		Pay_A_Tribute();
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Order;
	}
}

void Pay_A_Tribute() {
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    ����");
}