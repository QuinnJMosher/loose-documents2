#include "Stack.h"

template <class T>
Stack<T>::Stack() {
	currentNode = nullptr;
	size = 0;
}

template <class T>
Stack<T>::~Stack() {
	while (this->size > 0) {
		this->pop();
	}
}

template <class T>
bool Stack<T>::IsEmpty() {
	return (size == 0);
}

template <class T>
unsigned int Stack<T>::Size() {
	return size;
}

template <class T>
void Stack<T>::push(T &value) {

	Node *node = new Node();
	(*node).data = value;
	(*node).nextNode = currentNode;

	size++;

	currentNode = node;
}

template <class T>
T Stack<T>::pop() {
	if (size > 0) {
		Node node = (*currentNode);
		(*currentNode).~Node();

		currentNode = node.nextNode;

		size--;

		return node.data;
	} 
	return NULL;
}

template <class T>
T Stack<T>::top() {
	if (size > 0) {
		return (*currentNode).data;
	}
	return NULL;
}