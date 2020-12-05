#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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