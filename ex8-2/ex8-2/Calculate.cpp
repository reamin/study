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
		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
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
			cout << "�����ڰ� �߸� �Ǿ����ϴ�." << endl;
		}
	}
}