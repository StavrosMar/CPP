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
#include "utils.h"

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

//for template linking
#include "patricia.cpp"

#endif

