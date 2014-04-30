#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define X_MAX 79
#define Y_MAX 24
#define Y_MIN 1	//세팅에 관련된 값은 모두 DEFINE으로 관리
#define X_MIN 1	//세팅에 관련된 값은 모두 DEFINE으로 관리
#define getch() _getch() // http://jbslife-textcube.blogspot.kr/2010/02/getch%EC%99%80-getch.html 참고

void move_arrow_key(char key, int *x1, int *y1);
void gotoxy(int x, int y);
void move_axis(int*, int, BOOL); //코드 줄 수를 줄이기 위한 추가 함수

int main(void){
	char key;
	int x = 10, y = 5; // 처음 A를 출력하게 될 좌표

	do{
		gotoxy(x, y); // gotoxy함수 실행, 프롬프트를 x,y 위치로 이동
		printf("A"); // 해당위치에서 A를 출력함
		key = getch(); // getch()함수를 통해 키보드 입력을 받고, 해당키를 key변수에 대입
		// 윈도API를 쓸꺼라면 getch계열이 아닌 GetKeyState()계통을 사용하도록 한다.
		move_arrow_key(key, &x, &y); // move_arrow_key함수 실행, 위에서 입력된 key에 따라 해당문 실행
	} while (key != 27); // key의 값이 ESC(아스키코드 27)일때 와일문 탈출

	return 0;
}

void move_arrow_key(char key, int *x1, int *y1){
	switch (key){
	case 72: //위쪽(상) 방향의 화살표 키 입력
		move_axis(y1, Y_MIN , TRUE);
		break;
	case 75: //왼쪽(좌) 방향의 화살표 키 입력
		move_axis(x1, X_MIN, TRUE);
		break;
	case 77: //오른쪽(우) 방향의 화살표 키 입력
		move_axis(x1, X_MAX, FALSE);
		break;
	case 80: //아래쪽(하) 방향의 화살표 키 입력
		move_axis(y1, Y_MAX, FALSE);
		break;
	default:
		return;
	}
}

void move_axis(int *axis, int loc, BOOL flag){
	/* 참고로 c에는 bool타입이 없으나 typedef로 재정의 되있는 모양 
	* TRUE FALSE 역시 #DEFINE으로 정의되어 있고, VS의 경우에는 minwindef.h 에 정의되어 있음.
	* 빌더마다 조금씩 틀릴듯 함
	*/
	if (flag){
		*axis = *axis - 1;
		if (*axis < loc)
			*axis = loc;
	}
	else {
		*axis = *axis + 1;
		if (*axis > loc)
			*axis = loc;
	}
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}