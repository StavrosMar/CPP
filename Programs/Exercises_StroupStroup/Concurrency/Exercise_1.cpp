// Exercise 1 from Concurrency Utilities Chapter
//
#include <iostream>
#include <thread>


void hello() {

	std::cout<<"Hello"<<"\n";
	this_thread::sleep_for(milliseconds{1000});

}

void world() {

	std::cout<<"World"<<"\n";
	this_thread::sleep_for(milliseconds{1000});

}


int main() {

	for ( int i = 0 ; i < 100 ; i++ ) {
	
		std::thread t1{hello};
		std::thread t2{world};
	
	};

}

