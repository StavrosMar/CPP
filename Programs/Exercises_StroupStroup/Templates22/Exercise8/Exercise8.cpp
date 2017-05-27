//Templates 23 - Exercise 8
// Create a Map Class

/*
Implement a simple Map class based on the Assoc class from §19.2.1.(Assoc).
Make sure Map works correctly using both C-style strings(TEST2) and string(TEST1) s as keys.
Make sure Map works correctly for types with and without default constructors(TEST4).
Provide a way of iterating over the elements of a Map .
*/


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

//-// Assoc::operator[] declaration - slow method
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
	
	//Operators
	
	//-//Operator[] - Element Access/Addition
	int operator[](const T& s);

	//-//Opetator > - compare pair_1 with pair_2 for sorting

	//Function Objects
	//-// Function object for == operator
	struct Com_pair_key {
		
		Com_pair_key(const T& s) : key(s) {};

		constexpr bool operator()(const std::pair<T,int>& a) {
		
			return (a.first == key ? true : false);
		};

		private:

			T key;
	};

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

//-// Map::operator[] definition - faster way sol
template<typename T>
int Map<T>::operator[](const T& s) {
	
//	Map<T>::Com_pair_key(s);

	auto iter_found = std::find_if(Map<T>::vec.begin(),Map<T>::vec.end(),
					[s](const std::pair<T,int>& a) 
					{ return (a.first == s ? true : false); } );
		
	if (iter_found != Map<T>::vec.end()) {

		Map<T>::vec.push_back({s, 0});
		return Map<T>::vec.back().second;
	
	} else {
		
		return iter_found->second;
		
	};
}

// No Default constr definition
class NoDefCon {

	int _data;

public:
	
	NoDefCon(const int& data) : _data(data) {};

};

//TestFunction for different types
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

/*

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


//TEST4 - No Default Constructor defined

	using VecOfPairs = std::vector<std::pair<NoDefCon,int>>;
	
	std::pair<NoDefCon,int> pair1_ndc{100,1};
	
	std::pair<NoDefCon,int> pair2_ndc{1000,1};
	
	VecOfPairs vec_main_ndc{ pair1_ndc, pair2_ndc };
	
	//-//Calling point

	Map<NoDefCon>   map1{vec_main_ndc};

//TEST4 - NoDefCon - END
*/	
	return 0;

}
