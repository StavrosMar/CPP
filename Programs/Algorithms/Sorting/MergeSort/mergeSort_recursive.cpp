/*
*
*	Topics covered :
*					1) Merge sort recursive implementation  with intermediate storage
*
*/

#define N 10

#include <iostream>
#include <array>

using namespace std;


//A is still being pass as a pointer - A is modifyable.
//But we can wrap it and it is ok - i.e. if we replace with arra<int,size>.
void smerge(int* const A, int a, int mid, int b) {

	int Nt{(b-a)+1};
	int temp[Nt];
	
	int i{a}, j{mid+1};
	
	//Fill in temporary table temp
	for (int k = 0; k < Nt ; ++k) {
		
		if ( i > mid ) {
			temp[k] = A[j++];
		} else if ( j > b) {
			temp[k] = A[i++];
		} else if (A[i] < A[j]) {
			temp[k] = A[i++];
		} else {
			temp[k] = A[j++];
		}
	}
	
	//Copy temp back to A
	for (int k=0 ; k < Nt ; ++k) {
		A[a+k] = temp[k];
	}
}

void ssort(int* const A, int a, int b) {

	if (a<b) {
		
		int mid = (a+b)/2;
		ssort(A,a,mid);
		ssort(A,mid+1,b);

		smerge(A,a,mid,b);
	}
}

void printArray(const int* const A,unsigned int siz) {

	for (int i{0} ; i<siz ; ++i) {
		cout<<A[i]<<" ";
	}
	
	cout<<'\n';

}


int main() {

	int A[N]= {21,3,5,6,8,4,6,13,1,3};

	cout<<"Array before mergeSort"<<'\n';
	printArray(A,N);
	
	ssort(A,0,N-1);

	cout<<"Array after mergeSort"<<'\n';
	printArray(A,N);


}

	
