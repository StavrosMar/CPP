/*
*   Topics covered:
*                    1) Implementing a Heap
*
*	TODO:
*					1) Returning iterators and not elements(?)
*					2) Verify exception handling
*/

#include <iostream>
#include <vector>

using namespace std;

//maxHeap
template <typename T> class Heap {

private:
	vector<T> A;

public:

	//Interface functions
	void insert(const T&);
	//std::pair<bool,T> find(const T&);
	void removeMax();
	bool isEmpty();
//	const T&   top();
	unsigned int size();
	const T&  max();
	void debugPrintHeap();

    
};

template <typename T> bool Heap<T>::isEmpty() {
	
	return (this->size()<1) ? true : false; 
}

template <typename T> const T& Heap<T>::max()  {
	 
	 try {
	 	if ( !this->isEmpty() ) {
			return this->A[0];
		 } else {
	 		throw "Exception Thrown !!! : Heap is empty";
	 	}
	} catch (...) {
		throw;
	}
}

template <typename T> unsigned int Heap<T>::size() {
	
	return this->A.size();
}

template <typename T> void Heap<T>::debugPrintHeap() {

	cout<<"Printing heap elements\n ";
	for (auto i : A) {
		cout<<i<<'\n';
	}

}

//Implemented and Tested
template <typename T> void Heap<T>::insert(const T& s) {
		
		//Step 1 - push the child to the last position.
		A.push_back(s);
		
		int c = A.size()-1; //position of last element in vector;
		int par; //find the parent of child
		bool stop{false};

		//Step 2 - Swim upwards the child.
		while ( c > 0 && !stop) {
		
			(c%2 == 0) ? par = (c-1)/2 : par = c/2;
			if ( s > A[par] ) {
				swap(A[c],A[par]);
			} else {
				stop = true;
			}
			c = par;
		}
} 

template <typename T> void Heap<T>::removeMax() {
	
	//Step 1: Exchange last element with root and delete it.
	A[0] = *(A.end()-1);
	A.erase(A.end()-1); 

	//Step 2: Swim down - restore Heap structure.

	int par{0};
	int c;

	while (c<this->size()) {
		(par%2 == 0) ? c = 2*par+1 : c = par*2+2; 
		if( A[c] > A[par] ) {
			swap(A[c],A[par]);
			par = c;
		 } else if ( A[c+1] > A[par] ) {
		 	swap(A[c+1],A[par]);
			par = c+1;
		}
	}

}
//template <typename T> void Heap<T>::find(const T& s) {


int main() {
	
	Heap<int> h1;
	h1.insert(1);
	h1.insert(8);
	h1.insert(4);
	
	cout<<"Heap size is "<<h1.size()<<'\n';
	try {
		cout<<"Max is "<<h1.max()<<'\n';
	} catch(const char* s) {
		cout<<s<<'\n';
	}

	h1.debugPrintHeap();

	cout<<"Heap After Removal of Max"<<'\n';
	h1.removeMax();

	h1.debugPrintHeap();

	return 0;

}
