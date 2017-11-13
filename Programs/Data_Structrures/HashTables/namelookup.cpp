//Name Lookup Exercise 

/* Taken from https://www.hackerearth.com/fr/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/

Our friend Monk has been made teacher for the day today by his school professors . He is going to teach informatics to his colleagues as that is his favorite subject . Before entering the class, Monk realized that he does not remember the names of all his colleagues clearly . He thinks this will cause problems and will not allow him to teach the class well. However, Monk remembers the roll number of all his colleagues very well . Monk now wants you to help him out. He will initially give you a list indicating the name and roll number of all his colleagues. When he enters the class he will give you the roll number of any of his colleagues belonging to the class. You need to revert to him with the name of that colleague.

*/

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>


namespace stavros {

template<typename T> class HashTable {

public:

	// Constructor
	HashTable(const int& N) : m_N(N) {} 


	//Operators

		//Add Element
	T insert(const int& rollnum, const T& name) {
		
		int index{hash(rollnum)};
		

		return name;

	}
		
		//Access Element
	T operator[](const int& rollnum) {
		
		return ;

	}

private:
	
	// Member declaration
	int m_N;    // Size of Structure
	int    Roll[m_N] = {0};  // Array with the Roll numbers
	string Onoma[m_N] = {0}; // Array with the Student names

	// Hash function declaration
	unsigned int hash(unsigned int x, const int& N ) {
	    x = ((x >> 16) ^ x) * 0x45d9f3b;
	    x = ((x >> 16) ^ x) * 0x45d9f3b;
	    x = (x >> 16) ^ x;
		
		// Divide by the Database table length to get index
		int index( x % N);
	    return index;
	}

	//
};

}

int main() {

//Input 

int 		N{100}; //Student number
std::string i_name{"  "};
int         i_roll{0};

std::string input;
std::stringstream ss;


stavros::HashTable<std::string> store(N);

//User input - ends if a name ends in ~
while ( getline (std::cin,input) && i_name.find("~") > i_name.length()-1 ) {

	ss.clear();
	ss.str("");
	ss << input;
    
	//extract i_roll and i_name from the input
	ss >> i_roll >> i_name;

	//Add records to the structure
	store.insert(i_roll,i_name);

}


return 0;

}
