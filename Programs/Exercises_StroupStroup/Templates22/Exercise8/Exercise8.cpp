//Templates 23 - Exercise 8
// Create a Map Class

//<Details>



#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

// Assoc Definition
template<typename S>
class Assoc {
public:	
	using VecOfPairs = std::vector<std::pair<S,int>>;
	
	// Plain members
	VecOfPairs vec;

	Assoc(VecOfPairs& inVec) : vec (inVec) {};	
	
	// Operators
	const int& operator[](const S&) const;
	int operator[](const S&);

	//Test stavros
	int mary = 0;

};

//-// Assoc::operator[] declaration
template<typename S>
int Assoc<S>::operator[](const S& s) {
	
	// search for s; return a reference to its value if found;
	// otherwise, make a new pair {s,0} and return a reference to its value
	
	for(auto x : vec)
		if (s == x.first) return x.second; // gives warning - no prob 

	vec.push_back({s,0});	// initial value: 0

	return vec.back().second; //return last element
}

// Map Definition
template<typename T>
class Map : public Assoc<T> {

public:
	//Constructors

	//-// Sol1 : Run constructors
	Map(typename Map<T>::VecOfPairs& vinput) : Assoc<T>::Assoc(vinput) {}; //Run Assoc constructor
	
	//-// Sol2 : Inherit constructors
	//using Assoc<T>::Assoc;

	//Test
	
	//-// vectorprint
	void print_elemlast(){
		
		std::cout<<Map<T>::vec.back().first<<"    "<<Map<T>::vec.back().second<<std::endl;
	}
	//-// templateparamprint
	void print_testparam() {

		std::cout<<Map<T>::mary<<std::endl;
	}

	//-// using inheritance - keyword typename is necessary
        typename Map<T>::VecOfPairs lalal;

};


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


//TEST1 - std::string
	
	//-//Set-up
	using VecOfPairs = std::vector<std::pair<std::string,int>>;
	VecOfPairs vec_main{ {"Anna",3}, {"Liza", 10} };
		
	
	//-//Calling point

	Map<std::string>   map1{vec_main};

	//-//Print results

	map1.print_elemlast();

	//-//Find element
	std::cout<<map1["Liza"]<<std::endl;
	map1.print_elemlast();

//TEST1 - END

//TEST1 - char
	
	//-//Set-up
	using VecOfPairs_char = std::vector<std::pair<const char[],int>>;
	VecOfPairs_char vec_main_char{ {"Anna",3}, {"Liza", 10} };
		
	
	//-//Calling point

	Map<const char[100]>   map1_char{vec_main_char};

	//-//Print results

	map1_char.print_elemlast();

	//-//Find element
	std::cout<<map1_char["Liza"]<<std::endl;
	map1_char.print_elemlast();

//TEST1 - END
	return 0;

}
