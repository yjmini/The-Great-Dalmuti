#pragma once
int Manual();
void Get_Nickname(struct user* user);
void Decide_Divide_Class();
void Divide_Class(struct user* user);
void share_card(int* src_deck[], int* des_deck[]);
int distribute_card(struct user* user);
void print_card(struct user* user);

char Class[13][10] = { "달무티", "대주교","시종장","남작부인","수녀원장","기사","재봉사","석공","요리사","양치기","광부","농노", "조커" };//카드 계급

int cards[] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12,13,13 };
int p[4][20] = { 0 };