#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Print_Card(int* User_Card, char* User, char* User_Class) {

	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s�� ī�� ��\n", User);
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t1. �޹�Ƽ : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t2. ���ֱ� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t3. ������ : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t4. ���ۺ��� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t5. ������� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t6. ��� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t7. ����� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t8. ���� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t9. �丮�� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t10. ��ġ�� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t11. ���� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t12. ��� : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t��Ŀ : %d", *User_Card);
	
CHECK:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tī�� �и� Ȯ���ϼ̽��ϱ�? (\"Ȯ�� �Ϸ�\"��� �Է��Ͻÿ�) : ");
	gets_s(input, 255);
	if (strcmp(input, "Ȯ�� �Ϸ�") == 0) {
		return 0;
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t�߸��Է��ϼ̽��ϴ�.");
		goto CHECK;
	}
	
	
}