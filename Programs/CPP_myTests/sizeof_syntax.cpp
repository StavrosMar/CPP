/*
*   Topics covered:
*                    1) Expert C programming : sizeof (int) * p
*						- What does it do ? - Does not compile
*                   
*/

#include <iostream>
#include <vector>

using namespace std;


int main() {

	int pval{21};
	int* p = &pval;
	unsigned int apple = sizeof (int) * p;

	cout<<apple<<"bytes\n";

	return 0;

}
