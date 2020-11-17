#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define player 4

void manual(void);//게임방법
void name(void);//닉네임
void rank(struct card* _nick_name);//계급(왕, 상인, 소작농, 농노) 편성
void allot(struct card* _nick_name);//카드 배분

char class[13][10] = { "달무티", "대주교","시종장","남작부인","수녀원장","기사","재봉사","석공","요리사","양치기","광부","농노","조커" };//카드 계급
typedef enum number_cards { Dal, Arch, Si, Mis, Sister, Knight, Seam, Gong, Cook, Shep, Miner, Nong, Joker };
int total_cards = Dal + Arch + Si + Mis + Sister + Knight + Seam + Gong + Cook + Shep + Miner + Nong + Joker;

struct  card
{
	char Names[10]; //이름 , nick_name[4]
	int Cards;  //계급(카드 숫자),  rack_m[4]
};

int main(struct card* _nick_name) {//메인 화면, 게임 첫 창
	int n = 0;

	printf("                위대한 달무티\n\n");
	printf("             인생은 불공평 합니다.\n\n");
	printf("1.게임 시작\t2.게임 방법\t3.게임 종료\n\n");
	printf("              숫자를 입력하시오: \n\n\n");
	printf("                               전체 화면으로 진행해주세요.\n");
	scanf("%d", &n); n = 0;
	
	if (n == 2)
		manual();
	if (n == 3)
		exit(1);
	if (n == 1)
		name();

	printf("계급을 나누기 위해 카드를 뽑으시겠습니까?(1. 예, 2. 아니요): \n");
	scanf("%d\n", &n);  n = 0;

	if (n == 2)
		exit(1);
	else
		rank(_nick_name);

	char str[255] = { 0 };

	printf("왕이 노예에게 시키고 싶은 일을 입력하시오(예, 물 좀 가져와): ");
	if (gets(str) == NULL) {
		printf("입력 실패\n");
		return -1;
	}
	
	if (put(str) == EOF) {
		printf("출력 실패\n");
		return -1;
	}
	else
		printf("왕께서 %s라고 하셨습니다.\n", str);
	printf("왕께서 시킨 일을 다 행하였습니까?(1. 예, 2. 아니요) ");
	scanf("%d\n\n", &n); n = 0;

	printf("카드를 배분하시겠습니까?(1. 예, 2. 아니요) ");
	scanf("%d\n\n", &n); n = 0;

	void allot(_nick_name);

	return 0;
}

void manual() {//2.게임 방법
	int n = 0;

	printf("                               *************게임 방법************\n\n");
	printf("1.계급을 정하기 위해 카드를 한 장씩 뽑는다. 가장 작은 수를 뽑은 사람이 왕이 되고 순서대로 귀족, 평민, 노예가 된다.\n\n");
	printf("2.계급이 편성이 되었다면 왕은 노예에게 시키고 싶은 것을 시킨다.\n\n");
	printf("3.노예가 일을 끝냈다면 카드를 플레이어 수만큼 똑같이 분배한다.\n");
	printf("       3-1.이때, 조커가 2장이 있다면 혁명을 일으킬 수 있다.\n");
	printf("       3-2.노예가 혁명을 일으키면 계급은 역순으로 바뀐다.\n");
	printf("       3-3.다른 신분이 혁명을 일으키면 조공을 바치지 않고 게임이 진행된다.\n\n");
	printf("4.카드를 다 받았다면 이제 조공을 바쳐야 한다. 조공은 다음과 같은 규칙으로 바쳐야 한다.\n");
	printf("       4-1.노예는 왕에게 자신의 카드 중 숫자가 가장 작은 카드 2장을 공손하게 바쳐야 한다.\n");
	printf("       4-2.왕은 노예에게 자신의 카드 중 가장 쓸모없을 것 같은 카드 2장을 준다.\n");
	printf("       4-3.평민은 귀족에게 노예와 같은 방식으로 카드 1장, 귀족은 평민에게 왕과 같은 방식으로 카드 1장을 준다.\n\n");
	printf("5.조공을 다 받쳤다면 왕이 선이 되어 시작한다. 원하는 카드를 원하는 수 만큼 낼 수 있고, 이떄 전부 같은 수가 적힌 카드여야 한다.\n\n");
	printf("6.계급 순서대로 카드를 내는데 규칙이 있다.\n");
	printf("       6-1.맨 처음 플레이어(왕)가 낸 카드의 수만클 낼 수 있다.\n");
	printf("       6-2.바로 전 플레이어(나보다 계급이 한 단계 높은 사람)가 낸 카드에 적혀있는 수보다 낮은 수의 카드만 낼 수 있다.\n\n");
	printf("7.만약 카드를 낼 수 없거나 내고 싶지 않다면 패스를 선언한다.\n\n");
	printf("8.위의 과정을 반복해서 카드를 맨 처음 다 털어버리는 사람이 새로운 왕이 되고 그다음 사람부터 귀족, 평민, 노예가 된다.\n\n");
	printf("새로운 왕은 게임을 계속 진행할 것이지 결정한다.\n\n");
	printf("                                              1.게임 시작\t2.게임 종료\n\n");
	printf("                                              숫자를 입력하시오: ");
	scanf("%d", &n);
}

void name() {//닉네임 
	struct card nick_name[player] = { 0 };

	printf("플레이어의 닉네임을 차례대로 입력하시오(9자 이내): ");
	for (int i = 0; i < player; i++) 
		scanf("%s ", nick_name[i].Names);
	printf("지정된 플레이어의 닉네임은\n");
	for (int i = 0; i < player; i++)
		printf("%s\n ", nick_name[i].Names);
}

void rank(struct card* _nick_name) {//계급 분배(랜덤)

	struct card rank_m[player] = { 0 };

	for (int i = 0; i < player; i++)
		rank_m[i].Cards = rand() % 12 + 1;
	for (int i = 0; i < player; i++) {
		printf("%s: %d\n", _nick_name->Names, rank_m[i].Cards);
		(_nick_name++);
	}
	printf("\n계급\n\n");

	char ranking[player][10] = { "왕", "상인", "소작농", "농노" };
	int best = 0, n = 1;
	struct card temp, ch;

	for (int i = player - 1; i > 0; i--) //계급 편성(왕, 상인, 소작농, 농노)
	{
		for (int j = 0; j < i; j++)
		{
			if (rank_m[j].Cards > rank_m[j + 1].Cards)
			{
				temp = rank_m[j];
				rank_m[j] = rank_m[j + 1];
				rank_m[j + 1] = temp;
				ch = _nick_name[j];
				_nick_name[j] = _nick_name[j + 1];
				_nick_name[j + 1] = ch;
			}
		}
	}
	for (int i = 0; i < player; i++) {
		printf("%s: %s\n", _nick_name->Names, ranking[i]);
		(_nick_name++);
	}
}

void allot(struct card* _nick_name) {


	while ()
	{
		printf("%s의 카드\n\n", _nick_name->Names);
		for(int i=0; i<13; i++)
			printf("%d. %s : %d장\n", i+1, class[i], )

	}
}
