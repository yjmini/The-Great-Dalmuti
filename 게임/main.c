#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// 유저 구조체
struct User {
	char name[255];
	char Class[5];
	int Card[13];
};

#define USER_1 0
#define USER_2 1
#define USER_3 2
#define USER_4 3

const char class[13][10] = { "조커", "달무티", "대주교","시종장","남작부인","수녀원장","기사","재봉사","석공","요리사","양치기","광부","농노" }; //카드 계급

int preCard_Class = 13; // 이전에 나온 카드의 계급과 비교하기 위한 변수
int Pay_Card_Num = 0; // 선언한 카드의 개수를 저장할 변수
int count = 0, count_ = 0; // 턴을 카운트하기 위한 변수
int Rank = 0; // 등수를 저장할 변수

int main() {
	srand(time(NULL));

	struct User User[4] = { 0 };
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
		Write_User_Nickname(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);
		Decide_Divide_Class();
		Divide_Class(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);
		King_Order_To_Slave();
		Card_Deal(&User[USER_1], &User[USER_2], &User[USER_3], &User[USER_4]);
		Print_Card(&User[USER_1]); Revolution_Return = Revolution(&User[USER_1]);
		Print_Card(&User[USER_2]); Revolution_Return = Revolution(&User[USER_2]);
		Print_Card(&User[USER_3]); Revolution_Return = Revolution(&User[USER_3]);
		Print_Card(&User[USER_4]); Revolution_Return = Revolution(&User[USER_4]);

		if (Revolution_Return == 0) Pay_A_Tribute();

		while (Rank == 4) {
			for (int i = 0; i < 4; i++) {
				Print_Card(&User[i]);
				Play_A_Card(&User[i]);
				Reorganize_Class(&User[i]);
			}
		}

		for (int i = 0; i < 4; i++) Decide_Re_Game_Return = Decide_Re_Game(&User[i]);

		if (Decide_Re_Game_Return == 1) {
			// 카드 분배부터 다시 시작
		}

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
