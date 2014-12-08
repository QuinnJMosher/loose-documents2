#ifndef _logger_h_
#define _logger_h_ 

#include <string>
#include <queue>
#include <fstream>

using namespace std;

enum Logtype {
	Log_genral,
	Log_debug,
	Log_error
};

struct Message {
	Logtype type;
	string mes;
};

class Logger {
public:
	static void Receive(Message mes);
	static void ReadAllMessages();
	static void ReadOneMessage();

private:
	static queue<Message> readyMessages;

};

void say(Logtype in_log, string in_message);
void say(string in_message);


#endif