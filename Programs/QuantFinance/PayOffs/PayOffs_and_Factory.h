#include <iostream>
#include <map>
#include <string>

using namespace std;

// Interface class
class PayOff {
public:
	virtual ~PayOff() = default;
};

//Some other child class inheriting
class doublePayOff : public PayOff {
public:
	doublePayOff(const double&);
	// something;

};

//Some other child class inheriting
class intPayOff : public PayOff {
public:
	intPayOff(const double&);
	// something;

};

class PayOffFactory {

// Note - we always have 1 object of PayOffFactory - hence the chopped out constructors, =

public:

	//CreatePayOffFunction is a function taking a double returning a PayOff pointer
	typedef PayOff* (*CreatePayOffFunction)(const double&);
    static PayOffFactory& Instance();
    PayOff* CreatePayOff(const string& PayOffId,const double& Strike);
    void RegisterPayOff(string, CreatePayOffFunction);

    ~PayOffFactory(){};

private:
    
    //Making all constructors private;
	PayOffFactory() {};
	PayOffFactory(const PayOffFactory& p) {};
    PayOffFactory(PayOffFactory&& p)  {};

    //Making all assignment operators private;
    PayOffFactory& operator=(const PayOffFactory& p) { return *this;};
    
    //Map of the factory
    map<string,CreatePayOffFunction> creatorMap;
    
};
