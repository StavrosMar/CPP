#include <iostream>

/* Topics : 
            1) Building adaptor for C-style array for use with stl-container like for-loop
            2) const in return value of Function is useless for non-user defined types.
*/

using namespace std;

template <typename T, size_t N> class AdapterFor {

public:
    using iterator = T* ; // Modern C++ - could do typedef
    const T* m_array;                     //pointer to actual array;
    
    AdapterFor(const T* array) : m_array{array} {}; 
    
    //const in return value is useless - it works only for userDefined types i.e. not for T = int.
    //useless means it does nothing  - the container can be changed from the outside - dangerous
    const iterator  begin() const {
        return m_array;
    }
    
    iterator end() const{
        
        return (m_array + N);            //pointer after array[N]
    }
};

int main()
{
   
  int A[3] = {1,3,5};
  
  AdapterFor<int,3> arr{A};
   
  for (auto x : arr) {
       
       std::cout<< x << "\n";
  }
  
  //Test const iterators - Attempt to modify container
  auto i = arr.begin();
  *i = 10; // Spits out error - expected since we return const_staviterator.
  
  return 0;
}
