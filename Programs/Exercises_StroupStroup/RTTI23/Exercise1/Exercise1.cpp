//RTTI23 - Exercise 1 - ptr_cast like dynamic cast
//<Information>

//<Details>



#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <typeinfo>

namespace stavros {

	//* functions defined here *//

} 

template<class A_ptr, class B>    //Note the class vs typename identifier
A_ptr ptr_cast(B* p) {
	
	auto result{dynamic_cast<A_ptr>(p)};
	
		std::cout<<"before"<<std::endl;
	if (result != NULL) {
		
		std::cout<<"DynamicCastNotNull"<<std::endl;
		return result;
	
	} else {

		std::cout<<"Null"<<std::endl;
		const std::bad_cast e;
		std::cout<<e.what()<<std::endl;
	}

};


class A
{
public:
  virtual ~A () { }
};

class B : public A
{
};

//Main function
int main() {


A a_ref;
A* a_ptr;

B* b;

A* p = &a_ref // doesn't work on a_ptr ??? why ????

try
{
	auto ptr = dynamic_cast<B*>(p);
//	ptr->start();
}
catch (std::bad_cast)
{
	std::cout<<"Invalid_cast"<<std::endl;
}

//dyn_cast_res->start();
//TEST1 - Sorting Matrices
	
	//-//Set-up
	
	
	//-//Calling point


	//-//Print results
	
//TEST1 - END

	return 0;

}
