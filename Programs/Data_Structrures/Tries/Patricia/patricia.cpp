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

	/*//Utility functions
	//maybe make the below a friend i.e. generic function 
	int bit_diff(const string& ref, const string& s) {
			
			bool flag{true};
			int i{0};
			int len{min(ref.length(),s.length())};

			while (flag && i<len) {
				
				int a = bit_get(ref,i);
				int b = bit_get(s,i);
				
				if (a-b!=0) {

			}
	}*/
				
	//Get the nth bit of the stream s	
	//Validated		
	static int bit_get(const string& str, const int& n) {
		
		auto nchars = str.size();
		
		unsigned int indx = n/BITS_ASCII;

		unsigned int bitmod = n%BITS_ASCII; // bit (0-7) ASCII
		auto bitmove = BITS_ASCII - (bitmod+1);
		auto bitmask = 1 << (bitmove);
		
		unsigned int bit = (bitmask & str[indx]) >> bitmove;

		return bit;
	}
	

};
/*
template <class T> PatTree {

	void getbi


}*/


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


//#endif
