/* This is the automatic Registration for the class */

#include <iostream>
#include <string>
#include "PayOffs_and_Factory.h"

template <class T> class PayOffHelper {

public:

	PayOffHelper(const std::string&);
	static PayOff* Create(const double&);
};

/*
template <class T> PayOff* PayOffHelper<T>::Create(const double& Strike) {

	return new T(Strike);
	//TODO - Manage memory leaks in destructor.
}*/

template <class T> PayOffHelper<T>::PayOffHelper(const string& id) {

	PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
	thePayOffFactory.RegisterPayOff(id,PayOffHelper<T>::Create);
}


// Use PayOffHelper to build 1 kind of PayOff but with different Strike Prices.
int main() {

	PayOffHelper<doublePayOff> RegisterDoublePayOff("doublePayOff");
	PayOffHelper<intPayOff>    RegisterIntPayOff("intPayOff");
	//PayOffHelper<PayOff>    RegisterGenPayOff("genPayOff");


}

