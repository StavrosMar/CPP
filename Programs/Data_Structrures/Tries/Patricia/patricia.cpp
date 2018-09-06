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

//Insert the string
template <class T> bool PTrie<T>::insert(const string& key,const T& data) {

	Node<T>* c = root;//the child node
	Node<T>* p = root;

	//Search and stop at the first upwards link 
	while (c->bitIndex > p->bitIndex) {
		p = c;
		(bit_get(key.c_str(),c->bitIndex)) ? c = p->right : c = p->left;
	}

	//Key Exists on Tree - then don't add it.
	if (c->key == key) {
		return false;
	}

	// Create pointer - assign - stitch etc....
	//...
	//auto indx = bit_diff(key,p->key);
	//auto bval = bit_get(key.c_str(),indx);
			

}

template <class T> std::pair<bool,T> PTrie<T>::find(const string& key) const {

}

template <class T> bool PTrie<T>::remove(const string& key) {


}

#endif