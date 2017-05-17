// This is an auxiliary file to aid us understand
// the process of creating a function that receives a pointer to 
// a class member so that we can call it with different members as arguments
// - More info found in StrouStroup 20.6 - Pointers to Members

#include <iostream>

// Test Class
class FruitBasket {

public:
	//-// Constructor from 2 ints
	FruitBasket(const int& a = 0, const int& o = 0) : apple(a), orange(o) {};
	
	// Members (public)

	int apple;
	int orange;

	//Learning - function members
	const int* apple_ptr = &apple;
	void donothing() const {};
};


// Function
//-// This is where the test takes place
void printFruit(const FruitBasket& obj, const int FruitBasket::*fruitoulini) {

	std::cout<<"exeis : "<<obj.*fruitoulini<<std::endl;
}

// FunctionPtrObj
//-// Same but passing pointer
void printFruit(const FruitBasket* obj, const int FruitBasket::*fruitoulini) {

	std::cout<<"~~PtrObj Implementation~~~"<<std::endl;
	std::cout<<"exeis : "<<obj->*fruitoulini<<std::endl;
}

// Main function
int main() {

	// Create object 
	
	FruitBasket today(3,5); // 3 apples, 2 pears
	
	// Test Function
	//-// Count apples
	printFruit(today, &FruitBasket::apple);
	
	// Test FunctionPtrObj
	//-// Count oranges - pass pointer
	printFruit(&today, &FruitBasket::orange);


        //Pointer to data member test
         //-// Case 1 : Class member is not a pointer
         using Ptrm = const int FruitBasket::*;
         Ptrm pp(&FruitBasket::apple);
         
         //-// Case 2 : Class member is a pointer
         using Ptrm_ptr = const int* FruitBasket::*;
         Ptrm_ptr pp_ptr(&FruitBasket::apple_ptr);
         
         //-// Case 3 : Class member is a function taking 0 arguments
         using Ptrm_func = void (FruitBasket::*)() const;
         Ptrm_func dnfunc(&FruitBasket::donothing);
         
         //-// Case 4 : memeber is a pointer to a function
               // *f = f so same as Case 3
        
	return 0;
}
