#include <iostream>
#include <map>
#include <string>

using namespace std;

// Interface class
class PayOff {
public:
	virtual ~PayOff();
};

//Some other child class inheriting
class doublePayOff : public PayOff {

	// something;

};

class PayOffFactory {

// Note - we always have 1 object of PayOffFactory - hence the chopped out constructors, =
private:
    
    //Making all constructors private;
	PayOffFactory() {};
	PayOffFactory(const PayOffFactory& p) {};
    PayOffFactory(PayOffFactory&& p)  {};

    //Making all assignment operators private;
    PayOffFactory& operator=(const PayOffFactory& p) { return *this;};
    
public:
    

    typedef PayOff* (*CreatePayOffFunction)(double);
    static PayOffFactory& Instance();
    PayOff* CreatePayOff(string PayOffId, double Strike);

    ~PayOffFactory(){};
    
};

PayOffFactory& PayOffFactory::Instance() {
    
    static PayOffFactory theFactory;
    return theFactory;
    
}

int main() {

	PayOffFactory::Instance();

}
