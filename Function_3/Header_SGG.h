#pragma once
void Play_A_Card(struct user* User);
int Decide_Re_Game(struct user* User);
void Reorganize_Class(struct user* User);

int preCard_Class = 13; // 이전에 나온 카드의 계급과 비교하기 위한 변수
int Declare_Card_Class = 13; // 선언된 카드의 계급
int Pay_Card_Num = 0; // 선언한 카드의 개수를 저장할 변수
int count = 0; // 턴을 카운트하기 위한 변수
int Rank = 0; // 등수를 저장할 변수