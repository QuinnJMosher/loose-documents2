#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

void main() {

	Queue<int> queue = Queue<int>();
	int value = 10;
	queue.push(value);
	value = 20;
	queue.push(value);
	value = 30;
	queue.push(value);

	std::cout << queue.isEmpty() << "\n";
	std::cout << queue.pop() << "\n";
	std::cout << queue.pop() << "\n";
	std::cout << queue.pop() << "\n";
	std::cout << queue.isEmpty() << "\n";

	system("pause");
}