#include <iostream>

/* Topics : 
            1) Building adaptor for C-style array for use with STL-container like for-loop
            2) Making iterators const so that it is impossible to modify the array.
*/

using namespace std;

template <typename T, size_t N> class AdapterFor {

public:
    using const_staviterator = const T* ; // Modern C++ - could do typedef
    const T* m_array;                     //pointer to actual array;
    
    AdapterFor(const T* array) : m_array{array} {}; 
    
    const_staviterator begin() const {
        return m_array;
    }
    
    const_staviterator end() const{
        
        return (m_array + N);            //pointer after array[N]
    }
};

// Unitary test
int main()
{
   
  int A[3] = {1,3,5};
  
  AdapterFor<int,3> arr{A};
  
  // STL-container like Loop
  for (auto x : arr) {
       
       std::cout<< x << "\n";
  }
  
  //Test const iterators - Attempt to modify container
  auto i = arr.begin();
  *i = 10; // Spits out error - expected since we return const_staviterator.
  
  return 0;
}
