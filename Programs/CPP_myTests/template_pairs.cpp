// This is an example with template functions
// Inspired from std::make_pair which does not need 
// the template parameters defined when being called
// Just want to check that 
//
//
#include <iostream>

template<class T1, class T2> void templ_calledNotypes(T1 x, T2 y) {

	std::cout<<"Called"<<"\n";
}

int main() {

	std::cout<<"Lola"<<"\n";

	int x(0),y(0);

	//No need to run it with templ_calledNotypes<int,int>(x,y)
	templ_calledNotypes(x,y);
	
	return 0;

}
