#include <string>
#include <iostream>



void StavrosSort(int *A, const int& lo, const int& hi) {

	if (lo < hi)  {

		int lt{lo};
		int gt{hi};
		int i{lt+1};

		while (i <= gt) {

			if (A[i] < A[lt]) {
				std::swap(A[i],A[lt]);
				++i;++lt;
			} else if ( A[i] > A[gt]) {
				std::swap(A[i], A[gt]);
				++i; gt--;
			} else {
				i++;
			}
		}

		StavrosSort(A,lo,lt-1);
		StavrosSort(A,gt+1,hi);

	}
}

//Not passing pointer - to prevent modification to initial table
int findElem(int A[], const int& elem, const size_t& Asize) {

	StavrosSort(A,0,Asize-1);
	for(int i{0}; i< Asize; ++i) {

		std::cout<<*(A+i)<<" ";
	}

	std::cout<<"\n";
	return 0;

}


int main() {


	int A[10] = {11,13,19,89,20,10};


	int found{findElem(A,11,10)};

	std::cout<<"Found output"<<found;
}
