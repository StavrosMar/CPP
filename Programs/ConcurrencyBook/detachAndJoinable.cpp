#include <iostream>
#include <thread>
#include <stdexcept>

using namespace std;
/* Topics:
 * 		1)  Detach the thread and try assigning another thread on this object even if the thread is still busy.
 * 		    // It works fine since after detach the object does not own the thread anymore
 *
 */

//Function that runs long enough to let us experiment.
void busyFunc() {

	auto start{std::chrono::system_clock::now()};
	auto duration{std::chrono::seconds(3)};

	cout<<"Concurrent Thread Entering at: "+std::to_string((std::chrono::system_clock::to_time_t(start)))+"s\n";

	std::this_thread::sleep_for(duration);

	auto timeEnd{start+duration};

	cout<<"Concurrent Thread Resuming at: "+std::to_string(std::chrono::system_clock::to_time_t(timeEnd))+"s\n";


}

	// Test to verify that joinable returns 1 even if active thread has been detached.
	// Make it main to test
int joinableMain() {

	std::thread t1{busyFunc};
	t1.detach();
	//After detach t1 does not own the thread anymore!!!

	t1 = std::thread([]{cout<<"lala\n";});

	std::this_thread::sleep_for(std::chrono::seconds(10));

	if (!t1.joinable()) {
		cout<<"t1 thread still busy\n";
	} else {
		t1.join();
	}

	std::this_thread::sleep_for(std::chrono::seconds(5));

	cout<<"Terminating main at: "+std::to_string((std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())))+"s\n";

	return 0;

}
