#include <iostream>
#include "Add.h"
#include "Sub.h"
#include "Div.h"
#include "Mul.h"

using namespace std;

int main(){
	int a, b;
	char op;
	int result;

	Add adder;
	Sub subtracter;
	Mul multiplier;
	Div divider;

	for (;;){
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> a >> b >> op;

		switch (op){
		case '+':
			adder.setValue(a, b);
			result = adder.calculate();
			cout << result << endl;
			break;
		case '-':
			subtracter.setValue(a, b);
			result = subtracter.calculate();
			cout << result << endl;
			break;
		case '*':
			multiplier.setValue(a, b);
			result = multiplier.calculate();
			cout << result << endl;
			break;
		case '/':
			divider.setValue(a, b);
			result = divider.calculate();
			cout << result << endl;
			break;
		default:
			cout << "연산자가 잘못 되었습니다." << endl;
		}
	}
}