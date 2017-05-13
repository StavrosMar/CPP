// Exercise 5b - Record and sort on count and price 
//This is a prototype fpr 

#include <iostream>
#include <string>
#include <vector>
#include <Exercise5.cpp>

template<typename T>
class Record {

public :

	// Constructor 
	Record(const T& c,const T& p) : count{c}, price{p} {};
	
	
	// public members
	T count;
	T price;
	
	//Learning - function members
	const T* price_ptr = &price;
	void donothing() const {
		
	}
};

// Comparison wrapper - generic use for the following:
//-// T is for the objects
//-// Comp is for the function object used for the comparison
//-// C is for the object member i want to sort on

template<typename T,typename Comp, typename memType>
class compwrapper {

private:
	//This is the pointer to memebr - for count and price types
	using Pm = const memType T::*;
	
	//Pointer to member of type T e.g. Record
	Pm member; 

public:
       
       // Constructors
       //-// Construction of the wrapper based on the function pointer passed.
       compwrapper(Pm mem) : member{mem} {};

       bool operator() (const T& obj1, const T& obj2) {
       	
              // - Question : How am i going to pass the member ? pointer maybe?
	      //   Answer   : pointer to member already passed during construction.
	      //              Nothing to worry about now - just implement normal 
	      //              functionality
 //             C memsort;
              
              //execute operator on the member 
 //             obj1.memsorVtComp();
 
 
 			return 0;
 		}

};



int main() {


// Sort on Record data memebers

std::vector<Record<int>> vecRec{Record<int>(10,1), Record<int>(4,100)};

//Comparison Object creation
compwrapper<Record<int>,std::greater<int>,int> CompareOnPrice{&Record<int>::price};

/*
// Attempt2
fo::sort< CompareOnPrice() >; 


// Attempt1
fo::sort<std::greater<Record<int>>>(vecRec.begin(),vecRec.end());
*/


//TODO-Start - move these to the ptr to member relevant file.

//Pointer to data member test
//-// Case 1 : member is not a pointer
using Ptrm = const int Record<int>::*;
Ptrm pp(&Record<int>::price);

//-// Case 2 : member is a pointer
using Ptrm_ptr = const int* Record<int>::*;
Ptrm_ptr pp_ptr(&Record<int>::price_ptr);

//-// Case 3 : member is a function
using Ptrm_func = void (Record<int>::*)() const;
Ptrm_func dnfunc(&Record<int>::donothing);

//-// Case 4 : memeber is a pointer to a function
      // *f = f so same as Case 3

//TODO-End

return 0;

}

