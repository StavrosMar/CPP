#include <iostream>
#include <thread>
#include <stdexcept>

using namespace std;
/* Topics:
 * 		1) Guaranteeing thread join with RAII - taking care of main() throwing exceptions before manually joinning the thread
 * 		2) Protection from assigning if current thread has not finished execution - cannot drop a thread (2.6 - scoped_thread)
 */

void throwException() {

	cout<<"Throwing Exception"<<"\n";
	throw std::runtime_error("RuntimeError");
}


void printSomething(string day) {

	cout<<"Printing = "<< day <<"\n";
}

//Building wrapper for thread to catter for exceptions
class thread_kerveros {
private:
	thread _t1;

public:

	//Construct from thread;
	// TODO : Reference way inside the book.
	explicit thread_kerveros(thread& t1) : _t1(std::move(t1)) {

		// -- Issue 2
		if (!_t1.joinable()) {
			throw std::logic_error("Current thread still busy - Construction Failed");
		}
		cout<<"constucting with lvalue"<<"\n";
	};

	explicit thread_kerveros(thread&& t1) : _t1(std::move(t1)) {

		// -- Issue 2
		if (!_t1.joinable()) {
					throw std::logic_error("Current thread still busy - Construction Failed");
		}
		cout<<"Constructing with rvalue"<<"\n";
	};

	//Copying and assignement operations should be disabled;
	thread_kerveros(const thread_kerveros&) = delete;
	thread_kerveros& operator=(const thread_kerveros&) = delete;

	// Destructor - make sure we join the thread
	~thread_kerveros() {

		if ( _t1.joinable() ) { _t1.join();}

	};

};

/*// 1)
int main() {


	// --1 Issue : Exception thrown before we reach join
	thread t1{printSomething,"Wednesday"};
	//throwException();
	t1.join(); //-- // This is never run


	// -- Solution RAII :
	thread t2{printSomething,"Friday"};
		//thread_kerveros kerv{std::move(t2)};
	thread_kerveros kerv{t2};
	throwException();

		//... and t2 is joined on its destruction.

}*/

// 2)  - write test for case 2  - build a busy function and assign thread to get the logic error.
// play with detach as well  - detach the thread and try assigning another thread on this object.

void busyFunc() {

	auto start{std::chrono::system_clock::now()};
	auto duration{std::chrono::seconds(4)};

	cout<<"Concurrent Thread Sleeping at: "+std::to_string((std::chrono::system_clock::to_time_t(start)))+"s\n";

	std::this_thread::sleep_for(duration);

	auto timeEnd{start+duration};

	cout<<"Concurrent Thread Resuming at: "+std::to_string(std::chrono::system_clock::to_time_t(timeEnd))+"s\n";


}

int main() {

	std::thread t1{busyFunc};
	t1.detach();
	std::this_thread::sleep_for(std::chrono::seconds(2));

	if (!t1.joinable()) {
		cout<<"t1 thread still busy\n";
	}

}
