// Exercise 5b - Record and sort on count and price 
// Functions developed for Exercise5.cpp are used here 

#include <iostream>
#include <string>
#include <vector>
#include <Exercise5.cpp>

template<typename T>
class Record {
private:

	std::string name;

public :

	// Constructor 
	Record(const T& c,const T& p,const std::string& n) : count{c}, price{p}, name{n} {};
	
	
	// public members
	T count;
	T price;
	
	// Operators
	//-// << operator for printing the name
	friend std::ostream& operator<<(std::ostream& out, const Record& rec) {

		out<<rec.name;
		return out;
	}

	//Learning - function members
	const T* price_ptr = &price;
	void donothing() const {};
	
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


//Build Vector

std::vector<Record<int>> vecRec{Record<int>(10,1,"A"), Record<int>(4,100,"B")};

// Sorting on count

using Cmpr_count = compwrapper<Record<int>,std::greater<int>,int,&Record<int>::count>;

fo::sort<Cmpr_count> (vecRec.begin(),vecRec.end());

std::cout<<"------Sorting on \"count\" : \n"<<vecRec<<std::endl;

// Sorting on price

using Cmpr_price = compwrapper<Record<int>,std::greater<int>,int,&Record<int>::price>;

fo::sort<Cmpr_price> (vecRec.begin(),vecRec.end());

std::cout<<"------Sorting on \"price\" : \n"<<vecRec<<std::endl;


// END of Exercise 5b


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

