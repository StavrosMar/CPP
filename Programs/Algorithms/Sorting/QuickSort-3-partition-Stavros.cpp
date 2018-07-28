#include <string>
#include <iostream>



void StavrosSort(int *A, const int& lo, const int& hi) {

	if (lo < hi)  {

		int lt{lo};
		int gt{hi};
		int i{lo+1};

		// Comparing with lt not lo like djikstra.
		//Djikstra implementation does not work.
		//Mine works.
		while (i <= gt) {

			if (A[i] < A[lt]) {
				std::swap(A[i],A[lt]);
				++i;++lt;
			} else if ( A[i] > A[lt]) {
				std::swap(A[i], A[gt]);
				 gt--;
			} else {
				i++;
			}
		}

		StavrosSort(A,lo,lt-1);
		StavrosSort(A,gt+1,hi);

	}
}

//table modified - since A[] is essentially a pointer
int findElem(int A[], const int& elem, const size_t& Asize) {

	StavrosSort(A,0,Asize-1);
	for(int i{0}; i< Asize; ++i) {

		std::cout<<A[i]<<" ";
	}

	std::cout<<"\n";
	return 0;

}


int main() {

	const int sizeA{20};
	int A[sizeA] = {90,112,789,8,234,726,9,2,-1,65,7,76,0,65,89};


	int found{findElem(A,11,sizeA)};

	for(int i{0}; i< sizeA ; ++i) {

			std::cout<<A[i]<<" ";
		}

	std::cout<<"Found output"<<found;
}

