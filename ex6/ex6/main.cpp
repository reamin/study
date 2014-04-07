#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;

int main(){
	int n, radius;
	int count = 0;
	
	cout << "원의 개수 : ";
	cin >> n;
	Circle *pArray = new Circle[n];

	for (int i = 0; i < n; i++){
		cout << "원 " << i + 1 << "의 반지름 : ";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	

	Circle *p = pArray;

	for (int i = 0; i < n; i++){
		if (p->getArea() >= 100)
			count++;
		p++;
	}

	cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl;

	delete[] pArray;

}