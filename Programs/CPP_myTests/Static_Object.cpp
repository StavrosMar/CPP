/*
*
*    Topics covered:
*                1) Using static on objects
*                2) using thread_local with static
*
*/
//static on a variable - value visible to all threads. 

#include <iostream>

using namespace std;

class klash {
 public: 
 
    
    klash() { cout<<"constructing"<<'\n'; };
    ~klash() {cout<<"destructing"<<'\n';  };
};

void klash_static() {
    
  static klash sh; //visible to all threads.
  //  cout<<sta;
}

void klash_thread_local_static() {
    
    
}

int main()
{
   cout << "Hello World" << endl;
   /*Calling two times klash_static
        - sh created the first time is kept along*/
   klash_static();
   /*     - second call has no effect - sh has already been constructed.*/
   klash_static();
   
 //  cout<<sta<<'\n';
   return 0;
}
