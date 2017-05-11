// Exercise 5b - Record and sort on count and price 
//This is a prototype fpr 

#include <iostream>

template<typename T>
class Record {

public :

	// Constructor 
	Record(T& c, T& p) : count{c}, price{p} {};
	
	
	
	// public members
	T count;
	T price;
	
};

// Comparison wrapper - generic use for the following:
//-// T is for the objects
//-// Comp is for the function object used for the comparison
//-// C is for the object member i want to sort on

template<typename T,typename Comp>
class compwrapper {

private:

	auto memb;

public:

       compwrapper(auto& T::member) : memb{

       bool operator() (const& T obj1, const& T obj2) {
       	
              //how the hell am i going to pass the member ? pointer maybe?
              C memsort;
              
              //execute operator on the member 
              obj1.memsorVtComp();
       
       }

}



int main() {

// sort as we know it / syntax familiar

vector<int> svec{19,23,56,77};
sort<std::greater<int>>(svec.begin(),svec.end());

// Sort on Record data memebers

std::vector<Record<int>> vecRec{Record<int>(10,1), Record<int>(4,100)};

// Attempt1
fo::sort<std::greater<Record<int>>()>(vecRec.begin(),vecRec.end());

//Comparison Object creation required.
compwrapper<Record<int>,std::greater<int>> CompareOnPrice{Record<int>::price};

// Attempt2
fo::sort< compwrapper<std::vector<int>,std::greater<int>,

return 0;

}

