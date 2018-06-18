#include <iostream>
#include <array>
using namespace std;


/*
 *  Listing 3.6 - avoiding Deadlocks when requiring the mutex of two objects of the same class at a time
 *  Example from the Book
 */


class Big2DArray {
private:
	array<array<unsigned int,1000000000000>,1000000000000> A;
public:
	Big2DArray() {
		auto a=array<unsigned int,1000000000000>(); //make a array and then fill it
		a.fill(89);
		A.fill(a);
	}
};


// Implement hierarchical_thread //
