#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void share_card(char* src_deck[], char* des_deck[])
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