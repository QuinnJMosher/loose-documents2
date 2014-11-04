#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

//prototypes
int ToDecimal(int in_value, bool in_isSigned);
string ToBinary(int in_value, bool in_isSigned);

struct Number {
	bool isDecimal;
	bool isSigned;
	int value;

	void CreateNumber() {
		//2a\ prompt for number type
		cout << "enter number type: (BYte/DEcimal) ";
		char typeInput[3] = "";
		cin >> typeInput;

		isDecimal = false;

		if (strcmp(typeInput, "DE") == 0) {
			isDecimal = true;
		} else if (strcmp(typeInput, "BY") != 0) {
			cerr << "Invalid number type.\n";
			system("pause");
			throw;
		}

		//2b\ prompt for sinage
		cout << "Is this number signed? (y/n) ";
		char signedInput[3] = "";
		cin >> signedInput;

		isSigned = false;

		if (strcmp(signedInput, "y") == 0) {
			isSigned = true;
		}
		else if (strcmp(signedInput, "n") != 0) {
			cerr << "Invalid signed input.\n";
			system("pause");
			throw;
		}

		//2c\ prompt for value
		cout << "enter number value: ";
		cin >> value;

		if (!isDecimal) {
			value = ToDecimal(value, isSigned);
		}
	}

	Number Add(Number other) {
		Number out;
		out.value = this->value + other.value;
		return out;
	}

	Number Subtract(Number other) {
		Number out;
		out.value = this->value - other.value;
		return out;
	}
};

string ToBinary(int in_value, bool in_isSigned) {
	bool isNeg = false;
	int power = 0;
	int maxPower = 0;
	vector<bool> bitList = vector<bool>();

	if (in_value < 0) {
		isNeg = true;
		in_value = abs(in_value);
	}

	while (in_value >= pow(2, maxPower)) {
		maxPower++;
		bitList.push_back(false);
	}
	maxPower--;

	power = maxPower;

	while (power >= 0) {
		if (in_value - pow(2, power) >= 0) {
			in_value -= pow(2, power);
			bitList[maxPower - power] = true;
		}
		power--;
	}

	string out = "0000000000000000";

	if (in_isSigned && isNeg) {
		bitList.flip();
		for (int i = (bitList.size() - 1); i >= 0; i--) {
			if (bitList[i]) {
				bitList[i] = false;
			} else {
				bitList[i] = true;
				break;
			}
		}
	}

	for (int i = (bitList.size() - 1); i >= 0; i--) {
		if (bitList[i]) {
			if (maxPower < 15) {
				out[(15 - maxPower) + i] = '1';
			}
		}
	}

	if (isNeg && in_isSigned && maxPower < 15) {
		for (int i = (15 - bitList.size()); i >= 0 ; i--) {
			out[i] = '1';
		}
	}

	return out;
}

int ToDecimal(int in_value, bool in_isSigned) {
	vector<bool> bitList = vector<bool>();
	int temp = in_value;
	while (temp > 0) {
		temp /= 10;
		bitList.push_back(false);
	}

	temp = in_value;
	for (int i = bitList.size() - 1; i >= 0; i--) {
		if (temp % 2 == 1) {
			bitList[i] = true;
		}
		temp /= 10;
	}

	if (in_isSigned && bitList[0]) {
		bitList.flip();
		for (int i = (bitList.size() - 1); i >= 0; i--) {
			if (bitList[i]) {
				bitList[i] = false;
			}
			else {
				bitList[i] = true;
				break;
			}
		}
	}

	int out = 0;

	for (int j = 0; j < bitList.size(); j++) {
		out += bitList[j] * pow(2, (bitList.size() - 1) - j);
	}

	return out;
}

void main() {
	int temp = 01101;
	cout << ToDecimal(temp, false) << endl;
	system("pause");
}

/* final main method
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
	} else if (strcmp(returnInput, "BY") != 0) {
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
*/