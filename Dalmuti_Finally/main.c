#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "Function.h"

// 유저 구조체
struct User {
	char name[30];
	int Class_Num;
	char Class[10];
	int deck[13];
	int Rank;
};

#define Player 4
#define King 0
#define Noble 1
#define Farmer 2
#define Slave 3

extern int cards[];
extern int p[4][20];
extern int preCard_Class;
extern int Declare_Card_Class;
extern int Pay_Card_Num;
extern int count;
extern int Rank;

int main() {
	srand((unsigned int)time(NULL));

	struct User User[Player] = { 0 };
	int input = 0, Revolution_Return = 0;

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

		while (Rank != 5) {
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

			while (Rank != 5) {
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
			break;
		}
	case 3:
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t     게임을 종료하겠습니다.");
		break;
	}

	return 0;
}