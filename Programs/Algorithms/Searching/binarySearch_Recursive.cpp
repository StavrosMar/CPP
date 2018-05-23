
//binarySearch :  Recursive implementation

#include <iostream>

using namespace std;

int binarySearch(const int* A, const int& lo, const int& hi, const int& x) {
    
    
    if (hi>=lo) {
    
    int mid = (lo + hi) /2;
    
    if (A[mid] == x) {
        
        return mid;
        
    } else if ( A[mid] > x) {
        
        return binarySearch(A, lo, mid-1,x);
        
    } else {
        return binarySearch(A,mid+1,hi,x);
    }
    
    }
    
    return -1;
}


int main()
{

    int sizeA{10};
    int A[sizeA] = { 1,2,3,4,5,6,7,8};
    cout<<binarySearch(A,0,sizeA-1,5)<<"\n";
    
   
   return 0;
}
