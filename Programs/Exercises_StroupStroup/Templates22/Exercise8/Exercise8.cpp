//Templates 23 - Exercise 8
// Create a Map Class

//<Details>



#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cstring>

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

	//Testing stavros
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
	
	//-//test
	//Map(Map<const char* c_string>::) :	
	

	//Test
	
	//-// vectorprint
	void print_elemlast(){
		
		std::cout<<"print_elemlast::The Last Elem is : ("<<Map<T>::vec.back().first<<" ,    "<<Map<T>::vec.back().second<<")"<<std::endl;
	}
	//-// templateparamprint
	void print_testparam() {

		std::cout<<Map<T>::mary<<std::endl;
	}

	//-// using inheritance - keyword typename is necessary
        typename Map<T>::VecOfPairs lalal;

};

//TEST3 - int

template<typename T>
void TestFunction(const std::pair<T,int>& pair1, const std::pair<T,int>& pair2, const T& keyfound, const T& keynotfound) {

	//-//Set-up
	using VecOfPairs = std::vector<std::pair<T,int>>;
	VecOfPairs vec_main_int{ pair1, pair2 };
	
	//-//Calling point

	Map<T>   map1{vec_main_int};

	//-//Print results

	map1.print_elemlast();

	//-//Find element - tests
	std::cout<<"Value cor to : "<<keyfound<<"  ->   "<<map1[keyfound]<<std::endl;
	
	std::cout<<"Value cor to : "<<keynotfound<<"  Not Found   "<<std::endl;

}

//TEST3 - END


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

////TEST ORIGINAL END


//TEST1 - std::string
	
	//-//Set-up
	std::pair<std::string,int> pair1_str{"std::string - Anna",3};
	std::pair<std::string,int> pair2_str{"std::string - Liza", 10};

	std::string notfound_str="std::string - non existent";	
	TestFunction(pair1_str,pair2_str,pair1_str.first,notfound_str);

////TEST1 - END



//TEST2 - char - cstyle strings
	
	//-//Set-up
	std::pair<const char*,int> pair1{"char - Apollo",13};
	std::pair<const char*,int> pair2{"char - Zeus", 10};
		
	const char* notfound="char - non existent";	
	TestFunction(pair1,pair2,pair1.first,notfound);

////TEST2 - char - END



//TEST3 - int

	TestFunction({1, 300},{2, 1000}, 2, 39);

////TEST3 - int - END


	return 0;

}
