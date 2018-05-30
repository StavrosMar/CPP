#include <thread>
#include <functional>
#include <iostream>
#include <type_traits>

using namespace std;

//Need function with reference arg to return data to main  - otherwise even with std::ref it cannot copy
template <class T> void tcl(T& str) {

	//Just change the string
	cout<<"Calling tcl T& str"<<"\n";
	str += "+Stavros";

}

template <class T> void tclNoRef(T str) {

	//Just change the string
	cout<<"Calling tcl T str"<<"\n";
	str += "+Stavros";

}

/*
int main() {


	//----// Case - Implicit conversions

	char s2[20] = "Hello";
	//Convert to string before passing to thread - safe if we decide to detach the thread.
	//Note : tclNoRef is not taking a reference as argument. If changed to tcl - thread constructor throws error. Need to use std::ref wrapper in that case. See below.
	std::thread t2{tclNoRef<string>, std::string{s2}};

	t2.detach();

	//----// Case - Modifying data inside the thread and returning them to main.

	string s1{"Salma"};
	cout<<"s1: Before thread started: "<<s1<<endl;

	// Using std::ref as wrapper for object s2 - so that s1 is modified and returned.
	std::thread t1{tcl<string>,std::ref(s1)};

	t1.join();
	cout<<"s1: After thread finished: "<<s1<<endl;

	//----// Case - Using std::ref for function not taking references

	// Note :  Implicit casting allowed internally on invoke.....
	std::thread t3{tclNoRef<string>, std::ref(s1)};
	t3.detach();

	//-----//Case - std::ref on temporary objects does not work

	// : std::ref does not work on temporary objects !! - do example - makes sense - the pointer to them is temporary / r-values
	//std::thread t4{tcl<string>,std::ref(std::string(s1))};

	return 0;
}*/
