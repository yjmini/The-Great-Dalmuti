#pragma once
void Play_A_Card(struct user* User);
int Decide_Re_Game(struct user* User);
void Reorganize_Class(struct user* User);

int preCard_Class = 13; // ������ ���� ī���� ��ް� ���ϱ� ���� ����
int Declare_Card_Class = 13; // ����� ī���� ���
int Pay_Card_Num = 0; // ������ ī���� ������ ������ ����
int count = 0; // ���� ī��Ʈ�ϱ� ���� ����
int Rank = 0; // ����� ������ ����