/* Exercise for C++ concurrency */

#include <thread>
#include <iostream>

//Call with function
void Kalhspera(const int& a) {
	
	std::cout<<"nana"<<'\n';

}

//Call with function object
class ObjectKalhspera {

public:
	void operator()(const int& i) {

		std::cout<<"ObjectKalhspera"<<'\n';

	}
};


int main() {

	std::thread t1{Kalhspera,2};  	   // function
	std::thread t2{ObjectKalhspera(),1}; // initialise with func object
	t1.join();
	t2.detach();
	return 0;

}
