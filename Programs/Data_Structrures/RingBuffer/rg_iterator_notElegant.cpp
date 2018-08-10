/*
*
*   Topics covered:
*                1) Iterator for my ringBuffer
*                2) Eliminate code for iterator and const iterator - valid for both
*                3) TODO - complete operators
*                4) TODO - equality / conversions between const iter and iter should work
*
*/

#include <iostream>

using namespace std;

template <typename T> class rg_iterator {

private:
    T*            _ptr;
    int           _indx;
    const size_t _size;
    
    using pointer = T*;
    using reference = T&;
    
public:
    

    rg_iterator(T* ptr_start,const int& index, const size_t& N) : _ptr{ptr_start}, _indx{index}, _size{N} {};
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
    
    typedef typename std::conditional<std::is_const<T>::value, T, const T>::type type ; 
    
    bool operator==(const rg_iterator<type>& it2) {
        
        bool retval{false};
        if (this->_ptr == it2._ptr) { //Problem - i need to to make each class friend of the other ... getting complicated and byte hungry.......
            retval = true;
        }
        return retval;
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
   rg_iterator<const int> it2{&b[0],0,2};
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
   rg_iterator<const int> it3{&a[0],0,2};
   cout<<"Equal iterators? : "<<(it==it3)<<endl; //Problem !! - Need to explicitly define operators for handling const and non-const iterators.
   
   return 0;
}
