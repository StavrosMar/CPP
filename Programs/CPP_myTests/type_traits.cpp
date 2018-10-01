
/*
*
*
*       Topics covered:
*                       1) traits example - providing implementations depending
*                          on type on compile time
*
*/

#include <iostream>

using namespace std;

class simple {
    // this is a simple session
};

class kraken {
    //this is the kraken session.
};

//Providing default implementation
template <class T> class is_encrypted {
public:
    static const bool val = false;    
};

//Specialisation for kraken type objects.
template<> class is_encrypted<kraken> {
public:
    static const bool val = true;
};

int main()
{
    
    cout<<is_encrypted<simple>::val<<endl;
    cout<<is_encrypted<kraken>::val<<endl;
    
   return 0;
}
