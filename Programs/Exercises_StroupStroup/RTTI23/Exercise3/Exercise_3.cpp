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

	//First casting way
	int* vfptr = *reinterpret_cast<int**>(ptr);
	
	//Second casting way
	//size_t* vfptr = (size_

}

}

class Interface {public: virtual ~Interface() {}; 
	
	virtual void print_name() { std::cout<<"Interface"<<std::endl;} 
	virtual void interface_only() { std::cout<<"Interface only"<<std::endl;} ;
	virtual void interface_and_m_only() { std::cout<<"Interface + M only"<<std::endl;} ;
	
};

class M : public Interface {

	void print_name() { std::cout<<"M class"<<std::endl;} ;
	void interface_and_m_only() { std::cout<<"Interface + M only override in M"<<std::endl;} ;

};

class A : public M {

	void print_name() { std::cout<<"A class"<<std::endl;} ;
	//void print_name2() { std::cout<<"A class next"<<std::endl;} ;

};

class B : public Interface {};

int main() {

//-//Set-up

int i_sel(0);

A a,a2;
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

//Define pointers
Interface* ptr_test2 = &a;
A* ptr_a = &a;
A* ptr_a2 = &a2;

using Type = size_t;  //64 bit
//using Type = size_t;//64 bit equivalent

////First Casting way
//Type **vptr = (Type **)ptr_test2;
//Move 2 positions ahead
//((void (*) () ) vptr[0][2])();

////Second Casting way
//Or could do
  //Type* vptr = reinterpret_cast<Type*>(ptr_test2);
Type* vptr = (Type*)(ptr_test2);
vptr = (Type*)*vptr;

//Third Casting Way - Testing
//A* vptr = (A*)(ptr_test2);

//if ( vptr == ptr_test2 ) std::cout<<"vptr and ptr_a are the same"<<'\n';
//print ptr type
std::cout<<"Pointer Type Interface: "<<typeid(*vptr).name()<<std::endl;

//-//vptr++; //Move 2 bytes ahead
//-//vptr++; //Move another 2 bytes ahead as needed for x64 architecture (?)
vptr = vptr+2;

//Execute virtual functions
((void (*) () ) *vptr)();

vptr=vptr+1;;
((void (*) () ) *vptr)();

vptr=vptr+1;;
((void (*) () ) *vptr)();

//Expected segmentation fault here
vptr=vptr+1;;
((void (*) () ) *vptr)();

//Second cast
//Type* vfptr=(Type *)&ptr_test2;


//TEST1 - END

	return 0;
}
