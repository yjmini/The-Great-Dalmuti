#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// À¯Àú ±¸Á¶Ã¼
struct User {
	char name[255];
	char Class[5];
	int Card[13];
	int Total_Card;
};

void Revolution_Class_Change(struct User* User) {

	if (strcmp(User->name, "¿Õ") == 0) strcpy_s(User->Class, 5, "³ë¿¹");
	else if (strcmp(User->name, "±ÍÁ·") == 0) strcpy_s(User->Class, 5, "³ó¹Î");
	else if (strcmp(User->name, "³ó¹Î") == 0) strcpy_s(User->Class, 5, "±ÍÁ·");
	else if (strcmp(User->name, "³ë¿¹") == 0) strcpy_s(User->Class, 5, "¿Õ");

}