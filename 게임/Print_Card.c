#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Print_Card(int* User_Card, char* User, char* User_Class) {

	char input[255] = { 0 };

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t%s의 카드 패\n", User);
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t1. 달무티 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t2. 대주교 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t3. 시종장 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t4. 남작부인 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t5. 수녀원장 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t6. 기사 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t7. 재봉사 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t8. 석공 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t9. 요리사 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t10. 양치기 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t11. 광부 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t12. 농노 : %d", *User_Card);
	User_Card++;
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t조커 : %d", *User_Card);
	
CHECK:
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t카드 패를 확인하셨습니까? (\"확인 완료\"라고 입력하시오) : ");
	gets_s(input, 255);
	if (strcmp(input, "확인 완료") == 0) {
		return 0;
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t\t\t잘못입력하셨습니다.");
		goto CHECK;
	}
	
	
}