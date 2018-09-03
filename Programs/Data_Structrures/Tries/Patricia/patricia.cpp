/*
*   Topics covered:
*                    1) Patricia Trie implementation
*						a) insert
*						b) search
*						c) delete
*                   
*/

//for template linking
#ifndef PAT_C
#define PAT_C

#include "patricia.h"

template <class T> Node<T>::Node() {
	left = this;
	right = this;
	bitIndex = 0;
	//the rest default construction.
}

template <class T> Node<T>::Node(const string& key, const T& data) {
	left = this;
	right = this;
	bitIndex = 0;
	this->data = data;
	this->key = key;
}

#endif