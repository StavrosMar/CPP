//Templates 23 - Exercise 6 - qsort
// Create a qsort template

//Original qsort syntax
//-//void qsort( void *ptr, std::size_t count, std::size_t size, /*c-compare-pred*/* comp );


#include <iostream>
#include <algorithm>
#include <vector>







namespace stavros {


// Qsort Implementation


	template<typename T, typename Comp>
	void qsort(void *ptr, const std::size_t count,const std::size_t size, const bool* Comp::* comp) {

	

		//qsort(



		//Do stuff


	}




}


int main() {

	
	int* mat[2][2];
	constexpr std::size_t mat_size = sizeof mat / sizeof *mat;

	// Call qsort
	
	std::vector<int> vec{1,2,3};
	//stavros::qsort<int>(mat,4,sizeof *mat, std::greater());
	stavros::qsort<int>(mat, mat_size , sizeof *mat, &std::greater<int>());

	//TODO 
	/*
	1) Support for sorting criteria - either via template or function pointer


	*/


	return 0;

}
