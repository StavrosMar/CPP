/*
*
*	Topics covered:
*					1) object on stack lifetime
*
*/


#include <iostream>

using namespace std;





int main() {

	{
		//here a has its scope declared only here
		int a = 0;
		int b = * new int(10); // iou - memory leak.
		cout<<"b="<<b<<'\n';
	}
	

	//a does not exist
	//cout<<"a="<<a<<'\n';
	//cout<<"b="<<b<<'\n';

}
