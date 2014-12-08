#include "logger.h"

void say(Logtype in_log, string in_message) {
	Message newMessage;
	newMessage.type = in_log;
	newMessage.mes = in_message;
	Logger::Receive(newMessage);
}

void say(string in_message) {
	Message newMessage;
	newMessage.type = Logtype::Log_genral;
	newMessage.mes = in_message;
	Logger::Receive(newMessage);
}

queue<Message> Logger::readyMessages = queue<Message>();

void Logger::Receive(Message mes) {
	readyMessages.push(mes);
}

void Logger::ReadAllMessages() {
	while (readyMessages.size() > 0) {
		ReadOneMessage();
	}
}

void Logger::ReadOneMessage() {
	fstream file;

	switch (readyMessages.front().type) {
	case Logtype::Log_genral:
		file.open("genral_log.txt", ios_base::out);
		file << readyMessages.front().mes << endl;
		break;
	case Logtype::Log_debug:
		file.open("debug_log.txt", ios_base::out);
		file << readyMessages.front().mes << endl;
		break;
	case Logtype::Log_error:
		file.open("error_log.txt", ios_base::out);
		file << readyMessages.front().mes << endl;
		break;
	default:
		file.open("error_log.txt", ios_base::out);
		file << "message had an invalid log type: " + readyMessages.front().type << endl;
		file << "message was: " << readyMessages.front().mes << endl;
		break;
	}

	if (file.is_open()) {
		file.sync();
		file.close();
		file.clear();
	}

	readyMessages.pop();
}