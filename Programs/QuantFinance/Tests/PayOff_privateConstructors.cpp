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


private:
    
    //Making all constructors private;
	PayOffFactory() = default;
	PayOffFactory(const PayOffFactory& p) = default;
    PayOffFactory(PayOffFactory&& p) = default;
    
    //Making all assignment operators private;
    PayOffFactory& operator=(const PayOffFactory& p) = default;
    
public:
    
    //
    typedef PayOff* (*CreatePayOffFunction)(double);
    static PayOffFactory& Instance();
    PayOff* CreatePayOff(string PayOffId, double Strike);

    ~PayOff(){};
    
};

PayOffFactory& PayOffFactory::Instance() {
    
    static PayOffFactory theFactory;
    return theFactory;
    
}

int main() {

	PayOffFactory::Instance();

}
