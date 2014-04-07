#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;

int main(){
	int n, radius;
	int count = 0;
	
	cout << "���� ���� : ";
	cin >> n;
	Circle *pArray = new Circle[n];

	for (int i = 0; i < n; i++){
		cout << "�� " << i + 1 << "�� ������ : ";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	

	Circle *p = pArray;

	for (int i = 0; i < n; i++){
		if (p->getArea() >= 100)
			count++;
		p++;
	}

	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�." << endl;

	delete[] pArray;

}