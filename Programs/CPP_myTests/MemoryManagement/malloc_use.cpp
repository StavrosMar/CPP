/*
*
*
*	Topics covered:
*					1) use malloc
*
*/

#define N 10

#include <memory>
#include <iostream>

using namespace std;

//Just a test to show that ptr stays in memory after function exit
int* foo() {

	//Allocate memory for table of ints - size N.
	cout<<"Size of 1 int is "<<sizeof(int)<<" bytes"<<'\n';
	cout<<"Size of 1 int* is "<<sizeof(int*)<<" bytes"<<'\n';
	cout<<"Size of 1 double is "<<sizeof(double)<<" bytes"<<'\n';
	cout<<"Size of 1 double* is "<<sizeof(double*)<<" bytes"<<'\n';
	cout<<"Size of 1 float is "<<sizeof(float)<<" bytes"<<'\n';
	cout<<"Size of 1 float* is "<<sizeof(float*)<<" bytes"<<'\n';
	
	int* ptr = (int*)malloc(sizeof(int)*N);
	
	for (int i{0} ; i<N ; ++i) {
		ptr[i] = 10+i;
	}

	return ptr;
}


int main() {


	int* ptr = foo();

	for (int i{0} ; i<N ; ++i ) {
		cout<<"Malloc is "<<ptr[i]<<'\n';
	}
	//free allocated memory outside
	free(ptr);
	//free(ptr); // This gives error as expected.
	cout<<*ptr<<'\n';

	//Another example on 1 int.
	// Notice that the contents still stay after free.
	int* p2 = (int*)malloc(sizeof(int));
	*p2 = 19;

	free(p2);
	cout<<"p2 = "<<*p2<<'\n';


}
