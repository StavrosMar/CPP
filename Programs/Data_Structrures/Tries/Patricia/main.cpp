#include "patricia.h"
#include "util.h"

int main() {

	//Running Unitary Tests utils.cpp
	test_unit_binUtil();

	//a) Constructor - passed
	Node<int> a("lala",3);

	//Patricia Tests
	PTrie<int> patricia;

	
	return 0;
}
