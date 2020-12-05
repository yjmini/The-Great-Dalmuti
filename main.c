#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 유저 구조체
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

int Print_Game_Role(); // 게임 방법 출력 함수
void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4); // 닉네임 입력 함수
void Decide_Divide_Class(); // 계급 나누기 결정 함수
void _Divide_Class(struct User* user1, struct User* user2, struct User* user3, struct User* user4); // 계급 나누기 함수
void King_Order_To_Slave(); // 왕이 노예에게 일을 시키는 함수
int Revolution(struct User* User); // 혁명 함수
void Revolution_Class_Change(struct User* User); // 혁명 - 계급 바꾸기
void Pay_A_Tribute(struct User* User); // 조공 바치기 함수
void Get_A_Tribute(struct User* User); // 조공 받기 함수
void Play_A_Card(struct User* User); // 카드 내기 함수
void Reorganize_Class(struct User* User); // 계급 재편성 함수
int Decide_Re_Game(struct User* User); // 게임 계속 진행할 것인지 입력받는 함수
void Print_Card(struct User* User);
void share_card(char* src_deck[], char* des_deck[]);
void distribute_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4);
void print_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4);

int preCard_Class = 13; // 이전에 나온 카드의 계급과 비교하기 위한 변수
int Declare_Card_Class = 13; // 선언된 카드의 계급
int Pay_Card_Num = 0; // 선언한 카드의 개수를 저장할 변수
int count = 0; // 턴을 카운트하기 위한 변수
int Rank = 0; // 등수를 저장할 변수

char* ALL_card[80] = { 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12 };

int Card_Class_King = 0; // 왕이 노예에게 줄 카드 계급
int Card_Class_King_ = 0; // 왕이 노예에게 줄 카드 계급
int Card_Class_Noble = 0; // 귀족이 농민에게 줄 카드 계급
int Card_Class_Farmer = 0; // 농민이 귀족에게 줄 카드 계급
int Card_Class_Slave = 0; // 노예가 왕에게 줄 카드 계급
int Card_Class_Slave_ = 0; // 노예가 왕에게 줄 카드 계급

char* cards[] = { 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12 };

char* p1[20] = { 0 };
char* p2[20] = { 0 };
char* p3[20] = { 0 };
char* p4[20] = { 0 };

const char class[13][10] = { "조커", "달무티", "대주교","시종장","남작부인","수녀원장","기사","재봉사","석공","요리사","양치기","광부","노예" }; //카드 계급

int main() {
	srand((unsigned int)time(NULL));

	struct User User[Player] = { 0 };
	int input = 0, Revolution_Return = 0, Decide_Re_Game_Return = 0;

MAIN:
	printf("전체 화면으로 진행해주세요.\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t위대한 달무티          \n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t     인생은 불공평 합니다.       ");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t1. 게임 시작\t2. 게임 방법\t3. 게임 종료\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t     숫자를 입력하시오 : ");
	scanf_s("%d", &input);

	switch (input) {
	case 1:
		system("cls");

		Write_User_Nickname(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]); // 닉네임을 입력받는다.

		// 계급 분배를 한다.
		Decide_Divide_Class(); 
		_Divide_Class(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);

	ORDER:
		King_Order_To_Slave(); // 왕이 명령을 내린다.

		// 카드 분배 및 출력
		distribute_card(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);
		print_card(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);

		// 반복문을 돌려 조건에 맞는 유저가 있으면 혁명의 여부를 물어본다.
		for (int i = 0; i < 4; i++) Revolution_Return = Revolution(&User[i]);

		// 혁명함수의 리턴값의 조건
		// 혁명함수의 리턴값 0 : 조공 바치기 및 받기
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
		// 혁명함수의 리턴값 1 : 조공 패스 및 계급 뒤바뀌기
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
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t     게임을 종료하겠습니다.");
		break;
	}

	return 0;
}

int Print_Game_Role() {

	int input = 0;

	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t**********게임 방법**********\n\n");
	printf("\t\t\t\t1. 계급을 정하기 위해 카드를 한 장씩 뽑는다. 가장 작은 수를 뽑은 사람이 왕이 되고 순서대로 귀족, 평민, 노예가 된다.\n\n");
	printf("\t\t\t\t2. 계급이 편성이 되었다면 왕은 노예에게 시키고 싶은 것을 시킨다.\n\n");
	printf("\t\t\t\t3. 노예가 일이 끝났다면 카드를 플레이어 수만큼 똑같이 분배한다.\n");
	printf("\t\t\t\t\t3-1. 이때, 조커가 2장이 있다면 혁명을 일으킬 수 있다.\n");
	printf("\t\t\t\t\t3-2. 노예가 혁명을 일으키면 계급은 역순으로 바뀐다. \n");
	printf("\t\t\t\t\t3-3. 다른 신분이 혁명을 일으키면 조공을 바치지 않고 게임이 진행된다.\n\n");
	printf("\t\t\t\t4. 카드를 다 받았다면 이제 조공을 바쳐야 한다. 조공은 다음과 같은 규칙으로 바쳐야 한다.\n");
	printf("\t\t\t\t\t4-1. 노예는 왕에게 자신의 카드 중 숫자가 가장 작은 카드 2장을 공손하게 왕에게 준다.\n");
	printf("\t\t\t\t\t4-2. 왕은 노예에게 자산의 카드 중 가장 쓸모없을 것 같은 카드 2장을 준다.\n");
	printf("\t\t\t\t\t4-3. 평민은 귀족에게 노예와 같은 방식으로 카드 1장, 귀족은 평민에게 왕과 같은 방식으로 카드 1장을 준다.\n\n");
	printf("\t\t\t\t5. 조공을 다 바쳤다면 왕이 선이 되어 시작한다. 원하는 카드를 원하는 수 만큼 낼 수 있고, 이때 전부 같은 수가 적힌 카드여야 한다.\n\n");
	printf("\t\t\t\t6. 계급 순서대로 카드를 내는데 규칙이 있다.\n");
	printf("\t\t\t\t\t6-1. 처음 시작한 플레이어가 낸 카드의 수만큼 낼 수 있다.\n");
	printf("\t\t\t\t\t6-2. 바로 전 플레이어가 낸 카드에 적혀있는 수보다 낮은 수의 카드만 낼 수 있다.\n\n");
	printf("\t\t\t\t7. 만약 카드를 낼 수 없거나 내고 싶지 않다면 패스를 선언한다.\n\n");
	printf("\t\t\t\t8. 위의 과정을 반복해서 카드를 맨 처음 다 털어버리는 사람이 새로운 왕이 되고 그다음 사람부터 귀족, 평민, 노예가 된다.\n\n");
	printf("\t\t\t\t9. 새로운 왕은 게임을 계속 진행할 것인지 결정한다.\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1. 메인 화면\t2. 게임 종료\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t숫자를 입력하시오 : ");
	scanf_s("%d", &input);

	return input;
}

void Write_User_Nickname(struct User* User1, struct User* User2, struct User* User3, struct User* User4) {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t닉네임 최대 30자(공백포함)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1의 닉네임을 입력해주세요 : ");
	gets_s(User1->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2의 닉네임을 입력해주세요 : ");
	gets_s(User2->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3의 닉네임을 입력해주세요 : ");
	gets_s(User3->name, 30);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4의 닉네임을 입력해주세요 : ");
	gets_s(User4->name, 30);


Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t  닉네임을 확인하시겠습니까? (\"예\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "예") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto Check;
	}
}

void Decide_Divide_Class() {
	char input[255] = { 0 };

Divide:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t계급을 나누시겠습니까? (\"나눈다\"라고 입력하시오) :  ");
	gets_s(input, 255);

	if (strcmp(input, "나눈다") == 0) {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t계급을 나누겠습니다.\n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
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

void King_Order_To_Slave() {
	char Order[255] = { 0 };
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t    노예에게 어떤 명령을 내리겠습니까? : ");
	gets_s(Order, 255);

	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t   전달중");
	Sleep(3000);
	system("cls");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t    왕의 명령 : ");
	puts(Order);

Order:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    왕의 명령을 따르셨습니까? (\"따랐습니다.\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "따랐습니다.") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto Order;
	}
}

void share_card(char* src_deck[], char* des_deck[])
{
	for (int i = 0; i < 20; i++) //한 덱에 20장
	{
		while (1)
		{

			int random_value = rand() % 80; //랜덤으로 0~79 생성

			des_deck[i] = *(src_deck + random_value); //포인터 산술연산을 이용하여 랜덤 생성된 인덱스의 카드를 나눠줌

			if (src_deck[random_value] != '-1') //이미 뽑은 카드는 제외하도록 함
			{
				src_deck[random_value] = '-1'; //뽑은 카드는 -1으로 바꿔줌
				break;
			}
		}
	}
}

void distribute_card(struct User* user1, struct User* user2, struct User* user3, struct User* user4)
{
	srand(time(NULL));

	printf("\t\t\t\t\t\t\t\t\t\t카드 배분 결과는 다음과 같습니다.\n\n");

	printf("\t\t\t\t\t\t\t\t\t%s의 카드 : ", user1->name);
	share_card(cards, p1); //카드 뽑기
	for (int i = 0; i < 20; i++) //카드 출력
	{
		printf("%d ", p1[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s의 카드 : ", user2->name);
	share_card(cards, p2);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p2[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s의 카드 : ", user3->name);
	share_card(cards, p3);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p3[i]);
	}
	printf("\n");

	printf("\n\t\t\t\t\t\t\t\t\t%s의 카드 : ", user4->name);
	share_card(cards, p4);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p4[i]);
	}
	printf("\n");

	Sleep(3000);
	system("cls");

	printf("\n\t\t\t\t\t\t\t\t\t\t이제 한 명씩 자신의 카드를 확인하세요.\n");
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

	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s의 카드 패>\n", user1->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d장\n", i, class[i], user1->deck[i]);
	}
CHECK1:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t카드 패를 확인하셨습니까? (\"확인\"이라고 입력하시오) : ");
	gets_s(input, 255);
	if (strcmp(input, "확인") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t다시 입력하세요.\n");
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


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s의 카드 패>\n", user2->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d장\n", i, class[i], user2->deck[i]);
	}
CHECK2:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t카드 패를 확인하셨습니까? (\"확인\"이라고 입력하시오) : ");
	gets_s(input, 255);
	if (strcmp(input, "확인") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t다시 입력하세요.\n");
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


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s의 카드 패>\n", user3->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d장\n", i, class[i], user3->deck[i]);
	}
CHECK3:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t카드 패를 확인하셨습니까? (\"확인\"이라고 입력하시오) : ");
	gets_s(input, 255);
	if (strcmp(input, "확인") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t다시 입력하세요.\n");
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


	printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s의 카드 패>\n", user4->name);
	for (int i = 0; i < 13; i++)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d장\n", i, class[i], user4->deck[i]);
	}

CHECK4:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t카드 패를 확인하셨습니까? (\"확인\"이라고 입력하시오) : ");
	gets_s(input, 255);
	if (strcmp(input, "확인") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t다시 입력하세요.\n");
		goto CHECK4;
	}

}

void Print_Card(struct User* User) {

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s의 카드 패\n", User->name);
	for (int i = 0; i < 13; i++) {
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d\n", i, class[i], User->deck[i]);
	}

}

int Revolution(struct User* User) {

	char buf[255] = { 0 };

	if (strcmp(User->Class, "노예") == 0) {
		if (User->deck[0] == 2) {
			DECIDE:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s 플레이어 : 혁명을 일으키겠습니까? (\"예\" 혹은\"아니요\"라고 입력하시오): ", User->name);
			gets_s(buf, 255);

			if (strcmp(buf, "예") == 0) {
				User->deck[0] -= 2;
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t혁명이 일어났습니다!");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t계급이 뒤바뀌고 조공을 안내도 됩니다!\n");
				Sleep(3000);
				system("cls");
				return 1;
			}
			else if (strcmp(buf, "아니요") == 0) {
				system("cls");
			}
			else {
				printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
				goto DECIDE;
			}
		}
	}

	return 0;
}

void Revolution_Class_Change(struct User* User) {

	if (strcmp(User->name, "왕") == 0) strcpy(User->Class, "노예");
	else if (strcmp(User->name, "귀족") == 0) strcpy(User->Class, "평민");
	else if (strcmp(User->name, "평민") == 0) strcpy(User->Class, "귀족");
	else if (strcmp(User->name, "노예") == 0) strcpy(User->Class, "왕");

}

void Pay_A_Tribute(struct User* User) {

	int count = 0;

	if (strcmp(User->Class, "왕") == 0) {
		KING:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t노예에게 어떤 카드를 주겠습니까? : ");
		scanf_s("%d", &Card_Class_King);

		if (User->deck[Card_Class_King] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t카드가 부족합니다.\n");
			goto KING;
		}

		if (User->deck[Card_Class_King] == 1) {
			User->deck[Card_Class_King] -= 1;
		KING_:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t노예에게 어떤 카드를 주겠습니까? : ");
			scanf_s("%d", &Card_Class_King_);

			if (User->deck[Card_Class_King_] == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t카드가 부족합니다.\n");
				goto KING_;
			}
			else User->deck[Card_Class_King_] -= 1;
		}

		else User->deck[Card_Class_King] -= Give_To_Slave;
	}
	else if (strcmp(User->Class, "귀족") == 0) {
		NOBLE:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t평민에게 어떤 카드를 주겠습니까? : ");
		scanf_s("%d", &Card_Class_Noble);

		if (User->deck[Card_Class_Noble] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t카드가 부족합니다.\n");
			goto NOBLE;
		}

		User->deck[Card_Class_Noble] -= Give_To_Farmer;
	}
	else if (strcmp(User->Class, "평민") == 0) {
		FARMER:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t귀족께 어떤 카드를 주겠습니까? : ");
		scanf_s("%d", &Card_Class_Farmer);

		if (User->deck[Card_Class_Farmer] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t카드가 부족합니다.\n");
			goto FARMER;
		}
		for (int i = Card_Class_Farmer - 1; i > 0; i--) {
			if (User->deck[i] > 0) {
				count += 1;
			}
		}
		if (count > 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드보다 작은 계급이 존재합니다.\n");
			count = 0;
			goto FARMER;
		}

		User->deck[Card_Class_Farmer] -= Give_To_Noble;
	}
	else if (strcmp(User->Class, "노예") == 0) {
		SLAVE:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t왕께 어떤 카드를 주겠습니까? : ");
		scanf_s("%d", &Card_Class_Slave);

		if (User->deck[Card_Class_Slave] == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t카드가 부족합니다.\n");
			goto SLAVE;
		}
		for (int i = Card_Class_Slave - 1; i > 0; i--) {
			if (User->deck[i] > 0) {
				count += 1;
			}
		}
		if (count > 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드보다 작은 계급이 존재합니다.\n");
			count = 0;
			goto SLAVE;
		}

		if (User->deck[Card_Class_Slave] == 1) {
			User->deck[Card_Class_Slave] -= 1;
		SLAVE_:
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t왕께 어떤 카드를 주겠습니까? : ");
			scanf_s("%d", &Card_Class_Slave_);

			if (User->deck[Card_Class_Slave_] == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t카드가 부족합니다.\n");
				goto SLAVE_;
			}
			for (int i = Card_Class_Slave_ - 1; i > 0; i--) {
				if (User->deck[i] > 0) {
					count += 1;
				}
			}
			if (count > 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드보다 작은 계급이 존재합니다.\n");
				count = 0;
				goto SLAVE_;
			}

			else User->deck[Card_Class_Slave_] -= 1;
		}

		else User->deck[Card_Class_Slave] -= Give_To_King;
	}

}

void Get_A_Tribute(struct User* User) {

	if (strcmp(User->Class, "왕") == 0) {
		if (Card_Class_Slave_ > 0) {
			User->deck[Card_Class_Slave] += 1;
			User->deck[Card_Class_Slave_] += 1;
		}
		else User->deck[Card_Class_Slave] += Give_To_King;
	}

	else if (strcmp(User->Class, "귀족") == 0) User->deck[Card_Class_Farmer] += Give_To_Noble;
	else if (strcmp(User->Class, "평민") == 0) User->deck[Card_Class_Noble] += Give_To_Farmer;

	else if (strcmp(User->Class, "노예") == 0) {
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

	printf("\n\t\t\t\t\t\t\t\t\t\t\t선언된 카드의 계급과 개수: %d %d\n", Declare_Card_Class, Pay_Card_Num);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t이전 플레이어가 낸 카드의 계급 : %d\n", preCard_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t(선언된 카드의 계급과 이전 플레이어가 낸 카드의 계급이 13일 경우 당신이 낸 카드가 기준이 됩니다.)");
DECIDE:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 내시겠습니까? (\"낸다\" 혹은 \"패스\" 라고 입력하시오) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "패스") == 0) {
		count++;
		system("cls");
	}

	else if (strcmp(buf, "낸다") == 0) {
	PAY:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t어떤 카드를 내시겠습니까? : ");
		scanf_s("%d", &Card_Kind);

		if (Card_Kind >= 13) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다\n");
			goto PAY;
		}
		else if (User->deck[Card_Kind] == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드는 가지고 있지 않습니다.\n");
			goto PAY;
		}
		else if (Declare_Card_Class <= Card_Kind && preCard_Class <= Card_Kind) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드는 낼 수 없습니다.\n");
			goto PAY;
		}

		if (count % 3 == 0) {
			Declare_Card_Class = Card_Kind;
			preCard_Class = Card_Kind;
		}
		else preCard_Class = Card_Kind;

		if (User->deck[0] > 0) {
		JOKER:
			printf("\n\t\t\t\t\t\t\t\t\t\t\t어릿 광대를 내시겠습니까? (\"예\" 혹은 \"아니요\" 라고 입력하시오) : ");
			gets_s(buf_, 255);

			if (strcmp(buf_, "예") == 0) {
			HOW_JOKER:
				printf("\n\t\t\t\t\t\t\t\t\t\t\t어릿 광대를 몇 장 내시겠습니까? : ");
				scanf_s("%d", &Joker);

				if (Joker > User->deck[0]) {
					printf("\n\t\t\t\t\t\t\t\t\t\t\t너무 많이 내셨습니다.\n");
					goto HOW_JOKER;
				}

				else {
					User->deck[0] -= Joker;
					goto HOW_CARD;
				}
			}
			else if (strcmp(buf_, "아니요") == 0) goto HOW_CARD;
			else {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
				goto JOKER;
			}
		}

	HOW_CARD:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s를 몇 장 내시겠습니까? : ", class[Card_Kind]);
		scanf_s("%d", &Card_How);

		if (Joker > 0) {
			if (Pay_Card_Num > Card_How + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 더 내셔야합니다.\n");
				goto HOW_CARD;
			}
			else if (Pay_Card_Num < Card_How + Joker) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 많이 내셨습니다.\n");
				goto HOW_CARD;
			}
			else User->deck[Card_Kind] -= Card_How;
		}

		else {
			if (User->deck[Card_Kind] < Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t소유하신 카드가 부족합니다.\n");
				goto HOW_CARD;
			}
			else if (Pay_Card_Num > Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 %d장 더 내셔야합니다.\n", Pay_Card_Num - Card_How);
				goto HOW_CARD;
			}
			else if (Pay_Card_Num > 0 && Pay_Card_Num < Card_How) {
				printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 %d장 더 내셨습니다.\n", Card_How - Pay_Card_Num);
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
		printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
		goto DECIDE;
	}

	system("cls");
}

void Reorganize_Class(struct User* User) {

	// 가지고 있는 패 중에서 0개인 카드의 종류를 카운트하여 저장할 변수
	int Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (User->deck[i] == 0) {
			Count += 1;
		}
	}

	if (Count == 13) {
		// 등수에 따라 계급 부여
		switch (Rank) {
		case 0:
			strcpy(User->Class, "왕");
			break;
		case 1:
			strcpy(User->Class, "귀족");
			break;
		case 2:
			strcpy(User->Class, "평민");
			break;
		case 3:
			strcpy(User->Class, "노예");
			break;
		}

		Rank++;
	}
}

int Decide_Re_Game(struct User* User) {
	char buf[255] = { 0 };

	if (strcmp(User->Class, "왕") == 0) {
	PROCEED:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s 왕께서는 게임을 계속 진행하시겠습니까? (\"예\" 혹은 \"아니요\"라고 입력하시오): ", User->name);
		gets_s(buf, 255);

		if (strcmp(buf, "예") == 0) {
			return 1;
		}
		else if (strcmp(buf, "아니요") == 0) {
			return 0;
		}
		else {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
			goto PROCEED;
		}
	}

	return 0;
}
