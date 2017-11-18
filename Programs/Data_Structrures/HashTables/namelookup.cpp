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

private:
	
	// Member declaration
	int    m_N;    // Size of Structure
	int*    Roll;  // Array with the Roll numbers
	std::string* Onoma; // Array with the Student names

	// Hash function declaration
	unsigned int hash(const unsigned int& num) {
	    
		unsigned int x{num};
		
		x = ((x >> 16) ^ x) * 0x45d9f3b;
	    x = ((x >> 16) ^ x) * 0x45d9f3b;
	    x = (x >> 16) ^ x;

		return x;
	}


public:

	// Constructor
	HashTable() : m_N(100), Roll{new int[100]}, Onoma{new std::string[100]} {};
	HashTable(const int& N) : m_N(N), Roll{new int[N]}, Onoma{new std::string[N]} {}; 

	// Copy Constructor
	HashTable(const HashTable& hashTable) {

		m_N = hashTable.m_N ;
		Roll = new int[m_N];
		Onoma = new std::string[m_N];
		
		memmove(hashTable.Roll,Roll,sizeof(int)*m_N);
		memmove(hashTable.Onoma,Onoma,sizeof(std::string)*m_N);
	}

	//Move Constructor
	HashTable(HashTable&& hashTable) {

		m_N = std::move(hashTable.m_N);
		Roll = hashTable.Roll;
		Onoma = hashTable.Onoma;

	}

	// Destructor
	~HashTable() {
		
		delete[] Roll;
		delete[] Onoma;
	}

	//Operators

	//Insert Element
	int insert(const int& rollnum, const T& name) {
		
		// Run hash
		const unsigned int h{hash(rollnum)};
		
		// Divide by the Database table length to get index
		int index = h % m_N;

			
		int count{1};
		while ( Roll[index] != 0 && index < m_N) {

			//Implement quadratic probing.
			index = (h+int(pow(count,2))) % m_N;
		
		}				
		
		if (index < m_N) {
		
			Roll[index] = rollnum;
			Onoma[index] = name;
			return 0;

		} else {

			return -11;
		}
		
	}
		
		//Access Element
	 std::string operator[](const int& rollnum) {

		//Run hash
		const unsigned int h{hash(rollnum)};

		// Divide by the Database table length to get the index
		int index = { h % m_N };

		int count{1};
		while (Roll[index] != rollnum && index < m_N) {
		
			//IMplement quadratic probing
			index = (h+int(pow(count,2))) % m_N;

		}

		if (index < m_N) {

			return Onoma[index];
		
		} else {

			return std::string("Not found");

		}

	}

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
