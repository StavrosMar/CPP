#include <iostream>
#include <thread>

using namespace std;

/* Topics:
 * 		1) Ensure thread safety so that we cannot drop a running thread.
 * 		   Protection from assigning if current thread has not finished execution - cannot drop a thread (2.6 - scoped_thread)
 */

//scoped_thread
class scoped_thread {
private:
	std::thread _t;

public:
	/*Trying to move thread t.
	If he is busy, the move will fail, so the construction of _t will fail.
	Then it will not be joinable*/
	scoped_thread( std::thread& t) : _t(std::move(t)) {

		if(!_t.joinable()) {
			throw std::logic_error("NO thread - thread move failed");
		}

	};

	scoped_thread(const scoped_thread&) = delete;
	scoped_thread& operator=(const scoped_thread&) = delete;

};

//Function that runs long enough to let us experiment.
void busyFunc2() {

	auto start{std::chrono::system_clock::now()};
	auto duration{std::chrono::seconds(3)};

	cout<<"Concurrent Thread Entering at: "+std::to_string((std::chrono::system_clock::to_time_t(start)))+"s\n";

	std::this_thread::sleep_for(duration);

	auto timeEnd{start+duration};

	cout<<"Concurrent Thread Resuming at: "+std::to_string(std::chrono::system_clock::to_time_t(timeEnd))+"s\n";


}

int main() {

	std::thread t1(busyFunc2);
	scoped_thread sthr{t1};

}
