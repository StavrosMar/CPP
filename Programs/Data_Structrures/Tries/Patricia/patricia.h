/*
*   Topics covered:
*                    1) Patricia Trie implementation
*						a) insert
*						b) search
*						c) delete
*                   
*/

#ifndef PAT_H
#define PAT_H

#include <iostream>
#include <vector>

using namespace std;

//Patricia Node
template <class T> struct Node{

	//members
	Node*   right = this; // Set to this by Default at compile time
	Node*   left = this;
	string	key;
	T	  	data;
	int bitIndex{0};

	//Constructors
	Node(); //Maybe delete(?)
	Node(const string& key, const T& data);
	Node(const Node& n) = delete;
	Node operator=(const Node& n) = delete;

	//Utility functions
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
	}
				
	//Get the nth bit of the stream s			
	int bitget(const string& s, const int& n) {
		
	}
			//
	}

	

};

template <class T> public PatTree {

	void getbi


}


#endif
