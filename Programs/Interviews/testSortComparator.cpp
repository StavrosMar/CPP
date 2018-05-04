#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Compare object for loading inside functions requiring that.
template<typename T> class CompStavros {

public:

    CompStavros() {
        // default constructor 
        cout<< "Creating Object of Type CompStavros" << std::endl;
    }
    
    

    bool operator()(const T& obj1, const T& obj2) {
        
        return ((obj1 > obj2 ) ? true : false);
        
    }
};

using namespace std;

int main()
{
    
    vector<int> vec1{1,2,3,4,5,6};
    
    sort(vec1.begin(), vec1.end(),CompStavros<int>());
    
    std::cout<<vec1[0]<<std::endl;
   
   return 0;
}
