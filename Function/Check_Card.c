#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


void Check_Card(); //ī�� �� Ȯ�� �Լ�

void Check_Card() {

	char buf[255] = { 0 };

OKAY:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"��\"��� �Է��Ͻÿ�) : ");
	gets_s(buf, 255);

	if (strcmp(buf, "��") == 0) system("cls");
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸� �Է��ϼ̽��ϴ�.\n");
		goto OKAY;
	}

}