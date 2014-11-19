#ifndef _Stack_h_
#define _Stack_h_

template <class T>
class Stack {
private:
	class Node {
	public:
		T data;
		Node* nextNode;
	};

	Node* currentNode;
	unsigned int size;

public:
	Stack();
	~Stack();

	bool IsEmpty();
	unsigned int Size();

	void push(T &value);
	T pop();
	T top();

};

#endif