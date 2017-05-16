/* This is a file to troubleshoot the situation being faced
   in Exercise5b.cpp (unable to pass pointer to Class member as a template argument):
 
//-//CODE
	
	//CASE-1 not working

	// Comparison function object creation
		
		using Cmpr = compwrapper<Record<int>,std::greater<int>,int>;
		 const Cmpr CompareOnPrice{&Record<int>::price};

	// Load the object to our sorting function:
	
		fo::sort<CompareOnPrice> (vecRec.begin(),vecRec.end());

	//CASE-2 not working

		 using Cmpr_2 = compwrapper_2<Record<int>,std::greater<int>,int>;
	 	fo::sort<Cmpr_2(&Record<int>::price)> (vecRec.begin(),vecRec.end());

//-//VERDICT

         It is possible.

	 The catch is do not use the constructor
	
	 The only thing to keep an eye on is the declaration type in the 
	 testsortwrapper template. Keep an eye on the last argument. There is no typename.
	 check the other similar files as well.

*/

#include <iostream>

template<typename llT, typename T, const llT T::*member>
void testsortwrapper() {

	//Create arbitary object
	T paleAle(10,20);
	std::cout<<paleAle.*member<<std::endl;
};


template<typename T>
class Beer{

public:

	//constructor
	//Beer() : taste{5}, price{5} {};
	Beer(const T& t, const T& p) : taste{t}, price{p} {};

	T taste;
	T price;

};


int main() {
	
	//Works PERFECT Finally!!!
	//I am able to pass pointer to Class member as a template argument
	//It is possible with normal functions so why not with Class members
	// at compile time ?

	std::cout<<"Taste is : "<<std::endl;
	testsortwrapper<int,Beer<int>,&Beer<int>::taste>();
	std::cout<<"Price is : "<<std::endl;
	testsortwrapper<int,Beer<int>,&Beer<int>::price>();

	return 0;

}
