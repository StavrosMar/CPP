#include <iostream>

//Topics covered:
/* 
    1) Explicit constructor : Disallow copy initialisation
    2) Explicit cast to bool operator : Disallow implicit conversions.
    3) Deleting cast to float operator : Disallow conversions to float

*/
using namespace std;

template <typename T> class ECon {

private:
int m{0};

public:

    //No arg constructor needed in case i define copy constructors
    ECon() = default;
    
    //Copy Constructor Explicit - does not allow copy initialisation
    explicit ECon(const ECon&) = default;
    
    //Another Constructor Explicit - - does not allow copy initialisation
    explicit ECon(const int& i_m) : m{i_m} { cout<<"Calling ECon::ECon(const int&)"<<"\n";};
    
    //Casting operator of ECon to bool - Disallowing implicit conversions
    explicit operator bool() const { cout<<"Running Casting Operator to bool ()"<<"\n"; return true; }
    
    //Casting operator of ECon to float - Disallow conversions to float 
    operator float() const = delete;

};


int main()
{
    
   ECon<int> a,b;
   
   
//   ECon<int> c = b; //Error - arg constructor is explicit
   ECon<int> c(b);   //Fine
   ECon<int> d{b};   //Fine
   
   ECon<int> e{1};    //Fine
// ECon<int> f = 1;   //Error - attempting copy initialisation - calling ECon::ECon(const int&)
   
   bool n1 = (bool)e; //Fine - C-style casting bool explicitly first
   bool n2{static_cast<bool>(e)}; //Fine - safer but equivalent;
//   bool n3 = e;       //Error - it is attempting implicit conversion using operator bool()
  
//   float n3{static_cast<float>(e)}; //Error - Attempt of calling operator float() conversion
   
   return 0;
}
