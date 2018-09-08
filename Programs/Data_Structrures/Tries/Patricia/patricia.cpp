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

//Search down the tree
//returns true/false and pointer to last child traversed.
template <class T> pair<bool,const Node<T>*> PTrie<T>::findptr(const string& key) const {
	
	Node<T>* p = root;
	Node<T>* c;
	(bit_get(key.c_str(),p->bitIndex),key.length()) ? c = p->right : c = p->left;
	
	//-//Search and stop at the first upwards link 
	while (c->bitIndex > p->bitIndex) {
		p = c;
		(bit_get(key.c_str(),p->bitIndex),key.length()) ? c = p->right : c = p->left;
		cout<<"Performing loop"<<'\n';
	}

	pair<bool,const Node<T>*> ret;
	(c->key == key) ? ret.first = true : ret.first = false;
	ret.second = p;
	return ret;
}

template <class T> std::pair<bool,T> PTrie<T>::find(const string& key) const {
	
	pair<bool,const Node<T>*> foundp = findptr(key);
	pair<bool,T> retp;

	if (foundp.first) {
		retp.first = true;
		retp.second = foundp.second->data;
	} else {
		retp.first = false;
		retp.second = T();
	}
	return retp;
}

//Insert the string
template <class T> bool PTrie<T>::insert(const string& key,const T& data) {

	//If key already exists don't added.
	pair<bool,const Node<T>*> pn{this->findptr(key)};
	if (pn.first) {
		cout<<"Key : \""<<key<<"\" exists --- maintaing --- \n";
		return false;
	}

	cout<<"\nL1 : Adding "<<key<<endl;

	
	Node<T>* c = root->right;
	Node<T>* p = c;

	int indkey;

	//-//Search down the trie to find insertion point
	bool ftime = true;
	while ((indkey > c->bitIndex && c->bitIndex > p->bitIndex) || ftime) {
		ftime = false;
		p = c;	
		indkey = bit_diff(key,p->key);
		cout<<"indkey  = "<<indkey<<'\n';
		bit_get(key.c_str(),indkey,key.length()) ? c = p->right : c = p->left;
		cout<<"bit_Index c = "<<c->bitIndex<<" key: "<<c->key<<'\n';
	}

	Node<T>* x = new Node<T>(key,data); //build new node.
	x->bitIndex = indkey;

	if (!bit_get(key.c_str(),x->bitIndex,key.length())) {
		p->left = x;
		x->right = c;
		cout<<"Entered first"<<'\n';
	} else {
		p->right = x;
		x->left = c;

		cout<<"Entered second"<<'\n';
	}

	return true;
	
}

template <class T> bool PTrie<T>::remove(const string& key) {


}

#endif