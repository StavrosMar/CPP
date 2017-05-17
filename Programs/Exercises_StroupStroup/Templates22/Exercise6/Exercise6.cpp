//Templates 23 - Exercise 6 - qsort
// Create a qsort template

//Original qsort syntax
//-//void qsort( void *ptr, std::size_t count, std::size_t size, /*c-compare-pred*/* comp );


#include <iostream>
#include <algorithm>
#include <vector>







namespace stavros {

// Qsort Implementation
	
	template<typename T, typename RIter>
	void qsort(const RIter beg, const RIter end) {



		//Do stuff


	}




}


int main() {

	
	int* mat[2][2];

	// Call qsort
	
	std::vector<int> vec{1,2,3};
	stavros::qsort<int>(vec.begin(),vec.end());

	//TODO 
	/*
	1) Support for sorting criteria - either via template or function pointer



	*/


	return 0;

}
