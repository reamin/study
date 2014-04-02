#include <stdio.h>
int multiple(int a, int b);


int main(void){
	int i, j;

	printf("출력할 구구단의 수를 입력하세요 : ");
	scanf("%d %d", &i, &j);

	multiple(i, j);

}

int multiple(int a, int b){

	if (a <= b){
		for (int i = a; i <= b; i++){
			for (int j = 1; j <= 9; j++){
				printf("%d * %d = %d\n", i, j, i * j);
			}
		}
	}
	else{
		for (int i = b; i <= a; i++){
			for (int j = 1; j <= 9; j++){
				printf("%d * %d = %d\n", i, j, i * j);
			}
		}
	}
}