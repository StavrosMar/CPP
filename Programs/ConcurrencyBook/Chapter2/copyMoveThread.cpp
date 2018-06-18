#include <iostream>
#include <thread>

using namespace std;

/*
 * 	Topics:
 * 		  1) Explore passing std::thread as an argument to a function (i.e. its copy has been disabled)
 * 		  	 I could do it with a custom object as well to try
 *
 */

// Move constructor on thread is called here implicitly.
void f(std::thread t) { cout<<"Running f(std::thread)"<<"\n";};

void threadFun() { cout<<"Running threadFun"<<"\n"; };

//Make it main to run
int moveCopymain() {

  //Call with temporary
  f(std::thread(threadFun));

  //Call with variable
  std::thread t1{threadFun};
  f(std::move(t1));

 return 0;

}
