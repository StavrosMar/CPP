/*
*
*   Topics covered:
*                1) Iterator for my ringBuffer
*                2) Consolidate Eliminate code for iterator and const iterator
*                3) TODO - complete operators
*                4) Equality / conversions between const iter and iter should work
*
*/

#include <iostream>

using namespace std;

template <typename T, bool Const = false> class rg_iterator { //by default non-const iterator
   
    //Friend declaration necessary to make members visible to copy/conversion constructor.
    friend class rg_iterator<T, true>;
    
    typedef typename std::conditional<Const, const T, T>::type IterType; 
    using pointer = IterType*;
    using reference = IterType&;
    
    T*            _ptr;
    int           _indx;
    const size_t _size;
    
  public:  
 
    //Constructors
    rg_iterator(T* ptr_start,const int& index, const size_t& N) : _ptr{ptr_start}, _indx{index}, _size{N} {};
    rg_iterator(const rg_iterator<T,false>& i) : _ptr{i._ptr}, _indx{i._indx}, _size{i._size} {}; //Very important to add template parameters - A temporary object is created before conversion below on ==
    rg_iterator() = delete;

    reference operator*() {
        return *_ptr;
    }
    
    void operator++() {
        int indx_after = (_indx+1)%_size;
        int diff = indx_after - _indx;
        _indx = indx_after;
        
        _ptr = _ptr+diff;
    }
    
    //Here we are forcing a conversion - thus the copy constructor is called and needed.
    friend bool operator==(const rg_iterator& x,
                          const rg_iterator& y) {
      return (x._ptr == y._ptr && x._indx == y._indx && x._size == y._size) ;
   }
    
};


int main()
{
   //Test ++ and * operators
   int a[2]={10,20};
   rg_iterator<int> it{&a[0],0,2};
   
   cout<<"===Increasing iterator using ++it==="<<endl;
   cout<<"*it="<<*it<<endl;
   ++it;
   cout<<"*it="<<*it<<endl;
   ++it;
   cout<<"*it="<<*it<<endl;
   
   cout<<"===Non const check - Altering contents test using *it==="<<endl;
   *it = 39;
   cout<<"a is now : "<<a[0]<<"  "<<a[1]<<endl;
   
   //Test const iterator
   cout<<"\n=== Const Iterator - Testing ===\n"<<endl;
   int b[2]={10,20};
   rg_iterator<int,true> it2{&b[0],0,2};
   cout<<"=== b: Increasing iterator using ++it==="<<endl;
   cout<<"*it="<<*it2<<endl;
   ++it2;
   cout<<"*it="<<*it2<<endl;
   ++it2;
   cout<<"*it="<<*it2<<endl;
   
   cout<<"===Const check - Altering contents test using *it==="<<endl;
   //*it2 = 39; //Good - compile-time error
   cout<<"b is now : "<<b[0]<<"  "<<b[1]<<endl; 
   
   //Relationship between const and non-const
   cout<<"\n=== Iterator - Const iterator relationship ==="<<endl;
   rg_iterator<int,true> it3{&a[0],0,2};
   cout<<"Equal iterators? : "<<(it==it3)<<endl; //Problem !! - Need to explicitly define operators for handling const and non-const iterators.
   
   return 0;
}
