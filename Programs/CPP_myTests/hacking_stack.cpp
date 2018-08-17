/*
*   Topics covered:
*                    1) Hacking the stack - code injection
*						TODO - make it work - maybe replace cin?
*                   
*/

#include <iostream>
#include <vector>
#define N 10

using namespace std;


void userInput(char* input) {

	cin>>input; //give input more than N
}

int main() {

	char buff[N];
	
	userInput(buff);

	return 0;

}
