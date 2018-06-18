/* Exercise for C++ concurrency */

#include <thread>
#include <iostream>

//Call with function
void Kalhspera(const int& a) {
	
	/*Note : "\n" in the end after operator is not synchronised with the rest!!
	i.e. the change line command on stream-out is added after both threads have finished their execution*/
	std::cout<<"Sketo Kal\n"<<"\n";

}

//Call with function object
class ObjectKalhspera {

public:
	void operator()(const int& i) {

		std::cout<<"ObjectKalhspera\n"<<"\n";

	}
};

/*
int main() {

	std::thread t1{Kalhspera,2};  	   // function
	std::thread t2{ObjectKalhspera(),1}; // initialise with func object - pay attention to initialisers used - p17
	t1.join();
	t2.detach();


	return 0;

}
*/
