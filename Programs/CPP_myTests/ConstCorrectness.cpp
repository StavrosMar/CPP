/*
*
*		Topics covered:
*						1) const correctness on member functions.
*
*/


#include <iostream>

class Stavros {

public:
	
	void foo() {} ;
};

//moo has declared s as const.
void moo(const Stavros& s) {
	
	//Compiler throwing error since foo has not been declared const
	// - thus it does not know if foo is modifying the object in any way or not.
	s.foo();
}

int main() {

	Stavros s;
	moo(s);

}
