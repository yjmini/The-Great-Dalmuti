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

void Decide_Divide_Class(); // ��� ������ ���� �Լ�

void Decide_Divide_Class() {
	char input[255] = { 0 };

Divide:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t����� �����ðڽ��ϱ�? (\"������\"��� �Է��Ͻÿ�) :  ");
	gets_s(input, 255);

	if (strcmp(input, "������") == 0) {
		printf("\n\t\t\t\t\t\t\t\t\t\t\t����� �����ڽ��ϴ�.\n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Divide;
	}

}