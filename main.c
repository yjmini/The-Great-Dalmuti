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

int Print_Game_Role(); 
void Get_Nickname(struct User* user);
// user1부터 닉네임을 for으로 받을 때 user1 닉네임이 입력이 안되서 user1만 따로 입력받게해놨습니다.
// switch-case문 밖에서는 제대로 입력이 받아졌는데, 아마 제 생각에는 switch-case문으로 들어갈때 입력이 안되는 거 같아요. 
// user1 닉네임 입력받을 때 gets_s 두번쓴 이유는 한줄만 쓰면 이것도 입력이 안되서 두줄을 쓰니까 입력이 되더라구요.
// 혹시 제 컴퓨터 문제일수도 있으니까 for문 안에 넣으셔서 실행해보셔도 괜찮을꺼같아요!
void Decide_Divide_Class(); 
void Divide_Class(struct User* user);
void share_card(int* src_deck[], int* des_deck[]);
int distribute_card(struct User* user);
void print_card(struct User* user);
// 카드 확인하였는지 입력받는거 추가했어요
void King_Order_To_Slave(); 
int Revolution(struct User* user);
// 문자열 비교에서 Class_Num 비교로 바꿨어요.
// 혁명 이후 계급 출력 추가했습니다.
void Pay_A_Tribute(struct User* User); 
// 조커를 0번으로 하도록 했어요.
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

const char class[13][10] = { "조커", "달무티", "대주교","시종장","남작부인","수녀원장","기사","재봉사","석공","요리사","양치기","광부","노예" }; 

int main() {
	srand((unsigned int)time(NULL));

	struct User User[Player] = { 0 };
	int input = 0, Revolution_Return = 0;

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

void Get_Nickname(struct User* user) {
	char input[30] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t닉네임 최대 30자(공백 포함)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\tuser1의 닉네임을 입력하세요 : ");
	gets_s(user[0].name, 30); 
	gets_s(user[0].name, 30);
	printf("\n\n");

	for (int i = 1; i < Player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d의 닉네임을 입력하세요 : ", i + 1);
		gets_s(user[i].name, 30);
		printf("\n\n");
	}

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t이 닉네임이 맞습니까?\n\n");
	for (int i = 0; i < Player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t\tuser%d : %s\n\n", i + 1, user[i].name);
	}


Check:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t이대로 진행하시겠습니까? (\"예\" 혹은 \"아니요\"라고 입력하세요) : ");
	gets_s(input, 30);

	if (strcmp(input, "예") == 0) {
		system("cls");
	}
	else if (strcmp(input, "아니요") == 0) {
		system("cls");
		Get_Nickname(user);
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t다시 입력하세요.\n");
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
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    왕의 명령을 따르셨습니까? (\"따랐다\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "따랐다") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto Order;
	}
}

void share_card(int* src_deck[], int* des_deck[])
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

int distribute_card(struct User* user)
{
	srand(time(NULL));

	printf("\t\t\t\t\t\t\t\t\t\t카드 배분 결과는 다음과 같습니다.\n\n");

	for (int i = 0; i < Player; i++)
	{
		printf("\t\t\t\t\t\t\t\t\t%s의 카드 : ", user[i].name);
		share_card(cards, p[i]); //카드 뽑기
		for (int j = 0; j < 20; j++) //카드 출력
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	Sleep(3000);
	system("cls");

	printf("\n\t\t\t\t\t\t\t\t\t\t이제 한 명씩 자신의 카드를 확인하세요.\n");

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

		printf("\n\t\t\t\t\t\t\t\t\t\t\t<%s의 카드 패>\n", user[i].name);
		for (int k = 0; k < 13; k++)
		{
			if (k == 0)
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t\t조커 : %d장\n", user[i].deck[0]);
			}
			else
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t\t%d번 카드 : %d장\n", k, user[i].deck[k]);
			}

		}

	CHECK:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t카드 패를 확인하셨습니까? (\"확인\"이라고 입력하시오) : ");
		gets_s(input, 255);
		if (strcmp(input, "확인") == 0) {
			system("cls");
		}
		else {
			printf("\t\t\t\t\t\t\t\t\t\t\t다시 입력하세요.\n");
			goto CHECK;
		}
	}

}

int Revolution(struct User* user) {

	int n = 0;
	for (int i = 0; i < Player; i++) {
		if (user[i].Class_Num == Slave) {
			if (user[i].deck[0] == 2) {
				printf("혁명을 일으킬 수 있습니다. 혁명을 일으키겠습니까?(1. 예, 2. 아니요): ");
				scanf_s("%d", &n);

				if (n == 2)
					return -1;

				printf("계급이 뒤바뀌었습니다!!\n\n");
				for (int j = 0; j < Player; j++) {
					if (user[j].Class_Num == King) {
						strcpy(user[j].Class, "노예");
						user[j].Class_Num = Slave;
					}
					else if (user[j].Class_Num == Noble) {
						strcpy(user[j].Class, "평민");
						user[j].Class_Num = Farmer;
					}
					else if (user[j].Class_Num == Farmer) {
						strcpy(user[j].Class, "귀족");
						user[j].Class_Num = Noble;
					}	
					else {
						strcpy(user[j].Class, "왕");
						user[j].Class_Num = King;
					}
				}
				printf("계급\n\n");
				for (int i = 0; i < Player; i++)
				{
					printf("%s의 계급 : %s\n", user[i].name, user[i].Class);
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

	printf("왕________노예\n\n");
	for (i; i < Player; i++) {
		if (user[i].Class_Num == Slave) {//현재 농노의 카드 정보를 보여줌
			printf("%s의 카드\n\n", user[i].name);
			for (int k = 0; k < 13; k++)//분배된 카드 출력, ex) 1.달무티 : 1장
				printf("%d. %s : %d장\n", k, class[k], user[i].deck[k]);
			printf("\n");
		AERO:
			printf("자신의 카드 중 숫자가 가장 낮은 카드 2장을 왕에게 주세요.(카드 번호를 적으시오, 조커는 예외)\n");
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
		if (user[j].Class_Num == King) {//현재 왕의 카드 정보를 보여줌
			printf("\n%s의 카드\n\n", user[j].name);
			for (int k = 0; k < 13; k++)//분배된 카드 출력, ex) 1.달무티 : 1장
				printf("%d. %s : %d장\n", k, class[k], user[j].deck[k]);
			printf("\n");
		BERO:
			printf("자신의 카드 중 쓸모 없는 카드 2장을 노예에게 주세요.(카드 번호를 적으시오, 조커는 예외)\n");
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

	printf("\n조공 받은 카드를 확인하세요.\n\n");

	printf("%s의 카드\n\n", user[i].name);
	for (int k = 0; k < 13; k++)//분배된 카드 출력, ex) 1.달무티 : 1장
		printf("%d. %s : %d장\n", k, class[k], user[i].deck[k]);
	printf("\n");

	printf("%s의 카드\n\n", user[j].name);
	for (int k = 0; k < 13; k++)//분배된 카드 출력, ex) 1.달무티 : 1장
		printf("%d. %s : %d장\n", k, class[k], user[j].deck[k]);
	printf("\n");

	int c = 0, D = 0;
	int w = 0, e = 0;
	printf("귀족________평민\n\n");

	for (w; w < Player; w++) {
		if (user[w].Class_Num == Farmer) {//현재 평민의 카드 정보를 보여줌
			printf("%s의 카드\n\n", user[w].name);
			for (int k = 0; k < 13; k++)//분배된 카드 출력, ex) 1.달무티 : 1장
				printf("%d. %s : %d장\n", k, class[k], user[w].deck[k]);
			printf("\n");
		CERO:
			printf("자신의 카드 중 숫자가 가장 낮은 카드 1장을 귀족에게 주세요.(카드 번호를 적으시오, 조커는 예외)\n");
			scanf_s("%d", &c);
			if (((user + w)->deck[c]) == 0)
				goto CERO;
			if (c > 12 || c < 1)
				goto CERO;
			break;
		}
	}

	for (e; e < Player; e++) {
		if (user[e].Class_Num == Noble) {//현재 귀족의 카드 정보를 보여줌
			printf("%s의 카드\n\n", user[e].name);
			for (int k = 0; k < 13; k++)//분배된 카드 출력, ex) 1.달무티 : 1장
				printf("%d. %s : %d장\n", k, class[k], user[e].deck[k]);
			printf("\n");
		DERO:
			printf("자신의 카드 중 쓸모 없는 카드 1장을 평민에게 주세요.(카드 번호를 적으시오, 조커는 예외)\n");
			scanf_s("%d", &D);

			if (((user + e)->deck[D]) == 0)
				goto DERO;
			if (D > 12 || D < 1)
				goto DERO;
			break;
		}
	}
	((user + w)->deck[c])--; ((user + w)->deck[D])++; ((user + e)->deck[D])--; ((user + e)->deck[c])++;

	printf("조공 받은 카드를 확인하세요.\n\n");

	printf("%s의 카드\n\n", user[w].name);
	for (int k = 0; k < 13; k++)//분배된 카드 출력, ex) 1.달무티 : 1장
		printf("%d. %s : %d장\n", k + 1, class[k], user[w].deck[k]);
	printf("\n");

	printf("%s의 카드\n\n", user[e].name);
	for (int k = 0; k < 13; k++)//분배된 카드 출력, ex) 1.달무티 : 1장
		printf("%d. %s : %d장\n", k + 1, class[k], user[e].deck[k]);
	printf("\n");

	Sleep(3000);
	system("cls");
}

int Play_A_Card(struct User* user) {

	if (user->Rank > 0) return 0;
	system("cls");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s의 카드 패\n", user->name);
	for (int i = 0; i < 13; i++) {
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t%d. %s : %d\n", i, class[i], user->deck[i]);
	}

	int Card_Kind = 0, Card_How = 0, Joker = 0;
	char buf[255] = { 0 }, buf_[255] = { 0 };

	printf("\n\t\t\t\t\t\t\t\t\t\t\t선언된 카드의 계급과 개수: %d %d\n", Declare_Card_Class, Pay_Card_Num);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t이전 플레이어가 낸 카드의 계급 : %d\n", preCard_Class);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t(선언된 카드의 계급과 이전 플레이어가 낸 카드의 계급이 13일 경우 당신이 낸 카드가 기준이 됩니다.)");
DECIDE:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t카드를 내시겠습니까? (조커를 제외한 12번 까지의 카드를 낼 수 있습니다. \"낸다\" 혹은 \"패스\" 라고 입력하시오) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "패스") == 0) {
		count++;
		system("cls");
	}

	else if (strcmp(buf, "낸다") == 0) {
	PAY:
		printf("\n\t\t\t\t\t\t\t\t\t\t\t어떤 카드를 내시겠습니까? : ");
		scanf_s("%d", &Card_Kind);

		if (Card_Kind > 12) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다\n");
			goto PAY;
		}
		else if (user->deck[Card_Kind] == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드는 가지고 있지 않습니다.\n");
			goto PAY;
		}
		else if (Declare_Card_Class <= Card_Kind || preCard_Class <= Card_Kind) {
			printf("\n\t\t\t\t\t\t\t\t\t\t\t입력하신 카드는 낼 수 없습니다.\n");
			goto PAY;
		}

		if (count % 3 == 0) {
			Declare_Card_Class = Card_Kind;
			preCard_Class = Card_Kind;
		}
		else preCard_Class = Card_Kind;

		if (user->deck[0] > 0) {
		JOKER:
			printf("\n\t\t\t\t\t\t\t\t\t\t\t어릿 광대를 내시겠습니까? (\"예\" 혹은 \"아니요\" 라고 입력하시오) : ");
			gets_s(buf_, 255);

			if (strcmp(buf_, "예") == 0) {
			HOW_JOKER:
				printf("\n\t\t\t\t\t\t\t\t\t\t\t어릿 광대를 몇 장 내시겠습니까? : ");
				scanf_s("%d", &Joker);

				if (Joker > user->deck[0]) {
					printf("\n\t\t\t\t\t\t\t\t\t\t\t너무 많이 내셨습니다.\n");
					goto HOW_JOKER;
				}

				else {
					user->deck[0] -= Joker;
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
			else user->deck[Card_Kind] -= Card_How;
		}

		else {
			if (user->deck[Card_Kind] < Card_How) {
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
			else user->deck[Card_Kind] -= Card_How;
		}

		if (count % 3 == 0) Pay_Card_Num = Card_How;
		count++;
	}
	else {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t잘못 입력하셨습니다.\n");
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
		// 등수에 따라 계급 부여
		switch (Rank) {
		case 0:
			strcpy(user->Class, "왕");
			user->Rank = Rank;
			break;
		case 1:
			strcpy(user->Class, "귀족");
			user->Rank = Rank;
			break;
		case 2:
			strcpy(user->Class, "평민");
			user->Rank = Rank;
			break;
		case 3:
			strcpy(user->Class, "노예");
			user->Rank = Rank;
			break;
		}

		Rank++;
	}

	return 0;
}

void Print_Game_Result(struct User* user) {

	printf("\n\t\t\t\t\t\t\t\t\t\t\t게임의 결과는 다음과 같습니다!\n");
	for (int i = 0; i < Player; i++)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t%s의 계급 : %s\n", user[i].name, user[i].Class);
	}

	printf("\n\t\t\t\t\t\t\t\t\t\t\t수고하셨습니다!\n");

}