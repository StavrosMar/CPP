/*
*
*    Topics covered:
*                1) Using static on objects
*                2) using thread_local with static
*
*/
//static on a variable - value visible to all threads. 

#include <iostream>
#include <thread>

using namespace std;

class klash {
private:
    string s;

public:
    
    klash(const string& s) : s{s} { cout<<"constructing "<<s<<'\n'; };
    ~klash() {cout<<"destructing "<<s<<'\n';  };
    
    void print() {
        cout<<"Value is: "<<s<<'\n';
    }
};

void klash_static(const string& s) {
    
  static klash sh{s}; //visible to all threads.
  sh.print();

}

void klash_thread_local_static(const string& s) {
    
  thread_local static klash sh{s}; //visible to this thread only,
                                   //destroyed as soon as it leaves the scope of this function.
                                   //Usefullness : if i am entering two times with the same thread  in the function the value is not touched as soon as it is initialised during the first call.
  sh.print();
    
}

int main()
{
   thread t1{klash_static,"klash_static: thread1\n"};
   thread t2{klash_static,"klash_static: thread2\n"};
  
   t1.join();
   t2.join();
   
   t1 = thread(klash_thread_local_static,"klash_thread_local_static: thread3\n");
   t2 = thread(klash_thread_local_static,"klash_thread_local_static: thread4\n");
  
   t1.join();
   t2.join();
   
   std::cout<<"Exiting main"<<'\n';
   
   return 0;
}
