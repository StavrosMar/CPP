//Templates 23 - Exercise 6 - qsort
// Create a qsort template

//Original qsort syntax
//-//void qsort( void *ptr, std::size_t count, std::size_t size, /*c-compare-pred*/* comp );


#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

namespace stavros {


// Qsort Implementation

/*
	// Comp is a function pointer to the member of class Comp
	template<typename T,typename Comp>
	void qsort(T* begin, const std::size_t count,const std::size_t size,bool (Comp::*)(const T&, const T&) const ) {

		
		std::qsort(begin, count, size, [](const void *a, const void *b){			
		// Execute the function pointer passed with the arguments

				int aux_var{Comp()(*(int*)a,*(int*)b)};
			
				return aux_var;
		
			}
		);

		//Do stuff


	}

*/
	// Comp is a function pointer to the member of class Comp
	template<typename T, typename RIter, typename Comp>
	void qsort(RIter begin, const std::size_t count,const std::size_t size,bool (Comp::*)(const T&, const T&) const ) {

	
		// iterator to pointer 
		auto begin_under_val{*begin};

		std::qsort(&begin_under_val, count, size, [](const void *a, const void *b){			
		// Execute the function pointer passed with the arguments

				int aux_var{Comp()(*(int*)a,*(int*)b)};
			
				return aux_var;
		
			}
		);

		//Do stuff

	}


} 

template<typename T>
void print_Entity(const T* begin, const T* end) {


	std::cout<<"## Start Printint Object ##"<<std::endl;

	for (const T* i = begin ; i!=end ; ++i) {
		
		std::cout<<*i<<std::endl;

	}
	
	std::cout<<"## End Printint Object ##"<<std::endl;
}

int main() {


/*	
//TEST1 - Sorting Matrices
	
	//-// Setup matrix
	
	int mat[10]{9,8,1,10,2,3,4,5,6,7};
	
	constexpr std::size_t mat_size = sizeof mat / sizeof *mat;
	
	int* begin{mat};
	
	int* end{begin+mat_size};
	
	//-//Call sort

	stavros::qsort<int>(mat, mat_size , sizeof *mat, &std::greater<int>::operator());
	
	//-//Print results
	
	print_Entity(begin,end);
*/

//TEST2 - Sorting Containers (e.g. objects with iterators)
	
	std::vector<int> vec{0,1};
	
	std::array<int,10> arr{19,1,19};

	//-//Call sort

	stavros::qsort<int>(vec.begin(), vec.size() , sizeof vec[0], &std::greater<int>::operator());

	//-//Print results
	
	print_Entity(&(*vec.begin()),&(*vec.end()));


	//TODO 
	/*
	1) Support for sorting criteria - either via template or function pointer


	*/


	return 0;

}
