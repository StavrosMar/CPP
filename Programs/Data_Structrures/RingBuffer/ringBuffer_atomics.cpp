/*
*               Stripped down implementation of ringBuffer.cpp 
*
*   Topics covered :
*                1) TODO - fix pop synchronisation
*
*/

#include <iostream>
#include <array>
#include <atomic>
#include <thread>
#include <vector>

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
    
  //TEMP-DEBUG-REMOVE
  bool entered = false;
  for (;;) {
  //TEMP-DEBUG-REMOVE
    if (g_threadStart) {
    
        //Core
       bool changed = false;
               
            unsigned int h = head.load(std::memory_order_acquire);
            if ( count.load(std::memory_order_acquire) < N ) {
                while(!head.compare_exchange_weak(h,(h+1)%N,std::memory_order_acq_rel));
                auto c =  count.load(std::memory_order_acquire) ;
                if (c < N-1 )  {
                    count.compare_exchange_weak(c,c+1,std::memory_order_acq_rel);
                    A[h] = s;
                    cout<<"Pushed : "+to_string(s)+" Head is"+to_string(head.load(std::memory_order_acquire))+"\n";
                }
            }

        //}
        entered = true;
    }
     
    //TEMP-DEBUG-REMOVE
    if (entered) {
         break; //Stop the loop
     }
   }

}

template <typename T> void RingBuffer<T>::pop() {
  //TEMP-DEBUG-REMOVE
  bool entered = false;
  for (;;) {
  //TEMP-DEBUG-REMOVE
    if (g_threadStart) {
        
       //Core
       auto t  = tail.load(std::memory_order_acquire);
        if ( count.load(std::memory_order_acquire) != 0) {
             bool changed = tail.compare_exchange_weak(t,(t+1)%N,std::memory_order_acq_rel);
             auto c =  count.load(std::memory_order_acquire) ;
             if (changed && c != 0) { //Load / Syncronise count before subtracting && only do it if the value was successfully changed
                    count.compare_exchange_weak(c,c-1,std::memory_order_acq_rel);
                    std::cout<<"--Removing Element,  Count = "+to_string(count.load(std::memory_order_acquire))+", "
                    +"TailIndex after removal ="+to_string(tail.load(std::memory_order_acquire))+'\n';
             }
        } else {
            std::cout<<"--Buffer Empty--"<<'\n';
        }
        
        entered = true;
     }
     
     //TEMP-DEBUG-REMOVE
     if (entered) {
         break; //Stop the loop
     }
   }
   
}

int main() {
    
    //Initialise some values
    const int BUFF_SIZE{10};
    RingBuffer<int> buff1(BUFF_SIZE);
  
    //Push Test
    vector<std::thread> threads;
    
    for (int i=0 ; i<BUFF_SIZE; ++i) { //Make threads
        threads.push_back(std::move(thread(&RingBuffer<int>::push,&buff1,i+10))); //call push of object buff1 with argument i.
    }
  
    buff1.g_threadStart = true; //Fire all threads to start.
    
    for (auto& t : threads) { //Join the results.
        t.join();
    }
    
    /*
    //Pop Test
    //buff1.push(12);
    //buff1.push(122);
    
    std::thread t1{&RingBuffer<int>::pop,&buff1};
    std::thread t2{&RingBuffer<int>::pop,&buff1};
    std::thread t3{&RingBuffer<int>::pop,&buff1};
    std::thread t4{&RingBuffer<int>::pop,&buff1};
    std::thread t5{&RingBuffer<int>::pop,&buff1};
    std::thread t6{&RingBuffer<int>::pop,&buff1};
    
    buff1.g_threadStart = true;
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    */
    
    //Pop-Push test combined.

}
