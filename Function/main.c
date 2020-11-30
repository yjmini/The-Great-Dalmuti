#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// 유저 구조체
struct User {
	char name[255];
	char Class[5];
	int Card[13];
	int Total_Card;
};

#define USER_1 0
#define USER_2 1
#define USER_3 2
#define USER_4 3

#define Give_To_King 2
#define Give_To_Noble 1
#define Give_To_Farmer 1
#define Give_To_Slave 2

int preCard_Class = 13; // 이전에 나온 카드의 계급과 비교하기 위한 변수
int Declare_Card_Class = 13; // 선언된 카드의 계급
int Pay_Card_Num = 0; // 선언한 카드의 개수를 저장할 변수
int count = 0; // 턴을 카운트하기 위한 변수
int Rank = 0; // 등수를 저장할 변수

int main() {
	srand((unsigned int)time(NULL));

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
		Print_Card(&User[USER_1]); Check_Card(); Revolution_Return = Revolution(&User[USER_1]);
		Print_Card(&User[USER_2]); Check_Card(); Revolution_Return = Revolution(&User[USER_2]);
		Print_Card(&User[USER_3]); Check_Card(); Revolution_Return = Revolution(&User[USER_3]);
		Print_Card(&User[USER_4]); Check_Card(); Revolution_Return = Revolution(&User[USER_4]);

		if (Revolution_Return == 0) {
			Pay_A_Tribute(&User[USER_1]); Pay_A_Tribute(&User[USER_2]); Pay_A_Tribute(&User[USER_3]); Pay_A_Tribute(&User[USER_4]);
			Get_A_Tribute(&User[USER_1]); Get_A_Tribute(&User[USER_2]); Get_A_Tribute(&User[USER_3]); Get_A_Tribute(&User[USER_4]);
		}
		else if (Revolution_Return == 1) {
			for (int i = 0; i < 4; i++) {
				Revolution_Class_Change(&User[i]);
			}
		}

		while (Rank != 4) {

			for (int i = 0; i < 4; i++) {
				Print_Card(&User[i]);
				Play_A_Card(&User[i]);
				Reorganize_Class(&User[i]);

				if (count == 4) {
					Declare_Card_Class = 13; preCard_Class = 13; Pay_Card_Num = 0;
					count = 0;
					Print_Card(&User[i]);
					Play_A_Card(&User[i]);
					Reorganize_Class(&User[i]);
				}

			}

		}

		if (Rank == 4) Rank = 0;

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
