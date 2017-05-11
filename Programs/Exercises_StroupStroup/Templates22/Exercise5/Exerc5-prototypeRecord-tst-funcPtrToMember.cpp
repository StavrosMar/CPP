// This is an auxiliary file to aid us understand
// the process of creating a function that receives a pointer to 
// a class member so that we can call it with different members as arguments

#include <iostream>

// Test Class
class FruitBasket {

public:
	//-// Constructor from 2 ints
	FruitBasket(const int& a = 0, const int& o = 0) : apple(a), orange(o) {};
	
	// Members (public)

	int apple;
	int orange;

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

	return 0;
}
