/*
*   Topics covered:
*                    1) Patricia Trie implementation
*						a) insert - DONE
*						b) search - DONE
*						c) delete
*						c) delete - memory management and cleanup. 
*   				
*					 2) Optional :
*						Logging levels for debugging. (inheritance etc(?))
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

//TODO - Make it unique
//unique_ptr<Node<T>> root;
Node<T>* root;

public:

	//Constructors
	//PTrie() : root{make_unique<Node<T>>} {}; //TODO-Exception Handling
	PTrie() : root(new Node<T>("Root",T())) {};
	PTrie(const PTrie&) = delete; //delete for now
	PTrie operator=(const PTrie&) = delete; //delete for now
	PTrie operator=(PTrie&&) = delete; //delete for now


	//Member functions
	bool insert(const string& key,const T& data);
	std::pair<bool,const Node<T>*> findptr(const string& key) const;
	std::pair<bool,T> find(const string& key) const;
	bool remove(const string& key);

};

//for template linking
#include "patricia.cpp"

#endif

