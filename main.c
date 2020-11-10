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

char Class[4][4] = { "왕", "귀족", "평민", "노예" };

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

void Write_User_Nickname() {
	int input = 0;

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t닉네임 최대 255자(공백포함)\n\n\n");

	printf("\t\t\t\t\t\t\t\t\t\t\tUser1의 닉네임을 입력해주세요 : ");
	gets_s(User1, 255);
	gets_s(User1, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser2의 닉네임을 입력해주세요 : ");
	gets_s(User2, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser3의 닉네임을 입력해주세요 : ");
	gets_s(User3, 255);
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\tUser4의 닉네임을 입력해주세요 : ");
	gets_s(User4, 255);

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t  닉네임을 수정하시겠습니까? (1. 예, 2. 아니요) : ");
	scanf_s("%d", &input);

	if (input == 1) {
		system("cls");
		Write_User_Nickname();
	}
	else system("cls");

}

void Decide_Divide_Class() {
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t계급을 나누시겠습니까? (\"나눈다\"라고 입력하시오) :  ");
	gets_s(input, 255);
	gets_s(input, 255);

	if (strcmp(input, "나눈다") == 0) {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t계급을 나누겠습니다.");
		Divide_Class();
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		Divide_Class();
	}

}

void Divide_Class() {
	
	char input[255] = { 0 };
	/*
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
	*/

OK:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t   확인하셨습니까? (\"확인 완료\"라고 입력하시오) : ");
	gets_s(input, 255);

	if (strcmp(input, "확인 완료") == 0) {
		system("cls");
		King_Order_To_Slave();
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto OK;
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
		Pay_A_Tribute();
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto Order;
	}
}

void Pay_A_Tribute() {
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    조공");
}
