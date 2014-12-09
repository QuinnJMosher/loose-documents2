#include <iostream>
#include <string>
#include "ErrorHandeling.h";
using namespace std;

const int UPPER_LIMIT = 1000;
const int LOWER_LIMIT = -1000;

void calculator();

int main() {
	ErrCode errcode = ErrCode::NO_ERROR;
	try {
		calculator();
	}
	catch (Exception except) {//catch custom exceptions
		errcode = except.errType;
		cout << errcode << ": " << except.errMessage << endl;
	}
	catch (exception except) {//catch standard exception
		errcode = ErrCode::STD_EXCEPTION;
		cout << except.what() << endl;
	}
	catch (ErrCode error) {//catch errorcode only
		errcode = error;
		cout << errcode << ": No message given\n";
	}
	catch (...) {//catch all other throws
		errcode = ErrCode::UNIDENTIFIED_ERROR;
		cout << errcode << ": No message or ErrCode given\n";
	}

	if (errcode != ErrCode::NO_ERROR) {
		system("pause");
	}
	return errcode;
}

void calculator() {
	int val1, val2, ans;
	char opr;
	bool validInput = false;
	cout << "Enter value 1 (-1000 - 1000)\n";
	while (!validInput) {
		try {
			cin.sync();
			cin.clear();
			validInput = true;
			cin >> val1;
			if (val1 > UPPER_LIMIT || val1 < LOWER_LIMIT){
				throw val1;
			}
		}
		catch (int input) {
			cout << "value must be between -1000 and 1000\n";
			validInput = false;
		}
		catch (...) {
			cout << "value must be an integral number\n";
			validInput = false;
		}
	}

	validInput = false;
	cout << "Enter value 2 (-1000 - 1000)\n";
	while (!validInput) {
		try {
			cin.sync();
			cin.clear();
			validInput = true;
			cin >> val2;
			if (val2 > UPPER_LIMIT || val2 < LOWER_LIMIT){
				throw val2;
			}
		}
		catch (int input) {
			cout << "value must be between -1000 and 1000\n";
			validInput = false;
		}
		catch (...) {
			cout << "value must be an integral number\n";
			validInput = false;
		}
	}

	validInput = false;
	cout << "Enter operation (+, -, *, / or %)\n";
	while (!validInput) {
		try {
			cin.sync();
			cin.clear();
			validInput = true;
			opr = ' ';
			cin >> opr;
			if (!(opr == '+' || opr == '-' || opr == '*' || opr == '/' || opr == '%')) {
				throw opr;
			}
		}
		catch (...) {
			cout << "invalid operation\n";
			validInput = false;
		}
	}

	switch (opr) {
	case '+':
		ans = val1 + val2;
		break;
	case '-':
		ans = val1 - val2;
		break;
	case '*':
		ans = val1 * val2;
		break;
	case '/':
		ans = val1 / val2;
		break;
	case '%':
		ans = val1 % val2;
		break;
	default:
		throw Exception(ErrCode::INVALID_INPUT_ERROR, "opreation was invalid at operation switch");
		break;
	}

	cout << ans << endl;
	system("pause");
}