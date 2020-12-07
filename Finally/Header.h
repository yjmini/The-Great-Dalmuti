#pragma once

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

char class[13][10] = { "조커", "달무티", "대주교","시종장","남작부인","수녀원장","기사","재봉사","석공","요리사","양치기","광부","농노" }; 

int preCard_Class = 13;
int Declare_Card_Class = 13;
int Pay_Card_Num = 0;
int count = 0;
int Rank = 1;

int cards[] = { 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12 };

int p[4][20] = { 0 };

