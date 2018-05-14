#include <iostream>

// Defining - Deleting constructors 

using namespace std;

template <typename T> class ECon {

private:
int m{0};

public:

    //No arg constructor needed in case i define copy constructors
   ECon() = default;
    
    ECon(const ECon&) = delete ;
    ECon& operator=(const ECon&) = delete;

};


int main()
{
    
   ECon<int> a,b;
   // Calling deleted operator - error thrownn expected
   a = b;
   
   // Calling deleted constructor - error thrown expected
   ECon<int> c{b};
   ECon<int> d = b;
   
   return 0;
}
