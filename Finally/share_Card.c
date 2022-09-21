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

extern int p[4][20];
extern int cards[];

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