#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <windows.h> 

void draw_check01(int c, int r);
void gotoxy(int x, int y);
void game_control(void);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void display_stone(int matrix[][20]); // �̹� ���� �ٵϵ��� �ٵ��ǿ� ǥ�� 

// kidmct@nate.com 
// matrix((x+1)/2), y); 
int main(void){

	game_control();

	return 0;
}

void display_stone(int matrix[][20]){
	int x, y;

	for (x = 0; x < 20; x++){
		for (y = 0; y < 20; y++){
			if (matrix[x][y] == 1){
				gotoxy(x * 2 - 1, y);
				printf("��");
			}
		}
	}
}

void game_control(void){
	int x = 1, y = 1;
	int matrix[20][20] = { 0 };
	char key;

	do{
		gotoxy(1, 1);
		draw_check01(18, 18);

		gotoxy(x, y);
		printf("��");

		display_stone(matrix);
		gotoxy(1, 20);
		printf("����Ű�� �����ÿ�");
		printf("�����̽� Ű�� �����ÿ�.");

		key = getch();

		if (key == 27)
			exit(0);
		move_arrow_key(key, &x, &y, 37, 19);
		if (key == 32)
			matrix[(x + 1) / 2][y] = 1;
	} while (1);
}

void draw_check01(int c, int r){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (i = 1; i < 12; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);
	for (i = 0; i < c - 1; i++)
		printf("%c%c", a, b[8]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < r - 1; i++){
		printf("%c%c", a, b[7]);
		for (j = 0; j < c - 1; j++)
			printf("%c%c", a, b[11]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}

	printf("%c%c", a, b[6]);
	for (i = 0; i < c - 1; i++)
		printf("%c%c", a, b[10]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b){
	switch (key){
	case 72: //����(��) ������ ȭ��ǥ Ű �Է�  
		*y1 = *y1 - 1;
		if (*y1 < 1)
			*y1 = 1; // y��ǥ�� �ּҰ�  
		break;
	case 75: //����(��) ������ ȭ��ǥ Ű �Է�  
		*x1 = *x1 - 2;
		if (*x1 < 1)
			*x1 = 1; // x��ǥ�� �ּҰ�  
		break;
	case 77: //������(��) ������ ȭ��ǥ Ű �Է�  
		*x1 = *x1 + 2;
		if (*x1 > x_b)
			*x1 = x_b; // x��ǥ�� �ִ밪  
		break;
	case 80: //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�  
		*y1 = *y1 + 1;
		if (*y1 > y_b)
			*y1 = y_b; // y��ǥ�� �ִ밪  
		break;
	default:
		return;
	}
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
