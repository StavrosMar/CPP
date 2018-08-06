/*
*               Stripped down implementation of ringBuffer.cpp 
*
*   Topics covered :
*                1) TODO - lock free
*                3) TODO - define iterators
*
*/

#include <iostream>
#include <array>

using namespace std;

template <class T> class RingBuffer {

private:
    const unsigned int N;
    T* A{nullptr}; // array
    unsigned int head;
    unsigned int tail;
    unsigned int count = 0;
    
    //STL interface for looping - TODO : Separate class of custom iterators.
    using const_iter = const T*;
    //implement iterators properly...
    
public:
    
    //Constructors - Destructor
    RingBuffer(const unsigned int& iN) :N{iN}, A{new T[N]}, head{0},tail{0} {};
    RingBuffer() = delete;
    RingBuffer(const RingBuffer& r) = delete;
    ~RingBuffer() { delete[] A;}
    
    //Public interface
    void push(const T& s); //Add smth in the buffer
    void pop(); //Remove last elem from the buffer
    unsigned int capacity() const;

};

template <typename T> unsigned int RingBuffer<T>::capacity() const {
    return count;
};

template <typename T> void RingBuffer<T>::push(const T& s) {
    
    if (count<N) {
        A[head] = s;
        head = ++head%N;
        ++count;
        
    } else {
        //Output to log...
        cout<<"Error : Buffer is full - discarding data : "<<'\n';
    }
}

template <typename T> void RingBuffer<T>::pop() {
    if (count!=0) {
        tail = ++tail%N;
        --count;
    }
}

int main() {
    
    const int buffSize{4};
    RingBuffer<int> buff1(buffSize);
    //RingBuffer<int> buff2(buff1);
  
    buff1.push(1);
    buff1.push(4);
    buff1.push(5);
    buff1.push(6);
    buff1.pop();
    buff1.pop();
    buff1.push(8);
    
    //Need custom operators for iterators.
   // for (auto elem : buff1) {
    //    cout<<"Elem"<<elem<<'\n';
    //}
}
