#include <iostream>
#include <thread>

using namespace std;

// Move constructor on thread is called here implicitly.
void f(std::thread t) { cout<<"Running f(std::thread)"<<"\n";};

void threadFun() { cout<<"Running threadFun"<<"\n"; };
/*
int main() {


  //f(std::thread(threadFun));

  std::thread t1{threadFun};

  f(std::move(t1));

 return 0;

}
*/
