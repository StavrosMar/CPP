// This file is to validate that we can have an array
// of objects of generic type - i.e. array of contiguously arranged elements of type object.
// The example is using object type = vector

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> Nikos[2] = { vector<int>({1,2,3}), vector<int>({6,57,6})};
    
    for (int i=0 ; i<=9 ; ++i) {
        
        for (auto x : Nikos[i]) {
            
            cout<<x<<endl;
        }
        
    }
    
    return 0;
}
