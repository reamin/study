#include "Circle.h"

void Circle::setRadius(int radius){
	this->radius = radius; // �Ű������� ��� ������ �̸��� �Ȱ������� this �����͸� ���� 
} //setRadius()�Լ��� �Ű�����radius�� �ƴ� Circle��ü�� radius ����������� �˷��ֵ��� �Ѵ�.

double Circle::getArea(){ // �������� ���ϴ� ��� �Լ�
	return 3.14 * radius * radius;
}