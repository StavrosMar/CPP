//Templates 23 - Exercise 6 - qsort
// Create a qsort template

//Original qsort syntax
//-//void qsort( void *ptr, std::size_t count, std::size_t size, /*c-compare-pred*/* comp );


#include <iostream>
#include <algorithm>
#include <vector>







namespace stavros {


// Qsort Implementation

	// Comp is a function pointer to the member of class Comp
	template<typename T,typename Comp>
	void qsort(T *begin, const std::size_t count,const std::size_t size,bool (Comp::*)(const T&, const T&) const ) {

		int a=10;
		int b=29;
		
		// Execute the function pointer passed with the arguments
		std::cout<<Comp()(a,b)<<std::endl;

		std::qsort(begin, count, size, [](const void *a, const void *b){
				
				
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


//TEST2 - Sorting Vectors
	
	std::vector<int> vec{19,33,3};
	
	//-//Call sort

	//stavros::qsort<int>(vec.begin(), vec.size() , sizeof vec[0], &std::greater<int>::operator());
	
	//-//Print results
	
	//print_Entity(vec.begin(),vec.end());


	//TODO 
	/*
	1) Support for sorting criteria - either via template or function pointer


	*/


	return 0;

}
