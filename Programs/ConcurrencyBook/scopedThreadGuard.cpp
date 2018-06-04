#include <iostream>
#include <thread>

using namespace std;

/* Topics:
 * 		1) Ensure thread safety so that we cannot drop a running thread.
 *
 */

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

/*
	// Unit Test 2) - constructing a threadguard from a
int main() {

	std::thread t1{busyFunc};

	thread_kerveros tguardBusy{t1};
	thread_kerveros tguard2{t1};

	std::thread t2{testJoinable};

	return 0;
} */
