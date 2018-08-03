/*
*
*   Topics covered:
*                1) Construct a Ring Buffer
*                2) TODO - lock free
*
*/

#include <iostream>
#include <array>

using namespace std;

template <class T> class RingBuffer {

private:
    const unsigned int N;
    unsigned int prevN; //Variable for copy constructor
    T* A{nullptr}; // array
    unsigned int head;
    unsigned int tail;
    
public:
    
    //Constructors
    RingBuffer(const unsigned int& iN) :N{iN}, A{new T[N]} { prevN = N; };
    RingBuffer() = delete;
    RingBuffer(const RingBuffer& r) :  N{r.N} { 
        
        if (this != nullptr && this->prevN!=r.N ) { //Manage resources
            delete[] A;
            this->A = new T[r.N];
            prevN = N;
        }
        
        if ( this != &r) { //Self Assignment;
        
            this->head = r.head;
            this->tail = r.tail;
        
            for (int i{0}; i<N; ++i) {
                this->A[i] = r.A[i];
            }   
        }
    };
    
    //Destructor;
    ~RingBuffer() { delete[] A;}
    
    //Interface functions
    void push(const T& s); //Add smth in the buffer
    void pop(); //Remove last elem from the buffer
    T front(); //Take head from buffer
    T back();   //Take tail from buffer
    bool empty();
    size_t size();
    
    //implement iterators...

};

template <typename T> T  RingBuffer<T>::front() {
    return A[head];
}

int main() {
    
    //Test construction
    RingBuffer<int> buff1(21);
    RingBuffer<int> buff2(buff1);
  
    //Test functions....
  
    return 0;
    
}
