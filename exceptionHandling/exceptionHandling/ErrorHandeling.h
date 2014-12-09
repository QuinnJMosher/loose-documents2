#ifndef _ErrorHandeling_h_
#define _ErrorHandeling_h_
#include <string>

enum ErrCode {
	NO_ERROR,
	STD_EXCEPTION,
	UNIDENTIFIED_ERROR,
	NULL_POINTER_ERROR,
	FILE_NOT_FOUND_ERROR,
	FILE_IS_CORRUPT_ERROR
};

class Exception {
public:
	Exception() {
		errType = ErrCode::UNIDENTIFIED_ERROR;
		errMessage = "Unknown Error";
	}

	Exception(ErrCode in_errType, std::string in_errMessage) {
		errType = in_errType;
		errMessage = in_errMessage;
	}

	~Exception() { }

	ErrCode errType;
	std::string errMessage;
};

#endif