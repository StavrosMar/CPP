//Test for new project setup

#include <iostream>

using namespace std;

class Base1 {

public:
	Base1(){};

	Base1(const Base1& base1) { *this = base1; cout<<"        *** Calling Base1 Constructor"<<endl;};

	//At least 1 virtual method pure virtual -> Class is abstract --> No object can be built
	//virtual double operator()(const int& lola) const=0;

	//If function not pure virtual: I need to provide implementation for this function
	virtual double Nikos(const int& lola) const {
		return 0.0;
	}
	virtual ~Base1(){};

};

class Derv : public Base1 {

public:

	virtual double operator()(const int& kakao) const {

		return 0.0;
	}

};

//Implicit conversion to Base1 is imposed
double testFuncCopy(const Base1 base) {

	return 10.0;
}

double testFuncByReference(const Base1& base) {

	return 20.0;
}

double testFuncRReference(const Base1&& base){

	return 90.0;
}
/*
int main() {

	cout<<"Hello World"<<endl;

	Derv deriv;

	Base1* base = &deriv;

	cout<<"Calling Function by no Reference - implicit conversion is done to Base1"<<endl;
	cout<<"Result is :"<<testFuncCopy(deriv)<<endl;

	cout<<"Calling Function by Reference"<<endl;
	cout<<"Result is :"<<testFuncByReference(deriv)<<endl;

	cout<<"Calling Function by RReference"<<endl;
	cout<<"Result is :"<<testFuncRReference(std::move(deriv))<<endl;

	return 0;
}

*/
