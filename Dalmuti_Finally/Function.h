#pragma once

int Print_Game_Role();
void Get_Nickname(struct User* user);
void Decide_Divide_Class();
void Divide_Class(struct User* user);
void share_card(int* src_deck[], int* des_deck[]);
int distribute_card(struct User* user);
void print_card(struct User* user);
void King_Order_To_Slave();
int Revolution(struct User* user);
void Pay_A_Tribute(struct User* User);
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

