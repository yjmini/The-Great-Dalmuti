#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ���� ����ü
struct User {
	char name[255];
	char Class[5];
	int Card[13];
	int Total_Card;
};

void Revolution_Class_Change(struct User* User) {

	if (strcmp(User->name, "��") == 0) strcpy_s(User->Class, 5, "�뿹");
	else if (strcmp(User->name, "����") == 0) strcpy_s(User->Class, 5, "���");
	else if (strcmp(User->name, "���") == 0) strcpy_s(User->Class, 5, "����");
	else if (strcmp(User->name, "�뿹") == 0) strcpy_s(User->Class, 5, "��");

}