/* Topics:
	1) Access to data created by new after main program exits and thread is detached and still running. p18
*/

#include <iostream>
#include <thread>

class Func {

public:

	Func() = default;

	~Func() {
		std::cout<<"Destructing Object";
		//So if we do not do delete the object is still accessible from the detached thread.
		//delete this;
	};
	void operator()() {

		std::cout<<"Still Alive";
	}


};

Func* interm() {

	auto objFun = new Func();
	std::thread threadLoc{*objFun};
	threadLoc.detach();

	return objFun;
}


int main() {

	interm();
	std::cout<<"Main running";

}
