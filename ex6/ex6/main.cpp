#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;

int main(){
	int n, radius; // n�� �Է¹��� ���� �����̸�, radius�� �������� �ǹ��Ѵ�
	int count = 0; // ������ 100���� ū ���� ���� ���� ī��Ʈ ����
	
	cout << "���� ���� : ";
	cin >> n;
	Circle *pArray = new Circle[n]; // �Է¹��� ���� ����(����n)��ŭ Circle �迭�� ���� �����Ѵ�

	for (int i = 0; i < n; i++){ // for���� ���� �Է¹��� ���ǰ�����ŭ �������� �Է��Ѵ�.
		cout << "�� " << i + 1 << "�� ������ : ";
		cin >> radius;
		pArray[i].setRadius(radius); // �Է¹��� ���������� �� Circle��ü�� setRadius()�Լ��� ���� �������ش�.
	}
	

	Circle *p = pArray; // ������ ����p�� ���� pArray������, �� �迭�� �����Ѵ�.

	for (int i = 0; i < n; i++){ 
		if (p->getArea() >= 100) // getArea()�Լ��� ���� ���� �������� ���� 100���� ũ�ٸ�
			count++; // count�� 1 ������Ų��.
		p++;
	}

	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�." << endl; // for���� ���� ���� count������ �� = 100���� �������� ū ���� ������ ������ش�.

	delete[] pArray; // �������� �Ҵ���� �迭�� ��ȯ���ش�.

}