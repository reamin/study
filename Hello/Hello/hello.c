#include <stdio.h>
#include <windows.h>
void draw_check02(int c, int r);
void gotoxy(int x, int y);
void move_draw(int num);

int main(void){
	
	draw_check02(5, 5);
	move_draw(5);
	printf("\n\n");
	return 0;

}
void move_draw(int num){
	int i, j;
	//int a = 1;

	for (i = 0; i < num; i++){
		for (j = 1; j <= num; j++){
			gotoxy(j * 4 - 1, i * 2 + 2);
			printf("%2d", i * 5 + j);
			//a++;
		}
	}

}
void draw_check02(int c, int r){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (i = 1; i < 12; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	for (i = 0; i < c - 1; i++){
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[8]);
	}
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < r - 1; i++){
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++){
			printf("  ");
			printf("%c%c", a, b[2]);
		}
		printf("\n");

		printf("%c%c", a, b[7]);
		for (j = 0; j < c - 1; j++){
			printf("%c%c", a, b[1]);
			printf("%c%c", a, b[11]);
		}
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}

	printf("%c%c", a, b[2]);
	for (j = 0; j < c; j++){
		printf("  ");
		printf("%c%c", a, b[2]);
	}
	printf("\n");
	printf("%c%c", a, b[6]);
	for (i = 0; i < c - 1; i++){
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[10]);
	}
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
