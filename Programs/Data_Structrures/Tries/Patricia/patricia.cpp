/*
*   Topics covered:
*                    1) Patricia Trie implementation
*						a) insert
*						b) search
*						c) delete
*                   
*/

//#pragma once 
//#ifndef PAT_H
//#define PAT_H
#define BITS_ASCII 8

#include <iostream>
#include <vector>

using namespace std;

//Get the nth bit of the stream s	
//Validated
	 int bit_get(const char* str,const int& n,const size_t nchars=1) {
		
		unsigned int indx = n/BITS_ASCII;

		unsigned int bitmod = n%BITS_ASCII; // bit (0-7) ASCII
		auto bitmove = BITS_ASCII - (bitmod+1);
		auto bitmask = 1 << (bitmove);
		
		unsigned int bit{0}; //put zero if out-of-bounds
		if (indx < nchars) {
			bit = (bitmask & str[indx]) >> bitmove;
		};
		return bit;
	}

	//Utility functions
	//maybe make the below a friend i.e. generic function
	//Built it with std::strings  - could try char instead.
	int bit_diff(const string& s1, const string& s2) {

			const string* smlst;
			const string* lgst; //pointer to shortest and longest string
			if (s1.length() > s2.length()) {
				smlst = &s2;
				lgst = &s1;
			} else {
				smlst = &s1;
				lgst = &s2;
			}
			
			int indx{-1};
			bool flag{false};

			while (!flag && indx<smlst->length()) {
				++indx;
				if (s1[indx]!=s2[indx]) {
					flag = true;
				}
			}
			int bitInd;
			if (flag) {
				int i{0};
				while(bit_get(&s1[indx],i)==bit_get(&s2[indx],i)) {
					++i;
				}
				bitInd = (indx+1)*BITS_ASCII+i; //(i+1-1)
			} else if ( !flag && (s1.length() != s2.length()) ) { //dissimilar sizes
				bitInd = (indx+1)*BITS_ASCII; // (-1+1)
			} else { 
				bitInd = 0; // same string
		}
			return bitInd;
	}
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
