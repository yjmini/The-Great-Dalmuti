#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Revolution(int* User_Card, char* User_Class) {

	// ����ߵ� �� � ��Ȳ�� �Ͼ���� ���, ��� ��ȭ, ���� �н� �߰��ϱ�

	char input[255] = { 0 };


	if (*(User_Card + 12) == 2) {
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ ����Ű�ڽ��ϱ�? (\"��\" Ȥ��\"�ƴϿ�\"��� �Է��Ͻÿ�): ");
		gets_s(input, 255);
		if (strcmp(input, "��") == 0) {
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ �Ͼ���ϴ�!");
			if (strcmp(*User_Class, "�뿹") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t����� ��ȭ�� ������ϴ�.");
			}
			else if (strcmp(*User_Class, "��") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ ��ġ�� �ʾƵ� �˴ϴ�!");
			}
			else if (strcmp(*User_Class, "����") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ ��ġ�� �ʾƵ� �˴ϴ�!");
			}
			else if (strcmp(*User_Class, "���") == 0) {
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ ��ġ�� �ʾƵ� �˴ϴ�!");
			}
		}
		else if (strcmp(input, "�ƴϿ�") == 0) {
			system("cls");
		}
		else {
			printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
			Revolution(*User_Card, *User_Class);
		}
	}
	else {
		system("cls");
	}

	
}