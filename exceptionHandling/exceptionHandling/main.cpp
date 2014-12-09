#include <iostream>
#include <string>
using namespace std;

enum ErrCode {
	NO_ERROR,
	UNIDENTIFIED_ERROR
};

class Exception {
public:
	Exception() {	
		errType = ErrCode::UNIDENTIFIED_ERROR;
		errMessage = "Unknown Error"; 
	}

	Exception(ErrCode in_errType, string in_errMessage) {
		errType = in_errType;
		errMessage = in_errMessage;
	}

	~Exception() { }

	ErrCode errType;
	string errMessage;
};

int main() {
	try {
		run();//start the program proper
	}
	catch (Exception exec) {
		cout << exec.errType << ": " << exec.errMessage << endl;
	}
	catch (ErrCode error) {
		cout << error << ": No message given\n";
		return error;
	}
	catch (...) {
		cout << ErrCode::UNIDENTIFIED_ERROR << ": No message or ErrCode given\n";
		return ErrCode::UNIDENTIFIED_ERROR;
	}
	return ErrCode::NO_ERROR;
}

void run() {
	//stuff
}