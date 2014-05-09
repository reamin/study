#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define X_MAX 79
#define Y_MAX 24
#define Y_MIN 1	//���ÿ� ���õ� ���� ��� DEFINE���� ����
#define X_MIN 1	//���ÿ� ���õ� ���� ��� DEFINE���� ����
#define getch() _getch() // http://jbslife-textcube.blogspot.kr/2010/02/getch%EC%99%80-getch.html ����

void move_arrow_key(char key, int *x1, int *y1);
void gotoxy(int x, int y);
void move_axis(int*, int, BOOL); //�ڵ� �� ���� ���̱� ���� �߰� �Լ�

int main(void){
	char key;
	int x = 10, y = 5; // ó�� A�� ����ϰ� �� ��ǥ

	do{
		gotoxy(x, y); // gotoxy�Լ� ����, ������Ʈ�� x,y ��ġ�� �̵�
		printf("A"); // �ش���ġ���� A�� �����
		key = getch(); // getch()�Լ��� ���� Ű���� �Է��� �ް�, �ش�Ű�� key������ ����
		// ����API�� ������� getch�迭�� �ƴ� GetKeyState()������ ����ϵ��� �Ѵ�.
		move_arrow_key(key, &x, &y); // move_arrow_key�Լ� ����, ������ �Էµ� key�� ���� �ش繮 ����
	} while (key != 27); // key�� ���� ESC(�ƽ�Ű�ڵ� 27)�϶� ���Ϲ� Ż��

	return 0;
}

void move_arrow_key(char key, int *x1, int *y1){
	switch (key){
	case 72: //����(��) ������ ȭ��ǥ Ű �Է�
		move_axis(y1, Y_MIN , TRUE);
		break;
	case 75: //����(��) ������ ȭ��ǥ Ű �Է�
		move_axis(x1, X_MIN, TRUE);
		break;
	case 77: //������(��) ������ ȭ��ǥ Ű �Է�
		move_axis(x1, X_MAX, FALSE);
		break;
	case 80: //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		move_axis(y1, Y_MAX, FALSE);
		break;
	default:
		return;
	}
}

void move_axis(int *axis, int loc, BOOL flag){
	/* ����� c���� boolŸ���� ������ typedef�� ������ ���ִ� ��� 
	* TRUE FALSE ���� #DEFINE���� ���ǵǾ� �ְ�, VS�� ��쿡�� minwindef.h �� ���ǵǾ� ����.
	* �������� ���ݾ� Ʋ���� ��
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