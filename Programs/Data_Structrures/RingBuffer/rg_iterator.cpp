/*
*
*   Topics covered:
*                1) Iterator for my ringBuffer
*                2) Eliminate code for iterator and const iterator - valid for both
*                3) TODO- complete operators
*
*/

#include <iostream>

using namespace std;

template <typename T> class rg_iterator {

private:
    T*            _ptr;
    int           _indx;
    const size_t _size;
    
public:

    rg_iterator(T* ptr_start,const size_t& N) : _ptr{ptr_start}, _indx{0}, _size{N} {};

    T& operator*() {
        return *_ptr;
    }
    
    void operator++() {
        int indx_after = (_indx+1)%_size;
        int diff = indx_after - _indx;
        _indx = indx_after;
        
        _ptr = _ptr+diff;
    }
    
    
    
};


int main()
{
   //Test ++ and * operators
   int a[2]={10,20};
   rg_iterator<int> it{&a[0],2};
   
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
   rg_iterator<const int> it2{&b[0],2};
   cout<<"=== b: Increasing iterator using ++it==="<<endl;
   cout<<"*it="<<*it2<<endl;
   ++it2;
   cout<<"*it="<<*it2<<endl;
   ++it2;
   cout<<"*it="<<*it2<<endl;
   
   cout<<"===Const check - Altering contents test using *it==="<<endl;
   //*it2 = 39; //Good - compile-time error
   cout<<"b is now : "<<b[0]<<"  "<<b[1]<<endl;
   
   
   
   return 0;
}
