#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ���� ����ü
struct User {
	char name[255];
	char Class[5];
	int Card[13];
};

void Game_Result(struct User* User);

int Rank = 0; // ����� ������ ����

void Game_Result(struct User* User) {

	// ������ �ִ� �� �߿��� 0���� ī���� ������ ī��Ʈ�Ͽ� ������ ����
	int _Count = 0;
	char buf[255] = { 0 };

	for (int i = 0; i < 13; i++) {
		if (User->Card[i] == 0) {
			_Count += 1;
		}
	}

	if (_Count == 13) {
		printf("����� %d�� �Դϴ�.\n", Rank + 1);
	}

	// ����� ���� ��� �ο�
	switch (Rank) {
	case 0:
		strcpy_s(User->Class, 5, "��");
		printf("����� ���ο� ��� : ");
		puts(User->Class);
		break;
	case 1:
		strcpy_s(User->Class, 5, "����");
		printf("����� ���ο� ��� : ");
		puts(User->Class);
		break;
	case 2:
		strcpy_s(User->Class, 5, "���");
		printf("����� ���ο� ��� : ");
		puts(User->Class);
		break;
	case 3:
		strcpy_s(User->Class, 5, "�뿹");
		printf("����� ���ο� ��� : ");
		puts(User->Class);
		break;
	}

	Rank++;
	if (Rank + 1 == 4) Rank = 0;

	if (strcmp(User->Class, "��") == 0) {
	PROCEED:
		printf("������ ��� �����Ͻðڽ��ϱ�? (\"��\" Ȥ�� \"�ƴϿ�\"��� �Է��Ͻÿ�): ");
		gets_s(buf, 255);

		if (strcmp(buf, "��") == 0) {
			// ī�� �й���� �ٽ� ����
		}
		else if (strcmp(buf, "�ƴϿ�") == 0) {
			return 0;
		}
		else {
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			goto PROCEED;
		}
	}

	return 0;
}