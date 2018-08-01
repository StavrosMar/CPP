/*
*
*
*	Topics covered: 
*					1) Validate that allocating with new is equivalent to malloc. 
					  run g++  with -o  memory-layout option

*
*/

#include <memory>
#include <iostream>

using namespace std;

int main() {

	int* p1 = new int[10];

	p1[1] = 10;
	p1[0] = 11;

	delete[] p1;

	//int a = 10;

	int* p2 = (int*)malloc(sizeof(int)*10);
	
	p2[2] = 13;

	free(p2);

	//cout<<p2[2]<<'\n';


	return 0;

}
