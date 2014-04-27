#pragma once
class Circle // Circle 클래스 선언부
{
	int radius; // 반지름을 의미하는 변수 선언, 접근지정자는 private이다.
public:
	void setRadius(int radius);
	double getArea();
};

