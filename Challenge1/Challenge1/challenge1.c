#include <stdio.h>
int multiple(int a, int b);


int main(void){
	int i, j;

	printf("����� �������� ���� �Է��ϼ��� : ");
	scanf("%d %d", &i, &j);

	if (i > j){
		int temp = i;
		i = j;
		j = temp;
	}
	
	multiple(i, j);


}

int multiple(int a, int b){

	for (int i = a; i <= b; i++)
		for (int j = 1; j <= 9; j++)
			printf("%d * %d = %d\n", i, j, i * j);
}