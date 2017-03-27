#include<iostream>

//Random class for usage with the test class "dessous"
template<typename T>
struct Random {
	T value;
};

// Class for in-class New and Delete operation
template<typename T>
class NewDeleteInClassTest{
public:
	//the variable to test
	Random<T>* patrikas;
	
	NewDeleteInClassTest(T& mam) : patrikas{new Random<T>{mam}} {};
	~NewDeleteInClassTest(){
	    std::cout<<sizeof(patrikas->value)<<std::endl;
	    delete patrikas;
	}
	
};

//Aux function to be called
Random<int>* aux(){

	int a(20);
	int* c=&a;

	NewDeleteInClassTest<int> b(a);
	
	Random<int>* address1(b.patrikas);
	std::cout<<"**Before return Value : "<<address1->value<<std::endl;
	return address1;
};

int main() {
	Random<int>* vrou=aux();
	std::cout<<"**After return Value : "<<vrou->value<<std::endl;

	delete vrou;
};
