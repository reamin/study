#include "Circle.h"

void Circle::setRadius(int radius){
	this->radius = radius; // 매개변수와 멤버 변수의 이름이 똑같음으로 this 포인터를 통해 
} //setRadius()함수의 매개변수radius가 아닌 Circle객체의 radius 멤버변수임을 알려주도록 한다.

double Circle::getArea(){ // 반지름을 구하는 멤버 함수
	return 3.14 * radius * radius;
}