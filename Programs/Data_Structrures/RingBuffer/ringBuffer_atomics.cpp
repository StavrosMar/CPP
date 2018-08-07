/*
*               Stripped down implementation of ringBuffer.cpp 
*
*   Topics covered :
*                1) Pop has become lock-free.
*                2) TODO - push lock free
*                3) Compare Pop with a Lock-based - mutex or spinlock implementation.
*
*/

#include <iostream>
#include <array>
#include <atomic>
#include <thread>

using namespace std;

template <class T> class RingBuffer {

private:
    const unsigned int N;
    T* A{nullptr}; // array
    atomic<unsigned int> head;
    atomic<unsigned int> tail;
    atomic<unsigned int> count;
    
    //STL interface for looping - TODO : Separate class of custom iterators.
    using const_iter = const T*;
    //implement iterators properly...
    
public:
    
    ////TEMP-REMOVE
    bool g_threadStart = false; //To syncronise threads
    
    //Constructors - Destructor
    RingBuffer(const unsigned int& iN) :N{iN}, A{new T[N]} {
         //atomics initialisatinos
        count.store(0);
        tail.store(0);
        head.store(0);
    };
    
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
    
    unsigned int c = count.load();
    unsigned int h = head.load();
    
    /* NOT THREAD-SAFE  - TODO */
    if (c<N) {
        A[h] = s;
        h = ++h%N;
        ++c;
        count.store(c,std::memory_order_release);
        
    } else {
        //Output to log...
        cout<<"Error : Buffer is full - discarding data : "<<'\n';
    }

}

template <typename T> void RingBuffer<T>::pop() {
   //TEMP-REMOVE - for synchronising all open threads.
  bool entered = false;
  for (;;) {
  //TEMP-REMOVE
    if (g_threadStart) {
       
        
        
        auto t  = tail.load(std::memory_order_acquire);
        if ( count.load(std::memory_order_acquire) != 0) {
             bool changed = tail.compare_exchange_weak(t,(t+1)%N,std::memory_order_acq_rel);
             //Load / Syncronise count before subtracting && only do it if the value was successfully changed
             if (changed && count.load(std::memory_order_acquire) != 0) {
                    //count.compare_exchange_weak(c,c-1,std::memory_order_acq_rel);
                    count.fetch_sub(1,std::memory_order_release);
                    std::cout<<"--Removing Element,  Count = "+to_string(count.load(std::memory_order_acquire))+", "
                                    +"TailIndex after pop ="+to_string(tail.load(std::memory_order_acquire))+'\n';
             }
        } else {
            std::cout<<"--Buffer Empty--"<<'\n';
        }
        entered = true;
     }
     
     //TEMP-REMOVE
     if (entered) {
         break; //Stop the loop
     }
   }
   
}

//Testing thread//
int main() {
    
    //Create a buffer.
    RingBuffer<int> buff1(100);
  
    //Push a value into a buffer
    buff1.push(12);
    buff1.push(122);
    
    //Spawn 6 threads that try to pop a value.
    std::thread t1{&RingBuffer<int>::pop,&buff1};
    std::thread t2{&RingBuffer<int>::pop,&buff1};
    std::thread t3{&RingBuffer<int>::pop,&buff1};
    std::thread t4{&RingBuffer<int>::pop,&buff1};
    std::thread t5{&RingBuffer<int>::pop,&buff1};
    std::thread t6{&RingBuffer<int>::pop,&buff1};
    
    //Make sure they start at the same time
    buff1.g_threadStart = true;
    
    //Join the results.
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    
}
