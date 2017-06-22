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
T* dcast(void* ptr) { //ptr is the pointer to the object

	size_t* vfptr = reinterpret_cast<size_t**>(ptr);
	

}

}

class Interface {public: virtual ~Interface() {}; virtual void print_name() { std::cout<<"Interface"<<std::endl;} };

class M : public Interface {

	void print_name() { std::cout<<"M class"<<std::endl;} ;

};

class A : public M {

	void print_name() { std::cout<<"A class"<<std::endl;} ;

};

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

//TEST0 - confirming functionality

//A* PointerStavros = stavros::dcast<A>(ptr);
auto* ptr_test = dynamic_cast<A*>(ptr);
std::cout<<typeid(ptr_test).name()<<std::endl;

//TEST0 - END

//TEST1 - 

std::cout<<"######TEST 1 - Starting ######"<<std::endl;

Interface* ptr_test2 = &a;

using Type = size_t;

//First cast
Type* vfptr = *(reinterpret_cast<Type**>(ptr_test2));
//Second cast
//Type* vfptr=(Type *)&ptr_test2;
vfptr=(Type *)&*vfptr;

((void (*)()) *vfptr )();

vfptr++;

((void (*)()) *vfptr )();
//TEST1 - END

	return 0;
}
