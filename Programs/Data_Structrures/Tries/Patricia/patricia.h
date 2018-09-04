/*
*   Topics covered:
*                    1) Patricia Trie implementation
*						a) insert
*						b) search
*						c) delete
*                   
*/

//#pragma once 


#ifndef PAT_H
#define PAT_H

#include <iostream>
#include <vector>
#include <utility>
#include "utils.h"
#include <memory>

using namespace std;

//Patricia Node
template <class T> struct Node{

	//members
	Node*   right; // Set to this by Default at compile time
	Node*   left;
	string	key;
	T	  	data;
	int bitIndex;

	//Constructors
	Node(); //Maybe delete(?)
	Node(const string& key, const T& data);
	Node(const Node& n) = delete;
	Node operator=(const Node& n) = delete;

};

template <class T> class PTrie {
private:

unique_ptr<Node<T>> root;

public:
	
	//Constructors
	PTrie() : root{make_unique<Node<T>>} {}; //TODO-Exception Handling

	//Member functions
	bool insert(const string& key,const T& data);
	pair<bool,T> find(const string& key) const;
	bool remove(const string& key);

};

//for template linking
#include "patricia.cpp"

#endif

