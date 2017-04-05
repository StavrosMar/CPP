// This program is intended to find out the implications 
// of using <type>& in return types from functions

#include<iostream>

template<typename C>
class Wrapper{

public:
	
	// Constructors

	Wrapper(const C& c) : value{c} { std::cout << "Copying value" << std::endl;}
	Wrapper(const C&& c) : value{c} { std::cout << "Moving value" << std::endl;}

	// Access functions

	C* getVal() {  
		
		return &value;
	}
		
private:
	C value;
};

const int* func1(const int* garde ) {

	return garde;

}

int main() {

	Wrapper<int> maria{1};
	Wrapper<int> nikos( *func1(maria.getVal()) );

	std::cout << nikos.getVal() << std::endl;

	

	return 0;
}
