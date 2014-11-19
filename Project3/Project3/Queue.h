#ifndef _Queue_h_
#define _Queue_h_

template <class T>
class Queue {
private:
	class Node {
	public:
		T data;
		Node* nextNode;
	};

	Node* firstNode;
	Node* lastNode;
	unsigned int size;

public:
	Queue();
	~Queue();

	bool isEmpty();
	unsigned int Size();

	void push(T &value);
	T pop();
	T top();
};

#endif