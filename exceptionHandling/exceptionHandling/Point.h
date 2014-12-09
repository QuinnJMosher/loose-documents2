#ifndef _Point_h_
#define _Point_h_
#include "ErrorHandeling.h"

class Point {
public:
	int x;
	int y;

	void DoAthing() { 
		if (this == nullptr) {
			throw Exception(ErrCode::NULL_POINTER_ERROR, "\"Point.DoAthing()\" called on a null pointer");
		}
	}
};

#endif