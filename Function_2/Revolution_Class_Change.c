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

	if (strcmp(User->name, "¿Õ") == 0) strcpy(User->Class, "³ë¿¹");
	else if (strcmp(User->name, "±ÍÁ·") == 0) strcpy(User->Class, "Æò¹Î");
	else if (strcmp(User->name, "Æò¹Î") == 0) strcpy(User->Class, "±ÍÁ·");
	else if (strcmp(User->name, "³ë¿¹") == 0) strcpy(User->Class, "¿Õ");

}