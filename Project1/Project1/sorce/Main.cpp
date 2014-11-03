#include <iostream>

using namespace std;

struct Number {
	bool isDecimal;
	bool isSigned;
	int value;

	void CreateNumber() {
		//2a\ prompt for number type
		//2b\ prompt for sinage
		//2c\ prompt for value
	}

	Number Add(Number other) {

	}

	Number Subtract(Number other) {

	}
};

int ToBinary(int in_value, bool in_isSigned) {

}

int ToDecimal(int in_value, bool in_isSigned) {

}

void main() {
	cout << "cross-base calculator\n";
	//1\ create Numbers
	Number valueOne;
	Number valueTwo;

	//2\ call var.CreateNumber()
	cout << "creating first Number\n";
	valueOne.CreateNumber();
	cout << "creating second Number\n";
	valueOne.CreateNumber();

	//3\ prompt for return value
	cout << "enter return value: (BYte/DEcimal) ";
	char returnInput[3] = "";
	cin >> returnInput;

	bool returnAsDec = false;

	if (strcmp(returnInput, "DE") == 0) {
		returnAsDec = true;
	} else if (strcmp(returnInput, "-") != 0) {
		cerr << "Invalid return type.\n";
		system("pause");
		return;
	}

	//4\ prompt for operation type
	cout << "enter operation type: (+/-) ";
	char operationInput[2] = "";
	cin >> operationInput;

	Number displayValue;
	
	if (strcmp(operationInput, "+") == 0) {
		displayValue = valueOne.Add(valueTwo);
	} else if (strcmp(operationInput, "-") == 0) {
		displayValue = valueOne.Subtract(valueTwo);
	} else {
		cerr << "Invalid operation.\n";
		system("pause");
		return;
	}

	//5\ display value
	cout << valueOne.value << " " << operationInput << " " << valueTwo.value << " = ";

	if (returnAsDec) {
		cout << displayValue.value << endl;
	} else {
		cout << ToBinary(displayValue.value, displayValue.isSigned) << endl;
	}

	//e\ pause and end
	system("pause");
}