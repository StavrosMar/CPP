#include <iostream>

//Topics covered:
/* 
    1) Explicit constructor
    2) 

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
    explicit ECon(const int& i_m) : m{i_m} { cout<<"Calling ECon::ECon(const int&)";};

};


int main()
{
    
   ECon<int> a,b;
   
   
   //ECon<int> c = b; //Error - arg constructor is explicit
   ECon<int> c(b);   //Fine
   ECon<int> d{b};   //Fine
   
   ECon<int> e{1};    //Fine
   //ECon<int> f = 1; //Error - attempting copy initialisation - calling ECon::ECon(const int&)
   //Econ<int> 
   
   return 0;
}
