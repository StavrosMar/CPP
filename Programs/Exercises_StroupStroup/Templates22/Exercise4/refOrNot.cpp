// This program is intended to find out the implications 
// of using <type>& in return types from functions
// ** Bottom Line : if it is not a member function of class : DISASTER!!!!!!

#include<iostream>

template<typename C>
class Wrapper{

public:
	
	// Constructors

	Wrapper(const C& c) : value{c} { std::cout << "Copying value" << std::endl;}
	Wrapper(const C&& c) : value{c} { std::cout << "Moving value" << std::endl;}

	// Access functions

	C& getVal() {  
		
		return value;
	}
		
private:
	C value;
};


// disaster if returning reference or pointer to the value different to the one being fed.
// if the reference is removed from int& func1 then fine.
// If i do return garde by reference it does not crash probably because the compiler 
// is smart enough to not actually anything inside the function
int& func1(int& garde ) {

	int nikolaos{3};

	return nikolaos;


}

int main() {

	Wrapper<int> maria{1};
	Wrapper<int> nikos( func1(maria.getVal()) );

	std::cout << nikos.getVal() << std::endl;

	

	return 0;
}
