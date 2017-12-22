//22 December notes

//Description - Drive
/* We need pointers to a class member function.
   We do not know what kind of object we need to load - it is loaded dynamically.
   We load the string - in needs to point to a known function but from unknown object.
   
   Ignore polymorphism for now (?)



*/


#include <iostream>

class Base {
	
	//Polymorphic function
	virtual void printClassName() {

		std::cout<<"#### Calling Base ####"<<"\n";
	};

//Needs to be public
public:
	//Declaring Virtual Destructor
	virtual ~Base() { };

};
	
class Child1 : public Base {

	void printclassName() {

		std::cout<<"### Calling Derived ####"<<"\n";

	};
};

class Child2 : public Base {

	void printclassName() {

		std::cout<<"### Calling Derived ####"<<"\n";

	};
};

//Provide a function mapper
 //This is the functionality needed
 //to be encapsulated in the Exercise_4_advanced.cpp file
// Get string --> return pointer to function
// At this point we know which 


//main
int main() {

//Declaration of children
	Child1  paidi_1;
	Child2  paidi_2;

//Declare Basis class pointer
	Base*   base = &paidi_1;

return 0;

}
	


