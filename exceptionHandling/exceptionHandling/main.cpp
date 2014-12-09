#include <iostream>
#include <string>
#include "Point.h"
#include "ErrorHandeling.h"
using namespace std;

void run();
void AFileThing();

int main() {
	ErrCode errcode = ErrCode::NO_ERROR;
	try {
		run();//start the program proper
	}
	catch (Exception except) {
		errcode = except.errType;
		cout << errcode << ": " << except.errMessage << endl;
	}
	catch (exception except) {
		errcode = ErrCode::STD_EXCEPTION;
		cout << except.what() << endl;
	}
	catch (ErrCode error) {
		errcode = error;
		cout << errcode << ": No message given\n";
	}
	catch (...) {
		errcode = ErrCode::UNIDENTIFIED_ERROR;
		cout << errcode << ": No message or ErrCode given\n";
	}
	system("pause");
	return errcode;
}

void run() {
	/*try {
		AFileThing();
	}
	catch (Exception except) {
		throw Exception(except.errType, except.errMessage + " \"AFileThing\" threw this error.");
	}
	catch (exception except) {
		throw except;
	}
	catch (ErrCode error) {
		throw Exception(error, "\"AFileThing\" threw this error.");
	}
	catch (...) {
		throw Exception(ErrCode::UNIDENTIFIED_ERROR, "\"AFileThing\" threw this error.");
	}
	/**/
	Point* ptPtr = nullptr;
	(*ptPtr).DoAthing();
	/**/
}

void AFileThing() {
	throw Exception(ErrCode::FILE_NOT_FOUND_ERROR, "Could not find \"whatever.txt\" in directory \"C:\\here_it_is\"");
	//throw ErrCode::FILE_IS_CORRUPT_ERROR;
	//throw "oh noes!";
}