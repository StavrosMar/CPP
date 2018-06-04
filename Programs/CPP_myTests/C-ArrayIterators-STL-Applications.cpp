#include <iostream>
#include <algorithm>

/* Topics : 
            1) Building adaptor for C-style array for use with stl-container like for-loop
            2) Taking advantage of sort (O(NlogN) by using the wrapper for the iterators
*/

using namespace std;

template <typename T, size_t N> class AdapterFor {

public:
    using iterator = T* ; // Modern C++ - could do typedef
    T* m_array;                     //pointer to actual array;
    
    AdapterFor(T* array) : m_array{array} {}; 
    
   iterator  begin() const {
        return m_array;
    }
    
    iterator end() const{
        
        return (m_array + N);            //pointer after array[N]
    }
};

template <typename T, size_t N> void printArray(const AdapterFor<T,N>& arr) {
    
    for (auto x : arr) {
       
       std::cout<< x << "\n";
  }
    
}

int main()
{
   
  int A[3] = {1,33,5};
  
  AdapterFor<int,3> arr{A};
   
  cout<<"Array before Sorting"<<"\n";
  printArray(arr);
  
  std::sort(arr.begin(),arr.end());
  cout<<"Array after Sorting"<<"\n";
  printArray(arr);
  
  //Test const iterators - Attempt to modify container
  auto i = arr.begin();
  *i = 10; // Modify is sucessful since we are not using const iterators in the container
  
  return 0;
}
