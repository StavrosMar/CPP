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

std::atomic<int> data[5];
std::atomic<bool> sync1{false}, sync2{false};
std::atomic<int> go{0};

void thread_1() {

	data[0].store(42,std::memory_order_relaxed);
	data[1].store(97,std::memory_order_relaxed);
	data[2].store(17,std::memory_order_relaxed);
	data[3].store(-141,std::memory_order_relaxed);
	data[4].store(2003,std::memory_order_relaxed);

	sync1.store(true,std::memory_order_relaxed);

}

void thread_2() {
	while(!sync1.load(std::memory_order_relaxed));
	sync2.store(true,std::memory_order_relaxed);

}

void thread_3() {

	while(!sync2.load(std::memory_order_relaxed));

	assert(data[0].load(std::memory_order_relaxed)==42);
	assert(data[1].load(std::memory_order_relaxed)==97);
	assert(data[2].load(std::memory_order_relaxed)==17);
	assert(data[3].load(std::memory_order_relaxed)==-141);
	assert(data[4].load(std::memory_order_relaxed)==2003);

}

int atomic2_main() {

	std::thread t1(&thread_1);
	std::thread t2(&thread_2);
	std::thread t3(&thread_3);

	go=1;

	t3.join();
	t2.join();
	t1.join();


	return 0;
}


