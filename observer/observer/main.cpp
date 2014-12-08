#include <iostream>
#include "logger.h"

void main() {
	say("hello anyone!");
	say(Logtype::Log_genral, "hello people!");
	say(Logtype::Log_debug, "hello debuggers!");
	say(Logtype::Log_error, "hello errors!");
	Logger::ReadAllMessages();
	system("pause");
}