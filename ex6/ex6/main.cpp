#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;

int main(){
	int n, radius; // n은 입력받을 원의 개수이며, radius는 반지름을 의미한다
	int count = 0; // 면적이 100보다 큰 원을 세기 위한 카운트 변수
	
	cout << "원의 개수 : ";
	cin >> n;
	Circle *pArray = new Circle[n]; // 입력받은 원의 개수(변수n)만큼 Circle 배열을 동적 생성한다

	for (int i = 0; i < n; i++){ // for문을 통해 입력받은 원의개수만큼 반지름을 입력한다.
		cout << "원 " << i + 1 << "의 반지름 : ";
		cin >> radius;
		pArray[i].setRadius(radius); // 입력받은 반지름값을 각 Circle개체의 setRadius()함수를 통해 전달해준다.
	}
	

	Circle *p = pArray; // 포인터 변수p를 통해 pArray포인터, 즉 배열에 접근한다.

	for (int i = 0; i < n; i++){ 
		if (p->getArea() >= 100) // getArea()함수를 통해 나온 반지름의 값이 100보다 크다면
			count++; // count를 1 증가시킨다.
		p++;
	}

	cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl; // for문을 돌며 나온 count변수의 값 = 100보다 반지름이 큰 원의 갯수를 출력해준다.

	delete[] pArray; // 동적으로 할당받은 배열을 반환해준다.

}