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
		return (i->second)(Strike);
	}
}
