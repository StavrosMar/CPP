#include <thread>
#include <functional>
#include <iostream>

using namespace std;

//TODO : passing by reference is ruining it find why - in the book he is passing it fine - check also testref copied from example
template <class T> void stavros(T str) {

	//Just change the string
	str += "-inThread";

}

/*
int main() {

	char s1[20] = "Hello";
	cout<<"Before thread started"<<s1<<endl;

	//Convert to string before passing to thread - safe if we decide to detach the thread.
	std::thread t1{stavros<string>,std::ref(std::string(s1))};

	t1.join();
	cout<<"After thread finished= "<<s1<<endl;

	return 0;
}*/
