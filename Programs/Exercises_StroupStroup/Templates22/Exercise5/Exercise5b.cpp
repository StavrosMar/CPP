// Exercise 5b - Record and sort on count and price 
// Functions developed for Exercise5.cpp are used here 

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
	const T count;
	const T price;
	
	static int id;
	
	//Learning - function members
	const T* price_ptr = &price;
	void donothing() const {
		
	}
};

// Comparison wrapper - generic use for the following:
//-// T is for the objects
//-// Comp is for the function object used for the comparison
//-// C is for the object member i want to sort on

template<typename T,typename Comp, typename memType, const memType T::*member>
class compwrapper {

public:
       
       bool operator() (const T& obj1, const T& obj2) const {
       	
              
		/*Run the comparison function execute operator on the member
	          It is running the overloaded () operator*/
	
		bool result = Comp()(obj1.*member, obj2.*member);

 		return result;
 	}

};


int main() {


// Sort on Record data memebers

std::vector<Record<int>> vecRec{Record<int>(10,1), Record<int>(4,100)};

// Attempt1

using Cmpr = compwrapper<Record<int>,fo::greater<int>,int,&Record<int>::count>;
fo::sort<Cmpr> (vecRec.begin(),vecRec.end());

std::cout<<"The sorting order of the Records according\n to the sorting criteria selected is the following\n"<<std::endl;


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

