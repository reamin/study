#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define X_MAX 79
#define Y_MAX 24

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);

int main(void){
	char key;
	int x = 10, y = 5; // 처음 A를 출력하게 될 좌표

	do{
		gotoxy(x, y); // gotoxy함수 실행, 프롬프트를 x,y 위치로 이동
		printf("A"); // 해당위치에서 A를 출력함
		key = getch(); // getch()함수를 통해 키보드 입력을 받고, 해당키를 key변수에 대입
		move_arrow_key(key, &x, &y, X_MAX, Y_MAX); // move_arrow_key함수 실행, 위에서 입력된 key에 따라 해당문 실행
	} while (key != 27); // key의 값이 ESC(아스키코드 27)일때 와일문 탈출

	return 0;
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b){
	switch (key){
	case 72: //위쪽(상) 방향의 화살표 키 입력
		*y1 = *y1 - 1;
		if (*y1 < 1)
			*y1 = 1; // y좌표의 최소값
		break;
	case 75: //왼쪽(좌) 방향의 화살표 키 입력
		*x1 = *x1 - 1;
		if (*x1 < 1)
			*x1 = 1; // x좌표의 최소값
		break;
	case 77: //오른쪽(우) 방향의 화살표 키 입력
		*x1 = *x1 + 1;
		if (*x1 > x_b)
			*x1 = x_b; // x좌표의 최대값
		break;
	case 80: //아래쪽(하) 방향의 화살표 키 입력
		*y1 = *y1 + 1;
		if (*y1 > y_b)
			*y1 = y_b; // y좌표의 최대값
		break;
	default:
		return;
	}
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}