#include "patricia.h"

template <class T> Node<T>::Node() {
	//the rest default construction.
}

template <class T> Node<T>::Node(const string& key, const T& data) {
	this->data = data;
	this->key = key;
}

int main() {
	Node<int> a;
	return 0;
}
