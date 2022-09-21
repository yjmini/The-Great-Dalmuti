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

#define Give_To_King 2
#define Give_To_Noble 1
#define Give_To_Farmer 1
#define Give_To_Slave 2

int Card_Class_King = 0; // ¿ÕÀÌ ³ë¿¹¿¡°Ô ÁÙ Ä«µå °è±Þ
int Card_Class_Noble = 0; // ±ÍÁ·ÀÌ ³ó¹Î¿¡°Ô ÁÙ Ä«µå °è±Þ
int Card_Class_Farmer = 0; // ³ó¹ÎÀÌ ±ÍÁ·¿¡°Ô ÁÙ Ä«µå °è±Þ
int Card_Class_Slave = 0; // ³ë¿¹°¡ ¿Õ¿¡°Ô ÁÙ Ä«µå °è±Þ

void Get_A_Tribute(struct User* User); // Á¶°ø ¹Þ±â ÇÔ¼ö

void Get_A_Tribute(struct User* User) {

	if (strcmp(User->Class, "¿Õ") == 0) User->Card[Card_Class_Slave] += Give_To_King;
	else if (strcmp(User->Class, "±ÍÁ·") == 0) User->Card[Card_Class_Farmer] += Give_To_Noble;
	else if (strcmp(User->Class, "³ó¹Î") == 0) User->Card[Card_Class_Noble] += Give_To_Farmer;
	else if (strcmp(User->Class, "³ë¿¹") == 0) User->Card[Card_Class_King] += Give_To_Slave;

}