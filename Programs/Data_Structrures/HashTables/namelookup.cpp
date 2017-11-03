//Name Lookup Exercise 

/* Taken from https://www.hackerearth.com/fr/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/

Our friend Monk has been made teacher for the day today by his school professors . He is going to teach informatics to his colleagues as that is his favorite subject . Before entering the class, Monk realized that he does not remember the names of all his colleagues clearly . He thinks this will cause problems and will not allow him to teach the class well. However, Monk remembers the roll number of all his colleagues very well . Monk now wants you to help him out. He will initially give you a list indicating the name and roll number of all his colleagues. When he enters the class he will give you the roll number of any of his colleagues belonging to the class. You need to revert to him with the name of that colleague.

*/

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

// Hash function declaration
unsigned int hash(const unsigned int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
	// Truncate so that maximum is 10^5 (or 99999 to be precise)
	x = x & (unsigned int)(99999);
    return x;
}



int main() {

//Input 

std::string i_name{"  "};
int         i_roll{0};

std::string input;
std::stringstream ss;

	//Input ends if a name ends in ~
while ( getline (std::cin,input) && i_name.find("~") > i_name.length()-1 ) {

	ss.clear();
	ss.str("");
	ss << input;
    
	//extract i_roll and i_name from the input
	ss >> i_roll >> i_name;   	
	//debugging cin
	//std::cout<< "**Confirmation : " << i_roll << "<space>" <<  i_name << "\n";

}

//Tests passed - we have truncated random numbers woohoo!
std::cout << "Testing hash function : " << hash(9.2000021*pow(10,8)) << "\n" ;

// * build hash table now

// * build hash table here

return 0;

}
