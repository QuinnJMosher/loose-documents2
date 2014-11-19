#include "Queue.h"

template <class T>
Queue<T>::Queue() {
	firstNode = nullptr;
	lastNode = nullptr;
	size = 0;
}

template <class T>
Queue<T>::~Queue() {
	while (size > 0) {
		this->pop();
	}
}

template <class T>
bool Queue<T>::isEmpty() {
	return (size == 0);
}

template <class T>
unsigned int Queue<T>::Size() {
	return size;
}

template <class T>
void Queue<T>::push(T &value) {
	Node *node = new Node();

	if (size > 0) {
		(*lastNode).nextNode = node;
	} else {
		firstNode = node;
	}

	lastNode = node;
	(*node).data = value;

	size++;

}

template <class T>
T Queue<T>::pop() {
	if (size > 0) {
		Node node = (*firstNode);
		(*firstNode).~Node();

		size--;

		if (size > 0) {
			firstNode = node.nextNode;
		} else {
			firstNode = nullptr;
			lastNode = nullptr;
		}

		return node.data;
	}
	return NULL;
}

template <class T>
T Queue<T>::top() {
	if (size > 0) {
		return (*firstNode).data;
	}
	return NULL;
}