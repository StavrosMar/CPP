/*
 * 	Topics covered:
 * 				1)  understand better atomic operations / lock free stuff (?)
 *
 *
 */

#include <string>
#include <iostream>
#include <thread>
#include <atomic>
#include <cassert>
#include <vector>

std::atomic<int> zz; //defaulted to 0;

int atomic1_main() {

	std::cout<<zz.load()<<"\n";

	return 0;
}


