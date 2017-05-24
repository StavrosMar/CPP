//Templates 23 - Exercise 8
// Create a Map Class

//<Details>



#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

// Assoc Definition
class Assoc {
public:	
	using VecOfPairs = std::vector<std::pair<std::string,int>>;
	
	// Plain members
	VecOfPairs vec;

	Assoc(VecOfPairs& inVec) : vec (inVec) {};	
	
	// Operators
	const int& operator[](const std::string&) const;
	int& operator[](const std::string&);

};

//-// Assoc::operator[] declaration
int& Assoc::operator[](const std::string& s) {
	
	// search for s; return a reference to its value if found;
	// otherwise, make a new pair {s,0} and return a reference to its value
	
	for(auto x : vec)
		if (s == x.first) return x.second; // gives warning - no prob 

	vec.push_back({s,0});	// initial value: 0

	return vec.back().second; //return last element
}

// Map Definition
class Map : public Assoc {

public:
	//Constructors

	Map(VecOfPairs& vinput) : Assoc::Assoc(vinput) {}; //Run Assoc constructor
	
	void print_elemlast(){
		
		std::cout<<vec.back().first<<"    "<<vec.back().second<<std::endl;
	}
};


namespace stavros {

	//* functions defined here *//

} 

int main() {

//TEST ORIGINAL

//-// original map function - test with duplicated keys
std::map<std::string,int> maptic{
	
	{"Anna-Liz", 0},
	{"Lolita", 1},
	{"Lolita", 2}
};

//-// It is printing the first result
std::cout<<maptic["Delphine"]<<std::endl;

//TEST ORIGINAL END

//TEST1 - Sorting Matrices
	
	//-//Set-up
	using VecOfPairs = std::vector<std::pair<std::string,int>>;
	VecOfPairs vec_main{ {"Anna",3}, {"Liza", 10} };
		
	
	//-//Calling point

	Map   map1{vec_main};

	//-//Print results

	map1.print_elemlast();
//TEST1 - END

	return 0;

}
