/*
*
*   Topics covered:
*                1) Construct a Ring Buffer
*                2) TODO - lock free
*                3) TODO - define iterators
*
*/

#include <iostream>
#include <array>

using namespace std;

template <class T> class RingBuffer {

private:
    const unsigned int N;
    unsigned int prevN; //previous size : Needed for copy constructor
    T* A{nullptr}; // array
    unsigned int head;
    unsigned int tail;
    unsigned int count = 0;
    
    //STL interface for looping - TODO : Separate class of custom iterators.
    using const_iter = const T*;
    //implement iterators properly...
    
public:
    
    RingBuffer(const unsigned int& iN) :N{iN}, A{new T[N]}, head{0},tail{0} { prevN = N; };
    
    RingBuffer() = delete;
    
    //Copy constructor
    RingBuffer(const RingBuffer& r) :  N{r.N} { 
        
        if (this != nullptr && this->prevN!=r.N ) { //Manage resources
            delete[] A;
            this->A = new T[r.N];
            prevN = N;
        }
        
        if ( this != &r) { //Self Assignment;
        
            this->head = r.head;
            this->tail = r.tail;
            this->count = r.count;
        
            for (int i{0}; i<N; ++i) {
                this->A[i] = r.A[i];
            }   
        }
    };
    
    ~RingBuffer() { delete[] A;}
    
    //Public interface
    
    void push(const T& s); //Add smth in the buffer
    
    void pop(); //Remove last elem from the buffer
    
    T front();  //Take head from buffer
    T back();   //Take tail from buffer
    
    bool empty();
    unsigned int capacity() const;
    
    //STL interface for range-loops
    const_iter begin();
    const_iter end();

};

template <typename T> unsigned int RingBuffer<T>::capacity() const {
    return count;
};

template <typename T> T  RingBuffer<T>::front() {
    return A[head];
}

template <typename T> T  RingBuffer<T>::back() {
    return A[tail];
}

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
    RingBuffer<int> buff2(buff1);
  
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
    

    return 0;
    
}
