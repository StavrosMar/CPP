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
	
	if (result != NULL) {
		
		return result;
	
	} else {

		std::cout<<"dynamic_cast returned null_ptr"<<std::endl;
		const std::bad_cast e;
		std::cout<<e.what()<<std::endl;
		throw e;
	}

};


class A
{
public:
 virtual  ~A () { std::cout<<"~Calling A destructor"<<std::endl; } // Mandatory virtual destructor for base class
};

class B : public A
{
public:
 ~B () { std::cout<<"~Calling B destructor"<<std::endl; }
};

class D : public A
{
public:
 ~D () { std::cout<<"~Calling D destructor"<<std::endl; }
};

class C {};


//Test Function
//-//A not inheriting from C - should give null.
template<typename CastTo, typename typePtr>
void testCast(int test_id, typePtr ptr) {
	
	std::cout<<"Test "<<test_id<<std::endl;

	 try
	 {
	 	auto ptr_res = ptr_cast<CastTo>(ptr);
		std::cout<<"Cast Successful"<<std::endl;
	 }
	 catch (std::bad_cast)
	 {
	 	std::cout<<"Invalid_cast"<<std::endl;
	 }

	 std::cout<<"#####################"<<'\n'<<std::endl;
	
}

//TEST1 - END

//Main function
int main() {


//TEST 1
//-//A not inheriting from C - should give null.

A* a;

testCast<C*>(1,a);

//TEST1 - END

//TEST2
//-// a is pointing to an object of B so downcast should work

B b2; //(if the pointer is not pointing to anythingthen we get a seg fault - this is why is defined an object and passed the address below)
A* a2 = &b2;

testCast<B*>(2,a2);
//TEST2 - END

//TEST3
//-//a3 is pointing to A - casting to B is invalid
A* a3 = new A;

testCast<B*>(3,a3);
delete a3;
//TEST3 - END

//TEST4
//-//a4 is pointing to D (inherits from A) - should give invalid
D d4;
A* a4 = &d4;

//testCast<D*>(4,a4);

//TEST3 - END
return 0;

}
