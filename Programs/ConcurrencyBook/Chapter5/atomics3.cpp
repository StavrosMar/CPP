/*
 * 	Topics covered:
 * 				1)  understand better atomic operations / lock free stuff (?)
 *
 *
 */

#include <atomic>
#include <string>
#include <iostream>
#include <thread>
#include <atomic>
#include <cassert>
#include <vector>
#include <chrono>

using namespace std;

std::atomic<int> Guard{0};
int Payload = 0;
int pp{0};

void thread3_1() {

	Payload = 42;

	Guard.store(1, std::memory_order_release);
	auto t1_storefinished=chrono::high_resolution_clock::now().time_since_epoch().count();
		std::cout<<"t1 "+to_string(t1_storefinished)+'\n';

}

void thread3_2() {
	auto t2_loadstarting=chrono::high_resolution_clock::now().time_since_epoch().count();
	std::cout<<"t2 "+to_string(t2_loadstarting)+'\n';
	int g{0};
	while(!g) { g = Guard.load(memory_order_relaxed); };
		if (g != 0)
		    pp = Payload;
}

int atomic3_main() {

	std::thread t1(&thread3_2);
	std::thread t2(&thread3_1);

	t1.join();
	t2.join();


	std::cout<<pp<<'\n';
	return 0;
}


