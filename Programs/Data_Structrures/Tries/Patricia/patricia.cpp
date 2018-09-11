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
	Node<T>* c = root->right;
	
	int bit;
	//-//Search and stop at the first upwards link 
	while (c->bitIndex > p->bitIndex) {
		p = c;
		cout<<"\nSearch Loop comparing \""<<key<<"\"with \""<<c->key<<"\""<<'\n';
		auto bitdiff = bit_diff(key,c->key);
		if (bitdiff>=0) {
			bit = bit_get(key.c_str(),bitdiff,key.length());
			(bit) ? c = c->right : c = c->left;
		}
		cout<<"p = "<<p->key<<" | c = :"<<c->key<<endl;
		cout<<"bit ="<<bit<<"| bitdiff ="<<bitdiff<<endl;
	}

	pair<bool,const Node<T>*> ret;
	cout<<"Search stopped at = "<<c->key<<" c->right = "<<c->right->key<<" c->left = "<<c->left->key<<'\n';
	cout<<" | c->right->right="<<c->right->right->key;
	cout<<" | c->right->left="<<c->right->left->key;
	cout<<" | c->left->right="<<c->left->right->key;
	cout<<" | c->right->left="<<c->right->left->key<<'\n';


	(c->key == key) ? ret.first = true : ret.first = false;
	ret.second = c;
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

	Node<T>* p = root;
	Node<T>* t = root->right;

	int indx{0},bit{0};

	while(bit_diff(key,t->key) > t->bitIndex && t->bitIndex > p->bitIndex ) {
		indx = bit_diff(key,t->key);
		bit = bit_get(key.c_str(),indx,key.length());
		p = t;
		(bit) ? t = t->right : t = t->left;
		cout<<"p = :"<<p->key<<"| t = :"<<t->key<<" | bit = "<<bit<<" | indx = "<<indx<<endl;
	}

	Node<T>* x = new Node<T>(key,data); //build new node.
	x->bitIndex = bit_diff(key,p->key);
	cout<<"x->bitIndex ="<<x->bitIndex<<endl;
	
	if (!bit_get(key.c_str(),x->bitIndex,key.length())) {
		p->left = x;
		x->right = t;
		cout<<"Entered first"<<'\n';
	} else {
		p->right = x;
		x->left = t;
		cout<<"Entered second"<<'\n';
	}

	cout<<"p->left  = "<<(p->left)->key<<"| p->right  = "<<(p->right)->key<<'\n';

	return true;
	
}

template <class T> bool PTrie<T>::remove(const string& key) {


}

#endif