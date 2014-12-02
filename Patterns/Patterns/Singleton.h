#include <iostream>

#ifndef _Singleton_h_
#define _Singleton_h_

class Singleton {
public:
	static Singleton* GetInstance();
	void test();

protected:
	Singleton();
	~Singleton();

	static Singleton* instance;
};

#endif