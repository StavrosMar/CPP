/*
*
*	Topics covered :
*					1) Merge sort iterative implementation
*
*/

#define N 11

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

void ssort(int* const A) {

	//if (a<b) {
	
	for (int sz{1}; sz<N ; sz+=sz) {
		
		//a is Jumping two every time
		for (int a{0} ; a < N-sz ; a += 2*sz) {
			
			int b = a+2*sz-1;
			int mid = a+sz-1; //sitting on the first
			if (N-1 < b) {
				b = N-1;
			}
			cout<<"a="<<a<<" mid="<<mid<<" b="<<b<<'\n';
			smerge(A,a,mid,b);
		}
	}
}

void printArray(const int* const A,unsigned int siz) {

	for (int i{0} ; i<siz ; ++i) {
		cout<<A[i]<<" ";
	}
	
	cout<<'\n';

}


int main() {

	int A[N]= {21,3,5,6,8,4,6,13,1,3,-3};

	cout<<"Array before mergeSort"<<'\n';
	printArray(A,N);
	
	ssort(A);

	cout<<"Array after mergeSort"<<'\n';
	printArray(A,N);

}

	
