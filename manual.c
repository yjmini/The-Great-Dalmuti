#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define player 4
#define Joker 2

extern char Class[13][10];//카드 계급

extern int cards[];
extern int p[4][20];

struct user//종합 구조체
{
	char name[30]; //32정도?
	int deck[13]; //0-12 몇 장
	char class[10]; //계급

};

int Manual() {

	int input = 0;

	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t**********게임 방법**********\n\n");
	printf("\t\t\t\t1. 계급을 정하기 위해 카드를 한 장씩 뽑는다. 가장 작은 수를 뽑은 사람이 왕이 되고 순서대로 귀족, 평민, 노예가 된다.\n\n");
	printf("\t\t\t\t2. 계급이 편성이 되었다면 왕은 노예에게 시키고 싶은 것을 시킨다.\n\n");
	printf("\t\t\t\t3. 노예가 일을 끝냈다면 카드를 플레이어 수만큼 똑같이 분배한다.\n");
	printf("\t\t\t\t\t3-1. 이때, 조커가 2장이 있다면 혁명을 일으킬 수 있다.\n");
	printf("\t\t\t\t\t3-2. 노예가 혁명을 일으키면 계급은 역순으로 바뀐다. \n\n");
	printf("\t\t\t\t4. 카드를 다 받았다면 이제 조공을 바쳐야 한다. 조공은 다음과 같은 규칙으로 바쳐야 한다.\n");
	printf("\t\t\t\t\t4-1. 노예는 왕에게 자신의 카드 중 숫자가 가장 작은 카드 2장을 공손하게 왕에게 준다.\n");
	printf("\t\t\t\t\t4-2. 왕은 노예에게 자산의 카드 중 가장 쓸모없을 것 같은 카드 2장을 준다.\n");
	printf("\t\t\t\t\t4-3. 평민은 귀족에게 노예와 같은 방식으로 카드 1장, 귀족은 평민에게 왕과 같은 방식으로 카드 1장을 준다.\n\n");
	printf("\t\t\t\t5. 조공을 다 바쳤다면 왕이 선이 되어 시작한다. 원하는 카드를 원하는 수 만큼 낼 수 있고, 이때 전부 같은 수가 적힌 카드여야 한다.\n\n");
	printf("\t\t\t\t6. 계급 순서대로 카드를 내는데 규칙이 있다.\n");
	printf("\t\t\t\t\t6-1. 처음 시작한 플레이어가 낸 카드의 수만큼 내야 한다.\n");
	printf("\t\t\t\t\t6-2. 바로 전 플레이어가 낸 카드에 적혀있는 수보다 낮은 수의 카드만 낼 수 있다.\n\n");
	printf("\t\t\t\t7. 만약 카드를 낼 수 없거나 내고 싶지 않다면 패스를 선언한다.\n\n");
	printf("\t\t\t\t8. 위의 과정을 반복하여 카드를 맨 처음 다 없애는 사람이 새로운 왕이 되고, 그다음 사람부터 귀족, 평민, 노예가 된다.\n\n");
	printf("\t\t\t\t9. 새로운 왕은 게임을 계속 진행할 것인지 결정한다.\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1. 메인 화면\t2. 게임 종료\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t숫자를 입력하시오 : ");
	scanf_s("%d", &input);

	return input;

}