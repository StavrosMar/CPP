//RTTI23 - Exercise 3a- Consider how dynamic_cast might be implemented

/*Attempt for implementing a function behaving in a similar way to dynamic_cast
  This is not required by the exercise.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <typeinfo>

namespace stavros {

//dcast

template <typename T>
T*  dcast(void* arg) {

	

/*	
	try {	
		T* t = arg;
		std::cout<<"\n## cast success ##\n";
	}
	catch (std::bad_cast)
	{
		std::cout<<"\n!! cast failed ##\n";
	}

	return t;
*/

} 

}

class Interface {public: virtual ~Interface() {}; };

class M : public Interface {};

class A : public M {};

class B : public Interface {};

int main() {

//-//Set-up

int i_sel(0);

A a;
M m;
B b;
Interface* ptr;

//-//Calling point


std::cin>>i_sel;


if (i_sel==1) {

ptr = &m;
	
}


std::cout<<"Interface the same  ? : "<<(typeid(*ptr).name()==typeid(a).name())<<std::endl; 
std::cout<<"ptr is of type : "<<typeid(*ptr).name()<<std::endl; 

//	stavros::dcast<A>(ptr);
	
//TEST1 - Sorting Matrices

	//-//Print results
	
//TEST1 - END

	return 0;

}
