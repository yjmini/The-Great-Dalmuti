#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct User {
	char name[30];
	char Class[5];
	int deck[13];
	int Class_Num;
};

void Revolution_Class_Change(struct User* User) {

	if (strcmp(User->name, "��") == 0) strcpy(User->Class, "�뿹");
	else if (strcmp(User->name, "����") == 0) strcpy(User->Class, "���");
	else if (strcmp(User->name, "���") == 0) strcpy(User->Class, "����");
	else if (strcmp(User->name, "�뿹") == 0) strcpy(User->Class, "��");

}