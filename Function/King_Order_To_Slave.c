#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void King_Order_To_Slave(); // ���� �뿹���� ���� ��Ű�� �Լ�

void King_Order_To_Slave() {
	char Order[255] = { 0 };
	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t    �뿹���� � ����� �����ڽ��ϱ�? : ");
	gets_s(Order, 255);

	system("cls");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t   ������");
	Sleep(3000);
	system("cls");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t    ���� ��� : ");
	puts(Order);

Order:
	printf("\n\t\t\t\t\t\t\t\t\t\t\t    ���� ����� �����̽��ϱ�? (\"�������ϴ�.\"��� �Է��Ͻÿ�) : ");
	gets_s(input, 255);

	if (strcmp(input, "�������ϴ�.") == 0) {
		system("cls");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto Order;
	}
}