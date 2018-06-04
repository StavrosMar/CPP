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
	// TODO : Reference way - book.
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

/*// 1) Unit Test for Case 1.
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

