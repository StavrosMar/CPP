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

template <typename T,typename R>
T*  dcast(R* arg) {
	
	T t;

	std::cout<<"Argument is of type   :"<<typeid(*arg).name()<<std::endl;
	std::cout<<"Casting to type       :"<<typeid(t).name()<<std::endl;
	
	if( typeid(*arg).name() == typeid(t).name() ) {
	
		std::cout<<"\n## cast success ##\n";;
		
	//	*t = *arg;
		return &t;
	
	} else {

		const std::bad_cast e;
		
		std::cout<<"\n## cast failed ##\n";
		std::cout<<e.what()<<std::endl;
		
	}
	
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

	ptr = &a;
	
}


//std::cout<<"Interface the same  ? : "<<(typeid(*ptr).name()==typeid(a).name())<<std::endl; 
//std::cout<<"ptr is of type : "<<typeid(*ptr).name()<<std::endl; 

stavros::dcast<A>(ptr);

auto* ptr_test = dynamic_cast<A*>(ptr);
std::cout<<typeid(ptr_test).name()<<std::endl;

//TEST1 - Sorting Matrices

	//-//Print results
	
//TEST1 - END

	return 0;

}
