#include "PayOffs_and_Factory.h"


	intPayOff::intPayOff(const double& d) {};
	doublePayOff::doublePayOff(const double& d) {};



//This is responsible for create a sinlge instance of the Factory;
PayOffFactory& PayOffFactory::Instance() {
    
    static PayOffFactory theFactory;
    return theFactory;
    
}

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction) {

	//Yoshi's book wrong - i will use the operator or emplace as normal
	creatorMap.emplace(make_pair(PayOffId,CreatorFunction));

}

PayOff* PayOffFactory::CreatePayOff(const string& PayOffId, const double& Strike) {

	auto i{creatorMap.find(PayOffId)};

	if (i == creatorMap.end()) {
		cout<<" is an unknown payoff" << "\n";
		return nullptr;
	} else {
		//Call functionpointer with argument Strike;
		//This is the actual construction of the PayOff (or inherited) object -
			//i->second is the address of PayOffHelper<T>::Create
			// so we are actually calling new T(Strike) everytime we hit this point
			// - so everyTime we call CreatePayOff and we find a matching string - a new PayObject is created.
			// - TODO : Would we like to build a new object if we have already have 1 with the same Strike price ?????

		return (i->second)(Strike);
	}
}
