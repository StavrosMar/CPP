/*
*
*   Topics covered:
*                1) Iterator for my ringBuffer
*                2) TODO - eliminate code for iterator and const iterator
*                3) 
*
*/

#include <iostream>

using namespace std;

template <typename T> class rg_iterator {

private:
    T*            _ptr;
    const size_t _size;
    
public:

    rg_iterator(T* ptr_start, size_t& N) : _ptr{ptr_start}, _size{N} {};

    T& operator*() {
        return *_ptr;
    }
    
    void operator+() {
        _ptr = ++_ptr%_size;
    }
    
};


int main()
{
   //Unit test for iterator here.
}
