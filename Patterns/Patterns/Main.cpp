#include <iostream>
#include "Singleton.h"

void main() {

	Singleton* singleton = Singleton::GetInstance();
	(*singleton).test();
	system("pause");
}