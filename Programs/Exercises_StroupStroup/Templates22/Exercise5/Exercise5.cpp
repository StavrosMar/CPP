// Templates 23 - Exercise 5 - sort 
// This is the sort converted to a templated version

#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>

// Class declarations

// Function declarations

/*
// sort function template
	// Option 1 - using sort from std
template<typename T>
void sort(std::iterator &a, std::iterator &b) {

	// std::sort needs Compare type as input
	std::sort(&a, &b, &criteria);
}


// print function

void printVec( iterator a, iterator b) {
	
	for (auto i = a ; i != b ; ++i ) {
	
		std::cout<< "e" << *i << " ";
	}
	
	std::cout<< "\n" ;
	
}
*/

typedef bool (*F)(const int&,const int&); //!! typedef required for Comparison Functions

namespace stavros {
	
	//!!Temporary 
//	typedef int T;

	// sort
	template<typename T, F f<T> >       //!! F f instead of typename F
	void sort() {
		int a = 1;
		int b = 2;
		f<T>(a,b);     //!! inline with the typedef above
	};
	
	// Comparison function : greater
	template<typename T>
	bool greater(const T &a,const T &b) {
	
		return (a > b) ? true : false;
	}
	
	// Comparison function : smaller
	template<typename T>
	bool smaller(const T &a, const T &b) {
	
		return (a < b) ? true : false;
	}

}


// main 
int main() {

	std::vector<int> vec0{1,2,3};
	
	//std::cout<<stavros::greater<int>(1,2)<<std::endl;;
	stavros::sort<stavros::greater<int>>();

//	sort(vec0.begin(), vec0.end());
/*
	std::cout<< "The sorted vector is the following : " << std::endl;
	printVec( vec0.begin(), vec0.end() )<< std::endl;
*/	
}
